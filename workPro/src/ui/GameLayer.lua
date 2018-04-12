--
-- Created by IntelliJ IDEA.
-- User: PC
-- Date: 15-2-13
-- Time: 上午11:19
-- To change this template use File | Settings | File Templates.
--

GameLayer = class("GameLayer", function()
    return cc.Layer:create()
end)

GameLayer.__index = GameLayer
GameLayer.__instance = nil

function GameLayer:create(path)
    local ret = GameLayer.new(path)
    ret:init()
    ret:registTouch()

    return ret
end

function GameLayer:ctor()
    self.visibleSize = cc.Director:getInstance():getVisibleSize()
    self.winSize = cc.Director:getInstance():getWinSize()
    self.origin = cc.Director:getInstance():getVisibleOrigin()
    self.schedulerID = nil
end

function GameLayer:init()
    ccs.ArmatureDataManager:getInstance():addArmatureFileInfo("res/bomb/BombermenAnimation.ExportJson")

    self.moveStep = 2;                       --每帧要移动的距离
    self.moveDelta = 0.05;                   --为了模拟出加速度效果，移动增量
    self.jumpStep = GAME_GRAVITY;                   --为了模拟出加速度效果，移动增量

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

    local battleUILayer = battleUILayer:create()
    self.upLayer:addChild(battleUILayer, 1000, 1000)

    battleUILayer.button_map:addTouchEventListener(function(pSender, eventType) self:onButtonMap(pSender, eventType) end)

    local battleBg = ccs.GUIReader:getInstance():widgetFromJsonFile("res/battleBg/battleBg.json");
    self.mainLayer:addChild(battleBg, 0, 0);

    self.mainMap = GameMap:create(self, 'tmx/map_01.tmx');
    self.mainMap:setPosition(cc.p(-self.origin.x, -self.origin.y));
    self.mainLayer:addChild(self.mainMap, 5000, 5000);

    self.mainMap:addObjects();

    self.hero = Hero:create(self, 101);
    self.hero:setPosition(self.mainMap:getHeroBornPos());
    --self.mainLayer:addChild(self.hero, 100, 100);
    self.mainMap:addChild(self.hero, 1, 1);

    self.mapSize = cc.size(self.mainMap:getMapSize().width * self.mainMap:getTileSize().width,
        self.mainMap:getMapSize().height * self.mainMap:getTileSize().height);

    self.touchRootNode = cc.Node:create();
    self:addChild(self.touchRootNode);
    self:scheduleUpdate();
    self:updateBattleFog();
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
    ccs.ArmatureDataManager:getInstance():removeArmatureFileInfo("res/bomb/BombermenAnimation.ExportJson")
end

function GameLayer:getBombList()
    return self.bombList
end

function GameLayer:update(dt)
    self:updateControl(dt);
    ----------英雄放炸弹之后 不与炸弹发生碰撞检测 等到与炸弹分离后 可以检测碰撞了---------------------------------
    if self.hero:getStatus() == HERO_NOT_COLLISION_BOMB and self.hero:getCurBomb()then
        local bomb = self.hero:getCurBomb();
        local heroCollisionRect = self.hero:getCollisionRect();
        local bombCollisionRect = bomb:getCollisionRect();

        if not cc.rectIntersectsRect(heroCollisionRect, bombCollisionRect) then
            self.hero:setStatus(HERO_LIFE_ACTIVITY);
        end
    end
    ------------------------------------------------------
--关于为什么使用heroPos  update这个函数里面 很多地方调用了 hero对象调用了setPosition()这类函数 而游戏在和land进行碰撞
--检测的时候会有抖动， 猜测是因为每一次执行setPosition的时候 都会对opengl渲染进行调用  因为opengl渲染是多线程，与本线程的
--逻辑并无关系 所以hero 在当前这个uodate函数里面进行了多次渲染   那么只需要在这个函数结尾执行setPosition函数 效果证明
--了我的猜想 游戏好像没抖动了
    local heroPosX, heroPosY = self.hero:getPositionX(), self.hero:getPositionY();
    self.heroPos = cc.p(heroPosX, heroPosY)
    --[[if self.hero:isGadgetable() then
        heroPosX = heroPosX + self.moveOffset + self.hero:getGadget():getMoveOffset();
        heroPosY = heroPosY + self.jumpOffset + self.hero:getGadget():getJumpOffset();
    elseif self.hero:getSpring() then
        heroPosX = heroPosX + self.moveOffset;
        --heroPosY = heroPosY + self.jumpOffset + self.hero:getSpring():getJumpOffset();
        --cclog('self.hero:getSpring():getJumpOffset() %f', self.hero:getSpring():getJumpOffset())
    else
        heroPosX = heroPosX + self.moveOffset;
        heroPosY = heroPosY + self.jumpOffset;
    end

    if self.hero:isFly() then

    end]]

    if self.hero:isGadgetable() then
        self.heroPos.x = self.heroPos.x + self.moveOffset + self.hero:getGadget():getMoveOffset();
        self.heroPos.y = self.heroPos.y + self.jumpOffset + self.hero:getGadget():getJumpOffset();
    elseif self.hero:getSpring() then
        self.heroPos.x = self.heroPos.x + self.moveOffset;
        --heroPosY = heroPosY + self.jumpOffset + self.hero:getSpring():getJumpOffset();
        --cclog('self.hero:getSpring():getJumpOffset() %f', self.hero:getSpring():getJumpOffset())
    else
        self.heroPos.x = self.heroPos.x + self.moveOffset;
        self.heroPos.y = self.heroPos.y + self.jumpOffset;
    end


