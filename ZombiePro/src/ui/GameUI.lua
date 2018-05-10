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
local TAG_MONSTER_1 = 4
local TAG_MONSTER_2 = 5
local TAG_MONSTER_3 = 6
local TAG_MONSTER_4 = 7


local TAG_Pause = 4
local TAG_setting = 5

function GameUI:ctor()
    GameUI.super:ctor()
    self.uiLayer = SLUI:createNode("csb/battle/battle.csb")
    self:addChild(self.uiLayer)

    self.button_fire = self.uiLayer:getChildByName('button_fire')
    self.button_other_1 = self.uiLayer:getChildByName('button_other_1')
    self.button_other_2 = self.uiLayer:getChildByName('button_other_2')
    self.button_other_3 = self.uiLayer:getChildByName('button_other_3')

    self.button_monster_1 = self.uiLayer:getChildByName('button_monster_1')
    self.button_monster_2 = self.uiLayer:getChildByName('button_monster_2')
    self.button_monster_3 = self.uiLayer:getChildByName('button_monster_3')
    self.button_monster_4 = self.uiLayer:getChildByName('button_monster_4')

    self.button_other_1:setTag(TAG_1)
    self.button_other_2:setTag(TAG_2)
    self.button_other_3:setTag(TAG_3)
    self.button_monster_1:setTag(TAG_MONSTER_1)
    self.button_monster_2:setTag(TAG_MONSTER_2)
    self.button_monster_3:setTag(TAG_MONSTER_3)
    self.button_monster_4:setTag(TAG_MONSTER_4)

    local label = cc.Label:create()
    label:setSystemFontSize(48)
    label:setString('雷')
    label:setPosition(cc.p(self.button_other_1:getContentSize().width / 2, self.button_other_1:getContentSize().height / 2))
    self.button_other_1:addChild(label)



    label = cc.Label:create()
    label:setSystemFontSize(48)
    label:setString('盾')
    label:setPosition(cc.p(self.button_other_2:getContentSize().width / 2, self.button_other_2:getContentSize().height / 2))
    self.button_other_2:addChild(label)




    local fire = function(sender, type)
        if type == cc.EventCode.ENDED then
            if 'attack' == self.gameLayer:getHeroStatus() then 
                self:fire()
            else
                self.gameLayer:removeDefense()

                self.button_other_1:setVisible(true)
                self.button_other_2:setVisible(true)
                self.button_other_3:setVisible(true)
                self.button_fire:removeAllChildren()
            end
        end
    end

    self.button_fire:addTouchEventListener(fire);

    local btnCallback = function(sender, type) 
        if type == cc.EventCode.ENDED then
            local tag = sender:getTag()
            self:btnCallback(tag)
        end
    end

     self.button_other_1:addTouchEventListener(btnCallback);
     self.button_other_2:addTouchEventListener(btnCallback);
     self.button_other_3:addTouchEventListener(btnCallback);
     self.button_monster_1:addTouchEventListener(btnCallback);
     self.button_monster_2:addTouchEventListener(btnCallback);
     self.button_monster_3:addTouchEventListener(btnCallback);
     self.button_monster_4:addTouchEventListener(btnCallback);
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
        self.gameLayer:makeMine()
    elseif tag == TAG_2 then
        if 'attack' == self.gameLayer:getHeroStatus() then 
            self.gameLayer:makeDefense()
            self.button_other_1:setVisible(false)
            self.button_other_2:setVisible(false)
            self.button_other_3:setVisible(false)

            local label = cc.Label:create()
            label:setSystemFontSize(48)
            label:setString('移除盾')
            label:setPosition(cc.p(self.button_other_2:getContentSize().width / 2, self.button_other_2:getContentSize().height / 2))
            self.button_fire:addChild(label)
        end
    elseif tag == TAG_3 then

    elseif tag == TAG_MONSTER_1 then
        self.gameLayer:addMonster()
    elseif tag == TAG_MONSTER_2 then
        self.gameLayer:addBossA()
    elseif tag == TAG_MONSTER_3 then
        self.gameLayer:addBossB()
    elseif tag == TAG_MONSTER_4 then

    end
end

return GameUI