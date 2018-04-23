local config = {
    id = 1,
    during = 0.1,
    animal = ''
}
local NodeBuff = class('NodeBuff', require cc.Node)


function NodeBuff:ctor(...)
    local args = {...}
    self.parent = args[2]
    self.id = args[3]
    self.config = {}
    self.duringTime = 0
end

function NodeBuff:scheduleUpdate()
    local update = function(dt)
        self:update(dt);
    end

    self:scheduleUpdateWithPriorityLua(update, 0);
end

function NodeBuff:update(dt)
    self.duringTime = self.duringTime + dt
    if self.duringTime >= self.config.during then 
        self:removeFromParent()
        self.parent:deleteBuf(self.id)
    end
end

function NodeBuff:reset()
    self.duringTime = 0
end

return NodeBuff
