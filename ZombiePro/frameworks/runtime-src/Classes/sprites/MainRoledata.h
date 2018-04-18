#ifndef _MAIN_ROLE_DATA_
#define _MAIN_ROLE_DATA_

#include "cocos2d.h"
#include "Commen_ActionToDo.h"
#include "Commen_Direction.h"





class MainRoledata
{
public :
	MainRoledata()
	{
		onedir = dir_undef;
		maxcut_walk = 4;
		actiontime = 0.25f;
		walkactrate = 0.6f;
	}

	//人物初始坐标
	cocos2d::Point nowpoint;
	//人物默认像素图
	std::string spiritUrl;

	//人物站立最大帧
	uint8_t maxcut_stand;
	//人物走动最大帧
	uint8_t maxcut_walk;
	//人物跑动最大帧
	uint8_t maxcut_run;
	//人物战斗最大帧
	uint8_t maxcut_attack;
	//人物伤害最大帧
	uint8_t maxcut_hurt;
	//人物施法最大帧
	uint8_t maxcut_magic;
	uint8_t maxcut_ex;
	//人物当前动作
	Commen_ActionToDo acttodo;
	//人物当前朝向
	Commen_Direction dir;
	// 单方向
	Commen_Direction onedir;
	//行走动画播放速度
	float walkactrate;
	//动画时间
	float actiontime;
	
	std::string act_res;
	
};

#endif
