--run bomb  animal   假设动画0.3秒 则 0.15秒就开始计算伤害加buf，这样子效果会好一些
local SpriteMine = class('SpriteMine', cc.Node)
local STATUS_Born = 0
local STATUS_Ready = 1   
local STATUS_Active = 2
local STATUS_Bomb = 3
local STATUS_Hurm = 4
local STATUS_OVER = 5

local Strike_Time = 0.1   --击飞时间持续
local Strike_Len = 50     --击飞距离为
local ReadyTime = 3     --STATUS_Born到STATUS_Ready的时间,如果人物在埋雷后这段时间没有离开 就会被炸

function SpriteMine:ctor(...)
    local args = {...}
    self.gameLayer = args[1]
    self.mainSprite = cc.Sprite:create('001.png')
    self:addChild(self.mainSprite)
    self:scheduleUpdate();

    self.warningRadiis = 32
    self.attackRadiis = 100
    self.status = STATUS_Born

    self.readyTime = ReadyTime
    self.startHurm = 0.15

    table.insert(self.gameLayer.mineList, self)
end

function SpriteMine:scheduleUpdate()
    local update = function(dt)
        self:update(dt);
    end

    self:scheduleUpdateWithPriorityLua(update, 0);
end

function SpriteMine:update(dt)
    if self.status == STATUS_Born then 
        self.readyTime = self.readyTime - dt
        if self.readyTime <= 0 then 
            self.status = STATUS_Ready
        end
    elseif self.status == STATUS_Ready then 
        local x, y = self:getPosition()
        for _, role in ipairs(self.gameLayer.roleList) do 
            local posX, posY = role:getPosition()
            local roleRadius = role:getHurtRadius()
            
            if G_Utils.circleIntersect(cc.p(x, y), self.warningRadiis, cc.p(posX, posY), roleRadius) then 
                self.status = STATUS_Active
            end
        end

        if self.status == STATUS_Ready then
            for _, monster in ipairs(self.gameLayer.monsterList) do 
                local mX, mY = monster:getPosition()
                local mRadius = monster:getHurtRadius()

                if G_Utils.circleIntersect(cc.p(x, y), self.warningRadiis, cc.p(mX, mY), mRadius) then 
                    self.status = STATUS_Active
                end
            end
        end
    elseif self.status == STATUS_Active then 
        --run animal  动画执行完后移除
        self.status = STATUS_Bomb
        local animFrames = {}
        for i = 1, 4 do 
            local path = string.format('bomb_%d.png', i)
            local frame =  cc.SpriteFrameCache:getInstance():getSpriteFrame(path)
            table.insert(animFrames, frame)
        end

        local aniAction = cc.Animation:createWithSpriteFrames(animFrames, 0.1)
        local animate = cc.Animate:create(aniAction)
        self.mainSprite:stopAllActions()
        self.mainSprite:runAction(cc.RepeatForever:create(animate))
    elseif self.status == STATUS_Bomb then 
        self.startHurm = self.startHurm - dt

        if self.startHurm <=0 then 
            self.status = STATUS_Hurm
        end
    elseif self.status == STATUS_Hurm then 
        local x, y = self:getPosition()
        for _, role in ipairs(self.gameLayer.roleList) do 
            local posX, posY = role:getPosition()
            local roleRadius = role:getHurtRadius()
            
            if G_Utils.circleIntersect(cc.p(x, y), self.attackRadiis, cc.p(posX, posY), roleRadius) then 
                role:hurt(20, 102)

                local dir = G_Utils.getDirVector(cc.p(x, y), cc.p(posX, posY))
                local perFrame = (Strike_Len / Strike_Time)/60   --每帧的速度
                dir = cc.pMul(dir, perFrame)

                local t = {time = Strike_Time, dirAtor = dir}
                role:strikeFly(t)
            end
        end

        for _, monster in ipairs(self.gameLayer.monsterList) do 
            local mX, mY = monster:getPosition()
            local mRadius = monster:getHurtRadius()

            if G_Utils.circleIntersect(cc.p(x, y), self.attackRadiis, cc.p(mX, mY), mRadius) then 
                monster:hurt(20, 102)
                local dir = G_Utils.getDirVector(cc.p(x, y), cc.p(mX, mY))
                local perFrame = (Strike_Len / Strike_Time)/60   --每帧的速度
                dir = cc.pMul(dir, perFrame)

                local t = {time = Strike_Time, dirAtor = dir} 
                monster:strikeFly(t)
            end
        end

        --self:removeFromParent()
        self.status = STATUS_OVER
        self:unscheduleUpdate()
    end
end

function SpriteMine:getStatus() 
    return self.status
end

return SpriteMine
