local SpriteBossB = class('SpriteBossB', require 'ui.widget.SpriteMonster')
local SkillCDTime = 3
local SkillBefore = 0.6
local SkillAttackRadius = 500     --可以出钩子的距离
local DuringDt = 0.1              --优化
local GoziDuring = 2              --钩子动画的时长
local GoziRadius = 25             --钩子的攻击半径

function SpriteBossB:ctor(...)
    SpriteBossB.super.ctor(self, ...)
    self.skillCDTime = SkillCDTime
    self.skillAttackRadius = SkillAttackRadius
    self.mainSprite:loadTexture('monster_3_1.png')
    self.dtTemp = DuringDt    --担心每帧都计算这个是否能攻击太耗性能了  
    self.skillAnimalFlag = false
end


function SpriteBossB:update(dt)
    SpriteBossB.super.update(self, dt)

    self.dtTemp = self.dtTemp - dt
    self.skillCDTime = self.skillCDTime - dt
    if self.dtTemp <= 0 then                            --纯粹是为了优化
        if self.skillCDTime <= 0 and self:isSkillAttack() then 
            self.isForceAction = true
            self.skillCDTime = 1000000
            self:skill()
        end

        if self.skillAnimalFlag then 
            if self:isAttackTarget() then 
                
            end
        end

        self.dtTemp = DuringDt
    end
end

function SpriteBossB:skill()
    local tx, ty = self.gameLayer.mainRole:getPosition()
    local x, y = self:getPosition()

    local dir = G_Utils.getDirVector(cc.p(x, y), cc.p(tx, ty))
    local radian = cc.pToAngleSelf(dir)
    local angle = radian / 3.14159 * 180 --弧度变角度 
    self.mainNode:setRotation(270 - angle)   --重新确定方向

    local gozi = cc.Sprite:create("gouzi.png")
    local size = gozi:getContentSize()

    local stencil = cc.Sprite:create("img_place.png")
    stencil:setAnchorPoint(0.5, 0)
    stencil:setTextureRect(cc.rect(0, 0, size.width, size.height))

    local clip = cc.ClippingNode:create(stencil)
    clip:setPosition(cc.p(0, -20))
    clip:setInverted(true)                                           --反转
    self.mainNode:addChild(clip)

    gozi:setAnchorPoint(cc.p(0.5, 0))
    gozi:setPosition(cc.p(0, 0))
    gozi:runAction(cc.MoveTo:create(GoziDuring, cc.p(0, 0 - size.height)))
    clip:addChild(gozi)

    self.nodeGozi = cc.Node:create()
    self.nodeGozi:setPosition(cc.p(size.width / 2,  GoziRadius))  --看图片的钩子的大小 node放到正中心  然后看作圆来判断是否勾到英雄  半径用25来判断
    gozi:addChild(self.nodeGozi)

    local sp = cc.Sprite:create('progress.png')
    sp:setScale(0.3)
    self.nodeGozi:addChild(sp)

    self.skillAnimalFlag = true
end

function SpriteBossB:isSkillAttack()
    local heroX, heroY = self.gameLayer.mainRole:getPosition()
    local posX, posY = self:getPosition()

    local isLen = cc.pGetDistance(cc.p(heroX, heroY), cc.p(posX, posY)) < self.skillAttackRadius
    if not isLen then 
        return false
    end

    return not self.gameLayer.mainMap:pathHasBlock(cc.p(posX, posY), cc.p(heroX, heroY))
end

function SpriteBossB:isAttackTarget()
    local wPos = self.nodeGozi:convertToWorldSpace(cc.p(0, 0))  --把自己转换到世界坐标，然后转入mainMap
    local Pos = self.gameLayer.mainMap:convertToNodeSpace(wPos)
    local tx, ty = self.gameLayer.mainRole:getPosition()

    return cc.pGetDistance(Pos, cc.p(tx, ty)) < GoziRadius + self.gameLayer.mainRole.hurtRadius
end


return SpriteBossB