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
    ret:registTouch()

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
    self.moveStep = 2;                       --每帧要移动的距离
    self.moveDelta = 0.05;                   --为了模拟出加速度效果，移动增量

    self.moveOffset = 0;                     --水平移动偏移量
    self.jumpOffset = 0;                     --垂直跳跃的偏移量
    self.heroLastTilePos = cc.p(0, 0);

    self.controlStatus = HERO_STATUS_RIGHT_STAND;
    self.bombList = {};

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
    self.mainMap:loadMapNew('mapnew/hujz.tmx', 1001, cc.p(0, 0))
    self.mainLayer:addChild(self.mainMap, 5000, 5000);

    local spriteFrameCache = cc.SpriteFrameCache:getInstance()
    spriteFrameCache:addSpriteFrames('role/5110511.plist', 'role/5110511.png') 
    spriteFrameCache:addSpriteFrames('monster/20005.plist', 'monster/20005.png')

    local SpriteRole = require 'ui.widget.SpriteRole'
    self.role = SpriteRole:new(5110511)
    self.role:setPosition(cc.p(1200, 430))
    self.role:setGameLayer(self)
    self.mainMap:addChild(self.role)

    for i= 1, 500 do 
        local x = math.random(200, 800)
        local y = math.random(200, 800)
        local SpriteMonster = require 'ui.widget.SpriteMonster'
        local monster = SpriteMonster:new(20005)
        monster:setPosition(cc.p(x, y))
        monster:setGameLayer(self)
        self.mainMap:addChild(monster)
        monster:createPath()
        monster:findPath(self.mainMap:space2Tile(cc.p(1200, 430)))
    end



    self.mapSize = cc.size(self.mainMap:getMapSize().width * self.mainMap:getTileSize().width,
        self.mainMap:getMapSize().height * self.mainMap:getTileSize().height);
look(self.mapSize, 'self.mapSize')
    self:scheduleUpdate();
    --self:updateBattleFog();
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
    look(angle, 'angle')
    look(direct, 'direct')
    look(power, 'power')

    self.role:move(angle, direct, power)
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
    --self:updateBattleFog();
end

function GameLayer:setMapScrollPosition(dt)
    local heroPosX, heroPosY = self.role:getPositionX(), self.role:getPositionY();
    local x = math.max(heroPosX, self.heroAnchor.x);
    local y = math.max(heroPosY, self.heroAnchor.y);

    x = math.min(x, self.mapSize.width - self.winSize.width / 2 - 80);
    y = math.min(y, self.mapSize.height - self.winSize.height / 2);

    local viewPointX = self.heroAnchor.x - x;
    local viewPointY = self.heroAnchor.y - y;

    self.mainLayer:setPosition(viewPointX, viewPointY);
end





function GameLayer:updateControl(dt)
if not self.hero:isHeroDied() then
    if self.controlStatus == HERO_STATUS_RIGHT_WALKING then
        self.moveOffset = self.hero:getSpeedX();
    elseif self.controlStatus == HERO_STATUS_LEFT_WALKING then
        self.moveOffset = -self.hero:getSpeedX();
    elseif self.controlStatus == HERO_STATUS_RIGHT_STAND then
        self.moveOffset = 0;
    elseif self.controlStatus == HERO_STATUS_LEFT_STAND then
        self.moveOffset = 0;
    elseif self.controlStatus == HERO_STATUS_JUMP then
        self.moveOffset = 0;
    elseif self.controlStatus == HERO_STATUS_RIGHT_JUMP then
    elseif self.controlStatus == HERO_STATUS_LEFT_JUMP then
    elseif self.controlStatus == HERO_STATUS_BOM then
        self.moveOffset = 0;
    elseif self.controlStatus == HERO_STATUS_LEFT_BOM then
    elseif self.controlStatus == HERO_STATUS_RIGHT_BOM then
    end
end
end






















