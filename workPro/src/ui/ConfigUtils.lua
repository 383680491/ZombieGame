--
-- Created by IntelliJ IDEA.
-- User: Administrator
-- Date: 2015/1/31
-- Time: 19:11
-- To change this template use File | Settings | File Templates.
--
require "src/Config"

local function getMonsterConfigById(id)
    for _, monster in ipairs(monsterConfig) do
        if id == monster.id then
            return monster
        end
    end
end

local function getFlyConfigById(id)
    for _, fly in ipairs(flyConfig) do
        if id == fly.id then
            return fly
        end
    end
end

local function getSolderConfigById(id)
    for _, solder in ipairs(solderConfig) do
        if id == solder.id then
            return solder
        end
    end
end

local function getSolderConfigByIndex(index)
    return solderConfig[index]
end

local function getSkillConfigById(id)
    for _, skill in ipairs(skillConfig) do
        if id == skill.id then
            return skill
        end
    end
end

local function getChapterConfigByIndex(index)
    return chapterConfig[index]
end

local function getGuideDataById(id)
    return guide[id]
end

local function getBuyRuleById(id)
    return buy_hero[id]
end

local function getPropConfigById(id)
    for _, prop in ipairs(propConfig) do
        if id == prop.id then
            return prop
        end
    end
end

local function getBuffConfigById(id)
    for _, buff in ipairs(buffConfig) do
        if id == buff.id then
            return buff
        end
    end
end

ConfigUtils = {
    getMonsterConfigById = getMonsterConfigById,
    getFlyConfigById = getFlyConfigById,
    getSolderConfigById = getSolderConfigById,
    getSolderConfigByIndex = getSolderConfigByIndex,
    getSkillConfigById = getSkillConfigById,
    getChapterConfigByIndex = getChapterConfigByIndex,
    getGuideDataById = getGuideDataById,
    getBuyRuleById = getBuyRuleById,
    getBuffConfigById = getBuffConfigById,
    getPropConfigById = getPropConfigById,
}
