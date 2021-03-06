--
-- Created by IntelliJ IDEA.
-- User: PC
-- Date: 15-2-13
-- Time: 上午11:19
-- To change this template use File | Settings | File Templates.
--
local device = require 'cocos.framework.device'
local GameMap = require 'ui.GameMap'
local GameLayer = class("GameLayer", require 'ui.base.BaseView')
GameLayer.__index = GameLayer
GameLayer.__instance = nil

function GameLayer:create(path)
    local ret = GameLayer.new(path)
    ret:init()
    ret:initJoy()

    return ret
end

function GameLayer:ctor()
    GameLayer.super:ctor()
    self.schedulerID = nil
    self:setMoudleId(G_LayerDefine.BATTLE_LAYER)
end

function GameLayer:init()
    self.mineList = {};
    self.roleList = {};
    self.monsterList = {}
    self.heroAnchor = cc.p(self.winSize.width / 2 - 80, self.winSize.height / 2)    --主角走到屏幕的该点后地图就开始跟随

    self.bottomLayer = cc.Node:create();                         --底层
    self.bottomLayer:setPosition(cc.p(0, 0));
    self:addChild(self.bottomLayer, 1, 1);

    self.mainLayer = cc.Layer:create();                          --游戏层
    self.mainLayer:setAnchorPoint(0, 0);
    self.mainLayer:setPosition(cc.p(0, 0));
    self:addChild(self.mainLayer, 2, 2);

    self.upLayer = cc.Node:create();                             --上面层 比如 战斗UI在这一层
    self.upLayer:setPosition(cc.p(0, 0));
    self:addChild(self.upLayer, 3, 3);

    local GameUI = require 'ui.GameUI'
    local layer = GameUI.new()
    self.upLayer:addChild(layer)
    layer:setGameLayer(self)

    self.topLayer = cc.Node:create();                            --顶层
    self.topLayer:setPosition(cc.p(0, 0));
    self:addChild(self.topLayer, 4, 4);

    local GameMap = require 'ui.GameMap'
    self.mainMap = GameMap:new()
    self.mainMap:setPosition(cc.p(0, 0))
    self.mainMap:load('tileMap/map_1.tmx')
    self.mainLayer:addChild(self.mainMap, 5000, 5000);

    local spriteFrameCache = cc.SpriteFrameCache:getInstance()
    spriteFrameCache:addSpriteFrames('bomb.plist', 'bomb.png')

    local SpriteRole = require 'ui.widget.SpriteRole'
    self.mainRole = SpriteRole:new(5110511)
    self.mainRole:setPosition(cc.p(600, 100))
    self.mainRole:setGameLayer(self)
    self.mainMap:addChild(self.mainRole)
    table.insert(self.roleList, self.mainRole)

    self.mapSize = cc.size(self.mainMap:getMapSize().width * self.mainMap:getTileSize().width,
        self.mainMap:getMapSize().height * self.mainMap:getTileSize().height);
look(self.mapSize, 'self.mapSize===')
    self:scheduleUpdate();
    --self:updateBattleFog();
    self:registerTouch()
    self:registerKey()
end

function GameLayer:initJoy()
    local JoyStick = require 'utils.JoyStick'
    local JoyStick_left = JoyStick:create()
    JoyStick_left:setDetegate(self)
    JoyStick_left.isFollowTouch = true
    JoyStick_left:setPosition(cc.p(300, 200))
    JoyStick_left:setHitAreaWithRect(cc.rect(0, 0, 640, 720))
    self:addChild(JoyStick_left, 4, 4)
end

function GameLayer:onJoyStickUpdate(joyStick, angle, direct, power)
    -- look(angle, 'angle')
    -- look(direct, 'direct')
    -- look(power, 'power')

    self.mainRole:move(angle, direct, power)
end

function GameLayer:scheduleUpdate()
    local update = function(dt)
        self:update(dt);
    end

    self:scheduleUpdateWithPriorityLua(update, 0);
end

function GameLayer:onEnter()

end

function GameLayer:onExit()
    self:unscheduleUpdate();
end

function GameLayer:getBombList()
    return self.bombList
end

function GameLayer:update(dt)
    --self:setMapScrollPosition(dt);
    self:deleteObj()
    self:dealCollision()
    --self:updateBattleFog();
end

function GameLayer:setMapScrollPosition(dt)
    local heroPosX, heroPosY = self.mainRole:getPosition()
    local x = math.max(heroPosX, self.heroAnchor.x);
    local y = math.max(heroPosY, self.heroAnchor.y);

    x = math.min(x, self.mapSize.width - self.winSize.width / 2 - 80);
    y = math.min(y, self.mapSize.height - self.winSize.height / 2);

    local viewPointX = self.heroAnchor.x - x;
    local viewPointY = self.heroAnchor.y - y;
    self.mainLayer:setPosition(viewPointX, viewPointY);
end


