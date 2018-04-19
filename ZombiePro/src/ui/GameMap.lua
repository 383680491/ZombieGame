--
-- Created by IntelliJ IDEA.
-- User: PC
-- Date: 15-2-13
-- Time: 上午11:19
-- To change this template use File | Settings | File Templates.
--

local GameMap = class("GameMap", MapView)
function GameMap:ctor()
    self.visibleSize = cc.Director:getInstance():getVisibleSize()
    self.winSize = cc.Director:getInstance():getWinSize()
    self.origin = cc.Director:getInstance():getVisibleOrigin()
    self.schedulerID = nil

end

function GameMap:registTouch()
    local function sceneEventHandler(eventType)
        if eventType == "enter" then
            if self.onEnter then self:onEnter() end
        elseif eventType == "exit" then
            if self.onExit then self:onExit() end
        end
    end

    self:registerScriptHandler(sceneEventHandler)
end

function GameMap:onEnter()
end

function GameMap:onExit()
end




--判断该直线上是否有墙
function GameMap:pathHasBlock(beginPos, endPos)
    local vector = G_Utils.getDirVector(beginPos, endPos)
    local beginTile = self:space2Tile(beginPos)
    local endTile = self:space2Tile(endPos)
    local tileWidth = self:getTileSize().width

    local temp = beginPos
    local tempTile = beginTile

    while not cc.pEqu(tempTile, endTile) do 
        temp = cc.pAdd(temp, cc.pMul(vector, tileWidth))
        tempTile = self:space2Tile(temp)
        if self:isBlock(tempTile) then 
            return true
        end
    end

    return false
end


























function GameMap:init(battle)
    self._battle = battle;
    self.tileSize = self:getTileSize()
    self.mapSize = self:getMapSize()
cclog('self.tileSize (%d,%d)', self.tileSize.width, self.tileSize.height)
cclog('self.mapSize (%d,%d)', self.mapSize.width, self.mapSize.height)
    -- self.cloudLayer = self:getLayer("cloud")
    -- self.blockLayer = self:getLayer("block")
    -- self.pipeLayer = self:getLayer("pipe")
    -- self.landLayer = self:getLayer("land")
    -- self.trapLayer = self:getLayer("trap")
    -- self.objectLayer = self:getObjectGroup("objects")
    -- self.coinLayer = self:getLayer("coin")
    -- self.flagpoleLayer = self:getLayer("flagpole")
    -- self.fogLayer = self:getLayer("fog")

    -- self.monsterList = {};
    -- self.propList = {};
    -- self.gadgetList = {};
    -- self.SpringList = {};
    -- self.enemyBulletList = {};


--[[local pox = self:positionToTileCoord(cc.p(25, 25));
cclog('pos (%d, %d)', pox.x, pox.y);
local gid = self.fogLayer:getTileGIDAt(pox);
cclog('gid = %d', gid);

得出结论：图层例如landLayer， 会有自己对应的texture，同时我们在使用的过程中是将纹理分成了很多个小块   获得的gid
实际上就是该图层对应的texture对应的块,坐标系和瓦片地图一样  gid为1的时候是左上角，假设图块被分成6*6  则gid为7为
第二行第一个    因此在对某一个瓦片更改纹理的时候要注意找到对应的纹理坐标块
--]]

    -- local childList = self:getChildren();
    -- for _, child in ipairs(childList) do
    --     child:getTexture():setAntiAliasTexParameters();
    -- end
end

