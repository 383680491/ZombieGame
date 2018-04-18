#include "LuaBasicConversions.h"
#include "tolua_fix.h"
static int lua_DebugError(lua_State* L)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	bool ok = true;
	if (nullptr == L)
		return 0;

	int argc = lua_gettop(L);
	if (1 == argc)
	{
		const char* arg0;
		std::string arg0_tmp;
		ok &= luaval_to_std_string(L, 1, &arg0_tmp, "lua_DebugError");
		if (ok)
		{
			arg0 = arg0_tmp.c_str();
			MessageBox(arg0, "error!");
		}
	}
#endif
	return 0;
}

static void lua_register_debugError(lua_State* L)
{
	lua_register(L, "DebugError", lua_DebugError);
}