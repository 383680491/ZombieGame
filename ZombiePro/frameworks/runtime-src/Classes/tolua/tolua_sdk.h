#pragma once

#include "sdk/sdk.h"
#include "common/utils.h"

static int lua_sdkAutoLogin(lua_State *L)
{
    sdkAutoLogin();
    return 0;
}

static int lua_sdkWXLogin(lua_State *L)
{
    sdkWXLogin();
    return 0;
}

static int lua_sdkQQLogin(lua_State *L)
{
    sdkQQLogin();
    return 0;
}

static int lua_sdkGuestLogin(lua_State *L)
{
    sdkGuestLogin();
    return 0;
}

static int lua_sdkLogout(lua_State *L)
{
    sdkLogout();
    return 0;
}

static int lua_sdkGetCurrentDay(lua_State *L)
{
	lua_pushinteger(L, sdkGetCurrentDay());
	return 1;
}

static int lua_sdkQueryMyInfo(lua_State *L)
{
	bool isMine = lua_toboolean(L, 1) ? true : false;
	const char* strValue = luaL_checkstring(L, 2);
    sdkQueryMyInfo(isMine, strValue);
    return 0;
}

static int lua_sdkQueryFriendsInfo(lua_State *L)
{
	bool isMine = lua_toboolean(L, 1) ? true : false;
	const char* strValue = luaL_checkstring(L, 2);
    sdkQueryFriendsInfo(isMine, strValue);
    return 0;
}

static int lua_sdkAddGameFriendToQQ(lua_State *L)
{
	const char* cFopenid = luaL_checkstring(L, 1);
	const char* cDesc = luaL_checkstring(L, 2);
	const char* cMessage = luaL_checkstring(L, 3);
	
	sdkAddGameFriendToQQ(cFopenid, cDesc, cMessage);
	return 0;
}

static int lua_sdkBindQQGroup(lua_State *L)
{
	const char* cUnionid = luaL_checkstring(L, 1);
	const char* cUnion_name = luaL_checkstring(L, 2);
	const char* cZoneid = luaL_checkstring(L, 3);
	const char* cSignature = luaL_checkstring(L, 4);

	sdkBindQQGroup(cUnionid, cUnion_name, cZoneid, cSignature);
	return 0;
}

static int lua_sdkUnbindQQGroup(lua_State *L)
{
	const char* cGroupOpenid = luaL_checkstring(L, 1);
	const char* cUnionid = luaL_checkstring(L, 2);

	sdkUnbindQQGroup(cGroupOpenid, cUnionid);
	return 0;
}


static int lua_sdkQueryQQGroupInfo(lua_State *L)
{
	const char* cUnionid = luaL_checkstring(L, 1);
	const char* cZoneid = luaL_checkstring(L, 2);

	sdkQueryQQGroupInfo(cUnionid, cZoneid);
	return 0;
}

static int lua_sdkQueryQQGroupKey(lua_State *L)
{
	const char* cGroupOpenid = luaL_checkstring(L, 1);

	sdkQueryQQGroupKey(cGroupOpenid);
	return 0;
}

static int lua_sdkJoinQQGroup(lua_State *L)
{
	const char* cQqGroupKey = luaL_checkstring(L, 1);

	sdkJoinQQGroup(cQqGroupKey);
	return 0;
}

static int lua_sdkCreateWXGroup(lua_State *L)
{
	const char* unionid = luaL_checkstring(L, 1);
	const char* chatRoomName = luaL_checkstring(L, 2);
	const char* chatRoomNickName = luaL_checkstring(L, 3);

	sdkCreateWXGroup(unionid, chatRoomName, chatRoomNickName);
	return 0;
}

static int lua_sdkJoinWXGroup(lua_State *L)
{
	const char* unionid = luaL_checkstring(L, 1);
	const char* chatRoomNickName = luaL_checkstring(L, 2);

	sdkJoinWXGroup(unionid, chatRoomNickName);
	return 0;
}

