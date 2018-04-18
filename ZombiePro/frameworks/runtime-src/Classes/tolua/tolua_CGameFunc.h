#include "tolua++.h"
#include "LuaBasicConversions.h"
#include "tolua_fix.h"
#include "common/CGameFunc.h"

/************************************************************************/
/*						 函数模板									    */
/************************************************************************/
/*
static int tolua_CGameFunc_xxxxx(lua_State* tolua_S)
{
	int argc = 0;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertable(tolua_S, 1, "CGameFunc", 0, &tolua_err)) goto tolua_lerror;
#endif

	argc = lua_gettop(tolua_S) - 1;

	if (argc == x)
	{

	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "tolua_CGameFunc_xxxxx", argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'tolua_CGameFunc_xxxxx'.", &tolua_err);
#endif
	return 0;
}*/

static int lua_CGameFunc_IsNodeValid(lua_State* tolua_S)
{
	int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1)
	{
		do
		{
			Node* pNode = NULL;
			bool ok = luaval_to_object<Node>(tolua_S, 2, "cc.Node", &pNode);
			if (!ok || !pNode)
			{
				tolua_pushboolean(tolua_S, false);
				return 1;
			}
			tolua_pushboolean(tolua_S, true);
			return 1;
		} while (1);
	}
	tolua_error(tolua_S, "error in function 'lua_CGameFunc_isNodeValid'", NULL);
	return 0;
}

static int lua_CGameFunc_MkDir(lua_State* tolua_S)
{
	int argc = 0;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertable(tolua_S, 1, "CGameFunc", 0, &tolua_err)) goto tolua_lerror;
#endif

	argc = lua_gettop(tolua_S) - 1;

	if (argc == 1)
	{
		std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "CGameFunc:MkDir"); const char* arg0 = arg0_tmp.c_str();

		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_CGameFunc_MkDir'", nullptr);
			return 0;
		}
		CGameFunc::MkDir(arg0);
		return 0;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CGameFunc:MkDir", argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'lua_CGameFunc_MkDir'.", &tolua_err);
#endif
	return 0;
}

static int tolua_CGameFunc_GetWorkDir(lua_State* tolua_S)
{
	int argc = 0;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertable(tolua_S, 1, "CGameFunc", 0, &tolua_err)) goto tolua_lerror;
#endif

	argc = lua_gettop(tolua_S) - 1;

	if (argc == 0)
	{
		
		//char* ret = new char[];
		char ret[255];
		memset(ret, 0, 255);
		CGameFunc::GetWorkDir(ret);
		tolua_pushstring(tolua_S, (const char*)ret);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "tolua_CGameFunc_GetWorkDir", argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'tolua_CGameFunc_GetWorkDir'.", &tolua_err);
#endif
	return 0;
}

static int tolua_CGameFunc_DoCmd(lua_State* tolua_S)
{
	int argc = 0;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertable(tolua_S, 1, "CGameFunc", 0, &tolua_err)) goto tolua_lerror;
#endif

	argc = lua_gettop(tolua_S) - 1;

	if (argc == 1)
	{
		const char* arg0;
		std::string arg0_temp;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0_temp, "CGameFunc::DoCmd");
		arg0 = arg0_temp.c_str();
		if (!ok)
		{
			tolua_error(tolua_S, "invalid arguments in function 'lua_CGameFunc_DoCmd'", nullptr);
		}
		CGameFunc::DoCmd(arg0);
		return 0;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "tolua_CGameFunc_DoCmd", argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'tolua_CGameFunc_DoCmd'.", &tolua_err);
#endif
	return 0;
}

//获取ini文件
static int tolua_ParseIniToTable(lua_State* tolua_S)
{
	int argc = 0;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertable(tolua_S, 1, "CGameFunc", 0, &tolua_err)) goto tolua_lerror;