-- 进行怪物的初始化，先根据name来判断是不是enemy，再细分(type)类型
function GameMap:addObjects()
    local objects = self.objectLayer:getObjects()
    for _, object in ipairs(objects) do
        cclog("addObjects %s", serialize(object))
        if object.name == "heroPos" then
            self.bornPos = cc.p(object.x, object.y);
            self.bornPos.x = self.bornPos.x + self.tileSize.width / 2;
        elseif object.name == "monster" then
            if object.type == 'stand' then
                MonsterStand:create(self._battle, cc.p(object.x, object.y))
            elseif object.type == 'LR' then
                MonsterLR:create(self._battle, object)
            elseif object.type == 'UD' then
                MonsterUD:create(self._battle, object)
            elseif object.type == 'angry' then
                MonsterAngry:create(self._battle, object)
            elseif object.type == 'throw' then
                MonsterThrow:create(self._battle, object)
                doNextFrame(function()
                    MonsterGhost:create(self._battle)
                end)
            else
                Monster:create(self._battle, cc.p(object.x, object.y))
            end
        elseif object.name == "prop" then

        elseif object.name == "gadget" then
            GadgetLadder:create(self._battle, object)
        elseif object.name == "spring" then
            Spring:create(self._battle, object);
        elseif object.name == "box" then
        elseif object.name == "drop" then
            Dropping:create(self._battle, object)
        end
    end
end


function GameMap:tileTypeforPos(tileCoord)
--cclog('tileCoord (%d, %d)', tileCoord.x, tileCoord.y)
    if tileCoord.x < 0 or tileCoord.y < 0 or tileCoord.x > self.mapSize.width or tileCoord.y > self.mapSize.height then
        return TILE_TYPE_NONE
    end

    local gid = self.landLayer:getTileGIDAt(tileCoord);
    if gid > 0 then
        return TILE_TYPE_LAND;
    end

    return TILE_TYPE_NONE
end

function GameMap:updateWarFog(heroTileCoord)
    local range = self._battle.hero:getFogRange();
    --[[for i = heroTileCoord.x - range.left, heroTileCoord.x + range.right do
        for j = heroTileCoord.y - range.down, heroTileCoord.y + range.up do
            if not ((i == heroTileCoord.x - range.width and j == heroTileCoord.y - range.height) or  --优化 去掉四个角
               (i == heroTileCoord.x - range.width and j == heroTileCoord.y + range.height) or
               (i == heroTileCoord.x + range.width and j == heroTileCoord.y + range.height) or
               (i == heroTileCoord.x + range.width and j == heroTileCoord.y - range.height))
            then
                local temp = self:sureTileCroodValid(cc.p(i,j));
                self:updateLogicTileInfo(temp);
           -- end
        end
    end]]

    self:updateLogicTileInfo(heroTileCoord);
    self:updateLogicTileInfo(cc.p(heroTileCoord.x, heroTileCoord.y - 1));
    self:updateLogicTileInfo(cc.p(heroTileCoord.x, heroTileCoord.y - 2));
    self:updateLogicTileInfo(cc.p(heroTileCoord.x, heroTileCoord.y - 3));
    self:updateLogicTileInfo(cc.p(heroTileCoord.x, heroTileCoord.y + 1));

    self:updateLogicTileInfo(cc.p(heroTileCoord.x + 1, heroTileCoord.y));
    self:updateLogicTileInfo(cc.p(heroTileCoord.x + 1, heroTileCoord.y + 1));
    self:updateLogicTileInfo(cc.p(heroTileCoord.x + 1, heroTileCoord.y - 1));
    self:updateLogicTileInfo(cc.p(heroTileCoord.x + 1, heroTileCoord.y - 2));
    self:updateLogicTileInfo(cc.p(heroTileCoord.x + 1, heroTileCoord.y - 3));

    self:updateLogicTileInfo(cc.p(heroTileCoord.x - 1, heroTileCoord.y));
    self:updateLogicTileInfo(cc.p(heroTileCoord.x - 1, heroTileCoord.y + 1));
    self:updateLogicTileInfo(cc.p(heroTileCoord.x - 1, heroTileCoord.y - 1));
    self:updateLogicTileInfo(cc.p(heroTileCoord.x - 1, heroTileCoord.y - 2));
    self:updateLogicTileInfo(cc.p(heroTileCoord.x - 1, heroTileCoord.y - 3));

    self:updateLogicTileInfo(cc.p(heroTileCoord.x - 2, heroTileCoord.y));
    self:updateLogicTileInfo(cc.p(heroTileCoord.x - 2, heroTileCoord.y + 1));
    self:updateLogicTileInfo(cc.p(heroTileCoord.x - 2, heroTileCoord.y - 1));
    self:updateLogicTileInfo(cc.p(heroTileCoord.x - 2, heroTileCoord.y - 2));
    self:updateLogicTileInfo(cc.p(heroTileCoord.x - 2, heroTileCoord.y - 3));
