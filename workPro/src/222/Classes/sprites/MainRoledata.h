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

	//�����ʼ����
	cocos2d::Point nowpoint;
	//����Ĭ������ͼ
	std::string spiritUrl;

	//����վ�����֡
	uint8_t maxcut_stand;
	//�����߶����֡
	uint8_t maxcut_walk;
	//�����ܶ����֡
	uint8_t maxcut_run;
	//����ս�����֡
	uint8_t maxcut_attack;
	//�����˺����֡
	uint8_t maxcut_hurt;
	//����ʩ�����֡
	uint8_t maxcut_magic;
	uint8_t maxcut_ex;
	//���ﵱǰ����
	Commen_ActionToDo acttodo;
	//���ﵱǰ����
	Commen_Direction dir;
	// ������
	Commen_Direction onedir;
	//���߶��������ٶ�
	float walkactrate;
	//����ʱ��
	float actiontime;
	
	std::string act_res;
	
};

#endif
