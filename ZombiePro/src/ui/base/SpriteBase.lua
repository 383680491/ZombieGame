local SpriteBase = class('SpriteBase', NodeAStar) --NodeAStar

function SpriteBase:ctor()
    self.mainSprite = cc.Sprite:create()
    self:addChild(self.mainSprite)

    self.dir = G_Def.DIR_UP
    self.torwardId = G_Def.DIR_RIGHT
    self.action = G_Def.ACTION_STAND
    self.id = 10005
    self.actionFactot = 0.5
    self.speedFactor = 5
    self.speed = 0
    self.sourcePath = 'role_%d_%s_%05d.png'
end

function SpriteBase:runAnimal()   
    if self.dir ~= self.lastDir then 
        local animFrames = {}
        for i = 1, self.frameCount[self.action] do 
            local path = string.format(self.sourcePath, self.id, G_Def.ActionRelative[self.action], self.torwardId*10000 + i)
            look(path, 'path')
            local frame =  cc.SpriteFrameCache:getInstance():getSpriteFrame(path)
            table.insert(animFrames, frame)
        end

        local aniAction = cc.Animation:createWithSpriteFrames(animFrames, self.actionFactot)
        local animate = cc.Animate:create(aniAction)
        self.mainSprite:stopAllActions()
        self.mainSprite:runAction(cc.RepeatForever:create(animate))
        self.lastDir = self.dir
    end 
end


function SpriteBase:getTorwardIDByDir()
    if self.dir == self.lastDir then 
        return
    end

    if self.dir == G_Def.DIR_UP then 
        self.torwardId = 0
        self.mainSprite:setFlippedX(false)
    elseif self.dir == G_Def.DIR_DOWN then
        self.torwardId = 4
        self.mainSprite:setFlippedX(false)
    elseif self.dir == G_Def.DIR_LEFT then
        self.torwardId = 2
        self.mainSprite:setFlippedX(true)
    elseif self.dir == G_Def.DIR_RIGHT then
        self.torwardId = 2
        self.mainSprite:setFlippedX(false)
    elseif self.dir == G_Def.DIR_RIGHT_UP then
        self.torwardId = 1
        self.mainSprite:setFlippedX(false)
    elseif self.dir == G_Def.DIR_LEFT_UP then
        self.torwardId = 1
        self.mainSprite:setFlippedX(true)
    elseif self.dir == G_Def.DIR_RIGHT_DOWN then
        self.torwardId = 3
        self.mainSprite:setFlippedX(false)
    elseif self.dir == G_Def.DIR_LEFT_DOWN then
        self.torwardId = 3
        self.mainSprite:setFlippedX(true)
    end
end

function SpriteBase:getDirByJoyDir(angle, direct)
    if direct.x < 0.05 and direct.x > -0.05 then 
        if direct.y > 0 then 
            self.dir = G_Def.DIR_UP
        elseif direct.y < 0 then
            self.dir = G_Def.DIR_DOWN
        end
    elseif direct.y < 0.05 and direct.y > -0.05 then 
        if direct.x > 0 then 
            self.dir = G_Def.DIR_RIGHT
        elseif direct.x < 0 then
            self.dir = G_Def.DIR_LEFT
        end
    end

    if direct.x >= 0.05 and direct.y >= 0.05 then 
        self.dir = G_Def.DIR_RIGHT_UP
    elseif direct.x <= -0.05 and direct.y >= 0.05 then 
        self.dir = G_Def.DIR_LEFT_UP
    elseif direct.x <= -0.05 and direct.y <= -0.05 then 
        self.dir = G_Def.DIR_LEFT_DOWN
    elseif direct.x >= 0.05 and direct.y <= -0.05 then 
        self.dir = G_Def.DIR_RIGHT_DOWN
    end
end

return SpriteBase
