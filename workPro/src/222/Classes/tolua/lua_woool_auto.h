#pragma once
#include "cocos2d.h"
#include "CCComponentLua.h"
#include "woool.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"


int lua_woool_MapTileNode_getTilePoint(lua_State* tolua_S)
{
    int argc = 0;
    MapTileNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapTileNode_getTilePoint'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapTileNode_getTilePoint'", nullptr);
            return 0;
        }
        cocos2d::Point ret = cobj->getTilePoint();
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileNode:getTilePoint",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapTileNode_getTilePoint'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapTileNode_setTilePoint(lua_State* tolua_S)
{
    int argc = 0;
    MapTileNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapTileNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapTileNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapTileNode_setTilePoint'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;

        ok &= luaval_to_point(tolua_S, 2, &arg0, "MapTileNode:setTilePoint");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapTileNode_setTilePoint'", nullptr);
            return 0;
        }
        cobj->setTilePoint(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileNode:setTilePoint",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapTileNode_setTilePoint'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapTileNode_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"MapTileNode",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapTileNode_create'", nullptr);
            return 0;
        }
        MapTileNode* ret = MapTileNode::create();
        object_to_luaval<MapTileNode>(tolua_S, "MapTileNode",(MapTileNode*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "MapTileNode:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapTileNode_create'.",&tolua_err);
#endif
    return 0;
}
int lua_woool_MapTileNode_constructor(lua_State* tolua_S)
{
    int argc = 0;
    MapTileNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapTileNode_constructor'", nullptr);
            return 0;
        }
        cobj = new MapTileNode();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"MapTileNode");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapTileNode:MapTileNode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapTileNode_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_woool_MapTileNode_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (MapTileNode)");
    return 0;
}

int lua_register_woool_MapTileNode(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"MapTileNode");
    tolua_cclass(tolua_S,"MapTileNode","MapTileNode","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"MapTileNode");
        tolua_function(tolua_S,"new",lua_woool_MapTileNode_constructor);
        tolua_function(tolua_S,"getTilePoint",lua_woool_MapTileNode_getTilePoint);
        tolua_function(tolua_S,"setTilePoint",lua_woool_MapTileNode_setTilePoint);
        tolua_function(tolua_S,"create", lua_woool_MapTileNode_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(MapTileNode).name();
    g_luaType[typeName] = "MapTileNode";
    g_typeCast["MapTileNode"] = "MapTileNode";
    return 1;
}

int lua_woool_GraySprite_setColorWrite(lua_State* tolua_S)
{
    int argc = 0;
    GraySprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GraySprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GraySprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_GraySprite_setColorWrite'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "GraySprite:setColorWrite");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_GraySprite_setColorWrite'", nullptr);
            return 0;
        }
        cobj->setColorWrite(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GraySprite:setColorWrite",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_GraySprite_setColorWrite'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_GraySprite_addColorGray(lua_State* tolua_S)
{
    int argc = 0;
    GraySprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GraySprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GraySprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_GraySprite_addColorGray'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_GraySprite_addColorGray'", nullptr);
            return 0;
        }
        cobj->addColorGray();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GraySprite:addColorGray",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_GraySprite_addColorGray'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_GraySprite_setColorGray(lua_State* tolua_S)
{
    int argc = 0;
    GraySprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GraySprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GraySprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_GraySprite_setColorGray'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "GraySprite:setColorGray");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_GraySprite_setColorGray'", nullptr);
            return 0;
        }
        cobj->setColorGray(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GraySprite:setColorGray",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_GraySprite_setColorGray'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_GraySprite_removeColorGray(lua_State* tolua_S)
{
    int argc = 0;
    GraySprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"GraySprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (GraySprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_GraySprite_removeColorGray'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_GraySprite_removeColorGray'", nullptr);
            return 0;
        }
        cobj->removeColorGray();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GraySprite:removeColorGray",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_GraySprite_removeColorGray'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_GraySprite_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"GraySprite",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 1)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "GraySprite:create");
            if (!ok) { break; }
            GraySprite* ret = GraySprite::create(arg0);
            object_to_luaval<GraySprite>(tolua_S, "GraySprite",(GraySprite*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 0)
        {
            GraySprite* ret = GraySprite::create();
            object_to_luaval<GraySprite>(tolua_S, "GraySprite",(GraySprite*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "GraySprite:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_GraySprite_create'.",&tolua_err);
#endif
    return 0;
}
int lua_woool_GraySprite_constructor(lua_State* tolua_S)
{
    int argc = 0;
    GraySprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_GraySprite_constructor'", nullptr);
            return 0;
        }
        cobj = new GraySprite();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"GraySprite");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "GraySprite:GraySprite",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_woool_GraySprite_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_woool_GraySprite_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (GraySprite)");
    return 0;
}

int lua_register_woool_GraySprite(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"GraySprite");
    tolua_cclass(tolua_S,"GraySprite","GraySprite","cc.Sprite",nullptr);

    tolua_beginmodule(tolua_S,"GraySprite");
        tolua_function(tolua_S,"new",lua_woool_GraySprite_constructor);
        tolua_function(tolua_S,"setColorWrite",lua_woool_GraySprite_setColorWrite);
        tolua_function(tolua_S,"addColorGray",lua_woool_GraySprite_addColorGray);
        tolua_function(tolua_S,"setColorGray",lua_woool_GraySprite_setColorGray);
        tolua_function(tolua_S,"removeColorGray",lua_woool_GraySprite_removeColorGray);
        tolua_function(tolua_S,"create", lua_woool_GraySprite_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(GraySprite).name();
    g_luaType[typeName] = "GraySprite";
    g_typeCast["GraySprite"] = "GraySprite";
    return 1;
}

int lua_woool_SpriteBase_StreakToTheDirRide(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_StreakToTheDirRide'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        double arg0;
        Commen_Direction arg1;
        Commen_ActionToDo arg2;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpriteBase:StreakToTheDirRide");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "SpriteBase:StreakToTheDirRide");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "SpriteBase:StreakToTheDirRide");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_StreakToTheDirRide'", nullptr);
            return 0;
        }
        bool ret = cobj->StreakToTheDirRide(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 4) 
    {
        double arg0;
        Commen_Direction arg1;
        Commen_ActionToDo arg2;
        int arg3;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpriteBase:StreakToTheDirRide");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "SpriteBase:StreakToTheDirRide");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "SpriteBase:StreakToTheDirRide");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "SpriteBase:StreakToTheDirRide");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_StreakToTheDirRide'", nullptr);
            return 0;
        }
        bool ret = cobj->StreakToTheDirRide(arg0, arg1, arg2, arg3);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:StreakToTheDirRide",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_StreakToTheDirRide'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_getBaseUrl(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_getBaseUrl'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_getBaseUrl'", nullptr);
            return 0;
        }
        std::string ret = cobj->getBaseUrl();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:getBaseUrl",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_getBaseUrl'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_getSpriteOneDir(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_getSpriteOneDir'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_getSpriteOneDir'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getSpriteOneDir();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:getSpriteOneDir",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_getSpriteOneDir'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_standedby(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_standedby'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_standedby'", nullptr);
            return 0;
        }
        cobj->standedby();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:standedby",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_standedby'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_playAction(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_playAction'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        double arg0;
        Commen_ActionToDo arg1;
        Commen_Direction arg2;
        int arg3;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpriteBase:playAction");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "SpriteBase:playAction");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "SpriteBase:playAction");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "SpriteBase:playAction");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_playAction'", nullptr);
            return 0;
        }
        cobj->playAction(arg0, arg1, arg2, arg3);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 5) 
    {
        double arg0;
        Commen_ActionToDo arg1;
        Commen_Direction arg2;
        int arg3;
        double arg4;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpriteBase:playAction");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "SpriteBase:playAction");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "SpriteBase:playAction");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "SpriteBase:playAction");

        ok &= luaval_to_number(tolua_S, 6,&arg4, "SpriteBase:playAction");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_playAction'", nullptr);
            return 0;
        }
        cobj->playAction(arg0, arg1, arg2, arg3, arg4);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:playAction",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_playAction'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_getCurrectDir(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_getCurrectDir'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_getCurrectDir'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getCurrectDir();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:getCurrectDir",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_getCurrectDir'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_isNoActorOrNpc(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_isNoActorOrNpc'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_isNoActorOrNpc'", nullptr);
            return 0;
        }
        bool ret = cobj->isNoActorOrNpc();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:isNoActorOrNpc",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_isNoActorOrNpc'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_getActorFlag(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_getActorFlag'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_getActorFlag'", nullptr);
            return 0;
        }
        bool ret = cobj->getActorFlag();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:getActorFlag",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_getActorFlag'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_setBlue(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_setBlue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "SpriteBase:setBlue");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_setBlue'", nullptr);
            return 0;
        }
        cobj->setBlue(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:setBlue",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_setBlue'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_initMaxDeathCut(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_initMaxDeathCut'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "SpriteBase:initMaxDeathCut");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_initMaxDeathCut'", nullptr);
            return 0;
        }
        cobj->initMaxDeathCut(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:initMaxDeathCut",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_initMaxDeathCut'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_setPlistsNum(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_setPlistsNum'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "SpriteBase:setPlistsNum");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_setPlistsNum'", nullptr);
            return 0;
        }
        cobj->setPlistsNum(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:setPlistsNum",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_setPlistsNum'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_getResId(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_getResId'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_getResId'", nullptr);
            return 0;
        }
        int ret = cobj->getResId();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:getResId",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_getResId'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_streakToTheDir(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_streakToTheDir'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        Commen_Direction arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpriteBase:streakToTheDir");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "SpriteBase:streakToTheDir");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_streakToTheDir'", nullptr);
            return 0;
        }
        bool ret = cobj->streakToTheDir(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:streakToTheDir",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_streakToTheDir'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_setType(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_setType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        SpriteType arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "SpriteBase:setType");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_setType'", nullptr);
            return 0;
        }
        cobj->setType(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:setType",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_setType'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_get5DirMode(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_get5DirMode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_get5DirMode'", nullptr);
            return 0;
        }
        bool ret = cobj->get5DirMode();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:get5DirMode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_get5DirMode'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_initHurtStatus(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_initHurtStatus'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "SpriteBase:initHurtStatus");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_initHurtStatus'", nullptr);
            return 0;
        }
        cobj->initHurtStatus(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:initHurtStatus",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_initHurtStatus'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_initMagicStatus(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_initMagicStatus'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "SpriteBase:initMagicStatus");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_initMagicStatus'", nullptr);
            return 0;
        }
        cobj->initMagicStatus(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:initMagicStatus",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_initMagicStatus'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_initWalkStatus(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_initWalkStatus'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "SpriteBase:initWalkStatus");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_initWalkStatus'", nullptr);
            return 0;
        }
        cobj->initWalkStatus(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        int arg0;
        double arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "SpriteBase:initWalkStatus");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "SpriteBase:initWalkStatus");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_initWalkStatus'", nullptr);
            return 0;
        }
        cobj->initWalkStatus(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:initWalkStatus",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_initWalkStatus'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_setResId(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_setResId'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "SpriteBase:setResId");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_setResId'", nullptr);
            return 0;
        }
        cobj->setResId(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:setResId",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_setResId'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_initStandStatus(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_initStandStatus'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        int arg0;
        int arg1;
        double arg2;
        Commen_Direction arg3;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "SpriteBase:initStandStatus");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "SpriteBase:initStandStatus");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "SpriteBase:initStandStatus");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "SpriteBase:initStandStatus");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_initStandStatus'", nullptr);
            return 0;
        }
        cobj->initStandStatus(arg0, arg1, arg2, arg3);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:initStandStatus",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_initStandStatus'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_setWrite(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_setWrite'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "SpriteBase:setWrite");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_setWrite'", nullptr);
            return 0;
        }
        cobj->setWrite(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:setWrite",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_setWrite'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_getMainNode(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_getMainNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_getMainNode'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->getMainNode();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:getMainNode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_getMainNode'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_collideInTheDir(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_collideInTheDir'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        double arg0;
        cocos2d::Point arg1;
        Commen_Direction arg2;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpriteBase:collideInTheDir");

        ok &= luaval_to_point(tolua_S, 3, &arg1, "SpriteBase:collideInTheDir");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "SpriteBase:collideInTheDir");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_collideInTheDir'", nullptr);
            return 0;
        }
        bool ret = cobj->collideInTheDir(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:collideInTheDir",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_collideInTheDir'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_setSpriteDir(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_setSpriteDir'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        Commen_Direction arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "SpriteBase:setSpriteDir");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_setSpriteDir'", nullptr);
            return 0;
        }
        bool ret = cobj->setSpriteDir(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:setSpriteDir",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_setSpriteDir'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_walkToPos(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_walkToPos'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        cocos2d::Point arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpriteBase:walkToPos");

        ok &= luaval_to_point(tolua_S, 3, &arg1, "SpriteBase:walkToPos");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_walkToPos'", nullptr);
            return 0;
        }
        cobj->walkToPos(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 3) 
    {
        double arg0;
        cocos2d::Point arg1;
        bool arg2;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpriteBase:walkToPos");

        ok &= luaval_to_point(tolua_S, 3, &arg1, "SpriteBase:walkToPos");

        ok &= luaval_to_boolean(tolua_S, 4,&arg2, "SpriteBase:walkToPos");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_walkToPos'", nullptr);
            return 0;
        }
        cobj->walkToPos(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:walkToPos",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_walkToPos'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_changeState(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_changeState'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        ActionState arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "SpriteBase:changeState");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_changeState'", nullptr);
            return 0;
        }
        bool ret = cobj->changeState(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:changeState",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_changeState'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_initRunStatus(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_initRunStatus'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "SpriteBase:initRunStatus");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_initRunStatus'", nullptr);
            return 0;
        }
        cobj->initRunStatus(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:initRunStatus",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_initRunStatus'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_setFirstLoadRes(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_setFirstLoadRes'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "SpriteBase:setFirstLoadRes");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_setFirstLoadRes'", nullptr);
            return 0;
        }
        cobj->setFirstLoadRes(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:setFirstLoadRes",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_setFirstLoadRes'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_standed(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_standed'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_standed'", nullptr);
            return 0;
        }
        bool ret = cobj->standed();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:standed",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_standed'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_attackOneTime(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_attackOneTime'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        cocos2d::Point arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpriteBase:attackOneTime");

        ok &= luaval_to_point(tolua_S, 3, &arg1, "SpriteBase:attackOneTime");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_attackOneTime'", nullptr);
            return 0;
        }
        bool ret = cobj->attackOneTime(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:attackOneTime",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_attackOneTime'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_setBaseUrl(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_setBaseUrl'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "SpriteBase:setBaseUrl");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_setBaseUrl'", nullptr);
            return 0;
        }
        cobj->setBaseUrl(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:setBaseUrl",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_setBaseUrl'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_setMainSprite(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_setMainSprite'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Sprite* arg0;

        ok &= luaval_to_object<cocos2d::Sprite>(tolua_S, 2, "cc.Sprite",&arg0, "SpriteBase:setMainSprite");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_setMainSprite'", nullptr);
            return 0;
        }
        cobj->setMainSprite(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:setMainSprite",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_setMainSprite'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_setGray(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_setGray'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "SpriteBase:setGray");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_setGray'", nullptr);
            return 0;
        }
        cobj->setGray(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:setGray",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_setGray'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_getType(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_getType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_getType'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getType();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:getType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_getType'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_setCurrActionState(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_setCurrActionState'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        ActionState arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "SpriteBase:setCurrActionState");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_setCurrActionState'", nullptr);
            return 0;
        }
        cobj->setCurrActionState(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:setCurrActionState",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_setCurrActionState'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_moveToPos(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_moveToPos'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        cocos2d::Point arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpriteBase:moveToPos");

        ok &= luaval_to_point(tolua_S, 3, &arg1, "SpriteBase:moveToPos");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_moveToPos'", nullptr);
            return 0;
        }
        cobj->moveToPos(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 3) 
    {
        double arg0;
        cocos2d::Point arg1;
        bool arg2;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpriteBase:moveToPos");

        ok &= luaval_to_point(tolua_S, 3, &arg1, "SpriteBase:moveToPos");

        ok &= luaval_to_boolean(tolua_S, 4,&arg2, "SpriteBase:moveToPos");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_moveToPos'", nullptr);
            return 0;
        }
        cobj->moveToPos(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:moveToPos",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_moveToPos'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_gotoDeath(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_gotoDeath'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        Commen_Direction arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "SpriteBase:gotoDeath");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_gotoDeath'", nullptr);
            return 0;
        }
        cobj->gotoDeath(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        Commen_Direction arg0;
        double arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "SpriteBase:gotoDeath");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "SpriteBase:gotoDeath");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_gotoDeath'", nullptr);
            return 0;
        }
        cobj->gotoDeath(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:gotoDeath",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_gotoDeath'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_magicUpToPos(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_magicUpToPos'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        cocos2d::Point arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpriteBase:magicUpToPos");

        ok &= luaval_to_point(tolua_S, 3, &arg1, "SpriteBase:magicUpToPos");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_magicUpToPos'", nullptr);
            return 0;
        }
        bool ret = cobj->magicUpToPos(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:magicUpToPos",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_magicUpToPos'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_isTree(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_isTree'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_isTree'", nullptr);
            return 0;
        }
        bool ret = cobj->isTree();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:isTree",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_isTree'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_setSpriteOneDir(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_setSpriteOneDir'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        Commen_Direction arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "SpriteBase:setSpriteOneDir");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_setSpriteOneDir'", nullptr);
            return 0;
        }
        bool ret = cobj->setSpriteOneDir(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:setSpriteOneDir",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_setSpriteOneDir'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_excavateToTheDir(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_excavateToTheDir'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        Commen_Direction arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpriteBase:excavateToTheDir");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "SpriteBase:excavateToTheDir");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_excavateToTheDir'", nullptr);
            return 0;
        }
        bool ret = cobj->excavateToTheDir(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:excavateToTheDir",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_excavateToTheDir'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_set5DirMode(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_set5DirMode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "SpriteBase:set5DirMode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_set5DirMode'", nullptr);
            return 0;
        }
        cobj->set5DirMode(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:set5DirMode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_set5DirMode'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_getMainSprite(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_getMainSprite'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_getMainSprite'", nullptr);
            return 0;
        }
        cocos2d::Sprite* ret = cobj->getMainSprite();
        object_to_luaval<cocos2d::Sprite>(tolua_S, "cc.Sprite",(cocos2d::Sprite*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:getMainSprite",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_getMainSprite'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_setTreeFlag(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_setTreeFlag'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "SpriteBase:setTreeFlag");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_setTreeFlag'", nullptr);
            return 0;
        }
        cobj->setTreeFlag(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:setTreeFlag",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_setTreeFlag'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_changeModeDisplay(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_changeModeDisplay'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        bool arg0;
        std::string arg1;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "SpriteBase:changeModeDisplay");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "SpriteBase:changeModeDisplay");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_changeModeDisplay'", nullptr);
            return 0;
        }
        cobj->changeModeDisplay(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:changeModeDisplay",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_changeModeDisplay'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_initWithFile(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_initWithFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "SpriteBase:initWithFile");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_initWithFile'", nullptr);
            return 0;
        }
        bool ret = cobj->initWithFile(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:initWithFile",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_initWithFile'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_setColor(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_setColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color3B arg0;

        ok &= luaval_to_color3b(tolua_S, 2, &arg0, "SpriteBase:setColor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_setColor'", nullptr);
            return 0;
        }
        cobj->setColor(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:setColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_setColor'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_attackToPos(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_attackToPos'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        cocos2d::Point arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpriteBase:attackToPos");

        ok &= luaval_to_point(tolua_S, 3, &arg1, "SpriteBase:attackToPos");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_attackToPos'", nullptr);
            return 0;
        }
        bool ret = cobj->attackToPos(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:attackToPos",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_attackToPos'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_stopInTheTime(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_stopInTheTime'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_stopInTheTime'", nullptr);
            return 0;
        }
        cobj->stopInTheTime();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:stopInTheTime",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_stopInTheTime'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_setDirByNowPoint(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_setDirByNowPoint'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;

        ok &= luaval_to_point(tolua_S, 2, &arg0, "SpriteBase:setDirByNowPoint");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_setDirByNowPoint'", nullptr);
            return 0;
        }
        bool ret = cobj->setDirByNowPoint(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:setDirByNowPoint",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_setDirByNowPoint'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_initAttackStatus(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_initAttackStatus'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "SpriteBase:initAttackStatus");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_initAttackStatus'", nullptr);
            return 0;
        }
        cobj->initAttackStatus(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:initAttackStatus",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_initAttackStatus'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_isTouchInside(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_isTouchInside'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Touch* arg0;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0, "SpriteBase:isTouchInside");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_isTouchInside'", nullptr);
            return 0;
        }
        bool ret = cobj->isTouchInside(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:isTouchInside",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_isTouchInside'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_getLoadResTime(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_getLoadResTime'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_getLoadResTime'", nullptr);
            return 0;
        }
        int ret = cobj->getLoadResTime();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:getLoadResTime",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_getLoadResTime'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_getResLoadStatus(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_getResLoadStatus'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_getResLoadStatus'", nullptr);
            return 0;
        }
        bool ret = cobj->getResLoadStatus();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:getResLoadStatus",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_getResLoadStatus'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_digToTheDir(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_digToTheDir'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        Commen_Direction arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpriteBase:digToTheDir");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "SpriteBase:digToTheDir");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_digToTheDir'", nullptr);
            return 0;
        }
        bool ret = cobj->digToTheDir(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:digToTheDir",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_digToTheDir'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_moveInTheDir(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_moveInTheDir'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        double arg0;
        cocos2d::Point arg1;
        Commen_Direction arg2;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpriteBase:moveInTheDir");

        ok &= luaval_to_point(tolua_S, 3, &arg1, "SpriteBase:moveInTheDir");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "SpriteBase:moveInTheDir");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_moveInTheDir'", nullptr);
            return 0;
        }
        bool ret = cobj->moveInTheDir(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 4) 
    {
        double arg0;
        cocos2d::Point arg1;
        Commen_Direction arg2;
        double arg3;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpriteBase:moveInTheDir");

        ok &= luaval_to_point(tolua_S, 3, &arg1, "SpriteBase:moveInTheDir");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "SpriteBase:moveInTheDir");

        ok &= luaval_to_number(tolua_S, 5,&arg3, "SpriteBase:moveInTheDir");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_moveInTheDir'", nullptr);
            return 0;
        }
        bool ret = cobj->moveInTheDir(arg0, arg1, arg2, arg3);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:moveInTheDir",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_moveInTheDir'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_hasHurted(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_hasHurted'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        double arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpriteBase:hasHurted");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "SpriteBase:hasHurted");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_hasHurted'", nullptr);
            return 0;
        }
        cobj->hasHurted(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:hasHurted",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_hasHurted'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_getCurrActionState(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_getCurrActionState'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_getCurrActionState'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getCurrActionState();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:getCurrActionState",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_getCurrActionState'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_walkInTheDir(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_walkInTheDir'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        double arg0;
        cocos2d::Point arg1;
        Commen_Direction arg2;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpriteBase:walkInTheDir");

        ok &= luaval_to_point(tolua_S, 3, &arg1, "SpriteBase:walkInTheDir");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "SpriteBase:walkInTheDir");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_walkInTheDir'", nullptr);
            return 0;
        }
        bool ret = cobj->walkInTheDir(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:walkInTheDir",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_walkInTheDir'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_removeStread(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_removeStread'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_removeStread'", nullptr);
            return 0;
        }
        cobj->removeStread();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:removeStread",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_removeStread'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_setActorFlag(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteBase_setActorFlag'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "SpriteBase:setActorFlag");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_setActorFlag'", nullptr);
            return 0;
        }
        cobj->setActorFlag(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:setActorFlag",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_setActorFlag'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteBase_subCacheCount(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_subCacheCount'", nullptr);
            return 0;
        }
        SpriteBase::subCacheCount();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "SpriteBase:subCacheCount",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_subCacheCount'.",&tolua_err);
#endif
    return 0;
}
int lua_woool_SpriteBase_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"SpriteBase",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 2)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "SpriteBase:create");
            if (!ok) { break; }
            cocos2d::Size arg1;
            ok &= luaval_to_size(tolua_S, 3, &arg1, "SpriteBase:create");
            if (!ok) { break; }
            SpriteBase* ret = SpriteBase::create(arg0, arg1);
            object_to_luaval<SpriteBase>(tolua_S, "SpriteBase",(SpriteBase*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 1)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "SpriteBase:create");
            if (!ok) { break; }
            SpriteBase* ret = SpriteBase::create(arg0);
            object_to_luaval<SpriteBase>(tolua_S, "SpriteBase",(SpriteBase*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "SpriteBase:create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_create'.",&tolua_err);
#endif
    return 0;
}
int lua_woool_SpriteBase_constructor(lua_State* tolua_S)
{
    int argc = 0;
    SpriteBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteBase_constructor'", nullptr);
            return 0;
        }
        cobj = new SpriteBase();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"SpriteBase");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteBase:SpriteBase",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteBase_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_woool_SpriteBase_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (SpriteBase)");
    return 0;
}

int lua_register_woool_SpriteBase(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"SpriteBase");
    tolua_cclass(tolua_S,"SpriteBase","SpriteBase","MapTileNode",nullptr);

    tolua_beginmodule(tolua_S,"SpriteBase");
        tolua_function(tolua_S,"new",lua_woool_SpriteBase_constructor);
        tolua_function(tolua_S,"StreakToTheDirRide",lua_woool_SpriteBase_StreakToTheDirRide);
        tolua_function(tolua_S,"getBaseUrl",lua_woool_SpriteBase_getBaseUrl);
        tolua_function(tolua_S,"getSpriteOneDir",lua_woool_SpriteBase_getSpriteOneDir);
        tolua_function(tolua_S,"standedby",lua_woool_SpriteBase_standedby);
        tolua_function(tolua_S,"playAction",lua_woool_SpriteBase_playAction);
        tolua_function(tolua_S,"getCurrectDir",lua_woool_SpriteBase_getCurrectDir);
        tolua_function(tolua_S,"isNoActorOrNpc",lua_woool_SpriteBase_isNoActorOrNpc);
        tolua_function(tolua_S,"getActorFlag",lua_woool_SpriteBase_getActorFlag);
        tolua_function(tolua_S,"setBlue",lua_woool_SpriteBase_setBlue);
        tolua_function(tolua_S,"initMaxDeathCut",lua_woool_SpriteBase_initMaxDeathCut);
        tolua_function(tolua_S,"setPlistsNum",lua_woool_SpriteBase_setPlistsNum);
        tolua_function(tolua_S,"getResId",lua_woool_SpriteBase_getResId);
        tolua_function(tolua_S,"streakToTheDir",lua_woool_SpriteBase_streakToTheDir);
        tolua_function(tolua_S,"setType",lua_woool_SpriteBase_setType);
        tolua_function(tolua_S,"get5DirMode",lua_woool_SpriteBase_get5DirMode);
        tolua_function(tolua_S,"initHurtStatus",lua_woool_SpriteBase_initHurtStatus);
        tolua_function(tolua_S,"initMagicStatus",lua_woool_SpriteBase_initMagicStatus);
        tolua_function(tolua_S,"initWalkStatus",lua_woool_SpriteBase_initWalkStatus);
        tolua_function(tolua_S,"setResId",lua_woool_SpriteBase_setResId);
        tolua_function(tolua_S,"initStandStatus",lua_woool_SpriteBase_initStandStatus);
        tolua_function(tolua_S,"setWrite",lua_woool_SpriteBase_setWrite);
        tolua_function(tolua_S,"getMainNode",lua_woool_SpriteBase_getMainNode);
        tolua_function(tolua_S,"collideInTheDir",lua_woool_SpriteBase_collideInTheDir);
        tolua_function(tolua_S,"setSpriteDir",lua_woool_SpriteBase_setSpriteDir);
        tolua_function(tolua_S,"walkToPos",lua_woool_SpriteBase_walkToPos);
        tolua_function(tolua_S,"changeState",lua_woool_SpriteBase_changeState);
        tolua_function(tolua_S,"initRunStatus",lua_woool_SpriteBase_initRunStatus);
        tolua_function(tolua_S,"setFirstLoadRes",lua_woool_SpriteBase_setFirstLoadRes);
        tolua_function(tolua_S,"standed",lua_woool_SpriteBase_standed);
        tolua_function(tolua_S,"attackOneTime",lua_woool_SpriteBase_attackOneTime);
        tolua_function(tolua_S,"setBaseUrl",lua_woool_SpriteBase_setBaseUrl);
        tolua_function(tolua_S,"setMainSprite",lua_woool_SpriteBase_setMainSprite);
        tolua_function(tolua_S,"setGray",lua_woool_SpriteBase_setGray);
        tolua_function(tolua_S,"getType",lua_woool_SpriteBase_getType);
        tolua_function(tolua_S,"setCurrActionState",lua_woool_SpriteBase_setCurrActionState);
        tolua_function(tolua_S,"moveToPos",lua_woool_SpriteBase_moveToPos);
        tolua_function(tolua_S,"gotoDeath",lua_woool_SpriteBase_gotoDeath);
        tolua_function(tolua_S,"magicUpToPos",lua_woool_SpriteBase_magicUpToPos);
        tolua_function(tolua_S,"isTree",lua_woool_SpriteBase_isTree);
        tolua_function(tolua_S,"setSpriteOneDir",lua_woool_SpriteBase_setSpriteOneDir);
        tolua_function(tolua_S,"excavateToTheDir",lua_woool_SpriteBase_excavateToTheDir);
        tolua_function(tolua_S,"set5DirMode",lua_woool_SpriteBase_set5DirMode);
        tolua_function(tolua_S,"getMainSprite",lua_woool_SpriteBase_getMainSprite);
        tolua_function(tolua_S,"setTreeFlag",lua_woool_SpriteBase_setTreeFlag);
        tolua_function(tolua_S,"changeModeDisplay",lua_woool_SpriteBase_changeModeDisplay);
        tolua_function(tolua_S,"initWithFile",lua_woool_SpriteBase_initWithFile);
        tolua_function(tolua_S,"setColor",lua_woool_SpriteBase_setColor);
        tolua_function(tolua_S,"attackToPos",lua_woool_SpriteBase_attackToPos);
        tolua_function(tolua_S,"stopInTheTime",lua_woool_SpriteBase_stopInTheTime);
        tolua_function(tolua_S,"setDirByNowPoint",lua_woool_SpriteBase_setDirByNowPoint);
        tolua_function(tolua_S,"initAttackStatus",lua_woool_SpriteBase_initAttackStatus);
        tolua_function(tolua_S,"isTouchInside",lua_woool_SpriteBase_isTouchInside);
        tolua_function(tolua_S,"getLoadResTime",lua_woool_SpriteBase_getLoadResTime);
        tolua_function(tolua_S,"getResLoadStatus",lua_woool_SpriteBase_getResLoadStatus);
        tolua_function(tolua_S,"digToTheDir",lua_woool_SpriteBase_digToTheDir);
        tolua_function(tolua_S,"moveInTheDir",lua_woool_SpriteBase_moveInTheDir);
        tolua_function(tolua_S,"hasHurted",lua_woool_SpriteBase_hasHurted);
        tolua_function(tolua_S,"getCurrActionState",lua_woool_SpriteBase_getCurrActionState);
        tolua_function(tolua_S,"walkInTheDir",lua_woool_SpriteBase_walkInTheDir);
        tolua_function(tolua_S,"removeStread",lua_woool_SpriteBase_removeStread);
        tolua_function(tolua_S,"setActorFlag",lua_woool_SpriteBase_setActorFlag);
        tolua_function(tolua_S,"subCacheCount", lua_woool_SpriteBase_subCacheCount);
        tolua_function(tolua_S,"create", lua_woool_SpriteBase_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(SpriteBase).name();
    g_luaType[typeName] = "SpriteBase";
    g_typeCast["SpriteBase"] = "SpriteBase";
    return 1;
}

