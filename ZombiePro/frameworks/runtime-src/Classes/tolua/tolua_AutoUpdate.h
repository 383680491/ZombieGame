#include "common/utils.h"
#include "tolua_fix.h"
#include "autoupdate/sdAutoUpdate.h"
#include "autoupdate/sdServerList.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	#pragma comment(lib,"Psapi.lib")
	#include "Psapi.h"
#else
#include <dirent.h>
#include <sys/stat.h>
#endif

static int lua_getMemory(lua_State* L)
{
    if (nullptr == L)
        return 0;
    
    int argc = lua_gettop(L);
    if (0 == argc)
    {

		#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
		{
			HANDLE handle = GetCurrentProcess();
			PROCESS_MEMORY_COUNTERS pmc;
			GetProcessMemoryInfo(handle, &pmc, sizeof(pmc));
			tolua_pushnumber(L, pmc.WorkingSetSize);
			  return 1;
		}
		#endif      
    }
    
    cocos2d::log("'getMemory' function wrong number of arguments: %d, was expecting %d\n", argc, 0);
    return 0;
}

#include "autoupdate/sdAutoUpdate.h"

static int lua_startGetServerInfo(lua_State* L)
{
    const char* url = luaL_checkstring(L, 1);
    sdAutoUpdate::startGetServerInfo(url);

    return 0;
}

static int lua_getServerInfo(lua_State* L)
{
    std::string serverInfo = sdAutoUpdate::getServerInfo();
    lua_pushlstring(L, serverInfo.c_str(), serverInfo.size());

    return 1;
}

static int lua_startGetFileList(lua_State* L)
{
    const char* version = luaL_checkstring(L, 1);
    sdAutoUpdate::startGetFileList(version);

    return 0;
}

static int lua_startUpdate(lua_State* L)
{
    sdAutoUpdate::startUpdate();
    return 0;
}

static int lua_endUpdate(lua_State* L)
{
    sdAutoUpdate::endUpdate();
    return 0;
}

static int lua_getUpdateState(lua_State* L)
{
    int state = (int)sdAutoUpdate::getState();
    lua_pushinteger(L, state);

    return 1;
}

static int lua_getUpdateCurrentSize(lua_State* L)
{
    lua_pushnumber(L, sdAutoUpdate::getCurrentSize());
    return 1;
}

static int lua_getUpdateTotalSize(lua_State* L)
{
    lua_pushnumber(L, sdAutoUpdate::getTotalSize());
    return 1;
}

static int lua_updateNeedRestart(lua_State* L)
{
    lua_pushboolean(L, sdAutoUpdate::getRestart() ? 1 : 0);
    return 1;
}

static int lua_updateNeedReinstall(lua_State* L)
{
    lua_pushboolean(L, sdAutoUpdate::getReinstall() ? 1 : 0);
    return 1;   
}

static int lua_restartApp(lua_State* L)
{
    restartApp();
    return 0;
}

static int lua_installApp(lua_State* L)
{
    const char* appfile = luaL_checkstring(L, 1);
    installApp(appfile);
    return 0;
}

int lua_setUpdateStateChangeCB(lua_State* L)
{
    int callback = toluafix_ref_function(L, 1, 0);
    sdAutoUpdate::setStateChangeCB(callback);
    return 0;
}

int lua_setUpdateProgressCB(lua_State* L)
{
    int callback = toluafix_ref_function(L, 1, 0);
    sdAutoUpdate::setProgressCB(callback);
    return 0;
}

int lua_getHostName(lua_State* L)
{
    char name[256] = { 0 };
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    if (gethostname(name, sizeof(name)) != 0)
    {
        name[0] = 0;
    }
#else
    unsigned long size;
    const char* buf = (const char*)readFile("hostname.txt", &size);
    if (buf && size > 0)
    {
        strncpy(name, buf, sizeof(name));
        name[sizeof(name) - 1] = 0;
    }
    CC_SAFE_DELETE_ARRAY(buf);
#endif

    lua_pushstring(L, name);
    return 1;
}

int lua_getPatchDir(lua_State* L)
{
    lua_pushstring(L, getPatchDir());
    return 1;
}

int lua_getDownloadDir(lua_State* L)
{
    lua_pushstring(L, getDownloadDir().c_str());
    return 1;
}

int lua_getAppVersion(lua_State* L)
{
    lua_pushstring(L, getAppVersion().c_str());
    return 1;
}

int lua_getAppCode(lua_State* L)
{
    lua_pushstring(L, getAppCode().c_str());
    return 1;
}

int lua_openURL(lua_State* L)
{
    const char* url = luaL_checkstring(L, 1);
    openURL(url);
    return 0;
}

int lua_isJailbroken(lua_State* L)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    extern bool isJailbroken();
    lua_pushboolean(L,  isJailbroken() ? 1 : 0);
#else
    lua_pushboolean(L, 0);
#endif

    return 1;
}

int lua_getLastUpdateErrorCode(lua_State* L)
{
    lua_pushinteger(L, getLastUpdateErrorCode());
    return 1;
}

int lua_getLastUpdateErrorInfo(lua_State* L)
{
    lua_pushstring(L, getLastUpdateErrorInfo());
    return 1;
}

int lua_getLastUpdateFileSize(lua_State* L)
{
    lua_pushinteger(L, getLastUpdateFileSize());
    return 1;
}

int lua_getLastUpdateFileUrl(lua_State* L)
{
    lua_pushstring(L, getLastUpdateFileUrl());
    return 1;
}

