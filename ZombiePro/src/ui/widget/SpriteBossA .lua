local SpriteBossA = class('SpriteBossA', require 'ui.base.SpriteMonster')
local SkillCDTime = 4
local SkillBefore = 2
local SkillAttackRadius = 150

function SpriteBossA:ctor(...)
    SpriteBoss1.super.ctor(self, ...)
    self.skillCDTime = SkillCDTime
    self.skillAttackRadius = SkillAttackRadius
    self.mainSprite:loadTexture('monster_4_1.png')
end


function SpriteBossA:update(dt)
    SpriteBossA.super.update(self, dt)

    self.skillCDTime = self.skillCDTime - dt
    if self.skillCDTime <= 0 and self:isSkillAttack() then 
 		self.isForceAction = true
    	self.skillCDTime = 1000000
    	self:skill()
    end
end

function SpriteBossA:skill()
    local tx, ty = self.gameLayer.mainRole:getPosition()
    local x, y = self:getPosition()
    local warnCircle = ccui.ImageView:create('battle/button_shoot.png', 1)
    warnCircle:setPosition(cc.p(tx, ty))
    self.gameLayer.mainMap:addChild(warnCircle)
    warnCircle:runAction(cc.Sequence:create(cc.Bink:create(SkillBefore, 6), cc.CallFunc:create(function(pender) 
        pender:removeFromParent()
    end)))

    self:runAction(cc.Sequence:create(
        cc.DelayTime:create(SkillBefore)
        cc.Spawn:create(cc.ScaleTo(0.5, 2), cc.MoveTo:create(0.5, cc.pMidpoint(cc.p(x, y), cc.p(tx, ty)))),
        cc.Spawn:create(cc.ScaleTo(0.5, 1), cc.MoveTo:create(0.5, cc.p(tx, ty))),
        cc.CallFunc:create(function() 
            self.isForceAction = false
            self.status = 'stand'
            self.canInitPath = true
            self.skillCDTime = SkillCDTime
        end)))
end

function SpriteBossA:isSkillAttack()
    local heroX, heroY = self.gameLayer.mainRole:getPosition()
    local posX, posY = self:getPosition()
    return cc.pGetDistance(cc.p(heroX, heroY), cc.p(posX, posY)) < self.skillAttackRadius
end


return SpriteBossA