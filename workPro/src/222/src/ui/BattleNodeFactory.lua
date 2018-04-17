BattleNodeFactory = class("BattleNodeFactory", function()
        local ret = {
            animFramesList = {},
        }
        return ret
    end)

BattleNodeFactory.__index = BattleNodeFactory
BattleNodeFactory.__instance = nil

function BattleNodeFactory:ins()
    local ret = nil
    if BattleNodeFactory.__instance == nil then
        ret = BattleNodeFactory:new()
        ret:init()
        BattleNodeFactory.__instance = ret
    else 
        ret = BattleNodeFactory.__instance
    end
    return ret
end

function BattleNodeFactory:init()
end

function BattleNodeFactory:makeMonster(id, config)
    local monster = cc.Sprite:createWithSpriteFrameName(string.format(MONSTER_SRC_FORMAT, config.src, config.animation[1]))

    if not self.animFramesList[config.src] then
        local animFrames = {}
        for _, aniIndex in ipairs(config.animation) do
            local frame =  cc.SpriteFrameCache:getInstance():getSpriteFrame(string.format(MONSTER_SRC_FORMAT, config.src, aniIndex))
            table.insert(animFrames, frame)
        end

        self.animFramesList[config.src] = animFrames
    end

    local aniAction = cc.Animation:createWithSpriteFrames(self.animFramesList[config.src], 0.08)
    local animate = cc.Animate:create(aniAction)
    monster:runAction(cc.RepeatForever:create(animate))

    return monster
end

function BattleNodeFactory:makeGold()
    local gold = cc.Sprite:createWithSpriteFrameName("res/gold_ani_1.png")

    if not self.animFramesList.gold then
        local animFrames = {}
        for aniIndex = 1, 6 do
            local frame =  cc.SpriteFrameCache:getInstance():getSpriteFrame(string.format("res/gold_ani_%d.png", aniIndex))
            table.insert(animFrames, frame)
        end

        self.animFramesList.gold = animFrames
    end

    local aniAction = cc.Animation:createWithSpriteFrames(self.animFramesList.gold, 0.05)
    local animate = cc.Animate:create(aniAction)
    gold:runAction(cc.RepeatForever:create(animate))

    return gold
end

function BattleNodeFactory:makeLight(config)
    local light = cc.Sprite:createWithSpriteFrameName("res/place.png")
    if not self.animFramesList.light then
        local animFrames = {}
        for _, aniIndex in ipairs(config.effectAnimation) do
            local frame =  cc.SpriteFrameCache:getInstance():getSpriteFrame(string.format(EFFECT_SRC_FORMAT, aniIndex))
            table.insert(animFrames, frame)
        end

        self.animFramesList.light = animFrames
    end

    local aniAction = cc.Animation:createWithSpriteFrames(self.animFramesList.light, 0.3 / #self.animFramesList.light)
    local animate = cc.Animate:create(aniAction)
    light:runAction(cc.RepeatForever:create(animate))

    return light
end