static int lua_sdkSendToWXGroup(lua_State *L)
{
	int msgType = luaL_checkinteger(L, 1);
	int subType = luaL_checkinteger(L, 2);
	const char* unionid = luaL_checkstring(L, 3);
	const char* title = luaL_checkstring(L, 4);
	const char* description = luaL_checkstring(L, 5);
	const char* messageExt = luaL_checkstring(L, 6);
	const char* mediaTagName = luaL_checkstring(L, 7);
	const char* imgUrl = luaL_checkstring(L, 8);
	const char* msdkExtInfo = luaL_checkstring(L, 9);

	sdkSendToWXGroup(msgType, subType, unionid, title, description, messageExt, mediaTagName, imgUrl, msdkExtInfo);
	return 0;
}

static int lua_sdkQueryWXGroupInfo(lua_State *L)
{
	const char* unionid = luaL_checkstring(L, 1);
	const char* openIdList = luaL_checkstring(L, 2);

	sdkQueryWXGroupInfo(unionid, openIdList);
	return 0;
}

static int lua_isWXInstalled(lua_State *L)
{
    lua_pushboolean(L, isWXInstalled() ? 1 : 0);
    return 1;
}

static int lua_isQQInstalled(lua_State *L)
{
    lua_pushboolean(L, isQQInstalled() ? 1 : 0);
    return 1;
}

static int lua_setNativeCallback(lua_State *L)
{
    int callback = toluafix_ref_function(L, 1, 0);
    setNativeCallback(callback);
    return 0;
}

static int lua_sdkShowNotice(lua_State *L)
{
    const char* scene = luaL_checkstring(L, 1);
    sdkShowNotice(scene);

    return 0;
}

static int lua_sdkGetNoticeContent(lua_State *L)
{
    const char* scene = luaL_checkstring(L, 1);
    std::string content = sdkGetNoticeContent(scene);
    lua_pushlstring(L, content.c_str(), content.size());
    return 1;
}

static int lua_sdkGetNoticeTitle(lua_State *L)
{
    const char* scene = luaL_checkstring(L, 1);
    std::string title = sdkGetNoticeContent(scene);
    lua_pushlstring(L, title.c_str(), title.size());
    return 1;
}

static int lua_sdkOpenUrl(lua_State *L)
{
    const char* url = luaL_checkstring(L, 1);
    int screenDir = luaL_optint(L, 2, 2);
    sdkOpenUrl(url, screenDir);

    return 1;
}

static int lua_buglyLog(lua_State *L)
{
    const char* str = luaL_checkstring(L, 1);
    buglyLog(str);

    return 0;
}

static int lua_sdkGetPlatform(lua_State *L)
{
    lua_pushinteger(L, sdkGetPlatform());
    return 1;
}

static int lua_sdkGetArea(lua_State *L)
{
    lua_pushinteger(L, sdkGetArea());
    return 1;
}

static int lua_sdkGetOpenId(lua_State *L)
{
    std::string str = sdkGetOpenId();
    lua_pushlstring(L, str.c_str(), str.size());
    return 1;
}

static int lua_sdkGetPayToken(lua_State *L)
{
    std::string str = sdkGetPayToken();
    lua_pushlstring(L, str.c_str(), str.size());
    return 1;
}

static int lua_sdkGetSessionId(lua_State *L)
{
    const char* str = sdkGetSessionId();
    lua_pushstring(L, str);
    return 1;
}

static int lua_sdkGetSessionType(lua_State *L)
{
    const char* str = sdkGetSessionType();
    lua_pushstring(L, str);
    return 1;
}

static int lua_sdkGetPf(lua_State *L)
{
    std::string str = sdkGetPf();
    lua_pushlstring(L, str.c_str(), str.size());
    return 1;
}

static int lua_sdkGetPfKey(lua_State *L)
{
    std::string str = sdkGetPfKey();
    lua_pushlstring(L, str.c_str(), str.size());
    return 1;
}

static int lua_sdkPayInit(lua_State *L)
{
    sdkPayInit();
    return 0;
}

