#include "tersafe/tersafe.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"

int lua_tersafe_TersafeSDK_ListenerUploadData(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"TersafeSDK",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        double arg0;
        ok &= luaval_to_number(tolua_S, 2,&arg0, "TersafeSDK:ListenerUploadData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_tersafe_TersafeSDK_ListenerUploadData'", nullptr);
            return 0;
        }
        TersafeSDK::ListenerUploadData(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "TersafeSDK:ListenerUploadData",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_tersafe_TersafeSDK_ListenerUploadData'.",&tolua_err);
#endif
    return 0;
}
int lua_tersafe_TersafeSDK_onTersafeWeChatLogin(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"TersafeSDK",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 3)
    {
        const char* arg0;
        const char* arg1;
        int arg2;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "TersafeSDK:onTersafeWeChatLogin"); arg0 = arg0_tmp.c_str();
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "TersafeSDK:onTersafeWeChatLogin"); arg1 = arg1_tmp.c_str();
        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "TersafeSDK:onTersafeWeChatLogin");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_tersafe_TersafeSDK_onTersafeWeChatLogin'", nullptr);
            return 0;
        }
        TersafeSDK::onTersafeWeChatLogin(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "TersafeSDK:onTersafeWeChatLogin",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_tersafe_TersafeSDK_onTersafeWeChatLogin'.",&tolua_err);
#endif
    return 0;
}
int lua_tersafe_TersafeSDK_TersafeInitGame(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"TersafeSDK",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_tersafe_TersafeSDK_TersafeInitGame'", nullptr);
            return 0;
        }
        TersafeSDK::TersafeInitGame();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "TersafeSDK:TersafeInitGame",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_tersafe_TersafeSDK_TersafeInitGame'.",&tolua_err);
#endif
    return 0;
}

int lua_tersafe_TersafeSDK_send_sdk_data_to_svr_if_nessary(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"TersafeSDK",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_tersafe_TersafeSDK_send_sdk_data_to_svr_if_nessary'", nullptr);
            return 0;
        }
        TersafeSDK::send_sdk_data_to_svr_if_nessary();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "TersafeSDK:send_sdk_data_to_svr_if_nessary",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_tersafe_TersafeSDK_send_sdk_data_to_svr_if_nessary'.",&tolua_err);
#endif
    return 0;
}
int lua_tersafe_TersafeSDK_onTersafeQQLogin(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"TersafeSDK",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 3)
    {
        const char* arg0;
        const char* arg1;
        int arg2;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "TersafeSDK:onTersafeQQLogin"); arg0 = arg0_tmp.c_str();
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "TersafeSDK:onTersafeQQLogin"); arg1 = arg1_tmp.c_str();
        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "TersafeSDK:onTersafeQQLogin");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_tersafe_TersafeSDK_onTersafeQQLogin'", nullptr);
            return 0;
        }
        TersafeSDK::onTersafeQQLogin(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "TersafeSDK:onTersafeQQLogin",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_tersafe_TersafeSDK_onTersafeQQLogin'.",&tolua_err);
#endif
    return 0;
}
int lua_tersafe_TersafeSDK_on_recv_data_which_need_send_to_client_sdk(lua_State* tolua_S)
{
    int argc = 0;
	bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"TersafeSDK",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
		unsigned int arg1;
		ok &= luaval_to_uint32(tolua_S, 3,&arg1, "TersafeSDK:on_recv_data_which_need_send_to_client_sdk");
		size_t ld = (size_t)arg1;
		const char *arg0 = luaL_checklstring(tolua_S, 2, &ld);

        TersafeSDK::on_recv_data_which_need_send_to_client_sdk(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "TersafeSDK:on_recv_data_which_need_send_to_client_sdk",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_tersafe_TersafeSDK_on_recv_data_which_need_send_to_client_sdk'.",&tolua_err);
#endif
    return 0;
}
static int lua_tersafe_TersafeSDK_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (TersafeSDK)");
    return 0;
}

int lua_register_tersafe_TersafeSDK(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"TersafeSDK");
    tolua_cclass(tolua_S,"TersafeSDK","TersafeSDK","",nullptr);

    tolua_beginmodule(tolua_S,"TersafeSDK");
        tolua_function(tolua_S,"ListenerUploadData", lua_tersafe_TersafeSDK_ListenerUploadData);
        tolua_function(tolua_S,"onTersafeWeChatLogin", lua_tersafe_TersafeSDK_onTersafeWeChatLogin);
        tolua_function(tolua_S,"TersafeInitGame", lua_tersafe_TersafeSDK_TersafeInitGame);
        tolua_function(tolua_S,"send_sdk_data_to_svr_if_nessary", lua_tersafe_TersafeSDK_send_sdk_data_to_svr_if_nessary);
        tolua_function(tolua_S,"onTersafeQQLogin", lua_tersafe_TersafeSDK_onTersafeQQLogin);
        tolua_function(tolua_S,"on_recv_data_which_need_send_to_client_sdk", lua_tersafe_TersafeSDK_on_recv_data_which_need_send_to_client_sdk);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(TersafeSDK).name();
    g_luaType[typeName] = "TersafeSDK";
    g_typeCast["TersafeSDK"] = "TersafeSDK";
    return 1;
}

