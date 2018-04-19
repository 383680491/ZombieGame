local Utils = {}

function Utils.getDirVector(beginPos, endPos)
	return cc.pNormalize(cc.pSub(endPos, beginPos))
end


--获得时间描述
function Utils.getTimeDisc(sec)
    if sec > 3600 then
        local hour = math.floor(sec / 3600)
        local min  = math.floor((sec % 3600) / 60)
        return string.format("%d时%d分", hour, min)
    else
        local min = math.floor(sec / 60)
        local sec  = math.floor(sec % 60)
        return string.format("%d分%d秒", min, sec)
    end
end




--将时间转化为00:00:00
--时间单位
local DAY  = 86400
local HOUR = 3600
local MIN  = 60

function Utils.formatWorldTime(time)
    local hour = math.floor(time/HOUR)
    local tmp = math.mod(time, HOUR)
    local min = math.floor(tmp/MIN)
    local sec = math.mod(tmp, MIN)
    if hour > 0 then
        return string.format("%.2d:%.2d:%.2d", hour, min, sec)
    elseif hour == 0 and min > 0 then
        return string.format("%.2d:%.2d", min, sec)
    else
        return string.format("%.2d", sec)
    end
end

--将时间转化为2015-1-2 10:00:00 
function Utils.formatCalTime(tm)
    local date = Utils.getDateByGMT(tm)
    return string.format("%d-%.2d-%.2d %.2d:%.2d:%.2d", date.year, date.month, date.day,
        date.hour, date.min, date.sec)
end

--将字符串通过指定的字符进行分割 返回table
--str为原串        decollator为分隔符
function Utils.split(str, decollator)
    local retStrList = {}
    string.gsub(str, '[^' .. decollator ..']+',
        function(word)
            table.insert(retStrList, word)
        end
    )
    return retStrList
end


--获得utf-8字符串的长度
function Utils.utfstrlen(str)
    local len = #str;
    local left = len;
    local cnt = 0;
    local arr={0,0xc0,0xe0,0xf0,0xf8,0xfc};

    while left ~= 0 do
        local tmp=string.byte(str,-left);
        local i=#arr;

        while arr[i] do
            if tmp>=arr[i] then left=left-i;break;end
            i=i-1;
        end

        cnt=cnt+1;
    end

    return cnt;
end



--设置透明度同时对子节点有效调用此方法
function Utils.setNodeCascadeOpacityEnabled(node) 
    local children = node:getChildren();

    for _, child in ipairs(children) do 
        setNodeCascadeOpacityEnabled(child);
    end

    node:setCascadeOpacityEnabled(true);
end


return Utils