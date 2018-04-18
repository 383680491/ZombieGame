--
-- Created by IntelliJ IDEA.
-- User: Administrator
-- Date: 2015/2/4
-- Time: 1:04
-- To change this template use File | Settings | File Templates.
local Welcomelayer = class("Welcomelayer", require 'ui.base.BaseView')
Welcomelayer.__index = Welcomelayer
Welcomelayer.__instance = nil

function Welcomelayer:create(path)
    local ret = Welcomelayer.new(path)
    ret:init()

    return ret
end

function Welcomelayer:ctor()
    Welcomelayer.super:ctor()
    self.visibleSize = cc.Director:getInstance():getVisibleSize()
    self.origin = cc.Director:getInstance():getVisibleOrigin()
    self.schedulerID = nil
    self:setMoudleId(G_LayerDefine.LOGIN_TEST)
end

function Welcomelayer:init()
    -- local node = cc.CSLoader:createNode("MainScene.csb")
    -- self:addChild(node)

    local GameLayer = require 'ui.GameLayer'
    local layer = GameLayer:create()
    self:addChild(layer)

    -- local JoyStick = require 'utils.JoyStick'
    -- local JoyStick_right = JoyStick:create()
    -- JoyStick_right:setDetegate_right(self)
    -- JoyStick_right.isFollowTouch = false
    -- JoyStick_right:setPosition(cc.p(900, 200))
    -- JoyStick_right:setHitAreaWithRect(cc.rect(830, 130, 255, 255))
    -- self:addChild(JoyStick_right)

    -- local JoyStick_left = JoyStick:create()
    -- JoyStick_left:setDetegate(self)
    -- JoyStick_left.isFollowTouch = false
    -- JoyStick_left:setPosition(cc.p(300, 200))
    -- JoyStick_left:setHitAreaWithRect(cc.rect(230, 130, 255, 255))
    -- self:addChild(JoyStick_left)

 


    -- self.uiLayer = ccs.GUIReader:getInstance():widgetFromJsonFile("res/corn_welcome/corn_welcome_3_2.ExportJson")
    -- self:addChild(self.uiLayer)

    -- self.button_welcome = self.uiLayer:getChildByName("button_welcome")
    -- self.button_back = self.uiLayer:getChildByName("button_back")
    -- self.image_bg = self.uiLayer:getChildByName("image_bg")

    -- self.button_welcome:addTouchEventListener(function(pSender, eventType) self:onWelcomeClicked(pSender, eventType) end)
    -- self.button_back:addTouchEventListener(function(pSender, eventType) self:onBackClicked(pSender, eventType) end)

    -- local bg = cc.Sprite:create("res/welcome.jpg")
    -- bg:setPosition(cc.p(self.image_bg:getContentSize().width / 2, self.image_bg:getContentSize().height / 2))
    -- --setNodeCurDesignResolutionSizeByHeight(bg)
    -- self.image_bg:setScale(2)
    -- self.image_bg:addChild(bg)



    

    -- --cc.DrawPrimitives.drawSolidRect(cc.p(200, 200), cc.p(400, 400), cc.c4f(1,0,0,1))

    -- self:triangeleOpenTest()
end


function Welcomelayer:onJoyStickUpdate(joyStick, angle, direct, power)
    -- local hero = self.world:getHero()
    -- if hero then
    --     hero:go(angle, direct, power)
    -- end  
    look(angle, 'angle')
    look(direct, 'direct')
    look(power, 'power')

    self.role:getDirByJoyDir(direct, angle)
    self.role:getTorwardIDByDir()
    self.role:runAnimal()
end

function Welcomelayer:onJoyStickUpdate_right(joyStick,angle, direct, power)

end




function Welcomelayer:triangeleOpenTest()
    local px = self.visibleSize.width / 2
    local py = self.visibleSize.height / 2

    local draw = cc.DrawNode:create()
    self:addChild(draw, 10)

print('Welcomelayer:triangeleOpenTest')
    local cellWidth = 20 
    local cellHeight = 20
     
    local croodX = 0
    local croodY = 0
    local toward =1         -- [1=上、2=右、3=下、4=左]
    local stepCount = 1      --步数

    local circle = 10

    for i = 1, circle do 
        for j = 1, 2 do 
            toward = toward + 1

            if toward > 4 then 
                toward = 1
            end

            for k = 1, stepCount do 
                if toward == 1 then   --上
                    croodY = croodY + 1
                elseif toward == 2 then --右
                    croodX = croodX + 1
                elseif toward == 3 then --下
                    croodY = croodY - 1
                elseif toward == 4 then --左
                    croodX = croodX - 1
                end

                local curPx = px + (croodX * cellWidth)
                local curPy = py + (croodY * cellHeight)

                local f1 = 10
                local f2 = math.random(0, 100) / 100
                local f3 = math.random(0, 100) / 100

                print('croodX = ' .. croodX)
                print('croodY = ' .. croodY)
                print('\n')
                if i == 1 and j == 1 and k == 1 then 
                    draw:drawRect(cc.p(curPx, curPy), cc.p(curPx - cellWidth, curPy - cellHeight), cc.c4f(1,0,0,1))            
                else
                    draw:drawRect(cc.p(curPx, curPy), cc.p(curPx - cellWidth, curPy - cellHeight), cc.c4f(f1,f2,f3,1))            
                end
            end
        end

        -- if toward == 3 then --左
        --     curPx = curPx + 1
        --     curPy = curPy + 1
        -- end

        stepCount = stepCount + 1
    end
end

function Welcomelayer:onWelcomeClicked(pSender, eventType)
    if eventType == ccui.TouchEventType.began then
    elseif eventType == ccui.TouchEventType.moved then
    elseif eventType == ccui.TouchEventType.ended then
        local scene = G_UIManger:replaceScene(G_SceneDefine.SCENE_BATTLE)
        local GameLayer = require 'ui.GameLayer'
        local layer = GameLayer:create()
        G_UIManger:addLayer(layer, scene)
    elseif eventType == ccui.TouchEventType.canceled then
    end
end

function Welcomelayer:onBackClicked(pSender, eventType)
    if eventType == ccui.TouchEventType.ended then
        --BomberScene:create():changeScene(LUCKY_LAYER)
        --cc.Director:getInstance():endToLua()
        SdkDeal:create():showVideoIad()
    end
end

return Welcomelayer