local SpriteBossB = class('SpriteBossB', require 'ui.widget.SpriteMonster')
local SkillCDTime = 3
local SkillBefore = 0.6
local SkillAttackRadius = 500     --可以出钩子的距离
local DuringDt = 0.1              --优化
local GoziDuringTime = 0.5              --钩子动画的时长
local GoziRadius = 10             --钩子的攻击半径

local STATUS_GOzi_NULL = 1
local STATUS_GOzi_GO = 2
local STATUS_GOzi_Back = 3
local STATUS_GOzi_Backing = 4

function SpriteBossB:ctor(...)
    SpriteBossB.super.ctor(self, ...)
    self.skillCDTime = SkillCDTime
    self.skillAttackRadius = SkillAttackRadius
    self.mainSprite:loadTexture('monster_3_1.png')
    self.dtTemp = DuringDt    --担心每帧都计算这个是否能攻击太耗性能了  
    self.skillAnimalFlag = STATUS_GOzi_NULL
    self.catchTargetFlag = false
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
            self.skillAnimalFlag = STATUS_GOzi_GO
        end

        if self.skillAnimalFlag == STATUS_GOzi_GO then 
            if not self.catchTargetFlag and self:isCatchTarget() then 
                self.sprGozi:stopAllActions()
                self.catchTargetFlag = true
                self.skillAnimalFlag = STATUS_GOzi_Back
            end
        elseif self.skillAnimalFlag == STATUS_GOzi_Back then
            self.sprGozi:stopAllActions()
            self.skillAnimalFlag = STATUS_GOzi_Backing

            if self.catchTargetFlag then 
                self.gameLayer.mainRole:beginForceAction()
            end

            local high = self.sprGozi:getPositionY() - self.hurtRadius
            local costTime = (math.abs(high) / self.sprGozi:getContentSize().height) * GoziDuringTime
            self.sprGozi:runAction(cc.Sequence:create(cc.MoveTo:create(costTime, cc.p(0, 0 - self.hurtRadius)), cc.CallFunc:create(function() 
                self.clip:removeFromParent()
                self.sprGozi = nil
                self.nodeGozi = nil
                self.clip = nil

                self.catchTargetFlag = false
                self.skillAnimalFlag = STATUS_GOzi_NULL
                self.skillCDTime = SkillCDTime

                self.gameLayer.mainRole:endForceAction()
                self.isForceAction = false
            end)))            
        end

        self.dtTemp = DuringDt
    end

    if self.skillAnimalFlag == STATUS_GOzi_Backing then
        if self.catchTargetFlag then 
            local wPos = self.nodeGozi:convertToWorldSpace(cc.p(0, 0))  --把自己转换到世界坐标，然后转入mainMap
            local pos = self.gameLayer.mainMap:convertToNodeSpace(wPos)
            self.gameLayer.mainRole:setPosition(pos)
        end
    end
end

function SpriteBossB:skill()
    local tx, ty = self.gameLayer.mainRole:getPosition()
    local x, y = self:getPosition()

    local dir = G_Utils.getDirVector(cc.p(x, y), cc.p(tx, ty))
    local radian = cc.pToAngleSelf(dir)
    local angle = radian / 3.14159 * 180 --弧度变角度 
    self.mainNode:setRotation(270 - angle)   --重新确定方向

    self.sprGozi = cc.Sprite:create("gouzi.png")
    local size = self.sprGozi:getContentSize()

    local stencil = cc.Sprite:create("img_place.png")
    stencil:setAnchorPoint(0.5, 0)
    stencil:setTextureRect(cc.rect(0, 0, size.width, size.height))

    self.clip = cc.ClippingNode:create(stencil)
    self.clip:setPosition(cc.p(0, -20))
    self.clip:setInverted(true)                                           --反转
    self.mainNode:addChild(self.clip)

    self.sprGozi:setAnchorPoint(cc.p(0.5, 0))
    self.sprGozi:setPosition(cc.p(0, 0))
    self.sprGozi:runAction(cc.Sequence:create(cc.MoveTo:create(GoziDuringTime, cc.p(0, 0 - size.height)), cc.CallFunc:create(function() 
        self.skillAnimalFlag = STATUS_GOzi_Back
    end)))

    self.clip:addChild(self.sprGozi)

    self.nodeGozi = cc.Node:create()
    self.nodeGozi:setPosition(cc.p(size.width / 2,  GoziRadius))  --看图片的钩子的大小 node放到正中心  然后看作圆来判断是否勾到英雄  半径用25来判断
    self.sprGozi:addChild(self.nodeGozi)
end

function SpriteBossB:isSkillAttack()
    local heroX, heroY = self.gameLayer.mainRole:getPosition()
    local posX, posY = self:getPosition()

    if not self.gameLayer.mainRole:isCanAttack() then   --英雄是否可以被技能攻击
        return false
    end

    local isLen = cc.pGetDistance(cc.p(heroX, heroY), cc.p(posX, posY)) < self.skillAttackRadius
    if not isLen then 
        return false
    end

    return not self.gameLayer.mainMap:pathHasBlock(cc.p(posX, posY), cc.p(heroX, heroY))
end

function SpriteBossB:isCatchTarget()
    local wPos = self.nodeGozi:convertToWorldSpace(cc.p(0, 0))  --把自己转换到世界坐标，然后转入mainMap
    local Pos = self.gameLayer.mainMap:convertToNodeSpace(wPos)
    local tx, ty = self.gameLayer.mainRole:getPosition()

    return cc.pGetDistance(Pos, cc.p(tx, ty)) < GoziRadius + self.gameLayer.mainRole.hurtRadius
end


return SpriteBossB