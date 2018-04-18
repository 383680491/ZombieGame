#include "ApolloVoice/VoiceApollo.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"

int lua_VoiceApollo_VoiceApollo_StopPlayFile(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"VoiceApollo",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_VoiceApollo_VoiceApollo_StopPlayFile'", nullptr);
            return 0;
        }
        VoiceApollo::StopPlayFile();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "VoiceApollo:StopPlayFile",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_VoiceApollo_VoiceApollo_StopPlayFile'.",&tolua_err);
#endif
    return 0;
}
int lua_VoiceApollo_VoiceApollo_ResumeBGMPlay(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"VoiceApollo",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_VoiceApollo_VoiceApollo_ResumeBGMPlay'", nullptr);
            return 0;
        }
        VoiceApollo::ResumeBGMPlay();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "VoiceApollo:ResumeBGMPlay",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_VoiceApollo_VoiceApollo_ResumeBGMPlay'.",&tolua_err);
#endif
    return 0;
}
int lua_VoiceApollo_VoiceApollo_SetSpeakerVolume(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"VoiceApollo",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "VoiceApollo:SetSpeakerVolume");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_VoiceApollo_VoiceApollo_SetSpeakerVolume'", nullptr);
            return 0;
        }
        VoiceApollo::SetSpeakerVolume(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "VoiceApollo:SetSpeakerVolume",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_VoiceApollo_VoiceApollo_SetSpeakerVolume'.",&tolua_err);
#endif
    return 0;
}
int lua_VoiceApollo_VoiceApollo_GetMicLevel(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"VoiceApollo",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_VoiceApollo_VoiceApollo_GetMicLevel'", nullptr);
            return 0;
        }
        int ret = VoiceApollo::GetMicLevel();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "VoiceApollo:GetMicLevel",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_VoiceApollo_VoiceApollo_GetMicLevel'.",&tolua_err);
#endif
    return 0;
}
int lua_VoiceApollo_VoiceApollo_SetPlayDoneCallback(lua_State* tolua_S)
{
    int argc = 0;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"VoiceApollo",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        int arg0 = toluafix_ref_function(tolua_S,2,0);
        VoiceApollo::SetPlayDoneCallback(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "VoiceApollo:SetPlayDoneCallback",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_VoiceApollo_VoiceApollo_SetPlayDoneCallback'.",&tolua_err);
#endif
    return 0;
}
int lua_VoiceApollo_VoiceApollo_GetDownload_UploadState(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"VoiceApollo",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "VoiceApollo:GetDownload_UploadState");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_VoiceApollo_VoiceApollo_GetDownload_UploadState'", nullptr);
            return 0;
        }
        bool ret = VoiceApollo::GetDownload_UploadState(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "VoiceApollo:GetDownload_UploadState",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_VoiceApollo_VoiceApollo_GetDownload_UploadState'.",&tolua_err);
#endif
    return 0;
}
int lua_VoiceApollo_VoiceApollo_PauseBGMPlay(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"VoiceApollo",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_VoiceApollo_VoiceApollo_PauseBGMPlay'", nullptr);
            return 0;
        }
        VoiceApollo::PauseBGMPlay();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "VoiceApollo:PauseBGMPlay",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_VoiceApollo_VoiceApollo_PauseBGMPlay'.",&tolua_err);
#endif
    return 0;
}
int lua_VoiceApollo_VoiceApollo_GameReconnected(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"VoiceApollo",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_VoiceApollo_VoiceApollo_GameReconnected'", nullptr);
            return 0;
        }
        VoiceApollo::GameReconnected();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "VoiceApollo:GameReconnected",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_VoiceApollo_VoiceApollo_GameReconnected'.",&tolua_err);