function GameLayer:onTouchBegan(touch, event)
    local touchPoint = touch:getLocation()
    local pos = self.mainMap:convertToNodeSpace(touchPoint)
   -- look(pos, 'onTouchBegan pos')

    -- local heroPosX, heroPosY = self.mainRole:getPositionX(), self.mainRole:getPositionY();
    -- if self.mainMap:pathHasBlock(cc.p(heroPosX, heroPosY), pos) then 
    --     look('block！！！！！！！！！！！！！！！！！！！！！！！！！')
    -- else
    --     look('NONOONOONONONONO~~~~~~~~~~~block')
    -- end

    return true
end

function GameLayer:onKeyPressed(code, event)
    if code == cc.KeyCode['KEY_K'] then 
        self:attack()
    end
end

-- function GameLayer:dealCollision(dt)
--     local monsterCount = #self.monsterList;
--     for monsterIndex = 1, monsterCount do
--         local monster = self.monsterList[monsterIndex];
--         if monster and monster:isDead() then
--             table.remove(self.monsterList, monsterIndex)
--             monster:removeFromParent();  --
--         end
--     end

--     for _, role in ipairs(self.roleList) do 
--         local rX, rY = role:getPosition()
--         local list = {}
--         for _, monster in ipairs(self.monsterList) do 
--             local mX, mY = monster:getPosition()
--             local distance = cc.pGetDistance(cc.p(rX, rY), cc.p(mX, mY))
--             if distance <= role:getAttackRadius() then 
--                 table.insert(list, monster)
--             end
--         end

--         role:setTargetList(list)
--     end
-- end

function GameLayer:dealCollision(dt)
    for _, role in ipairs(self.roleList) do 
        local rX, rY = role:getPosition()
        local list = {}
        for _, monster in ipairs(self.monsterList) do 
            if monster and not monster:isDead() then
                local mX, mY = monster:getPosition()
                local distance = cc.pGetDistance(cc.p(rX, rY), cc.p(mX, mY))
                if distance <= role:getAttackRadius() then 
                    table.insert(list, monster)
                end
            end
        end

        role:setTargetList(list)
    end
end


function GameLayer:deleteObj()
    --mine
    for i = 1, #self.mineList do 
        local mine = self.mineList[i]
        if mine and 5 == mine:getStatus() then 
            mine:removeFromParent()
            table.remove(self.mineList, i)
        end
    end

    --monster
    local monsterCount = #self.monsterList;
    for monsterIndex = 1, monsterCount do
        local monster = self.monsterList[monsterIndex];
        if monster and 'deaded' == monster:getStatus() then
            for _, role in ipairs(self.roleList) do 
                role:deleteTarget(monster)
            end

            table.remove(self.monsterList, monsterIndex)
            monster:removeFromParent();  --
        end
    end
end

function GameLayer:attack()
    self.mainRole:attack()
end


function GameLayer:makeMine()
    self.mainRole:makeMine()
end


function GameLayer:makeDefense()
    self.mainRole:makeDefense()
end

function GameLayer:removeDefense()
    self.mainRole:removeDefense()
end

function GameLayer:getHeroStatus()
    return self.mainRole:getStatus()
end


function GameLayer:addMonster()
    math.newrandomseed()

    local posList = {
        cc.p(0, 0),
        cc.p(0, self.winSize.height),
        cc.p(self.winSize.width, self.winSize.height),
        cc.p(self.winSize.width, 0),
    }

    for i= 1, 3 do 
        local torward = math.random(1, 4)
        local pos = posList[torward]

        local x = math.random(40, 70)
        local y = math.random(40, 70)

        if 1 == torward then 
            pos.x = pos.x + x
            pos.y = pos.y + y
        elseif 2 == torward then
            pos.x = pos.x + x
            pos.y = pos.y - y
        elseif 3 == torward then
            pos.x = pos.x - x
            pos.y = pos.y - y
        elseif 4 == torward then
            pos.x = pos.x - x
            pos.y = pos.y + y
        end

        local SpriteMonster = require 'ui.widget.SpriteMonster'
        local monster = SpriteMonster:new(20005)
        monster:setPosition(pos)
        monster:setGameLayer(self)
        self.mainMap:addChild(monster)
        table.insert(self.monsterList, monster)
        monster:createPath()
        monster:findPath(self.mainMap:space2Tile(cc.p(self.mainRole:getPositionX(), self.mainRole:getPositionY())))
    end
end





function GameLayer:addBossA()
    math.newrandomseed()

    local posList = {
        cc.p(0, 0),
        cc.p(0, self.winSize.height),
        cc.p(self.winSize.width, self.winSize.height),
        cc.p(self.winSize.width, 0),
    }

    local torward = math.random(1, 4)
    local pos = posList[torward]

    local x = math.random(40, 70)
    local y = math.random(40, 70)

    if 1 == torward then 
        pos.x = pos.x + x
        pos.y = pos.y + y
    elseif 2 == torward then
        pos.x = pos.x + x
        pos.y = pos.y - y
    elseif 3 == torward then
        pos.x = pos.x - x
        pos.y = pos.y - y
    elseif 4 == torward then
        pos.x = pos.x - x
        pos.y = pos.y + y
    end

    local SpriteMonster = require 'ui.widget.SpriteBossA '
    local monster = SpriteMonster:new(20005)
    monster:setPosition(pos)
    monster:setGameLayer(self)
    self.mainMap:addChild(monster)
    table.insert(self.monsterList, monster)
    monster:createPath()
    monster:findPath(self.mainMap:space2Tile(cc.p(self.mainRole:getPositionX(), self.mainRole:getPositionY())))
