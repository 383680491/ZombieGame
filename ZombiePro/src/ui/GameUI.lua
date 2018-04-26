--
-- Created by IntelliJ IDEA.
-- User: PC
-- Date: 15-2-13
-- Time: 上午11:19
-- To change this template use File | Settings | File Templates.
--
local device = require 'cocos.framework.device'
local GameUI = class("GameUI", require 'ui.base.BaseView')

local TAG_1 = 1
local TAG_2 = 2
local TAG_3 = 3
local TAG_Pause = 4
local TAG_setting = 5

function GameUI:ctor()
    GameUI.super:ctor()
    self.uiLayer = SLUI:createNode("csb/battle/battle.csb")
    self:addChild(self.uiLayer)

    local button_fire = self.uiLayer:getChildByName('button_fire')
    local button_other_1 = self.uiLayer:getChildByName('button_other_1')
    local button_other_2 = self.uiLayer:getChildByName('button_other_2')
    local button_other_3 = self.uiLayer:getChildByName('button_other_3')
    button_other_1:setTag(TAG_1)
    button_other_2:setTag(TAG_2)
    button_other_3:setTag(TAG_3)


    local fire = function(sender, type)
        if type == cc.EventCode.ENDED then
            self:fire()
        end
    end

    button_fire:addTouchEventListener(fire);

    local btnCallback = function(sender, type) 
        if type == cc.EventCode.ENDED then
            local tag = sender:getTag()
            self:btnCallback(tag)
        end
    end

     button_other_1:addTouchEventListener(btnCallback);
     button_other_2:addTouchEventListener(btnCallback);
     button_other_3:addTouchEventListener(btnCallback);
end

function GameUI:setGameLayer(gameLayer)
    self.gameLayer = gameLayer
end

function GameUI:fire()
    self.gameLayer:attack()
end

function GameUI:btnCallback(tag)
    look(tag, 'tag')
    if tag == TAG_1 then 
    elseif tag == TAG_2 then

    elseif tag == TAG_3 then

    end
end

return GameUI