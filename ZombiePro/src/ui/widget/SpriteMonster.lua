local SpriteMonster = class('SpriteMonster', require 'ui.base.SpriteBase')

function SpriteMonster:ctor(...)
    SpriteMonster.super.ctor(self)
    local args = {...}
    self.id = args[2]
    self.dir = G_Def.DIR_DOWN
    self.action = G_Def.ACTION_WALK
    self.sourcePath = '%d_%s_%05d.png'
    self.frameCount = {
        [G_Def.ACTION_WALK] = 4,
    }

    self.speed = 1

    self:getTorwardIDByDir()
    self:runAnimal()
    self:scheduleUpdate();

    self.status = 'stand'
    self.second = 0
    self.canInitPath = false
end

function SpriteMonster:scheduleUpdate()
    local update = function(dt)
        self:update(dt);
    end

    self:scheduleUpdateWithPriorityLua(update, 0);
end

function SpriteMonster:setGameLayer(gameLayer)
    self.gameLayer = gameLayer
    self:setMap(self.gameLayer.mainMap)
end

function SpriteMonster:update(dt)
    if self.status == 'stand' then 
        self.curDestTile = self:getPathNode()

        if self.curDestTile.x == -1 and self.curDestTile.y == -1 then 
            self.status = 'attack'
            return
        end

        if self.canInitPath then 
            local x, y = self.gameLayer.role:getPosition()
            self:findPath(self.gameLayer.mainMap:space2Tile(cc.p(x, y)));
            self.canInitPath = false
        end

        local curDestPos = self.gameLayer.mainMap:tile2Space(self.curDestTile)
        local x, y = self:getPosition()
        local curPos = cc.p(x, y)
        self.dirAtor = G_Utils.getDirVector(curPos, curDestPos)
        self.status = 'run'
    elseif self.status == 'run' then
        local posX, posY = self:getPosition()
        local x = self.speed * self.dirAtor.x + posX
        local y = self.speed * self.dirAtor.y + posY

        self:setPosition(cc.p(x, y))
        local curTile = self.gameLayer.mainMap:space2Tile(cc.p(x, y))
        if curTile.x == self.curDestTile.x and curTile.y == self.curDestTile.y then 
            self:deleteDoneNode()
            self.status = 'stand'
        end
    end

    if not self.canInitPath then 
        self.second = self.second + dt

        if self.second >= 1 then 
            self.second = 0
            self.canInitPath = true
        end
    end
end

return SpriteMonster