static int lua_sdkShareQQ(lua_State *L)
{
	int qSession = luaL_checkinteger(L, 1);
	const char* title = luaL_checkstring(L, 2);
	const char* desc = luaL_checkstring(L, 3);
	const char* url = luaL_checkstring(L, 4);
	const char* imgUrl = luaL_checkstring(L, 5);
	int imgUrlLen = luaL_checkinteger(L, 6);
    
    sdkShareQQ(qSession, title, desc, url, imgUrl, imgUrlLen);

	return 0;
}

static int lua_sdkShareQQwithPhoto(lua_State *L)
{
	int qSession = luaL_checkinteger(L, 1);
	const char* imgData = luaL_checkstring(L, 2);
    int imgDataLength = luaL_checkinteger(L, 3);
    sdkShareQQwithPhoto(qSession, imgData, imgDataLength);

	return 0;
}


static int lua_sdkShareQQwithFriend(lua_State *L)
{
	int act = luaL_checkinteger(L, 1);
	const char* friendOpenId = luaL_checkstring(L, 2);
	const char* title = luaL_checkstring(L, 3);
	const char* summary = luaL_checkstring(L, 4);
	const char* targetUrl = luaL_checkstring(L, 5);
	const char* imageUrl = luaL_checkstring(L, 6);
	const char* previewText = luaL_checkstring(L, 7);
	const char* gameTag = luaL_checkstring(L, 8);

	sdkShareQQwithFriend(act, friendOpenId, title, summary, targetUrl, imageUrl, previewText, gameTag);

	return 0;
}
static int lua_sdkShareWeixin(lua_State *L)
{
	const char* title = luaL_checkstring(L, 1);
	const char* desc = luaL_checkstring(L, 2);
	const char* mediaTagName = luaL_checkstring(L, 3);
	const char* thumbImgData = luaL_checkstring(L, 4);
	int thumbImgDataLen = luaL_checkinteger(L, 5);
	const char* messageExt = luaL_checkstring(L, 6);
	
    sdkShareWeixin(title, desc, mediaTagName, thumbImgData, thumbImgDataLen, messageExt);

	return 0;
}
static int lua_sdkShareWeixinwithPhoto(lua_State *L)
{
	int session = luaL_checkinteger(L, 1);
	const char* mediaTagName = luaL_checkstring(L, 2);
	const char* thumbImgData = luaL_checkstring(L, 3);
	int thumbImgDataLen = luaL_checkinteger(L, 4);
	const char* messageExt = luaL_checkstring(L, 5);
	const char* messageAction = luaL_checkstring(L, 6);

	sdkShareWeixinwithPhoto(session, mediaTagName, thumbImgData, thumbImgDataLen, messageExt, messageAction);

	return 0;
}
static int lua_sdkShareWeixinwithFriend(lua_State *L) 
{
	const char* friendOpenId = luaL_checkstring(L, 1);
	const char* title = luaL_checkstring(L, 2);
	const char* description = luaL_checkstring(L, 3);
	const char* mediaId = luaL_checkstring(L, 4);
	const char* messageExt = luaL_checkstring(L, 5);
	const char* mediaTagName = luaL_checkstring(L, 6);
	const char* msdkExtInfo = luaL_checkstring(L, 7);

	sdkShareWeixinwithFriend(friendOpenId, title, description, mediaId, messageExt, mediaTagName, msdkExtInfo);

	return 0;
} 

static int lua_sdkGetNearByPersonInfo(lua_State *L)
{
	sdkGetNearByPersonInfo();
	return 0;
}

static int lua_sdkCleanLocation(lua_State *L)
{
	sdkCleanLocation();
	return 0;
}

static int lua_sdkGetLocationInfo(lua_State *L)
{
	sdkGetLocationInfo();
	return 0;
}

static int lua_sdkFeedBack(lua_State *L)
{
	const char* ugame = luaL_checkstring(L, 1);
	const char* ubody = luaL_checkstring(L, 2);
	sdkFeedBack(ugame, ubody);
	return 0;
}

static int lua_sdkFeedBackSingleBody(lua_State *L)
{
	const char* ubody = luaL_checkstring(L, 1);
	sdkFeedBackSingleBody(ubody);
	return 0;
}

