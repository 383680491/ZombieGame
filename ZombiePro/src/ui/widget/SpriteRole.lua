local SpriteRole = class('SpriteRole', require 'ui.base.SpriteBase')

local getOneTrue = function(list)
    for idx, flag in ipairs(list) do 
        if flag then 
            return idx
        end
    end

    return
end


function SpriteRole:ctor(...)
    SpriteRole.super.ctor(self)
    local args = {...}
    self.id = args[2]
    self.dir = G_Def.DIR_DOWN
    self.frameCount = {
        [G_Def.ACTION_STAND] = 3,
    }

    self.speed = 4

--    self:getTorwardIDByDir()
--    self:runAnimal()
    self.mainSprite:loadTexture('hero.png')

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
    local tileList = {}
    local flagList = {}

    tileList[1] = map:space2Tile(cc.p(x + 32, y + 32)) --分别对应 ↗ ↖ ↙ ↘  四个tile
    tileList[2] = map:space2Tile(cc.p(x - 32, y + 32))
    tileList[3] = map:space2Tile(cc.p(x - 32, y - 32))
    tileList[4] = map:space2Tile(cc.p(x + 32, y - 32))
    tileList[5] = map:space2Tile(cc.p(x + 32, y))     
    tileList[6] = map:space2Tile(cc.p(x, y + 32))
    tileList[7] = map:space2Tile(cc.p(x - 32, y))
    tileList[8] = map:space2Tile(cc.p(x, y - 32))

    for idx, tile in ipairs(tileList) do   --如果直接判断有block就return 会感觉人物黏在墙上移不动 摇杆失效的感觉 
        flagList[idx] = map:isBlock(tile)
    end

    --判断 为true有多少个
    local count = 0
    for _, flag in ipairs(flagList) do 
        if flag then 
            count = count + 1
        end
    end

    if count >= 4 then 
        return
    end

    if (flagList[1] and flagList[4] and flagList[5]) or   --代表左右两边的完全没法通行 则Y轴可以同行
        (flagList[2] and flagList[3] and flagList[7]) or
        (flagList[1] and flagList[5] and 2 == count) or
        (flagList[4] and flagList[5] and 2 == count) or
        (flagList[2] and flagList[7] and 2 == count) or
        (flagList[3] and flagList[7] and 2 == count) then
        self:setPositionY(y) 
        return
    elseif (flagList[1] and flagList[2] and flagList[6]) or   --代表上下两边的完全没法通行 则X轴可以同行
        (flagList[3] and flagList[4] and flagList[8]) or
        (flagList[1] and flagList[6] and 2 == count) or
        (flagList[2] and flagList[6] and 2 == count) or
        (flagList[3] and flagList[8] and 2 == count) or
        (flagList[4] and flagList[8] and 2 == count) then
        self:setPositionX(x) 
        return
    end

    if count >= 3 then 
        return
    elseif 1 == count then  --这种最复杂  但只有一个点的时候 也得计算出到底是X方向导致的碰撞还是Y方向，这样子只能通过回溯的方式来
        local idx = getOneTrue(flagList)
        if 1 == idx then 
            local flag_x = map:isBlock(map:space2Tile(cc.p(x + 32, posY + 32)))
            local flag_y = map:isBlock(map:space2Tile(cc.p(posX + 32, y + 32)))
            if flag_x and flag_y then 
                return
            elseif flag_x and not flag_y then
                self:setPositionY(y)
                return
            elseif not flag_x and flag_y then
                self:setPositionX(x) 
                return
            end
        elseif 2 == idx then
            local flag_x = map:isBlock(map:space2Tile(cc.p(x - 32, posY + 32)))
            local flag_y = map:isBlock(map:space2Tile(cc.p(posX - 32, y + 32)))
            if flag_x and flag_y then 
                return
            elseif flag_x and not flag_y then
                self:setPositionY(y)
                return
            elseif not flag_x and flag_y then
                self:setPositionX(x) 
                return
            end
        elseif 3 == idx then
            local flag_x = map:isBlock(map:space2Tile(cc.p(x - 32, posY - 32)))
            local flag_y = map:isBlock(map:space2Tile(cc.p(posX - 32, y - 32)))
            if flag_x and flag_y then 
                return
            elseif flag_x and not flag_y then
                self:setPositionY(y)
                return
            elseif not flag_x and flag_y then
                self:setPositionX(x) 
                return
            end
        elseif 4 == idx then
            local flag_x = map:isBlock(map:space2Tile(cc.p(x + 32, posY - 32)))
            local flag_y = map:isBlock(map:space2Tile(cc.p(posX + 32, y - 32)))
            if flag_x and flag_y then 
                return
            elseif flag_x and not flag_y then
                self:setPositionY(y)
                return
            elseif not flag_x and flag_y then
                self:setPositionX(x) 
                return
            end
        end
        
        return 
    end

    self:setPosition(cc.p(x, y))   

    --如果锁定了 则朝向以锁定目标为主    否则以虚拟摇杆为主
    if self.lock then 
        local dir = self:getDirByTarget()

        if dir then 
            local radian = cc.pToAngleSelf(dir)
            local angle = radian / 3.14159 * 180 --弧度变角度 
            self:setRotation(270 - angle)
        end
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
    for _, target in ipairs(self.curSelectTargetList) do 
        local x, y = self:getPosition()
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

        image.__userdata__ = target
        image:runAction(cc.Sequence:create(cc.FadeOut:create(0.3), cc.CallFunc:create(function(sender) 
            local tar = sender.__userdata__
            sender:removeFromParent()
            tar:hurt(5, 101)
        end)))

        local width = image:getContentSize().width
        image:setScaleX(len / width)
    end
end

function SpriteRole:attack()
    local selectList = {}
    local posX, posY = self:getPosition()

    --是否有墙
    for _, target in ipairs(self.targetList) do 
        local x, y = target:getPosition()    
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
    if #list <= 0 then 
        self.curSelectTargetList = {}
        self.lock = false
    end
    self.targetList = list
end



return SpriteRole
