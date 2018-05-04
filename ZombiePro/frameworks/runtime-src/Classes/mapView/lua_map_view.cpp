#include "lua_map_view.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#include "scripting/lua-bindings/manual/CCLuaEngine.h"
#include "MapView.h"
#include "NodeAStar.h"

int lua_map_view_create(lua_State* tolua_S)
{
	int argc = 0;
	MapView* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif



	argc = lua_gettop(tolua_S) - 1;
	if (argc == 0)
	{
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_map_view_create'", nullptr);
			return 0;
		}
		cobj = new MapView();
		int ID = (int)cobj->_ID;
		int* luaID = &cobj->_luaID;
		toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj, "MapView");
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView::create", argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
	tolua_error(tolua_S, "#ferror in function 'lua_map_view_create'.", &tolua_err);
#endif

	return 0;
}


int lua_map_view_load(lua_State* tolua_S)
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
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_map_view_load'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_map_view_load'", nullptr);
			return 0;
		}
		std::string filename = tolua_tostring(tolua_S, 2, 0);
		cobj->load(filename);
		lua_settop(tolua_S, 1);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:load", argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_map_view_load'.", &tolua_err);
#endif

	return 0;
}


int lua_map_view_isBlock(lua_State* tolua_S)
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
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_map_view_isBlock'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		cocos2d::Point arg0;

		ok &= luaval_to_point(tolua_S, 2, &arg0, "MapView:isBlock");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_map_view_isBlock'", nullptr);
			return 0;
		}
		bool ret = cobj->isBlock(arg0);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:isBlock", argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_map_view_isBlock'.", &tolua_err);
#endif

	return 0;
}

int lua_map_view_isOpacity(lua_State* tolua_S)
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
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_map_view_isOpacity'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		cocos2d::Point arg0;

		ok &= luaval_to_point(tolua_S, 2, &arg0, "MapView:isOpacity");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_map_view_isOpacity'", nullptr);
			return 0;
		}
		bool ret = cobj->isOpacity(arg0);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:isOpacity", argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_map_view_isOpacity'.", &tolua_err);
#endif

	return 0;
}


int lua_map_view_tile2Space(lua_State* tolua_S)
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
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_map_view_tile2Space'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		cocos2d::Point arg0;

		ok &= luaval_to_point(tolua_S, 2, &arg0, "MapView:tile2Space");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_map_view_tile2Space'", nullptr);
			return 0;
		}
		cocos2d::Point ret = cobj->tile2Space(arg0);
		point_to_luaval(tolua_S, ret);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:tile2Space", argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_map_view_tile2Space'.", &tolua_err);
#endif

	return 0;
}

int lua_map_view_space2Tile(lua_State* tolua_S)
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
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_map_view_space2Tile'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		cocos2d::Point arg0;

		ok &= luaval_to_point(tolua_S, 2, &arg0, "MapView:space2Tile");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_map_view_space2Tile'", nullptr);
			return 0;
		}
		cocos2d::Point ret = cobj->space2Tile(arg0);
		point_to_luaval(tolua_S, ret);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:space2Tile", argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_map_view_space2Tile'.", &tolua_err);
#endif

	return 0;
}


int lua_map_view_getMapSize(lua_State* tolua_S)
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
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_map_view_getMapSize'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 0)
	{

		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_map_view_getMapSize'", nullptr);
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
	tolua_error(tolua_S, "#ferror in function 'lua_map_view_getMapSize'.", &tolua_err);
#endif

	return 0;
}




int lua_map_view_getTileSize(lua_State* tolua_S)
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
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_map_view_getTileSize'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 0)
	{

		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_map_view_getTileSize'", nullptr);
			return 0;
		}

		const cocos2d::Size& ret = cobj->getTileSize();
		size_to_luaval(tolua_S, ret);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:getTileSize", argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_map_view_getTileSize'.", &tolua_err);
#endif

	return 0;
}

int lua_map_view_setPosition(lua_State* tolua_S)
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
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_map_view_setPosition'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		cocos2d::Point arg0;

		ok &= luaval_to_point(tolua_S, 2, &arg0, "MapView:setPosition");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_map_view_setPosition'", nullptr);
			return 0;
		}
		cobj->setPosition(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "MapView:setPosition", argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_map_view_setPosition'.", &tolua_err);
#endif

	return 0;
}


