int lua_woool_HttpSprite_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"HttpSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        std::string arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "HttpSprite:create");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "HttpSprite:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_HttpSprite_create'", nullptr);
            return 0;
        }
        HttpSprite* ret = HttpSprite::create(arg0, arg1);
        object_to_luaval<HttpSprite>(tolua_S, "HttpSprite",(HttpSprite*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "HttpSprite:create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_HttpSprite_create'.",&tolua_err);
#endif
    return 0;
}
int lua_woool_HttpSprite_constructor(lua_State* tolua_S)
{
    int argc = 0;
    HttpSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_HttpSprite_constructor'", nullptr);
            return 0;
        }
        cobj = new HttpSprite();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"HttpSprite");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "HttpSprite:HttpSprite",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_woool_HttpSprite_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_woool_HttpSprite_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (HttpSprite)");
    return 0;
}

int lua_register_woool_HttpSprite(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"HttpSprite");
    tolua_cclass(tolua_S,"HttpSprite","HttpSprite","cc.Sprite",nullptr);

    tolua_beginmodule(tolua_S,"HttpSprite");
        tolua_function(tolua_S,"new",lua_woool_HttpSprite_constructor);
        tolua_function(tolua_S,"create", lua_woool_HttpSprite_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(HttpSprite).name();
    g_luaType[typeName] = "HttpSprite";
    g_typeCast["HttpSprite"] = "HttpSprite";
    return 1;
}

int lua_woool_SpriteCharacterBase_getSkillDownNode(lua_State* tolua_S)
{
    int argc = 0;
    SpriteCharacterBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteCharacterBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteCharacterBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteCharacterBase_getSkillDownNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteCharacterBase_getSkillDownNode'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->getSkillDownNode();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteCharacterBase:getSkillDownNode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteCharacterBase_getSkillDownNode'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteCharacterBase_getSkillNode(lua_State* tolua_S)
{
    int argc = 0;
    SpriteCharacterBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpriteCharacterBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpriteCharacterBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteCharacterBase_getSkillNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteCharacterBase_getSkillNode'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->getSkillNode();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteCharacterBase:getSkillNode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteCharacterBase_getSkillNode'.",&tolua_err);
#endif

    return 0;
}
static int lua_woool_SpriteCharacterBase_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (SpriteCharacterBase)");
    return 0;
}

int lua_register_woool_SpriteCharacterBase(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"SpriteCharacterBase");
    tolua_cclass(tolua_S,"SpriteCharacterBase","SpriteCharacterBase","SpriteBase",nullptr);

    tolua_beginmodule(tolua_S,"SpriteCharacterBase");
        tolua_function(tolua_S,"getSkillDownNode",lua_woool_SpriteCharacterBase_getSkillDownNode);
        tolua_function(tolua_S,"getSkillNode",lua_woool_SpriteCharacterBase_getSkillNode);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(SpriteCharacterBase).name();
    g_luaType[typeName] = "SpriteCharacterBase";
    g_typeCast["SpriteCharacterBase"] = "SpriteCharacterBase";
    return 1;
}

int lua_woool_UISpriteCharacter_playAction(lua_State* tolua_S)
{
    int argc = 0;
    UISpriteCharacter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UISpriteCharacter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UISpriteCharacter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_UISpriteCharacter_playAction'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        double arg0;
        Commen_ActionToDo arg1;
        Commen_Direction arg2;
        int arg3;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "UISpriteCharacter:playAction");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "UISpriteCharacter:playAction");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "UISpriteCharacter:playAction");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "UISpriteCharacter:playAction");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_UISpriteCharacter_playAction'", nullptr);
            return 0;
        }
        cobj->playAction(arg0, arg1, arg2, arg3);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 5) 
    {
        double arg0;
        Commen_ActionToDo arg1;
        Commen_Direction arg2;
        int arg3;
        double arg4;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "UISpriteCharacter:playAction");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "UISpriteCharacter:playAction");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "UISpriteCharacter:playAction");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "UISpriteCharacter:playAction");

        ok &= luaval_to_number(tolua_S, 6,&arg4, "UISpriteCharacter:playAction");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_UISpriteCharacter_playAction'", nullptr);
            return 0;
        }
        cobj->playAction(arg0, arg1, arg2, arg3, arg4);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UISpriteCharacter:playAction",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_UISpriteCharacter_playAction'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_UISpriteCharacter_doStanded(lua_State* tolua_S)
{
    int argc = 0;
    UISpriteCharacter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UISpriteCharacter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UISpriteCharacter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_UISpriteCharacter_doStanded'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_UISpriteCharacter_doStanded'", nullptr);
            return 0;
        }
        cobj->doStanded();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UISpriteCharacter:doStanded",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_UISpriteCharacter_doStanded'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_UISpriteCharacter_setHP(lua_State* tolua_S)
{
    int argc = 0;
    UISpriteCharacter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UISpriteCharacter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UISpriteCharacter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_UISpriteCharacter_setHP'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "UISpriteCharacter:setHP");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_UISpriteCharacter_setHP'", nullptr);
            return 0;
        }
        cobj->setHP(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UISpriteCharacter:setHP",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_UISpriteCharacter_setHP'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_UISpriteCharacter_insertBloodNode(lua_State* tolua_S)
{
    int argc = 0;
    UISpriteCharacter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UISpriteCharacter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UISpriteCharacter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_UISpriteCharacter_insertBloodNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "UISpriteCharacter:insertBloodNode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_UISpriteCharacter_insertBloodNode'", nullptr);
            return 0;
        }
        cobj->insertBloodNode(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UISpriteCharacter:insertBloodNode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_UISpriteCharacter_insertBloodNode'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_UISpriteCharacter_insertActionChild(lua_State* tolua_S)
{
    int argc = 0;
    UISpriteCharacter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UISpriteCharacter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UISpriteCharacter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_UISpriteCharacter_insertActionChild'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        SpriteBase* arg0;

        ok &= luaval_to_object<SpriteBase>(tolua_S, 2, "SpriteBase",&arg0, "UISpriteCharacter:insertActionChild");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_UISpriteCharacter_insertActionChild'", nullptr);
            return 0;
        }
        cobj->insertActionChild(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UISpriteCharacter:insertActionChild",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_UISpriteCharacter_insertActionChild'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_UISpriteCharacter_MagicOneTime_ex(lua_State* tolua_S)
{
    int argc = 0;
    UISpriteCharacter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UISpriteCharacter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UISpriteCharacter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_UISpriteCharacter_MagicOneTime_ex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        cocos2d::Point arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "UISpriteCharacter:MagicOneTime_ex");

        ok &= luaval_to_point(tolua_S, 3, &arg1, "UISpriteCharacter:MagicOneTime_ex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_UISpriteCharacter_MagicOneTime_ex'", nullptr);
            return 0;
        }
        bool ret = cobj->MagicOneTime_ex(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UISpriteCharacter:MagicOneTime_ex",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_UISpriteCharacter_MagicOneTime_ex'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_UISpriteCharacter_doSetOpacity(lua_State* tolua_S)
{
    int argc = 0;
    UISpriteCharacter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UISpriteCharacter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UISpriteCharacter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_UISpriteCharacter_doSetOpacity'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_UISpriteCharacter_doSetOpacity'", nullptr);
            return 0;
        }
        cobj->doSetOpacity();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UISpriteCharacter:doSetOpacity",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_UISpriteCharacter_doSetOpacity'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_UISpriteCharacter_walkInTheDir_ex(lua_State* tolua_S)
{
    int argc = 0;
    UISpriteCharacter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UISpriteCharacter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UISpriteCharacter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_UISpriteCharacter_walkInTheDir_ex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        double arg0;
        cocos2d::Point arg1;
        Commen_Direction arg2;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "UISpriteCharacter:walkInTheDir_ex");

        ok &= luaval_to_point(tolua_S, 3, &arg1, "UISpriteCharacter:walkInTheDir_ex");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "UISpriteCharacter:walkInTheDir_ex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_UISpriteCharacter_walkInTheDir_ex'", nullptr);
            return 0;
        }
        bool ret = cobj->walkInTheDir_ex(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UISpriteCharacter:walkInTheDir_ex",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_UISpriteCharacter_walkInTheDir_ex'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_UISpriteCharacter_setOpacity(lua_State* tolua_S)
{
    int argc = 0;
    UISpriteCharacter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UISpriteCharacter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UISpriteCharacter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_UISpriteCharacter_setOpacity'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0, "UISpriteCharacter:setOpacity");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_UISpriteCharacter_setOpacity'", nullptr);
            return 0;
        }
        cobj->setOpacity(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UISpriteCharacter:setOpacity",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_UISpriteCharacter_setOpacity'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_UISpriteCharacter_collideInTheDir(lua_State* tolua_S)
{
    int argc = 0;
    UISpriteCharacter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UISpriteCharacter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UISpriteCharacter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_UISpriteCharacter_collideInTheDir'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        double arg0;
        cocos2d::Point arg1;
        Commen_Direction arg2;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "UISpriteCharacter:collideInTheDir");

        ok &= luaval_to_point(tolua_S, 3, &arg1, "UISpriteCharacter:collideInTheDir");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "UISpriteCharacter:collideInTheDir");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_UISpriteCharacter_collideInTheDir'", nullptr);
            return 0;
        }
        bool ret = cobj->collideInTheDir(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UISpriteCharacter:collideInTheDir",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_UISpriteCharacter_collideInTheDir'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_UISpriteCharacter_moveInTheDir_ex(lua_State* tolua_S)
{
    int argc = 0;
    UISpriteCharacter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UISpriteCharacter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UISpriteCharacter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_UISpriteCharacter_moveInTheDir_ex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        double arg0;
        cocos2d::Point arg1;
        Commen_Direction arg2;
        double arg3;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "UISpriteCharacter:moveInTheDir_ex");

        ok &= luaval_to_point(tolua_S, 3, &arg1, "UISpriteCharacter:moveInTheDir_ex");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "UISpriteCharacter:moveInTheDir_ex");

        ok &= luaval_to_number(tolua_S, 5,&arg3, "UISpriteCharacter:moveInTheDir_ex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_UISpriteCharacter_moveInTheDir_ex'", nullptr);
            return 0;
        }
        bool ret = cobj->moveInTheDir_ex(arg0, arg1, arg2, arg3);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UISpriteCharacter:moveInTheDir_ex",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_UISpriteCharacter_moveInTheDir_ex'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_UISpriteCharacter_standed(lua_State* tolua_S)
{
    int argc = 0;
    UISpriteCharacter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UISpriteCharacter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UISpriteCharacter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_UISpriteCharacter_standed'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_UISpriteCharacter_standed'", nullptr);
            return 0;
        }
        bool ret = cobj->standed();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UISpriteCharacter:standed",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_UISpriteCharacter_standed'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_UISpriteCharacter_doSetOpacity_ex(lua_State* tolua_S)
{
    int argc = 0;
    UISpriteCharacter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UISpriteCharacter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UISpriteCharacter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_UISpriteCharacter_doSetOpacity_ex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_UISpriteCharacter_doSetOpacity_ex'", nullptr);
            return 0;
        }
        cobj->doSetOpacity_ex();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UISpriteCharacter:doSetOpacity_ex",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_UISpriteCharacter_doSetOpacity_ex'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_UISpriteCharacter_getBuffSkillNode(lua_State* tolua_S)
{
    int argc = 0;
    UISpriteCharacter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UISpriteCharacter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UISpriteCharacter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_UISpriteCharacter_getBuffSkillNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_UISpriteCharacter_getBuffSkillNode'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->getBuffSkillNode();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UISpriteCharacter:getBuffSkillNode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_UISpriteCharacter_getBuffSkillNode'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_UISpriteCharacter_getHP(lua_State* tolua_S)
{
    int argc = 0;
    UISpriteCharacter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UISpriteCharacter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UISpriteCharacter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_UISpriteCharacter_getHP'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_UISpriteCharacter_getHP'", nullptr);
            return 0;
        }
        int ret = cobj->getHP();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UISpriteCharacter:getHP",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_UISpriteCharacter_getHP'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_UISpriteCharacter_getSpeed(lua_State* tolua_S)
{
    int argc = 0;
    UISpriteCharacter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UISpriteCharacter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UISpriteCharacter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_UISpriteCharacter_getSpeed'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_UISpriteCharacter_getSpeed'", nullptr);
            return 0;
        }
        double ret = cobj->getSpeed();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UISpriteCharacter:getSpeed",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_UISpriteCharacter_getSpeed'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_UISpriteCharacter_getMaxHP(lua_State* tolua_S)
{
    int argc = 0;
    UISpriteCharacter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UISpriteCharacter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UISpriteCharacter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_UISpriteCharacter_getMaxHP'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_UISpriteCharacter_getMaxHP'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getMaxHP();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UISpriteCharacter:getMaxHP",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_UISpriteCharacter_getMaxHP'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_UISpriteCharacter_getSkillNode(lua_State* tolua_S)
{
    int argc = 0;
    UISpriteCharacter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UISpriteCharacter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UISpriteCharacter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_UISpriteCharacter_getSkillNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_UISpriteCharacter_getSkillNode'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->getSkillNode();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UISpriteCharacter:getSkillNode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_UISpriteCharacter_getSkillNode'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_UISpriteCharacter_setSpeed(lua_State* tolua_S)
{
    int argc = 0;
    UISpriteCharacter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UISpriteCharacter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UISpriteCharacter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_UISpriteCharacter_setSpeed'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "UISpriteCharacter:setSpeed");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_UISpriteCharacter_setSpeed'", nullptr);
            return 0;
        }
        cobj->setSpeed(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UISpriteCharacter:setSpeed",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_UISpriteCharacter_setSpeed'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_UISpriteCharacter_getSkillDownNode(lua_State* tolua_S)
{
    int argc = 0;
    UISpriteCharacter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UISpriteCharacter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UISpriteCharacter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_UISpriteCharacter_getSkillDownNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_UISpriteCharacter_getSkillDownNode'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->getSkillDownNode();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UISpriteCharacter:getSkillDownNode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_UISpriteCharacter_getSkillDownNode'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_UISpriteCharacter_setMaxHP(lua_State* tolua_S)
{
    int argc = 0;
    UISpriteCharacter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UISpriteCharacter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UISpriteCharacter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_UISpriteCharacter_setMaxHP'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "UISpriteCharacter:setMaxHP");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_UISpriteCharacter_setMaxHP'", nullptr);
            return 0;
        }
        cobj->setMaxHP(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UISpriteCharacter:setMaxHP",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_UISpriteCharacter_setMaxHP'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_UISpriteCharacter_removeStread(lua_State* tolua_S)
{
    int argc = 0;
    UISpriteCharacter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UISpriteCharacter",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UISpriteCharacter*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_UISpriteCharacter_removeStread'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_UISpriteCharacter_removeStread'", nullptr);
            return 0;
        }
        cobj->removeStread();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UISpriteCharacter:removeStread",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_UISpriteCharacter_removeStread'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_UISpriteCharacter_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UISpriteCharacter",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "UISpriteCharacter:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_UISpriteCharacter_create'", nullptr);
            return 0;
        }
        UISpriteCharacter* ret = UISpriteCharacter::create(arg0);
        object_to_luaval<UISpriteCharacter>(tolua_S, "UISpriteCharacter",(UISpriteCharacter*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "UISpriteCharacter:create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_UISpriteCharacter_create'.",&tolua_err);
#endif
    return 0;
}
int lua_woool_UISpriteCharacter_constructor(lua_State* tolua_S)
{
    int argc = 0;
    UISpriteCharacter* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_UISpriteCharacter_constructor'", nullptr);
            return 0;
        }
        cobj = new UISpriteCharacter();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"UISpriteCharacter");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UISpriteCharacter:UISpriteCharacter",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_woool_UISpriteCharacter_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_woool_UISpriteCharacter_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (UISpriteCharacter)");
    return 0;
}

int lua_register_woool_UISpriteCharacter(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"UISpriteCharacter");
    tolua_cclass(tolua_S,"UISpriteCharacter","UISpriteCharacter","SpriteCharacterBase",nullptr);

    tolua_beginmodule(tolua_S,"UISpriteCharacter");
        tolua_function(tolua_S,"new",lua_woool_UISpriteCharacter_constructor);
        tolua_function(tolua_S,"playAction",lua_woool_UISpriteCharacter_playAction);
        tolua_function(tolua_S,"doStanded",lua_woool_UISpriteCharacter_doStanded);
        tolua_function(tolua_S,"setHP",lua_woool_UISpriteCharacter_setHP);
        tolua_function(tolua_S,"insertBloodNode",lua_woool_UISpriteCharacter_insertBloodNode);
        tolua_function(tolua_S,"insertActionChild",lua_woool_UISpriteCharacter_insertActionChild);
        tolua_function(tolua_S,"MagicOneTime_ex",lua_woool_UISpriteCharacter_MagicOneTime_ex);
        tolua_function(tolua_S,"doSetOpacity",lua_woool_UISpriteCharacter_doSetOpacity);
        tolua_function(tolua_S,"walkInTheDir_ex",lua_woool_UISpriteCharacter_walkInTheDir_ex);
        tolua_function(tolua_S,"setOpacity",lua_woool_UISpriteCharacter_setOpacity);
        tolua_function(tolua_S,"collideInTheDir",lua_woool_UISpriteCharacter_collideInTheDir);
        tolua_function(tolua_S,"moveInTheDir_ex",lua_woool_UISpriteCharacter_moveInTheDir_ex);
        tolua_function(tolua_S,"standed",lua_woool_UISpriteCharacter_standed);
        tolua_function(tolua_S,"doSetOpacity_ex",lua_woool_UISpriteCharacter_doSetOpacity_ex);
        tolua_function(tolua_S,"getBuffSkillNode",lua_woool_UISpriteCharacter_getBuffSkillNode);
        tolua_function(tolua_S,"getHP",lua_woool_UISpriteCharacter_getHP);
        tolua_function(tolua_S,"getSpeed",lua_woool_UISpriteCharacter_getSpeed);
        tolua_function(tolua_S,"getMaxHP",lua_woool_UISpriteCharacter_getMaxHP);
        tolua_function(tolua_S,"getSkillNode",lua_woool_UISpriteCharacter_getSkillNode);
        tolua_function(tolua_S,"setSpeed",lua_woool_UISpriteCharacter_setSpeed);
        tolua_function(tolua_S,"getSkillDownNode",lua_woool_UISpriteCharacter_getSkillDownNode);
        tolua_function(tolua_S,"setMaxHP",lua_woool_UISpriteCharacter_setMaxHP);
        tolua_function(tolua_S,"removeStread",lua_woool_UISpriteCharacter_removeStread);
        tolua_function(tolua_S,"create", lua_woool_UISpriteCharacter_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(UISpriteCharacter).name();
    g_luaType[typeName] = "UISpriteCharacter";
    g_typeCast["UISpriteCharacter"] = "UISpriteCharacter";
    return 1;
}

int lua_woool_MirTextNode_setLineBreakWithoutSpace(lua_State* tolua_S)
{
    int argc = 0;
    MirTextNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirTextNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirTextNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MirTextNode_setLineBreakWithoutSpace'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "MirTextNode:setLineBreakWithoutSpace");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MirTextNode_setLineBreakWithoutSpace'", nullptr);
            return 0;
        }
        cobj->setLineBreakWithoutSpace(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirTextNode:setLineBreakWithoutSpace",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MirTextNode_setLineBreakWithoutSpace'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MirTextNode_getLettersCount(lua_State* tolua_S)
{
    int argc = 0;
    MirTextNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirTextNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirTextNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MirTextNode_getLettersCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MirTextNode_getLettersCount'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getLettersCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirTextNode:getLettersCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MirTextNode_getLettersCount'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MirTextNode_getOffset(lua_State* tolua_S)
{
    int argc = 0;
    MirTextNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirTextNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirTextNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MirTextNode_getOffset'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MirTextNode_getOffset'", nullptr);
            return 0;
        }
        cocos2d::Vec2 ret = cobj->getOffset();
        vec2_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirTextNode:getOffset",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MirTextNode_getOffset'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MirTextNode_setRangeColors(lua_State* tolua_S)
{
    int argc = 0;
    MirTextNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirTextNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirTextNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MirTextNode_setRangeColors'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Color3B arg0;
        int arg1;
        int arg2;

        ok &= luaval_to_color3b(tolua_S, 2, &arg0, "MirTextNode:setRangeColors");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "MirTextNode:setRangeColors");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "MirTextNode:setRangeColors");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MirTextNode_setRangeColors'", nullptr);
            return 0;
        }
        cobj->setRangeColors(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirTextNode:setRangeColors",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MirTextNode_setRangeColors'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MirTextNode_setText(lua_State* tolua_S)
{
    int argc = 0;
    MirTextNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirTextNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirTextNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MirTextNode_setText'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "MirTextNode:setText");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MirTextNode_setText'", nullptr);
            return 0;
        }
        cobj->setText(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirTextNode:setText",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MirTextNode_setText'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MirTextNode_resetDirty(lua_State* tolua_S)
{
    int argc = 0;
    MirTextNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirTextNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirTextNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MirTextNode_resetDirty'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MirTextNode_resetDirty'", nullptr);
            return 0;
        }
        cobj->resetDirty();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirTextNode:resetDirty",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MirTextNode_resetDirty'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MirTextNode_setOffset(lua_State* tolua_S)
{
    int argc = 0;
    MirTextNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirTextNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirTextNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MirTextNode_setOffset'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Vec2 arg0;

        ok &= luaval_to_vec2(tolua_S, 2, &arg0, "MirTextNode:setOffset");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MirTextNode_setOffset'", nullptr);
            return 0;
        }
        cobj->setOffset(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirTextNode:setOffset",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MirTextNode_setOffset'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MirTextNode_setString(lua_State* tolua_S)
{
    int argc = 0;
    MirTextNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirTextNode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirTextNode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MirTextNode_setString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "MirTextNode:setString");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MirTextNode_setString'", nullptr);
            return 0;
        }
        cobj->setString(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirTextNode:setString",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MirTextNode_setString'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MirTextNode_constructor(lua_State* tolua_S)
{
    int argc = 0;
    MirTextNode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        MirBatchDrawLabel* arg0;
        int arg1;

        ok &= luaval_to_object<MirBatchDrawLabel>(tolua_S, 2, "MirBatchDrawLabel",&arg0, "MirTextNode:MirTextNode");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "MirTextNode:MirTextNode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MirTextNode_constructor'", nullptr);
            return 0;
        }
        cobj = new MirTextNode(arg0, arg1);
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"MirTextNode");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirTextNode:MirTextNode",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MirTextNode_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_woool_MirTextNode_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (MirTextNode)");
    return 0;
}

int lua_register_woool_MirTextNode(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"MirTextNode");
    tolua_cclass(tolua_S,"MirTextNode","MirTextNode","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"MirTextNode");
        tolua_function(tolua_S,"new",lua_woool_MirTextNode_constructor);
        tolua_function(tolua_S,"setLineBreakWithoutSpace",lua_woool_MirTextNode_setLineBreakWithoutSpace);
        tolua_function(tolua_S,"getLettersCount",lua_woool_MirTextNode_getLettersCount);
        tolua_function(tolua_S,"getOffset",lua_woool_MirTextNode_getOffset);
        tolua_function(tolua_S,"setRangeColors",lua_woool_MirTextNode_setRangeColors);
        tolua_function(tolua_S,"setText",lua_woool_MirTextNode_setText);
        tolua_function(tolua_S,"resetDirty",lua_woool_MirTextNode_resetDirty);
        tolua_function(tolua_S,"setOffset",lua_woool_MirTextNode_setOffset);
        tolua_function(tolua_S,"setString",lua_woool_MirTextNode_setString);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(MirTextNode).name();
    g_luaType[typeName] = "MirTextNode";
    g_typeCast["MirTextNode"] = "MirTextNode";
    return 1;
}

