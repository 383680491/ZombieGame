local app = cc.Application:getInstance()
local plat = app:getTargetPlatform()

cclog = function(...)
    print(...) 
end

function __G__TRACKBACK__(msg)
    cclog("-----------------code by lx-----------------------")
    cclog("LUA ERROR: " .. tostring(msg) .. "\n")
    cclog(debug.traceback())
    cclog("------------------code by lx----------------------")
end



OPEN_HOT_UPDATE = true

function setSearchPath()
	cc.FileUtils:getInstance():setPopupNotify(false)
    local WRITEABLEPATH = cc.FileUtils:getInstance():getWritablePath()
    print("设备可写目录:%s", WRITEABLEPATH);

    CACHEDIR = WRITEABLEPATH .. "cache/";
    _G.__MY_HOT_UPDATE_PATH__ = CACHEDIR .. 'hot/'

    if not (cc.FileUtils:getInstance():isDirectoryExist(CACHEDIR)) then        
        cc.FileUtils:getInstance():createDirectory(CACHEDIR) 
        print("创建游戏图片缓存目录成功:%s", CACHEDIR)      
    end

    if not (cc.FileUtils:getInstance():isDirectoryExist(_G.__MY_HOT_UPDATE_PATH__)) then        
        cc.FileUtils:getInstance():createDirectory(_G.__MY_HOT_UPDATE_PATH__) 
        print("创建热更新缓存目录成功:%s", _G.__MY_HOT_UPDATE_PATH__)      
    end

    print(_G.__MY_HOT_UPDATE_PATH__)
    cc.FileUtils:getInstance():addSearchPath(CACHEDIR);
    cc.FileUtils:getInstance():addSearchPath("res/");
    cc.FileUtils:getInstance():addSearchPath("src/");
    --cc.FileUtils:getInstance():addSearchPath("lastRes/img/prize_pic/");

    if OPEN_HOT_UPDATE then 
        cc.FileUtils:getInstance():addSearchPath(_G.__MY_HOT_UPDATE_PATH__ .. "src/", true);
        cc.FileUtils:getInstance():addSearchPath(_G.__MY_HOT_UPDATE_PATH__ .. "res/", true)
        --cc.FileUtils:getInstance():addSearchPath(_G.__MY_HOT_UPDATE_PATH__ .. "lastRes/img/prize_pic/", true)
    end
end

setSearchPath()


-----------------------------------------------------------------
--             基本引入
-----------------------------------------------------------------
require "config"
require "cocos.init"
require "utils.Log"
G_Utils = require "utils.Utils"
require "ui.base.UIDef"
require "utils.SLUI"
local EventEmitter = require "utils.EventEmitter"
G_Def = require "common.Define"


-----------------------------------------------------------------
--             main 入口
-----------------------------------------------------------------
local function main()
    -- 每5000毫秒回收内存
    collectgarbage("setpause", 100)
    collectgarbage("setstepmul", 5000)
    -- 加载GLView
    local director = cc.Director:getInstance()
    local glView = director:getOpenGLView()
    if nil == glView then
        glView = cc.GLViewImpl:create("myWork")
        director:setOpenGLView(glView)
    end

    director:setOpenGLView(glView)
    glView:setDesignResolutionSize(1280, 720, cc.ResolutionPolicy.NO_BORDER )
    director:setDisplayStats(true)
    director:setAnimationInterval(1.0 / 60)

    -- require "data.BridgeManager"
    -- BridgeManager:ins();
       
    G_EmitIns = EventEmitter:new()
    local UIManager = require 'ui.base.UIManager'
    G_UIManger = UIManager:new()
           -- require "update.LogoAndUpdate"

    -- local layer = LogoAndUpdate:create(function() 
    --     print('更新成功啦')
    -- end);
    
    local scene = G_UIManger:replaceScene(G_SceneDefine.SCENE_LOGIN)
    local WelcomeLayer = require 'ui.WelcomeLayer'
    local layer = WelcomeLayer:create()
    G_UIManger:addLayer(layer, scene)
end

xpcall(main, __G__TRACKBACK__)
