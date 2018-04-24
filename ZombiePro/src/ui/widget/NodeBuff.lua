local NodeBuff = class('NodeBuff', function() 
    return cc.Node:create()
end)

function NodeBuff:ctor(...)
    local args = {...}
    self.parent = args[1]
    self.id = args[2]
    self.config = G_ConfigUtils.getBufferConfigById(self.id)
    self.duringTime = 0
    self:scheduleUpdate()
    self.over = false
    self.userdata = {}
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
        self.over = true
        self:unscheduleUpdate()
    end
end

function NodeBuff:reset()
    self.duringTime = 0
end

function NodeBuff:isOver()
    return self.over
end

return NodeBuff
