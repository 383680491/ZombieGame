local SpriteBase = class('SpriteBase', cc.Node)

function SpriteBase:ctor(...)
    self.mainSprite = cc.Sprite:create()
    self:addChild(self.mainSprite)

    self.dir = G_Def.DIR_UP
    self.torwardId = G_Def.DIR_RIGHT
    self.action = G_Def.ACTION_STAND
    self.id = 10005
    self.actionFactot = 0.1
    self.speedFactor = 5
end

function SpriteBase:getAnimal()
    local ani = cc.Animation:create()
    ani:setDelayPerUnit(self.actionFactot)
    local cache = cc.SpriteFrameCache:getInstance()

    for i = 1, 5 do 
        local path = string.format('%d_%s_%d.png', self.id, G_Def.ActionRelative[self.action], self.dir*10000 + i)
        local frame = cache:getSpriteFrameByName(path)
        assert(frame ~= nil,  string.format('%s ========not exist', path))
        ani:addSpriteFrame(frame);
    end

    return ani
end


function SpriteBase:getTorwardIDByDir()
    if self.self.dir == G_Def.DIR_UP then 
        self.torwardId = 0
    elseif self.self.dir == G_Def.DIR_DOWN then
        self.torwardId = 4
    elseif self.self.dir == G_Def.DIR_LEFT then
        self.torwardId = 3
    elseif self.self.dir == G_Def.DIR_RIGHT then
        self.torwardId = 2
    elseif self.self.dir == G_Def.DIR_RIGHT_UP then
        
    end

end

return SpriteBase
