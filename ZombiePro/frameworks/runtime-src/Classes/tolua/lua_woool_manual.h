#pragma once
#include "cocos2d.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"
#include "CCLuaValue.h"
#include "CCLuaEngine.h"

/*****
lua_Debug ar;
if (lua_getstack(tolua_S, 1, &ar)) { 
	lua_getinfo(tolua_S, "Sl", &ar);
	if (ar.currentline > 0) {
		CCLOGWIN32("%s:%d: ", ar.short_src, ar.currentline);
	}
}
*/

int lua_woool_TouchSprite_registerTouchDownHandler(lua_State* tolua_S)
{
    int argc = 0;
    TouchSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"TouchSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (TouchSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_TouchSprite_registerTouchDownHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
#if COCOS2D_DEBUG >= 1
        if (!toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) {
            goto tolua_lerror;
        }
#endif

        LUA_FUNCTION handler =  toluafix_ref_function(tolua_S,2,0);
        cobj->registerTouchDownHandler(handler);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "TouchSprite:registerTouchDownHandler",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_TouchSprite_registerTouchDownHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_TouchSprite_registerTouchUpHandler(lua_State* tolua_S)
{
    int argc = 0;
    TouchSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"TouchSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (TouchSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_TouchSprite_registerTouchUpHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
#if COCOS2D_DEBUG >= 1
        if (!toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) {
            goto tolua_lerror;
        }
#endif

        LUA_FUNCTION handler =  toluafix_ref_function(tolua_S,2,0);
        cobj->registerTouchUpHandler(handler);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "TouchSprite:registerTouchUpHandler",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_TouchSprite_registerTouchUpHandler'.",&tolua_err);
#endif

    return 0;
}

static void extend_TouchSprite(lua_State* L)
{
    lua_pushstring(L, "TouchSprite");
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_istable(L,-1))
    {
		tolua_function(L,"registerTouchDownHandler",lua_woool_TouchSprite_registerTouchDownHandler);
		tolua_function(L,"registerTouchUpHandler",lua_woool_TouchSprite_registerTouchUpHandler);
    }
    lua_pop(L, 1);
}

int lua_woool_Touch9Sprite_registerTouchDownHandler(lua_State* tolua_S)
{
    int argc = 0;
    Touch9Sprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Touch9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Touch9Sprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_Touch9Sprite_registerTouchDownHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
#if COCOS2D_DEBUG >= 1
        if (!toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) {
            goto tolua_lerror;
        }
#endif

        LUA_FUNCTION handler =  toluafix_ref_function(tolua_S,2,0);
        cobj->registerTouchDownHandler(handler);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Touch9Sprite:registerTouchDownHandler",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_Touch9Sprite_registerTouchDownHandler'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_Touch9Sprite_registerTouchUpHandler(lua_State* tolua_S)
{
    int argc = 0;
    Touch9Sprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Touch9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Touch9Sprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_Touch9Sprite_registerTouchUpHandler'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
#if COCOS2D_DEBUG >= 1
        if (!toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) {
            goto tolua_lerror;
        }
#endif

        LUA_FUNCTION handler =  toluafix_ref_function(tolua_S,2,0);
        cobj->registerTouchUpHandler(handler);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Touch9Sprite:registerTouchUpHandler",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_Touch9Sprite_registerTouchUpHandler'.",&tolua_err);
#endif

    return 0;
}

static void extend_Touch9Sprite(lua_State* L)
{
    lua_pushstring(L, "Touch9Sprite");
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_istable(L,-1))
    {
        tolua_function(L,"registerTouchDownHandler",lua_woool_Touch9Sprite_registerTouchDownHandler);
		tolua_function(L,"registerTouchUpHandler",lua_woool_Touch9Sprite_registerTouchUpHandler);
    }
    lua_pop(L, 1);
}

