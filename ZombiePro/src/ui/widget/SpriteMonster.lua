local SpriteMonster = class('SpriteMonster', require 'ui.base.SpriteBase')

--怪物寻路分两种状态  第一根据选路算法去行走  第二 如果和英雄靠的足够近且中间没有墙则直接锁定玩家，如果还是A*算法走路 怪物会看起来特么蠢
local FindPath_NeedLen = 3   --当A*算法路径低于n个时 则开始判断是否切换状态
local FindPath_Star = 1
local FindPath_Lock = 2

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

    self.speed = 2

    --self:getTorwardIDByDir()
    --self:runAnimal()
    self.mainSprite:loadTexture('monster.png')
    self.mainSprite:setScale(0.5)
    self:scheduleUpdate();

    self.status = 'stand'
    self.second = 0
    self.halfSecond = 0
    self.canInitPath = false
    self.findPathStatus = FindPath_Star
    if DEBUG_MOD then 
        self:drawRect()
    end
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
    local speed = self.speed
    self.second = self.second + dt
    self.halfSecond = self.halfSecond + dt

    for bufId, target in pairs(self.buffList) do 
        if target:isOver() then 
            target:removeFromParent()
            self.buffList[bufId] = nil
        else
            if bufId == 101 then 
                speed = 0
            elseif bufId == 102 then

            end
        end
    end

    --击飞状态下的逻辑
    if self.strikeFlyInfo then 
        if self.strikeFlyInfo.time <= 0 then 
            self.status = 'stand'
            self.canInitPath = true
            self.strikeFlyInfo = nil
            return
        end

        local posX, posY = self:getPosition()
        local x = speed * self.strikeFlyInfo.dirAtor.x + posX
        local y = speed * self.strikeFlyInfo.dirAtor.y + posY
        local tile = self.gameLayer.mainMap:space2Tile(cc.p(x, y))
        local isBlock = self.gameLayer.mainMap:isBlock(tile)

        if isBlock then 
            self.strikeFlyInfo = nil
        else
            self:setPosition(cc.p(x, y))
            self.strikeFlyInfo.time = self.strikeFlyInfo.time - dt
        end

        return
    end

    if self.status == 'stand' then 
        self.curDestTile = self:getPathNode()

        if self.curDestTile.x == -1 and self.curDestTile.y == -1 then 
            self.status = 'attack'
            return
        end

        local heroX, heroY = self.gameLayer.mainRole:getPosition()
        if self.canInitPath then 
            self:findPath(self.gameLayer.mainMap:space2Tile(cc.p(heroX, heroY)));
            self.curDestTile = self:getPathNode()
            self.canInitPath = false
        end

        if self.findPathStatus == FindPath_Star then 
            local pathCount = self:getPathCount()
            if pathCount <= FindPath_NeedLen then 
                local x, y = self:getPosition()

                if not self.gameLayer.mainMap:pathHasBlock(cc.p(x, y), cc.p(heroX, heroY)) then --数量小于FindPath_NeedLen 且没有墙，进入锁定模式
                    self.findPathStatus = FindPath_Lock
                end
            end
        end

        local curDestPos
        if self.findPathStatus == FindPath_Lock then 
            curDestPos = cc.p(heroX, heroY)
        else
            --因为寻路算法并不考虑模型的大小  得根据当前的tile和模型大小来确定新的tile
            curDestPos = self.gameLayer.mainMap:tile2Space(self.curDestTile)
            local tileWidth, tileHeight = self.gameLayer.mainMap:getTileSize().width, self.gameLayer.mainMap:getTileSize().height
            local wCount = math.ceil(self.hurtRadius / tileWidth) 
            local hCount = math.ceil(self.hurtRadius / tileHeight) 

            --右边有墙
            local flag = -1
            for i = wCount - 1, 1, -1 do 
                local isBlock = self.gameLayer.mainMap:isBlock(cc.pAdd(self.curDestTile, cc.p(i, 0)))
                if isBlock then 
                    flag = i
                    break
                end
            end
            if flag ~= -1 then 
                curDestPos.x = curDestPos.x - (wCount - flag) * tileWidth
            end

            --左边
            flag = -1
            for i = wCount, 1, -1 do 
                local isBlock = self.gameLayer.mainMap:isBlock(cc.pSub(self.curDestTile, cc.p(i, 0)))
                if isBlock then 
                    flag = i
                    break
                end
            end
            if flag ~= -1 then 
                curDestPos.x = curDestPos.x + (wCount - flag + 1) * tileWidth
            end

            --上边
            flag = -1
            for i = hCount - 1, 1, -1 do 
                local isBlock = self.gameLayer.mainMap:isBlock(cc.pSub(self.curDestTile, cc.p(0, i)))
                if isBlock then 
                    flag = i
                    break
                end
            end
            if flag ~= -1 then 
                curDestPos.y = curDestPos.y - (hCount - flag) * tileHeight
            end

            --下边
            flag = -1
            for i = hCount, 1, -1 do 
                local isBlock = self.gameLayer.mainMap:isBlock(cc.pAdd(self.curDestTile, cc.p(0, i)))
                if isBlock then 
                    flag = i
                    break
                end
            end
            if flag ~= -1 then 
                curDestPos.y = curDestPos.y + (hCount - flag + 1) * tileHeight
            end

            self.curDestTile = self.gameLayer.mainMap:space2Tile(curDestPos)
        end

        local x, y = self:getPosition()
        local curPos = cc.p(x, y)
        self.dirAtor = G_Utils.getDirVector(curPos, curDestPos)

        local radian = cc.pToAngleSelf(self.dirAtor)
        local angle = radian / 3.14159 * 180 --弧度变角度 
        self:setRotation(270 - angle)

        self.status = 'run'
    elseif self.status == 'run' then
        local posX, posY = self:getPosition()
        local x = speed * self.dirAtor.x + posX
        local y = speed * self.dirAtor.y + posY

        self:setPosition(cc.p(x, y))

        if self.findPathStatus == FindPath_Star then--非寻路模式不要执行下面的逻辑
            local curTile = self.gameLayer.mainMap:space2Tile(cc.p(x, y))
            if curTile.x == self.curDestTile.x and curTile.y == self.curDestTile.y then 
                self:deleteDoneNode()
                self.status = 'stand'
            end
        end
    end

    if self.second >= 1 then 
        self.second = 0

        if not self.canInitPath then
            self.canInitPath = true
        end
    end

    if self.halfSecond >= 0.3 then 
        self.halfSecond = 0.3

        --FindPath_Lock模式下   0.5秒判断一次方向和墙
        if FindPath_Lock == self.findPathStatus and self.status == 'run' then 
            local heroX, heroY = self.gameLayer.mainRole:getPosition()
            local x, y = self:getPosition()

            local curDestPos = cc.p(heroX, heroY)
            local curPos = cc.p(x, y)

            if self.gameLayer.mainMap:pathHasBlock(curPos, curDestPos) then --有墙则进入寻路状态 每帧都有判断墙会不会太耗性能？
                self.findPathStatus = FindPath_Star
                self.status = 'stand'
                self.canInitPath = true
                return
            end

            self.dirAtor = G_Utils.getDirVector(curPos, curDestPos)
            local radian = cc.pToAngleSelf(self.dirAtor)
            local angle = radian / 3.14159 * 180 --弧度变角度 
            self:setRotation(270 - angle)
        end
    end
end
--击飞strikeFly
function SpriteMonster:strikeFly(data)
    self.strikeFlyInfo = data
end

return SpriteMonster
