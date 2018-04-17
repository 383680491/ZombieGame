#pragma once

//#include "screenRecording/ScreenRecording.h"
#include "common/utils.h"


// 是否支持录像功能(仅ios9以上支持)
static int lua_isSupportReplay(lua_State *L)
{
	//lua_pushboolean(L, isSupportReplay() ? 1 : 0);
    return 1;
}

// 开始录制视频
static int  lua_startRecording(lua_State *L)
{
	//startRecording();
	return 0;
}

// 停止录制视频
static int lua_stopRecording(lua_State *L)
{
//	stopRecording();
	return 0;
}

// 显示视频
static int lua_displayRecordingContent(lua_State *L)
{
//	displayRecordingContent();
	return 0;
}
void lua_register_screenRecording(lua_State* L)
{
    lua_register(L, "isSupportReplay", lua_isSupportReplay);
	lua_register(L, "startRecording", lua_startRecording);
	lua_register(L, "stopRecording", lua_stopRecording);
	lua_register(L, "displayRecordingContent", lua_displayRecordingContent);
}