int lua_woool_SpriteMonster_setIsOnAttackRide(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_setIsOnAttackRide'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "SpriteMonster:setIsOnAttackRide");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_setIsOnAttackRide'", nullptr);
            return 0;
        }
        cobj->setIsOnAttackRide(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:setIsOnAttackRide",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_setIsOnAttackRide'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_isChangeModeDisplay(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_isChangeModeDisplay'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_isChangeModeDisplay'", nullptr);
            return 0;
        }
        bool ret = cobj->isChangeModeDisplay();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:isChangeModeDisplay",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_isChangeModeDisplay'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_setVirtualOpacityNum(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_setVirtualOpacityNum'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "SpriteMonster:setVirtualOpacityNum");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_setVirtualOpacityNum'", nullptr);
            return 0;
        }
        cobj->setVirtualOpacityNum(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:setVirtualOpacityNum",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_setVirtualOpacityNum'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_resetShowHPosition(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_resetShowHPosition'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_resetShowHPosition'", nullptr);
            return 0;
        }
        cobj->resetShowHPosition();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:resetShowHPosition",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_resetShowHPosition'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_setVisibleNameAndBlood(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_setVisibleNameAndBlood'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "SpriteMonster:setVisibleNameAndBlood");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_setVisibleNameAndBlood'", nullptr);
            return 0;
        }
        cobj->setVisibleNameAndBlood(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:setVisibleNameAndBlood",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_setVisibleNameAndBlood'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_removeActionChild(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_removeActionChild'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        SpriteBase* arg0;

        ok &= luaval_to_object<SpriteBase>(tolua_S, 2, "SpriteBase",&arg0, "SpriteMonster:removeActionChild");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_removeActionChild'", nullptr);
            return 0;
        }
        cobj->removeActionChild(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:removeActionChild",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_removeActionChild'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_getServerTile(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_getServerTile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_getServerTile'", nullptr);
            return 0;
        }
        cocos2d::Point ret = cobj->getServerTile();
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:getServerTile",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_getServerTile'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_subBlood(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_subBlood'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "SpriteMonster:subBlood");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_subBlood'", nullptr);
            return 0;
        }
        cobj->subBlood(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:subBlood",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_subBlood'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_getFacNameBatchLabel(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_getFacNameBatchLabel'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_getFacNameBatchLabel'", nullptr);
            return 0;
        }
        MirTextNode* ret = cobj->getFacNameBatchLabel();
        object_to_luaval<MirTextNode>(tolua_S, "MirTextNode",(MirTextNode*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:getFacNameBatchLabel",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_getFacNameBatchLabel'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_getTitleNameBatchLabel(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_getTitleNameBatchLabel'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_getTitleNameBatchLabel'", nullptr);
            return 0;
        }
        MirTextNode* ret = cobj->getTitleNameBatchLabel();
        object_to_luaval<MirTextNode>(tolua_S, "MirTextNode",(MirTextNode*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:getTitleNameBatchLabel",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_getTitleNameBatchLabel'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_setTheSpeedUp(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_setTheSpeedUp'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int32_t arg0;

        ok &= luaval_to_int32(tolua_S, 2,&arg0, "SpriteMonster:setTheSpeedUp");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_setTheSpeedUp'", nullptr);
            return 0;
        }
        cobj->setTheSpeedUp(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:setTheSpeedUp",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_setTheSpeedUp'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_doSpecailAction(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_doSpecailAction'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        double arg0;
        int arg1;
        Commen_Direction arg2;
        std::string arg3;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpriteMonster:doSpecailAction");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "SpriteMonster:doSpecailAction");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "SpriteMonster:doSpecailAction");

        ok &= luaval_to_std_string(tolua_S, 5,&arg3, "SpriteMonster:doSpecailAction");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_doSpecailAction'", nullptr);
            return 0;
        }
        cobj->doSpecailAction(arg0, arg1, arg2, arg3);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:doSpecailAction",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_doSpecailAction'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_setWeaponId(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_setWeaponId'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "SpriteMonster:setWeaponId");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_setWeaponId'", nullptr);
            return 0;
        }
        cobj->setWeaponId(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:setWeaponId",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_setWeaponId'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_getBaseSpeed(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_getBaseSpeed'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_getBaseSpeed'", nullptr);
            return 0;
        }
        double ret = cobj->getBaseSpeed();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:getBaseSpeed",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_getBaseSpeed'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_setOnRide(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_setOnRide'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "SpriteMonster:setOnRide");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_setOnRide'", nullptr);
            return 0;
        }
        cobj->setOnRide(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:setOnRide",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_setOnRide'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_getWeaponId(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_getWeaponId'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_getWeaponId'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getWeaponId();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:getWeaponId",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_getWeaponId'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_onRestore(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_onRestore'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_onRestore'", nullptr);
            return 0;
        }
        cobj->onRestore();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:onRestore",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_onRestore'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_walkToPos(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_walkToPos'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        cocos2d::Point arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpriteMonster:walkToPos");

        ok &= luaval_to_point(tolua_S, 3, &arg1, "SpriteMonster:walkToPos");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_walkToPos'", nullptr);
            return 0;
        }
        cobj->walkToPos(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 3) 
    {
        double arg0;
        cocos2d::Point arg1;
        bool arg2;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpriteMonster:walkToPos");

        ok &= luaval_to_point(tolua_S, 3, &arg1, "SpriteMonster:walkToPos");

        ok &= luaval_to_boolean(tolua_S, 4,&arg2, "SpriteMonster:walkToPos");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_walkToPos'", nullptr);
            return 0;
        }
        cobj->walkToPos(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:walkToPos",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_walkToPos'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_setBaseSpeed(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_setBaseSpeed'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpriteMonster:setBaseSpeed");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_setBaseSpeed'", nullptr);
            return 0;
        }
        cobj->setBaseSpeed(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:setBaseSpeed",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_setBaseSpeed'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_attackOneTime(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_attackOneTime'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        cocos2d::Point arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpriteMonster:attackOneTime");

        ok &= luaval_to_point(tolua_S, 3, &arg1, "SpriteMonster:attackOneTime");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_attackOneTime'", nullptr);
            return 0;
        }
        bool ret = cobj->attackOneTime(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:attackOneTime",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_attackOneTime'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_setWingNodeVisble(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_setWingNodeVisble'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "SpriteMonster:setWingNodeVisble");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_setWingNodeVisble'", nullptr);
            return 0;
        }
        cobj->setWingNodeVisble(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:setWingNodeVisble",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_setWingNodeVisble'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_resetBloodHeight(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_resetBloodHeight'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_resetBloodHeight'", nullptr);
            return 0;
        }
        cobj->resetBloodHeight();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:resetBloodHeight",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_resetBloodHeight'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_changeDisplay(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_changeDisplay'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        double arg0;
        int arg1;
        Commen_Direction arg2;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpriteMonster:changeDisplay");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "SpriteMonster:changeDisplay");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "SpriteMonster:changeDisplay");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_changeDisplay'", nullptr);
            return 0;
        }
        bool ret = cobj->changeDisplay(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:changeDisplay",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_changeDisplay'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_setFacName(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_setFacName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "SpriteMonster:setFacName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_setFacName'", nullptr);
            return 0;
        }
        cobj->setFacName(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:setFacName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_setFacName'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_getSpeed(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_getSpeed'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_getSpeed'", nullptr);
            return 0;
        }
        double ret = cobj->getSpeed();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:getSpeed",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_getSpeed'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_setFacNameBatchLabel(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_setFacNameBatchLabel'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        MirTextNode* arg0;

        ok &= luaval_to_object<MirTextNode>(tolua_S, 2, "MirTextNode",&arg0, "SpriteMonster:setFacNameBatchLabel");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_setFacNameBatchLabel'", nullptr);
            return 0;
        }
        cobj->setFacNameBatchLabel(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:setFacNameBatchLabel",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_setFacNameBatchLabel'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_walkInTheDir_ex(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_walkInTheDir_ex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        double arg0;
        cocos2d::Point arg1;
        Commen_Direction arg2;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpriteMonster:walkInTheDir_ex");

        ok &= luaval_to_point(tolua_S, 3, &arg1, "SpriteMonster:walkInTheDir_ex");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "SpriteMonster:walkInTheDir_ex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_walkInTheDir_ex'", nullptr);
            return 0;
        }
        bool ret = cobj->walkInTheDir_ex(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:walkInTheDir_ex",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_walkInTheDir_ex'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_getAttack(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_getAttack'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_getAttack'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getAttack();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:getAttack",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_getAttack'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_getSeverPointsNum(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_getSeverPointsNum'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_getSeverPointsNum'", nullptr);
            return 0;
        }
        int ret = cobj->getSeverPointsNum();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:getSeverPointsNum",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_getSeverPointsNum'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_attackAction(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_attackAction'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        double arg0;
        int arg1;
        Commen_Direction arg2;
        int arg3;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpriteMonster:attackAction");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "SpriteMonster:attackAction");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "SpriteMonster:attackAction");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "SpriteMonster:attackAction");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_attackAction'", nullptr);
            return 0;
        }
        bool ret = cobj->attackAction(arg0, arg1, arg2, arg3);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:attackAction",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_attackAction'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_getTitleNode(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_getTitleNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_getTitleNode'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->getTitleNode();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:getTitleNode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_getTitleNode'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_standedby(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_standedby'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_standedby'", nullptr);
            return 0;
        }
        cobj->standedby();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:standedby",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_standedby'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_getTheName(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_getTheName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_getTheName'", nullptr);
            return 0;
        }
        std::string ret = cobj->getTheName();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:getTheName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_getTheName'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_getTopNode(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_getTopNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_getTopNode'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->getTopNode();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:getTopNode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_getTopNode'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_getSkillNode(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_getSkillNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_getSkillNode'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->getSkillNode();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:getSkillNode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_getSkillNode'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_setWrite(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_setWrite'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "SpriteMonster:setWrite");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_setWrite'", nullptr);
            return 0;
        }
        cobj->setWrite(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:setWrite",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_setWrite'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_setLockHeight(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_setLockHeight'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "SpriteMonster:setLockHeight");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_setLockHeight'", nullptr);
            return 0;
        }
        cobj->setLockHeight(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:setLockHeight",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_setLockHeight'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_removeActionChildByTag(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_removeActionChildByTag'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "SpriteMonster:removeActionChildByTag");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_removeActionChildByTag'", nullptr);
            return 0;
        }
        cobj->removeActionChildByTag(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:removeActionChildByTag",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_removeActionChildByTag'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_reloadRes(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_reloadRes'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_reloadRes'", nullptr);
            return 0;
        }
        cobj->reloadRes();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:reloadRes",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_reloadRes'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_setNameLabel(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_setNameLabel'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Node* arg0;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "SpriteMonster:setNameLabel");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_setNameLabel'", nullptr);
            return 0;
        }
        cobj->setNameLabel(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:setNameLabel",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_setNameLabel'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_getNameBatchLabel(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_getNameBatchLabel'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_getNameBatchLabel'", nullptr);
            return 0;
        }
        MirTextNode* ret = cobj->getNameBatchLabel();
        object_to_luaval<MirTextNode>(tolua_S, "MirTextNode",(MirTextNode*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:getNameBatchLabel",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_getNameBatchLabel'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_attackOneTime_ex(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_attackOneTime_ex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        cocos2d::Point arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpriteMonster:attackOneTime_ex");

        ok &= luaval_to_point(tolua_S, 3, &arg1, "SpriteMonster:attackOneTime_ex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_attackOneTime_ex'", nullptr);
            return 0;
        }
        bool ret = cobj->attackOneTime_ex(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:attackOneTime_ex",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_attackOneTime_ex'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_clearServerPoints(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_clearServerPoints'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_clearServerPoints'", nullptr);
            return 0;
        }
        cobj->clearServerPoints();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:clearServerPoints",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_clearServerPoints'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_disappeared(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_disappeared'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        double arg0;
        int arg1;
        Commen_Direction arg2;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpriteMonster:disappeared");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "SpriteMonster:disappeared");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "SpriteMonster:disappeared");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_disappeared'", nullptr);
            return 0;
        }
        bool ret = cobj->disappeared(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:disappeared",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_disappeared'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_gotoDeath(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_gotoDeath'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        Commen_Direction arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "SpriteMonster:gotoDeath");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_gotoDeath'", nullptr);
            return 0;
        }
        cobj->gotoDeath(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        Commen_Direction arg0;
        double arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "SpriteMonster:gotoDeath");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "SpriteMonster:gotoDeath");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_gotoDeath'", nullptr);
            return 0;
        }
        cobj->gotoDeath(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:gotoDeath",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_gotoDeath'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_magicUpToPos(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_magicUpToPos'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        cocos2d::Point arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpriteMonster:magicUpToPos");

        ok &= luaval_to_point(tolua_S, 3, &arg1, "SpriteMonster:magicUpToPos");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_magicUpToPos'", nullptr);
            return 0;
        }
        bool ret = cobj->magicUpToPos(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:magicUpToPos",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_magicUpToPos'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_getBuffSkillNode(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_getBuffSkillNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_getBuffSkillNode'", nullptr);
            return 0;
        }
        MapTileNode* ret = cobj->getBuffSkillNode();
        object_to_luaval<MapTileNode>(tolua_S, "MapTileNode",(MapTileNode*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:getBuffSkillNode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_getBuffSkillNode'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_getIsOnHighRide(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_getIsOnHighRide'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_getIsOnHighRide'", nullptr);
            return 0;
        }
        bool ret = cobj->getIsOnHighRide();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:getIsOnHighRide",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_getIsOnHighRide'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_showNameAndBlood(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_showNameAndBlood'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "SpriteMonster:showNameAndBlood");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_showNameAndBlood'", nullptr);
            return 0;
        }
        cobj->showNameAndBlood(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        bool arg0;
        int arg1;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "SpriteMonster:showNameAndBlood");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "SpriteMonster:showNameAndBlood");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_showNameAndBlood'", nullptr);
            return 0;
        }
        cobj->showNameAndBlood(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:showNameAndBlood",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_showNameAndBlood'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_getTheSpeedUp(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_getTheSpeedUp'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_getTheSpeedUp'", nullptr);
            return 0;
        }
        int32_t ret = cobj->getTheSpeedUp();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:getTheSpeedUp",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_getTheSpeedUp'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_setColor(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_setColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color3B arg0;

        ok &= luaval_to_color3b(tolua_S, 2, &arg0, "SpriteMonster:setColor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_setColor'", nullptr);
            return 0;
        }
        cobj->setColor(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:setColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_setColor'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_getNameLabel(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_getNameLabel'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_getNameLabel'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->getNameLabel();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:getNameLabel",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_getNameLabel'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_setNameAndBloodPos(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_setNameAndBloodPos'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "SpriteMonster:setNameAndBloodPos");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_setNameAndBloodPos'", nullptr);
            return 0;
        }
        cobj->setNameAndBloodPos(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        bool arg0;
        int arg1;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "SpriteMonster:setNameAndBloodPos");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "SpriteMonster:setNameAndBloodPos");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_setNameAndBloodPos'", nullptr);
            return 0;
        }
        cobj->setNameAndBloodPos(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 3) 
    {
        bool arg0;
        int arg1;
        int arg2;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "SpriteMonster:setNameAndBloodPos");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "SpriteMonster:setNameAndBloodPos");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "SpriteMonster:setNameAndBloodPos");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_setNameAndBloodPos'", nullptr);
            return 0;
        }
        cobj->setNameAndBloodPos(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:setNameAndBloodPos",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_setNameAndBloodPos'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_setSpeed(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_setSpeed'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpriteMonster:setSpeed");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_setSpeed'", nullptr);
            return 0;
        }
        cobj->setSpeed(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:setSpeed",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_setSpeed'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_getSkillDownNode(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_getSkillDownNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_getSkillDownNode'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->getSkillDownNode();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:getSkillDownNode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_getSkillDownNode'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_setNameBatchLabel(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_setNameBatchLabel'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        MirTextNode* arg0;

        ok &= luaval_to_object<MirTextNode>(tolua_S, 2, "MirTextNode",&arg0, "SpriteMonster:setNameBatchLabel");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_setNameBatchLabel'", nullptr);
            return 0;
        }
        cobj->setNameBatchLabel(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:setNameBatchLabel",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_setNameBatchLabel'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_setTitleName(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_setTitleName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "SpriteMonster:setTitleName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_setTitleName'", nullptr);
            return 0;
        }
        cobj->setTitleName(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:setTitleName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_setTitleName'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_getFacName(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_getFacName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_getFacName'", nullptr);
            return 0;
        }
        std::string ret = cobj->getFacName();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:getFacName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_getFacName'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_getTitleName(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_getTitleName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_getTitleName'", nullptr);
            return 0;
        }
        std::string ret = cobj->getTitleName();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:getTitleName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_getTitleName'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_appeared(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_appeared'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        double arg0;
        int arg1;
        Commen_Direction arg2;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpriteMonster:appeared");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "SpriteMonster:appeared");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "SpriteMonster:appeared");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_appeared'", nullptr);
            return 0;
        }
        bool ret = cobj->appeared(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:appeared",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_appeared'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_setHP(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_setHP'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "SpriteMonster:setHP");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_setHP'", nullptr);
            return 0;
        }
        cobj->setHP(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:setHP",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_setHP'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_setTopNode(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_setTopNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Node* arg0;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "SpriteMonster:setTopNode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_setTopNode'", nullptr);
            return 0;
        }
        cobj->setTopNode(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:setTopNode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_setTopNode'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_MagicOneTime_ex(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_MagicOneTime_ex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        cocos2d::Point arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpriteMonster:MagicOneTime_ex");

        ok &= luaval_to_point(tolua_S, 3, &arg1, "SpriteMonster:MagicOneTime_ex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_MagicOneTime_ex'", nullptr);
            return 0;
        }
        bool ret = cobj->MagicOneTime_ex(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:MagicOneTime_ex",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_MagicOneTime_ex'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_setDownNode(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_setDownNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Node* arg0;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "SpriteMonster:setDownNode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_setDownNode'", nullptr);
            return 0;
        }
        cobj->setDownNode(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:setDownNode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_setDownNode'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_setMonsterId(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_setMonsterId'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "SpriteMonster:setMonsterId");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_setMonsterId'", nullptr);
            return 0;
        }
        cobj->setMonsterId(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:setMonsterId",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_setMonsterId'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_setTitleNameBatchLabel(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_setTitleNameBatchLabel'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        MirTextNode* arg0;

        ok &= luaval_to_object<MirTextNode>(tolua_S, 2, "MirTextNode",&arg0, "SpriteMonster:setTitleNameBatchLabel");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_setTitleNameBatchLabel'", nullptr);
            return 0;
        }
        cobj->setTitleNameBatchLabel(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:setTitleNameBatchLabel",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_setTitleNameBatchLabel'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_visit(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_visit'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Renderer* arg0;
        cocos2d::Mat4 arg1;
        unsigned int arg2;

        ok &= luaval_to_object<cocos2d::Renderer>(tolua_S, 2, "cc.Renderer",&arg0, "SpriteMonster:visit");

        ok &= luaval_to_mat4(tolua_S, 3, &arg1, "SpriteMonster:visit");

        ok &= luaval_to_uint32(tolua_S, 4,&arg2, "SpriteMonster:visit");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_visit'", nullptr);
            return 0;
        }
        cobj->visit(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:visit",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_visit'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_reloadPosition(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_reloadPosition'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_reloadPosition'", nullptr);
            return 0;
        }
        cobj->reloadPosition();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:reloadPosition",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_reloadPosition'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_setServerTile(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_setServerTile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;

        ok &= luaval_to_point(tolua_S, 2, &arg0, "SpriteMonster:setServerTile");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_setServerTile'", nullptr);
            return 0;
        }
        cobj->setServerTile(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:setServerTile",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_setServerTile'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_hasServerPoints(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_hasServerPoints'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_hasServerPoints'", nullptr);
            return 0;
        }
        bool ret = cobj->hasServerPoints();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:hasServerPoints",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_hasServerPoints'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_standed(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_standed'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_standed'", nullptr);
            return 0;
        }
        bool ret = cobj->standed();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:standed",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_standed'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_isAlive(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_isAlive'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_isAlive'", nullptr);
            return 0;
        }
        bool ret = cobj->isAlive();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:isAlive",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_isAlive'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_setNeedShowName(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_setNeedShowName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "SpriteMonster:setNeedShowName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_setNeedShowName'", nullptr);
            return 0;
        }
        cobj->setNeedShowName(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:setNeedShowName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_setNeedShowName'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_doSetOpacity_ex(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_doSetOpacity_ex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_doSetOpacity_ex'", nullptr);
            return 0;
        }
        cobj->doSetOpacity_ex();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:doSetOpacity_ex",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_doSetOpacity_ex'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_getDownNode(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_getDownNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_getDownNode'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->getDownNode();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:getDownNode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_getDownNode'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_getNeedShowName(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_getNeedShowName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_getNeedShowName'", nullptr);
            return 0;
        }
        bool ret = cobj->getNeedShowName();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:getNeedShowName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_getNeedShowName'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_attackToPos(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_attackToPos'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        cocos2d::Point arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpriteMonster:attackToPos");

        ok &= luaval_to_point(tolua_S, 3, &arg1, "SpriteMonster:attackToPos");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_attackToPos'", nullptr);
            return 0;
        }
        bool ret = cobj->attackToPos(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:attackToPos",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_attackToPos'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_stopInTheTime(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_stopInTheTime'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_stopInTheTime'", nullptr);
            return 0;
        }
        cobj->stopInTheTime();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:stopInTheTime",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_stopInTheTime'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_getMaxHP(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_getMaxHP'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_getMaxHP'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getMaxHP();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:getMaxHP",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_getMaxHP'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_getMonsterId(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_getMonsterId'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_getMonsterId'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getMonsterId();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:getMonsterId",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_getMonsterId'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_hasHurted(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_hasHurted'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        double arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpriteMonster:hasHurted");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "SpriteMonster:hasHurted");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_hasHurted'", nullptr);
            return 0;
        }
        cobj->hasHurted(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:hasHurted",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_hasHurted'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_setMaxHP(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_setMaxHP'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "SpriteMonster:setMaxHP");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_setMaxHP'", nullptr);
            return 0;
        }
        cobj->setMaxHP(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:setMaxHP",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_setMaxHP'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_getOnRide(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_getOnRide'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_getOnRide'", nullptr);
            return 0;
        }
        bool ret = cobj->getOnRide();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:getOnRide",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_getOnRide'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_initOrderByDir(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_initOrderByDir'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        SpriteBase* arg0;
        Commen_Direction arg1;

        ok &= luaval_to_object<SpriteBase>(tolua_S, 2, "SpriteBase",&arg0, "SpriteMonster:initOrderByDir");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "SpriteMonster:initOrderByDir");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_initOrderByDir'", nullptr);
            return 0;
        }
        cobj->initOrderByDir(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:initOrderByDir",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_initOrderByDir'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_doStanded(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_doStanded'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_doStanded'", nullptr);
            return 0;
        }
        cobj->doStanded();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:doStanded",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_doStanded'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_changeModeDisplay(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_changeModeDisplay'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        bool arg0;
        std::string arg1;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "SpriteMonster:changeModeDisplay");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "SpriteMonster:changeModeDisplay");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_changeModeDisplay'", nullptr);
            return 0;
        }
        cobj->changeModeDisplay(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:changeModeDisplay",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_changeModeDisplay'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_DoMagicWithoutAction(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_DoMagicWithoutAction'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;

        ok &= luaval_to_point(tolua_S, 2, &arg0, "SpriteMonster:DoMagicWithoutAction");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_DoMagicWithoutAction'", nullptr);
            return 0;
        }
        bool ret = cobj->DoMagicWithoutAction(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:DoMagicWithoutAction",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_DoMagicWithoutAction'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_doSetOpacity(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_doSetOpacity'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_doSetOpacity'", nullptr);
            return 0;
        }
        cobj->doSetOpacity();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:doSetOpacity",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_doSetOpacity'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_setTheName(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_setTheName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "SpriteMonster:setTheName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_setTheName'", nullptr);
            return 0;
        }
        cobj->setTheName(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:setTheName",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_setTheName'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_setAttack(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_setAttack'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "SpriteMonster:setAttack");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_setAttack'", nullptr);
            return 0;
        }
        cobj->setAttack(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:setAttack",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_setAttack'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_setTitleNode(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_setTitleNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Node* arg0;

        ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "SpriteMonster:setTitleNode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_setTitleNode'", nullptr);
            return 0;
        }
        cobj->setTitleNode(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:setTitleNode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_setTitleNode'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_getLevel(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_getLevel'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_getLevel'", nullptr);
            return 0;
        }
        int ret = cobj->getLevel();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:getLevel",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_getLevel'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_setNeedHide(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_setNeedHide'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "SpriteMonster:setNeedHide");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_setNeedHide'", nullptr);
            return 0;
        }
        cobj->setNeedHide(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:setNeedHide",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_setNeedHide'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_removeServerPoint(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_removeServerPoint'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_removeServerPoint'", nullptr);
            return 0;
        }
        cobj->removeServerPoint();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:removeServerPoint",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_removeServerPoint'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_setGray(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_setGray'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "SpriteMonster:setGray");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_setGray'", nullptr);
            return 0;
        }
        cobj->setGray(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:setGray",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_setGray'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_setLevel(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_setLevel'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "SpriteMonster:setLevel");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_setLevel'", nullptr);
            return 0;
        }
        cobj->setLevel(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:setLevel",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_setLevel'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_getNeedHide(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_getNeedHide'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_getNeedHide'", nullptr);
            return 0;
        }
        bool ret = cobj->getNeedHide();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:getNeedHide",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_getNeedHide'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_magicAction(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_magicAction'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        double arg0;
        int arg1;
        Commen_Direction arg2;
        int arg3;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpriteMonster:magicAction");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "SpriteMonster:magicAction");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "SpriteMonster:magicAction");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "SpriteMonster:magicAction");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_magicAction'", nullptr);
            return 0;
        }
        bool ret = cobj->magicAction(arg0, arg1, arg2, arg3);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:magicAction",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_magicAction'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_initWithFileExt(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_initWithFileExt'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "SpriteMonster:initWithFileExt");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_initWithFileExt'", nullptr);
            return 0;
        }
        bool ret = cobj->initWithFileExt(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:initWithFileExt",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_initWithFileExt'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_getHP(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_getHP'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_getHP'", nullptr);
            return 0;
        }
        int ret = cobj->getHP();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:getHP",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_getHP'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_onRetain(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_onRetain'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_onRetain'", nullptr);
            return 0;
        }
        cobj->onRetain();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:onRetain",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_onRetain'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_setBuffSkillNode(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_setBuffSkillNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        MapTileNode* arg0;

        ok &= luaval_to_object<MapTileNode>(tolua_S, 2, "MapTileNode",&arg0, "SpriteMonster:setBuffSkillNode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_setBuffSkillNode'", nullptr);
            return 0;
        }
        cobj->setBuffSkillNode(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:setBuffSkillNode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_setBuffSkillNode'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_setShow_H(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_setShow_H'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "SpriteMonster:setShow_H");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_setShow_H'", nullptr);
            return 0;
        }
        cobj->setShow_H(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:setShow_H",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_setShow_H'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_setIsOnHighRide(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_setIsOnHighRide'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "SpriteMonster:setIsOnHighRide");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_setIsOnHighRide'", nullptr);
            return 0;
        }
        cobj->setIsOnHighRide(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:setIsOnHighRide",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_setIsOnHighRide'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_setServerTilePosByTile(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_setServerTilePosByTile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        double arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpriteMonster:setServerTilePosByTile");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "SpriteMonster:setServerTilePosByTile");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_setServerTilePosByTile'", nullptr);
            return 0;
        }
        cobj->setServerTilePosByTile(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:setServerTilePosByTile",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_setServerTilePosByTile'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_setVisible(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_setVisible'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "SpriteMonster:setVisible");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_setVisible'", nullptr);
            return 0;
        }
        cobj->setVisible(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:setVisible",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_setVisible'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_reCalcShowH(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_reCalcShowH'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_reCalcShowH'", nullptr);
            return 0;
        }
        cobj->reCalcShowH();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:reCalcShowH",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_reCalcShowH'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_doStandedAction(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_doStandedAction'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_doStandedAction'", nullptr);
            return 0;
        }
        cobj->doStandedAction();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:doStandedAction",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_doStandedAction'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_getIsOnAttackRide(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_getIsOnAttackRide'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_getIsOnAttackRide'", nullptr);
            return 0;
        }
        bool ret = cobj->getIsOnAttackRide();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:getIsOnAttackRide",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_getIsOnAttackRide'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_walkInTheDir(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpriteMonster_walkInTheDir'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        double arg0;
        cocos2d::Point arg1;
        Commen_Direction arg2;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpriteMonster:walkInTheDir");

        ok &= luaval_to_point(tolua_S, 3, &arg1, "SpriteMonster:walkInTheDir");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "SpriteMonster:walkInTheDir");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_walkInTheDir'", nullptr);
            return 0;
        }
        bool ret = cobj->walkInTheDir(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:walkInTheDir",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_walkInTheDir'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpriteMonster_setHideCenterRect(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "SpriteMonster:setHideCenterRect");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_setHideCenterRect'", nullptr);
            return 0;
        }
        SpriteMonster::setHideCenterRect(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "SpriteMonster:setHideCenterRect",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_setHideCenterRect'.",&tolua_err);
#endif
    return 0;
}
int lua_woool_SpriteMonster_getMonstersCountOnRect(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        cocos2d::Rect arg0;
        ok &= luaval_to_rect(tolua_S, 2, &arg0, "SpriteMonster:getMonstersCountOnRect");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_getMonstersCountOnRect'", nullptr);
            return 0;
        }
        int ret = SpriteMonster::getMonstersCountOnRect(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "SpriteMonster:getMonstersCountOnRect",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_getMonstersCountOnRect'.",&tolua_err);
#endif
    return 0;
}
int lua_woool_SpriteMonster_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "SpriteMonster:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_create'", nullptr);
            return 0;
        }
        SpriteMonster* ret = SpriteMonster::create(arg0);
        object_to_luaval<SpriteMonster>(tolua_S, "SpriteMonster",(SpriteMonster*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "SpriteMonster:create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_create'.",&tolua_err);
#endif
    return 0;
}
int lua_woool_SpriteMonster_clearMapTile(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_clearMapTile'", nullptr);
            return 0;
        }
        SpriteMonster::clearMapTile();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "SpriteMonster:clearMapTile",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_clearMapTile'.",&tolua_err);
#endif
    return 0;
}
int lua_woool_SpriteMonster_setMaxNumOneTile(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"SpriteMonster",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "SpriteMonster:setMaxNumOneTile");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_setMaxNumOneTile'", nullptr);
            return 0;
        }
        SpriteMonster::setMaxNumOneTile(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "SpriteMonster:setMaxNumOneTile",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_setMaxNumOneTile'.",&tolua_err);
#endif
    return 0;
}
int lua_woool_SpriteMonster_constructor(lua_State* tolua_S)
{
    int argc = 0;
    SpriteMonster* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpriteMonster_constructor'", nullptr);
            return 0;
        }
        cobj = new SpriteMonster();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"SpriteMonster");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpriteMonster:SpriteMonster",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpriteMonster_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_woool_SpriteMonster_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (SpriteMonster)");
    return 0;
}

int lua_register_woool_SpriteMonster(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"SpriteMonster");
    tolua_cclass(tolua_S,"SpriteMonster","SpriteMonster","SpriteCharacterBase",nullptr);

    tolua_beginmodule(tolua_S,"SpriteMonster");
        tolua_function(tolua_S,"new",lua_woool_SpriteMonster_constructor);
        tolua_function(tolua_S,"setIsOnAttackRide",lua_woool_SpriteMonster_setIsOnAttackRide);
        tolua_function(tolua_S,"isChangeModeDisplay",lua_woool_SpriteMonster_isChangeModeDisplay);
        tolua_function(tolua_S,"setVirtualOpacityNum",lua_woool_SpriteMonster_setVirtualOpacityNum);
        tolua_function(tolua_S,"resetShowHPosition",lua_woool_SpriteMonster_resetShowHPosition);
        tolua_function(tolua_S,"setVisibleNameAndBlood",lua_woool_SpriteMonster_setVisibleNameAndBlood);
        tolua_function(tolua_S,"removeActionChild",lua_woool_SpriteMonster_removeActionChild);
        tolua_function(tolua_S,"getServerTile",lua_woool_SpriteMonster_getServerTile);
        tolua_function(tolua_S,"subBlood",lua_woool_SpriteMonster_subBlood);
        tolua_function(tolua_S,"getFacNameBatchLabel",lua_woool_SpriteMonster_getFacNameBatchLabel);
        tolua_function(tolua_S,"getTitleNameBatchLabel",lua_woool_SpriteMonster_getTitleNameBatchLabel);
        tolua_function(tolua_S,"setTheSpeedUp",lua_woool_SpriteMonster_setTheSpeedUp);
        tolua_function(tolua_S,"doSpecailAction",lua_woool_SpriteMonster_doSpecailAction);
        tolua_function(tolua_S,"setWeaponId",lua_woool_SpriteMonster_setWeaponId);
        tolua_function(tolua_S,"getBaseSpeed",lua_woool_SpriteMonster_getBaseSpeed);
        tolua_function(tolua_S,"setOnRide",lua_woool_SpriteMonster_setOnRide);
        tolua_function(tolua_S,"getWeaponId",lua_woool_SpriteMonster_getWeaponId);
        tolua_function(tolua_S,"onRestore",lua_woool_SpriteMonster_onRestore);
        tolua_function(tolua_S,"walkToPos",lua_woool_SpriteMonster_walkToPos);
        tolua_function(tolua_S,"setBaseSpeed",lua_woool_SpriteMonster_setBaseSpeed);
        tolua_function(tolua_S,"attackOneTime",lua_woool_SpriteMonster_attackOneTime);
        tolua_function(tolua_S,"setWingNodeVisble",lua_woool_SpriteMonster_setWingNodeVisble);
        tolua_function(tolua_S,"resetBloodHeight",lua_woool_SpriteMonster_resetBloodHeight);
        tolua_function(tolua_S,"changeDisplay",lua_woool_SpriteMonster_changeDisplay);
        tolua_function(tolua_S,"setFacName",lua_woool_SpriteMonster_setFacName);
        tolua_function(tolua_S,"getSpeed",lua_woool_SpriteMonster_getSpeed);
        tolua_function(tolua_S,"setFacNameBatchLabel",lua_woool_SpriteMonster_setFacNameBatchLabel);
        tolua_function(tolua_S,"walkInTheDir_ex",lua_woool_SpriteMonster_walkInTheDir_ex);
        tolua_function(tolua_S,"getAttack",lua_woool_SpriteMonster_getAttack);
        tolua_function(tolua_S,"getSeverPointsNum",lua_woool_SpriteMonster_getSeverPointsNum);
        tolua_function(tolua_S,"attackAction",lua_woool_SpriteMonster_attackAction);
        tolua_function(tolua_S,"getTitleNode",lua_woool_SpriteMonster_getTitleNode);
        tolua_function(tolua_S,"standedby",lua_woool_SpriteMonster_standedby);
        tolua_function(tolua_S,"getTheName",lua_woool_SpriteMonster_getTheName);
        tolua_function(tolua_S,"getTopNode",lua_woool_SpriteMonster_getTopNode);
        tolua_function(tolua_S,"getSkillNode",lua_woool_SpriteMonster_getSkillNode);
        tolua_function(tolua_S,"setWrite",lua_woool_SpriteMonster_setWrite);
        tolua_function(tolua_S,"setLockHeight",lua_woool_SpriteMonster_setLockHeight);
        tolua_function(tolua_S,"removeActionChildByTag",lua_woool_SpriteMonster_removeActionChildByTag);
        tolua_function(tolua_S,"reloadRes",lua_woool_SpriteMonster_reloadRes);
        tolua_function(tolua_S,"setNameLabel",lua_woool_SpriteMonster_setNameLabel);
        tolua_function(tolua_S,"getNameBatchLabel",lua_woool_SpriteMonster_getNameBatchLabel);
        tolua_function(tolua_S,"attackOneTime_ex",lua_woool_SpriteMonster_attackOneTime_ex);
        tolua_function(tolua_S,"clearServerPoints",lua_woool_SpriteMonster_clearServerPoints);
        tolua_function(tolua_S,"disappeared",lua_woool_SpriteMonster_disappeared);
        tolua_function(tolua_S,"gotoDeath",lua_woool_SpriteMonster_gotoDeath);
        tolua_function(tolua_S,"magicUpToPos",lua_woool_SpriteMonster_magicUpToPos);
        tolua_function(tolua_S,"getBuffSkillNode",lua_woool_SpriteMonster_getBuffSkillNode);
        tolua_function(tolua_S,"getIsOnHighRide",lua_woool_SpriteMonster_getIsOnHighRide);
        tolua_function(tolua_S,"showNameAndBlood",lua_woool_SpriteMonster_showNameAndBlood);
        tolua_function(tolua_S,"getTheSpeedUp",lua_woool_SpriteMonster_getTheSpeedUp);
        tolua_function(tolua_S,"setColor",lua_woool_SpriteMonster_setColor);
        tolua_function(tolua_S,"getNameLabel",lua_woool_SpriteMonster_getNameLabel);
        tolua_function(tolua_S,"setNameAndBloodPos",lua_woool_SpriteMonster_setNameAndBloodPos);
        tolua_function(tolua_S,"setSpeed",lua_woool_SpriteMonster_setSpeed);
        tolua_function(tolua_S,"getSkillDownNode",lua_woool_SpriteMonster_getSkillDownNode);
        tolua_function(tolua_S,"setNameBatchLabel",lua_woool_SpriteMonster_setNameBatchLabel);
        tolua_function(tolua_S,"setTitleName",lua_woool_SpriteMonster_setTitleName);
        tolua_function(tolua_S,"getFacName",lua_woool_SpriteMonster_getFacName);
        tolua_function(tolua_S,"getTitleName",lua_woool_SpriteMonster_getTitleName);
        tolua_function(tolua_S,"appeared",lua_woool_SpriteMonster_appeared);
        tolua_function(tolua_S,"setHP",lua_woool_SpriteMonster_setHP);
        tolua_function(tolua_S,"setTopNode",lua_woool_SpriteMonster_setTopNode);
        tolua_function(tolua_S,"MagicOneTime_ex",lua_woool_SpriteMonster_MagicOneTime_ex);
        tolua_function(tolua_S,"setDownNode",lua_woool_SpriteMonster_setDownNode);
        tolua_function(tolua_S,"setMonsterId",lua_woool_SpriteMonster_setMonsterId);
        tolua_function(tolua_S,"setTitleNameBatchLabel",lua_woool_SpriteMonster_setTitleNameBatchLabel);
        tolua_function(tolua_S,"visit",lua_woool_SpriteMonster_visit);
        tolua_function(tolua_S,"reloadPosition",lua_woool_SpriteMonster_reloadPosition);
        tolua_function(tolua_S,"setServerTile",lua_woool_SpriteMonster_setServerTile);
        tolua_function(tolua_S,"hasServerPoints",lua_woool_SpriteMonster_hasServerPoints);
        tolua_function(tolua_S,"standed",lua_woool_SpriteMonster_standed);
        tolua_function(tolua_S,"isAlive",lua_woool_SpriteMonster_isAlive);
        tolua_function(tolua_S,"setNeedShowName",lua_woool_SpriteMonster_setNeedShowName);
        tolua_function(tolua_S,"doSetOpacity_ex",lua_woool_SpriteMonster_doSetOpacity_ex);
        tolua_function(tolua_S,"getDownNode",lua_woool_SpriteMonster_getDownNode);
        tolua_function(tolua_S,"getNeedShowName",lua_woool_SpriteMonster_getNeedShowName);
        tolua_function(tolua_S,"attackToPos",lua_woool_SpriteMonster_attackToPos);
        tolua_function(tolua_S,"stopInTheTime",lua_woool_SpriteMonster_stopInTheTime);
        tolua_function(tolua_S,"getMaxHP",lua_woool_SpriteMonster_getMaxHP);
        tolua_function(tolua_S,"getMonsterId",lua_woool_SpriteMonster_getMonsterId);
        tolua_function(tolua_S,"hasHurted",lua_woool_SpriteMonster_hasHurted);
        tolua_function(tolua_S,"setMaxHP",lua_woool_SpriteMonster_setMaxHP);
        tolua_function(tolua_S,"getOnRide",lua_woool_SpriteMonster_getOnRide);
        tolua_function(tolua_S,"initOrderByDir",lua_woool_SpriteMonster_initOrderByDir);
        tolua_function(tolua_S,"doStanded",lua_woool_SpriteMonster_doStanded);
        tolua_function(tolua_S,"changeModeDisplay",lua_woool_SpriteMonster_changeModeDisplay);
        tolua_function(tolua_S,"DoMagicWithoutAction",lua_woool_SpriteMonster_DoMagicWithoutAction);
        tolua_function(tolua_S,"doSetOpacity",lua_woool_SpriteMonster_doSetOpacity);
        tolua_function(tolua_S,"setTheName",lua_woool_SpriteMonster_setTheName);
        tolua_function(tolua_S,"setAttack",lua_woool_SpriteMonster_setAttack);
        tolua_function(tolua_S,"setTitleNode",lua_woool_SpriteMonster_setTitleNode);
        tolua_function(tolua_S,"getLevel",lua_woool_SpriteMonster_getLevel);
        tolua_function(tolua_S,"setNeedHide",lua_woool_SpriteMonster_setNeedHide);
        tolua_function(tolua_S,"removeServerPoint",lua_woool_SpriteMonster_removeServerPoint);
        tolua_function(tolua_S,"setGray",lua_woool_SpriteMonster_setGray);
        tolua_function(tolua_S,"setLevel",lua_woool_SpriteMonster_setLevel);
        tolua_function(tolua_S,"getNeedHide",lua_woool_SpriteMonster_getNeedHide);
        tolua_function(tolua_S,"magicAction",lua_woool_SpriteMonster_magicAction);
        tolua_function(tolua_S,"initWithFileExt",lua_woool_SpriteMonster_initWithFileExt);
        tolua_function(tolua_S,"getHP",lua_woool_SpriteMonster_getHP);
        tolua_function(tolua_S,"onRetain",lua_woool_SpriteMonster_onRetain);
        tolua_function(tolua_S,"setBuffSkillNode",lua_woool_SpriteMonster_setBuffSkillNode);
        tolua_function(tolua_S,"setShow_H",lua_woool_SpriteMonster_setShow_H);
        tolua_function(tolua_S,"setIsOnHighRide",lua_woool_SpriteMonster_setIsOnHighRide);
        tolua_function(tolua_S,"setServerTilePosByTile",lua_woool_SpriteMonster_setServerTilePosByTile);
        tolua_function(tolua_S,"setVisible",lua_woool_SpriteMonster_setVisible);
        tolua_function(tolua_S,"reCalcShowH",lua_woool_SpriteMonster_reCalcShowH);
        tolua_function(tolua_S,"doStandedAction",lua_woool_SpriteMonster_doStandedAction);
        tolua_function(tolua_S,"getIsOnAttackRide",lua_woool_SpriteMonster_getIsOnAttackRide);
        tolua_function(tolua_S,"walkInTheDir",lua_woool_SpriteMonster_walkInTheDir);
        tolua_function(tolua_S,"setHideCenterRect", lua_woool_SpriteMonster_setHideCenterRect);
        tolua_function(tolua_S,"getMonstersCountOnRect", lua_woool_SpriteMonster_getMonstersCountOnRect);
        tolua_function(tolua_S,"create", lua_woool_SpriteMonster_create);
        tolua_function(tolua_S,"clearMapTile", lua_woool_SpriteMonster_clearMapTile);
        tolua_function(tolua_S,"setMaxNumOneTile", lua_woool_SpriteMonster_setMaxNumOneTile);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(SpriteMonster).name();
    g_luaType[typeName] = "SpriteMonster";
    g_typeCast["SpriteMonster"] = "SpriteMonster";
    return 1;
}

