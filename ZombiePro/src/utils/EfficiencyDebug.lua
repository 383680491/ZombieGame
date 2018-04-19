--
-- Created by IntelliJ IDEA.
-- User: PC
-- Date: 14-9-12
-- Time: 下午8:31
-- To change this template use File | Settings | File Templates.
--
local socket = require "socket"

--获取系统当前时间，以微妙为单位
local function GetCurTime()
    return socket.gettime()
end

--测试工具：完成一段代码所需的时间，检测效率
local _ref

local function Begin()
    _ref =  socket.gettime()
end

local function GetInterval(info)
    info = info or "debug effciency interval:"
    cclog(info.."%f", socket.gettime() - _ref)

    return socket.gettime() - _ref
end

EffiDebug = {
    GetCurTime = GetCurTime ,
    Begin = Begin ,
    GetInterval = GetInterval
}






