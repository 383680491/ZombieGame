#include "SpritePlayer.h"
#include "ObjectMoveAction.h"

USING_NS_CC;

const float PLAYERRUNSPEEDRATE  = 2.8f;
const float PLAYERRUNSPEEDRATE2 = 3.5f;

SpritePlayer::SpritePlayer()
{	
	m_isMonster_role = false;
	m_unAttack = true;
}

SpritePlayer::~SpritePlayer(void)
{
}

SpritePlayer *SpritePlayer::create(const std::string&pszFileName,int actorflag)
{
    SpritePlayer *pRet = new SpritePlayer();
	if(pRet) 
		pRet->setActorFlag(actorflag>0);
    if (pRet && pRet->initWithFileExt(pszFileName))
    {
		 //pRet->getMainSprite()->setPosition(0,20)
		if(actorflag>0)
		{
			pRet->setRoleId(actorflag);
		}
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}

bool SpritePlayer::isActor()
{
	return getActorFlag();
}


void SpritePlayer::moveToPos(float times,Point newpoint,bool stand)
{
	//removeStread();
	if(getCurrActionState()<ACTION_STATE_CREATE)
	{
		if(changeState(ACTION_STATE_RUN)||setDirByNowPoint(newpoint))
		{
			
			setDirByNowPoint(newpoint);
			playAction(0.15f,run,m_roledata.dir,0.0f);
			for (auto c_sprite : m_sprites)
			{
				initOrderByDir(c_sprite,m_roledata.dir);
				c_sprite->playAction(0.15f,run,m_roledata.dir,0.0f);
			}
		}
		if(stand)
		{
			FiniteTimeAction* actbackfun = CallFunc::create([&](){ this->standed();});
			runAction(Sequence::create(MoveTo::create(times,newpoint),actbackfun,NULL));
		}
		else
			runAction( MoveTo::create(times,newpoint));
	}
}

bool SpritePlayer::moveInTheDir(float times,Point newpoint,Commen_Direction dir,float movetimes)
{
	//removeStread();
	if(getActorFlag()&&(getCurrActionState()==ACTION_STATE_ATTACK||getCurrActionState()==ACTION_STATE_MAGICUP
		||getCurrActionState()==ACTION_STATE_COLLIDE ))
		return false;

	if(getCurrActionState()<ACTION_STATE_CREATE)
	{
		if(changeState(ACTION_STATE_RUN)||setSpriteDir(dir))
		{
			float actLoopTime = 0.6f;
			playAction(actLoopTime, run, dir, 0);
			for (const auto c_sprite : m_sprites)
			{
				initOrderByDir(c_sprite,dir);
				c_sprite->playAction(actLoopTime, run, dir, 0);
			}
		}
		if(newpoint != Point(0,0))
		{
			if(movetimes == 0) movetimes = times;
			
			if(getActorFlag())
			{
				//FiniteTimeAction* doset = CallFunc::create(CC_CALLBACK_0(SpriteMonster::doSetOpacity_ex,this));
				//runAction(Sequence::create( MoveTo::create(movetimes,newpoint),doset,NULL));

				runAction(ObjectMoveAction::create(movetimes,newpoint,CC_CALLBACK_0(SpriteMonster::doSetOpacity_ex,this)) );
			}
			else
			{
				//FiniteTimeAction* doset = CallFunc::create(CC_CALLBACK_0(SpriteMonster::doSetOpacity,this));
				//runAction(Sequence::create( MoveTo::create(movetimes,newpoint),doset,NULL));

				runAction(ObjectMoveAction::create(movetimes,newpoint,CC_CALLBACK_0(SpriteMonster::doSetOpacity,this)) );
			}
		}
		return true;
	}
	return false;
}

bool SpritePlayer::moveInTheDir_ex(float times,Point newpoint,Commen_Direction dir,float movetimes)
{
	//removeStread();
	if(getActorFlag()&&(getCurrActionState()==ACTION_STATE_ATTACK||getCurrActionState()==ACTION_STATE_MAGICUP
		||getCurrActionState()==ACTION_STATE_COLLIDE ))
		return false;

	if(getCurrActionState()<ACTION_STATE_CREATE)
	{
		if(changeState(ACTION_STATE_RUN)||setSpriteDir(dir))
		{
			float actLoopTime = 0.6f;
			playAction(actLoopTime, run, dir, 0);
			for (const auto c_sprite : m_sprites)
			{
				initOrderByDir(c_sprite,dir);
				c_sprite->playAction(actLoopTime, run, dir, 0);
			}
		}
		if(newpoint != Point(0,0))
		{
			if(movetimes == 0) movetimes = times;
			
			if(getSeverPointsNum()>1)
			{
				//CCLOG("[SpritePlayer::moveInTheDir_ex] %u, %f, %f", Director::getInstance()->getTotalFrames(), getPositionX(), getPositionY());

				//FiniteTimeAction* doset = CallFunc::create(CC_CALLBACK_0(SpriteMonster::doSetOpacity_ex,this));
				//runAction(Sequence::create( MoveTo::create(movetimes,newpoint),doset,NULL));
				runAction(ObjectMoveAction::create(movetimes,newpoint,CC_CALLBACK_0(SpriteMonster::doSetOpacity_ex,this)));
			}
			else
			{
				//CCLOG("[SpritePlayer::moveInTheDir_ex - 2] %u, %f, %f", Director::getInstance()->getTotalFrames(), getPositionX(), getPositionY());

				//FiniteTimeAction* doset = CallFunc::create(CC_CALLBACK_0(SpriteMonster::doSetOpacity_ex,this));
				FiniteTimeAction* dostand = CallFunc::create(CC_CALLBACK_0(SpriteMonster::doStanded,this));
				runAction(ObjectMoveAction::create(movetimes,newpoint,CC_CALLBACK_0(SpriteMonster::doSetOpacity_ex,this)));
				runAction(Sequence::create( DelayTime::create(movetimes+0.2),dostand,NULL));
			}
		}
		return true;
	}
	return false;
}


bool SpritePlayer::collideInTheDir(float times,Point newpoint,Commen_Direction dir)
{
	if(getCurrActionState()<ACTION_STATE_DEAD)
	{
		if(changeState(ACTION_STATE_COLLIDE)||setSpriteDir(dir))
		{
			streakToTheDir(times,dir);
			playAction(0.4f,collide,dir,0.0f);
			setSpriteDir(dir);
			for (const auto c_sprite : m_sprites)
			{
				initOrderByDir(c_sprite,dir);
				c_sprite->playAction(0.4f,collide,dir,0.0f);

				if (c_sprite->getType() == WING_TYPE && !m_wing_node->isVisible())
					continue;

				c_sprite->streakToTheDir(times,dir);
			}
		}
		if(newpoint != Point(0,0))
		{
			
			if(getSeverPointsNum()>1)
			{
				//FiniteTimeAction* doset = CallFunc::create(CC_CALLBACK_0(SpriteMonster::doSetOpacity_ex,this));
				//runAction(Sequence::create( MoveTo::create(times,newpoint),doset,NULL));
				runAction(ObjectMoveAction::create(times,newpoint,CC_CALLBACK_0(SpriteMonster::doSetOpacity_ex,this)));
			}
			else
			{
				FiniteTimeAction* doset = CallFunc::create(CC_CALLBACK_0(SpriteMonster::doSetOpacity_ex,this));
				//FiniteTimeAction* dostand = CallFunc::create(CC_CALLBACK_0(SpriteMonster::doStanded,this));
				FiniteTimeAction* dostand = CallFunc::create([&](){ 
						if(hasServerPoints())
							return;
						if(getCurrActionState()== ACTION_STATE_COLLIDE||getCurrActionState()== ACTION_STATE_IDLE)
						{
							standed();
						}
				});
				runAction(Sequence::create( MoveTo::create(times,newpoint),doset,DelayTime::create( 0.3f),dostand,NULL));
			}
		}
		return true;
	}
	return false;
}


bool SpritePlayer::attackOnRide(float times, const cocos2d::Point& newpoint, Commen_Direction dir, int iTileNums)
{
	if(changeState(ACTION_STATE_COLLIDE))
	{
		setSpriteDir(dir);
		Commen_ActionToDo ac = attack_zs;
		int attack_cut = 14;
		
		// 法师
		if(getSchool() == 2)
		{
			ac = attack_fs;
			attack_cut = 8;
		}
		else if(getSchool() == 3)
		{
			ac = attack_ds;
			attack_cut = 12;
		}

		m_roledata.maxcut_ex = attack_cut;

		if(getSchool() == 2)
		{
			playAction(times*(attack_cut-2)/attack_cut, ac, dir, 1);

			// 第3帧开始叠影
			FiniteTimeAction* doStreak = CallFunc::create([&, times, attack_cut, dir, ac, iTileNums]()
			{
				StreakToTheDirRide(times*(attack_cut-2)/attack_cut,dir, ac, iTileNums);
			});
			runAction(Sequence::create(DelayTime::create(times*2/attack_cut), doStreak, NULL));
		}
		else if(getSchool() == 3)
		{
			playAction(times,ac,dir,1);
		}
		else
		{
			StreakToTheDirRide(times*9/attack_cut,dir, ac, iTileNums);
			playAction(times,ac,dir,1);

			// 翱风斩-第10帧需要去除叠影
			FiniteTimeAction* doRemoveStreak = CallFunc::create([&]()
			{
				removeStread();
			});
			runAction(Sequence::create(DelayTime::create(times*9/attack_cut), doRemoveStreak, NULL));
		}

		for (auto c_sprite : m_sprites)
		{
			initOrderByDir(c_sprite,dir);
			c_sprite->m_roledata.maxcut_ex = attack_cut;
			if(getSchool() == 2)
			{
				if (c_sprite->getType() == WING_TYPE && !m_wing_node->isVisible())
					continue;

				c_sprite->playAction(times*(attack_cut-2)/attack_cut, ac, dir, 1);

				// 纵雷决-第3帧开始叠影
				FiniteTimeAction* doStreak = CallFunc::create([=]()
				{
					if(c_sprite)
					{
						auto tmpSpr = dynamic_cast<SpriteBase*>(c_sprite);
						if(tmpSpr != nullptr)
							tmpSpr->StreakToTheDirRide(times*(attack_cut-2)/attack_cut, dir, ac, iTileNums);
					}
				});
				c_sprite->runAction(Sequence::create(DelayTime::create(times*2/attack_cut), doStreak, NULL));
			}
			else if(getSchool() == 3)
			{
				c_sprite->playAction(times,ac,dir,1);
			}
			else
			{
				c_sprite->playAction(times,ac,dir,1);

				if (c_sprite->getType() == WING_TYPE && !m_wing_node->isVisible())
					continue;
				c_sprite->StreakToTheDirRide(times*9/attack_cut,dir, ac, iTileNums);
			}
		}
		FiniteTimeAction* doset = CallFunc::create(CC_CALLBACK_0(SpriteMonster::doSetOpacity_ex,this));
		FiniteTimeAction* actbackfun = CallFunc::create([&](){standed();});

		// 3,4,5,6帧开始位移
		if(getSchool() == 2)	// mvoe 后的 delay 时间缩短，防止动作异常切换
			runAction(Sequence::create(DelayTime::create(times*2/attack_cut),MoveTo::create(times*4/attack_cut,newpoint),DelayTime::create(times*1/attack_cut),actbackfun ,doset,NULL));
		else
			runAction(Sequence::create(DelayTime::create(times*2/attack_cut),MoveTo::create(times*4/attack_cut,newpoint),DelayTime::create(times*8/attack_cut),actbackfun ,doset,NULL));
		return true;
	} 
	return false;
}


void SpritePlayer::removeStread()
{
	if(getCurrActionState() == ACTION_STATE_COLLIDE)
	{
		for(int j=1;j<5;j++)
		{
			this->removeChildByTag(1000+j);
		}
		for (auto c_sprite : m_sprites)
		{
			for(int j=1;j<5;j++)
			{
				c_sprite->removeChildByTag(1000+j);
			}
		}

	}
}

bool SpritePlayer::digToTheDir(float times,Commen_Direction dir)
{

	if(changeState(ACTION_STATE_DIG)||setSpriteDir(dir))
	{
		playAction(times,dig,dir,0);
		for (auto c_sprite : m_sprites)
		{
			initOrderByDir(c_sprite,dir);
			c_sprite->playAction(times,dig,dir,0);
		}
		return true; 
	}	
	return false;
}

bool SpritePlayer::excavateToTheDir(float times,Commen_Direction dir)
{

	if(changeState(ACTION_STATE_EXCAVATE)||setSpriteDir(dir))
	{
		//this->stopAllActions();
		playAction(times,excavate,dir,0);
		for (auto c_sprite : m_sprites)
		{
			initOrderByDir(c_sprite,dir);
			c_sprite->playAction(times,excavate,dir,0);
		}
		return true; 
	}	
	return false;
}



void SpritePlayer::hasHurted(float delay,float times)
{

}

bool SpritePlayer::AttackDSUpToPos(float times,Point newpoint)
{
	if(changeState(ACTION_STATE_MAGICUP))
	{
		if(newpoint != Point() && getPosition() != newpoint)
			setDirByNowPoint(newpoint);
		m_roledata.maxcut_ex = 12;
		playAction(times,attack_ds,m_roledata.dir,1);
		for (auto c_sprite : m_sprites)
		{
			initOrderByDir(c_sprite,m_roledata.dir);
			c_sprite->m_roledata.maxcut_ex = 12;
			c_sprite->playAction(times,attack_ds,m_roledata.dir,1);
		}
		FiniteTimeAction* actbackfun = CallFunc::create([&](){if(getCurrActionState()<= ACTION_STATE_CREATE) changeState(ACTION_STATE_IDLE);});
		Action *seq_act = Sequence::create(DelayTime::create(times),actbackfun,NULL);
		//seq_act->setTag(1);
		runAction(seq_act);
		return true;
	}
	else 
	{
		changeState(ACTION_STATE_IDLE);
	}
	return false;
}



//void SpritePlayer::initOrderByDir(SpriteBase* c_sprite,Commen_Direction dir)
//{
//	SpriteType s_type = c_sprite->getType();
//	if(s_type == WUQI_TYPE || s_type == HOE_TYPE)
//	{
//		if(dir == dir_left||dir == dir_left_up||dir == dir_left_down||dir == dir_up||(dir == dir_down&&getCurrActionState()==ACTION_STATE_IDLE))
//		{
//			c_sprite->setLocalZOrder(9);
//		}
//		else
//		{
//			c_sprite->setLocalZOrder(11);
//		}
//	}
//	else if(s_type == WING_TYPE )
//	{
//		if(dir == dir_left_down||dir == dir_right_down||dir == dir_down||(dir == dir_right&&(getCurrActionState()==ACTION_STATE_ATTACK||getCurrActionState()==ACTION_STATE_MAGICUP)))
//		{
//			c_sprite->setLocalZOrder(9);
//		}
//		else
//		{
//			c_sprite->setLocalZOrder(12);
//		}
//	}
//}