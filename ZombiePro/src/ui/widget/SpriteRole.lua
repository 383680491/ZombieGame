local SpriteRole = class('SpriteRole', require 'ui.base.SpriteBase')
local MineWasteTime = 2   --制造雷需要的时间
local HelpStayTime = 0.3   --在死亡玩家旁边呆足这段时间才开始治疗
local HelpDuringTime = 5   --治疗玩家所需要的时间

local ShieldAnimalLen = 10   --收到攻击后盾相对动画移动的长度
local ShieldTimeCD = 0.3
local AttackTimeCD = 0.3

local STATUS_HELP_NULL = 1 
local STATUS_HELP_STAY = 2 
local STATUS_HELP = 3
local STATUS_HELPING = 4


local SpriteMine = require 'ui.widget.SpriteMine'

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
    self.hurtRadius = 32    --受伤范围也是人物大小

--    self:getTorwardIDByDir()
--    self:runAnimal()
    self.mainSprite = ccui.ImageView:create('hero.png')
    self.mainNode = cc.Node:create()       --角度改变的节点
    self.mainNode:addChild(self.mainSprite)
    self:addChild(self.mainNode)

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
    self.attackTimeCD = 0
    self:scheduleUpdate()

    if DEBUG_MOD then 
        self:drawRect()
    end

    self.helpStatus = STATUS_HELP_NULL
    self.helpStayTime = saveStayTime
    self.heroStaus = 'attack'
    self.shieldTimeCD = 0

    --被攻击的时候 盾会触发一个前移然后后退的一个动画，这段时间移动的方向以该动画为主，如果玩家方向移动了，那盾动的方向就不对了
    self.shiieldAnimalFlag = false 

     --强制动作   比如role 需要播放移动的动画 或者其他强行动作的情况 
    self.isForceAction = false

    self.hp = 200
    self.constVargs.hp = 200
    self:addBloodBar(cc.p(0, 60))
end

function SpriteRole:scheduleUpdate()
    local update = function(dt)
        self:update(dt);
    end

    self:scheduleUpdateWithPriorityLua(update, 0);
end



function SpriteRole:attack()
    if self.isForceAction then 
        return
    end

    if self.attackTimeCD > 0 then 
        return
    end

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
    self.mainNode:setRotation(270 - angle)

    self:displayAttack()
     self.attackTimeCD = AttackTimeCD
end



--
function SpriteRole:makeMine()
    if self.isForceAction then 
        return
    end

    if self.mineNode then 
        return
    end

    local x, y = self:getPosition()
    local time = MineWasteTime
    self.mineNode = cc.Node:create()
    self.gameLayer.mainMap:addChild(self.mineNode)
    self.mineNode:setPosition(cc.p(x, self.hurtRadius + y + 20))

    local to = cc.ProgressTo:create(time, 100)
    local spr = cc.ProgressTimer:create(cc.Sprite:create('progress.png'))
    spr:setType(cc.PROGRESS_TIMER_TYPE_RADIAL)
    spr:setPosition(cc.p(0, 0))
    spr:runAction(cc.RepeatForever:create(to))
    self.mineNode:addChild(spr)

    local delayNode = cc.Node:create()
    self.mineNode:addChild(delayNode)
    delayNode:runAction(cc.Sequence:create(cc.DelayTime:create(time + 0.02), cc.CallFunc:create(function(sender)    
        local parent = sender:getParent()
        parent:removeFromParent()
        self.mineNode = nil

        local x, y = self:getPosition()
        local mine = SpriteMine.new(self.gameLayer)
        mine:setPosition(cc.p(x, y))
        self.gameLayer.mainMap:addChild(mine)
     end)))
end

function SpriteRole:makeDefense()
    if self.isForceAction then 
        return
    end

    if not self.spriteShield then 
        self.spriteShield = cc.Sprite:create('shield.png')
        self.mainNode:addChild(self.spriteShield)
        self.spriteShield:setPosition(cc.p(0, -40))
    end

    self.heroStaus = 'defense'
    self.lock = false
    self.shieldTimeCD = 0
end 

function SpriteRole:removeDefense()
    if self.spriteShield then 
        self.spriteShield:removeFromParent()
        self.spriteShield = nil
    end

    self.heroStaus = 'attack'
    self.shieldTimeCD = 0
end  





