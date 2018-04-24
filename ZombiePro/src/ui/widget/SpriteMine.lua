        --run bomb  animal   假设动画0.3秒 则 0.15秒就开始计算伤害加buf，这样子效果会好一些

local SpriteMine = class('SpriteMine', cc.Node)
local STATUS_Ready = 1   
local STATUS_Active = 2
local STATUS_Bomb = 3
local STATUS_Hurm = 4
function SpriteMine:ctor(...)
    self.mainSprite:loadTexture('mine.png')
    self:addChild(self.mainSprite)
    self:scheduleUpdate();

    self.warningRadiis = 30
    self.attackRadiis = 100
    self.status = STATUS_Ready

    self.startHurm = 0.15
end

function SpriteMine:scheduleUpdate()
    local update = function(dt)
        self:update(dt);
    end

    self:scheduleUpdateWithPriorityLua(update, 0);
end

function SpriteMine:setGameLayer(gameLayer)
    self.gameLayer = gameLayer
end

function SpriteMine:update(dt)
    if self.status == STATUS_Ready then 
        local x, y = self:getPosition()
        for _, role in ipairs(self.gameLayer.roleList) do 
            local posX, posY = role:getPosition()
            local roleRadius = role:getHurtRadius()
            
            if Utils.circleIntersect(cc.p(x, y), self.warningRadiis, cc.p(posX, posY), roleRadius) then 
                self.status = STATUS_Active
            end
        end

        if self.status == STATUS_Ready then
            for _, monster in ipairs(self.gameLayer.monsterList) do 
                local mX, mY = monster:getPosition()
                local mRadius = role:getHurtRadius()

                if Utils.circleIntersect(cc.p(x, y), self.warningRadiis, cc.p(mX, mY), mRadius) then 
                    self.status = STATUS_Active
                end
            end
        end
    elseif self.status == STATUS_Active then 
        --run animal  动画执行完后移除
        self.status = STATUS_Bomb
    elseif self.status == STATUS_Bomb then 
        self.startHurm = self.startHurm - dt

        if self.startHurm <=0 then 
            self.status == STATUS_Hurm
        end
    elseif self.status == STATUS_Hurm then 
        local x, y = self:getPosition()
        for _, role in ipairs(self.gameLayer.roleList) do 
            local posX, posY = role:getPosition()
            local roleRadius = role:getHurtRadius()
            
            if Utils.circleIntersect(cc.p(x, y), self.attackRadiis, cc.p(posX, posY), roleRadius) then 
                role:hurt(20, 102)

                local dir = Utils.getDirVector(cc.p(x, y), cc.p(mX, mY))
                local time = 0.3       --击飞时间持续0.3
                local length = 30      --击飞距离为30
                local perFrame = (30 / 0.3)/60   --每帧的速度
                dir = cc.pMul(dir, perFrame)

                local t = {time = time, dirAtor = dir}
                role:strikeFly(t)
            end
        end

        for _, monster in ipairs(self.gameLayer.monsterList) do 
            local mX, mY = monster:getPosition()
            local mRadius = role:getHurtRadius()

            if Utils.circleIntersect(cc.p(x, y), self.attackRadiis, cc.p(mX, mY), mRadius) then 
                monster:hurt(20, 102)
                local dir = Utils.getDirVector(cc.p(x, y), cc.p(mX, mY))
                local time = 0.3       --击飞时间持续0.3
                local length = 30      --击飞距离为30
                local perFrame = (30 / 0.3)/60   --每帧的速度
                dir = cc.pMul(dir, perFrame)

                local t = {time = time, dirAtor = dir} 
                monster:strikeFly(t)
            end
        end

        self:unscheduleUpdate()
    end

end

return SpriteMine
