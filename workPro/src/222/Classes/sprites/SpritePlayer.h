#ifndef _SPIRIT_PLAYER_
#define _SPIRIT_PLAYER_

#include "SpriteMonster.h"



class SpritePlayer : public SpriteMonster 
{
public: 

	SpritePlayer();
	virtual ~SpritePlayer(void);
	//virtual bool initWithFile(const std::string&pszFileName);

	static SpritePlayer* create(const std::string&pszFileName,int actorflag);
	bool isActor();
	CC_SYNTHESIZE(double, m_role_id, RoleId); 
	CC_SYNTHESIZE(int, m_sex, Sex);
	CC_SYNTHESIZE(double, m_school, School);
	CC_SYNTHESIZE(bool, m_unAttack, UnToAttack);
	CC_SYNTHESIZE(bool, m_isMonster_role, IsMonsterRole);

	virtual void removeStread()override;
	virtual void moveToPos(float times,cocos2d::Point pos,bool stand = false)override;
	virtual void hasHurted(float delay,float times)override;
	virtual bool moveInTheDir(float times,cocos2d::Point pos,Commen_Direction dir,float movetimes = 0.0f)override;
	bool moveInTheDir_ex(float times,cocos2d::Point pos,Commen_Direction dir,float movetimes = 0.0f);
	virtual bool collideInTheDir(float times,cocos2d::Point pos,Commen_Direction dir)override;
	virtual bool digToTheDir(float times,Commen_Direction dir)override;
	virtual bool excavateToTheDir(float times,Commen_Direction dir)override;
	bool attackOnRide(float times, const cocos2d::Point& newpoint,Commen_Direction dir, int iTileNums=5);
	// 道士-毒凌波类动作
	bool AttackDSUpToPos(float times,Point newpoint);
};
#endif//_SPIRIT_PLAYER_