int lua_woool_SpritePlayer_setUnToAttack(lua_State* tolua_S)
{
    int argc = 0;
    SpritePlayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpritePlayer_setUnToAttack'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "SpritePlayer:setUnToAttack");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpritePlayer_setUnToAttack'", nullptr);
            return 0;
        }
        cobj->setUnToAttack(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpritePlayer:setUnToAttack",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpritePlayer_setUnToAttack'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpritePlayer_setRoleId(lua_State* tolua_S)
{
    int argc = 0;
    SpritePlayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpritePlayer_setRoleId'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpritePlayer:setRoleId");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpritePlayer_setRoleId'", nullptr);
            return 0;
        }
        cobj->setRoleId(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpritePlayer:setRoleId",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpritePlayer_setRoleId'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpritePlayer_getSchool(lua_State* tolua_S)
{
    int argc = 0;
    SpritePlayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpritePlayer_getSchool'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpritePlayer_getSchool'", nullptr);
            return 0;
        }
        double ret = cobj->getSchool();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpritePlayer:getSchool",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpritePlayer_getSchool'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpritePlayer_setSex(lua_State* tolua_S)
{
    int argc = 0;
    SpritePlayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpritePlayer_setSex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "SpritePlayer:setSex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpritePlayer_setSex'", nullptr);
            return 0;
        }
        cobj->setSex(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpritePlayer:setSex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpritePlayer_setSex'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpritePlayer_setSchool(lua_State* tolua_S)
{
    int argc = 0;
    SpritePlayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpritePlayer_setSchool'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpritePlayer:setSchool");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpritePlayer_setSchool'", nullptr);
            return 0;
        }
        cobj->setSchool(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpritePlayer:setSchool",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpritePlayer_setSchool'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpritePlayer_getIsMonsterRole(lua_State* tolua_S)
{
    int argc = 0;
    SpritePlayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpritePlayer_getIsMonsterRole'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpritePlayer_getIsMonsterRole'", nullptr);
            return 0;
        }
        bool ret = cobj->getIsMonsterRole();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpritePlayer:getIsMonsterRole",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpritePlayer_getIsMonsterRole'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpritePlayer_setIsMonsterRole(lua_State* tolua_S)
{
    int argc = 0;
    SpritePlayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpritePlayer_setIsMonsterRole'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "SpritePlayer:setIsMonsterRole");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpritePlayer_setIsMonsterRole'", nullptr);
            return 0;
        }
        cobj->setIsMonsterRole(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpritePlayer:setIsMonsterRole",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpritePlayer_setIsMonsterRole'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpritePlayer_moveInTheDir_ex(lua_State* tolua_S)
{
    int argc = 0;
    SpritePlayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpritePlayer_moveInTheDir_ex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        double arg0;
        cocos2d::Point arg1;
        Commen_Direction arg2;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpritePlayer:moveInTheDir_ex");

        ok &= luaval_to_point(tolua_S, 3, &arg1, "SpritePlayer:moveInTheDir_ex");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "SpritePlayer:moveInTheDir_ex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpritePlayer_moveInTheDir_ex'", nullptr);
            return 0;
        }
        bool ret = cobj->moveInTheDir_ex(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 4) 
    {
        double arg0;
        cocos2d::Point arg1;
        Commen_Direction arg2;
        double arg3;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpritePlayer:moveInTheDir_ex");

        ok &= luaval_to_point(tolua_S, 3, &arg1, "SpritePlayer:moveInTheDir_ex");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "SpritePlayer:moveInTheDir_ex");

        ok &= luaval_to_number(tolua_S, 5,&arg3, "SpritePlayer:moveInTheDir_ex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpritePlayer_moveInTheDir_ex'", nullptr);
            return 0;
        }
        bool ret = cobj->moveInTheDir_ex(arg0, arg1, arg2, arg3);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpritePlayer:moveInTheDir_ex",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpritePlayer_moveInTheDir_ex'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpritePlayer_isActor(lua_State* tolua_S)
{
    int argc = 0;
    SpritePlayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpritePlayer_isActor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpritePlayer_isActor'", nullptr);
            return 0;
        }
        bool ret = cobj->isActor();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpritePlayer:isActor",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpritePlayer_isActor'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpritePlayer_getSex(lua_State* tolua_S)
{
    int argc = 0;
    SpritePlayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpritePlayer_getSex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpritePlayer_getSex'", nullptr);
            return 0;
        }
        int ret = cobj->getSex();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpritePlayer:getSex",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpritePlayer_getSex'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpritePlayer_attackOnRide(lua_State* tolua_S)
{
    int argc = 0;
    SpritePlayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpritePlayer_attackOnRide'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        double arg0;
        cocos2d::Point arg1;
        Commen_Direction arg2;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpritePlayer:attackOnRide");

        ok &= luaval_to_point(tolua_S, 3, &arg1, "SpritePlayer:attackOnRide");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "SpritePlayer:attackOnRide");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpritePlayer_attackOnRide'", nullptr);
            return 0;
        }
        bool ret = cobj->attackOnRide(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 4) 
    {
        double arg0;
        cocos2d::Point arg1;
        Commen_Direction arg2;
        int arg3;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpritePlayer:attackOnRide");

        ok &= luaval_to_point(tolua_S, 3, &arg1, "SpritePlayer:attackOnRide");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "SpritePlayer:attackOnRide");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "SpritePlayer:attackOnRide");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpritePlayer_attackOnRide'", nullptr);
            return 0;
        }
        bool ret = cobj->attackOnRide(arg0, arg1, arg2, arg3);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpritePlayer:attackOnRide",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpritePlayer_attackOnRide'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpritePlayer_AttackDSUpToPos(lua_State* tolua_S)
{
    int argc = 0;
    SpritePlayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpritePlayer_AttackDSUpToPos'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        cocos2d::Point arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "SpritePlayer:AttackDSUpToPos");

        ok &= luaval_to_point(tolua_S, 3, &arg1, "SpritePlayer:AttackDSUpToPos");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpritePlayer_AttackDSUpToPos'", nullptr);
            return 0;
        }
        bool ret = cobj->AttackDSUpToPos(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpritePlayer:AttackDSUpToPos",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpritePlayer_AttackDSUpToPos'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpritePlayer_getRoleId(lua_State* tolua_S)
{
    int argc = 0;
    SpritePlayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpritePlayer_getRoleId'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpritePlayer_getRoleId'", nullptr);
            return 0;
        }
        double ret = cobj->getRoleId();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpritePlayer:getRoleId",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpritePlayer_getRoleId'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpritePlayer_getUnToAttack(lua_State* tolua_S)
{
    int argc = 0;
    SpritePlayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (SpritePlayer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_SpritePlayer_getUnToAttack'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpritePlayer_getUnToAttack'", nullptr);
            return 0;
        }
        bool ret = cobj->getUnToAttack();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpritePlayer:getUnToAttack",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpritePlayer_getUnToAttack'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_SpritePlayer_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"SpritePlayer",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        int arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "SpritePlayer:create");
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "SpritePlayer:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpritePlayer_create'", nullptr);
            return 0;
        }
        SpritePlayer* ret = SpritePlayer::create(arg0, arg1);
        object_to_luaval<SpritePlayer>(tolua_S, "SpritePlayer",(SpritePlayer*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "SpritePlayer:create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpritePlayer_create'.",&tolua_err);
#endif
    return 0;
}
int lua_woool_SpritePlayer_constructor(lua_State* tolua_S)
{
    int argc = 0;
    SpritePlayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_SpritePlayer_constructor'", nullptr);
            return 0;
        }
        cobj = new SpritePlayer();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"SpritePlayer");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "SpritePlayer:SpritePlayer",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_woool_SpritePlayer_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_woool_SpritePlayer_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (SpritePlayer)");
    return 0;
}

int lua_register_woool_SpritePlayer(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"SpritePlayer");
    tolua_cclass(tolua_S,"SpritePlayer","SpritePlayer","SpriteMonster",nullptr);

    tolua_beginmodule(tolua_S,"SpritePlayer");
        tolua_function(tolua_S,"new",lua_woool_SpritePlayer_constructor);
        tolua_function(tolua_S,"setUnToAttack",lua_woool_SpritePlayer_setUnToAttack);
        tolua_function(tolua_S,"setRoleId",lua_woool_SpritePlayer_setRoleId);
        tolua_function(tolua_S,"getSchool",lua_woool_SpritePlayer_getSchool);
        tolua_function(tolua_S,"setSex",lua_woool_SpritePlayer_setSex);
        tolua_function(tolua_S,"setSchool",lua_woool_SpritePlayer_setSchool);
        tolua_function(tolua_S,"getIsMonsterRole",lua_woool_SpritePlayer_getIsMonsterRole);
        tolua_function(tolua_S,"setIsMonsterRole",lua_woool_SpritePlayer_setIsMonsterRole);
        tolua_function(tolua_S,"moveInTheDir_ex",lua_woool_SpritePlayer_moveInTheDir_ex);
        tolua_function(tolua_S,"isActor",lua_woool_SpritePlayer_isActor);
        tolua_function(tolua_S,"getSex",lua_woool_SpritePlayer_getSex);
        tolua_function(tolua_S,"attackOnRide",lua_woool_SpritePlayer_attackOnRide);
        tolua_function(tolua_S,"AttackDSUpToPos",lua_woool_SpritePlayer_AttackDSUpToPos);
        tolua_function(tolua_S,"getRoleId",lua_woool_SpritePlayer_getRoleId);
        tolua_function(tolua_S,"getUnToAttack",lua_woool_SpritePlayer_getUnToAttack);
        tolua_function(tolua_S,"create", lua_woool_SpritePlayer_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(SpritePlayer).name();
    g_luaType[typeName] = "SpritePlayer";
    g_typeCast["SpritePlayer"] = "SpritePlayer";
    return 1;
}

int lua_woool_Touch9Sprite_isTouchInside(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_Touch9Sprite_isTouchInside'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Touch* arg0;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0, "Touch9Sprite:isTouchInside");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_Touch9Sprite_isTouchInside'", nullptr);
            return 0;
        }
        bool ret = cobj->isTouchInside(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Touch9Sprite:isTouchInside",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_Touch9Sprite_isTouchInside'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_Touch9Sprite_initTouch(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_Touch9Sprite_initTouch'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_Touch9Sprite_initTouch'", nullptr);
            return 0;
        }
        bool ret = cobj->initTouch();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Touch9Sprite:initTouch",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_Touch9Sprite_initTouch'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_Touch9Sprite_setActionEnable(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_Touch9Sprite_setActionEnable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_Touch9Sprite_setActionEnable'", nullptr);
            return 0;
        }
        cobj->setActionEnable();
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "Touch9Sprite:setActionEnable");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_Touch9Sprite_setActionEnable'", nullptr);
            return 0;
        }
        cobj->setActionEnable(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Touch9Sprite:setActionEnable",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_Touch9Sprite_setActionEnable'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_Touch9Sprite_setTouchEnable(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_Touch9Sprite_setTouchEnable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_Touch9Sprite_setTouchEnable'", nullptr);
            return 0;
        }
        cobj->setTouchEnable();
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "Touch9Sprite:setTouchEnable");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_Touch9Sprite_setTouchEnable'", nullptr);
            return 0;
        }
        cobj->setTouchEnable(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Touch9Sprite:setTouchEnable",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_Touch9Sprite_setTouchEnable'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_Touch9Sprite_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"Touch9Sprite",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 2)
        {
            const char* arg0;
            std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "Touch9Sprite:create"); arg0 = arg0_tmp.c_str();
            if (!ok) { break; }
            cocos2d::Size arg1;
            ok &= luaval_to_size(tolua_S, 3, &arg1, "Touch9Sprite:create");
            if (!ok) { break; }
            Touch9Sprite* ret = Touch9Sprite::create(arg0, arg1);
            object_to_luaval<Touch9Sprite>(tolua_S, "Touch9Sprite",(Touch9Sprite*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 0)
        {
            Touch9Sprite* ret = Touch9Sprite::create();
            object_to_luaval<Touch9Sprite>(tolua_S, "Touch9Sprite",(Touch9Sprite*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "Touch9Sprite:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_Touch9Sprite_create'.",&tolua_err);
#endif
    return 0;
}
int lua_woool_Touch9Sprite_constructor(lua_State* tolua_S)
{
    int argc = 0;
    Touch9Sprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_Touch9Sprite_constructor'", nullptr);
            return 0;
        }
        cobj = new Touch9Sprite();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"Touch9Sprite");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Touch9Sprite:Touch9Sprite",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_woool_Touch9Sprite_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_woool_Touch9Sprite_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Touch9Sprite)");
    return 0;
}

int lua_register_woool_Touch9Sprite(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"Touch9Sprite");
    tolua_cclass(tolua_S,"Touch9Sprite","Touch9Sprite","ccui.Scale9Sprite",nullptr);

    tolua_beginmodule(tolua_S,"Touch9Sprite");
        tolua_function(tolua_S,"new",lua_woool_Touch9Sprite_constructor);
        tolua_function(tolua_S,"isTouchInside",lua_woool_Touch9Sprite_isTouchInside);
        tolua_function(tolua_S,"initTouch",lua_woool_Touch9Sprite_initTouch);
        tolua_function(tolua_S,"setActionEnable",lua_woool_Touch9Sprite_setActionEnable);
        tolua_function(tolua_S,"setTouchEnable",lua_woool_Touch9Sprite_setTouchEnable);
        tolua_function(tolua_S,"create", lua_woool_Touch9Sprite_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(Touch9Sprite).name();
    g_luaType[typeName] = "Touch9Sprite";
    g_typeCast["Touch9Sprite"] = "Touch9Sprite";
    return 1;
}

int lua_woool_TouchSprite_setWithFrame(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_TouchSprite_setWithFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "TouchSprite:setWithFrame");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_TouchSprite_setWithFrame'", nullptr);
            return 0;
        }
        cobj->setWithFrame(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "TouchSprite:setWithFrame",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_TouchSprite_setWithFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_TouchSprite_isTouchInside(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_TouchSprite_isTouchInside'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Touch* arg0;

        ok &= luaval_to_object<cocos2d::Touch>(tolua_S, 2, "cc.Touch",&arg0, "TouchSprite:isTouchInside");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_TouchSprite_isTouchInside'", nullptr);
            return 0;
        }
        bool ret = cobj->isTouchInside(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "TouchSprite:isTouchInside",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_TouchSprite_isTouchInside'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_TouchSprite_setSelectAction(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_TouchSprite_setSelectAction'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Action* arg0;

        ok &= luaval_to_object<cocos2d::Action>(tolua_S, 2, "cc.Action",&arg0, "TouchSprite:setSelectAction");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_TouchSprite_setSelectAction'", nullptr);
            return 0;
        }
        cobj->setSelectAction(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "TouchSprite:setSelectAction",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_TouchSprite_setSelectAction'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_TouchSprite_setUnSelectAction(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_TouchSprite_setUnSelectAction'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Action* arg0;

        ok &= luaval_to_object<cocos2d::Action>(tolua_S, 2, "cc.Action",&arg0, "TouchSprite:setUnSelectAction");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_TouchSprite_setUnSelectAction'", nullptr);
            return 0;
        }
        cobj->setUnSelectAction(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "TouchSprite:setUnSelectAction",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_TouchSprite_setUnSelectAction'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_TouchSprite_setEnable(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_TouchSprite_setEnable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_TouchSprite_setEnable'", nullptr);
            return 0;
        }
        cobj->setEnable();
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "TouchSprite:setEnable");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_TouchSprite_setEnable'", nullptr);
            return 0;
        }
        cobj->setEnable(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "TouchSprite:setEnable",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_TouchSprite_setEnable'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_TouchSprite_setSelectFrame(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_TouchSprite_setSelectFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "TouchSprite:setSelectFrame");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_TouchSprite_setSelectFrame'", nullptr);
            return 0;
        }
        cobj->setSelectFrame(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "TouchSprite:setSelectFrame",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_TouchSprite_setSelectFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_TouchSprite_initTouch(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_TouchSprite_initTouch'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_TouchSprite_initTouch'", nullptr);
            return 0;
        }
        bool ret = cobj->initTouch();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "TouchSprite:initTouch",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_TouchSprite_initTouch'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_TouchSprite_setTouchEnable(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_TouchSprite_setTouchEnable'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_TouchSprite_setTouchEnable'", nullptr);
            return 0;
        }
        cobj->setTouchEnable();
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "TouchSprite:setTouchEnable");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_TouchSprite_setTouchEnable'", nullptr);
            return 0;
        }
        cobj->setTouchEnable(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "TouchSprite:setTouchEnable",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_TouchSprite_setTouchEnable'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_TouchSprite_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"TouchSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 1)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "TouchSprite:create");
            if (!ok) { break; }
            TouchSprite* ret = TouchSprite::create(arg0);
            object_to_luaval<TouchSprite>(tolua_S, "TouchSprite",(TouchSprite*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 2)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "TouchSprite:create");
            if (!ok) { break; }
            bool arg1;
            ok &= luaval_to_boolean(tolua_S, 3,&arg1, "TouchSprite:create");
            if (!ok) { break; }
            TouchSprite* ret = TouchSprite::create(arg0, arg1);
            object_to_luaval<TouchSprite>(tolua_S, "TouchSprite",(TouchSprite*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 0)
        {
            TouchSprite* ret = TouchSprite::create();
            object_to_luaval<TouchSprite>(tolua_S, "TouchSprite",(TouchSprite*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "TouchSprite:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_TouchSprite_create'.",&tolua_err);
#endif
    return 0;
}
int lua_woool_TouchSprite_createWithFrame(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"TouchSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "TouchSprite:createWithFrame");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_TouchSprite_createWithFrame'", nullptr);
            return 0;
        }
        TouchSprite* ret = TouchSprite::createWithFrame(arg0);
        object_to_luaval<TouchSprite>(tolua_S, "TouchSprite",(TouchSprite*)ret);
        return 1;
    }
    if (argc == 2)
    {
        std::string arg0;
        std::string arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "TouchSprite:createWithFrame");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "TouchSprite:createWithFrame");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_TouchSprite_createWithFrame'", nullptr);
            return 0;
        }
        TouchSprite* ret = TouchSprite::createWithFrame(arg0, arg1);
        object_to_luaval<TouchSprite>(tolua_S, "TouchSprite",(TouchSprite*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "TouchSprite:createWithFrame",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_TouchSprite_createWithFrame'.",&tolua_err);
#endif
    return 0;
}
int lua_woool_TouchSprite_constructor(lua_State* tolua_S)
{
    int argc = 0;
    TouchSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_TouchSprite_constructor'", nullptr);
            return 0;
        }
        cobj = new TouchSprite();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"TouchSprite");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "TouchSprite:TouchSprite",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_woool_TouchSprite_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_woool_TouchSprite_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (TouchSprite)");
    return 0;
}

int lua_register_woool_TouchSprite(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"TouchSprite");
    tolua_cclass(tolua_S,"TouchSprite","TouchSprite","GraySprite",nullptr);

    tolua_beginmodule(tolua_S,"TouchSprite");
        tolua_function(tolua_S,"new",lua_woool_TouchSprite_constructor);
        tolua_function(tolua_S,"setWithFrame",lua_woool_TouchSprite_setWithFrame);
        tolua_function(tolua_S,"isTouchInside",lua_woool_TouchSprite_isTouchInside);
        tolua_function(tolua_S,"setSelectAction",lua_woool_TouchSprite_setSelectAction);
        tolua_function(tolua_S,"setUnSelectAction",lua_woool_TouchSprite_setUnSelectAction);
        tolua_function(tolua_S,"setEnable",lua_woool_TouchSprite_setEnable);
        tolua_function(tolua_S,"setSelectFrame",lua_woool_TouchSprite_setSelectFrame);
        tolua_function(tolua_S,"initTouch",lua_woool_TouchSprite_initTouch);
        tolua_function(tolua_S,"setTouchEnable",lua_woool_TouchSprite_setTouchEnable);
        tolua_function(tolua_S,"create", lua_woool_TouchSprite_create);
        tolua_function(tolua_S,"createWithFrame", lua_woool_TouchSprite_createWithFrame);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(TouchSprite).name();
    g_luaType[typeName] = "TouchSprite";
    g_typeCast["TouchSprite"] = "TouchSprite";
    return 1;
}