--self.hero:setPosition(cc.p(heroPosX, heroPosY));
self:collisionV();
self:collisionH();
    self.hero:setPosition(self.heroPos);
    self:setMapScrollPosition(dt);


    self:dealCollision();
    self:updateBattleFog();
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

function GameLayer:setMapScrollPosition(dt)
--local heroPosX, heroPosY = self.hero:getPositionX(), self.hero:getPositionY();
local heroPosX, heroPosY = self.heroPos.x, self.heroPos.y;
local x = math.max(heroPosX, self.heroAnchor.x);
local y = math.max(heroPosY, self.heroAnchor.y);

x = math.min(x, self.mapSize.width - self.winSize.width / 2 - 80);
y = math.min(y, self.mapSize.height - self.winSize.height / 2);

local viewPointX = self.heroAnchor.x - x;
local viewPointY = self.heroAnchor.y - y;

self.mainLayer:setPosition(viewPointX, viewPointY);
end

--垂直方向碰撞
function GameLayer:collisionV()
--local heroPosX, heroPosY = self.hero:getPositionX(), self.hero:getPositionY();
local heroPosX, heroPosY = self.heroPos.x, self.heroPos.y;
local heroSize = self.hero:getCurrentSize();
local headInGadgetFlag = false;
local headInSpringFlag = false;

--下面是判断马里奥的脚底是否已经接近地图下边缘的5像素处，以此为die
if heroPosY <= -5 then
    cclog('die')
end

--主角头顶的碰撞检测
for i = HERO_101_TOP_HEAD_LEFT, heroSize.width - HERO_101_TOP_HEAD_RIGHT, 3 do
    local upCollision = cc.p(heroPosX - heroSize.width / 2 + i, heroPosY + heroSize.height);
    local upTileCoord = self.mainMap:positionToTileCoord(upCollision);

    --判断是否吃到道具
    --[[if self.mainMap:isEatProp() then
        self.hero:changeForEatProp();
    end]]


        local upPos = self.mainMap:tilecoordToPosition(upTileCoord);
        upPos = cc.p(heroPosX, upPos.y - heroSize.height);
        local tileType = self.mainMap:tileTypeforPos(upTileCoord);
        local flagUp = false;

        if TILE_TYPE_BLOCK == tileType or TILE_TYPE_LAND == tileType then
            if self.jumpOffset > 0 then
                self.jumpOffset = 0;
                --self.hero:setPosition(upPos);
                self.heroPos = upPos;

                flagUp = true;
            end
        elseif TILE_TYPE_COIN == tileType then
            self.mainMap.coinLayer:removeTileAt(upTileCoord);
        end

        if flagUp then
            self.jumpOffset = self.jumpOffset - self.jumpStep;
            return
        end

        --检测主角是否头站在梯子里面
        headInGadgetFlag = self.mainMap:isHeroInGadget(upCollision);
        headInSpringFlag = self.mainMap:isHeroInSpring(upCollision, 'v');
    end


    local heroLeftSide = heroPosX - heroSize.width/2;
    for i = HERO_101_BOTTOM_FOOT_LEFT, heroSize.width - HERO_101_BOTTOM_FOOT_RIGHT, 3 do
        local downCollision = cc.p(heroLeftSide + i, heroPosY);
        local downTileCoord = self.mainMap:positionToTileCoord(downCollision);

        --判断是否吃到道具
        --[[if self.mainMap:isEatProp() then
            self.hero:changeForEatProp();
        end]]

        local downPos = self.mainMap:tilecoordToPosition(downTileCoord);
        downPos = cc.p(heroPosX , downPos.y + self.mainMap.tileSize.height);

        local tileType = self.mainMap:tileTypeforPos(downTileCoord);
        local flagDown = false;

        if TILE_TYPE_BLOCK == tileType or TILE_TYPE_LAND == tileType then
            if self.jumpOffset < 0 then
                self.jumpOffset = 0;
                --self.hero:setPosition(downPos);
                self.heroPos = downPos;
                self.hero:setGadgetable(false);
                self.moveOffset = 0;
                self.hero:setFlyStatus(false)
                --落地之后的朝向在这里操作
                flagDown = true;
            end
        elseif TILE_TYPE_COIN == tileType then
            self.mainMap.coinLayer:removeTileAt(downTileCoord);
        end

        if flagDown then
            return
        end

        --检测主角是否站在梯子上
        local ret, gadgetLevel, gadget = self.mainMap:isHeroInGadget(downCollision);
        if ret and not headInGadgetFlag then                                          --同时头不能也在梯子里面
            self.jumpOffset = 0;
            self.moveOffset = 0;
            downPos = cc.p(heroPosX, gadgetLevel);
            --self.hero:setPosition(downPos);
            self.heroPos = downPos;
            self.hero:setGadgetable(true);
            self.hero:setGadget(gadget);
            self.hero:setFlyStatus(false)

            --落地之后的朝向在这里操作

            return
        else
            self.hero:setGadgetable(false);
            self.hero:clearGadget();
        end

        --检测主角是否在弹簧上
        local ret, springLevel, spring = self.mainMap:isHeroInSpring(downCollision, 'v');
        if ret and not headInSpringFlag then
            self.jumpOffset = 0;
            self.moveOffset = 0;

            downPos = cc.p(heroPosX, springLevel);
            --self.hero:setPosition(downPos);
            self.heroPos = downPos;
            self.hero:setSpring(spring);
            spring:triggerSpring();
            self.hero:setFlyStatus(false)

            return;
        end

        if HERO_NOT_COLLISION_BOMB ~= self.hero:getStatus() then
            for _, bomb in ipairs(self.bombList) do
                local collisionRect = bomb:getCollisionRect();
                if BULLET_STATUS_NORMAL == bomb:getStatus() and cc.rectContainsPoint(collisionRect, downCollision) then
                    --self.hero:setPositionY(collisionRect.y + collisionRect.height);
                    self.heroPos.y = collisionRect.y + collisionRect.height;
                    self.jumpOffset = 0;
                    self.moveOffset = 0;
                    self.hero:setFlyStatus(false)

                    return
                end
            end
        end
    end

    self.jumpOffset = self.jumpOffset - self.jumpStep;

    if not self.hero:isFly() and self.jumpOffset < 0 - self.jumpStep then
        self.hero:setFlyStatus(true);
    end
