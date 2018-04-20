local SpriteRole = class('SpriteRole', require 'ui.base.SpriteBase')

function SpriteRole:ctor(...)
    SpriteRole.super.ctor(self)
    local args = {...}
    self.id = args[2]
    self.dir = G_Def.DIR_DOWN
    self.frameCount = {
        [G_Def.ACTION_STAND] = 3,
    }

    self.speed = 8

--    self:getTorwardIDByDir()
--    self:runAnimal()
    self.mainSprite:loadTexture('solder.png')

    --简单选定，仅仅只是判断距离不考虑其他因素
    self.targetList = {}
    --刷选出肯定能攻击的，比如距离够但是墙的阻隔，或者怪物无敌 等等~~~
    self.curSelectTargetList = {}
    self.gunConfig = {
        targetCount = 1,
        harm = 3,
        frameAtor = 0.5,
    }

    --非锁定状态 则玩家的朝向和虚拟键保持一致，如锁定状态则朝向与锁定状态保持一致
    self.lock = false 
    self.curSelectTargetList = {}  --当前锁定的目标
    self.attackRadius = 300

    if DEBUG_MOD then 
        self:drawRect()
    end
end

function SpriteRole:setGameLayer(gameLayer)
    self.gameLayer = gameLayer
end

function SpriteRole:move(angle, direct, power)
    --self:getDirByJoyDir(angle, direct)
    --self:getTorwardIDByDir()
    --self:runAnimal()
    if power < 0.3 then 
        power = 0        
    end

    local posX, posY = self:getPosition()
    local x = self.speed * direct.x * power + posX
    local y = self.speed * direct.y * power + posY

    local map = self.gameLayer.mainMap
    local tile = map:space2Tile(cc.p(x, y))

    if map:isBlock(tile) then 
        return
    end

    self:setPosition(cc.p(x, y))   

    --如果锁定了 则朝向以锁定目标为主    否则以虚拟摇杆为主
    if self.lock then 
        local dir = self:getDirByTarget()
        local radian = cc.pToAngleSelf(dir)
        local angle = radian / 3.14159 * 180 --弧度变角度 
        self:setRotation(270 - angle)
    else
        self:setRotation(270 - angle)  -- 180 - angle + 90    角度是逆时针向上旋转  而setRotation顺时针向下旋转 所以先减了180 至于加90
    end                                --是因为游戏美术出图就是向下了90度
end

function SpriteRole:getDirByTarget()
    local x, y = self:getPosition()
    if #self.curSelectTargetList == 1 then 
        local target = self.curSelectTargetList[1]
        local tx, ty = target:getPosition()
        return G_Utils.getDirVector(cc.p(x, y), cc.p(tx, ty))
    elseif #self.curSelectTargetList == 2 then
        local target1 = self.curSelectTargetList[1]
        local target2 = self.curSelectTargetList[2]
        local tx1, ty1 = target1:getPosition()
        local tx2, ty2 = target2:getPosition()

        local vtr1 = G_Utils.getDirVector(cc.p(x, y), cc.p(tx1, ty1))
        local vtr2 = G_Utils.getDirVector(cc.p(x, y), cc.p(tx2, ty2))

        return cc.pMul(cc.pAdd(vtr1, vtr2), 0.5)
    elseif #self.curSelectTargetList == 3 then
        local target1 = self.curSelectTargetList[1]
        local target2 = self.curSelectTargetList[2]
        local target3 = self.curSelectTargetList[3]
        local tx1, ty1 = target1:getPosition()
        local tx2, ty2 = target2:getPosition()
        local tx3, ty3 = target2:getPosition()

        local vtr1 = G_Utils.getDirVector(cc.p(x, y), cc.p(tx1, ty1))
        local vtr2 = G_Utils.getDirVector(cc.p(x, y), cc.p(tx2, ty2))
        local vtr3 = G_Utils.getDirVector(cc.p(x, y), cc.p(tx3, ty3))

        return cc.pMul(cc.pAdd(cc.pAdd(vtr1, vtr2), vtr3), 0.33)
    end
end

function SpriteRole:displayAttack()
    local x, y = self:getPosition()
    local target = self.curSelectTargetList[1]
    local tx, ty = target:getPosition()
    local vector = G_Utils.getDirVector(cc.p(tx, ty), cc.p(x, y))

    local len = cc.pGetDistance(cc.p(x, y), cc.p(tx, ty))
    local radian = cc.pToAngleSelf(vector)
    local angle = radian / 3.14159 * 180 --弧度变角度 
    local image = ccui.ImageView:create('track.png')
    image:setAnchorPoint(0, 0.5)
    image:setRotation(180 - angle)   --角度是逆时针向上旋转  而setRotation顺时针向下旋转
    image:setPosition(cc.p(x, y))
    self:getParent():addChild(image, 100, 100)

    image:runAction(cc.Sequence:create(cc.FadeOut:create(1), cc.CallFunc:create(function(sender) 
        sender:removeFromParent()
    end)))

    local width = image:getContentSize().width
    image:setScaleX(len / width)
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
        self.curSelectTargetList = {}
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

    --直接先改变一次方向 锁定就立刻对准目标
    local dir = self:getDirByTarget()
    local radian = cc.pToAngleSelf(dir)
    local angle = radian / 3.14159 * 180 --弧度变角度 
    self:setRotation(270 - angle)

    self:displayAttack()
end

function SpriteRole:setTargetList(list)
    self.curSelectTargetList = {}
    self.targetList = list
end



return SpriteRole