end




function GameLayer:addBossB()
    math.newrandomseed()

    local posList = {
        cc.p(0, 0),
        cc.p(0, self.winSize.height),
        cc.p(self.winSize.width, self.winSize.height),
        cc.p(self.winSize.width, 0),
    }

    local torward = math.random(1, 4)
    local pos = posList[torward]

    local x = math.random(40, 70)
    local y = math.random(40, 70)

    if 1 == torward then 
        pos.x = pos.x + x
        pos.y = pos.y + y
    elseif 2 == torward then
        pos.x = pos.x + x
        pos.y = pos.y - y
    elseif 3 == torward then
        pos.x = pos.x - x
        pos.y = pos.y - y
    elseif 4 == torward then
        pos.x = pos.x - x
        pos.y = pos.y + y
    end

    local SpriteMonster = require 'ui.widget.SpriteBossB'
    local monster = SpriteMonster:new(20005)
    monster:setPosition(pos)
    monster:setGameLayer(self)
    self.mainMap:addChild(monster)
    table.insert(self.monsterList, monster)
    monster:createPath()
    monster:findPath(self.mainMap:space2Tile(cc.p(self.mainRole:getPositionX(), self.mainRole:getPositionY())))
end





















function GameLayer:updateBattleFog()
    local heroX, heroY = self.hero:getPosition();
    local pos = self.mainMap:positionToTileCoord(cc.p(heroX, heroY));
    if self.heroLastTilePos.x ~= pos.x or self.heroLastTilePos.y ~= pos.y then
        self.mainMap:updateWarFog(pos);
        self.heroLastTilePos = pos;
    end
end


function GameLayer:onButtonMap(pSender, eventType)
    if eventType == ccui.TouchEventType.began then
        self:pause();
        self._mainLayerCurPos = cc.p(self.mainLayer:getPositionX(), self.mainLayer:getPositionY());
        self.mainLayer:setScaleX(self.winSize.width / self.mapSize.width)
        self.mainLayer:setScaleY(self.winSize.height / self.mapSize.height)
        self.mainLayer:setPosition(cc.p(0, 0))
    elseif eventType == ccui.TouchEventType.moved then
    elseif eventType == ccui.TouchEventType.ended then
        self:resume();
        self.mainLayer:setScaleX(1)
        self.mainLayer:setScaleY(1)
        self.mainLayer:setPosition(self._mainLayerCurPos);
    elseif eventType == ccui.TouchEventType.canceled then
        self:resume();
        self.mainLayer:setScaleX(1)
        self.mainLayer:setScaleY(1)
        self.mainLayer:setPosition(self._mainLayerCurPos);
    end
end





















--暂停所有
function GameLayer:pause()
    local monsterList = self.mainMap:getMonsterList()
    local enemyBulletList = self.mainMap:getEnemyBulletList()
    local gadgetList = self.mainMap:getGadgetList()
    local springList = self.mainMap:getSpringList()
    local bombList = self.bombList;

    for _, monster in ipairs(monsterList) do
        monster:unscheduleUpdate();
    end

    for _, enemyBullet in ipairs(enemyBulletList) do
        enemyBullet:unscheduleUpdate();
    end

    for _, gadget in ipairs(gadgetList) do
        gadget:unscheduleUpdate();
    end

    for _, spring in ipairs(springList) do
        spring:unscheduleUpdate();
    end

    for _, bomb in ipairs(bombList) do
        bomb:unscheduleUpdate();
    end

    --self.mainMap:getFogLayer():setVisible(false);
    self:unscheduleUpdate();
end

--回复所有
function GameLayer:resume()
    local monsterList = self.mainMap:getMonsterList()
    local enemyBulletList = self.mainMap:getEnemyBulletList()
    local gadgetList = self.mainMap:getGadgetList()
    local springList = self.mainMap:getSpringList()
    local bombList = self.bombList;

    for _, monster in ipairs(monsterList) do
        monster:scheduleUpdate();
    end

    for _, enemyBullet in ipairs(enemyBulletList) do
        enemyBullet:scheduleUpdate();
    end

    for _, gadget in ipairs(gadgetList) do
        gadget:scheduleUpdate();
    end

    for _, spring in ipairs(springList) do
        spring:scheduleUpdate();
    end

    for _, bomb in ipairs(bombList) do
        bomb:scheduleUpdate();
    end

    --self.mainMap:getFogLayer():setVisible(true);
    self:scheduleUpdate();
end


return GameLayer