static int lua_sdkEnablePayLog(lua_State *L)
{
    bool enable = lua_toboolean(L, 1) ? true : false;
    sdkEnablePayLog(enable);
    return 0;
}

static int lua_sdkSetPayEnv(lua_State *L)
{
    const char* env = luaL_checkstring(L, 1);
    sdkSetPayEnv(env);
    return 0;
}

static int lua_sdkRegisterPay(lua_State *L)
{
    const char* extend = luaL_checkstring(L, 1);
    sdkRegisterPay(extend);

    return 0;
}

static int lua_sdkPay(lua_State *L)
{
    const char* productId = luaL_checkstring(L, 1);
    int count = luaL_checkinteger(L, 2);
    bool deposit = lua_toboolean(L, 3) ? true : false;
    const char* zoneId = luaL_checkstring(L, 4);
    const char* extend = luaL_optstring(L, 5, "");

    sdkPay(productId, count, deposit, zoneId, extend);
    return 0;
}

static int lua_sdkBuyGoods(lua_State* L)
{
    const char* zoneId = luaL_checkstring(L, 1);
    const char* offerId = luaL_checkstring(L, 2);
    const char* goodsTokenUrl = luaL_checkstring(L, 3);
    sdkBuyGoods(zoneId, offerId, goodsTokenUrl);

    return 0;
}


static int lua_sdkQQVipPay(lua_State *L)
{
    const char* serviceCode = luaL_checkstring(L, 1);
    const char* serviceName = luaL_checkstring(L, 2);
    int serviceType = luaL_checkinteger(L, 3);
    const char* zoneId = luaL_checkstring(L, 4);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    sdkQQVipPay(serviceCode, serviceName, serviceType, zoneId);
#endif

    return 0;
}

static int lua_sdkMidasNet(lua_State *L)
{
    const char* zoneId = luaL_checkstring(L, 1);
    sdkMidasNet(zoneId);

    return 0;
}

static int lua_sdkStartSaveUpdate(lua_State *L)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    bool useYYB = lua_toboolean(L, 1) ? true : false;
    sdkStartSaveUpdate(useYYB);
#endif

    return 0;
}

static int lua_sdkCheckNeedUpdate(lua_State *L)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    sdkCheckNeedUpdate();
#endif

    return 0;
}

int lua_sdkCheckYYBInstalled(lua_State *L)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    lua_pushinteger(L, sdkCheckYYBInstalled());
#else
    lua_pushinteger(L, 0);
#endif

    return 1;
}

int lua_httpDNSResolve(lua_State* L)
{
    const char* domain = luaL_checkstring(L, 1);
    httpDNSResolve(domain);

    return 0;
}

static const char* tostring(lua_State *L, int narg)
{
    switch (lua_type(L, narg))
    {
        case LUA_TNUMBER:
        case LUA_TSTRING:
            return lua_tostring(L, narg);

        case LUA_TBOOLEAN:
            return lua_toboolean(L, narg) ? "1" : "0";
    } 

    return "";
}

int lua_sdkReportEvent(lua_State *L)
{
    const char* name = luaL_checkstring(L, 1);
    bool isRealTime = lua_toboolean(L, 2) ? true : false;

    std::vector<std::string> kvs;
    int count = lua_gettop(L);
    for (int i = 3; i + 1 <= count; i += 2)
    {
        const char* key = tostring(L, i);
        const char* value = tostring(L, i + 1);
        if (key && *key && value)
        {
            kvs.push_back(key);
            kvs.push_back(value);
        }
    }

    sdkReportEvent(name, isRealTime, kvs);
    return 0;
}

static int lua_getOSVersion(lua_State *L)
{
    lua_pushstring(L, getOSVersion().c_str());
    return 1;
}

static int lua_getDeviceType(lua_State *L)
{
    lua_pushstring(L, getDeviceType());
    return 1;
}

static int lua_getNetworkType(lua_State *L)
{
    lua_pushstring(L, getNetworkType());
    return 1;
}

static int lua_getTelephonyProviderType(lua_State *L)
{
    lua_pushstring(L, getTelephonyProviderType());
    return 1;
}