/*int lua_woool_MenuButton_setLongTouchCallBack(lua_State* tolua_S)
{
    int argc = 0;
    MenuButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MenuButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MenuButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MenuButton_setLongTouchCallBack'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
#if COCOS2D_DEBUG >= 1
        if (!toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) {
            goto tolua_lerror;
        }
#endif

        LUA_FUNCTION handler =  toluafix_ref_function(tolua_S,2,0);
        cobj->setLongTouchCallBack(handler);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MenuButton:setLongTouchCallBack",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MenuButton_setLongTouchCallBack'.",&tolua_err);
#endif

    return 0;
}*/
/*
static void extend_MenuButton(lua_State* L)
{
    lua_pushstring(L, "MenuButton");
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_istable(L,-1))
    {
        tolua_function(L,"setLongTouchCallBack",lua_woool_MenuButton_setLongTouchCallBack);
    }
    lua_pop(L, 1);
}*/

int lua_woool_SpriteMonster_insertActionChild(lua_State* tolua_S)
{
    int argc = 0;
    SpriteMonster* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteMonster*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_insertActionChild'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        std::string arg0;
        int arg1;
        int arg2;
		ok &= luaval_to_std_string(tolua_S, 2,&arg0, "SpriteMonster:insertActionChild");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "SpriteMonster:insertActionChild");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "SpriteMonster:insertActionChild");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_insertActionChild'", nullptr);
            return 0;
        }
        cobj->insertActionChild(arg0, arg1, arg2);
        //object_to_luaval<SpriteBase>(tolua_S, "SpriteBase",(SpriteBase*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:insertActionChild",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_insertActionChild'.",&tolua_err);
