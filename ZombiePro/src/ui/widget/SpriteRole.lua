local SpriteRole = class('SpriteRole', require 'ui.base.SpriteBase')

function SpriteRole:ctor(...)
    SpriteRole.super.ctor(self)
    local args = {...}
    self.id = args[2]
    self.dir = G_Def.DIR_DOWN
    self.frameCount = {
        [G_Def.ACTION_STAND] = 3,
    }

    self.speed = 10

    self:getTorwardIDByDir()
    self:runAnimal()
end

function SpriteRole:setGameLayer(gameLayer)
    self.gameLayer = gameLayer
end



function SpriteRole:move(angle, direct, power)
    self:getDirByJoyDir(angle, direct)
    self:getTorwardIDByDir()
    self:runAnimal()

    local posX, posY = self:getPosition()
    local x = self.speed * direct.x + posX
    local y = self.speed * direct.y + posY

    local map = self.gameLayer.mainMap
    local tile = map:space2Tile(cc.p(x, y))

    if map:isBlock(tile) then 
        return
    end

    self:setPosition(cc.p(x, y))

    look(cc.p(x, y), 'curPosition')
end

return SpriteRole