/*int lua_woool_Effects_createEffect2(lua_State* tolua_S)
{
    int argc = 0;
    Effects* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Effects",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Effects*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_Effects_createEffect2'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        int arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "Effects:createEffect2");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "Effects:createEffect2");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_Effects_createEffect2'", nullptr);
            return 0;
        }
        cocos2d::Animation* ret = cobj->createEffect2(arg0, arg1);
        object_to_luaval<cocos2d::Animation>(tolua_S, "cc.Animation",(cocos2d::Animation*)ret);
        return 1;
    }
    if (argc == 3) 
    {
        std::string arg0;
        int arg1;
        int arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "Effects:createEffect2");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "Effects:createEffect2");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "Effects:createEffect2");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_Effects_createEffect2'", nullptr);
            return 0;
        }
        cocos2d::Animation* ret = cobj->createEffect2(arg0, arg1, arg2);
        object_to_luaval<cocos2d::Animation>(tolua_S, "cc.Animation",(cocos2d::Animation*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Effects:createEffect2",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_Effects_createEffect2'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_Effects_CreateEffect3(lua_State* tolua_S)
{
    int argc = 0;
    Effects* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Effects",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Effects*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_Effects_CreateEffect3'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        std::string arg0;
        int arg1;
        int arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "Effects:CreateEffect3");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "Effects:CreateEffect3");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "Effects:CreateEffect3");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_Effects_CreateEffect3'", nullptr);
            return 0;
        }
        cocos2d::Animation* ret = cobj->CreateEffect3(arg0, arg1, arg2);
        object_to_luaval<cocos2d::Animation>(tolua_S, "cc.Animation",(cocos2d::Animation*)ret);
        return 1;
    }
    if (argc == 4) 
    {
        std::string arg0;
        int arg1;
        int arg2;
        int arg3;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "Effects:CreateEffect3");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "Effects:CreateEffect3");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "Effects:CreateEffect3");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "Effects:CreateEffect3");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_Effects_CreateEffect3'", nullptr);
            return 0;
        }
        cocos2d::Animation* ret = cobj->CreateEffect3(arg0, arg1, arg2, arg3);
        object_to_luaval<cocos2d::Animation>(tolua_S, "cc.Animation",(cocos2d::Animation*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Effects:CreateEffect3",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_Effects_CreateEffect3'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_Effects_setAlwaysNoClean(lua_State* tolua_S)
{
    int argc = 0;
    Effects* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Effects",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Effects*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_Effects_setAlwaysNoClean'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "Effects:setAlwaysNoClean");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_Effects_setAlwaysNoClean'", nullptr);
            return 0;
        }
        cobj->setAlwaysNoClean(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Effects:setAlwaysNoClean",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_Effects_setAlwaysNoClean'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_Effects_setCleanCache(lua_State* tolua_S)
{
    int argc = 0;
    Effects* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Effects",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Effects*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_Effects_setCleanCache'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_Effects_setCleanCache'", nullptr);
            return 0;
        }
        cobj->setCleanCache();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Effects:setCleanCache",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_Effects_setCleanCache'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_Effects_createEffect(lua_State* tolua_S)
{
    int argc = 0;
    Effects* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Effects",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Effects*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_Effects_createEffect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        std::string arg0;
        int arg1;
        double arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "Effects:createEffect");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "Effects:createEffect");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "Effects:createEffect");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_Effects_createEffect'", nullptr);
            return 0;
        }
        cocos2d::Animation* ret = cobj->createEffect(arg0, arg1, arg2);
        object_to_luaval<cocos2d::Animation>(tolua_S, "cc.Animation",(cocos2d::Animation*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Effects:createEffect",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_Effects_createEffect'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_Effects_setAsyncLoad(lua_State* tolua_S)
{
    int argc = 0;
    Effects* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Effects",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Effects*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_Effects_setAsyncLoad'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "Effects:setAsyncLoad");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_Effects_setAsyncLoad'", nullptr);
            return 0;
        }
        cobj->setAsyncLoad(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Effects:setAsyncLoad",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_Effects_setAsyncLoad'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_Effects_playActionData2(lua_State* tolua_S)
{
    int argc = 0;
    Effects* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Effects",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Effects*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_Effects_playActionData2'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        std::string arg0;
        double arg1;
        int arg2;
        double arg3;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "Effects:playActionData2");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "Effects:playActionData2");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "Effects:playActionData2");

        ok &= luaval_to_number(tolua_S, 5,&arg3, "Effects:playActionData2");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_Effects_playActionData2'", nullptr);
            return 0;
        }
        cobj->playActionData2(arg0, arg1, arg2, arg3);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Effects:playActionData2",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_Effects_playActionData2'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_Effects_playActionData(lua_State* tolua_S)
{
    int argc = 0;
    Effects* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Effects",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Effects*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_Effects_playActionData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        std::string arg0;
        int arg1;
        double arg2;
        int arg3;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "Effects:playActionData");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "Effects:playActionData");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "Effects:playActionData");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "Effects:playActionData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_Effects_playActionData'", nullptr);
            return 0;
        }
        cobj->playActionData(arg0, arg1, arg2, arg3);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 5) 
    {
        std::string arg0;
        int arg1;
        double arg2;
        int arg3;
        double arg4;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "Effects:playActionData");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "Effects:playActionData");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "Effects:playActionData");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "Effects:playActionData");

        ok &= luaval_to_number(tolua_S, 6,&arg4, "Effects:playActionData");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_Effects_playActionData'", nullptr);
            return 0;
        }
        cobj->playActionData(arg0, arg1, arg2, arg3, arg4);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Effects:playActionData",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_Effects_playActionData'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_Effects_setPlistNum(lua_State* tolua_S)
{
    int argc = 0;
    Effects* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"Effects",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (Effects*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_Effects_setPlistNum'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "Effects:setPlistNum");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_Effects_setPlistNum'", nullptr);
            return 0;
        }
        cobj->setPlistNum(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Effects:setPlistNum",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_Effects_setPlistNum'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_Effects_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"Effects",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "Effects:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_Effects_create'", nullptr);
            return 0;
        }
        Effects* ret = Effects::create(arg0);
        object_to_luaval<Effects>(tolua_S, "Effects",(Effects*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "Effects:create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_Effects_create'.",&tolua_err);
#endif
    return 0;
}
int lua_woool_Effects_constructor(lua_State* tolua_S)
{
    int argc = 0;
    Effects* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_Effects_constructor'", nullptr);
            return 0;
        }
        cobj = new Effects();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"Effects");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "Effects:Effects",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_woool_Effects_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_woool_Effects_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Effects)");
    return 0;
}

int lua_register_woool_Effects(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"Effects");
    tolua_cclass(tolua_S,"Effects","Effects","cc.Sprite",nullptr);

    tolua_beginmodule(tolua_S,"Effects");
        tolua_function(tolua_S,"new",lua_woool_Effects_constructor);
        tolua_function(tolua_S,"createEffect2",lua_woool_Effects_createEffect2);
        tolua_function(tolua_S,"CreateEffect3",lua_woool_Effects_CreateEffect3);
        tolua_function(tolua_S,"setAlwaysNoClean",lua_woool_Effects_setAlwaysNoClean);
        tolua_function(tolua_S,"setCleanCache",lua_woool_Effects_setCleanCache);
        tolua_function(tolua_S,"createEffect",lua_woool_Effects_createEffect);
        tolua_function(tolua_S,"setAsyncLoad",lua_woool_Effects_setAsyncLoad);
        tolua_function(tolua_S,"playActionData2",lua_woool_Effects_playActionData2);
        tolua_function(tolua_S,"playActionData",lua_woool_Effects_playActionData);
        tolua_function(tolua_S,"setPlistNum",lua_woool_Effects_setPlistNum);
        tolua_function(tolua_S,"create", lua_woool_Effects_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(Effects).name();
    g_luaType[typeName] = "Effects";
    g_typeCast["Effects"] = "Effects";
    return 1;
}

int lua_woool_CMagicCtrlMgr_CreateMagicByPos(lua_State* tolua_S)
{
    int argc = 0;
    CMagicCtrlMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMagicCtrlMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMagicCtrlMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CMagicCtrlMgr_CreateMagicByPos'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        int arg0;
        int arg1;
        int arg2;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CMagicCtrlMgr:CreateMagicByPos");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "CMagicCtrlMgr:CreateMagicByPos");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "CMagicCtrlMgr:CreateMagicByPos");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CMagicCtrlMgr_CreateMagicByPos'", nullptr);
            return 0;
        }
        cobj->CreateMagicByPos(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 4) 
    {
        int arg0;
        int arg1;
        int arg2;
        MapViewBase* arg3;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CMagicCtrlMgr:CreateMagicByPos");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "CMagicCtrlMgr:CreateMagicByPos");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "CMagicCtrlMgr:CreateMagicByPos");

        ok &= luaval_to_object<MapViewBase>(tolua_S, 5, "MapViewBase",&arg3, "CMagicCtrlMgr:CreateMagicByPos");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CMagicCtrlMgr_CreateMagicByPos'", nullptr);
            return 0;
        }
        cobj->CreateMagicByPos(arg0, arg1, arg2, arg3);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMagicCtrlMgr:CreateMagicByPos",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CMagicCtrlMgr_CreateMagicByPos'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CMagicCtrlMgr_GetMagicRootD3(lua_State* tolua_S)
{
    int argc = 0;
    CMagicCtrlMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMagicCtrlMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMagicCtrlMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CMagicCtrlMgr_GetMagicRootD3'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CMagicCtrlMgr:GetMagicRootD3");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CMagicCtrlMgr_GetMagicRootD3'", nullptr);
            return 0;
        }
        int ret = cobj->GetMagicRootD3(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMagicCtrlMgr:GetMagicRootD3",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CMagicCtrlMgr_GetMagicRootD3'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CMagicCtrlMgr_CreateFloorMagic(lua_State* tolua_S)
{
    int argc = 0;
    CMagicCtrlMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMagicCtrlMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMagicCtrlMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CMagicCtrlMgr_CreateFloorMagic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        int arg0;
        int arg1;
        int arg2;
        int arg3;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CMagicCtrlMgr:CreateFloorMagic");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "CMagicCtrlMgr:CreateFloorMagic");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "CMagicCtrlMgr:CreateFloorMagic");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "CMagicCtrlMgr:CreateFloorMagic");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CMagicCtrlMgr_CreateFloorMagic'", nullptr);
            return 0;
        }
        cobj->CreateFloorMagic(arg0, arg1, arg2, arg3);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 5) 
    {
        int arg0;
        int arg1;
        int arg2;
        int arg3;
        int arg4;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CMagicCtrlMgr:CreateFloorMagic");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "CMagicCtrlMgr:CreateFloorMagic");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "CMagicCtrlMgr:CreateFloorMagic");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "CMagicCtrlMgr:CreateFloorMagic");

        ok &= luaval_to_int32(tolua_S, 6,(int *)&arg4, "CMagicCtrlMgr:CreateFloorMagic");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CMagicCtrlMgr_CreateFloorMagic'", nullptr);
            return 0;
        }
        cobj->CreateFloorMagic(arg0, arg1, arg2, arg3, arg4);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 6) 
    {
        int arg0;
        int arg1;
        int arg2;
        int arg3;
        int arg4;
        MapViewBase* arg5;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CMagicCtrlMgr:CreateFloorMagic");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "CMagicCtrlMgr:CreateFloorMagic");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "CMagicCtrlMgr:CreateFloorMagic");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "CMagicCtrlMgr:CreateFloorMagic");

        ok &= luaval_to_int32(tolua_S, 6,(int *)&arg4, "CMagicCtrlMgr:CreateFloorMagic");

        ok &= luaval_to_object<MapViewBase>(tolua_S, 7, "MapViewBase",&arg5, "CMagicCtrlMgr:CreateFloorMagic");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CMagicCtrlMgr_CreateFloorMagic'", nullptr);
            return 0;
        }
        cobj->CreateFloorMagic(arg0, arg1, arg2, arg3, arg4, arg5);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMagicCtrlMgr:CreateFloorMagic",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CMagicCtrlMgr_CreateFloorMagic'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CMagicCtrlMgr_ClearAllFloors(lua_State* tolua_S)
{
    int argc = 0;
    CMagicCtrlMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMagicCtrlMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMagicCtrlMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CMagicCtrlMgr_ClearAllFloors'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CMagicCtrlMgr_ClearAllFloors'", nullptr);
            return 0;
        }
        cobj->ClearAllFloors();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMagicCtrlMgr:ClearAllFloors",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CMagicCtrlMgr_ClearAllFloors'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CMagicCtrlMgr_ClearFloorById(lua_State* tolua_S)
{
    int argc = 0;
    CMagicCtrlMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMagicCtrlMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMagicCtrlMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CMagicCtrlMgr_ClearFloorById'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CMagicCtrlMgr:ClearFloorById");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CMagicCtrlMgr_ClearFloorById'", nullptr);
            return 0;
        }
        cobj->ClearFloorById(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMagicCtrlMgr:ClearFloorById",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CMagicCtrlMgr_ClearFloorById'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CMagicCtrlMgr_CreateOffsetMagic(lua_State* tolua_S)
{
    int argc = 0;
    CMagicCtrlMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMagicCtrlMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMagicCtrlMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CMagicCtrlMgr_CreateOffsetMagic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 9) 
    {
        int arg0;
        int arg1;
        int arg2;
        int arg3;
        int arg4;
        int arg5;
        unsigned int arg6;
        unsigned int arg7;
        int arg8;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CMagicCtrlMgr:CreateOffsetMagic");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "CMagicCtrlMgr:CreateOffsetMagic");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "CMagicCtrlMgr:CreateOffsetMagic");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "CMagicCtrlMgr:CreateOffsetMagic");

        ok &= luaval_to_int32(tolua_S, 6,(int *)&arg4, "CMagicCtrlMgr:CreateOffsetMagic");

        ok &= luaval_to_int32(tolua_S, 7,(int *)&arg5, "CMagicCtrlMgr:CreateOffsetMagic");

        ok &= luaval_to_uint32(tolua_S, 8,&arg6, "CMagicCtrlMgr:CreateOffsetMagic");

        ok &= luaval_to_uint32(tolua_S, 9,&arg7, "CMagicCtrlMgr:CreateOffsetMagic");

        ok &= luaval_to_int32(tolua_S, 10,(int *)&arg8, "CMagicCtrlMgr:CreateOffsetMagic");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CMagicCtrlMgr_CreateOffsetMagic'", nullptr);
            return 0;
        }
        cobj->CreateOffsetMagic(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 10) 
    {
        int arg0;
        int arg1;
        int arg2;
        int arg3;
        int arg4;
        int arg5;
        unsigned int arg6;
        unsigned int arg7;
        int arg8;
        MapViewBase* arg9;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CMagicCtrlMgr:CreateOffsetMagic");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "CMagicCtrlMgr:CreateOffsetMagic");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "CMagicCtrlMgr:CreateOffsetMagic");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "CMagicCtrlMgr:CreateOffsetMagic");

        ok &= luaval_to_int32(tolua_S, 6,(int *)&arg4, "CMagicCtrlMgr:CreateOffsetMagic");

        ok &= luaval_to_int32(tolua_S, 7,(int *)&arg5, "CMagicCtrlMgr:CreateOffsetMagic");

        ok &= luaval_to_uint32(tolua_S, 8,&arg6, "CMagicCtrlMgr:CreateOffsetMagic");

        ok &= luaval_to_uint32(tolua_S, 9,&arg7, "CMagicCtrlMgr:CreateOffsetMagic");

        ok &= luaval_to_int32(tolua_S, 10,(int *)&arg8, "CMagicCtrlMgr:CreateOffsetMagic");

        ok &= luaval_to_object<MapViewBase>(tolua_S, 11, "MapViewBase",&arg9, "CMagicCtrlMgr:CreateOffsetMagic");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CMagicCtrlMgr_CreateOffsetMagic'", nullptr);
            return 0;
        }
        cobj->CreateOffsetMagic(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMagicCtrlMgr:CreateOffsetMagic",argc, 9);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CMagicCtrlMgr_CreateOffsetMagic'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CMagicCtrlMgr_CreatePichesMagic(lua_State* tolua_S)
{
    int argc = 0;
    CMagicCtrlMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMagicCtrlMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMagicCtrlMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CMagicCtrlMgr_CreatePichesMagic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CMagicCtrlMgr:CreatePichesMagic");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CMagicCtrlMgr_CreatePichesMagic'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->CreatePichesMagic(arg0);
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    if (argc == 2) 
    {
        unsigned short arg0;
        int arg1;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CMagicCtrlMgr:CreatePichesMagic");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "CMagicCtrlMgr:CreatePichesMagic");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CMagicCtrlMgr_CreatePichesMagic'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->CreatePichesMagic(arg0, arg1);
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    if (argc == 3) 
    {
        unsigned short arg0;
        int arg1;
        MapViewBase* arg2;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CMagicCtrlMgr:CreatePichesMagic");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "CMagicCtrlMgr:CreatePichesMagic");

        ok &= luaval_to_object<MapViewBase>(tolua_S, 4, "MapViewBase",&arg2, "CMagicCtrlMgr:CreatePichesMagic");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CMagicCtrlMgr_CreatePichesMagic'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->CreatePichesMagic(arg0, arg1, arg2);
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMagicCtrlMgr:CreatePichesMagic",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CMagicCtrlMgr_CreatePichesMagic'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CMagicCtrlMgr_CreateBgMagic(lua_State* tolua_S)
{
    int argc = 0;
    CMagicCtrlMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMagicCtrlMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMagicCtrlMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CMagicCtrlMgr_CreateBgMagic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CMagicCtrlMgr:CreateBgMagic");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CMagicCtrlMgr_CreateBgMagic'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->CreateBgMagic(arg0);
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMagicCtrlMgr:CreateBgMagic",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CMagicCtrlMgr_CreateBgMagic'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CMagicCtrlMgr_LoadFile(lua_State* tolua_S)
{
    int argc = 0;
    CMagicCtrlMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMagicCtrlMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMagicCtrlMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CMagicCtrlMgr_LoadFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CMagicCtrlMgr_LoadFile'", nullptr);
            return 0;
        }
        bool ret = cobj->LoadFile();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMagicCtrlMgr:LoadFile",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CMagicCtrlMgr_LoadFile'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CMagicCtrlMgr_IsMagicCanDisplay(lua_State* tolua_S)
{
    int argc = 0;
    CMagicCtrlMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMagicCtrlMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMagicCtrlMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CMagicCtrlMgr_IsMagicCanDisplay'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned short arg0;

        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "CMagicCtrlMgr:IsMagicCanDisplay");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CMagicCtrlMgr_IsMagicCanDisplay'", nullptr);
            return 0;
        }
        uint16_t ret = cobj->IsMagicCanDisplay(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMagicCtrlMgr:IsMagicCanDisplay",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CMagicCtrlMgr_IsMagicCanDisplay'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CMagicCtrlMgr_MakeLongMacro(lua_State* tolua_S)
{
    int argc = 0;
    CMagicCtrlMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMagicCtrlMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMagicCtrlMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CMagicCtrlMgr_MakeLongMacro'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        int arg0;
        int arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CMagicCtrlMgr:MakeLongMacro");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "CMagicCtrlMgr:MakeLongMacro");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CMagicCtrlMgr_MakeLongMacro'", nullptr);
            return 0;
        }
        int ret = cobj->MakeLongMacro(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMagicCtrlMgr:MakeLongMacro",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CMagicCtrlMgr_MakeLongMacro'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CMagicCtrlMgr_CreateMagic(lua_State* tolua_S)
{
    int argc = 0;
    CMagicCtrlMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CMagicCtrlMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CMagicCtrlMgr*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CMagicCtrlMgr_CreateMagic'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 5) 
    {
        int arg0;
        int arg1;
        unsigned int arg2;
        unsigned int arg3;
        int arg4;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CMagicCtrlMgr:CreateMagic");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "CMagicCtrlMgr:CreateMagic");

        ok &= luaval_to_uint32(tolua_S, 4,&arg2, "CMagicCtrlMgr:CreateMagic");

        ok &= luaval_to_uint32(tolua_S, 5,&arg3, "CMagicCtrlMgr:CreateMagic");

        ok &= luaval_to_int32(tolua_S, 6,(int *)&arg4, "CMagicCtrlMgr:CreateMagic");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CMagicCtrlMgr_CreateMagic'", nullptr);
            return 0;
        }
        cobj->CreateMagic(arg0, arg1, arg2, arg3, arg4);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 6) 
    {
        int arg0;
        int arg1;
        unsigned int arg2;
        unsigned int arg3;
        int arg4;
        MapViewBase* arg5;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CMagicCtrlMgr:CreateMagic");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "CMagicCtrlMgr:CreateMagic");

        ok &= luaval_to_uint32(tolua_S, 4,&arg2, "CMagicCtrlMgr:CreateMagic");

        ok &= luaval_to_uint32(tolua_S, 5,&arg3, "CMagicCtrlMgr:CreateMagic");

        ok &= luaval_to_int32(tolua_S, 6,(int *)&arg4, "CMagicCtrlMgr:CreateMagic");

        ok &= luaval_to_object<MapViewBase>(tolua_S, 7, "MapViewBase",&arg5, "CMagicCtrlMgr:CreateMagic");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CMagicCtrlMgr_CreateMagic'", nullptr);
            return 0;
        }
        cobj->CreateMagic(arg0, arg1, arg2, arg3, arg4, arg5);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMagicCtrlMgr:CreateMagic",argc, 5);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CMagicCtrlMgr_CreateMagic'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CMagicCtrlMgr_destroyInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CMagicCtrlMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CMagicCtrlMgr_destroyInstance'", nullptr);
            return 0;
        }
        CMagicCtrlMgr::destroyInstance();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMagicCtrlMgr:destroyInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CMagicCtrlMgr_destroyInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_woool_CMagicCtrlMgr_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CMagicCtrlMgr",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CMagicCtrlMgr_getInstance'", nullptr);
            return 0;
        }
        CMagicCtrlMgr* ret = CMagicCtrlMgr::getInstance();
        object_to_luaval<CMagicCtrlMgr>(tolua_S, "CMagicCtrlMgr",(CMagicCtrlMgr*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CMagicCtrlMgr:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CMagicCtrlMgr_getInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_woool_CMagicCtrlMgr_constructor(lua_State* tolua_S)
{
    int argc = 0;
    CMagicCtrlMgr* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CMagicCtrlMgr_constructor'", nullptr);
            return 0;
        }
        cobj = new CMagicCtrlMgr();
        tolua_pushusertype(tolua_S,(void*)cobj,"CMagicCtrlMgr");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CMagicCtrlMgr:CMagicCtrlMgr",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CMagicCtrlMgr_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_woool_CMagicCtrlMgr_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CMagicCtrlMgr)");
    return 0;
}

int lua_register_woool_CMagicCtrlMgr(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CMagicCtrlMgr");
    tolua_cclass(tolua_S,"CMagicCtrlMgr","CMagicCtrlMgr","",nullptr);

    tolua_beginmodule(tolua_S,"CMagicCtrlMgr");
        tolua_function(tolua_S,"new",lua_woool_CMagicCtrlMgr_constructor);
        tolua_function(tolua_S,"CreateMagicByPos",lua_woool_CMagicCtrlMgr_CreateMagicByPos);
        tolua_function(tolua_S,"GetMagicRootD3",lua_woool_CMagicCtrlMgr_GetMagicRootD3);
        tolua_function(tolua_S,"CreateFloorMagic",lua_woool_CMagicCtrlMgr_CreateFloorMagic);
        tolua_function(tolua_S,"ClearAllFloors",lua_woool_CMagicCtrlMgr_ClearAllFloors);
        tolua_function(tolua_S,"ClearFloorById",lua_woool_CMagicCtrlMgr_ClearFloorById);
        tolua_function(tolua_S,"CreateOffsetMagic",lua_woool_CMagicCtrlMgr_CreateOffsetMagic);
        tolua_function(tolua_S,"CreatePichesMagic",lua_woool_CMagicCtrlMgr_CreatePichesMagic);
        tolua_function(tolua_S,"CreateBgMagic",lua_woool_CMagicCtrlMgr_CreateBgMagic);
        tolua_function(tolua_S,"LoadFile",lua_woool_CMagicCtrlMgr_LoadFile);
        tolua_function(tolua_S,"IsMagicCanDisplay",lua_woool_CMagicCtrlMgr_IsMagicCanDisplay);
        tolua_function(tolua_S,"MakeLongMacro",lua_woool_CMagicCtrlMgr_MakeLongMacro);
        tolua_function(tolua_S,"CreateMagic",lua_woool_CMagicCtrlMgr_CreateMagic);
        tolua_function(tolua_S,"destroyInstance", lua_woool_CMagicCtrlMgr_destroyInstance);
        tolua_function(tolua_S,"getInstance", lua_woool_CMagicCtrlMgr_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CMagicCtrlMgr).name();
    g_luaType[typeName] = "CMagicCtrlMgr";
    g_typeCast["CMagicCtrlMgr"] = "CMagicCtrlMgr";
    return 1;
}

int lua_woool_CCoverflow_AddCard(lua_State* tolua_S)
{
    int argc = 0;
    CCoverflow* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCoverflow",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (CCoverflow*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CCoverflow_AddCard'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            cocos2d::Node* arg0;
            ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "CCoverflow:AddCard");

            if (!ok) { break; }
            int arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "CCoverflow:AddCard");

            if (!ok) { break; }
            cobj->AddCard(arg0, arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            cocos2d::Node* arg0;
            ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "CCoverflow:AddCard");

            if (!ok) { break; }
            cobj->AddCard(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 3) {
            cocos2d::Node* arg0;
            ok &= luaval_to_object<cocos2d::Node>(tolua_S, 2, "cc.Node",&arg0, "CCoverflow:AddCard");

            if (!ok) { break; }
            int arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "CCoverflow:AddCard");

            if (!ok) { break; }
            int arg2;
            ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "CCoverflow:AddCard");

            if (!ok) { break; }
            cobj->AddCard(arg0, arg1, arg2);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "CCoverflow:AddCard",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CCoverflow_AddCard'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CCoverflow_setIsIgnoreScale(lua_State* tolua_S)
{
    int argc = 0;
    CCoverflow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCoverflow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCoverflow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CCoverflow_setIsIgnoreScale'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "CCoverflow:setIsIgnoreScale");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CCoverflow_setIsIgnoreScale'", nullptr);
            return 0;
        }
        cobj->setIsIgnoreScale(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCoverflow:setIsIgnoreScale",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CCoverflow_setIsIgnoreScale'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CCoverflow_StartMiddleIndex(lua_State* tolua_S)
{
    int argc = 0;
    CCoverflow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCoverflow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCoverflow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CCoverflow_StartMiddleIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CCoverflow:StartMiddleIndex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CCoverflow_StartMiddleIndex'", nullptr);
            return 0;
        }
        cobj->StartMiddleIndex(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCoverflow:StartMiddleIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CCoverflow_StartMiddleIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CCoverflow_scrollViewDidScroll(lua_State* tolua_S)
{
    int argc = 0;
    CCoverflow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCoverflow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCoverflow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CCoverflow_scrollViewDidScroll'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::extension::ScrollView* arg0;

        ok &= luaval_to_object<cocos2d::extension::ScrollView>(tolua_S, 2, "cc.ScrollView",&arg0, "CCoverflow:scrollViewDidScroll");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CCoverflow_scrollViewDidScroll'", nullptr);
            return 0;
        }
        cobj->scrollViewDidScroll(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCoverflow:scrollViewDidScroll",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CCoverflow_scrollViewDidScroll'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CCoverflow_getIsMove(lua_State* tolua_S)
{
    int argc = 0;
    CCoverflow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCoverflow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCoverflow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CCoverflow_getIsMove'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CCoverflow_getIsMove'", nullptr);
            return 0;
        }
        bool ret = cobj->getIsMove();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCoverflow:getIsMove",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CCoverflow_getIsMove'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CCoverflow_setSwSize(lua_State* tolua_S)
{
    int argc = 0;
    CCoverflow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCoverflow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCoverflow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CCoverflow_setSwSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Size arg0;

        ok &= luaval_to_size(tolua_S, 2, &arg0, "CCoverflow:setSwSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CCoverflow_setSwSize'", nullptr);
            return 0;
        }
        cobj->setSwSize(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCoverflow:setSwSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CCoverflow_setSwSize'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CCoverflow_setSlSize(lua_State* tolua_S)
{
    int argc = 0;
    CCoverflow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCoverflow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCoverflow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CCoverflow_setSlSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Size arg0;

        ok &= luaval_to_size(tolua_S, 2, &arg0, "CCoverflow:setSlSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CCoverflow_setSlSize'", nullptr);
            return 0;
        }
        cobj->setSlSize(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCoverflow:setSlSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CCoverflow_setSlSize'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CCoverflow_getOffsetPosition(lua_State* tolua_S)
{
    int argc = 0;
    CCoverflow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCoverflow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCoverflow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CCoverflow_getOffsetPosition'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CCoverflow_getOffsetPosition'", nullptr);
            return 0;
        }
        const cocos2d::Point& ret = cobj->getOffsetPosition();
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCoverflow:getOffsetPosition",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CCoverflow_getOffsetPosition'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CCoverflow_setIsMove(lua_State* tolua_S)
{
    int argc = 0;
    CCoverflow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCoverflow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCoverflow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CCoverflow_setIsMove'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "CCoverflow:setIsMove");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CCoverflow_setIsMove'", nullptr);
            return 0;
        }
        cobj->setIsMove(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCoverflow:setIsMove",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CCoverflow_setIsMove'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CCoverflow_setScrollLayer(lua_State* tolua_S)
{
    int argc = 0;
    CCoverflow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCoverflow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCoverflow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CCoverflow_setScrollLayer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Layer* arg0;

        ok &= luaval_to_object<cocos2d::Layer>(tolua_S, 2, "cc.Layer",&arg0, "CCoverflow:setScrollLayer");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CCoverflow_setScrollLayer'", nullptr);
            return 0;
        }
        cobj->setScrollLayer(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCoverflow:setScrollLayer",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CCoverflow_setScrollLayer'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CCoverflow_setOffsetPosition(lua_State* tolua_S)
{
    int argc = 0;
    CCoverflow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCoverflow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCoverflow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CCoverflow_setOffsetPosition'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;

        ok &= luaval_to_point(tolua_S, 2, &arg0, "CCoverflow:setOffsetPosition");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CCoverflow_setOffsetPosition'", nullptr);
            return 0;
        }
        cobj->setOffsetPosition(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCoverflow:setOffsetPosition",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CCoverflow_setOffsetPosition'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CCoverflow_getCardNum(lua_State* tolua_S)
{
    int argc = 0;
    CCoverflow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCoverflow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCoverflow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CCoverflow_getCardNum'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CCoverflow_getCardNum'", nullptr);
            return 0;
        }
        int ret = cobj->getCardNum();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCoverflow:getCardNum",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CCoverflow_getCardNum'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CCoverflow_getResponseTouch(lua_State* tolua_S)
{
    int argc = 0;
    CCoverflow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCoverflow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCoverflow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CCoverflow_getResponseTouch'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CCoverflow_getResponseTouch'", nullptr);
            return 0;
        }
        bool ret = cobj->getResponseTouch();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCoverflow:getResponseTouch",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CCoverflow_getResponseTouch'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CCoverflow_getDisScale(lua_State* tolua_S)
{
    int argc = 0;
    CCoverflow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCoverflow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCoverflow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CCoverflow_getDisScale'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CCoverflow_getDisScale'", nullptr);
            return 0;
        }
        double ret = cobj->getDisScale();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCoverflow:getDisScale",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CCoverflow_getDisScale'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CCoverflow_AdjustCardScale(lua_State* tolua_S)
{
    int argc = 0;
    CCoverflow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCoverflow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCoverflow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CCoverflow_AdjustCardScale'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;

        ok &= luaval_to_point(tolua_S, 2, &arg0, "CCoverflow:AdjustCardScale");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CCoverflow_AdjustCardScale'", nullptr);
            return 0;
        }
        cobj->AdjustCardScale(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCoverflow:AdjustCardScale",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CCoverflow_AdjustCardScale'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CCoverflow_getSlayerPosition(lua_State* tolua_S)
{
    int argc = 0;
    CCoverflow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCoverflow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCoverflow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CCoverflow_getSlayerPosition'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CCoverflow_getSlayerPosition'", nullptr);
            return 0;
        }
        const cocos2d::Point& ret = cobj->getSlayerPosition();
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCoverflow:getSlayerPosition",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CCoverflow_getSlayerPosition'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CCoverflow_setSwPosition(lua_State* tolua_S)
{
    int argc = 0;
    CCoverflow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCoverflow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCoverflow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CCoverflow_setSwPosition'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;

        ok &= luaval_to_point(tolua_S, 2, &arg0, "CCoverflow:setSwPosition");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CCoverflow_setSwPosition'", nullptr);
            return 0;
        }
        cobj->setSwPosition(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCoverflow:setSwPosition",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CCoverflow_setSwPosition'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CCoverflow_setDisScale(lua_State* tolua_S)
{
    int argc = 0;
    CCoverflow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCoverflow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCoverflow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CCoverflow_setDisScale'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "CCoverflow:setDisScale");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CCoverflow_setDisScale'", nullptr);
            return 0;
        }
        cobj->setDisScale(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCoverflow:setDisScale",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CCoverflow_setDisScale'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CCoverflow_setResponseTouch(lua_State* tolua_S)
{
    int argc = 0;
    CCoverflow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCoverflow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCoverflow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CCoverflow_setResponseTouch'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "CCoverflow:setResponseTouch");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CCoverflow_setResponseTouch'", nullptr);
            return 0;
        }
        cobj->setResponseTouch(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCoverflow:setResponseTouch",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CCoverflow_setResponseTouch'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CCoverflow_getIsHorizontal(lua_State* tolua_S)
{
    int argc = 0;
    CCoverflow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCoverflow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCoverflow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CCoverflow_getIsHorizontal'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CCoverflow_getIsHorizontal'", nullptr);
            return 0;
        }
        bool ret = cobj->getIsHorizontal();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCoverflow:getIsHorizontal",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CCoverflow_getIsHorizontal'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CCoverflow_getIsIgnoreScale(lua_State* tolua_S)
{
    int argc = 0;
    CCoverflow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCoverflow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCoverflow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CCoverflow_getIsIgnoreScale'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CCoverflow_getIsIgnoreScale'", nullptr);
            return 0;
        }
        bool ret = cobj->getIsIgnoreScale();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCoverflow:getIsIgnoreScale",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CCoverflow_getIsIgnoreScale'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CCoverflow_getSwPosition(lua_State* tolua_S)
{
    int argc = 0;
    CCoverflow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCoverflow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCoverflow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CCoverflow_getSwPosition'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CCoverflow_getSwPosition'", nullptr);
            return 0;
        }
        const cocos2d::Point& ret = cobj->getSwPosition();
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCoverflow:getSwPosition",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CCoverflow_getSwPosition'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CCoverflow_GetCardByIndex(lua_State* tolua_S)
{
    int argc = 0;
    CCoverflow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCoverflow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCoverflow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CCoverflow_GetCardByIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CCoverflow:GetCardByIndex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CCoverflow_GetCardByIndex'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->GetCardByIndex(arg0);
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCoverflow:GetCardByIndex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CCoverflow_GetCardByIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CCoverflow_scrollViewDidZoom(lua_State* tolua_S)
{
    int argc = 0;
    CCoverflow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCoverflow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCoverflow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CCoverflow_scrollViewDidZoom'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::extension::ScrollView* arg0;

        ok &= luaval_to_object<cocos2d::extension::ScrollView>(tolua_S, 2, "cc.ScrollView",&arg0, "CCoverflow:scrollViewDidZoom");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CCoverflow_scrollViewDidZoom'", nullptr);
            return 0;
        }
        cobj->scrollViewDidZoom(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCoverflow:scrollViewDidZoom",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CCoverflow_scrollViewDidZoom'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CCoverflow_setCardNum(lua_State* tolua_S)
{
    int argc = 0;
    CCoverflow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCoverflow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCoverflow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CCoverflow_setCardNum'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "CCoverflow:setCardNum");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CCoverflow_setCardNum'", nullptr);
            return 0;
        }
        cobj->setCardNum(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCoverflow:setCardNum",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CCoverflow_setCardNum'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CCoverflow_AdjustEndScrollView(lua_State* tolua_S)
{
    int argc = 0;
    CCoverflow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCoverflow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCoverflow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CCoverflow_AdjustEndScrollView'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CCoverflow_AdjustEndScrollView'", nullptr);
            return 0;
        }
        cobj->AdjustEndScrollView();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCoverflow:AdjustEndScrollView",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CCoverflow_AdjustEndScrollView'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CCoverflow_setSlayerPosition(lua_State* tolua_S)
{
    int argc = 0;
    CCoverflow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCoverflow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCoverflow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CCoverflow_setSlayerPosition'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;

        ok &= luaval_to_point(tolua_S, 2, &arg0, "CCoverflow:setSlayerPosition");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CCoverflow_setSlayerPosition'", nullptr);
            return 0;
        }
        cobj->setSlayerPosition(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCoverflow:setSlayerPosition",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CCoverflow_setSlayerPosition'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CCoverflow_AdjustScrollView(lua_State* tolua_S)
{
    int argc = 0;
    CCoverflow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCoverflow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCoverflow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CCoverflow_AdjustScrollView'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;

        ok &= luaval_to_point(tolua_S, 2, &arg0, "CCoverflow:AdjustScrollView");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CCoverflow_AdjustScrollView'", nullptr);
            return 0;
        }
        cobj->AdjustScrollView(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCoverflow:AdjustScrollView",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CCoverflow_AdjustScrollView'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CCoverflow_getSwBox(lua_State* tolua_S)
{
    int argc = 0;
    CCoverflow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCoverflow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCoverflow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CCoverflow_getSwBox'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CCoverflow_getSwBox'", nullptr);
            return 0;
        }
        const cocos2d::Rect& ret = cobj->getSwBox();
        rect_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCoverflow:getSwBox",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CCoverflow_getSwBox'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CCoverflow_setIsHorizontal(lua_State* tolua_S)
{
    int argc = 0;
    CCoverflow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCoverflow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCoverflow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CCoverflow_setIsHorizontal'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "CCoverflow:setIsHorizontal");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CCoverflow_setIsHorizontal'", nullptr);
            return 0;
        }
        cobj->setIsHorizontal(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCoverflow:setIsHorizontal",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CCoverflow_setIsHorizontal'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CCoverflow_GetCurCardIndex(lua_State* tolua_S)
{
    int argc = 0;
    CCoverflow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCoverflow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCoverflow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CCoverflow_GetCurCardIndex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CCoverflow_GetCurCardIndex'", nullptr);
            return 0;
        }
        int ret = cobj->GetCurCardIndex();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCoverflow:GetCurCardIndex",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CCoverflow_GetCurCardIndex'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CCoverflow_getScrollLayer(lua_State* tolua_S)
{
    int argc = 0;
    CCoverflow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCoverflow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCoverflow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CCoverflow_getScrollLayer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CCoverflow_getScrollLayer'", nullptr);
            return 0;
        }
        cocos2d::Layer* ret = cobj->getScrollLayer();
        object_to_luaval<cocos2d::Layer>(tolua_S, "cc.Layer",(cocos2d::Layer*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCoverflow:getScrollLayer",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CCoverflow_getScrollLayer'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CCoverflow_getDisDistance(lua_State* tolua_S)
{
    int argc = 0;
    CCoverflow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCoverflow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCoverflow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CCoverflow_getDisDistance'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CCoverflow_getDisDistance'", nullptr);
            return 0;
        }
        double ret = cobj->getDisDistance();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCoverflow:getDisDistance",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CCoverflow_getDisDistance'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CCoverflow_getSlSize(lua_State* tolua_S)
{
    int argc = 0;
    CCoverflow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCoverflow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCoverflow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CCoverflow_getSlSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CCoverflow_getSlSize'", nullptr);
            return 0;
        }
        const cocos2d::Size& ret = cobj->getSlSize();
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCoverflow:getSlSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CCoverflow_getSlSize'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CCoverflow_setSwBox(lua_State* tolua_S)
{
    int argc = 0;
    CCoverflow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCoverflow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCoverflow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CCoverflow_setSwBox'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Rect arg0;

        ok &= luaval_to_rect(tolua_S, 2, &arg0, "CCoverflow:setSwBox");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CCoverflow_setSwBox'", nullptr);
            return 0;
        }
        cobj->setSwBox(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCoverflow:setSwBox",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CCoverflow_setSwBox'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CCoverflow_setDisDistance(lua_State* tolua_S)
{
    int argc = 0;
    CCoverflow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCoverflow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCoverflow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CCoverflow_setDisDistance'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "CCoverflow:setDisDistance");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CCoverflow_setDisDistance'", nullptr);
            return 0;
        }
        cobj->setDisDistance(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCoverflow:setDisDistance",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CCoverflow_setDisDistance'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CCoverflow_getSwSize(lua_State* tolua_S)
{
    int argc = 0;
    CCoverflow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CCoverflow",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CCoverflow*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CCoverflow_getSwSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CCoverflow_getSwSize'", nullptr);
            return 0;
        }
        const cocos2d::Size& ret = cobj->getSwSize();
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCoverflow:getSwSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CCoverflow_getSwSize'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CCoverflow_Create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CCoverflow",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 4)
    {
        cocos2d::Rect arg0;
        cocos2d::Size arg1;
        double arg2;
        double arg3;
        ok &= luaval_to_rect(tolua_S, 2, &arg0, "CCoverflow:Create");
        ok &= luaval_to_size(tolua_S, 3, &arg1, "CCoverflow:Create");
        ok &= luaval_to_number(tolua_S, 4,&arg2, "CCoverflow:Create");
        ok &= luaval_to_number(tolua_S, 5,&arg3, "CCoverflow:Create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CCoverflow_Create'", nullptr);
            return 0;
        }
        CCoverflow* ret = CCoverflow::Create(arg0, arg1, arg2, arg3);
        object_to_luaval<CCoverflow>(tolua_S, "CCoverflow",(CCoverflow*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CCoverflow:Create",argc, 4);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CCoverflow_Create'.",&tolua_err);
#endif
    return 0;
}
int lua_woool_CCoverflow_constructor(lua_State* tolua_S)
{
    int argc = 0;
    CCoverflow* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CCoverflow_constructor'", nullptr);
            return 0;
        }
        cobj = new CCoverflow();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"CCoverflow");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CCoverflow:CCoverflow",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CCoverflow_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_woool_CCoverflow_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CCoverflow)");
    return 0;
}

int lua_register_woool_CCoverflow(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CCoverflow");
    tolua_cclass(tolua_S,"CCoverflow","CCoverflow","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"CCoverflow");
        tolua_function(tolua_S,"new",lua_woool_CCoverflow_constructor);
        tolua_function(tolua_S,"AddCard",lua_woool_CCoverflow_AddCard);
        tolua_function(tolua_S,"setIsIgnoreScale",lua_woool_CCoverflow_setIsIgnoreScale);
        tolua_function(tolua_S,"StartMiddleIndex",lua_woool_CCoverflow_StartMiddleIndex);
        tolua_function(tolua_S,"scrollViewDidScroll",lua_woool_CCoverflow_scrollViewDidScroll);
        tolua_function(tolua_S,"getIsMove",lua_woool_CCoverflow_getIsMove);
        tolua_function(tolua_S,"setSwSize",lua_woool_CCoverflow_setSwSize);
        tolua_function(tolua_S,"setSlSize",lua_woool_CCoverflow_setSlSize);
        tolua_function(tolua_S,"getOffsetPosition",lua_woool_CCoverflow_getOffsetPosition);
        tolua_function(tolua_S,"setIsMove",lua_woool_CCoverflow_setIsMove);
        tolua_function(tolua_S,"setScrollLayer",lua_woool_CCoverflow_setScrollLayer);
        tolua_function(tolua_S,"setOffsetPosition",lua_woool_CCoverflow_setOffsetPosition);
        tolua_function(tolua_S,"getCardNum",lua_woool_CCoverflow_getCardNum);
        tolua_function(tolua_S,"getResponseTouch",lua_woool_CCoverflow_getResponseTouch);
        tolua_function(tolua_S,"getDisScale",lua_woool_CCoverflow_getDisScale);
        tolua_function(tolua_S,"AdjustCardScale",lua_woool_CCoverflow_AdjustCardScale);
        tolua_function(tolua_S,"getSlayerPosition",lua_woool_CCoverflow_getSlayerPosition);
        tolua_function(tolua_S,"setSwPosition",lua_woool_CCoverflow_setSwPosition);
        tolua_function(tolua_S,"setDisScale",lua_woool_CCoverflow_setDisScale);
        tolua_function(tolua_S,"setResponseTouch",lua_woool_CCoverflow_setResponseTouch);
        tolua_function(tolua_S,"getIsHorizontal",lua_woool_CCoverflow_getIsHorizontal);
        tolua_function(tolua_S,"getIsIgnoreScale",lua_woool_CCoverflow_getIsIgnoreScale);
        tolua_function(tolua_S,"getSwPosition",lua_woool_CCoverflow_getSwPosition);
        tolua_function(tolua_S,"GetCardByIndex",lua_woool_CCoverflow_GetCardByIndex);
        tolua_function(tolua_S,"scrollViewDidZoom",lua_woool_CCoverflow_scrollViewDidZoom);
        tolua_function(tolua_S,"setCardNum",lua_woool_CCoverflow_setCardNum);
        tolua_function(tolua_S,"AdjustEndScrollView",lua_woool_CCoverflow_AdjustEndScrollView);
        tolua_function(tolua_S,"setSlayerPosition",lua_woool_CCoverflow_setSlayerPosition);
        tolua_function(tolua_S,"AdjustScrollView",lua_woool_CCoverflow_AdjustScrollView);
        tolua_function(tolua_S,"getSwBox",lua_woool_CCoverflow_getSwBox);
        tolua_function(tolua_S,"setIsHorizontal",lua_woool_CCoverflow_setIsHorizontal);
        tolua_function(tolua_S,"GetCurCardIndex",lua_woool_CCoverflow_GetCurCardIndex);
        tolua_function(tolua_S,"getScrollLayer",lua_woool_CCoverflow_getScrollLayer);
        tolua_function(tolua_S,"getDisDistance",lua_woool_CCoverflow_getDisDistance);
        tolua_function(tolua_S,"getSlSize",lua_woool_CCoverflow_getSlSize);
        tolua_function(tolua_S,"setSwBox",lua_woool_CCoverflow_setSwBox);
        tolua_function(tolua_S,"setDisDistance",lua_woool_CCoverflow_setDisDistance);
        tolua_function(tolua_S,"getSwSize",lua_woool_CCoverflow_getSwSize);
        tolua_function(tolua_S,"Create", lua_woool_CCoverflow_Create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CCoverflow).name();
    g_luaType[typeName] = "CCoverflow";
    g_typeCast["CCoverflow"] = "CCoverflow";
    return 1;
}

int lua_woool_CIrregularButton_HitTest(lua_State* tolua_S)
{
    int argc = 0;
    CIrregularButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CIrregularButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CIrregularButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CIrregularButton_HitTest'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Vec2 arg0;

        ok &= luaval_to_vec2(tolua_S, 2, &arg0, "CIrregularButton:HitTest");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CIrregularButton_HitTest'", nullptr);
            return 0;
        }
        bool ret = cobj->HitTest(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CIrregularButton:HitTest",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CIrregularButton_HitTest'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CIrregularButton_SetSwallowByAlpha(lua_State* tolua_S)
{
    int argc = 0;
    CIrregularButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"CIrregularButton",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (CIrregularButton*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_CIrregularButton_SetSwallowByAlpha'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "CIrregularButton:SetSwallowByAlpha");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CIrregularButton_SetSwallowByAlpha'", nullptr);
            return 0;
        }
        cobj->SetSwallowByAlpha(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CIrregularButton:SetSwallowByAlpha",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CIrregularButton_SetSwallowByAlpha'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_CIrregularButton_Create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"CIrregularButton",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 1)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "CIrregularButton:Create");
            if (!ok) { break; }
            CIrregularButton* ret = CIrregularButton::Create(arg0);
            object_to_luaval<CIrregularButton>(tolua_S, "CIrregularButton",(CIrregularButton*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 2)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "CIrregularButton:Create");
            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1, "CIrregularButton:Create");
            if (!ok) { break; }
            CIrregularButton* ret = CIrregularButton::Create(arg0, arg1);
            object_to_luaval<CIrregularButton>(tolua_S, "CIrregularButton",(CIrregularButton*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 3)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "CIrregularButton:Create");
            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1, "CIrregularButton:Create");
            if (!ok) { break; }
            std::string arg2;
            ok &= luaval_to_std_string(tolua_S, 4,&arg2, "CIrregularButton:Create");
            if (!ok) { break; }
            CIrregularButton* ret = CIrregularButton::Create(arg0, arg1, arg2);
            object_to_luaval<CIrregularButton>(tolua_S, "CIrregularButton",(CIrregularButton*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 4)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "CIrregularButton:Create");
            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1, "CIrregularButton:Create");
            if (!ok) { break; }
            std::string arg2;
            ok &= luaval_to_std_string(tolua_S, 4,&arg2, "CIrregularButton:Create");
            if (!ok) { break; }
            cocos2d::ui::Widget::TextureResType arg3;
            ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "CIrregularButton:Create");
            if (!ok) { break; }
            CIrregularButton* ret = CIrregularButton::Create(arg0, arg1, arg2, arg3);
            object_to_luaval<CIrregularButton>(tolua_S, "CIrregularButton",(CIrregularButton*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 0)
        {
            CIrregularButton* ret = CIrregularButton::Create();
            object_to_luaval<CIrregularButton>(tolua_S, "CIrregularButton",(CIrregularButton*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "CIrregularButton:Create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CIrregularButton_Create'.",&tolua_err);
#endif
    return 0;
}
int lua_woool_CIrregularButton_constructor(lua_State* tolua_S)
{
    int argc = 0;
    CIrregularButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_CIrregularButton_constructor'", nullptr);
            return 0;
        }
        cobj = new CIrregularButton();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"CIrregularButton");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "CIrregularButton:CIrregularButton",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_woool_CIrregularButton_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_woool_CIrregularButton_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (CIrregularButton)");
    return 0;
}

int lua_register_woool_CIrregularButton(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"CIrregularButton");
    tolua_cclass(tolua_S,"CIrregularButton","CIrregularButton","ccui.Button",nullptr);

    tolua_beginmodule(tolua_S,"CIrregularButton");
        tolua_function(tolua_S,"new",lua_woool_CIrregularButton_constructor);
        tolua_function(tolua_S,"HitTest",lua_woool_CIrregularButton_HitTest);
        tolua_function(tolua_S,"SetSwallowByAlpha",lua_woool_CIrregularButton_SetSwallowByAlpha);
        tolua_function(tolua_S,"Create", lua_woool_CIrregularButton_Create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(CIrregularButton).name();
    g_luaType[typeName] = "CIrregularButton";
    g_typeCast["CIrregularButton"] = "CIrregularButton";
    return 1;
}

int lua_woool_MenuButton_getSmallToBigMode(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MenuButton_getSmallToBigMode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MenuButton_getSmallToBigMode'", nullptr);
            return 0;
        }
        bool ret = cobj->getSmallToBigMode();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MenuButton:getSmallToBigMode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MenuButton_getSmallToBigMode'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MenuButton_setSelectAction(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MenuButton_setSelectAction'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Action* arg0;

        ok &= luaval_to_object<cocos2d::Action>(tolua_S, 2, "cc.Action",&arg0, "MenuButton:setSelectAction");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MenuButton_setSelectAction'", nullptr);
            return 0;
        }
        cobj->setSelectAction(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MenuButton:setSelectAction",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MenuButton_setSelectAction'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MenuButton_setSmallToBigMode(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MenuButton_setSmallToBigMode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "MenuButton:setSmallToBigMode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MenuButton_setSmallToBigMode'", nullptr);
            return 0;
        }
        cobj->setSmallToBigMode(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MenuButton:setSmallToBigMode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MenuButton_setSmallToBigMode'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MenuButton_setUnSelectAction(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MenuButton_setUnSelectAction'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Action* arg0;

        ok &= luaval_to_object<cocos2d::Action>(tolua_S, 2, "cc.Action",&arg0, "MenuButton:setUnSelectAction");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MenuButton_setUnSelectAction'", nullptr);
            return 0;
        }
        cobj->setUnSelectAction(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MenuButton:setUnSelectAction",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MenuButton_setUnSelectAction'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MenuButton_blink(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MenuButton_blink'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MenuButton_blink'", nullptr);
            return 0;
        }
        cobj->blink();
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "MenuButton:blink");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MenuButton_blink'", nullptr);
            return 0;
        }
        cobj->blink(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MenuButton:blink",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MenuButton_blink'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MenuButton_setImages(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MenuButton_setImages'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "MenuButton:setImages");

            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1, "MenuButton:setImages");

            if (!ok) { break; }
            cobj->setImages(arg0, arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "MenuButton:setImages");

            if (!ok) { break; }
            cobj->setImages(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "MenuButton:setImages",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MenuButton_setImages'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MenuButton_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"MenuButton",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 2)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "MenuButton:create");
            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1, "MenuButton:create");
            if (!ok) { break; }
            MenuButton* ret = MenuButton::create(arg0, arg1);
            object_to_luaval<MenuButton>(tolua_S, "MenuButton",(MenuButton*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 1)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "MenuButton:create");
            if (!ok) { break; }
            MenuButton* ret = MenuButton::create(arg0);
            object_to_luaval<MenuButton>(tolua_S, "MenuButton",(MenuButton*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 3)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "MenuButton:create");
            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1, "MenuButton:create");
            if (!ok) { break; }
            std::string arg2;
            ok &= luaval_to_std_string(tolua_S, 4,&arg2, "MenuButton:create");
            if (!ok) { break; }
            MenuButton* ret = MenuButton::create(arg0, arg1, arg2);
            object_to_luaval<MenuButton>(tolua_S, "MenuButton",(MenuButton*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "MenuButton:create",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MenuButton_create'.",&tolua_err);
#endif
    return 0;
}
int lua_woool_MenuButton_constructor(lua_State* tolua_S)
{
    int argc = 0;
    MenuButton* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MenuButton_constructor'", nullptr);
            return 0;
        }
        cobj = new MenuButton();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"MenuButton");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MenuButton:MenuButton",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MenuButton_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_woool_MenuButton_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (MenuButton)");
    return 0;
}

int lua_register_woool_MenuButton(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"MenuButton");
    tolua_cclass(tolua_S,"MenuButton","MenuButton","cc.MenuItemImage",nullptr);

    tolua_beginmodule(tolua_S,"MenuButton");
        tolua_function(tolua_S,"new",lua_woool_MenuButton_constructor);
        tolua_function(tolua_S,"getSmallToBigMode",lua_woool_MenuButton_getSmallToBigMode);
        tolua_function(tolua_S,"setSelectAction",lua_woool_MenuButton_setSelectAction);
        tolua_function(tolua_S,"setSmallToBigMode",lua_woool_MenuButton_setSmallToBigMode);
        tolua_function(tolua_S,"setUnSelectAction",lua_woool_MenuButton_setUnSelectAction);
        tolua_function(tolua_S,"blink",lua_woool_MenuButton_blink);
        tolua_function(tolua_S,"setImages",lua_woool_MenuButton_setImages);
        tolua_function(tolua_S,"create", lua_woool_MenuButton_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(MenuButton).name();
    g_luaType[typeName] = "MenuButton";
    g_typeCast["MenuButton"] = "MenuButton";
    return 1;
}

int lua_woool_BtnContainer_addItem(lua_State* tolua_S)
{
    int argc = 0;
    BtnContainer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BtnContainer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (BtnContainer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_BtnContainer_addItem'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        MenuButton* arg0;

        ok &= luaval_to_object<MenuButton>(tolua_S, 2, "MenuButton",&arg0, "BtnContainer:addItem");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_BtnContainer_addItem'", nullptr);
            return 0;
        }
        cobj->addItem(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "BtnContainer:addItem",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_BtnContainer_addItem'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_BtnContainer_setTopTag(lua_State* tolua_S)
{
    int argc = 0;
    BtnContainer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BtnContainer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (BtnContainer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_BtnContainer_setTopTag'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "BtnContainer:setTopTag");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_BtnContainer_setTopTag'", nullptr);
            return 0;
        }
        cobj->setTopTag(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "BtnContainer:setTopTag",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_BtnContainer_setTopTag'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_BtnContainer_changeFullShortMode(lua_State* tolua_S)
{
    int argc = 0;
    BtnContainer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BtnContainer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (BtnContainer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_BtnContainer_changeFullShortMode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_BtnContainer_changeFullShortMode'", nullptr);
            return 0;
        }
        cobj->changeFullShortMode();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "BtnContainer:changeFullShortMode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_BtnContainer_changeFullShortMode'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_BtnContainer_setFullMode(lua_State* tolua_S)
{
    int argc = 0;
    BtnContainer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BtnContainer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (BtnContainer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_BtnContainer_setFullMode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_BtnContainer_setFullMode'", nullptr);
            return 0;
        }
        cobj->setFullMode();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "BtnContainer:setFullMode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_BtnContainer_setFullMode'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_BtnContainer_getTopTag(lua_State* tolua_S)
{
    int argc = 0;
    BtnContainer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BtnContainer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (BtnContainer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_BtnContainer_getTopTag'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_BtnContainer_getTopTag'", nullptr);
            return 0;
        }
        int ret = cobj->getTopTag();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "BtnContainer:getTopTag",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_BtnContainer_getTopTag'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_BtnContainer_setShortMode(lua_State* tolua_S)
{
    int argc = 0;
    BtnContainer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"BtnContainer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (BtnContainer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_BtnContainer_setShortMode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_BtnContainer_setShortMode'", nullptr);
            return 0;
        }
        cobj->setShortMode();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "BtnContainer:setShortMode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_BtnContainer_setShortMode'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_BtnContainer_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"BtnContainer",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 1)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "BtnContainer:create");
            if (!ok) { break; }
            BtnContainer* ret = BtnContainer::create(arg0);
            object_to_luaval<BtnContainer>(tolua_S, "BtnContainer",(BtnContainer*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 2)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "BtnContainer:create");
            if (!ok) { break; }
            double arg1;
            ok &= luaval_to_number(tolua_S, 3,&arg1, "BtnContainer:create");
            if (!ok) { break; }
            BtnContainer* ret = BtnContainer::create(arg0, arg1);
            object_to_luaval<BtnContainer>(tolua_S, "BtnContainer",(BtnContainer*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "BtnContainer:create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_BtnContainer_create'.",&tolua_err);
#endif
    return 0;
}
int lua_woool_BtnContainer_createTopContainer(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"BtnContainer",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 1)
        {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "BtnContainer:createTopContainer");
            if (!ok) { break; }
            BtnContainer* ret = BtnContainer::createTopContainer(arg0);
            object_to_luaval<BtnContainer>(tolua_S, "BtnContainer",(BtnContainer*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 2)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "BtnContainer:createTopContainer");
            if (!ok) { break; }
            double arg1;
            ok &= luaval_to_number(tolua_S, 3,&arg1, "BtnContainer:createTopContainer");
            if (!ok) { break; }
            BtnContainer* ret = BtnContainer::createTopContainer(arg0, arg1);
            object_to_luaval<BtnContainer>(tolua_S, "BtnContainer",(BtnContainer*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "BtnContainer:createTopContainer",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_BtnContainer_createTopContainer'.",&tolua_err);
#endif
    return 0;
}
int lua_woool_BtnContainer_constructor(lua_State* tolua_S)
{
    int argc = 0;
    BtnContainer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_BtnContainer_constructor'", nullptr);
            return 0;
        }
        cobj = new BtnContainer();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"BtnContainer");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "BtnContainer:BtnContainer",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_woool_BtnContainer_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_woool_BtnContainer_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (BtnContainer)");
    return 0;
}

int lua_register_woool_BtnContainer(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"BtnContainer");
    tolua_cclass(tolua_S,"BtnContainer","BtnContainer","cc.Sprite",nullptr);

    tolua_beginmodule(tolua_S,"BtnContainer");
        tolua_function(tolua_S,"new",lua_woool_BtnContainer_constructor);
        tolua_function(tolua_S,"addItem",lua_woool_BtnContainer_addItem);
        tolua_function(tolua_S,"setTopTag",lua_woool_BtnContainer_setTopTag);
        tolua_function(tolua_S,"changeFullShortMode",lua_woool_BtnContainer_changeFullShortMode);
        tolua_function(tolua_S,"setFullMode",lua_woool_BtnContainer_setFullMode);
        tolua_function(tolua_S,"getTopTag",lua_woool_BtnContainer_getTopTag);
        tolua_function(tolua_S,"setShortMode",lua_woool_BtnContainer_setShortMode);
        tolua_function(tolua_S,"create", lua_woool_BtnContainer_create);
        tolua_function(tolua_S,"createTopContainer", lua_woool_BtnContainer_createTopContainer);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(BtnContainer).name();
    g_luaType[typeName] = "BtnContainer";
    g_typeCast["BtnContainer"] = "BtnContainer";
    return 1;
}

int lua_woool_OperateLayer_setCenterPoint(lua_State* tolua_S)
{
    int argc = 0;
    OperateLayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"OperateLayer",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (OperateLayer*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_OperateLayer_setCenterPoint'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;

        ok &= luaval_to_point(tolua_S, 2, &arg0, "OperateLayer:setCenterPoint");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_OperateLayer_setCenterPoint'", nullptr);
            return 0;
        }
        cobj->setCenterPoint(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "OperateLayer:setCenterPoint",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_OperateLayer_setCenterPoint'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_OperateLayer_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"OperateLayer",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_OperateLayer_create'", nullptr);
            return 0;
        }
        OperateLayer* ret = OperateLayer::create();
        object_to_luaval<OperateLayer>(tolua_S, "OperateLayer",(OperateLayer*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "OperateLayer:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_OperateLayer_create'.",&tolua_err);
#endif
    return 0;
}
int lua_woool_OperateLayer_constructor(lua_State* tolua_S)
{
    int argc = 0;
    OperateLayer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_OperateLayer_constructor'", nullptr);
            return 0;
        }
        cobj = new OperateLayer();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"OperateLayer");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "OperateLayer:OperateLayer",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_woool_OperateLayer_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_woool_OperateLayer_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (OperateLayer)");
    return 0;
}

int lua_register_woool_OperateLayer(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"OperateLayer");
    tolua_cclass(tolua_S,"OperateLayer","OperateLayer","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"OperateLayer");
        tolua_function(tolua_S,"new",lua_woool_OperateLayer_constructor);
        tolua_function(tolua_S,"setCenterPoint",lua_woool_OperateLayer_setCenterPoint);
        tolua_function(tolua_S,"create", lua_woool_OperateLayer_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(OperateLayer).name();
    g_luaType[typeName] = "OperateLayer";
    g_typeCast["OperateLayer"] = "OperateLayer";
    return 1;
}
*/
int lua_woool_MakeNumbers_createWithSymbol(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"MakeNumbers",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 3)
    {
        std::string arg0;
        int arg1;
        int arg2;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "MakeNumbers:createWithSymbol");
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "MakeNumbers:createWithSymbol");
        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "MakeNumbers:createWithSymbol");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MakeNumbers_createWithSymbol'", nullptr);
            return 0;
        }
        MakeNumbers* ret = MakeNumbers::createWithSymbol(arg0, arg1, arg2);
        object_to_luaval<MakeNumbers>(tolua_S, "MakeNumbers",(MakeNumbers*)ret);
        return 1;
    }
    if (argc == 4)
    {
        std::string arg0;
        int arg1;
        int arg2;
        bool arg3;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "MakeNumbers:createWithSymbol");
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "MakeNumbers:createWithSymbol");
        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "MakeNumbers:createWithSymbol");
        ok &= luaval_to_boolean(tolua_S, 5,&arg3, "MakeNumbers:createWithSymbol");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MakeNumbers_createWithSymbol'", nullptr);
            return 0;
        }
        MakeNumbers* ret = MakeNumbers::createWithSymbol(arg0, arg1, arg2, arg3);
        object_to_luaval<MakeNumbers>(tolua_S, "MakeNumbers",(MakeNumbers*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "MakeNumbers:createWithSymbol",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MakeNumbers_createWithSymbol'.",&tolua_err);
#endif
    return 0;
}
int lua_woool_MakeNumbers_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"MakeNumbers",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 3)
    {
        std::string arg0;
        int arg1;
        int arg2;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "MakeNumbers:create");
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "MakeNumbers:create");
        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "MakeNumbers:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MakeNumbers_create'", nullptr);
            return 0;
        }
        MakeNumbers* ret = MakeNumbers::create(arg0, arg1, arg2);
        object_to_luaval<MakeNumbers>(tolua_S, "MakeNumbers",(MakeNumbers*)ret);
        return 1;
    }
    if (argc == 4)
    {
        std::string arg0;
        int arg1;
        int arg2;
        bool arg3;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "MakeNumbers:create");
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "MakeNumbers:create");
        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "MakeNumbers:create");
        ok &= luaval_to_boolean(tolua_S, 5,&arg3, "MakeNumbers:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MakeNumbers_create'", nullptr);
            return 0;
        }
        MakeNumbers* ret = MakeNumbers::create(arg0, arg1, arg2, arg3);
        object_to_luaval<MakeNumbers>(tolua_S, "MakeNumbers",(MakeNumbers*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "MakeNumbers:create",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MakeNumbers_create'.",&tolua_err);
#endif
    return 0;
}
int lua_woool_MakeNumbers_constructor(lua_State* tolua_S)
{
    int argc = 0;
    MakeNumbers* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MakeNumbers_constructor'", nullptr);
            return 0;
        }
        cobj = new MakeNumbers();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"MakeNumbers");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MakeNumbers:MakeNumbers",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MakeNumbers_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_woool_MakeNumbers_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (MakeNumbers)");
    return 0;
}

