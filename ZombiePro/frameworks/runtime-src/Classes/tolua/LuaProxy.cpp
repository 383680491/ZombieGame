#include "LuaProxy.h"
#include "lua_woool_auto.h"
#include "lua_woool_manual.h"
//#include "young/Young.h"

//#include "tolua_SpriteBase.h"
//#include "tolua_CCEffects.h"
//#include "tolua_BtnContainer.h"
//#include "tolua_MenuButton.h"
//#include "tolua_OperateLayer.h"
//#include "tolua_MakeNumbers.h"
//#include "tolua_LuaMsgBuffer.h"
//#include "tolua_MirControl.h"
//#include "tolua_MagicMgr.h"
//#include "tolua_DirtyWords.h"
//#include "tolua_luaSocket.h"
//#include "tolua_MapView.h"

//#include "sjcj/MdsAgent_binding.h"
//#include "tolua_AutoUpdate.h"
//#include "tolua_sdk.h"
//#include "tolua_tersafe.h"
//#include "tolua_VoiceApollo.h"
//#include "tolua_pbc.h"
#include "tolua_ScreenRecording.h"

#ifdef WIN32
#include "tolua_DebugError.h"
#include "tolua_CGameFunc.h"
#endif

//手写的的函数放在这里注册
static void registerLua(lua_State* l)
{
    //lua_register_AutoUpdate(l);
    
   // lua_register_sdk(l);

	lua_register_screenRecording(l);
#ifdef WIN32
	lua_register_debugError(l);
#endif // WIN32

	//luaopen_protobuf_c(l);
}

TOLUA_API int lua_LuaProxy(lua_State* l){
	
	register_all_woool(l);			// 自动生成
	register_all_woool_manual(l);	// 手写
	//tolua_Young_open(l);	

//-----------------------------------------------------------------

	tolua_open(l);
	tolua_module(l, NULL, 0);
	tolua_beginmodule(l, NULL);
//-----------------------------------------------------------------
//tolua++ 生成的注册放在这里

	//lua_register_cocos2dx_MapView(l);
	//lua_register_cocos2dx_SpriteBase(l);
	//lua_register_cocos2dx_SpriteMonster(l);
	//lua_register_cocos2dx_SpritePlayer(l);
	//lua_register_cocos2dx_GraySprite(l);
	//lua_register_cocos2dx_TouchSprite(l);
	//lua_register_cocos2dx_Touch9Sprite(l);
	//lua_register_cocos2dx_HttpSprite(l);
	//lua_register_cocos2dx_Effects(l);
	//lua_register_cocos2dx_BtnContainer(l);
	//lua_register_cocos2dx_MenuButton(l);	
	//lua_register_cocos2dx_OperateLayer(l);
	//lua_register_cocos2dx_MakeNumbers(l);
	//lua_register_cocos2dx_DirtyWords(l);
	//lua_register_CMagicCtrlMgr(l);
	//lua_register_MirControl_MirBatchDrawLabel(l);
	//lua_register_MirControl_MirTextNodeFormatter(l);
	//lua_register_MirControl_MirTextNode(l);
	//tolua_LuaMsgBuffer_open(l);
	//tolua_LuaSocket_open(l);

#ifdef WIN32
	lua_register_CGameFunc(l);
#endif // WIN32
	
	//tolua_MdsAgent_open(l);

//	lua_register_tersafe_TersafeSDK(l);
//	lua_register_VoiceApollo_VoiceApollo(l);
    
//------------------------------------------------------------
	tolua_endmodule(l);
    registerLua(l);
	return 1;
}


