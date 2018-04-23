--
-- Created by IntelliJ IDEA.
-- User: Administrator
-- Date: 2015/1/31
-- Time: 19:11
-- To change this template use File | Settings | File Templates.
--
require "src.ui.Config"
local ConfigUtils = {}

function ConfigUtils.getBufferConfigById(id)
    if not ConfigUtils.buffMap then 
        ConfigUtils.buffMap = {}

        for _, buff in ipairs(G_BuffConfig) do
            ConfigUtils.buffMap[buff.id] = buff
        end
    end

    return ConfigUtils.buffMap[id]
end

return ConfigUtils