#endif
    return 0;
}
int lua_VoiceApollo_VoiceApollo_SetJoinRoomDoneCallback(lua_State* tolua_S)
{
    int argc = 0;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"VoiceApollo",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        int arg0 = toluafix_ref_function(tolua_S, 2, 0);
        VoiceApollo::SetJoinRoomDoneCallback(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "VoiceApollo:SetJoinRoomDoneCallback",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_VoiceApollo_VoiceApollo_SetJoinRoomDoneCallback'.",&tolua_err);
#endif
    return 0;
}
int lua_VoiceApollo_VoiceApollo_ListenerActionDone(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"VoiceApollo",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_VoiceApollo_VoiceApollo_ListenerActionDone'", nullptr);
            return 0;
        }
        VoiceApollo::ListenerActionDone();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "VoiceApollo:ListenerActionDone",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_VoiceApollo_VoiceApollo_ListenerActionDone'.",&tolua_err);
#endif
    return 0;
}
int lua_VoiceApollo_VoiceApollo_onExitRoom(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"VoiceApollo",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_VoiceApollo_VoiceApollo_onExitRoom'", nullptr);
            return 0;
        }
        VoiceApollo::onExitRoom();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "VoiceApollo:onExitRoom",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_VoiceApollo_VoiceApollo_onExitRoom'.",&tolua_err);
#endif
    return 0;
}
int lua_VoiceApollo_VoiceApollo_GetFileID(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"VoiceApollo",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_VoiceApollo_VoiceApollo_GetFileID'", nullptr);
            return 0;
        }
        const char* ret = VoiceApollo::GetFileID();
        tolua_pushstring(tolua_S,(const char*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "VoiceApollo:GetFileID",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_VoiceApollo_VoiceApollo_GetFileID'.",&tolua_err);
#endif
    return 0;
}
int lua_VoiceApollo_VoiceApollo_OpenMic(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"VoiceApollo",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_VoiceApollo_VoiceApollo_OpenMic'", nullptr);
            return 0;
        }
        VoiceApollo::OpenMic();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "VoiceApollo:OpenMic",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_VoiceApollo_VoiceApollo_OpenMic'.",&tolua_err);
#endif
    return 0;
}
int lua_VoiceApollo_VoiceApollo_GetSpeakerLevel(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"VoiceApollo",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_VoiceApollo_VoiceApollo_GetSpeakerLevel'", nullptr);
            return 0;
        }
        int ret = VoiceApollo::GetSpeakerLevel();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "VoiceApollo:GetSpeakerLevel",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_VoiceApollo_VoiceApollo_GetSpeakerLevel'.",&tolua_err);
#endif
    return 0;
}
int lua_VoiceApollo_VoiceApollo_OpenSpeaker(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"VoiceApollo",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_VoiceApollo_VoiceApollo_OpenSpeaker'", nullptr);
            return 0;
        }
        VoiceApollo::OpenSpeaker();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "VoiceApollo:OpenSpeaker",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_VoiceApollo_VoiceApollo_OpenSpeaker'.",&tolua_err);
#endif
    return 0;
}
int lua_VoiceApollo_VoiceApollo_SetBGMPath(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"VoiceApollo",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "VoiceApollo:SetBGMPath"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_VoiceApollo_VoiceApollo_SetBGMPath'", nullptr);
            return 0;
        }
        VoiceApollo::SetBGMPath(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "VoiceApollo:SetBGMPath",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_VoiceApollo_VoiceApollo_SetBGMPath'.",&tolua_err);
#endif
    return 0;
}
int lua_VoiceApollo_VoiceApollo_SetMicVolume(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"VoiceApollo",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "VoiceApollo:SetMicVolume");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_VoiceApollo_VoiceApollo_SetMicVolume'", nullptr);
            return 0;
        }
        VoiceApollo::SetMicVolume(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "VoiceApollo:SetMicVolume",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_VoiceApollo_VoiceApollo_SetMicVolume'.",&tolua_err);
#endif
    return 0;
}
int lua_VoiceApollo_VoiceApollo_ApolloVoiceInit(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"VoiceApollo",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_VoiceApollo_VoiceApollo_ApolloVoiceInit'", nullptr);
            return 0;
        }
        VoiceApollo::ApolloVoiceInit();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "VoiceApollo:ApolloVoiceInit",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_VoiceApollo_VoiceApollo_ApolloVoiceInit'.",&tolua_err);