#endif

    return 0;
}
static void extend_SpriteMonster(lua_State* L)
{
    lua_pushstring(L, "SpriteMonster");
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_istable(L,-1))
    {
        tolua_function(L,"insertActionChild",lua_woool_SpriteMonster_insertActionChild);
    }
    lua_pop(L, 1);
}
/*
int lua_woool_LuaMsgBuffer_getMsgBody(lua_State* tolua_S)
{
    int argc = 0;
    LuaMsgBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"LuaMsgBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (LuaMsgBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_LuaMsgBuffer_getMsgBody'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_LuaMsgBuffer_getMsgBody'", nullptr);
            return 0;
        }
        const char* ret = cobj->getMsgBody();
        lua_pushlightuserdata(tolua_S, (void*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaMsgBuffer:getMsgBody",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_LuaMsgBuffer_getMsgBody'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_LuaMsgBuffer_getMsgBodyLen(lua_State* tolua_S)
{
    int argc = 0;
    LuaMsgBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"LuaMsgBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (LuaMsgBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_LuaMsgBuffer_getMsgBodyLen'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_LuaMsgBuffer_getMsgBodyLen'", nullptr);
            return 0;
        }
        int ret = cobj->getMsgBodyLen();
        lua_pushinteger(tolua_S,(lua_Integer)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaMsgBuffer:getMsgBodyLen",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_LuaMsgBuffer_getMsgBodyLen'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_LuaMsgBuffer_pushData(lua_State* tolua_S)
{
    int argc = 0;
    LuaMsgBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"LuaMsgBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (LuaMsgBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_LuaMsgBuffer_pushData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
#if COCOS2D_DEBUG >= 1
		if (!tolua_isuserdata(tolua_S,2,0,&tolua_err))
			goto tolua_lerror;
#endif

        int arg1;
		
		void* arg0 = ((void*)tolua_touserdata(tolua_S,2,0));

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "LuaMsgBuffer:pushData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_LuaMsgBuffer_pushData'", nullptr);
            return 0;
        }
        cobj->pushData(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaMsgBuffer:pushData",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_LuaMsgBuffer_pushData'.",&tolua_err);
#endif

    return 0;
}


int lua_woool_LuaMsgBuffer_writeByFmt(lua_State* tolua_S)
{
    int argc = 0;
    LuaMsgBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"LuaMsgBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (LuaMsgBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_LuaMsgBuffer_writeByFmt'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc >= 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "LuaMsgBuffer:writeByFmt");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_LuaMsgBuffer_writeByFmt'", nullptr);
            return 0;
        }

		for (int index = 0;index < (int)arg0.size() && index + 3 <= argc + 1; ++index)
		{
			char c = arg0[index];
			switch (c)
			{
				case 'b': { cobj->pushBool((bool)  tolua_toboolean(tolua_S,3+index,0)); } break;
				case 'i': { cobj->pushInt((int)  tolua_tonumber(tolua_S,3+index,0)); } break;
				case 'c': { cobj->pushChar((char)  tolua_tonumber(tolua_S,3+index,0)); } break;
				case 's': { cobj->pushShort((short)  tolua_tonumber(tolua_S,3+index,0)); } break;
				case 'd': { cobj->pushDouble((double)  tolua_tonumber(tolua_S,3+index,0)); } break;
				case 'C': { cobj->pushChars((const char*)  tolua_tostring(tolua_S,3+index,0)); } break;
				case 'S': 
					{ 
						std::string str = ((std::string)  tolua_tocppstring(tolua_S,3+index,0));
						cobj->pushString(str);
					} break;
				default: break;
			}
		 }
        
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaMsgBuffer:writeByFmt",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_LuaMsgBuffer_writeByFmt'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_LuaMsgBuffer_readByFmt(lua_State* tolua_S)
{
    int argc = 0;
    LuaMsgBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"LuaMsgBuffer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (LuaMsgBuffer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_LuaMsgBuffer_readByFmt'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "LuaMsgBuffer:readByFmt");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_LuaMsgBuffer_readByFmt'", nullptr);
            return 0;
        }

		for (int index = 0;index < (int)arg0.size(); ++index)
		{
			char c = arg0[index];
			switch (c)
			{
			case 'b': { tolua_pushboolean(tolua_S, (bool)cobj->popBool()); } break;
			case 'i': { tolua_pushnumber(tolua_S, (lua_Number)cobj->popInt()); } break;
			case 'c': { tolua_pushnumber(tolua_S, (lua_Number)cobj->popChar()); } break;
			case 's': { tolua_pushnumber(tolua_S, (lua_Number)cobj->popShort()); } break;
			case 'd': { tolua_pushnumber(tolua_S, (lua_Number)cobj->popDouble()); } break;
			case 'f': { tolua_pushnumber(tolua_S, (lua_Number)cobj->popFloat()); } break;
			case 'S': { tolua_pushcppstring(tolua_S, (const char*)cobj->popString()); } break;
			case 'l': { tolua_pushnumber(tolua_S, (lua_Number)cobj->popLongLong()); } break;
			default: break;
			}
		}
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaMsgBuffer:readByFmt",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_LuaMsgBuffer_readByFmt'.",&tolua_err);
#endif

    return 0;
}
static void extend_LuaMsgBuffer(lua_State* L)
{
    lua_pushstring(L, "LuaMsgBuffer");
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_istable(L,-1))
    {
        tolua_function(L,"getMsgBody",lua_woool_LuaMsgBuffer_getMsgBody);
        tolua_function(L,"getMsgBodyLen",lua_woool_LuaMsgBuffer_getMsgBodyLen);
        tolua_function(L,"pushData",lua_woool_LuaMsgBuffer_pushData);
        tolua_function(L,"writeByFmt",lua_woool_LuaMsgBuffer_writeByFmt);
		tolua_function(L,"readByFmt",lua_woool_LuaMsgBuffer_readByFmt);
    }
    lua_pop(L, 1);
}
*/
/*int lua_woool_LuaSocket_openSocket(lua_State* tolua_S)
{
    int argc = 0;
    LuaSocket* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"LuaSocket",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (LuaSocket*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_LuaSocket_openSocket'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc >= 4) 
    {
        int arg0;
        int arg1;
        int arg2;
        std::vector<std::string> arg3;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "LuaSocket:openSocket");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "LuaSocket:openSocket");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "LuaSocket:openSocket");
        
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_LuaSocket_openSocket'", nullptr);
            return 0;
        }

		std::vector<std::string> ips;
		std::string arg_tmp;
		for (int i = 5; i <= argc + 1; ++i)
		{
			ok &= luaval_to_std_string(tolua_S, i, &arg_tmp, "LuaSocket:openSocket");
			if (!ok)
			{
				tolua_error(tolua_S, "invalid arguments in function 'tolua_LuaSocket_LuaSocket_openSocket'", nullptr);
				return 0;
			}

			ips.push_back(arg_tmp);
		}

        int ret = cobj->openSocket(arg0, arg1, arg2, ips);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaSocket:openSocket",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_LuaSocket_openSocket'.",&tolua_err);
#endif

    return 0;
}
static void extend_LuaSocket(lua_State* L)
{
    lua_pushstring(L, "LuaSocket");
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_istable(L,-1))
    {
        tolua_function(L,"openSocket",lua_woool_LuaSocket_openSocket);
    }
    lua_pop(L, 1);
}
*/