end

function GameMap:sureTileCroodValid(crood)
    crood.x = crood.x < 0 and 0 or crood.x;
    crood.x = crood.x >= self.mapSize.width and self.mapSize.width - 1 or crood.x;
    crood.y = crood.y < 0 and 0 or crood.y;
    crood.y = crood.y >= self.mapSize.height and self.mapSize.height - 1 or crood.y;

    return crood;
end

--http://www.benmutou.com/archives/455
--http://bbs.9ria.com/thread-157487-1-1.html
function GameMap:updateLogicTileInfo(tileCrood)                       --每一个坐标 都需要更新该坐标的 右边 右下 右下角  四个坐标
    if self:setTileInfo(self:sureTileCroodValid(tileCrood), 4) then
        self:setTileInfo(self:sureTileCroodValid(cc.p(tileCrood.x + 1, tileCrood.y)), 8);
        self:setTileInfo(self:sureTileCroodValid(cc.p(tileCrood.x, tileCrood.y + 1)), 1);
        self:setTileInfo(self:sureTileCroodValid(cc.p(tileCrood.x + 1, tileCrood.y + 1)), 2);
    end
end

function GameMap:setTileInfo(crood, textureIndex)
    local tileSprite = self.fogLayer:getTileAt(crood);
    if not tileSprite.myCustomUserData then
        tileSprite.myCustomUserData = {};
        table.insert(tileSprite.myCustomUserData, textureIndex)
    else
        if not self:IsValidFun(tileSprite.myCustomUserData, textureIndex) then
            return
        end

        local total = self:TotalNumFun(tileSprite.myCustomUserData)
        if total == 15 then
            return
        end

        table.insert(tileSprite.myCustomUserData, textureIndex)
    end

    local total = self:TotalNumFun(tileSprite.myCustomUserData);
    self.fogLayer:setTileGID(64 + mapFogTextureIndex[total + 1], crood);

    return true
end

function GameMap:TotalNumFun(list)
    local argv = 0;
    for _, num in ipairs(list) do
        argv = argv + num;
    end

    return argv;
end

function GameMap:IsValidFun(list, varg)
    local flag = true; --每一个列表里面 有且只能有 单独一个  1、2、4、8
    for _, num in ipairs(list) do
        if num == varg then
            flag = false;
            break;
        end
    end

    return flag;
end
















--瓦片地图从0,0开始  由上而下 由左到右
function GameMap:positionToTileCoord(pos)
    local x = math.floor(pos.x / self.tileSize.width);
    local y = math.floor((self.mapSize.height) - pos.y / self.tileSize.height);

    return cc.p(x, y)
end

function GameMap:tilecoordToPosition(tileCoord)       --此算法并非平常的瓦片地图的中心点 而是计算的是左下角
    local x = tileCoord.x * self.tileSize.width;
    local y = (self.mapSize.height - 1 - tileCoord.y) * self.tileSize.height;

    return cc.p(x, y);
end

function GameMap:getHeroBornPos()
    return self.bornPos
end

function GameMap:getMonsterList()
    return self.monsterList
end

function GameMap:getEnemyBulletList()
    return self.enemyBulletList
end

function GameMap:getGadgetList()
    return self.gadgetList
end

function GameMap:getSpringList()
    return self.SpringList
end

function GameMap:getFogLayer()
    return self.fogLayer
end


return GameMap