#endif
    return 0;
}

int lua_VoiceApollo_VoiceApollo_onGetAuthKey(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"VoiceApollo",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 7)
    {
        const char* arg0;
        const char* arg1;
        const char* arg2;
        const char* arg3;
        int arg4;
        const char* arg5;
        int arg6;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "VoiceApollo:onGetAuthKey"); arg0 = arg0_tmp.c_str();
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "VoiceApollo:onGetAuthKey"); arg1 = arg1_tmp.c_str();
        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp, "VoiceApollo:onGetAuthKey"); arg2 = arg2_tmp.c_str();
        std::string arg3_tmp; ok &= luaval_to_std_string(tolua_S, 5, &arg3_tmp, "VoiceApollo:onGetAuthKey"); arg3 = arg3_tmp.c_str();
        ok &= luaval_to_int32(tolua_S, 6,(int *)&arg4, "VoiceApollo:onGetAuthKey");
        std::string arg5_tmp; ok &= luaval_to_std_string(tolua_S, 7, &arg5_tmp, "VoiceApollo:onGetAuthKey"); arg5 = arg5_tmp.c_str();
        ok &= luaval_to_int32(tolua_S, 8,(int *)&arg6, "VoiceApollo:onGetAuthKey");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_VoiceApollo_VoiceApollo_onGetAuthKey'", nullptr);
            return 0;
        }
        VoiceApollo::onGetAuthKey(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "VoiceApollo:onGetAuthKey",argc, 7);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_VoiceApollo_VoiceApollo_onGetAuthKey'.",&tolua_err);
#endif
    return 0;
}
int lua_VoiceApollo_VoiceApollo_SetUploadDoneCallback(lua_State* tolua_S)
{
    int argc = 0;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"VoiceApollo",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        int arg0 = toluafix_ref_function(tolua_S, 2, 0);
        VoiceApollo::SetUploadDoneCallback(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "VoiceApollo:SetUploadDoneCallback",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_VoiceApollo_VoiceApollo_SetUploadDoneCallback'.",&tolua_err);
#endif
    return 0;
}
int lua_VoiceApollo_VoiceApollo_onJoinRoom(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"VoiceApollo",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 7)
    {
        const char* arg0;
        const char* arg1;
        const char* arg2;
        int arg3;
        int arg4;
        int arg5;
        int arg6;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "VoiceApollo:onJoinRoom"); arg0 = arg0_tmp.c_str();
        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "VoiceApollo:onJoinRoom"); arg1 = arg1_tmp.c_str();
        std::string arg2_tmp; ok &= luaval_to_std_string(tolua_S, 4, &arg2_tmp, "VoiceApollo:onJoinRoom"); arg2 = arg2_tmp.c_str();
        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "VoiceApollo:onJoinRoom");
        ok &= luaval_to_int32(tolua_S, 6,(int *)&arg4, "VoiceApollo:onJoinRoom");
        ok &= luaval_to_int32(tolua_S, 7,(int *)&arg5, "VoiceApollo:onJoinRoom");
        ok &= luaval_to_int32(tolua_S, 8,(int *)&arg6, "VoiceApollo:onJoinRoom");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_VoiceApollo_VoiceApollo_onJoinRoom'", nullptr);
            return 0;
        }
        VoiceApollo::onJoinRoom(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "VoiceApollo:onJoinRoom",argc, 7);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_VoiceApollo_VoiceApollo_onJoinRoom'.",&tolua_err);
#endif
    return 0;
}
int lua_VoiceApollo_VoiceApollo_StopBGMPlay(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"VoiceApollo",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_VoiceApollo_VoiceApollo_StopBGMPlay'", nullptr);
            return 0;
        }
        VoiceApollo::StopBGMPlay();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "VoiceApollo:StopBGMPlay",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_VoiceApollo_VoiceApollo_StopBGMPlay'.",&tolua_err);