int lua_register_woool_MakeNumbers(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"MakeNumbers");
    tolua_cclass(tolua_S,"MakeNumbers","MakeNumbers","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"MakeNumbers");
        tolua_function(tolua_S,"new",lua_woool_MakeNumbers_constructor);
        tolua_function(tolua_S,"createWithSymbol", lua_woool_MakeNumbers_createWithSymbol);
        tolua_function(tolua_S,"create", lua_woool_MakeNumbers_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(MakeNumbers).name();
    g_luaType[typeName] = "MakeNumbers";
    g_typeCast["MakeNumbers"] = "MakeNumbers";
    return 1;
}

int lua_woool_DirtyWords_Init(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"DirtyWords",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_DirtyWords_Init'", nullptr);
            return 0;
        }
        DirtyWords::Init();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "DirtyWords:Init",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_DirtyWords_Init'.",&tolua_err);
#endif
    return 0;
}
int lua_woool_DirtyWords_isHaveDirytWords(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"DirtyWords",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "DirtyWords:isHaveDirytWords");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_DirtyWords_isHaveDirytWords'", nullptr);
            return 0;
        }
        bool ret = DirtyWords::isHaveDirytWords(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "DirtyWords:isHaveDirytWords",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_DirtyWords_isHaveDirytWords'.",&tolua_err);
#endif
    return 0;
}
int lua_woool_DirtyWords_checkAndReplaceDirtyWords(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"DirtyWords",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "DirtyWords:checkAndReplaceDirtyWords");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_DirtyWords_checkAndReplaceDirtyWords'", nullptr);
            return 0;
        }
        std::string ret = DirtyWords::checkAndReplaceDirtyWords(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    if (argc == 2)
    {
        std::string arg0;
        std::string arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "DirtyWords:checkAndReplaceDirtyWords");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "DirtyWords:checkAndReplaceDirtyWords");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_DirtyWords_checkAndReplaceDirtyWords'", nullptr);
            return 0;
        }
        std::string ret = DirtyWords::checkAndReplaceDirtyWords(arg0, arg1);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "DirtyWords:checkAndReplaceDirtyWords",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_DirtyWords_checkAndReplaceDirtyWords'.",&tolua_err);
#endif
    return 0;
}
int lua_woool_DirtyWords_constructor(lua_State* tolua_S)
{
    int argc = 0;
    DirtyWords* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_DirtyWords_constructor'", nullptr);
            return 0;
        }
        cobj = new DirtyWords();
        tolua_pushusertype(tolua_S,(void*)cobj,"DirtyWords");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "DirtyWords:DirtyWords",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_woool_DirtyWords_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_woool_DirtyWords_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (DirtyWords)");
    return 0;
}

int lua_register_woool_DirtyWords(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"DirtyWords");
    tolua_cclass(tolua_S,"DirtyWords","DirtyWords","",nullptr);

    tolua_beginmodule(tolua_S,"DirtyWords");
        tolua_function(tolua_S,"new",lua_woool_DirtyWords_constructor);
        tolua_function(tolua_S,"Init", lua_woool_DirtyWords_Init);
        tolua_function(tolua_S,"isHaveDirytWords", lua_woool_DirtyWords_isHaveDirytWords);
        tolua_function(tolua_S,"checkAndReplaceDirtyWords", lua_woool_DirtyWords_checkAndReplaceDirtyWords);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(DirtyWords).name();
    g_luaType[typeName] = "DirtyWords";
    g_typeCast["DirtyWords"] = "DirtyWords";
    return 1;
}