end

--水平方向碰撞检测
function GameLayer:collisionH()
    --local heroPosX, heroPosY = self.hero:getPositionX(), self.hero:getPositionY();
    local heroPosX, heroPosY = self.heroPos.x, self.heroPos.y;
    local heroSize = self.hero:getCurrentSize();

    --做判断不让主角移除屏幕的左侧
    if heroPosX - heroSize.width/2 <= 0 then
        local pp = cc.p(heroSize.width/2, heroPosY);
        --self.hero:setPosition(pp);
        self.heroPos = pp;
        return ;
    end

    if heroPosX + heroSize.width/2 + self.mainLayer:getPositionX() >= self.winSize.width then
        local pp = cc.p(self.winSize.width - heroSize.width/2 - self.mainLayer:getPositionX(), heroPosY);
        --self.hero:setPosition(pp);
        self.heroPos = pp;
        return ;
    end

    local flag = false;
    --右侧判段

    for i = heroPosY + 10, heroPosY + heroSize.height - 10, 3 do
        local rightCollision = cc.p(heroPosX + heroSize.width/2, i);
        local rightTileCoord = self.mainMap:positionToTileCoord(rightCollision);
        --判断是否吃到道具
        --[[if self.mainMap:isEatProp() then
            self.hero:changeForEatProp();
        end]]

        local rightPos = self.mainMap:tilecoordToPosition(rightTileCoord);
        rightPos = cc.p(rightPos.x - heroSize.width/2, heroPosY);

        local tileType = self.mainMap:tileTypeforPos(rightTileCoord);

        if TILE_TYPE_BLOCK == tileType or TILE_TYPE_LAND == tileType then
            --self.hero:setPosition(rightPos);
            self.heroPos = rightPos;
            return
        elseif TILE_TYPE_COIN == tileType then
            self.mainMap.coinLayer:removeTileAt(rightCollision);
        end

        local ret, springLevel = self.mainMap:isHeroInSpring(rightCollision, 'r');
        if ret then
            --return self.hero:setPosition(springLevel - self.hero:getCurrentSize().width / 2, heroPosY)
            self.heroPos = cc.p(springLevel - self.hero:getCurrentSize().width / 2, heroPosY);
            return
        end

        if HERO_NOT_COLLISION_BOMB ~= self.hero:getStatus() then
            for _, bomb in ipairs(self.bombList) do
                local collisionRect = bomb:getCollisionRect();
                if BULLET_STATUS_NORMAL == bomb:getStatus() and cc.rectContainsPoint(collisionRect, rightCollision) then
                    --self.hero:setPositionX(collisionRect.x - self.hero:getCurrentSize().width / 2);
                    self.heroPos.x = collisionRect.x - self.hero:getCurrentSize().width / 2
                    return
                end
            end
        end

        if not self.hero:isGadgetable() then
            for _, gadget in ipairs(self.mainMap.gadgetList) do
                if gadget:getStatus() == GADGET_ACTIVE then
                    local gadgetRect = gadget:getCollisionRect();
                    if cc.rectContainsPoint(gadgetRect, rightCollision) then
                        --self.hero:setPositionX(gadgetRect.x - self.hero:getCurrentSize().width / 2);
                        self.heroPos.x = gadgetRect.x - self.hero:getCurrentSize().width / 2;
                        return
                    end
                end
            end
        end
    end

    --主角的左侧碰撞检测点
    for i = heroPosY + 10, heroPosY + heroSize.height - 10, 3 do
        local leftCollision = cc.p(heroPosX - heroSize.width/2, i); -- + heroSize.height/2
        local leftTileCoord = self.mainMap:positionToTileCoord(leftCollision);

        --判断是否吃到道具
        --[[if self.mainMap:isEatProp() then
            self.hero:changeForEatProp();
        end]]

        local leftPos = self.mainMap:tilecoordToPosition(leftTileCoord);
        leftPos = cc.p(leftPos.x + heroSize.width/2 + self.mainMap:getTileSize().width, heroPosY);
        local tileType = self.mainMap:tileTypeforPos(leftTileCoord);

        if TILE_TYPE_BLOCK == tileType or TILE_TYPE_LAND == tileType then
            --self.hero:setPosition(leftPos);
            self.heroPos = leftPos;
            return;
        elseif TILE_TYPE_COIN == tileType then
            self.mainMap.coinLayer:removeTileAt(leftTileCoord);
        end

        local ret, springLevel = self.mainMap:isHeroInSpring(leftCollision, 'l');
        if ret then
            self.heroPos = cc.p(springLevel + self.hero:getCurrentSize().width / 2, heroPosY)
            --return self.hero:setPosition(springLevel + self.hero:getCurrentSize().width / 2, heroPosY)
            return
        end

        if HERO_NOT_COLLISION_BOMB ~= self.hero:getStatus() then
            for _, bomb in ipairs(self.bombList) do
                local collisionRect = bomb:getCollisionRect();
                if BULLET_STATUS_NORMAL == bomb:getStatus() and cc.rectContainsPoint(collisionRect, leftCollision) then
                    --self.hero:setPositionX(collisionRect.x + collisionRect.width + self.hero:getCurrentSize().width / 2);
                    self.heroPos.x = collisionRect.x + collisionRect.width + self.hero:getCurrentSize().width / 2;
                    return
                end
            end
        end

        if not self.hero:isGadgetable() then
            for _, gadget in ipairs(self.mainMap.gadgetList) do
                if gadget:getStatus() == GADGET_ACTIVE then
                    local gadgetRect = gadget:getCollisionRect();
                    if cc.rectContainsPoint(gadgetRect, leftCollision) then
                        --self.hero:setPositionX(gadgetRect.x + gadgetRect.width + self.hero:getCurrentSize().width / 2);
                        self.heroPos.x = gadgetRect.x + gadgetRect.width + self.hero:getCurrentSize().width / 2;
                        return
                    end
                end
            end
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