int lua_NodeAStar_createPath(lua_State* tolua_S)
{
	int argc = 0;
	NodeAStar* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "NodeAStar", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (NodeAStar*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_NodeAStar_createPath'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 0)
	{
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_NodeAStar_createPath'", nullptr);
			return 0;
		}
		cobj->createPath();
		lua_settop(tolua_S, 1);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "NodeAStar:createPath", argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_NodeAStar_createPath'.", &tolua_err);
#endif

	return 0;
}
int lua_NodeAStar_findPath(lua_State* tolua_S)
{
	int argc = 0;
	NodeAStar* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "NodeAStar", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (NodeAStar*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_NodeAStar_findPath'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		cocos2d::Point arg0;

		ok &= luaval_to_point(tolua_S, 2, &arg0, "NodeAStar:findPath");
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_NodeAStar_findPath'", nullptr);
			return 0;
		}
		cobj->findPath(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "NodeAStar:findPath", argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_NodeAStar_findPath'.", &tolua_err);
#endif

	return 0;
}
int lua_NodeAStar_deleteDoneNode(lua_State* tolua_S)
{
	int argc = 0;
	NodeAStar* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "NodeAStar", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (NodeAStar*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_NodeAStar_deleteDoneNode'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 0)
	{
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_NodeAStar_deleteDoneNode'", nullptr);
			return 0;
		}
		cobj->deleteDoneNode();
		lua_settop(tolua_S, 1);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "NodeAStar:deleteDoneNode", argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_NodeAStar_deleteDoneNode'.", &tolua_err);
#endif

	return 0;
}
int lua_NodeAStar_getPathNode(lua_State* tolua_S)
{
	int argc = 0;
	NodeAStar* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "NodeAStar", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (NodeAStar*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_NodeAStar_getPathNode'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 0)
	{
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_NodeAStar_getPathNode'", nullptr);
			return 0;
		}
		_AstarNode* node = cobj->getPathNode();
		Point p;
		if (node == NULL)
		{
			p.x = -1;
			p.y = -1;
		}
		else
		{
			p.x = node->X;
			p.y = node->Y;
		}

		point_to_luaval(tolua_S, p);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "NodeAStar:getPathNode", argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_NodeAStar_getPathNode'.", &tolua_err);
#endif

	return 0;
}
int lua_NodeAStar_setMap(lua_State* tolua_S)
{
	int argc = 0;
	NodeAStar* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "NodeAStar", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (NodeAStar*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_NodeAStar_setMap'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		MapView* arg0 = (MapView*)tolua_tousertype(tolua_S, 2, 0);
		cobj->setMap(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "NodeAStar:setMap", argc, 1);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_NodeAStar_setMap'.", &tolua_err);
#endif

	return 0;
}
int lua_NodeAStar_create(lua_State* tolua_S)
{
	int argc = 0;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertable(tolua_S, 1, "NodeAStar", 0, &tolua_err)) goto tolua_lerror;
#endif

	if (argc == 0)
	{
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_NodeAStar_create'", nullptr);
			return 0;
		}
		NodeAStar* ret = NodeAStar::create();
		object_to_luaval<cocos2d::Node>(tolua_S, "NodeAStar", (NodeAStar*)ret);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "NodeAStar:create", argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_NodeAStar_create'.", &tolua_err);
#endif
	return 0;
}
int lua_NodeAStar_getPathCount(lua_State* tolua_S)
{
	int argc = 0;
	NodeAStar* cobj = nullptr;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertype(tolua_S, 1, "NodeAStar", 0, &tolua_err)) goto tolua_lerror;
#endif

	cobj = (NodeAStar*)tolua_tousertype(tolua_S, 1, 0);

#if COCOS2D_DEBUG >= 1
	if (!cobj)
	{
		tolua_error(tolua_S, "invalid 'cobj' in function 'lua_NodeAStar_getPathCount'", nullptr);
		return 0;
	}
#endif

	argc = lua_gettop(tolua_S) - 1;
	if (argc == 0)
	{
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_NodeAStar_getPathCount'", nullptr);
			return 0;
		}
		int count = cobj->getPathCount();
		tolua_pushnumber(tolua_S, (lua_Number)count);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "NodeAStar:getPathCount", argc, 0);
	return 0;

#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_NodeAStar_getPathCount'.", &tolua_err);
#endif

	return 0;
}










int register_map_view(lua_State* tolua_S)
{
    tolua_usertype(tolua_S, "MapView");
    tolua_cclass(tolua_S, "MapView", "MapView", "cc.Node", nullptr);

    tolua_beginmodule(tolua_S, "MapView");
	tolua_function(tolua_S, "create", lua_map_view_create);
	tolua_function(tolua_S, "load", lua_map_view_load);
	tolua_function(tolua_S, "isBlock", lua_map_view_isBlock);
	tolua_function(tolua_S, "isOpacity", lua_map_view_isOpacity);
	tolua_function(tolua_S, "tile2Space", lua_map_view_tile2Space);
	tolua_function(tolua_S, "space2Tile", lua_map_view_space2Tile);
	tolua_function(tolua_S, "getMapSize", lua_map_view_getMapSize);
	tolua_function(tolua_S, "getTileSize", lua_map_view_getTileSize);
	tolua_function(tolua_S, "setPosition", lua_map_view_setPosition);

    tolua_endmodule(tolua_S);

	std::string typeName = typeid(MapView).name();
    g_luaType[typeName] = "MapView";
    g_typeCast["MapView"] = "MapView";
    return 1;
}


int register_NodeAStar(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "NodeAStar");
	tolua_cclass(tolua_S, "NodeAStar", "NodeAStar", "cc.Node", nullptr);

	tolua_beginmodule(tolua_S, "NodeAStar");
	tolua_function(tolua_S, "createPath", lua_NodeAStar_createPath);
	tolua_function(tolua_S, "findPath", lua_NodeAStar_findPath);
	tolua_function(tolua_S, "getPathNode", lua_NodeAStar_getPathNode);
	tolua_function(tolua_S, "deleteDoneNode", lua_NodeAStar_deleteDoneNode);
	tolua_function(tolua_S, "create", lua_NodeAStar_create);
	tolua_function(tolua_S, "setMap", lua_NodeAStar_setMap);
	tolua_function(tolua_S, "getPathCount", lua_NodeAStar_getPathCount);

	tolua_endmodule(tolua_S);
	std::string typeName = typeid(NodeAStar).name();
	g_luaType[typeName] = "NodeAStar";
	g_typeCast["NodeAStar"] = "NodeAStar";
	return 1;
}


TOLUA_API int register_all_map_view(lua_State* L)
{
    tolua_open(L);

    tolua_module(L, nullptr, 0);
    tolua_beginmodule(L, nullptr);

	register_map_view(L);
	register_NodeAStar(L);

    tolua_endmodule(L);

    return 1;
}