#endif
    return 0;
}
int lua_VoiceApollo_VoiceApollo_StartBGMPlay(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"VoiceApollo",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_VoiceApollo_VoiceApollo_StartBGMPlay'", nullptr);
            return 0;
        }
        VoiceApollo::StartBGMPlay();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "VoiceApollo:StartBGMPlay",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_VoiceApollo_VoiceApollo_StartBGMPlay'.",&tolua_err);
#endif
    return 0;
}
int lua_VoiceApollo_VoiceApollo_StopRecord(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"VoiceApollo",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_VoiceApollo_VoiceApollo_StopRecord'", nullptr);
            return 0;
        }
        VoiceApollo::StopRecord();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "VoiceApollo:StopRecord",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_VoiceApollo_VoiceApollo_StopRecord'.",&tolua_err);
#endif
    return 0;
}
int lua_VoiceApollo_VoiceApollo_CloseSpeaker(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"VoiceApollo",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_VoiceApollo_VoiceApollo_CloseSpeaker'", nullptr);
            return 0;
        }
        VoiceApollo::CloseSpeaker();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "VoiceApollo:CloseSpeaker",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_VoiceApollo_VoiceApollo_CloseSpeaker'.",&tolua_err);
#endif
    return 0;
}
int lua_VoiceApollo_VoiceApollo_CloseMic(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"VoiceApollo",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_VoiceApollo_VoiceApollo_CloseMic'", nullptr);
            return 0;
        }
        VoiceApollo::CloseMic();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "VoiceApollo:CloseMic",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_VoiceApollo_VoiceApollo_CloseMic'.",&tolua_err);
#endif
    return 0;
}
int lua_VoiceApollo_VoiceApollo_EnableNativeBGMPlay(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"VoiceApollo",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "VoiceApollo:EnableNativeBGMPlay");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_VoiceApollo_VoiceApollo_EnableNativeBGMPlay'", nullptr);
            return 0;
        }
        VoiceApollo::EnableNativeBGMPlay(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "VoiceApollo:EnableNativeBGMPlay",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_VoiceApollo_VoiceApollo_EnableNativeBGMPlay'.",&tolua_err);
#endif
    return 0;
}
int lua_VoiceApollo_VoiceApollo_PlayFile(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"VoiceApollo",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        const char* arg0;
        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "VoiceApollo:PlayFile"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_VoiceApollo_VoiceApollo_PlayFile'", nullptr);
            return 0;
        }
        VoiceApollo::PlayFile(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "VoiceApollo:PlayFile",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_VoiceApollo_VoiceApollo_PlayFile'.",&tolua_err);
#endif
    return 0;
}

int lua_VoiceApollo_VoiceApollo_SetMode(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"VoiceApollo",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "VoiceApollo:SetMode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_VoiceApollo_VoiceApollo_SetMode'", nullptr);
            return 0;
        }
        VoiceApollo::SetMode(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "VoiceApollo:SetMode",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_VoiceApollo_VoiceApollo_SetMode'.",&tolua_err);
#endif
    return 0;
}
int lua_VoiceApollo_VoiceApollo_StartRecord(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"VoiceApollo",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_VoiceApollo_VoiceApollo_StartRecord'", nullptr);
            return 0;
        }
        VoiceApollo::StartRecord();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "VoiceApollo:StartRecord",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_VoiceApollo_VoiceApollo_StartRecord'.",&tolua_err);
#endif
    return 0;
}
static int lua_VoiceApollo_VoiceApollo_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (VoiceApollo)");
    return 0;
}