int lua_setHttpDNS(lua_State* L)
{
    const char* ips[16];
    int count = lua_gettop(L);
    if (count > 16)
        count = 16;

    for (int i = 0; i < count; i++)
    {
        ips[i] = luaL_checkstring(L, i + 1);
    }

    setHttpDNS(ips, count);

    return 0;
}

int lua_setHttpHost(lua_State* L)
{
    const char* host = luaL_checkstring(L, 1);
    const char* path = luaL_checkstring(L, 2);
    setHttpHost(host, path);
    return 0;
}

int lua_ServerList_connect(lua_State* L)
{
    std::vector<const char*> ips;
    unsigned short port = 0;

    int argc = lua_gettop(L);
    if (argc >= 2)
    {
        for (int i = 1; i < argc; i++)
            ips.push_back(luaL_checkstring(L, i));

        port = (unsigned short)luaL_checkinteger(L, argc);
    }

    g_serverList.connect(ips, port);
    return 0;
}

int lua_ServerList_disconnect(lua_State* L)
{
    g_serverList.disconnect();
    return 0;
}

int lua_ServerList_requestAllInfo(lua_State* L)
{
    const char* version = luaL_checkstring(L, 1);
    unsigned char areaId = (unsigned char)luaL_checkinteger(L, 2);

    g_serverList.requestAllInfo(version, areaId);
    return 0;
}

int lua_ServerList_sendLoginServer(lua_State* L)
{
    unsigned char areaId = (unsigned char)luaL_checkinteger(L, 1);
    unsigned short serverId = (unsigned short)luaL_checkinteger(L, 2);
    bool createUser = lua_toboolean(L, 3) ? true : false;

    g_serverList.sendLoginServer(areaId, serverId, createUser);
    return 0;
}

int lua_ServerList_getStatus(lua_State* L)
{
    lua_pushinteger(L, g_serverList.getStatus());
    return 1;
}

int lua_ServerList_isConnected(lua_State* L)
{
    lua_pushboolean(L, g_serverList.isConnected() ? 1 : 0);
    return 1;
}

int lua_ServerList_delayDisconnect(lua_State* L)
{
    float time = (float)luaL_checknumber(L, 1);
    g_serverList.delayDisconnect(time);
    return 0;
}

int lua_ServerList_setMaxConnectTime(lua_State* L)
{
    float time = (float)luaL_checknumber(L, 1);
    g_serverList.setMaxConnectTime(time);
    return 0;
}

int lua_ServerList_setMaxRecvTime(lua_State* L)
{
    float time = (float)luaL_checknumber(L, 1);
    g_serverList.setMaxRecvTime(time);
    return 0;
}

void lua_register_AutoUpdate(lua_State* L)
{
    lua_register(L, "getMemory", lua_getMemory);

    //update

    lua_register(L, "startGetServerInfo", lua_startGetServerInfo);
    lua_register(L, "getServerInfo", lua_getServerInfo);

    lua_register(L, "startGetFileList", lua_startGetFileList);
    lua_register(L, "startUpdate", lua_startUpdate);
    lua_register(L, "endUpdate", lua_endUpdate);
    lua_register(L, "getUpdateState", lua_getUpdateState);
    lua_register(L, "getUpdateCurrentSize", lua_getUpdateCurrentSize);
    lua_register(L, "getUpdateTotalSize", lua_getUpdateTotalSize);
    lua_register(L, "setUpdateStateChangeCB", lua_setUpdateStateChangeCB);
    lua_register(L, "setUpdateProgressCB", lua_setUpdateProgressCB);

    lua_register(L, "updateNeedRestartApp", lua_updateNeedRestart);
    lua_register(L, "updateNeedReinstallApp", lua_updateNeedReinstall);

    lua_register(L, "restartApp", lua_restartApp);
    lua_register(L, "installApp", lua_installApp);
    
    lua_register(L, "getHostName", lua_getHostName);

    lua_register(L, "getPatchDir", lua_getPatchDir);
    lua_register(L, "getDownloadDir", lua_getDownloadDir);

    lua_register(L, "getAppVersion", lua_getAppVersion);
    lua_register(L, "getAppCode", lua_getAppCode);
    lua_register(L, "openURL", lua_openURL);

    lua_register(L, "isJailbroken", lua_isJailbroken);

    lua_register(L, "getLastUpdateErrorCode", lua_getLastUpdateErrorCode);
    lua_register(L, "getLastUpdateErrorInfo", lua_getLastUpdateErrorInfo);
    lua_register(L, "getLastUpdateFileSize", lua_getLastUpdateFileSize);
    lua_register(L, "getLastUpdateFileUrl", lua_getLastUpdateFileUrl);

    lua_register(L, "setHttpDNS", lua_setHttpDNS);
    lua_register(L, "setHttpHost", lua_setHttpHost);

    const luaL_Reg serverListFunc[] = {
        { "connect",     lua_ServerList_connect },
        { "disconnect",      lua_ServerList_disconnect },
        { "requestAllInfo",  lua_ServerList_requestAllInfo },
        { "sendLoginServer",   lua_ServerList_sendLoginServer },
        { "getStatus",      lua_ServerList_getStatus },
        { "isConnected",      lua_ServerList_isConnected },
        { "delayDisconnect",    lua_ServerList_delayDisconnect },
        { "setMaxConnectTime",  lua_ServerList_setMaxConnectTime },
        { "setMaxRecvTime",    lua_ServerList_setMaxRecvTime },
        { NULL, NULL }
    };

    luaL_register(L, "ServerList", serverListFunc);
}
