local SpriteRole = class('SpriteRole', require 'ui.base.SpriteBase')

function SpriteRole:ctor(...)
    SpriteRole.super.ctor(self)
    local args = {...}
    self.id = args[2]
    self.dir = G_Def.DIR_DOWN
    self.frameCount = {
        [G_Def.ACTION_STAND] = 3,
    }

    self.speed = 10

    self:getTorwardIDByDir()
    self:runAnimal()

    if DEBUG_MOD then 
        --self:drawRect()
    end

    self.targetList = {}
    self.gunConfig = {
        targetCount = 1,
        harm = 3,
        frameAtor = 0.5,
    }

    --非锁定状态 则玩家的朝向和虚拟键保持一致，如锁定状态则朝向与锁定状态保持一致
    self.lock = false 
    self.curSelectTargetList = {}  --当前锁定的目标
end

function SpriteRole:setGameLayer(gameLayer)
    self.gameLayer = gameLayer
end

function SpriteRole:move(angle, direct, power)
    self:getDirByJoyDir(angle, direct)
    self:getTorwardIDByDir()
    self:runAnimal()

    local posX, posY = self:getPosition()
    local x = self.speed * direct.x + posX
    local y = self.speed * direct.y + posY

    local map = self.gameLayer.mainMap
    local tile = map:space2Tile(cc.p(x, y))

    if map:isBlock(tile) then 
        return
    end

    self:setPosition(cc.p(x, y))

    look(cc.p(x, y), 'curPosition')
end

function SpriteRole:getDirByTarget()
    local x, y = self:getPosition()
    if #self.curSelectTargetList == 1 then 
        local target = self.curSelectTargetList[1]
        local tx, ty = target:getPosition()
        return Utils.getDirVector(cc.p(x, y), cc.p(tx, ty))
    elseif #self.curSelectTargetList == 2 then
        local target1 = self.curSelectTargetList[1]
        local target2 = self.curSelectTargetList[2]
        local tx1, ty1 = target1:getPosition()
        local tx2, ty2 = target2:getPosition()

        local vtr1 = Utils.getDirVector(cc.p(x, y), cc.p(tx1, ty1))
        local vtr2 = Utils.getDirVector(cc.p(x, y), cc.p(tx2, ty2))

        return cc.pMul(cc.pAdd(vtr1, vtr2), 0.5)
    elseif #self.curSelectTargetList == 3 then
        local target1 = self.curSelectTargetList[1]
        local target2 = self.curSelectTargetList[2]
        local target3 = self.curSelectTargetList[3]
        local tx1, ty1 = target1:getPosition()
        local tx2, ty2 = target2:getPosition()
        local tx3, ty3 = target2:getPosition()

        local vtr1 = Utils.getDirVector(cc.p(x, y), cc.p(tx1, ty1))
        local vtr2 = Utils.getDirVector(cc.p(x, y), cc.p(tx2, ty2))
        local vtr3 = Utils.getDirVector(cc.p(x, y), cc.p(tx3, ty3))

        return cc.pMul(cc.pAdd(cc.pAdd(vtr1, vtr2), vtr3), 0.33)
    end
end

function SpriteRole:attack()
    local selectList = {}
    local posX, posY = self:getPosition()

    --是否有墙
    for _, target in ipairs(self.targetList) do 
        local x, y = self:getPosition()    
        if not self.gameLayer.mainMap:pathHasBlock(cc.p(posX, posY), cc.p(x, y)) then  
            table.insert(selectList, target)
        end
    end

    if #selectList <= 0 then 
        self.lock = false
        return
    end

    --按照距离排序，可能需要获得前几个 不一定只有一个
    table.sort(selectList, function(A, B) 
        local AX, AY = A:getPosition() 
        local BX, BY = B:getPosition() 
        local ALen = cc.pGetDistance(cc.p(posX, posY), cc.p(AX, AY))
        local BLen = cc.pGetDistance(cc.p(posX, posY), cc.p(BX, BY))

        return ALen < BLen
    end)

    self.curSelectTargetList = {}
    for i = 1, self.gunConfig.targetCount do 
        if selectList[i] then 
            self.curSelectTargetList[i] = selectList[i]
        end
    end

    self.lock = true
end

function SpriteRole:setTargetList(list)
    self.targetList = list
end



return SpriteRole