function SpriteRole:judgeHelpFriend(dt)
    if self.helpStatus == STATUS_HELP_NULL then 
        for _,role in ipairs(self.gameLayer.roleList) do 
            if role ~= self then
                local x, y = self:getPosition() 
                local rx, ry = role:getPosition() 
                if math.abs(rx - x) <= self.hurtRadius and math.abs(ry - y) <= self.hurtRadius and role:getLifeStatus() == G_Def.STATUS_DEAD then 
                    self.helpStatus = STATUS_HELP_STAY
                    self.helpStayTime = HelpStayTime
                    self.helpSelectFriend = role
                    break
                end
            end
        end
    elseif self.helpStatus == STATUS_HELP_STAY then
        self.helpStayTime = self.helpStayTime - dt
        if self.helpStayTime <= 0 then 
            self.helpFlag = STATUS_HELP
        end
    elseif self.helpStatus == STATUS_HELP then
        self:helpFriend()
        self.helpStatus = STATUS_HELPING
    end
end

function SpriteRole:helpFriend()
    if self.isForceAction then 
        return
    end

    if self.helpNode then 
        return
    end

    local x, y = self:getPosition()
    local time = HelpDuringTime
    self.helpNode = cc.Node:create()
    self.gameLayer.mainMap:addChild(self.helpNode)
    self.helpNode:setPosition(cc.p(x, self.hurtRadius + y + 20))


    local to = cc.ProgressTo:create(time, 100)
    local spr = cc.ProgressTimer:create(cc.Sprite:create('progress.png'))
    spr:setType(cc.PROGRESS_TIMER_TYPE_RADIAL)
    spr:setPosition(cc.p(0, 0))
    spr:runAction(cc.RepeatForever:create(to))
    self.helpNode:addChild(spr)

    local delayNode = cc.Node:create()
    self.helpNode:addChild(delayNode)
    delayNode:runAction(cc.Sequence:create(cc.DelayTime:create(time + 0.02), cc.CallFunc:create(function(sender)    
        local parent = sender:getParent()
        parent:removeFromParent()

        self.helpNode = nil
        if self.helpSelectFriend then 
            self.helpSelectFriend:resurrection()
        end
 
        self.helpStatus = STATUS_HELP_NULL
     end)))
end


--复活
function SpriteRole:resurrection()
    
end

function SpriteRole:setGameLayer(gameLayer)
    self.gameLayer = gameLayer
end

function SpriteRole:update(dt)
    if self.heroStaus == 'deading' or self.heroStaus == 'deaded' then 
        return
    end

    if self.attackTimeCD > 0 then 
        self.attackTimeCD = self.attackTimeCD - dt
    end

    for bufId, target in pairs(self.buffList) do 
        if target:isOver() then 
            target:removeFromParent()
            self.buffList[bufId] = nil
        else
            -- if bufId == 102 then
            --     speed = 0
            -- end
        end
    end

    if self.isForceAction then 
        return
    end

    --击飞状态下的逻辑
    if self.strikeFlyInfo then 
        if self.strikeFlyInfo.time <= 0 then 
            self.strikeFlyInfo = nil
            return
        end

        local posX, posY = self:getPosition()
        local x = self.strikeFlyInfo.dirAtor.x + posX
        local y = self.strikeFlyInfo.dirAtor.y + posY

        if not self:inMapRange(cc.p(x, y)) then 
            self.strikeFlyInfo = nil
            return
        end

        local tileList = self:getNearTile(cc.p(x, y))
        local isBlock = false

        for idx, tile in ipairs(tileList) do
            isBlock = self.gameLayer.mainMap:isBlock(tile)
            if isBlock then 
                break
            end
        end

        if isBlock then 
            self.strikeFlyInfo = nil
        else
            self:setPosition(cc.p(x, y))
            self.strikeFlyInfo.time = self.strikeFlyInfo.time - dt
        end

        return
    end

    if self.heroStaus == 'defense' and self.shieldTimeCD > 0 then 
        self.shieldTimeCD = self.shieldTimeCD - dt
    end
end