static int lua_getLoginChannel(lua_State *L)
{
    lua_pushnumber(L, getLoginChannel());
    return 1;
}

static int lua_getCPUType(lua_State *L)
{
    lua_pushstring(L, getCPUType());
    return 1;
}

static int lua_getRamSize(lua_State *L)
{
    lua_pushnumber(L, getRamSize());
    return 1;
}

static int lua_hexEncode(lua_State *L)
{
    size_t len = 0;
    const char* ptr = luaL_checklstring(L, 1, &len);
    if (ptr && len < 4096)
    {
        char str[4096 * 2 + 1];
        hexEncode(ptr, len, str);
        lua_pushlstring(L, str, len * 2);
        return 1;
    }
    
    return 0;
}

static int lua_hexDecode(lua_State *L)
{
    size_t len = 0;
    const char* ptr = luaL_checklstring(L, 1, &len);
    if (ptr && len < 8192)
    {
        char str[8192 / 2 + 1];
        hexDecode(ptr, len, str);
        lua_pushlstring(L, str, len / 2);
        return 1;
    }
    
    return 0;
}

static int lua_sdkdecodeFile(lua_State *L)
{
	const char* filename = luaL_checkstring(L, 1);
	const char* sign = luaL_checkstring(L, 2);
	const char* key = luaL_checkstring(L, 3);
	auto engine = LuaEngine::getInstance();
	LuaStack *pStack = engine->getLuaStack();
	pStack->decodeScriptFile(filename,sign,key); 
	return 0;
}

static int lua_setCrashLog(lua_State *L)
{
    const char* key = luaL_checkstring(L, 1);
	const char* value = luaL_checkstring(L, 2);
    setCrashLog(key, value);
    return 0;
}

static int lua_getMd5HexStr(lua_State *L)
{
	size_t len = 0;
	char result[33];
	const char* dataSrc = luaL_checklstring(L, 1, &len);
	getMd5HexStr(dataSrc, len, result);
	//lua_pushlstring(L, result, len);
	lua_pushstring(L, result);
	return 1;
}