function GameLayer:dealCollision(dt)
    local isHeroSuper = self.hero:isSuper();
    local heroRect = self.hero:getCollisionRect();
    local monsterList = self.mainMap:getMonsterList()
    local enemyBulletList = self.mainMap:getEnemyBulletList()

    for _, bomb in ipairs(self.bombList) do
        if bomb and BULLET_STATUS_ACTIVE == bomb:getStatus() then
            local bombRect = bomb:getHarmCollisionRect();

            for _, monster in ipairs(monsterList) do
                local monsterRect = monster:getCollisionRect();
                if (MONSTER_STATUS_ACTIVE == monster:getStatus() or MONSTER_STATUS_NO_ACTIVE == monster:getStatus()) and
                        BULLET_STATUS_ACTIVE == bomb:getStatus() and
                        math.abs(bombRect.x - monsterRect.x) < 600 and
                        math.abs(bombRect.y - monsterRect.y) < 600 and
                        cc.rectIntersectsRect(monsterRect, bombRect) then
                    monster:setHarm(bomb:getAttackValue());
                end
            end

            if not isHeroSuper and BULLET_STATUS_ACTIVE == bomb:getStatus() and
                    math.abs(bombRect.x - heroRect.x) < 600 and
                    math.abs(bombRect.y - heroRect.y) < 600 and
                    cc.rectIntersectsRect(bombRect, heroRect) then
                --self.hero:setHeroLifeStatus(HERO_LIFE_DIE);
            end

            bomb:setStatus(BULLET_STATUS_CLEAR);
        end
    end

    for _, monster in ipairs(monsterList) do
        if monster then
            local monsterRect = monster:getCollisionRect();
            if not isHeroSuper and (MONSTER_STATUS_ACTIVE == monster:getStatus() or MONSTER_STATUS_ANGRY == monster:getStatus()) and
                    math.abs(monsterRect.x - heroRect.x) < 600 and
                    math.abs(monsterRect.y - heroRect.y) < 600 and
                    cc.rectIntersectsRect(monsterRect, heroRect) then
                --self.hero:setHeroLifeStatus(HERO_LIFE_DIE);
            end
        end
    end

    local bombCount = #self.bombList
    for bombIndex = 1, bombCount do
        local bomb = self.bombList[bombIndex]
        if bomb and BULLET_STATUS_CLEAR == bomb:getStatus() then
            table.remove(self.bombList, bombIndex)

            if bomb == self.hero:getCurBomb() then
                self.hero.curBomb = nil;
            end

            bomb:removeFromParent();
        end
    end

    local monsterCount = #monsterList;
    for monsterIndex = 1, monsterCount do
        local monster = monsterList[monsterIndex];
        if monster and MONSTER_STATUS_DEAD == monster:getStatus() then
            table.remove(monsterList, monsterIndex)
            monster:removeFromParent();
        end
    end

    local monsterCount = #monsterList;
    for monsterIndex = 1, monsterCount do
        local monster = monsterList[monsterIndex];
        if monster and MONSTER_STATUS_DEAD == monster:getStatus() then
            table.remove(monsterList, monsterIndex)
            monster:removeFromParent();
        end
    end

    local enemyBulletCount = #enemyBulletList;
    for enemyBulletIndex = 1, enemyBulletCount do
        local bullut = enemyBulletList[enemyBulletIndex];
        if bullut and BULLET_STATUS_CLEAR == bullut:getStatus() then
            table.remove(enemyBulletList, enemyBulletIndex)
            bullut:removeFromParent();
        end
    end
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



--touch 事件
function GameLayer:registTouch()
    local onBegan = function(touch, event)
        return self:onTouchBegan(touch, event)
    end

    local onMove = function(touch, event)
        self:onTouchMoved(touch, event)
    end

    local onEnded = function(touch, event)
        self:onTouchEnded(touch, event)
    end

    local onCancelled = function(touch, event)
        self:onCancelled(touch, event)
    end

    local listener = cc.EventListenerTouchOneByOne:create()
    listener:registerScriptHandler(onBegan, cc.Handler.EVENT_TOUCH_BEGAN )
    listener:registerScriptHandler(onMove, cc.Handler.EVENT_TOUCH_MOVED )
    listener:registerScriptHandler(onEnded, cc.Handler.EVENT_TOUCH_ENDED )
    listener:registerScriptHandler(onCancelled, cc.Handler.EVENT_TOUCH_CANCELLED )

    local eventDispatcher = self:getEventDispatcher()
    eventDispatcher:addEventListenerWithSceneGraphPriority(listener, self)

    local function sceneEventHandler(eventType)
        if eventType == "enter" then
            if self.onEnter then self:onEnter() end
        elseif eventType == "exit" then
            if self.onExit then self:onExit() end
        end
    end

    self:registerScriptHandler(sceneEventHandler)

    if device.platform == "windows" then
        local onKeyPressed = function(keyCode, event)
            return self:onKeyPressed(keyCode, event)
        end

        local onKeyReleased = function(keyCode, event)
            self:onKeyReleased(keyCode, event)
        end

        listener = cc.EventListenerKeyboard:create()
        listener:registerScriptHandler(onKeyPressed, cc.Handler.EVENT_KEYBOARD_PRESSED)
        listener:registerScriptHandler(onKeyReleased, cc.Handler.EVENT_KEYBOARD_RELEASED)
        eventDispatcher:addEventListenerWithSceneGraphPriority(listener, self)
    end
end

return GameLayer