function SpriteRole:move(angle, direct, power)
    --self:getDirByJoyDir(angle, direct)
    --self:getTorwardIDByDir()
    --self:runAnimal()

    if self.isForceAction then 
        return
    end

    if self.heroStaus == 'deading' or self.heroStaus == 'deaded' then 
        return
    end

    --击飞和眩状态下遥感无效
    if self.strikeFlyInfo then 
        return
    end 

    --眩晕
    for bufId, target in pairs(self.buffList) do  
        if bufId == 102 then
            return
        end
    end

    if power < 0.3 then 
        power = 0        
    end

    local posX, posY = self:getPosition()
    local x = self.speed * direct.x * power + posX
    local y = self.speed * direct.y * power + posY

    if x == posX and y == posY then 
        return
    end


    --移动则立刻移除埋雷状态
    if self.mineNode then 
        self.mineNode:removeFromParent()
        self.mineNode = nil
    end


    --移动则立刻停止治疗
    if self.helpStatus ~= STATUS_HELP_NULL then 
        self.helpNode:removeFromParent()
        self.helpNode = nil
        self.helpStatus = STATUS_HELP_NULL
    end

    local map = self.gameLayer.mainMap
    local tileList = self:getNearTile(cc.p(x, y))
    local flagList = {}

    for idx, tile in ipairs(tileList) do   --如果直接判断有block就return 会感觉人物黏在墙上移不动 摇杆失效的感觉 
        flagList[idx] = map:isBlock(tile)
    end

    local mapSize = self.gameLayer.mapSize

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

        if y >= self.hurtRadius and y <= mapSize.height - self.hurtRadius then 
            self:setPositionY(y) 
        end

        return
    elseif (flagList[1] and flagList[2] and flagList[6]) or   --代表上下两边的完全没法通行 则X轴可以同行
        (flagList[3] and flagList[4] and flagList[8]) or
        (flagList[1] and flagList[6] and 2 == count) or
        (flagList[2] and flagList[6] and 2 == count) or
        (flagList[3] and flagList[8] and 2 == count) or
        (flagList[4] and flagList[8] and 2 == count) then

        if x >= self.hurtRadius and x <= mapSize.width - self.hurtRadius then 
            self:setPositionX(x) 
        end

        return
    end

    if count >= 3 then 
        return
    elseif 1 == count then  --这种最复杂  但只有一个点的时候 也得计算出到底是X方向导致的碰撞还是Y方向，这样子只能通过回溯的方式来
        local radius = self.hurtRadius
        local idx = getOneTrue(flagList)
        if 1 == idx then 
            local flag_x = map:isBlock(map:space2Tile(cc.p(x + radius, posY + radius)))
            local flag_y = map:isBlock(map:space2Tile(cc.p(posX + radius, y + radius)))
            if flag_x and flag_y then 
                return
            elseif flag_x and not flag_y then
                if y >= self.hurtRadius and y <= mapSize.height - self.hurtRadius then 
                    self:setPositionY(y) 
                end
                return
            elseif not flag_x and flag_y then
                if x >= self.hurtRadius and x <= mapSize.width - self.hurtRadius then 
                    self:setPositionX(x) 
                end

                return
            end
        elseif 2 == idx then
            local flag_x = map:isBlock(map:space2Tile(cc.p(x - radius, posY + radius)))
            local flag_y = map:isBlock(map:space2Tile(cc.p(posX - radius, y + radius)))
            if flag_x and flag_y then 
                return
            elseif flag_x and not flag_y then
                if y >= self.hurtRadius and y <= mapSize.height - self.hurtRadius then 
                    self:setPositionY(y) 
                end
                return
            elseif not flag_x and flag_y then
                if x >= self.hurtRadius and x <= mapSize.width - self.hurtRadius then 
                    self:setPositionX(x) 
                end
                
                return
            end
        elseif 3 == idx then
            local flag_x = map:isBlock(map:space2Tile(cc.p(x - radius, posY - radius)))
            local flag_y = map:isBlock(map:space2Tile(cc.p(posX - radius, y - radius)))
            if flag_x and flag_y then 
                return
            elseif flag_x and not flag_y then
                if y >= self.hurtRadius and y <= mapSize.height - self.hurtRadius then 
                    self:setPositionY(y) 
                end
                return
            elseif not flag_x and flag_y then
                if x >= self.hurtRadius and x <= mapSize.width - self.hurtRadius then 
                    self:setPositionX(x) 
                end
                return
            end
        elseif 4 == idx then
            local flag_x = map:isBlock(map:space2Tile(cc.p(x + radius, posY - radius)))
            local flag_y = map:isBlock(map:space2Tile(cc.p(posX + radius, y - radius)))
            if flag_x and flag_y then 
                return
            elseif flag_x and not flag_y then
                if y >= self.hurtRadius and y <= mapSize.height - self.hurtRadius then 
                    self:setPositionY(y) 
                end
                return
            elseif not flag_x and flag_y then
                if x >= self.hurtRadius and x <= mapSize.width - self.hurtRadius then 
                    self:setPositionX(x) 
                end
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
            self.mainNode:setRotation(270 - angle)
        end
    else 
        --防御状态且执行盾动画过程中 方向无法改变
        if 'defense' == self.heroStaus and self.shiieldAnimalFlag then 
            return
        end

        self.mainNode:setRotation(270 - angle)  -- 180 - angle + 90    角度是逆时针向上旋转  而setRotation顺时针向下旋转 所以先减了180 至于加90
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
            tar:hurt(1, 101)
        end)))

        local width = image:getContentSize().width
        image:setScaleX(len / width)
    end