function GameLayer:onTouchBegan(touch, event)
    self:createTouchEffect(touch);
    self:EffectFollow(touch);


    --self.touchStatus = TOUCH_BEGIN;


    local longTouch = function()
        if self.touchStatus == 'touchBeginStatus' then 
            --self.beginTouchPos = touch:getLocation();
            self.beginTouchTime = os.time();

            if self.beginTouchPos.x > self.winSize.width / 2 then
                cclog('long touch walking right')
                self.controlStatus = HERO_STATUS_RIGHT_WALKING;
                self.hero:setToward(TOWARD_RIGHT);
            else
                cclog('long touch walking left');
                self.controlStatus = HERO_STATUS_LEFT_WALKING;
                self.hero:setToward(TOWARD_LEFT);
            end

            self.touchStatus = 'touchMoveStatus'
        end
    end

    doDelay(0.05, longTouch);

    self.touchStatus = 'touchBeginStatus'
    self.beginTouchPos = touch:getLocation();


    return true
end

function GameLayer:onTouchMoved(touch, event)
    self:EffectFollow(touch);
    local movePos = touch:getLocation();
    local time = os.time();

    if touchMoveStatus == 'touchMoveStatus' and math.abs(movePos.x - self.beginTouchPos.x) <= 20 and math.abs(movePos.y - self.beginTouchPos.y) <= 20 then
        --如果在玩家手指一直在屏幕上 位移很小 则在规定时间内重置该值  就想象玩家在屏幕一直慢慢在移动 如果没有时间限制 则慢慢移动超过规定的
        --的距离就会跳动了，实际上玩家并不打算跳动 只是手指不自觉的移动了而已
        if time - self.beginTouchTime > 1 then
            self.beginTouchPos = movePos;
            self.beginTouchTime = time;
        end

        return
    end

    if self.touchStatus ~= 'touchJumpDownStatus' and math.abs(movePos.y - self.beginTouchPos.y) >= 40 then
        if movePos.y > self.beginTouchPos.y then
            if math.abs(movePos.x - self.beginTouchPos.x) < 16 then
                --正上方
                if not self.hero:isFly() or self.hero:getSpring()then
                    self.controlStatus = HERO_STATUS_JUMP
                    self.hero:clearGadget(false);
                    self.hero:setFlyStatus(true);

                    if self.hero:getSpring() then
                        self.jumpOffset = self.hero:getSpring():getSpringValue();
                    else
                        self.jumpOffset = self.hero:getSpeedY();
                    end

                    self.hero:setFlyStatus(true)
                    self.hero:clearSpring(false);
                    self.touchStatus = 'touchJumpDownStatus';
                end
            elseif math.abs(movePos.x - self.beginTouchPos.x) >= 16 and movePos.x > self.beginTouchPos.x then
                --右上
                if not self.hero:isFly() or self.hero:getSpring() then
                    self.controlStatus = HERO_STATUS_RIGHT_JUMP
                    self.hero:clearGadget(false);
                    self.hero:setFlyStatus(true);
                    self.hero:setToward(TOWARD_RIGHT);

                    if self.hero:getSpring() then
                        self.jumpOffset = self.hero:getSpring():getSpringValue();
                    else
                        self.jumpOffset = self.hero:getSpeedY();
                    end

                    self.moveOffset = self.hero:getSpeedX();
                    self.hero:setFlyStatus(true)
                    self.hero:clearSpring(false);
                    self.touchStatus = 'touchJumpDownStatus';
                end
            elseif math.abs(movePos.x - self.beginTouchPos.x) >= 16 and movePos.x <= self.beginTouchPos.x then
                --左上
                if not self.hero:isFly() or self.hero:getSpring() then
                    self.controlStatus = HERO_STATUS_LEFT_JUMP
                    self.hero:clearGadget(false);
                    self.hero:setFlyStatus(true);
                    self.hero:setToward(TOWARD_LEFT);

                    if self.hero:getSpring() then
                        self.jumpOffset = self.hero:getSpring():getSpringValue();
                    else
                        self.jumpOffset = self.hero:getSpeedY();
                    end

                    self.moveOffset = -self.hero:getSpeedX();
                    self.hero:setFlyStatus(true)
                    self.hero:clearSpring(false);
                    self.touchStatus = 'touchJumpDownStatus';
                end
            end
        else
            if self.touchStatus ~= 'touchJumpDownStatus' then
                if math.abs(movePos.x - self.beginTouchPos.x) < 16 then
                    --正下方
                    if not self.hero:getSpring() and not self.hero:isFly() then        --简单点  在弹簧上面不能放子弹   空中也不行
                        self.controlStatus = HERO_STATUS_BOM
                        self.touchStatus = 'touchJumpDownStatus';
                        self.hero:makeBomb(BOMB_DOWN);
                    end
                elseif math.abs(movePos.x - self.beginTouchPos.x) >= 16 and movePos.x > self.beginTouchPos.x then
                    --右下方
                    if not self.hero:getSpring() and not self.hero:isFly() then        --简单点  在弹簧上面不能放子弹   空中也不行
                        self.controlStatus = HERO_STATUS_LEFT_BOM
                        self.touchStatus = 'touchJumpDownStatus';
                        self.hero:makeBomb(BOMB_RIGHT);
                        self.hero:setToward(TOWARD_RIGHT);
                    end                   

                elseif math.abs(movePos.x - self.beginTouchPos.x) >= 16 and movePos.x <= self.beginTouchPos.x then
                    --左下方
                    if not self.hero:getSpring() and not self.hero:isFly() then        --简单点  在弹簧上面不能放子弹   空中也不行
                        self.controlStatus = HERO_STATUS_RIGHT_BOM
                        self.touchStatus = 'touchJumpDownStatus';
                        self.hero:makeBomb(BOMB_LEFT);
                        self.hero:setToward(TOWARD_LEFT);
                    end           
                end
            end
        end
    end