int lua_woool_MirBatchDrawLabel_setEffectColor(lua_State* tolua_S)
{
    int argc = 0;
    MirBatchDrawLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirBatchDrawLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirBatchDrawLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MirBatchDrawLabel_setEffectColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color3B arg0;

        ok &= luaval_to_color3b(tolua_S, 2, &arg0, "MirBatchDrawLabel:setEffectColor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MirBatchDrawLabel_setEffectColor'", nullptr);
            return 0;
        }
        cobj->setEffectColor(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirBatchDrawLabel:setEffectColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MirBatchDrawLabel_setEffectColor'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MirBatchDrawLabel_removeLabel(lua_State* tolua_S)
{
    int argc = 0;
    MirBatchDrawLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirBatchDrawLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirBatchDrawLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MirBatchDrawLabel_removeLabel'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        MirTextNode* arg0;

        ok &= luaval_to_object<MirTextNode>(tolua_S, 2, "MirTextNode",&arg0, "MirBatchDrawLabel:removeLabel");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MirBatchDrawLabel_removeLabel'", nullptr);
            return 0;
        }
        cobj->removeLabel(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirBatchDrawLabel:removeLabel",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MirBatchDrawLabel_removeLabel'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MirBatchDrawLabel_setTTFConfig(lua_State* tolua_S)
{
    int argc = 0;
    MirBatchDrawLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirBatchDrawLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirBatchDrawLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MirBatchDrawLabel_setTTFConfig'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::_ttfConfig arg0;

        ok &= luaval_to_ttfconfig(tolua_S, 2, &arg0, "MirBatchDrawLabel:setTTFConfig");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MirBatchDrawLabel_setTTFConfig'", nullptr);
            return 0;
        }
        bool ret = cobj->setTTFConfig(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirBatchDrawLabel:setTTFConfig",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MirBatchDrawLabel_setTTFConfig'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MirBatchDrawLabel_setBaseOffset(lua_State* tolua_S)
{
    int argc = 0;
    MirBatchDrawLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirBatchDrawLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirBatchDrawLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MirBatchDrawLabel_setBaseOffset'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Vec2 arg0;

        ok &= luaval_to_vec2(tolua_S, 2, &arg0, "MirBatchDrawLabel:setBaseOffset");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MirBatchDrawLabel_setBaseOffset'", nullptr);
            return 0;
        }
        cobj->setBaseOffset(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirBatchDrawLabel:setBaseOffset",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MirBatchDrawLabel_setBaseOffset'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MirBatchDrawLabel_getTTFConfig(lua_State* tolua_S)
{
    int argc = 0;
    MirBatchDrawLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirBatchDrawLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirBatchDrawLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MirBatchDrawLabel_getTTFConfig'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MirBatchDrawLabel_getTTFConfig'", nullptr);
            return 0;
        }
        const cocos2d::_ttfConfig& ret = cobj->getTTFConfig();
        ttfconfig_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirBatchDrawLabel:getTTFConfig",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MirBatchDrawLabel_getTTFConfig'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MirBatchDrawLabel_createLabel(lua_State* tolua_S)
{
    int argc = 0;
    MirBatchDrawLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirBatchDrawLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirBatchDrawLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MirBatchDrawLabel_createLabel'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        std::string arg0;
        int arg1;
        cocos2d::Vec2 arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "MirBatchDrawLabel:createLabel");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "MirBatchDrawLabel:createLabel");

        ok &= luaval_to_vec2(tolua_S, 4, &arg2, "MirBatchDrawLabel:createLabel");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MirBatchDrawLabel_createLabel'", nullptr);
            return 0;
        }
        MirTextNode* ret = cobj->createLabel(arg0, arg1, arg2);
        object_to_luaval<MirTextNode>(tolua_S, "MirTextNode",(MirTextNode*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirBatchDrawLabel:createLabel",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MirBatchDrawLabel_createLabel'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MirBatchDrawLabel_setTextColor(lua_State* tolua_S)
{
    int argc = 0;
    MirBatchDrawLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirBatchDrawLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirBatchDrawLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MirBatchDrawLabel_setTextColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color3B arg0;

        ok &= luaval_to_color3b(tolua_S, 2, &arg0, "MirBatchDrawLabel:setTextColor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MirBatchDrawLabel_setTextColor'", nullptr);
            return 0;
        }
        cobj->setTextColor(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirBatchDrawLabel:setTextColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MirBatchDrawLabel_setTextColor'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MirBatchDrawLabel_getBaseOffset(lua_State* tolua_S)
{
    int argc = 0;
    MirBatchDrawLabel* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MirBatchDrawLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MirBatchDrawLabel*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MirBatchDrawLabel_getBaseOffset'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MirBatchDrawLabel_getBaseOffset'", nullptr);
            return 0;
        }
        cocos2d::Vec2 ret = cobj->getBaseOffset();
        vec2_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MirBatchDrawLabel:getBaseOffset",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MirBatchDrawLabel_getBaseOffset'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MirBatchDrawLabel_createWithTTF(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"MirBatchDrawLabel",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        cocos2d::_ttfConfig arg0;
        ok &= luaval_to_ttfconfig(tolua_S, 2, &arg0, "MirBatchDrawLabel:createWithTTF");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MirBatchDrawLabel_createWithTTF'", nullptr);
            return 0;
        }
        MirBatchDrawLabel* ret = MirBatchDrawLabel::createWithTTF(arg0);
        object_to_luaval<MirBatchDrawLabel>(tolua_S, "MirBatchDrawLabel",(MirBatchDrawLabel*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "MirBatchDrawLabel:createWithTTF",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MirBatchDrawLabel_createWithTTF'.",&tolua_err);
#endif
    return 0;
}
static int lua_woool_MirBatchDrawLabel_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (MirBatchDrawLabel)");
    return 0;
}

int lua_register_woool_MirBatchDrawLabel(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"MirBatchDrawLabel");
    tolua_cclass(tolua_S,"MirBatchDrawLabel","MirBatchDrawLabel","cc.Node",nullptr);

    tolua_beginmodule(tolua_S,"MirBatchDrawLabel");
        tolua_function(tolua_S,"setEffectColor",lua_woool_MirBatchDrawLabel_setEffectColor);
        tolua_function(tolua_S,"removeLabel",lua_woool_MirBatchDrawLabel_removeLabel);
        tolua_function(tolua_S,"setTTFConfig",lua_woool_MirBatchDrawLabel_setTTFConfig);
        tolua_function(tolua_S,"setBaseOffset",lua_woool_MirBatchDrawLabel_setBaseOffset);
        tolua_function(tolua_S,"getTTFConfig",lua_woool_MirBatchDrawLabel_getTTFConfig);
        tolua_function(tolua_S,"createLabel",lua_woool_MirBatchDrawLabel_createLabel);
        tolua_function(tolua_S,"setTextColor",lua_woool_MirBatchDrawLabel_setTextColor);
        tolua_function(tolua_S,"getBaseOffset",lua_woool_MirBatchDrawLabel_getBaseOffset);
        tolua_function(tolua_S,"createWithTTF", lua_woool_MirBatchDrawLabel_createWithTTF);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(MirBatchDrawLabel).name();
    g_luaType[typeName] = "MirBatchDrawLabel";
    g_typeCast["MirBatchDrawLabel"] = "MirBatchDrawLabel";
    return 1;
}

int lua_woool_MirTextNodeFormatter_alignText(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"MirTextNodeFormatter",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        MirTextNode* arg0;
        ok &= luaval_to_object<MirTextNode>(tolua_S, 2, "MirTextNode",&arg0, "MirTextNodeFormatter:alignText");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MirTextNodeFormatter_alignText'", nullptr);
            return 0;
        }
        bool ret = MirTextNodeFormatter::alignText(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "MirTextNodeFormatter:alignText",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MirTextNodeFormatter_alignText'.",&tolua_err);
#endif
    return 0;
}
int lua_woool_MirTextNodeFormatter_createStringSprites(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"MirTextNodeFormatter",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        MirTextNode* arg0;
        ok &= luaval_to_object<MirTextNode>(tolua_S, 2, "MirTextNode",&arg0, "MirTextNodeFormatter:createStringSprites");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MirTextNodeFormatter_createStringSprites'", nullptr);
            return 0;
        }
        bool ret = MirTextNodeFormatter::createStringSprites(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "MirTextNodeFormatter:createStringSprites",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MirTextNodeFormatter_createStringSprites'.",&tolua_err);
#endif
    return 0;
}
int lua_woool_MirTextNodeFormatter_multilineText(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"MirTextNodeFormatter",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        MirTextNode* arg0;
        ok &= luaval_to_object<MirTextNode>(tolua_S, 2, "MirTextNode",&arg0, "MirTextNodeFormatter:multilineText");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MirTextNodeFormatter_multilineText'", nullptr);
            return 0;
        }
        bool ret = MirTextNodeFormatter::multilineText(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "MirTextNodeFormatter:multilineText",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MirTextNodeFormatter_multilineText'.",&tolua_err);
#endif
    return 0;
}
static int lua_woool_MirTextNodeFormatter_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (MirTextNodeFormatter)");
    return 0;
}

int lua_register_woool_MirTextNodeFormatter(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"MirTextNodeFormatter");
    tolua_cclass(tolua_S,"MirTextNodeFormatter","MirTextNodeFormatter","",nullptr);

    tolua_beginmodule(tolua_S,"MirTextNodeFormatter");
        tolua_function(tolua_S,"alignText", lua_woool_MirTextNodeFormatter_alignText);
        tolua_function(tolua_S,"createStringSprites", lua_woool_MirTextNodeFormatter_createStringSprites);
        tolua_function(tolua_S,"multilineText", lua_woool_MirTextNodeFormatter_multilineText);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(MirTextNodeFormatter).name();
    g_luaType[typeName] = "MirTextNodeFormatter";
    g_typeCast["MirTextNodeFormatter"] = "MirTextNodeFormatter";
    return 1;
}
/*
int lua_woool_LuaMsgBuffer_popString(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_LuaMsgBuffer_popString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_LuaMsgBuffer_popString'", nullptr);
            return 0;
        }
        std::string ret = cobj->popString();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaMsgBuffer:popString",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_LuaMsgBuffer_popString'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_LuaMsgBuffer_pushUChar(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_LuaMsgBuffer_pushUChar'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0, "LuaMsgBuffer:pushUChar");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_LuaMsgBuffer_pushUChar'", nullptr);
            return 0;
        }
        cobj->pushUChar(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaMsgBuffer:pushUChar",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_LuaMsgBuffer_pushUChar'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_LuaMsgBuffer_popBool(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_LuaMsgBuffer_popBool'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_LuaMsgBuffer_popBool'", nullptr);
            return 0;
        }
        bool ret = cobj->popBool();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaMsgBuffer:popBool",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_LuaMsgBuffer_popBool'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_LuaMsgBuffer_getMsgId(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_LuaMsgBuffer_getMsgId'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_LuaMsgBuffer_getMsgId'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getMsgId();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaMsgBuffer:getMsgId",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_LuaMsgBuffer_getMsgId'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_LuaMsgBuffer_pushDouble(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_LuaMsgBuffer_pushDouble'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "LuaMsgBuffer:pushDouble");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_LuaMsgBuffer_pushDouble'", nullptr);
            return 0;
        }
        cobj->pushDouble(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaMsgBuffer:pushDouble",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_LuaMsgBuffer_pushDouble'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_LuaMsgBuffer_getSendBufLen(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_LuaMsgBuffer_getSendBufLen'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_LuaMsgBuffer_getSendBufLen'", nullptr);
            return 0;
        }
        int ret = cobj->getSendBufLen();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaMsgBuffer:getSendBufLen",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_LuaMsgBuffer_getSendBufLen'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_LuaMsgBuffer_pushBool(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_LuaMsgBuffer_pushBool'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "LuaMsgBuffer:pushBool");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_LuaMsgBuffer_pushBool'", nullptr);
            return 0;
        }
        cobj->pushBool(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaMsgBuffer:pushBool",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_LuaMsgBuffer_pushBool'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_LuaMsgBuffer_popFloat(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_LuaMsgBuffer_popFloat'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_LuaMsgBuffer_popFloat'", nullptr);
            return 0;
        }
        double ret = cobj->popFloat();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaMsgBuffer:popFloat",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_LuaMsgBuffer_popFloat'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_LuaMsgBuffer_popDouble(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_LuaMsgBuffer_popDouble'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_LuaMsgBuffer_popDouble'", nullptr);
            return 0;
        }
        double ret = cobj->popDouble();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaMsgBuffer:popDouble",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_LuaMsgBuffer_popDouble'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_LuaMsgBuffer_pushChars(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_LuaMsgBuffer_pushChars'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        const char* arg0;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "LuaMsgBuffer:pushChars"); arg0 = arg0_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_LuaMsgBuffer_pushChars'", nullptr);
            return 0;
        }
        cobj->pushChars(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaMsgBuffer:pushChars",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_LuaMsgBuffer_pushChars'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_LuaMsgBuffer_popInt(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_LuaMsgBuffer_popInt'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_LuaMsgBuffer_popInt'", nullptr);
            return 0;
        }
        int ret = cobj->popInt();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaMsgBuffer:popInt",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_LuaMsgBuffer_popInt'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_LuaMsgBuffer_eof(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_LuaMsgBuffer_eof'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_LuaMsgBuffer_eof'", nullptr);
            return 0;
        }
        bool ret = cobj->eof();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaMsgBuffer:eof",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_LuaMsgBuffer_eof'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_LuaMsgBuffer_pushChar(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_LuaMsgBuffer_pushChar'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int32_t arg0;

        ok &= luaval_to_int32(tolua_S, 2,&arg0, "LuaMsgBuffer:pushChar");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_LuaMsgBuffer_pushChar'", nullptr);
            return 0;
        }
        cobj->pushChar(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaMsgBuffer:pushChar",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_LuaMsgBuffer_pushChar'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_LuaMsgBuffer_pushDataByString(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_LuaMsgBuffer_pushDataByString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "LuaMsgBuffer:pushDataByString");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_LuaMsgBuffer_pushDataByString'", nullptr);
            return 0;
        }
        cobj->pushDataByString(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaMsgBuffer:pushDataByString",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_LuaMsgBuffer_pushDataByString'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_LuaMsgBuffer_clear(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_LuaMsgBuffer_clear'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_LuaMsgBuffer_clear'", nullptr);
            return 0;
        }
        cobj->clear();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaMsgBuffer:clear",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_LuaMsgBuffer_clear'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_LuaMsgBuffer_pushString(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_LuaMsgBuffer_pushString'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "LuaMsgBuffer:pushString");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_LuaMsgBuffer_pushString'", nullptr);
            return 0;
        }
        cobj->pushString(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaMsgBuffer:pushString",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_LuaMsgBuffer_pushString'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_LuaMsgBuffer_popLongLong(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_LuaMsgBuffer_popLongLong'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_LuaMsgBuffer_popLongLong'", nullptr);
            return 0;
        }
        long long ret = cobj->popLongLong();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaMsgBuffer:popLongLong",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_LuaMsgBuffer_popLongLong'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_LuaMsgBuffer_popShort(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_LuaMsgBuffer_popShort'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_LuaMsgBuffer_popShort'", nullptr);
            return 0;
        }
        int32_t ret = cobj->popShort();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaMsgBuffer:popShort",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_LuaMsgBuffer_popShort'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_LuaMsgBuffer_popChar(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_LuaMsgBuffer_popChar'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_LuaMsgBuffer_popChar'", nullptr);
            return 0;
        }
        int32_t ret = cobj->popChar();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaMsgBuffer:popChar",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_LuaMsgBuffer_popChar'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_LuaMsgBuffer_pushShort(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_LuaMsgBuffer_pushShort'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int32_t arg0;

        ok &= luaval_to_int32(tolua_S, 2,&arg0, "LuaMsgBuffer:pushShort");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_LuaMsgBuffer_pushShort'", nullptr);
            return 0;
        }
        cobj->pushShort(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaMsgBuffer:pushShort",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_LuaMsgBuffer_pushShort'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_LuaMsgBuffer_pushInt(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_LuaMsgBuffer_pushInt'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "LuaMsgBuffer:pushInt");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_LuaMsgBuffer_pushInt'", nullptr);
            return 0;
        }
        cobj->pushInt(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaMsgBuffer:pushInt",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_LuaMsgBuffer_pushInt'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_LuaMsgBuffer_popInts(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_LuaMsgBuffer_popInts'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::vector<int> arg0;

        ok &= luaval_to_std_vector_int(tolua_S, 2, &arg0, "LuaMsgBuffer:popInts");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_LuaMsgBuffer_popInts'", nullptr);
            return 0;
        }
        cobj->popInts(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaMsgBuffer:popInts",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_LuaMsgBuffer_popInts'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_LuaMsgBuffer_constructor(lua_State* tolua_S)
{
    int argc = 0;
    LuaMsgBuffer* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_LuaMsgBuffer_constructor'", nullptr);
            return 0;
        }
        cobj = new LuaMsgBuffer();
        tolua_pushusertype(tolua_S,(void*)cobj,"LuaMsgBuffer");
        tolua_register_gc(tolua_S,lua_gettop(tolua_S));
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaMsgBuffer:LuaMsgBuffer",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_woool_LuaMsgBuffer_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_woool_LuaMsgBuffer_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (LuaMsgBuffer)");
    return 0;
}

int lua_register_woool_LuaMsgBuffer(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"LuaMsgBuffer");
    tolua_cclass(tolua_S,"LuaMsgBuffer","LuaMsgBuffer","",nullptr);

    tolua_beginmodule(tolua_S,"LuaMsgBuffer");
        tolua_function(tolua_S,"new",lua_woool_LuaMsgBuffer_constructor);
        tolua_function(tolua_S,"popString",lua_woool_LuaMsgBuffer_popString);
        tolua_function(tolua_S,"pushUChar",lua_woool_LuaMsgBuffer_pushUChar);
        tolua_function(tolua_S,"popBool",lua_woool_LuaMsgBuffer_popBool);
        tolua_function(tolua_S,"getMsgId",lua_woool_LuaMsgBuffer_getMsgId);
        tolua_function(tolua_S,"pushDouble",lua_woool_LuaMsgBuffer_pushDouble);
        tolua_function(tolua_S,"getSendBufLen",lua_woool_LuaMsgBuffer_getSendBufLen);
        tolua_function(tolua_S,"pushBool",lua_woool_LuaMsgBuffer_pushBool);
        tolua_function(tolua_S,"popFloat",lua_woool_LuaMsgBuffer_popFloat);
        tolua_function(tolua_S,"popDouble",lua_woool_LuaMsgBuffer_popDouble);
        tolua_function(tolua_S,"pushChars",lua_woool_LuaMsgBuffer_pushChars);
        tolua_function(tolua_S,"popInt",lua_woool_LuaMsgBuffer_popInt);
        tolua_function(tolua_S,"eof",lua_woool_LuaMsgBuffer_eof);
        tolua_function(tolua_S,"pushChar",lua_woool_LuaMsgBuffer_pushChar);
        tolua_function(tolua_S,"pushDataByString",lua_woool_LuaMsgBuffer_pushDataByString);
        tolua_function(tolua_S,"clear",lua_woool_LuaMsgBuffer_clear);
        tolua_function(tolua_S,"pushString",lua_woool_LuaMsgBuffer_pushString);
        tolua_function(tolua_S,"popLongLong",lua_woool_LuaMsgBuffer_popLongLong);
        tolua_function(tolua_S,"popShort",lua_woool_LuaMsgBuffer_popShort);
        tolua_function(tolua_S,"popChar",lua_woool_LuaMsgBuffer_popChar);
        tolua_function(tolua_S,"pushShort",lua_woool_LuaMsgBuffer_pushShort);
        tolua_function(tolua_S,"pushInt",lua_woool_LuaMsgBuffer_pushInt);
        tolua_function(tolua_S,"popInts",lua_woool_LuaMsgBuffer_popInts);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(LuaMsgBuffer).name();
    g_luaType[typeName] = "LuaMsgBuffer";
    g_typeCast["LuaMsgBuffer"] = "LuaMsgBuffer";
    return 1;
}

int lua_woool_LuaEventManager_getLuaEvent(lua_State* tolua_S)
{
    int argc = 0;
    LuaEventManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"LuaEventManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (LuaEventManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_LuaEventManager_getLuaEvent'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int32_t arg0;

        ok &= luaval_to_int32(tolua_S, 2,&arg0, "LuaEventManager:getLuaEvent");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_LuaEventManager_getLuaEvent'", nullptr);
            return 0;
        }
        LuaMsgBuffer* ret = cobj->getLuaEvent(arg0);
        object_to_luaval<LuaMsgBuffer>(tolua_S, "LuaMsgBuffer",(LuaMsgBuffer*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaEventManager:getLuaEvent",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_LuaEventManager_getLuaEvent'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_LuaEventManager_getLuaEventEx(lua_State* tolua_S)
{
    int argc = 0;
    LuaEventManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"LuaEventManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (LuaEventManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_LuaEventManager_getLuaEventEx'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int32_t arg0;

        ok &= luaval_to_int32(tolua_S, 2,&arg0, "LuaEventManager:getLuaEventEx");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_LuaEventManager_getLuaEventEx'", nullptr);
            return 0;
        }
        LuaMsgBuffer* ret = cobj->getLuaEventEx(arg0);
        object_to_luaval<LuaMsgBuffer>(tolua_S, "LuaMsgBuffer",(LuaMsgBuffer*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaEventManager:getLuaEventEx",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_LuaEventManager_getLuaEventEx'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_LuaEventManager_getLuaEventExEx(lua_State* tolua_S)
{
    int argc = 0;
    LuaEventManager* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"LuaEventManager",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (LuaEventManager*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_LuaEventManager_getLuaEventExEx'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int32_t arg0;

        ok &= luaval_to_int32(tolua_S, 2,&arg0, "LuaEventManager:getLuaEventExEx");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_LuaEventManager_getLuaEventExEx'", nullptr);
            return 0;
        }
        LuaMsgBuffer* ret = cobj->getLuaEventExEx(arg0);
        object_to_luaval<LuaMsgBuffer>(tolua_S, "LuaMsgBuffer",(LuaMsgBuffer*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaEventManager:getLuaEventExEx",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_LuaEventManager_getLuaEventExEx'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_LuaEventManager_instance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"LuaEventManager",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_LuaEventManager_instance'", nullptr);
            return 0;
        }
        LuaEventManager* ret = LuaEventManager::instance();
        object_to_luaval<LuaEventManager>(tolua_S, "LuaEventManager",(LuaEventManager*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "LuaEventManager:instance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_LuaEventManager_instance'.",&tolua_err);
#endif
    return 0;
}
static int lua_woool_LuaEventManager_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (LuaEventManager)");
    return 0;
}

int lua_register_woool_LuaEventManager(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"LuaEventManager");
    tolua_cclass(tolua_S,"LuaEventManager","LuaEventManager","",nullptr);

    tolua_beginmodule(tolua_S,"LuaEventManager");
        tolua_function(tolua_S,"getLuaEvent",lua_woool_LuaEventManager_getLuaEvent);
        tolua_function(tolua_S,"getLuaEventEx",lua_woool_LuaEventManager_getLuaEventEx);
        tolua_function(tolua_S,"getLuaEventExEx",lua_woool_LuaEventManager_getLuaEventExEx);
        tolua_function(tolua_S,"instance", lua_woool_LuaEventManager_instance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(LuaEventManager).name();
    g_luaType[typeName] = "LuaEventManager";
    g_typeCast["LuaEventManager"] = "LuaEventManager";
    return 1;
}

int lua_woool_LuaSocket_clearNetBytes(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_LuaSocket_clearNetBytes'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_LuaSocket_clearNetBytes'", nullptr);
            return 0;
        }
        cobj->clearNetBytes();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaSocket:clearNetBytes",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_LuaSocket_clearNetBytes'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_LuaSocket_sendSocket(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_LuaSocket_sendSocket'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        LuaMsgBuffer* arg0;

        ok &= luaval_to_object<LuaMsgBuffer>(tolua_S, 2, "LuaMsgBuffer",&arg0, "LuaSocket:sendSocket");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_LuaSocket_sendSocket'", nullptr);
            return 0;
        }
        cobj->sendSocket(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaSocket:sendSocket",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_LuaSocket_sendSocket'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_LuaSocket_closeSocket(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_LuaSocket_closeSocket'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_LuaSocket_closeSocket'", nullptr);
            return 0;
        }
        cobj->closeSocket();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaSocket:closeSocket",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_LuaSocket_closeSocket'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_LuaSocket_destroyInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"LuaSocket",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_LuaSocket_destroyInstance'", nullptr);
            return 0;
        }
        LuaSocket::destroyInstance();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "LuaSocket:destroyInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_LuaSocket_destroyInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_woool_LuaSocket_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"LuaSocket",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_LuaSocket_getInstance'", nullptr);
            return 0;
        }
        LuaSocket* ret = LuaSocket::getInstance();
        object_to_luaval<LuaSocket>(tolua_S, "LuaSocket",(LuaSocket*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "LuaSocket:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_LuaSocket_getInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_woool_LuaSocket_constructor(lua_State* tolua_S)
{
    int argc = 0;
    LuaSocket* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_LuaSocket_constructor'", nullptr);
            return 0;
        }
        cobj = new LuaSocket();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"LuaSocket");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "LuaSocket:LuaSocket",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_woool_LuaSocket_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_woool_LuaSocket_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (LuaSocket)");
    return 0;
}

int lua_register_woool_LuaSocket(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"LuaSocket");
    tolua_cclass(tolua_S,"LuaSocket","LuaSocket","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"LuaSocket");
        tolua_function(tolua_S,"new",lua_woool_LuaSocket_constructor);
        tolua_function(tolua_S,"clearNetBytes",lua_woool_LuaSocket_clearNetBytes);
        tolua_function(tolua_S,"sendSocket",lua_woool_LuaSocket_sendSocket);
        tolua_function(tolua_S,"closeSocket",lua_woool_LuaSocket_closeSocket);
        tolua_function(tolua_S,"destroyInstance", lua_woool_LuaSocket_destroyInstance);
        tolua_function(tolua_S,"getInstance", lua_woool_LuaSocket_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(LuaSocket).name();
    g_luaType[typeName] = "LuaSocket";
    g_typeCast["LuaSocket"] = "LuaSocket";
    return 1;
}
*/
int lua_woool_MapViewBase_getTileByDir(lua_State* tolua_S)
{
    int argc = 0;
    MapViewBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapViewBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapViewBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapViewBase_getTileByDir'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        Commen_Direction arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "MapViewBase:getTileByDir");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapViewBase_getTileByDir'", nullptr);
            return 0;
        }
        cocos2d::Point ret = cobj->getTileByDir(arg0);
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapViewBase:getTileByDir",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapViewBase_getTileByDir'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapViewBase_getDirByTile(lua_State* tolua_S)
{
    int argc = 0;
    MapViewBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapViewBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapViewBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapViewBase_getDirByTile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;

        ok &= luaval_to_point(tolua_S, 2, &arg0, "MapViewBase:getDirByTile");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapViewBase_getDirByTile'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getDirByTile(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapViewBase:getDirByTile",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapViewBase_getDirByTile'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapViewBase_isBlock(lua_State* tolua_S)
{
    int argc = 0;
    MapViewBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapViewBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapViewBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapViewBase_isBlock'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;

        ok &= luaval_to_point(tolua_S, 2, &arg0, "MapViewBase:isBlock");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapViewBase_isBlock'", nullptr);
            return 0;
        }
        bool ret = cobj->isBlock(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapViewBase:isBlock",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapViewBase_isBlock'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapViewBase_isOpacity(lua_State* tolua_S)
{
    int argc = 0;
    MapViewBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapViewBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapViewBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapViewBase_isOpacity'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;

        ok &= luaval_to_point(tolua_S, 2, &arg0, "MapViewBase:isOpacity");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapViewBase_isOpacity'", nullptr);
            return 0;
        }
        bool ret = cobj->isOpacity(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapViewBase:isOpacity",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapViewBase_isOpacity'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapViewBase_tile2Space(lua_State* tolua_S)
{
    int argc = 0;
    MapViewBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapViewBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapViewBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapViewBase_tile2Space'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;

        ok &= luaval_to_point(tolua_S, 2, &arg0, "MapViewBase:tile2Space");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapViewBase_tile2Space'", nullptr);
            return 0;
        }
        cocos2d::Point ret = cobj->tile2Space(arg0);
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapViewBase:tile2Space",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapViewBase_tile2Space'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapViewBase_space2Tile(lua_State* tolua_S)
{
    int argc = 0;
    MapViewBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapViewBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapViewBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapViewBase_space2Tile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;

        ok &= luaval_to_point(tolua_S, 2, &arg0, "MapViewBase:space2Tile");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapViewBase_space2Tile'", nullptr);
            return 0;
        }
        cocos2d::Point ret = cobj->space2Tile(arg0);
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapViewBase:space2Tile",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapViewBase_space2Tile'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapViewBase_getSkillRootNode(lua_State* tolua_S)
{
    int argc = 0;
    MapViewBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapViewBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapViewBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapViewBase_getSkillRootNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapViewBase_getSkillRootNode'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->getSkillRootNode();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapViewBase:getSkillRootNode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapViewBase_getSkillRootNode'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapViewBase_GetItemRoot(lua_State* tolua_S)
{
    int argc = 0;
    MapViewBase* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"MapViewBase",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (MapViewBase*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapViewBase_GetItemRoot'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapViewBase_GetItemRoot'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->GetItemRoot();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapViewBase:GetItemRoot",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapViewBase_GetItemRoot'.",&tolua_err);
#endif

    return 0;
}
static int lua_woool_MapViewBase_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (MapViewBase)");
    return 0;
}

int lua_register_woool_MapViewBase(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"MapViewBase");
    tolua_cclass(tolua_S,"MapViewBase","MapViewBase","cc.Layer",nullptr);

    tolua_beginmodule(tolua_S,"MapViewBase");
        tolua_function(tolua_S,"getTileByDir",lua_woool_MapViewBase_getTileByDir);
        tolua_function(tolua_S,"getDirByTile",lua_woool_MapViewBase_getDirByTile);
        tolua_function(tolua_S,"isBlock",lua_woool_MapViewBase_isBlock);
        tolua_function(tolua_S,"isOpacity",lua_woool_MapViewBase_isOpacity);
        tolua_function(tolua_S,"tile2Space",lua_woool_MapViewBase_tile2Space);
        tolua_function(tolua_S,"space2Tile",lua_woool_MapViewBase_space2Tile);
        tolua_function(tolua_S,"getSkillRootNode",lua_woool_MapViewBase_getSkillRootNode);
        tolua_function(tolua_S,"GetItemRoot",lua_woool_MapViewBase_GetItemRoot);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(MapViewBase).name();
    g_luaType[typeName] = "MapViewBase";
    g_typeCast["MapViewBase"] = "MapViewBase";
    return 1;
}

int lua_woool_UIMapView_onShowHurt(lua_State* tolua_S)
{
    int argc = 0;
    UIMapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIMapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UIMapView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_UIMapView_onShowHurt'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
       /* LuaMsgBuffer* arg0;

        ok &= luaval_to_object<LuaMsgBuffer>(tolua_S, 2, "LuaMsgBuffer",&arg0, "UIMapView:onShowHurt");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_UIMapView_onShowHurt'", nullptr);
            return 0;
        }
        cobj->onShowHurt(arg0);
        lua_settop(tolua_S, 1);*/
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UIMapView:onShowHurt",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_UIMapView_onShowHurt'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_UIMapView_onCrash(lua_State* tolua_S)
{
    int argc = 0;
    UIMapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIMapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UIMapView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_UIMapView_onCrash'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 9) 
    {
        int arg0;
        int arg1;
        int arg2;
        int arg3;
        int arg4;
        int arg5;
        int arg6;
        int arg7;
        int arg8;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "UIMapView:onCrash");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "UIMapView:onCrash");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "UIMapView:onCrash");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "UIMapView:onCrash");

        ok &= luaval_to_int32(tolua_S, 6,(int *)&arg4, "UIMapView:onCrash");

        ok &= luaval_to_int32(tolua_S, 7,(int *)&arg5, "UIMapView:onCrash");

        ok &= luaval_to_int32(tolua_S, 8,(int *)&arg6, "UIMapView:onCrash");

        ok &= luaval_to_int32(tolua_S, 9,(int *)&arg7, "UIMapView:onCrash");

        ok &= luaval_to_int32(tolua_S, 10,(int *)&arg8, "UIMapView:onCrash");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_UIMapView_onCrash'", nullptr);
            return 0;
        }
        //cobj->onCrash(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UIMapView:onCrash",argc, 9);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_UIMapView_onCrash'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_UIMapView_isBlock(lua_State* tolua_S)
{
    int argc = 0;
    UIMapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIMapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UIMapView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_UIMapView_isBlock'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;

        ok &= luaval_to_point(tolua_S, 2, &arg0, "UIMapView:isBlock");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_UIMapView_isBlock'", nullptr);
            return 0;
        }
        bool ret = cobj->isBlock(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UIMapView:isBlock",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_UIMapView_isBlock'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_UIMapView_isOpacity(lua_State* tolua_S)
{
    int argc = 0;
    UIMapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIMapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UIMapView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_UIMapView_isOpacity'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;

        ok &= luaval_to_point(tolua_S, 2, &arg0, "UIMapView:isOpacity");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_UIMapView_isOpacity'", nullptr);
            return 0;
        }
        bool ret = cobj->isOpacity(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UIMapView:isOpacity",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_UIMapView_isOpacity'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_UIMapView_GetDirByPos(lua_State* tolua_S)
{
    int argc = 0;
    UIMapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIMapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UIMapView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_UIMapView_GetDirByPos'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Point arg0;
        cocos2d::Point arg1;

        ok &= luaval_to_point(tolua_S, 2, &arg0, "UIMapView:GetDirByPos");

        ok &= luaval_to_point(tolua_S, 3, &arg1, "UIMapView:GetDirByPos");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_UIMapView_GetDirByPos'", nullptr);
            return 0;
        }
        int ret = (int)cobj->GetDirByPos(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UIMapView:GetDirByPos",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_UIMapView_GetDirByPos'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_UIMapView_getSpeedUp(lua_State* tolua_S)
{
    int argc = 0;
    UIMapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIMapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UIMapView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_UIMapView_getSpeedUp'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        UISpriteCharacter* arg0;

        ok &= luaval_to_object<UISpriteCharacter>(tolua_S, 2, "UISpriteCharacter",&arg0, "UIMapView:getSpeedUp");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_UIMapView_getSpeedUp'", nullptr);
            return 0;
        }
        int32_t ret = cobj->getSpeedUp(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UIMapView:getSpeedUp",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_UIMapView_getSpeedUp'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_UIMapView_tile2Space(lua_State* tolua_S)
{
    int argc = 0;
    UIMapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIMapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UIMapView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_UIMapView_tile2Space'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;

        ok &= luaval_to_point(tolua_S, 2, &arg0, "UIMapView:tile2Space");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_UIMapView_tile2Space'", nullptr);
            return 0;
        }
        cocos2d::Point ret = cobj->tile2Space(arg0);
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UIMapView:tile2Space",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_UIMapView_tile2Space'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_UIMapView_onDelayCrash(lua_State* tolua_S)
{
    int argc = 0;
    UIMapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIMapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UIMapView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_UIMapView_onDelayCrash'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        UISpriteCharacter* arg0;
        action_queue arg1;

        ok &= luaval_to_object<UISpriteCharacter>(tolua_S, 2, "UISpriteCharacter",&arg0, "UIMapView:onDelayCrash");

        #pragma warning NO CONVERSION TO NATIVE FOR action_queue
		ok = false;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_UIMapView_onDelayCrash'", nullptr);
            return 0;
        }
        //cobj->onDelayCrash(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UIMapView:onDelayCrash",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_UIMapView_onDelayCrash'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_UIMapView_space2Tile(lua_State* tolua_S)
{
    int argc = 0;
    UIMapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIMapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UIMapView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_UIMapView_space2Tile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;

        ok &= luaval_to_point(tolua_S, 2, &arg0, "UIMapView:space2Tile");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_UIMapView_space2Tile'", nullptr);
            return 0;
        }
        cocos2d::Point ret = cobj->space2Tile(arg0);
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UIMapView:space2Tile",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_UIMapView_space2Tile'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_UIMapView_onDelayMove(lua_State* tolua_S)
{
    int argc = 0;
    UIMapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIMapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UIMapView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_UIMapView_onDelayMove'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        UISpriteCharacter* arg0;
        cocos2d::Point arg1;

        ok &= luaval_to_object<UISpriteCharacter>(tolua_S, 2, "UISpriteCharacter",&arg0, "UIMapView:onDelayMove");

        ok &= luaval_to_point(tolua_S, 3, &arg1, "UIMapView:onDelayMove");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_UIMapView_onDelayMove'", nullptr);
            return 0;
        }
        cobj->onDelayMove(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UIMapView:onDelayMove",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_UIMapView_onDelayMove'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_UIMapView_onShowHurtNumber(lua_State* tolua_S)
{
    int argc = 0;
    UIMapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIMapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UIMapView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_UIMapView_onShowHurtNumber'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 6) 
    {
        int arg0;
        cocos2d::Point arg1;
        int32_t arg2;
        bool arg3;
        cocos2d::Point arg4;
        int arg5;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "UIMapView:onShowHurtNumber");

        ok &= luaval_to_point(tolua_S, 3, &arg1, "UIMapView:onShowHurtNumber");

        ok &= luaval_to_int32(tolua_S, 4,&arg2, "UIMapView:onShowHurtNumber");

        ok &= luaval_to_boolean(tolua_S, 5,&arg3, "UIMapView:onShowHurtNumber");

        ok &= luaval_to_point(tolua_S, 6, &arg4, "UIMapView:onShowHurtNumber");

        ok &= luaval_to_int32(tolua_S, 7,(int *)&arg5, "UIMapView:onShowHurtNumber");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_UIMapView_onShowHurtNumber'", nullptr);
            return 0;
        }
        cobj->onShowHurtNumber(arg0, arg1, arg2, arg3, arg4, arg5);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UIMapView:onShowHurtNumber",argc, 6);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_UIMapView_onShowHurtNumber'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_UIMapView_getSkillRootNode(lua_State* tolua_S)
{
    int argc = 0;
    UIMapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIMapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UIMapView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_UIMapView_getSkillRootNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_UIMapView_getSkillRootNode'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->getSkillRootNode();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UIMapView:getSkillRootNode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_UIMapView_getSkillRootNode'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_UIMapView_onDelayCrashed(lua_State* tolua_S)
{
    int argc = 0;
    UIMapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIMapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UIMapView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_UIMapView_onDelayCrashed'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        UISpriteCharacter* arg0;
        action_queue arg1;

        ok &= luaval_to_object<UISpriteCharacter>(tolua_S, 2, "UISpriteCharacter",&arg0, "UIMapView:onDelayCrashed");

        #pragma warning NO CONVERSION TO NATIVE FOR action_queue
		ok = false;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_UIMapView_onDelayCrashed'", nullptr);
            return 0;
        }
       // cobj->onDelayCrashed(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UIMapView:onDelayCrashed",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_UIMapView_onDelayCrashed'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_UIMapView_GetItemRoot(lua_State* tolua_S)
{
    int argc = 0;
    UIMapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIMapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UIMapView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_UIMapView_GetItemRoot'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_UIMapView_GetItemRoot'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->GetItemRoot();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UIMapView:GetItemRoot",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_UIMapView_GetItemRoot'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_UIMapView_onDoMove(lua_State* tolua_S)
{
    int argc = 0;
    UIMapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UIMapView",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UIMapView*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_UIMapView_onDoMove'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        int arg0;
        int32_t arg1;
        int32_t arg2;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "UIMapView:onDoMove");

        ok &= luaval_to_int32(tolua_S, 3,&arg1, "UIMapView:onDoMove");

        ok &= luaval_to_int32(tolua_S, 4,&arg2, "UIMapView:onDoMove");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_UIMapView_onDoMove'", nullptr);
            return 0;
        }
        cobj->onDoMove(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UIMapView:onDoMove",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_UIMapView_onDoMove'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_UIMapView_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UIMapView",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_UIMapView_create'", nullptr);
            return 0;
        }
        UIMapView* ret = UIMapView::create();
        object_to_luaval<UIMapView>(tolua_S, "UIMapView",(UIMapView*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "UIMapView:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_UIMapView_create'.",&tolua_err);
#endif
    return 0;
}
int lua_woool_UIMapView_constructor(lua_State* tolua_S)
{
    int argc = 0;
    UIMapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_UIMapView_constructor'", nullptr);
            return 0;
        }
        cobj = new UIMapView();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"UIMapView");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UIMapView:UIMapView",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_woool_UIMapView_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_woool_UIMapView_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (UIMapView)");
    return 0;
}

int lua_register_woool_UIMapView(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"UIMapView");
    tolua_cclass(tolua_S,"UIMapView","UIMapView","MapViewBase",nullptr);

    tolua_beginmodule(tolua_S,"UIMapView");
        tolua_function(tolua_S,"new",lua_woool_UIMapView_constructor);
        tolua_function(tolua_S,"onShowHurt",lua_woool_UIMapView_onShowHurt);
        tolua_function(tolua_S,"onCrash",lua_woool_UIMapView_onCrash);
        tolua_function(tolua_S,"isBlock",lua_woool_UIMapView_isBlock);
        tolua_function(tolua_S,"isOpacity",lua_woool_UIMapView_isOpacity);
        tolua_function(tolua_S,"GetDirByPos",lua_woool_UIMapView_GetDirByPos);
        tolua_function(tolua_S,"getSpeedUp",lua_woool_UIMapView_getSpeedUp);
        tolua_function(tolua_S,"tile2Space",lua_woool_UIMapView_tile2Space);
        tolua_function(tolua_S,"onDelayCrash",lua_woool_UIMapView_onDelayCrash);
        tolua_function(tolua_S,"space2Tile",lua_woool_UIMapView_space2Tile);
        tolua_function(tolua_S,"onDelayMove",lua_woool_UIMapView_onDelayMove);
        tolua_function(tolua_S,"onShowHurtNumber",lua_woool_UIMapView_onShowHurtNumber);
        tolua_function(tolua_S,"getSkillRootNode",lua_woool_UIMapView_getSkillRootNode);
        tolua_function(tolua_S,"onDelayCrashed",lua_woool_UIMapView_onDelayCrashed);
        tolua_function(tolua_S,"GetItemRoot",lua_woool_UIMapView_GetItemRoot);
        tolua_function(tolua_S,"onDoMove",lua_woool_UIMapView_onDoMove);
        tolua_function(tolua_S,"create", lua_woool_UIMapView_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(UIMapView).name();
    g_luaType[typeName] = "UIMapView";
    g_typeCast["UIMapView"] = "UIMapView";
    return 1;
}

int lua_woool_MapView_getRockDirSet(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapView_getRockDirSet'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_getRockDirSet'", nullptr);
            return 0;
        }
        bool ret = cobj->getRockDirSet();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:getRockDirSet",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_getRockDirSet'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapView_isBlock(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapView_isBlock'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;

        ok &= luaval_to_point(tolua_S, 2, &arg0, "MapView:isBlock");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_isBlock'", nullptr);
            return 0;
        }
        bool ret = cobj->isBlock(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:isBlock",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_isBlock'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapView_scroll2Tile(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapView_scroll2Tile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;

        ok &= luaval_to_point(tolua_S, 2, &arg0, "MapView:scroll2Tile");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_scroll2Tile'", nullptr);
            return 0;
        }
        cobj->scroll2Tile(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        cocos2d::Point arg0;
        double arg1;

        ok &= luaval_to_point(tolua_S, 2, &arg0, "MapView:scroll2Tile");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "MapView:scroll2Tile");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_scroll2Tile'", nullptr);
            return 0;
        }
        cobj->scroll2Tile(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:scroll2Tile",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_scroll2Tile'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapView_removeTouchMoveCb(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapView_removeTouchMoveCb'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_removeTouchMoveCb'", nullptr);
            return 0;
        }
        cobj->removeTouchMoveCb();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:removeTouchMoveCb",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_removeTouchMoveCb'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapView_setScale(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapView_setScale'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "MapView:setScale");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_setScale'", nullptr);
            return 0;
        }
        cobj->setScale(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:setScale",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_setScale'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapView_setMainRole(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapView_setMainRole'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        SpritePlayer* arg0;

        ok &= luaval_to_object<SpritePlayer>(tolua_S, 2, "SpritePlayer",&arg0, "MapView:setMainRole");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_setMainRole'", nullptr);
            return 0;
        }
        cobj->setMainRole(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:setMainRole",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_setMainRole'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapView_setMapActionFlag(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapView_setMapActionFlag'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "MapView:setMapActionFlag");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_setMapActionFlag'", nullptr);
            return 0;
        }
        cobj->setMapActionFlag(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:setMapActionFlag",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_setMapActionFlag'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapView_getCurTile(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapView_getCurTile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_getCurTile'", nullptr);
            return 0;
        }
        cocos2d::Point ret = cobj->getCurTile();
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:getCurTile",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_getCurTile'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapView_removeRockerCb(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapView_removeRockerCb'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_removeRockerCb'", nullptr);
            return 0;
        }
        cobj->removeRockerCb();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:removeRockerCb",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_removeRockerCb'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapView_setPosition(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapView_setPosition'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;

        ok &= luaval_to_point(tolua_S, 2, &arg0, "MapView:setPosition");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_setPosition'", nullptr);
            return 0;
        }
        cobj->setPosition(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:setPosition",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_setPosition'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapView_setAttackFlag(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapView_setAttackFlag'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "MapView:setAttackFlag");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_setAttackFlag'", nullptr);
            return 0;
        }
        cobj->setAttackFlag(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:setAttackFlag",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_setAttackFlag'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapView_hasPath(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapView_hasPath'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_hasPath'", nullptr);
            return 0;
        }
        bool ret = cobj->hasPath();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:hasPath",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_hasPath'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapView_getRolePathNum(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapView_getRolePathNum'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_getRolePathNum'", nullptr);
            return 0;
        }
        int ret = cobj->getRolePathNum();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:getRolePathNum",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_getRolePathNum'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapView_isStoryMap(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapView_isStoryMap'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "MapView:isStoryMap");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_isStoryMap'", nullptr);
            return 0;
        }
        bool ret = cobj->isStoryMap(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:isStoryMap",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_isStoryMap'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapView_cleanAstarPath(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapView_cleanAstarPath'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_cleanAstarPath'", nullptr);
            return 0;
        }
        cobj->cleanAstarPath();
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "MapView:cleanAstarPath");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_cleanAstarPath'", nullptr);
            return 0;
        }
        cobj->cleanAstarPath(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        bool arg0;
        bool arg1;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "MapView:cleanAstarPath");

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "MapView:cleanAstarPath");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_cleanAstarPath'", nullptr);
            return 0;
        }
        cobj->cleanAstarPath(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:cleanAstarPath",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_cleanAstarPath'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapView_getMainRole(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapView_getMainRole'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_getMainRole'", nullptr);
            return 0;
        }
        SpritePlayer* ret = cobj->getMainRole();
        object_to_luaval<SpritePlayer>(tolua_S, "SpritePlayer",(SpritePlayer*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:getMainRole",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_getMainRole'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapView_getNearTiled(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapView_getNearTiled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Point arg0;
        Commen_Direction arg1;

        ok &= luaval_to_point(tolua_S, 2, &arg0, "MapView:getNearTiled");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "MapView:getNearTiled");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_getNearTiled'", nullptr);
            return 0;
        }
        cocos2d::Point ret = cobj->getNearTiled(arg0, arg1);
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:getNearTiled",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_getNearTiled'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapView_setBlockRectValue(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapView_setBlockRectValue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Rect arg0;
        const char* arg1;

        ok &= luaval_to_rect(tolua_S, 2, &arg0, "MapView:setBlockRectValue");

        std::string arg1_tmp; ok &= luaval_to_std_string(tolua_S, 3, &arg1_tmp, "MapView:setBlockRectValue"); arg1 = arg1_tmp.c_str();
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_setBlockRectValue'", nullptr);
            return 0;
        }
        cobj->setBlockRectValue(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:setBlockRectValue",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_setBlockRectValue'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapView_getMapActionFlag(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapView_getMapActionFlag'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_getMapActionFlag'", nullptr);
            return 0;
        }
        bool ret = cobj->getMapActionFlag();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:getMapActionFlag",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_getMapActionFlag'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapView_moveMapByPos(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapView_moveMapByPos'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;

        ok &= luaval_to_point(tolua_S, 2, &arg0, "MapView:moveMapByPos");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_moveMapByPos'", nullptr);
            return 0;
        }
        cobj->moveMapByPos(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        cocos2d::Point arg0;
        bool arg1;

        ok &= luaval_to_point(tolua_S, 2, &arg0, "MapView:moveMapByPos");

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "MapView:moveMapByPos");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_moveMapByPos'", nullptr);
            return 0;
        }
        cobj->moveMapByPos(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:moveMapByPos",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_moveMapByPos'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapView_IsOutoffScreen(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapView_IsOutoffScreen'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Vec2 arg0;

        ok &= luaval_to_vec2(tolua_S, 2, &arg0, "MapView:IsOutoffScreen");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_IsOutoffScreen'", nullptr);
            return 0;
        }
        bool ret = cobj->IsOutoffScreen(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:IsOutoffScreen",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_IsOutoffScreen'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapView_loadMapNew(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapView_loadMapNew'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        std::string arg0;
        int arg1;
        cocos2d::Point arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "MapView:loadMapNew");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "MapView:loadMapNew");

        ok &= luaval_to_point(tolua_S, 4, &arg2, "MapView:loadMapNew");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_loadMapNew'", nullptr);
            return 0;
        }
        bool ret = cobj->loadMapNew(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:loadMapNew",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_loadMapNew'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapView_removeWalkCb(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapView_removeWalkCb'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_removeWalkCb'", nullptr);
            return 0;
        }
        cobj->removeWalkCb();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:removeWalkCb",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_removeWalkCb'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapView_moveLock(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapView_moveLock'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "MapView:moveLock");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_moveLock'", nullptr);
            return 0;
        }
        cobj->moveLock(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:moveLock",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_moveLock'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapView_isOpacity(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapView_isOpacity'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;

        ok &= luaval_to_point(tolua_S, 2, &arg0, "MapView:isOpacity");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_isOpacity'", nullptr);
            return 0;
        }
        bool ret = cobj->isOpacity(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:isOpacity",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_isOpacity'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapView_isHasAllLoaded(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapView_isHasAllLoaded'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_isHasAllLoaded'", nullptr);
            return 0;
        }
        bool ret = cobj->isHasAllLoaded();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:isHasAllLoaded",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_isHasAllLoaded'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapView_getSpeedUp(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapView_getSpeedUp'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        SpriteMonster* arg0;

        ok &= luaval_to_object<SpriteMonster>(tolua_S, 2, "SpriteMonster",&arg0, "MapView:getSpeedUp");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_getSpeedUp'", nullptr);
            return 0;
        }
        int32_t ret = cobj->getSpeedUp(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:getSpeedUp",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_getSpeedUp'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapView_loadSpritesPre(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapView_loadSpritesPre'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_loadSpritesPre'", nullptr);
            return 0;
        }
        cobj->loadSpritesPre();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:loadSpritesPre",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_loadSpritesPre'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapView_initDataAndFunc(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapView_initDataAndFunc'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;

        ok &= luaval_to_point(tolua_S, 2, &arg0, "MapView:initDataAndFunc");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_initDataAndFunc'", nullptr);
            return 0;
        }
        cobj->initDataAndFunc(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:initDataAndFunc",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_initDataAndFunc'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapView_loadMap(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapView_loadMap'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        std::string arg0;
        int arg1;
        cocos2d::Point arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "MapView:loadMap");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "MapView:loadMap");

        ok &= luaval_to_point(tolua_S, 4, &arg2, "MapView:loadMap");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_loadMap'", nullptr);
            return 0;
        }
        bool ret = cobj->loadMap(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:loadMap",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_loadMap'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapView_tile2Space(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapView_tile2Space'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;

        ok &= luaval_to_point(tolua_S, 2, &arg0, "MapView:tile2Space");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_tile2Space'", nullptr);
            return 0;
        }
        cocos2d::Point ret = cobj->tile2Space(arg0);
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:tile2Space",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_tile2Space'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapView_getDestPosition(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapView_getDestPosition'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::Point arg0;
        int arg1;

        ok &= luaval_to_point(tolua_S, 2, &arg0, "MapView:getDestPosition");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "MapView:getDestPosition");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_getDestPosition'", nullptr);
            return 0;
        }
        cocos2d::Point ret = cobj->getDestPosition(arg0, arg1);
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:getDestPosition",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_getDestPosition'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapView_getSkillRootNode(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapView_getSkillRootNode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_getSkillRootNode'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->getSkillRootNode();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:getSkillRootNode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_getSkillRootNode'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapView_setRockDir(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapView_setRockDir'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        Commen_Direction arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "MapView:setRockDir");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_setRockDir'", nullptr);
            return 0;
        }
        cobj->setRockDir(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:setRockDir",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_setRockDir'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapView_space2Tile(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapView_space2Tile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Point arg0;

        ok &= luaval_to_point(tolua_S, 2, &arg0, "MapView:space2Tile");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_space2Tile'", nullptr);
            return 0;
        }
        cocos2d::Point ret = cobj->space2Tile(arg0);
        point_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:space2Tile",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_space2Tile'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapView_resetSpeed(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapView_resetSpeed'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "MapView:resetSpeed");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_resetSpeed'", nullptr);
            return 0;
        }
        cobj->resetSpeed(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:resetSpeed",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_resetSpeed'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapView_GetItemRoot(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_woool_MapView_GetItemRoot'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_GetItemRoot'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = cobj->GetItemRoot();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:GetItemRoot",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_GetItemRoot'.",&tolua_err);
#endif

    return 0;
}
int lua_woool_MapView_resetShowHurt(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "MapView:resetShowHurt");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_resetShowHurt'", nullptr);
            return 0;
        }
        MapView::resetShowHurt(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "MapView:resetShowHurt",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_resetShowHurt'.",&tolua_err);
#endif
    return 0;
}
int lua_woool_MapView_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 3)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "MapView:create");
            if (!ok) { break; }
            int arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "MapView:create");
            if (!ok) { break; }
            cocos2d::Point arg2;
            ok &= luaval_to_point(tolua_S, 4, &arg2, "MapView:create");
            if (!ok) { break; }
            MapView* ret = MapView::create(arg0, arg1, arg2);
            object_to_luaval<MapView>(tolua_S, "MapView",(MapView*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 0)
        {
            MapView* ret = MapView::create();
            object_to_luaval<MapView>(tolua_S, "MapView",(MapView*)ret);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "MapView:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_create'.",&tolua_err);
#endif
    return 0;
}
int lua_woool_MapView_GetDirByPos(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        cocos2d::Point arg0;
        cocos2d::Point arg1;
        ok &= luaval_to_point(tolua_S, 2, &arg0, "MapView:GetDirByPos");
        ok &= luaval_to_point(tolua_S, 3, &arg1, "MapView:GetDirByPos");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_GetDirByPos'", nullptr);
            return 0;
        }
        int ret = (int)MapView::GetDirByPos(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "MapView:GetDirByPos",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_GetDirByPos'.",&tolua_err);
#endif
    return 0;
}
int lua_woool_MapView_resetBloodNode(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_resetBloodNode'", nullptr);
            return 0;
        }
        MapView::resetBloodNode();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "MapView:resetBloodNode",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_resetBloodNode'.",&tolua_err);