int lua_woool_MapView_registerWalkCb(lua_State* tolua_S)
{
    int argc = 0;
    MapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapView_registerWalkCb'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
#if COCOS2D_DEBUG >= 1
        if (!toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) {
            goto tolua_lerror;
        }
#endif

        LUA_FUNCTION handler =  toluafix_ref_function(tolua_S,2,0);
        cobj->registerWalkCb(handler);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:registerWalkCb",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_registerWalkCb'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapView_registerRockerCb(lua_State* tolua_S)
{
    int argc = 0;
    MapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapView_registerRockerCb'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
#if COCOS2D_DEBUG >= 1
        if (!toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) {
            goto tolua_lerror;
        }
#endif

        LUA_FUNCTION handler =  toluafix_ref_function(tolua_S,2,0);
        cobj->registerRockerCb(handler);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:registerRockerCb",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_registerRockerCb'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapView_registerTouchMoveCb(lua_State* tolua_S)
{
    int argc = 0;
    MapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapView_registerTouchMoveCb'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
#if COCOS2D_DEBUG >= 1
        if (!toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) {
            goto tolua_lerror;
        }
#endif

        LUA_FUNCTION handler =  toluafix_ref_function(tolua_S,2,0);
        cobj->registerTouchMoveCb(handler);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:registerTouchMoveCb",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_registerTouchMoveCb'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapView_registerHurtCb(lua_State* tolua_S)
{
    int argc = 0;
    MapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapView_registerHurtCb'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
#if COCOS2D_DEBUG >= 1
        if (!toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) {
            goto tolua_lerror;
        }
#endif

        LUA_FUNCTION handler =  toluafix_ref_function(tolua_S,2,0);
        cobj->registerHurtCb(handler);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:registerHurtCb",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_registerHurtCb'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapView_moveMonsterByPos(lua_State* tolua_S)
{
    int argc = 0;
    MapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapView_moveMonsterByPos'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2 || argc == 3 || argc == 4) 
    {
        cocos2d::Point arg0;
        SpriteMonster* arg1;
        double arg2 = 3.0;
        bool arg3 = true;

        ok &= luaval_to_point(tolua_S, 2, &arg0, "MapView:moveMonsterByPos");

        ok &= luaval_to_object<SpriteMonster>(tolua_S, 3, "SpriteMonster",&arg1, "MapView:moveMonsterByPos");

		if (argc >= 3)
			ok &= luaval_to_number(tolua_S, 4,&arg2, "MapView:moveMonsterByPos");

		if (argc >= 4)
			ok &= luaval_to_boolean(tolua_S, 5,&arg3, "MapView:moveMonsterByPos");

        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_moveMonsterByPos'", nullptr);
            return 0;
        }

		std::vector<cocos2d::Point> arg4;
        cobj->moveMonsterByPos(arg0, arg1, arg2, arg3, &arg4);
		std_vector_vec2_to_luaval(tolua_S, arg4);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:moveMonsterByPos",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_moveMonsterByPos'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapView_getPathByPos(lua_State* tolua_S)
{
    int argc = 0;
    MapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapView_getPathByPos'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Point arg0;
        cocos2d::Point arg1;

        ok &= luaval_to_point(tolua_S, 2, &arg0, "MapView:getPathByPos");

        ok &= luaval_to_point(tolua_S, 3, &arg1, "MapView:getPathByPos");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_getPathByPos'", nullptr);
            return 0;
        }
        std::vector<cocos2d::Vec2> ret = cobj->getPathByPos(arg0, arg1);
        std_vector_vec2_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:getPathByPos",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_getPathByPos'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapView_getRolePath(lua_State* tolua_S)
{
    int argc = 0;
    MapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapView_getRolePath'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_getRolePath'", nullptr);
            return 0;
        }
        std::vector<cocos2d::Vec2, std::allocator<cocos2d::Vec2> > ret = cobj->getRolePath();
        std_vector_vec2_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:getRolePath",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_getRolePath'.",&tolua_err);
#endif

    return 0;
}
static void extend_MapView(lua_State* L)
{
    lua_pushstring(L, "MapView");
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_istable(L,-1))
    {
		tolua_function(L,"registerWalkCb",lua_woool_MapView_registerWalkCb);
		tolua_function(L,"registerRockerCb",lua_woool_MapView_registerRockerCb);
		tolua_function(L,"registerTouchMoveCb",lua_woool_MapView_registerTouchMoveCb);
		tolua_function(L,"registerHurtCb",lua_woool_MapView_registerHurtCb);
		tolua_function(L,"moveMonsterByPos",lua_woool_MapView_moveMonsterByPos);
		tolua_function(L,"getPathByPos",lua_woool_MapView_getPathByPos);
		tolua_function(L,"getRolePath",lua_woool_MapView_getRolePath);
    }
    lua_pop(L, 1);
}

/*int lua_woool_CCoverflow_RegisterCoverflowEventHandler(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"CCoverflow",0,&tolua_err) ||
		!toluafix_isfunction(tolua_S,2,"LUA_FUNCTION",0,&tolua_err) ||
		!tolua_isnumber(tolua_S, 3, 0, &tolua_err)                  ||
		!tolua_isnoobj(tolua_S,4,&tolua_err)
		)
		goto tolua_lerror;
	else
#endif
	{
		CCoverflow* self = (CCoverflow*)tolua_tousertype(tolua_S,1,0);
		if(self != nullptr)
		{
			int handler = (  toluafix_ref_function(tolua_S,2,0));

			ScriptHandlerMgr::HandlerType type = static_cast<ScriptHandlerMgr::HandlerType>((int)tolua_tonumber(tolua_S, 3, 0));
			switch (type)
			{
			case ScriptHandlerMgr::HandlerType::EVENT_COVERFLOW_SELECT:
				{
					self->setSelCallback([=](cocos2d::Node* card, int selIndex){
						if(card == nullptr)
							return;

						int iSelHandle = ScriptHandlerMgr::getInstance()->getObjectHandler((void*)self, type);
						if(handler == 0)
							return;

						LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
						if (nullptr == stack)
							return;

						stack->pushObject(card, "cc.Node");
						stack->pushInt(selIndex);

						int iRet = stack->executeFunctionByHandler(iSelHandle, 2);

						stack->clean();

					});
					ScriptHandlerMgr::getInstance()->addObjectHandler((void*)self, handler, type);
				}
				break;
			case ScriptHandlerMgr::HandlerType::EVENT_COVERFLOW_START:
				{
					self->setStartCallback([=](){
						int iStartHandle = ScriptHandlerMgr::getInstance()->getObjectHandler((void*)self, type);
						if(handler == 0)
							return;

						LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
						if (nullptr == stack)
							return;

						int iRet = stack->executeFunctionByHandler(iStartHandle, 0);

						stack->clean();
					});
					ScriptHandlerMgr::getInstance()->addObjectHandler((void*)self, handler, type);
				}
				break;
			
			default:
				break;
			}
		}
	}
	return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_woool_CCoverflow_RegisterCoverflowEventHandler'.",&tolua_err);
	return 0;
#endif
}

int lua_woool_CCoverflow_UnregisterCoverflowEventHandler(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
	tolua_Error tolua_err;
	if (
		!tolua_isusertype(tolua_S,1,"CCoverflow",0,&tolua_err) ||
		!tolua_isnumber(tolua_S, 2, 0, &tolua_err) ||
		!tolua_isnoobj(tolua_S,3,&tolua_err)
		)
		goto tolua_lerror;
	else
#endif
	{
		CCoverflow* self = (CCoverflow*)tolua_tousertype(tolua_S,1,0);
		if(self != nullptr)
		{
			ScriptHandlerMgr::HandlerType type = static_cast<ScriptHandlerMgr::HandlerType>((int)tolua_tonumber(tolua_S, 2, 0));
			switch (type)
			{
			case ScriptHandlerMgr::HandlerType::EVENT_COVERFLOW_SELECT:
				self->setSelCallback(nullptr);
				ScriptHandlerMgr::getInstance()->removeObjectHandler((void*)self, type);
				break;
			case ScriptHandlerMgr::HandlerType::EVENT_COVERFLOW_START:
				self->setStartCallback(nullptr);
				ScriptHandlerMgr::getInstance()->removeObjectHandler((void*)self, type);
				break;

			default:
				break;
			}
			
		}
	}
	return 0;
#ifndef TOLUA_RELEASE
tolua_lerror:
	tolua_error(tolua_S,"#ferror in function 'lua_woool_CCoverflow_UnregisterCoverflowEventHandler'.",&tolua_err);
	return 0;
#endif
}

static void extendCCoverflow(lua_State* L)
{
	lua_pushstring(L, "CCoverflow");
	lua_rawget(L, LUA_REGISTRYINDEX);
	if (lua_istable(L,-1))
	{
		tolua_function(L, "RegisterCoverflowEventHandler", lua_woool_CCoverflow_RegisterCoverflowEventHandler);
		tolua_function(L, "UnregisterCoverflowEventHandler", lua_woool_CCoverflow_UnregisterCoverflowEventHandler);
	}
	lua_pop(L, 1);
}
*/
static int lua_Mapview_onMsgHandler(lua_State *L)
{
	int arg0 = luaL_checkinteger(L, 1);
	if (g_MapView != nullptr)
	{
		//g_MapView->onMsgHandler(arg0);
	}
    return 0;
}


static int lua_byteAnd(lua_State *L)
{
	int arg0 = luaL_checkinteger(L, -1);
	int arg1 = luaL_checkinteger(L, -2);
	lua_settop(L, 0);
	lua_pushinteger(L, arg0 & arg1);
    return 1;
}

int register_all_woool_manual(lua_State* L)
{
    if (nullptr == L)
        return 0;

	extend_TouchSprite(L);
	extend_Touch9Sprite(L);
	//extend_MenuButton(L);
	extend_SpriteMonster(L);
	//extend_LuaMsgBuffer(L);
	//extend_LuaSocket(L);
	extend_MapView(L);
	//extendCCoverflow(L);
	lua_register(L, "Mapview_onMsgHandler", lua_Mapview_onMsgHandler);
	lua_register(L, "lua_byteAnd", lua_byteAnd);
    return 0;
}
