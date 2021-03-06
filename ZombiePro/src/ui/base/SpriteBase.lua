local NodeBuff = require 'ui.widget.NodeBuff'
local SpriteBase = class('SpriteBase', NodeAStar) --NodeAStar

function SpriteBase:ctor()
    self.mainSprite = nil
    self.dir = G_Def.DIR_UP
    self.torwardId = G_Def.DIR_RIGHT
    self.action = G_Def.ACTION_STAND
    self.id = 10005
    self.actionFactot = 0.5
    self.speedFactor = 5
    self.speed = 0
    self.sourcePath = 'role_%d_%s_%05d.png'
    self.hurtRadius = 50   --受伤范围
    self.attackRadius = 100  --攻击范围
    self.warningRadiis = -1  --警戒范围   （-1是全屏 这个参数应该只有怪物会用到，在警戒范围内，会寻找目标攻击）
    self.buffList = {}
    self.lifeStatus = G_Def.STATUS_LIVING
    self.constVargs = {
        speed = 3.5,
        hp = 5
    }

    self.hp = 5
end


function SpriteBase:getHurtRadius()
    return self.hurtRadius
end

function SpriteBase:getAttackRadius()
    return self.attackRadius
end

function SpriteBase:getWarningRadiis()
    return self.warningRadiis
end

function SpriteBase:isDead()
    return self.hp <= 0
end

function SpriteBase:drawRect()
    local drawNode = cc.DrawNode:create()
    self:addChild(drawNode, 100)
    local x, y = self:getPosition()
    drawNode:drawCircle(cc.p(x, y), self.hurtRadius, 0, 50, false, cc.c4f(0,0,1,1))  
    drawNode:drawCircle(cc.p(x, y), self.attackRadius, 0, 50, false, cc.c4f(1,0,0,1))    
end

function SpriteBase:hurt(harmValue, buffId)
    self.hp = self.hp - harmValue
    if self.hp <= 0 then 
        self:runDeadAnimal()
        return 
    end

    self:runHitAnimal()
    self:updateBloodBar()
    if buffId then 
        self:addBuff(buffId)
    end
end

function SpriteBase:addBuff(id)
    if not self.buffList[id] then 
        self.buffList[id] = NodeBuff.new(self, id)
        self:addChild(self.buffList[id])
    else
        self.buffList[id]:reset()
    end
end

function SpriteBase:getLifeStatus()
    return self.lifeStatus
end

function SpriteBase:setLifeStatus(status)
    self.lifeStatus = status
end

function SpriteBase:getNearTile(pos)
    local tileList = {}
    local x, y = pos.x, pos.y
    local map = self.gameLayer.mainMap
    local radius = self.hurtRadius
    tileList[1] = map:space2Tile(cc.p(x + radius, y + radius)) --分别对应 ↗ ↖ ↙ ↘  四个tile
    tileList[2] = map:space2Tile(cc.p(x - radius, y + radius))
    tileList[3] = map:space2Tile(cc.p(x - radius, y - radius))
    tileList[4] = map:space2Tile(cc.p(x + radius, y - radius))
    tileList[5] = map:space2Tile(cc.p(x + radius, y))     
    tileList[6] = map:space2Tile(cc.p(x, y + radius))
    tileList[7] = map:space2Tile(cc.p(x - radius, y))
    tileList[8] = map:space2Tile(cc.p(x, y - radius))

    return tileList
end

function SpriteBase:inMapRange(pos)
    local mapSize = self.gameLayer.mapSize
    local radius = self.hurtRadius
    local rect = cc.rect(radius, radius, mapSize.width - radius, mapSize.height - radius)

    return cc.rectContainsPoint(rect, pos)
end