#endif
    return 0;
}
int lua_woool_MapView_getFlyTime(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 3)
    {
        cocos2d::Vec2 arg0;
        cocos2d::Vec2 arg1;
        double arg2;
        ok &= luaval_to_vec2(tolua_S, 2, &arg0, "MapView:getFlyTime");
        ok &= luaval_to_vec2(tolua_S, 3, &arg1, "MapView:getFlyTime");
        ok &= luaval_to_number(tolua_S, 4,&arg2, "MapView:getFlyTime");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_getFlyTime'", nullptr);
            return 0;
        }
        double ret = MapView::getFlyTime(arg0, arg1, arg2);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "MapView:getFlyTime",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_getFlyTime'.",&tolua_err);
#endif
    return 0;
}
int lua_woool_MapView_getSkillNode(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_getSkillNode'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = MapView::getSkillNode();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "MapView:getSkillNode",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_getSkillNode'.",&tolua_err);
#endif
    return 0;
}
int lua_woool_MapView_setMaxLockNum(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        unsigned short arg0;
        ok &= luaval_to_ushort(tolua_S, 2, &arg0, "MapView:setMaxLockNum");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_setMaxLockNum'", nullptr);
            return 0;
        }
        MapView::setMaxLockNum(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "MapView:setMaxLockNum",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_setMaxLockNum'.",&tolua_err);
#endif
    return 0;
}
int lua_woool_MapView_getSkillDownNode(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_getSkillDownNode'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = MapView::getSkillDownNode();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "MapView:getSkillDownNode",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_getSkillDownNode'.",&tolua_err);
#endif
    return 0;
}
int lua_woool_MapView_onMsgHandler(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "MapView:onMsgHandler");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_onMsgHandler'", nullptr);
            return 0;
        }
       // MapView::onMsgHandler(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "MapView:onMsgHandler",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_onMsgHandler'.",&tolua_err);
#endif
    return 0;
}
int lua_woool_MapView_getTitleNode(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"MapView",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_getTitleNode'", nullptr);
            return 0;
        }
        cocos2d::Node* ret = MapView::getTitleNode();
        object_to_luaval<cocos2d::Node>(tolua_S, "cc.Node",(cocos2d::Node*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "MapView:getTitleNode",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_getTitleNode'.",&tolua_err);
#endif
    return 0;
}
int lua_woool_MapView_constructor(lua_State* tolua_S)
{
    int argc = 0;
    MapView* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_woool_MapView_constructor'", nullptr);
            return 0;
        }
        cobj = new MapView();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"MapView");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:MapView",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_woool_MapView_constructor'.",&tolua_err);
#endif

    return 0;
}


int lua_woool_MapView_getMapSize(lua_State* tolua_S)
{
	int argc = 0;
	MapView* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "MapView", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (MapView*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_woool_MapView_getMapSize'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 0)
	{

		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_woool_MapView_getMapSize'", nullptr);
			return 0;
		}

		const cocos2d::Size& ret = cobj->getMapSize();
		size_to_luaval(tolua_S, ret);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:resetSpeed", argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
	tolua_lerror:
				tolua_error(tolua_S, "#ferror in function 'lua_woool_MapView_getMapSize'.", &tolua_err);
#endif

				return 0;
}

int lua_woool_MapView_getTileSize(lua_State* tolua_S)
{
	int argc = 0;
	MapView* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "MapView", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (MapView*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_woool_MapView_getTileSize'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 0)
	{

		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_woool_MapView_getTileSize'", nullptr);
			return 0;
		}

		const cocos2d::Size& ret = cobj->getTileSize();
		size_to_luaval(tolua_S, ret);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:resetSpeed", argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
	tolua_lerror:
				tolua_error(tolua_S, "#ferror in function 'lua_woool_MapView_getTileSize'.", &tolua_err);
#endif

				return 0;
}





static int lua_woool_MapView_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (MapView)");
    return 0;
}

int lua_register_woool_MapView(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"MapView");
    tolua_cclass(tolua_S,"MapView","MapView","MapViewBase",nullptr);

    tolua_beginmodule(tolua_S,"MapView");
        tolua_function(tolua_S,"new",lua_woool_MapView_constructor);
        tolua_function(tolua_S,"getRockDirSet",lua_woool_MapView_getRockDirSet);
        tolua_function(tolua_S,"isBlock",lua_woool_MapView_isBlock);
        tolua_function(tolua_S,"scroll2Tile",lua_woool_MapView_scroll2Tile);
        tolua_function(tolua_S,"removeTouchMoveCb",lua_woool_MapView_removeTouchMoveCb);
        tolua_function(tolua_S,"setScale",lua_woool_MapView_setScale);
        tolua_function(tolua_S,"setMainRole",lua_woool_MapView_setMainRole);
        tolua_function(tolua_S,"setMapActionFlag",lua_woool_MapView_setMapActionFlag);
        tolua_function(tolua_S,"getCurTile",lua_woool_MapView_getCurTile);
        tolua_function(tolua_S,"removeRockerCb",lua_woool_MapView_removeRockerCb);
        tolua_function(tolua_S,"setPosition",lua_woool_MapView_setPosition);
        tolua_function(tolua_S,"setAttackFlag",lua_woool_MapView_setAttackFlag);
        tolua_function(tolua_S,"hasPath",lua_woool_MapView_hasPath);
        tolua_function(tolua_S,"getRolePathNum",lua_woool_MapView_getRolePathNum);
        tolua_function(tolua_S,"isStoryMap",lua_woool_MapView_isStoryMap);
        tolua_function(tolua_S,"cleanAstarPath",lua_woool_MapView_cleanAstarPath);
        tolua_function(tolua_S,"getMainRole",lua_woool_MapView_getMainRole);
        tolua_function(tolua_S,"getNearTiled",lua_woool_MapView_getNearTiled);
        tolua_function(tolua_S,"setBlockRectValue",lua_woool_MapView_setBlockRectValue);
        tolua_function(tolua_S,"getMapActionFlag",lua_woool_MapView_getMapActionFlag);
        tolua_function(tolua_S,"moveMapByPos",lua_woool_MapView_moveMapByPos);
        tolua_function(tolua_S,"IsOutoffScreen",lua_woool_MapView_IsOutoffScreen);
        tolua_function(tolua_S,"loadMapNew",lua_woool_MapView_loadMapNew);
        tolua_function(tolua_S,"removeWalkCb",lua_woool_MapView_removeWalkCb);
        tolua_function(tolua_S,"moveLock",lua_woool_MapView_moveLock);
        tolua_function(tolua_S,"isOpacity",lua_woool_MapView_isOpacity);
        tolua_function(tolua_S,"isHasAllLoaded",lua_woool_MapView_isHasAllLoaded);
        tolua_function(tolua_S,"getSpeedUp",lua_woool_MapView_getSpeedUp);
        tolua_function(tolua_S,"loadSpritesPre",lua_woool_MapView_loadSpritesPre);
        tolua_function(tolua_S,"initDataAndFunc",lua_woool_MapView_initDataAndFunc);
        tolua_function(tolua_S,"loadMap",lua_woool_MapView_loadMap);
        tolua_function(tolua_S,"tile2Space",lua_woool_MapView_tile2Space);
        tolua_function(tolua_S,"getDestPosition",lua_woool_MapView_getDestPosition);
        tolua_function(tolua_S,"getSkillRootNode",lua_woool_MapView_getSkillRootNode);
        tolua_function(tolua_S,"setRockDir",lua_woool_MapView_setRockDir);
        tolua_function(tolua_S,"space2Tile",lua_woool_MapView_space2Tile);
        tolua_function(tolua_S,"resetSpeed",lua_woool_MapView_resetSpeed);
        tolua_function(tolua_S,"GetItemRoot",lua_woool_MapView_GetItemRoot);
        tolua_function(tolua_S,"resetShowHurt", lua_woool_MapView_resetShowHurt);
        tolua_function(tolua_S,"create", lua_woool_MapView_create);
        tolua_function(tolua_S,"GetDirByPos", lua_woool_MapView_GetDirByPos);
        tolua_function(tolua_S,"resetBloodNode", lua_woool_MapView_resetBloodNode);
        tolua_function(tolua_S,"getFlyTime", lua_woool_MapView_getFlyTime);
        tolua_function(tolua_S,"getSkillNode", lua_woool_MapView_getSkillNode);
        tolua_function(tolua_S,"setMaxLockNum", lua_woool_MapView_setMaxLockNum);
        tolua_function(tolua_S,"getSkillDownNode", lua_woool_MapView_getSkillDownNode);
        tolua_function(tolua_S,"onMsgHandler", lua_woool_MapView_onMsgHandler);
        tolua_function(tolua_S,"getTitleNode", lua_woool_MapView_getTitleNode);

		tolua_function(tolua_S, "getMapSize", lua_woool_MapView_getMapSize);
		tolua_function(tolua_S, "getTileSize", lua_woool_MapView_getTileSize);

    tolua_endmodule(tolua_S);
    std::string typeName = typeid(MapView).name();
    g_luaType[typeName] = "MapView";
    g_typeCast["MapView"] = "MapView";
    return 1;
}
TOLUA_API int register_all_woool(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,nullptr,0);
	tolua_beginmodule(tolua_S,nullptr);

	lua_register_woool_MirBatchDrawLabel(tolua_S);
	lua_register_woool_HttpSprite(tolua_S);
	lua_register_woool_MapViewBase(tolua_S);
	//lua_register_woool_OperateLayer(tolua_S);
	lua_register_woool_MapView(tolua_S);
	lua_register_woool_MapTileNode(tolua_S);
	lua_register_woool_SpriteBase(tolua_S);
	lua_register_woool_SpriteCharacterBase(tolua_S);
	lua_register_woool_SpriteMonster(tolua_S);
	lua_register_woool_SpritePlayer(tolua_S);
	//lua_register_woool_CCoverflow(tolua_S);
	//lua_register_woool_Effects(tolua_S);
	//lua_register_woool_CMagicCtrlMgr(tolua_S);
	lua_register_woool_UISpriteCharacter(tolua_S);
	lua_register_woool_UIMapView(tolua_S);
	lua_register_woool_MirTextNodeFormatter(tolua_S);
	lua_register_woool_GraySprite(tolua_S);
	lua_register_woool_TouchSprite(tolua_S);
	//lua_register_woool_MenuButton(tolua_S);
	lua_register_woool_DirtyWords(tolua_S);
	//lua_register_woool_LuaSocket(tolua_S);
	//lua_register_woool_CIrregularButton(tolua_S);
	//lua_register_woool_LuaMsgBuffer(tolua_S);
	//lua_register_woool_LuaEventManager(tolua_S);
	lua_register_woool_MakeNumbers(tolua_S);
	lua_register_woool_Touch9Sprite(tolua_S);
	//lua_register_woool_BtnContainer(tolua_S);
	lua_register_woool_MirTextNode(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