#endif

	argc = lua_gettop(tolua_S) - 1;

	if (argc == 1)
	{
		const char* arg0;
		std::string arg0_temp;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0_temp, "CGameFunc::ParseIniToTable");
		arg0 = arg0_temp.c_str();
		if (cocos2d::FileUtils::getInstance()->isFileExist(arg0))
		{	
			std::string sFileFullPath = cocos2d::FileUtils::getInstance()->fullPathForFilename(arg0);
			std::map<std::string, std::map<string, std::string>> stIni;
			CGameFunc::ParseIniToMap(sFileFullPath.c_str(), stIni);
			std::map<std::string, std::map<std::string, std::string>>::iterator it_parent;
			std::map<std::string, std::string>::iterator it_sub;
			lua_newtable(tolua_S);									/*stack: parentTable */
			for (it_parent = stIni.begin(); it_parent != stIni.end(); it_parent++)
			{		
				lua_pushstring(tolua_S, it_parent->first.c_str());	/*stack: parentTable sParentKey */
				lua_newtable(tolua_S);								/*stack: parentTable sParentKey subTable */
				for (it_sub = it_parent->second.begin(); it_sub != it_parent->second.end(); ++it_sub)
				{
					lua_pushstring(tolua_S, it_sub->first.c_str());	/*stack: parentTable sParentKey subTable sSubKey */
					lua_pushstring(tolua_S, it_sub->second.c_str());/*stack: parentTable sParentKey subTable sSubKey sSubValue*/
					lua_rawset(tolua_S, -3);						/*stack: parentTable sParentKey subTable*/
				}
				lua_rawset(tolua_S, -3);
			}
		}
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "tolua_ParseIniToTable", argc, 1);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'tolua_ParseIniToTable'.", &tolua_err);
#endif
	return 0;
}

static int tolua_GetIniCach(lua_State* tolua_S)
{
	int argc = 0;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertable(tolua_S, 1, "CGameFunc", 0, &tolua_err)) goto tolua_lerror;
#endif

	argc = lua_gettop(tolua_S) - 1;

	if (argc == 0)
	{
		std::map<std::string, std::map<string, std::string>> stIni;
		CGameFunc::GetIniMap(stIni);
		std::map<std::string, std::map<std::string, std::string>>::iterator it_parent;
		std::map<std::string, std::string>::iterator it_sub;
		lua_newtable(tolua_S);									/*stack: parentTable */
		for (it_parent = stIni.begin(); it_parent != stIni.end(); it_parent++)
		{
			lua_pushstring(tolua_S, it_parent->first.c_str());	/*stack: parentTable sParentKey */
			lua_newtable(tolua_S);								/*stack: parentTable sParentKey subTable */
			for (it_sub = it_parent->second.begin(); it_sub != it_parent->second.end(); ++it_sub)
			{
				lua_pushstring(tolua_S, it_sub->first.c_str());	/*stack: parentTable sParentKey subTable sSubKey */
				lua_pushstring(tolua_S, it_sub->second.c_str());/*stack: parentTable sParentKey subTable sSubKey sSubValue*/
				lua_rawset(tolua_S, -3);						/*stack: parentTable sParentKey subTable*/
			}
			lua_rawset(tolua_S, -3);
		}
	return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "tolua_GetIniCach", argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'tolua_GetIniCach'.", &tolua_err);
#endif
	return 0;
}

static int tolua_getAccount(lua_State* tolua_S)
{
	int argc = 0;
	bool ok = true;

#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
	if (!tolua_isusertable(tolua_S, 1, "CGameFunc", 0, &tolua_err)) goto tolua_lerror;
#endif

	argc = lua_gettop(tolua_S) - 1;

	if (argc == 0)
	{
		string strAccount;
		string strPwd;
		CGameFunc::getAccount(strAccount, strPwd);
		lua_pushstring(tolua_S, strAccount.c_str());
		lua_pushstring(tolua_S, strPwd.c_str());
		return 2;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "CGameFunc:getAccount", argc, 0);
	return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'tolua_CGameFunc_xxxxx'.", &tolua_err);
#endif
	return 0;
}

static void lua_register_CGameFunc(lua_State* L)
{
	tolua_usertype(L, "CGameFunc");
	tolua_cclass(L, "CGameFunc", "CGameFunc", "", nullptr);

	tolua_beginmodule(L, "CGameFunc");
		tolua_function(L, "IsNodeValid", lua_CGameFunc_IsNodeValid);
		tolua_function(L, "MkDir", lua_CGameFunc_MkDir);
		tolua_function(L, "GetWorkDir", tolua_CGameFunc_GetWorkDir);
		tolua_function(L, "DoCmd", tolua_CGameFunc_DoCmd);
		tolua_function(L, "ParseIniToTable", tolua_ParseIniToTable);
		tolua_function(L, "GetIniCach", tolua_GetIniCach);
		tolua_function(L, "getAccount", tolua_getAccount);
	tolua_endmodule(L);
}