void lua_register_sdk(lua_State* L)
{
	lua_register(L, "decodeXXTeaFile", lua_sdkdecodeFile);
    lua_register(L, "sdkAutoLogin", lua_sdkAutoLogin);
    lua_register(L, "sdkWXLogin", lua_sdkWXLogin);
    lua_register(L, "sdkQQLogin", lua_sdkQQLogin);
    lua_register(L, "sdkGuestLogin", lua_sdkGuestLogin);
    lua_register(L, "sdkLogout", lua_sdkLogout);
    lua_register(L, "isWXInstalled", lua_isWXInstalled);
    lua_register(L, "isQQInstalled", lua_isQQInstalled);
    lua_register(L, "setNativeCallback", lua_setNativeCallback);

	//拉取个人和好友信息
	lua_register(L, "sdkGetCurrentDay", lua_sdkGetCurrentDay);
	lua_register(L, "sdkQueryMyInfo", lua_sdkQueryMyInfo);
	lua_register(L, "sdkQueryFriendsInfo", lua_sdkQueryFriendsInfo);
	//QQ结构化分享和大图分享
	lua_register(L, "sdkShareQQ", lua_sdkShareQQ);
	lua_register(L, "sdkShareQQwithPhoto", lua_sdkShareQQwithPhoto);
	//仅QQ安卓的后端分享
	lua_register(L, "sdkShareQQwithFriend", lua_sdkShareQQwithFriend);
	//微信结构化分享和大图分享
	lua_register(L, "sdkShareWeixin", lua_sdkShareWeixin);
	lua_register(L, "sdkShareWeixinwithPhoto", lua_sdkShareWeixinwithPhoto);
	lua_register(L, "sdkShareWeixinwithFriend", lua_sdkShareWeixinwithFriend);

	lua_register(L, "sdkQueryQQGroupInfo", lua_sdkQueryQQGroupInfo);
	lua_register(L, "sdkQueryQQGroupKey", lua_sdkQueryQQGroupKey);
	lua_register(L, "sdkJoinQQGroup", lua_sdkJoinQQGroup);
	lua_register(L, "sdkUnbindQQGroup", lua_sdkUnbindQQGroup);
	lua_register(L, "sdkBindQQGroup", lua_sdkBindQQGroup);
	lua_register(L, "sdkAddGameFriendToQQ", lua_sdkAddGameFriendToQQ);

	lua_register(L, "sdkCreateWXGroup", lua_sdkCreateWXGroup);
	lua_register(L, "sdkJoinWXGroup", lua_sdkJoinWXGroup);
	lua_register(L, "sdkSendToWXGroup", lua_sdkSendToWXGroup);
	lua_register(L, "sdkQueryWXGroupInfo", lua_sdkQueryWXGroupInfo);

	lua_register(L, "sdkGetNearByPersonInfo", lua_sdkGetNearByPersonInfo);
	lua_register(L, "sdkCleanLocation", lua_sdkCleanLocation);
	lua_register(L, "sdkGetLocationInfo", lua_sdkGetLocationInfo);
	lua_register(L, "sdkFeedBack", lua_sdkFeedBack);
	lua_register(L, "sdkFeedBackSingleBody", lua_sdkFeedBackSingleBody);

    lua_register(L, "sdkShowNotice", lua_sdkShowNotice);
    lua_register(L, "sdkGetNoticeContent", lua_sdkGetNoticeContent);
    lua_register(L, "sdkGetNoticeTitle", lua_sdkGetNoticeTitle);

    lua_register(L, "sdkGetPlatform", lua_sdkGetPlatform);
    lua_register(L, "sdkGetArea", lua_sdkGetArea);
    lua_register(L, "sdkGetOpenId", lua_sdkGetOpenId);
    lua_register(L, "sdkGetPayToken", lua_sdkGetPayToken);
    lua_register(L, "sdkGetSessionId", lua_sdkGetSessionId);
    lua_register(L, "sdkGetSessionType", lua_sdkGetSessionType);
    
    lua_register(L, "sdkGetPf", lua_sdkGetPf);
    lua_register(L, "sdkGetPfKey", lua_sdkGetPfKey);

    lua_register(L, "sdkPayInit", lua_sdkPayInit);
    lua_register(L, "sdkEnablePayLog", lua_sdkEnablePayLog);
    lua_register(L, "sdkSetPayEnv", lua_sdkSetPayEnv);
    lua_register(L, "sdkRegisterPay", lua_sdkRegisterPay);
    lua_register(L, "sdkPay", lua_sdkPay);
    lua_register(L, "sdkBuyGoods", lua_sdkBuyGoods);
    lua_register(L, "sdkQQVipPay", lua_sdkQQVipPay);
    lua_register(L, "sdkMidasNet", lua_sdkMidasNet);

    lua_register(L, "sdkStartSaveUpdate", lua_sdkStartSaveUpdate);
    lua_register(L, "sdkCheckNeedUpdate", lua_sdkCheckNeedUpdate);
    lua_register(L, "sdkCheckYYBInstalled", lua_sdkCheckYYBInstalled);
    lua_register(L, "httpDNSResolve", lua_httpDNSResolve);

    lua_register(L, "sdkOpenUrl", lua_sdkOpenUrl);
    lua_register(L, "buglyLog", lua_buglyLog);
    lua_register(L, "sdkReportEvent", lua_sdkReportEvent);

    lua_register(L, "getOSVersion", lua_getOSVersion);
    lua_register(L, "getDeviceType", lua_getDeviceType);
    lua_register(L, "getNetworkType", lua_getNetworkType);
    lua_register(L, "getTelephonyProviderType", lua_getTelephonyProviderType);
    lua_register(L, "getLoginChannel", lua_getLoginChannel);
    lua_register(L, "getCPUType", lua_getCPUType);
    lua_register(L, "getRamSize", lua_getRamSize);
    
    lua_register(L, "hexEncode", lua_hexEncode);
    lua_register(L, "hexDecode", lua_hexDecode);
	lua_register(L, "setCrashLog", lua_setCrashLog);
	lua_register(L, "getMd5HexStr", lua_getMd5HexStr);
}


