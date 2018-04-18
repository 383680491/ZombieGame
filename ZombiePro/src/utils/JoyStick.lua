local JoyStick = class("JoyStick", function()return cc.Node:create() end)
function JoyStick:create()
    local ret = JoyStick:new()
    return ret
end

function JoyStick:setDetegate(detegate)
    self.detegate = detegate
end

function JoyStick:setDetegate_right(detegate)
    self.detegate_right = detegate
end



function JoyStick:ctor()
   
    self.bg = ccui.ImageView:create()
    self.bg:loadTexture("XYDCJ_JP_dk.png")
    --self.bg:setScale(1.8)
    self.ball = ccui.ImageView:create()
    self.ball:loadTexture("YXC_DSQ_DK.png")

    self.ballRadius = 22.5     --旋转球半径
    self.moveAreaRadius = 70  --旋转球活动半径
    self.isFollowTouch = true  --是否跟随触摸
    self.isVisible = true     
    self.isAutoHide = false
    self.isAnimal = true

    self.currentPoint = cc.p(0, 0)
    self.isTouch = false
    self.isUpdate = false
    self:setHitAreaWithRect(cc.rect(0, 0, 1280, 720))

    self.angle = 0
    self.power = 0
    self.direct = 0
    self.detegate = nil

    self.detegate_right = nil

    self:addChild(self.bg)
    self:addChild(self.ball)

    local function registerHander(event)
        if "enter" == event then
            self:onEnter()
        elseif "exit" == event then
            self:onExit()
        end
    end

    self:registerScriptHandler(registerHander)
end

function JoyStick:onEnter()
    local function onTouchBegan(touch, event)
        return self:onTouchBegan(touch, event)
    end

    local function onTouchMoved(touch, event)
        self:onTouchMoved(touch, event)
    end

    local function onTouchEnded(touch, event)
        self:onTouchEnded(touch, event)
    end

    local function onTouchCancelled(touch, event)
        self:onTouchCancelled(touch, event)
    end
    local listener = cc.EventListenerTouchOneByOne:create()
    listener:setSwallowTouches(false)

    listener:registerScriptHandler(onTouchBegan, cc.Handler.EVENT_TOUCH_BEGAN)
    listener:registerScriptHandler(onTouchMoved, cc.Handler.EVENT_TOUCH_MOVED)
    listener:registerScriptHandler(onTouchEnded, cc.Handler.EVENT_TOUCH_ENDED)
    listener:registerScriptHandler(onTouchCancelled, cc.Handler.EVENT_TOUCH_CANCELLED)

    local eventDispatcher = self:getEventDispatcher()
    eventDispatcher:addEventListenerWithSceneGraphPriority(listener, self)

    local function frameEvent(dt) 
        self:onFrame(dt) 
    end
    self:scheduleUpdateWithPriorityLua( frameEvent, 0 )
end

function JoyStick:onExit()

end

function JoyStick:setHitAreaWithRect(rect)
    self.activeRect = rect
    self.activeRadius = 0
end




function JoyStick:onTouchBegan(touch, event)
    local touchPoint = touch:getLocation()
    if not self:containsTouchLocation(touch) then
        return false;  
    end

    self:myTouchBegan(touchPoint);  
      
    return true
end

function JoyStick:onTouchMoved(touch, event)
    local touchPoint = touch:getLocation()
    if self.isTouch then 
        self:updateTouchPoint(touchPoint);  
    end
end

function JoyStick:onTouchEnded(touch, event)
    if self.isTouch then 
        if self.isAutoHide and self.isVisible then 
            self:setVisible(false)
        end

        self.isTouch = false
        self.isUpdate = false
        self:resetTexturePosition();
    end
end

function JoyStick:onTouchCancelled(touch, event)

end


function JoyStick:containsTouchLocation(touch)  
    local touchPoint = touch:getLocation();  
    if self.activeRadius > 0 then
        local x, y = self:getPosition()
        if cc.pGetDistance(touchPoint, self:getParent():convertToWorldSpace(cc.p(x, y))) < ActiveRadius then 
            return true
        end
    end

    if self.activeRect.width > 0 and self.activeRect.height > 0 then 
        if cc.rectContainsPoint(self.activeRect, touchPoint) then 
            return true
        end
    end

    return false;  
end


function JoyStick:myTouchBegan(touchPoint)  
    self.currentPoint = touchPoint;  
    self.isTouch = true;  

    if self.isAutoHide and self.isVisible then 
        self:setVisible(true)
    end
      
    if self.isFollowTouch then 
        self:setPosition(self:getParent():convertToNodeSpace(touchPoint))
    end
      
    self.ball:stopAllActions()
    self:updateTouchPoint(touchPoint)
    self.isUpdate = true
end

function JoyStick:updateTouchPoint(touchPoint)  
    local x, y = self:getPosition()
    local pos = self:getParent():convertToWorldSpace(cc.p(x, y))
    if cc.pGetDistance(touchPoint, pos) > (self.moveAreaRadius - self.ballRadius) then 
        local temp = cc.pNormalize(cc.pSub(touchPoint, pos))
        temp.x = temp.x * (self.moveAreaRadius - self.ballRadius)
        temp.y = temp.y * (self.moveAreaRadius - self.ballRadius)
        self.currentPoint = temp
    else
        self.currentPoint = cc.pSub(touchPoint, pos)
    end

    self.ball:setPosition(self.currentPoint)
    local radian = cc.pToAngleSelf(self.currentPoint)
    self.angle = radian / 3.14159 * 180 --弧度变角度 
    self.power = cc.pGetLength(self.currentPoint) / (self.moveAreaRadius - self.ballRadius)
    self.direct = cc.pForAngle(radian)
end

function JoyStick:resetTexturePosition()  
    self.power = 0
    self.angle = 0
    self.currentPoint = cc.p(0, 0)

    if self.isAutoHide and self.isVisible and isAniaml then 
        self:runAction(cc.EaseElasticOut:creat(cc.MoveTo:creat(0.5, cc.p(0, 0))))
    else
        self.ball:setPosition(cc.p(0, 0))
    end
end

function JoyStick:onFrame(dt)
    if not self.isUpdate then 
       return
    end
    
    if self.detegate then 
        self.detegate:onJoyStickUpdate(self, self.angle, self.direct, self.power)
    end

    if self.detegate_right then 
        self.detegate_right:onJoyStickUpdate_right(self, self.angle-90, self.direct, self.power)
    end
end


return JoyStick