function SpriteBase:addBloodBar(pos)
    pos = pos or cc.p(0, 100)
    local barBg = ccui.ImageView:create("hp_pro_bg.png")
    barBg:setScaleX(0.8)
    barBg:setPosition(pos)
    self:addChild(barBg)

    self.bloodProgress = cc.ProgressTimer:create(cc.Sprite:create("hp_pro.png"))  
    self.bloodProgress:setPosition(cc.p(barBg:getContentSize().width / 2, barBg:getContentSize().height / 2))
    self.bloodProgress:setType(cc.PROGRESS_TIMER_TYPE_BAR)
    self.bloodProgress:setAnchorPoint(cc.p(0.5,0.5))
    self.bloodProgress:setBarChangeRate(cc.p(1, 0))
    self.bloodProgress:setMidpoint(cc.p(0,1))
    barBg:addChild(self.bloodProgress)
    self.bloodProgress:setPercentage(100)
end

function SpriteBase:updateBloodBar()
    self.bloodProgress:setPercentage(100 * self.hp / self.constVargs.hp)
end




--下面这三个函数是针对三转二来的 比如孤胆枪手    不要删除
function SpriteBase:runAnimal()   
    if self.dir ~= self.lastDir then 
        local animFrames = {}
        for i = 1, self.frameCount[self.action] do 
            local path = string.format(self.sourcePath, self.id, G_Def.ActionRelative[self.action], self.torwardId*10000 + i)
            --look(path, 'path')
            local frame =  cc.SpriteFrameCache:getInstance():getSpriteFrame(path)
            table.insert(animFrames, frame)
        end

        local aniAction = cc.Animation:createWithSpriteFrames(animFrames, self.actionFactot)
        local animate = cc.Animate:create(aniAction)
        self.mainSprite:stopAllActions()
        self.mainSprite:runAction(cc.RepeatForever:create(animate))
        self.lastDir = self.dir
    end 
end


function SpriteBase:getTorwardIDByDir()
    if self.dir == self.lastDir then 
        return
    end

    if self.dir == G_Def.DIR_UP then 
        self.torwardId = 0
        self.mainSprite:setFlippedX(false)
    elseif self.dir == G_Def.DIR_DOWN then
        self.torwardId = 4
        self.mainSprite:setFlippedX(false)
    elseif self.dir == G_Def.DIR_LEFT then
        self.torwardId = 2
        self.mainSprite:setFlippedX(true)
    elseif self.dir == G_Def.DIR_RIGHT then
        self.torwardId = 2
        self.mainSprite:setFlippedX(false)
    elseif self.dir == G_Def.DIR_RIGHT_UP then
        self.torwardId = 1
        self.mainSprite:setFlippedX(false)
    elseif self.dir == G_Def.DIR_LEFT_UP then
        self.torwardId = 1
        self.mainSprite:setFlippedX(true)
    elseif self.dir == G_Def.DIR_RIGHT_DOWN then
        self.torwardId = 3
        self.mainSprite:setFlippedX(false)
    elseif self.dir == G_Def.DIR_LEFT_DOWN then
        self.torwardId = 3
        self.mainSprite:setFlippedX(true)
    end
end

function SpriteBase:getDirByJoyDir(angle, direct)
    if direct.x < 0.05 and direct.x > -0.05 then 
        if direct.y > 0 then 
            self.dir = G_Def.DIR_UP
        elseif direct.y < 0 then
            self.dir = G_Def.DIR_DOWN
        end
    elseif direct.y < 0.05 and direct.y > -0.05 then 
        if direct.x > 0 then 
            self.dir = G_Def.DIR_RIGHT
        elseif direct.x < 0 then
            self.dir = G_Def.DIR_LEFT
        end
    end

    if direct.x >= 0.05 and direct.y >= 0.05 then 
        self.dir = G_Def.DIR_RIGHT_UP
    elseif direct.x <= -0.05 and direct.y >= 0.05 then 
        self.dir = G_Def.DIR_LEFT_UP
    elseif direct.x <= -0.05 and direct.y <= -0.05 then 
        self.dir = G_Def.DIR_LEFT_DOWN
    elseif direct.x >= 0.05 and direct.y <= -0.05 then 
        self.dir = G_Def.DIR_RIGHT_DOWN
    end
end









return SpriteBase