end

function SpriteRole:setTargetList(list)
    if #list <= 0 then 
        self.curSelectTargetList = {}
        self.lock = false
    end
    self.targetList = list
end

function SpriteRole:deleteTarget(monster)
    for idx, mon in ipairs(self.curSelectTargetList) do 
        if mon == monster then 
            table.remove(self.curSelectTargetList, idx)
            break
        end
    end
end

--击飞strikeFly
function SpriteRole:strikeFly(data)
    self.strikeFlyInfo = data
end

function SpriteRole:hurt(harmValue, buffId, attackObj)
    if self.isForceAction then 
        return
    end

    if self.heroStaus == 'defense' then 
        if self.shieldTimeCD <= 0 then 
            local x, y = self:getPosition()
            if attackObj and self.spriteShield then 
                local tx, ty = attackObj:getPosition()
                local dir = G_Utils.getDirVector(cc.p(x, y), cc.p(tx, ty))
                local radian = cc.pToAngleSelf(dir)
                local angle = radian / 3.14159 * 180 --弧度变角度 
                self.mainNode:setRotation(270 - angle)

                dir = cc.p(0 - dir.x, 0 - dir.y)
                x, y = self.spriteShield:getPosition()
                dir = cc.pMul(dir, ShieldAnimalLen)
                local targetPos = cc.pAdd(cc.p(x, y), dir)

                self.shiieldAnimalFlag = true
                local action = cc.MoveTo:create(0.2, targetPos)
                local revAction = cc.MoveTo:create(0.2, cc.p(x, y))
                self.spriteShield:runAction(cc.Sequence:create(action, revAction, cc.CallFunc:create(function() 
                    self.shiieldAnimalFlag = false
                end)))                 --盾牌收到伤害的动画
            end

            self.shieldTimeCD = ShieldTimeCD
            return
        end
    end

    self.hp = self.hp - harmValue
    if self.hp <= 0 then 
        self.heroStaus = 'deading'
        self:runDeadAnimal()
        return 
    end

    self:runHitAnimal()
    self:updateBloodBar()
    if buffId then 
        self:addBuff(buffId)
    end



    --计算伤害
    local pos = cc.p(0, 50)
    local label = cc.Label:create()
    label:setSystemFontSize(24)
    label:setString('啊')
    label:setScale(1)
    label:setPosition(pos)
    self:addChild(label)

    label:runAction(cc.Sequence:create(
        cc.Spawn:create(
            cc.MoveTo:create(0.5, cc.p(0, 80)),
            cc.ScaleTo:create(0.5, 2)
        ),
        cc.CallFunc:create(function(pender)  pender:removeFromParent() end)
    ))
end

--暂时只有 self.isForceAction  这个时候算是无敌
function SpriteRole:isCanAttack()
    return not self.isForceAction
end 

--获得英雄状态
function SpriteRole:getStatus()
    return self.heroStaus
end

function SpriteRole:runDeadAnimal()
    --run animal
    self.heroStaus = 'deaded'
end 

function SpriteRole:runHitAnimal()
    --run animal
end 

function SpriteRole:isDead()
    return self.heroStaus == 'deaded' or self.heroStaus == 'deading'
end  

function SpriteRole:beginForceAction()
    self.isForceAction = true
end 

function SpriteRole:endForceAction()
    self.isForceAction = false
    
end 


return SpriteRole