end

function GameLayer:onCancelled(touch, event)
    cclog('onCancelled')
    self.touchStatus = 'touchNothingStatus'
end

function GameLayer:onTouchEnded(touch, event)
    cclog('end   ==' .. self.touchStatus)
    self:removeTouchEffect();


    if self.touchStatus == 'touchBeginStatus' then 
        if self.beginTouchPos.x > self.winSize.width / 2 then
            self.controlStatus = HERO_STATUS_RIGHT_STAND
            self.hero:setToward(TOWARD_RIGHT);
        else
            self.controlStatus = HERO_STATUS_LEFT_STAND
            self.hero:setToward(TOWARD_LEFT);
        end
    elseif self.touchStatus == 'touchMoveStatus' or 'touchNothingStatus' == self.touchStatus then
        if self.controlStatus == HERO_STATUS_RIGHT_WALKING then
            self.controlStatus = HERO_STATUS_RIGHT_STAND
        else
            self.controlStatus = HERO_STATUS_LEFT_STAND
        end
    end

    self.touchStatus = 'touchEndStatus'
end


--[[function GameLayer:onTouchBegan(touch, event)
    self:createTouchEffect(touch);
    self:EffectFollow(touch);

    local longTouch = function()
        if 1 == self.isMoveAndTouchEnd then                       --如果移动了 或者 提前抬起手了
            self.isMoveAndTouchEnd = 4                            --进入行走状态

            if self.beginTouchPos.x > self.winSize.width / 2 then
                cclog('long touch walking right')
                self.controlStatus = HERO_STATUS_RIGHT_WALKING;
                self.hero:setToward(TOWARD_RIGHT);
            else
                cclog('long touch walking left');
                self.controlStatus = HERO_STATUS_LEFT_WALKING;
                self.hero:setToward(TOWARD_LEFT);
            end
        end
    end

    self.isMoveAndTouchEnd = 1;                        --初始状态
    doDelay(0.12, longTouch);
    self.beginTouchPos = touch:getLocation();
    return true
end

function GameLayer:onTouchMoved(touch, event)
    self:EffectFollow(touch);
    local movePos = touch:getLocation();

    if -1 == self.isMoveAndTouchEnd then
        return
    end

    if self.isMoveAndTouchEnd == 4 and (math.abs(movePos.x - self.beginTouchPos.x) > TOUCH_EFFECTIVE_ERROR_X * 2 or math.abs(movePos.y - self.beginTouchPos.y) > TOUCH_EFFECTIVE_ERROR_Y * 2) then
        self.isMoveAndTouchEnd = -1;                --进入行走状态后 移动距离大于有效距离 则判断为停止行走 进入跳跃 这样子操作流畅  且直接中断本次touch操作

        local longTouch = function()
            if movePos.x - self.beginTouchPos.x <= -TOUCH_EFFECTIVE_ERROR_X and movePos.y - self.beginTouchPos.y >= TOUCH_EFFECTIVE_ERROR_Y then
                cclog("move left_up");
                if not self.hero:isFly() or self.hero:getSpring() then
                    self.controlStatus = HERO_STATUS_LEFT_JUMP
                    self.hero:clearGadget(false);
                    self.hero:setFlyStatus(true);
                    self.hero:setToward(TOWARD_LEFT);

                    if self.hero:getSpring() then
                        self.jumpOffset = self.hero:getSpring():getSpringValue();
                    else
                        self.jumpOffset = self.hero:getSpeedY();
                    end

                    self.moveOffset = -self.hero:getSpeedX();
                    self.hero:setFlyStatus(true)
                    self.hero:clearSpring(false);
                end
            elseif movePos.x - self.beginTouchPos.x >= TOUCH_EFFECTIVE_ERROR_X and movePos.y - self.beginTouchPos.y >= TOUCH_EFFECTIVE_ERROR_Y then
                cclog("move right_up");
                if not self.hero:isFly() or self.hero:getSpring() then
                    self.controlStatus = HERO_STATUS_RIGHT_JUMP
                    self.hero:clearGadget(false);
                    self.hero:setFlyStatus(true);
                    self.hero:setToward(TOWARD_RIGHT);

                    if self.hero:getSpring() then
                        self.jumpOffset = self.hero:getSpring():getSpringValue();
                    else
                        self.jumpOffset = self.hero:getSpeedY();
                    end

                    self.moveOffset = self.hero:getSpeedX();
                    self.hero:setFlyStatus(true)
                    self.hero:clearSpring(false);
                end
            elseif movePos.x - self.beginTouchPos.x <= -TOUCH_EFFECTIVE_ERROR_X and movePos.y - self.beginTouchPos.y <= -TOUCH_EFFECTIVE_ERROR_Y then
                cclog("move left_down");
                if not self.hero:getSpring() and not self.hero:isFly() then        --简单点  在弹簧上面不能放子弹   空中也不行
                    self.controlStatus = HERO_STATUS_LEFT_BOM
                    local bomb = BombNormal:create(self, BOMB_LEFT);
                    self.hero:setToward(TOWARD_LEFT);
                    self.hero:setCurBomb(bomb);
                    --BombJump:create(self, BOMB_LEFT);
                end
            elseif movePos.x - self.beginTouchPos.x >= TOUCH_EFFECTIVE_ERROR_X and movePos.y - self.beginTouchPos.y <= -TOUCH_EFFECTIVE_ERROR_Y then
                cclog("move right_down");
                if not self.hero:getSpring() and not self.hero:isFly() then        --简单点  在弹簧上面不能放子弹  空中也不行
                    self.controlStatus = HERO_STATUS_RIGHT_BOM
                    local bomb = BombNormal:create(self, BOMB_RIGHT);
                    self.hero:setToward(TOWARD_RIGHT);
                    self.hero:setCurBomb(bomb);
                    --BombJump:create(self, BOMB_RIGHT);
                end
            elseif movePos.x - self.beginTouchPos.x > -TOUCH_EFFECTIVE_ERROR_X and movePos.x - self.beginTouchPos.x < TOUCH_EFFECTIVE_ERROR_X and movePos.y - self.beginTouchPos.y >= TOUCH_EFFECTIVE_ERROR_Y then
                cclog("move up");

                if not self.hero:isFly() or self.hero:getSpring() then
                    self.controlStatus = HERO_STATUS_JUMP
                    self.hero:clearGadget(false);
                    self.hero:setFlyStatus(true);

                    if self.hero:getSpring() then
                        self.jumpOffset = self.hero:getSpring():getSpringValue();
                    else
                        self.jumpOffset = self.hero:getSpeedY();
                    end

                    self.hero:setFlyStatus(true)
                    self.hero:clearSpring(false);
                end
            elseif movePos.x - self.beginTouchPos.x > -TOUCH_EFFECTIVE_ERROR_X and movePos.x - self.beginTouchPos.x < TOUCH_EFFECTIVE_ERROR_X and movePos.y - self.beginTouchPos.y <= -TOUCH_EFFECTIVE_ERROR_Y then
                cclog("move down");
                if not self.hero:getSpring() and not self.hero:isFly() then        --简单点  在弹簧上面不能放子弹  空中也不行
                    self.controlStatus = HERO_STATUS_BOM
                    local bomb = BombNormal:create(self, BOMB_DOWN);
                    self.hero:setCurBomb(bomb);
                end
            else
                if self.controlStatus == HERO_STATUS_RIGHT_WALKING then
                    self.controlStatus = HERO_STATUS_RIGHT_STAND
                else
                    self.controlStatus = HERO_STATUS_LEFT_STAND
                end
            end
        end



        doDelay(0.1, longTouch);
    elseif 4 ~= self.isMoveAndTouchEnd and (math.abs(movePos.x - self.beginTouchPos.x) > TOUCH_EFFECTIVE_ERROR_X  or math.abs(movePos.y - self.beginTouchPos.y) > TOUCH_EFFECTIVE_ERROR_Y) then
        self.isMoveAndTouchEnd = 2;  -- 可以理解为在 很短时间内 滑动的距离 满足 非垂直跳跃或者非垂直下蛋的

        local longTouch = function()
            if self.isMoveAndTouchEnd == 2 then
                self:onTouchEnded(touch, event);
                self.isMoveAndTouchEnd = -1;
            end
        end

        doDelay(0.1, longTouch);
    end
end

function GameLayer:onTouchEnded(touch, event)
    self:removeTouchEffect();
    local endTouchPos = touch:getLocation();
    if -1 == self.isMoveAndTouchEnd then
        return
    end

    if 4 ~= self.isMoveAndTouchEnd or self.isMoveAndTouchEnd == 2 then
        self.isMoveAndTouchEnd = 3;

        if endTouchPos.x - self.beginTouchPos.x <= -TOUCH_EFFECTIVE_ERROR_X and endTouchPos.y - self.beginTouchPos.y >= TOUCH_EFFECTIVE_ERROR_Y then
            cclog("left_up");
            if not self.hero:isFly() or self.hero:getSpring() then
                self.controlStatus = HERO_STATUS_LEFT_JUMP
                self.hero:clearGadget(false);
                self.hero:setFlyStatus(true);
                self.hero:setToward(TOWARD_LEFT);

                if self.hero:getSpring() then
                    self.jumpOffset = self.hero:getSpring():getSpringValue();
                else
                    self.jumpOffset = self.hero:getSpeedY();
                end

                self.moveOffset = -self.hero:getSpeedX();
                self.hero:setFlyStatus(true)
                self.hero:clearSpring(false);
            end
        elseif endTouchPos.x - self.beginTouchPos.x >= TOUCH_EFFECTIVE_ERROR_X and endTouchPos.y - self.beginTouchPos.y >= TOUCH_EFFECTIVE_ERROR_Y then
            cclog("right_up");
            if not self.hero:isFly() or self.hero:getSpring() then
                self.controlStatus = HERO_STATUS_RIGHT_JUMP
                self.hero:clearGadget(false);
                self.hero:setFlyStatus(true);
                self.hero:setToward(TOWARD_RIGHT);

                if self.hero:getSpring() then
                    self.jumpOffset = self.hero:getSpring():getSpringValue();
                else
                    self.jumpOffset = self.hero:getSpeedY();
                end

                self.moveOffset = self.hero:getSpeedX();
                self.hero:setFlyStatus(true)
                self.hero:clearSpring(false);
            end
        elseif endTouchPos.x - self.beginTouchPos.x <= -TOUCH_EFFECTIVE_ERROR_X and endTouchPos.y - self.beginTouchPos.y <= -TOUCH_EFFECTIVE_ERROR_Y then
            cclog("left_down");
            if not self.hero:getSpring() and not self.hero:isFly() then        --简单点  在弹簧上面不能放子弹   空中也不行
                self.controlStatus = HERO_STATUS_LEFT_BOM
                local bomb = BombNormal:create(self, BOMB_LEFT);
                self.hero:setToward(TOWARD_LEFT);
                self.hero:setCurBomb(bomb);
                --BombJump:create(self, BOMB_LEFT);
            end
        elseif endTouchPos.x - self.beginTouchPos.x >= TOUCH_EFFECTIVE_ERROR_X and endTouchPos.y - self.beginTouchPos.y <= -TOUCH_EFFECTIVE_ERROR_Y then
            cclog("right_down");
            if not self.hero:getSpring() and not self.hero:isFly() then        --简单点  在弹簧上面不能放子弹  空中也不行
                self.controlStatus = HERO_STATUS_RIGHT_BOM
                local bomb = BombNormal:create(self, BOMB_RIGHT);
                self.hero:setToward(TOWARD_RIGHT);
                self.hero:setCurBomb(bomb);
                --BombJump:create(self, BOMB_RIGHT);
            end
        elseif endTouchPos.x - self.beginTouchPos.x > -TOUCH_EFFECTIVE_ERROR_X and endTouchPos.x - self.beginTouchPos.x < TOUCH_EFFECTIVE_ERROR_X and endTouchPos.y - self.beginTouchPos.y >= TOUCH_EFFECTIVE_ERROR_Y then
            cclog("up");

            if not self.hero:isFly() or self.hero:getSpring()then
                self.controlStatus = HERO_STATUS_JUMP
                self.hero:clearGadget(false);
                self.hero:setFlyStatus(true);

                if self.hero:getSpring() then
                    self.jumpOffset = self.hero:getSpring():getSpringValue();
                else
                    self.jumpOffset = self.hero:getSpeedY();
                end

                self.hero:setFlyStatus(true)
                self.hero:clearSpring(false);
            end
        elseif endTouchPos.x - self.beginTouchPos.x > -TOUCH_EFFECTIVE_ERROR_X and endTouchPos.x - self.beginTouchPos.x < TOUCH_EFFECTIVE_ERROR_X and endTouchPos.y - self.beginTouchPos.y <= -TOUCH_EFFECTIVE_ERROR_Y then
            cclog("down");
            if not self.hero:getSpring() and not self.hero:isFly() then        --简单点  在弹簧上面不能放子弹  空中也不行
                self.controlStatus = HERO_STATUS_BOM
                local bomb = BombNormal:create(self, BOMB_DOWN);
                self.hero:setCurBomb(bomb);
            end
        elseif endTouchPos.x > self.winSize.width / 2 then
            cclog("touch right");
            self.controlStatus = HERO_STATUS_RIGHT_STAND
        else
            cclog("touch left");
            self.controlStatus = HERO_STATUS_LEFT_STAND
            self.hero:setToward(TOWARD_LEFT);
        end
    else
        if self.controlStatus == HERO_STATUS_RIGHT_WALKING then          --很快点击 没有触发到长按状态  又静止不动  则是 改变方向就是很快点击
            self.controlStatus = HERO_STATUS_RIGHT_STAND
        else
            self.controlStatus = HERO_STATUS_LEFT_STAND
        end

        cclog('long touch end');
    end
end
]]
function GameLayer:onKeyPressed(keyCode, event)
    --[[if 'KEY_1' == cc.KeyCodeKey[keyCode] then

    end]]
end




--touch 特效

function GameLayer:createTouchEffect(touch)
    local effect = cc.ParticleSystemQuad:create("TouchEffect/TouchEffect.plist");
    self.touchRootNode:addChild(effect);
    effect:setPosition( 0, 0 );
    self:EffectFollow(touch);
end

function GameLayer:removeTouchEffect()
    self.touchRootNode:removeAllChildren();
end

function GameLayer:EffectFollow(touch)
    local mTmp = touch:getLocation();
    self.touchRootNode:setPosition( mTmp.x, mTmp.y);
end

