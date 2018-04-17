
local device = require 'cocos.framework.device'

local Login = class("Login",  function()
    local ret = cc.Layer:create()
    return ret
end )


--消息传过来准备 点击确定后重连 
function Login:create()
    local ret = LogoAndUpdate:new()
    ret:initUI()
    return ret
end

function Login:initUI() 
    local path = "csb/login/LoginAgain.csb"
    local logoLayer = cc.CSLoader:createNode(path)
end

return Login




   


