int lua_register_VoiceApollo_VoiceApollo(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"VoiceApollo");
    tolua_cclass(tolua_S,"VoiceApollo","VoiceApollo","",nullptr);

    tolua_beginmodule(tolua_S,"VoiceApollo");
        tolua_function(tolua_S,"StopPlayFile", lua_VoiceApollo_VoiceApollo_StopPlayFile);
        tolua_function(tolua_S,"ResumeBGMPlay", lua_VoiceApollo_VoiceApollo_ResumeBGMPlay);
        tolua_function(tolua_S,"SetSpeakerVolume", lua_VoiceApollo_VoiceApollo_SetSpeakerVolume);
        tolua_function(tolua_S,"GetMicLevel", lua_VoiceApollo_VoiceApollo_GetMicLevel);
        tolua_function(tolua_S,"SetPlayDoneCallback", lua_VoiceApollo_VoiceApollo_SetPlayDoneCallback);
        tolua_function(tolua_S,"GetDownload_UploadState", lua_VoiceApollo_VoiceApollo_GetDownload_UploadState);
        tolua_function(tolua_S,"PauseBGMPlay", lua_VoiceApollo_VoiceApollo_PauseBGMPlay);
        tolua_function(tolua_S,"GameReconnected", lua_VoiceApollo_VoiceApollo_GameReconnected);
        tolua_function(tolua_S,"onExitRoom", lua_VoiceApollo_VoiceApollo_onExitRoom);
        tolua_function(tolua_S,"GetFileID", lua_VoiceApollo_VoiceApollo_GetFileID);
        tolua_function(tolua_S,"OpenMic", lua_VoiceApollo_VoiceApollo_OpenMic);
        tolua_function(tolua_S,"GetSpeakerLevel", lua_VoiceApollo_VoiceApollo_GetSpeakerLevel);
        tolua_function(tolua_S,"OpenSpeaker", lua_VoiceApollo_VoiceApollo_OpenSpeaker);
        tolua_function(tolua_S,"SetBGMPath", lua_VoiceApollo_VoiceApollo_SetBGMPath);
        tolua_function(tolua_S,"SetMicVolume", lua_VoiceApollo_VoiceApollo_SetMicVolume);
        tolua_function(tolua_S,"ApolloVoiceInit", lua_VoiceApollo_VoiceApollo_ApolloVoiceInit);
        //tolua_function(tolua_S,"ListenerRecordDone", lua_VoiceApollo_VoiceApollo_ListenerRecordDone);
        tolua_function(tolua_S,"onGetAuthKey", lua_VoiceApollo_VoiceApollo_onGetAuthKey);
        tolua_function(tolua_S,"SetUploadDoneCallback", lua_VoiceApollo_VoiceApollo_SetUploadDoneCallback);
        tolua_function(tolua_S,"onJoinRoom", lua_VoiceApollo_VoiceApollo_onJoinRoom);
        tolua_function(tolua_S,"StopBGMPlay", lua_VoiceApollo_VoiceApollo_StopBGMPlay);
        tolua_function(tolua_S,"StartBGMPlay", lua_VoiceApollo_VoiceApollo_StartBGMPlay);
        tolua_function(tolua_S,"StopRecord", lua_VoiceApollo_VoiceApollo_StopRecord);
        tolua_function(tolua_S,"CloseSpeaker", lua_VoiceApollo_VoiceApollo_CloseSpeaker);
        tolua_function(tolua_S,"CloseMic", lua_VoiceApollo_VoiceApollo_CloseMic);
        tolua_function(tolua_S,"EnableNativeBGMPlay", lua_VoiceApollo_VoiceApollo_EnableNativeBGMPlay);
        tolua_function(tolua_S,"PlayFile", lua_VoiceApollo_VoiceApollo_PlayFile);
        //tolua_function(tolua_S,"ListenerUploadDone", lua_VoiceApollo_VoiceApollo_ListenerUploadDone);
        tolua_function(tolua_S,"SetMode", lua_VoiceApollo_VoiceApollo_SetMode);
        tolua_function(tolua_S,"StartRecord", lua_VoiceApollo_VoiceApollo_StartRecord);
		tolua_function(tolua_S,"ListenerActionDone", lua_VoiceApollo_VoiceApollo_ListenerActionDone);
		tolua_function(tolua_S,"SetJoinRoomDoneCallback", lua_VoiceApollo_VoiceApollo_SetJoinRoomDoneCallback);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(VoiceApollo).name();
    g_luaType[typeName] = "VoiceApollo";
    g_typeCast["VoiceApollo"] = "VoiceApollo";
    return 1;
}