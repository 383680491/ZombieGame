local SpriteBase = class('SpriteBase', function() return cc.Node:create() end)

local G_Def = {

    DIR_RIGHT = 0,
    DIR_RIGHT_UP = 1,
    DIR_UP = 2,
    DIR_LEFT_UP = 3,
    DIR_LEFT = 4,
    DIR_LEFT_DOWN = 5,
    DIR_DOWN = 6,
    DIR_RIGHT_DOWN = 7,
    


    ACTION_RUN = 1,
    ACTION_STAND = 2,
    ACTION_ATTACK = 3,
    ACTION_HURT = 4,
    ACTION_DEATH = 5,
    ACTION_APPEAR = 6,
    ACTION_MAGIC_UP = 7,
    ACTION_WALK = 8,
    --碰撞
    ACTIVE_COLLIDE = 9,


    ActionRelative = {
        'run',
        'stand',
        'attack',
        'hurt',
        'death',
        'appear',
        'magic_up',
        'walk'
    }
}


function SpriteBase:ctor(...)
    local args = {...}
    self.mainSprite = cc.Sprite:create()
    self:addChild(self.mainSprite)

    self.dir = G_Def.DIR_DOWN
    self.torwardId = G_Def.DIR_RIGHT
    self.action = G_Def.ACTION_STAND
    self.id = args[2]
    self.actionFactot = 0.1
    self.speedFactor = 5
    self:getTorwardIDByDir()
    self:runAnimal()
end

function SpriteBase:runAnimal()
    local animFrames = {}
    for i = 1, 4  do
        local path = string.format('role_%d_%s_%05d.png', self.id, 'stand', self.torwardId*10000 + i - 1)
        look(path, 'path')
        local frame =  cc.SpriteFrameCache:getInstance():getSpriteFrame(path)
        assert(frame ~= nil,  string.format('%s ========not exist', path))
        table.insert(animFrames, frame)
    end


    local aniAction = cc.Animation:createWithSpriteFrames(animFrames, 0.08)
    local animate = cc.Animate:create(aniAction)
    self.mainSprite:runAction(cc.RepeatForever:create(animate))
end


function SpriteBase:getTorwardIDByDir()
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

function SpriteBase:getDirByJoyDir(direct, angle)
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
look(self.dir, 'self.dir')
end

return SpriteBase
