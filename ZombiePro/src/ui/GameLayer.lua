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
    self.visibleSize = cc.Director:getInstance():getVisibleSize()
    self.winSize = cc.Director:getInstance():getWinSize()
    self.origin = cc.Director:getInstance():getVisibleOrigin()
    self.schedulerID = nil
    self:setMoudleId(G_LayerDefine.BATTLE_LAYER)
end

function GameLayer:init()
    self.bombList = {};
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

    self.topLayer = cc.Node:create();                            --顶层
    self.topLayer:setPosition(cc.p(0, 0));
    self:addChild(self.topLayer, 4, 4);

    local GameMap = require 'ui.GameMap'
    self.mainMap = GameMap:new()
    self.mainMap:loadMapNew('tileMap/map_1.tmx', 1001, cc.p(0, 0))
    self.mainLayer:addChild(self.mainMap, 5000, 5000);

    local spriteFrameCache = cc.SpriteFrameCache:getInstance()
    spriteFrameCache:addSpriteFrames('role/role_5110511.plist', 'role/role_5110511.png') 
    spriteFrameCache:addSpriteFrames('monster/20005.plist', 'monster/20005.png')

    local SpriteRole = require 'ui.widget.SpriteRole'
    self.mainRole = SpriteRole:new(5110511)
    self.mainRole:setPosition(cc.p(600, 430))
    self.mainRole:setGameLayer(self)
    self.mainMap:addChild(self.mainRole)
    table.insert(self.roleList, self.mainRole)

    for i= 1, 1 do 
        local x = math.random(200, 800)
        local y = math.random(200, 800)
        local SpriteMonster = require 'ui.widget.SpriteMonster'
        local monster = SpriteMonster:new(20005)
        monster:setPosition(cc.p(900, 330))
        monster:setGameLayer(self)
        self.mainMap:addChild(monster)
        table.insert(self.monsterList, monster)
        monster:createPath()
        monster:findPath(self.mainMap:space2Tile(cc.p(600, 430)))
    end

    self.mapSize = cc.size(self.mainMap:getMapSize().width * self.mainMap:getTileSize().width,
        self.mainMap:getMapSize().height * self.mainMap:getTileSize().height);
    self:scheduleUpdate();
    --self:updateBattleFog();
    self:registerTouch()
    self:registerKey()
end

function GameLayer:initJoy()
    local JoyStick = require 'utils.JoyStick'
    local JoyStick_left = JoyStick:create()
    JoyStick_left:setDetegate(self)
    JoyStick_left.isFollowTouch = false
    JoyStick_left:setPosition(cc.p(300, 200))
    JoyStick_left:setHitAreaWithRect(cc.rect(230, 130, 255, 255))
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
    self:setMapScrollPosition(dt);
    self:dealCollision()
    --self:updateBattleFog();
end

function GameLayer:setMapScrollPosition(dt)
    local heroPosX, heroPosY = self.mainRole:getPositionX(), self.mainRole:getPositionY();
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

function GameLayer:dealCollision(dt)
    local monsterCount = #self.monsterList;
    for monsterIndex = 1, monsterCount do
        local monster = self.monsterList[monsterIndex];
        if monster and monster:isDead() then
            table.remove(self.monsterList, monsterIndex)
            monster:removeFromParent();  --
        end
    end

    for _, role in ipairs(self.roleList) do 
        local rX, rY = role:getPosition()
        local list = {}
        for _, monster in ipairs(self.monsterList) do 
            local mX, mY = monster:getPosition()
            local distance = cc.pGetDistance(cc.p(rX, rY), cc.p(mX, mY))
            if distance <= role:getAttackRadius() then 
                table.insert(list, monster)
            end
        end

        role:setTargetList(list)
    end
end


function GameLayer:attack()
    self.mainRole:attack()
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