#include "SpriteBase.h"
#include "mapview/MapView.h"

USING_NS_CC;

//static	std::mutex _cacheMutex;
//static int __cache_count = 0;
SpriteBase::SpriteBase()
: main_node(nullptr)
, main_sprite(nullptr)
{
	stand_inited = false;
	walk_inited = false;
	run_inited = false;
	attack_inited = false;
	hurt_inited = false;
	magic_inited = false;
	has_load_res = false;
	m_5dir_mode = true;
	m_plist_num = 1;
	m_plist_loadnum = 0;
	m_roledata.dir=  dir_right_up;
	m_type = BASE_TYPE;
	isactor_flag = false;
	istree_flag = false;
	first_load_res = false;
	load_times = 0;
	m_res_id = 0;
	base_url.clear();
	m_need_recalc_plist_num = E_NRPN_NULL;
	m_death_cut = 4;
	m_is_change_display = false;
	change_base_url.clear();
	//m_win_size =  Director::getInstance()->getWinSize();
}

SpriteBase::~SpriteBase(void)
{
	base_url.clear();
	m_need_recalc_plist_num = E_NRPN_NULL;
	m_roledata.spiritUrl.clear();
	m_roledata.act_res.clear();
	change_base_url.clear();
	//CC_SAFE_RELEASE(m_roledata.spiritUrl);
	//SpriteFrameCache::getInstance()->removeSpriteFrameByName(m_plist_file->getCString());
}

void SpriteBase::subCacheCount()
{
	//if(__cache_count>0)
	//{
	//	__cache_count--;
	//	if(__cache_count == 0 )
	//	{
	//		SpriteFrameCache::getInstance()->removeReloadFileNames();
	//	}
	//}
}

void SpriteBase::setTreeFlag(bool istree)
{
	istree_flag = istree;
}

void SpriteBase::setFirstLoadRes(bool first)
{
	first_load_res = first;
}

bool SpriteBase::initWithFile(const std::string&pszFileName)
{
	main_node = Node::create();
	addChild(main_node,10,110);
	main_sprite = Sprite::create();
	setBaseUrl(pszFileName);
	if(main_sprite == NULL)
		return false;
	main_node->addChild(main_sprite,10,110);
	return true;
}


void SpriteBase::visit(Renderer *renderer, const Mat4& parentTransform, uint32_t parentFlags)
{
    // quick return if not visible. children won't be drawn.
	//Point n_pos = getParent()->convertToWorldSpace(getPosition());
	//if(!istree_flag && !Rect(0,0,m_win_size.width,m_win_size.height).containsPoint(n_pos))
	//{
	//	return;
	//}
   MapTileNode::visit(renderer, parentTransform, parentFlags);
}

void SpriteBase::setBaseUrl(const std::string& pszFileName)
{
	if (m_roledata.spiritUrl != pszFileName)
	{
		m_roledata.spiritUrl = pszFileName;
		base_url.clear();
		m_need_recalc_plist_num = E_NRPN_NULL;

		m_res_id = 0;

		auto i = m_roledata.spiritUrl.find("/");
		if (std::string::npos != i)
		{
			char sub_str[256] = { 0 };

			int nCopyLen = m_roledata.spiritUrl.size() - i - 1;
			if (nCopyLen > 0)
				memcpy(sub_str, m_roledata.spiritUrl.c_str() + i + 1, nCopyLen);
			sub_str[nCopyLen] = '\0';

			if (sub_str[0] >= '0' && sub_str[0] <= '9')
			{
				m_res_id = atoi(sub_str);
			}
			else
			{
				// 坐骑
				memcpy(sub_str, m_roledata.spiritUrl.c_str(), i);
				sub_str[i] = '\0';

				if (sub_str[0] >= '0' && sub_str[0] <= '9')
				{
					m_res_id = atoi(sub_str);
				}
			}
			
			//if(m_res_id > 5000000)
			//{
			//	m_res_id -= 230000;
			//	//int sex = (m_res_id/100000)%10;
			//	//int school = (m_res_id/10000)%10;
			//	//int res_id = m_res_id%10;
			//	//int temp_res_id = m_res_id - sex*100000 - school*10000;
			//	//m_res_id = temp_res_id + res_id*10 + school + sex;
			//}
		}
		else
		{
			auto j = m_roledata.spiritUrl.find("s");
			if (std::string::npos != j)
				m_res_id = atoi(m_roledata.spiritUrl.substr(j+1).c_str());
			else
				m_res_id = atoi(m_roledata.spiritUrl.c_str());
		}
	}
}

std::string SpriteBase::getBaseUrl()
{
	return m_roledata.spiritUrl;
}

SpriteBase *SpriteBase::create(const std::string&pszFileName)
{
    SpriteBase *pRet = new SpriteBase();
    if (pRet && pRet->initWithFile(pszFileName))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}


SpriteBase *SpriteBase::create(const std::string&pszFileName,Size touch_size)
{
    SpriteBase *pRet = new SpriteBase();
    if (pRet && pRet->initWithFile(pszFileName))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}



void SpriteBase::initStandStatus(int standcut,int maxcut2,float times,Commen_Direction dir)
{
	//m_roledata.spiritUrl_stand = CCString::create(pszFileName); 
	//m_roledata.spiritUrl_stand->retain();
	m_roledata.maxcut_stand = 4;
	m_stand_times = times;
	m_roledata.dir = dir;
	stand_inited = true;
	initWalkStatus(4, 0.6f);
	initRunStatus(12);
	initAttackStatus(6);
	initHurtStatus(4);
	initMagicStatus(8);
}

void SpriteBase::initWalkStatus(int maxcut, float actrate)
{
	//m_roledata.spiritUrl_walk = CCString::create(pszFileName); 
	//m_roledata.spiritUrl_walk->retain();
	if (maxcut > 0)
		m_roledata.maxcut_walk = maxcut;

	if (actrate > 0)
		m_roledata.walkactrate = actrate;

	walk_inited = true;

}

void SpriteBase::initRunStatus(int maxcut)
{
	//m_roledata.spiritUrl_run = CCString::create(pszFileName); 
	//m_roledata.spiritUrl_run->retain();
	m_roledata.maxcut_run = maxcut;
	run_inited = true;

}

void SpriteBase::initAttackStatus(int maxcut)
{
	//m_roledata.spiritUrl_attack = CCString::create(pszFileName); 
	m_roledata.maxcut_attack = maxcut;
//	m_roledata.spiritUrl_attack->retain();
	attack_inited = true;

}

void SpriteBase::initHurtStatus(int maxcut)
{
	//m_roledata.spiritUrl_hurt = CCString::create(pszFileName); 
	m_roledata.maxcut_hurt = maxcut;
	//m_roledata.spiritUrl_hurt->retain();
	hurt_inited = true;

}

void SpriteBase::initMagicStatus(int maxcut)
{
	//m_roledata.spiritUrl_magic = CCString::create(pszFileName); 
	m_roledata.maxcut_magic = maxcut;
//	m_roledata.spiritUrl_magic->retain();
	magic_inited = true;
}

void SpriteBase::playAction(float times,Commen_ActionToDo action,Commen_Direction dir,int loop,float ltimes)
{
	m_roledata.acttodo = action;
	m_roledata.actiontime = times;
	setSpriteDir(dir);
	if (main_sprite)
	{
		main_sprite->stopActionByTag(123);
		main_sprite->runAction(updateNowAnt(loop));
	}
}

void SpriteBase::removeStread()
{
}

bool SpriteBase::standed()
{
	if(stand_inited&&changeState(ACTION_STATE_IDLE))
	{
		playAction(m_stand_times,stand,m_roledata.dir,0);
	}
	//if(!has_load_res)
	//{
	//	if(load_times<30)
	//	{
	//		load_times++;
	//		FiniteTimeAction* actbackfun = CallFunc::create([&](){ this->standed();});
	//		runAction(Sequence::create(DelayTime::create(m_stand_times),actbackfun,NULL));
	//	}
	//}else
	//{
	//	load_times = 0;
	//}
	return has_load_res;
}

void SpriteBase::setLoadResTime(int times)
{
	load_times = times;
}


void SpriteBase::moveToPos(float times,Point newpoint,bool stand)
{
	if(getCurrActionState()<ACTION_STATE_DEAD)
	{
		if(changeState(ACTION_STATE_RUN)||setDirByNowPoint(newpoint))
		{
			setDirByNowPoint(newpoint);
			playAction(times,run,m_roledata.dir,0);
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

void SpriteBase::walkToPos(float times,Point newpoint,bool stand)
{
	if(getCurrActionState()<ACTION_STATE_DEAD)
	{
		if(changeState(ACTION_STATE_WALK)||setDirByNowPoint(newpoint))
		{
			setDirByNowPoint(newpoint);
			playAction(times,walk,m_roledata.dir,0);
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

bool SpriteBase::moveInTheDir(float times,Point newpoint,Commen_Direction dir,float movetimes)
{
	if(getCurrActionState()<ACTION_STATE_DEAD)
	{
		if(changeState(ACTION_STATE_RUN)||setSpriteDir(dir))
		{
			playAction(times,run,dir,0);
		}
		if(newpoint != Point(0,0))
			runAction( MoveTo::create(times,newpoint));
		return true;
	}
	return false;
}


bool SpriteBase::walkInTheDir(float times,Point newpoint,Commen_Direction dir)
{
	if(getCurrActionState()<ACTION_STATE_DEAD)
	{
		if(changeState(ACTION_STATE_WALK)||setSpriteDir(dir))
		{
			playAction(times,walk,dir,0);
		}
		if(newpoint != Point(0,0))
			runAction( MoveTo::create(times,newpoint));
		return true;
	}
	return false;
}

bool SpriteBase::collideInTheDir(float times,Point newpoint,Commen_Direction dir)
{
	return false;
}

 Point SpriteBase::getTileByDir(Commen_Direction dir) 
{
	switch (dir)
	{
	case dir_up:
		return  Point(0,-16);
	case dir_down:
		return  Point(0,16);
	case dir_left:
		return  Point(24,0);
	case dir_right:
		return  Point(-24,0);
	case dir_left_up:
		return  Point(24,-16);
	case dir_right_up:
		return  Point(-24,-16);
	case dir_left_down:
		return  Point(24,16);
	case dir_right_down:
		return  Point(-24,16);
	default:
		return  Point(0,-16);
	}

}

 bool SpriteBase::StreakToTheDirRide(float times,Commen_Direction dir, Commen_ActionToDo action, int iTileNum)
 {
	// 最多不超过4格， removeStread 1-4
	if(iTileNum > 7)
		iTileNum = 7;
	Point base = getTileByDir(dir);
	int i = 1;
	for(float j = 1.0f; j < iTileNum; j = j + 1.5f)
	{
		SpriteBase * cl_sp = SpriteBase::create(getBaseUrl());
		cl_sp->initStandStatus(0,0,m_stand_times,m_roledata.dir);
		cl_sp->setType(getType());
		cl_sp->setPosition(base*j);
		cl_sp->setOpacity(255*(1-0.1*i));
		addChild(cl_sp,0,1000+i);
		
		if (action == attack_zs)
			cl_sp->m_roledata.maxcut_ex = 14;
		else
			cl_sp->m_roledata.maxcut_ex = 8;
		
		cl_sp->playAction(times, action, dir, 1);

		cl_sp->runAction(Sequence::create(FadeTo::create(times/i, 4/i),NULL));
	}

	return false;
 }

bool SpriteBase::streakToTheDir(float times,Commen_Direction dir)
{
	char strurl[128] = {0};
	std::string ss = m_roledata.spiritUrl;	
	memset(strurl,0,128);
	sprintf(strurl,"/attack/%d0004.png",getDirIDByDir(NULL,dir));
	ss.append(strurl);
	//log(ss.c_str());
	SpriteFrame *frame =  SpriteFrameCache::getInstance()->getSpriteFrameByName(ss);
	if(frame)
	{
		Point base = getTileByDir(dir);
		for(int i = 1;i<5;i++)
		{
			Sprite *sub_sprite = Sprite::createWithSpriteFrame(frame);
			if(sub_sprite)
			{
				sub_sprite->setPosition(base*i);
				sub_sprite->setOpacity(255*(1-0.1*i));
				if(m_5dir_mode&&(dir == dir_left_down || dir == dir_left_up ||dir == dir_left))
					sub_sprite->setFlippedX(true);
				addChild(sub_sprite,0,1000+i);
				sub_sprite->runAction(Sequence::create(FadeTo::create(times,200/i),NULL));
			}
		}
	}
	return false;
}

bool SpriteBase::attackToPos(float times,Point newpoint)
{
	if(changeState(ACTION_STATE_ATTACK))
	{
		
		if(newpoint != Point())
			setDirByNowPoint(newpoint);
		playAction(times,attack,m_roledata.dir,1);

		FiniteTimeAction* actbackfun = CallFunc::create([&](){ if(getCurrActionState()<= ACTION_STATE_CREATE) changeState(ACTION_STATE_IDLE);});
		runAction(Sequence::create(DelayTime::create(times*1.5),actbackfun,NULL));
		return true;  
	}
	return false;
}


bool SpriteBase::attackOneTime(float times,Point newpoint)
{
	if(changeState(ACTION_STATE_ATTACK))
	{	
		if(newpoint != Point(0,0))
			setDirByNowPoint(newpoint);
		playAction(times,attack,m_roledata.dir,1);
		FiniteTimeAction* actbackfun = CallFunc::create([&](){if(getCurrActionState()<= ACTION_STATE_CREATE) changeState(ACTION_STATE_IDLE);});
		runAction(Sequence::create(DelayTime::create(times*1.5),actbackfun,NULL));
		return true;
	}
	return false;
}

bool SpriteBase::magicUpToPos(float times,Point newpoint)
{
	if(changeState(ACTION_STATE_MAGICUP))
	{
		
		if(newpoint != Point())
			setDirByNowPoint(newpoint);
		playAction(times,magicup,m_roledata.dir,1);

		FiniteTimeAction* actbackfun = CallFunc::create([&](){if(getCurrActionState()<= ACTION_STATE_CREATE) changeState(ACTION_STATE_IDLE);});
		runAction(Sequence::create(DelayTime::create(times*2),actbackfun,NULL));
		return true;
	}
	return false;
}

void SpriteBase::gotoDeath(Commen_Direction dir,float times)
{
	if(changeState(ACTION_STATE_DEAD))
	{
		setSpriteDir(dir);
		playAction(times,death,m_roledata.dir,1);
		//FiniteTimeAction* actbackfun = CallFunc::create([&](){ changeState(ACTION_STATE_REMOVE);});
		//runAction(Sequence::create(DelayTime::create(1.0),actbackfun,NULL));
	}
}

void SpriteBase::hasHurted(float delay,float times)
{
	if(changeState(ACTION_STATE_HURT))
	{
	}
}

void SpriteBase::setOpacity(GLubyte opact)
{
	if(main_sprite!=NULL)
		main_sprite->setOpacity(opact);
	Node::setOpacity(opact);
}


bool SpriteBase::isTouchInside(Touch* touch)
{
	Point local = main_sprite->convertTouchToNodeSpace(touch);
	Rect t_rect = main_sprite->getTextureRect();
	Size c_size =  main_sprite->getContentSize();
	int width = t_rect.size.width;
	int height =  t_rect.size.height;
	if(width>100) width = 100;
	if(width>200) width = 200;
	Rect r = Rect(c_size.width/2-width/2,c_size.height/2-t_rect.size.height/2,width,height);
	return r.containsPoint(local); 
}

/*************
* 根据点击坐标获得人物的朝向
*************/
bool SpriteBase::setDirByNowPoint(const cocos2d::Point& newpoint)
{
	// 已在当前位置，不需另设朝向
	if(getPosition() != newpoint)
	{
		Commen_Direction dir = MapView::GetDirByPos(getPosition(), newpoint);
		return setSpriteDir(dir);
	}

	return false;
}

bool SpriteBase::setSpriteDir(Commen_Direction dir)
{
	if(m_roledata.dir == dir)
		return false;

	m_roledata.dir = dir;
	return true;
}

bool SpriteBase::setSpriteOneDir(Commen_Direction dir)
{
	if(m_roledata.onedir == dir)
		return false;

	m_roledata.onedir = dir;
	return true;
}

void SpriteBase::setColor(const Color3B& color)
{
	if(main_sprite!=NULL)
		main_sprite->setColor(color);
}


void SpriteBase::setWrite(bool isgray)
{
	//if(main_sprite!=NULL)
	//	main_sprite->setColorWrite(isgray);
}

void SpriteBase::setBlue(bool isblue)
{

}

void SpriteBase::setGray(bool isgray)
{
	if(isgray)
	{
		main_sprite->setColor(ccColor3B(100,100,100));
	}
	else 
	{
		main_sprite->setColor(ccColor3B(255,255,255));
	}
}

Animate* SpriteBase::updateNowAnt(int RepeatNum)
{
	//NPC动画
	Animation* donghua = getNowActByDir();
	donghua->setRestoreOriginalFrame(true);
	if(RepeatNum>0)
	{
		donghua->setLoops(RepeatNum);
	}
	else
	{
		donghua->setLoops(-1);
	}
	Animate* playdonghua = Animate::create(donghua);
	playdonghua->setTag(123);
	return playdonghua;
}

void SpriteBase::stopInTheTime()
{
	if(changeState(ACTION_STATE_MABI))
	{
		//stopAllActions();
		getMainSprite()->stopAllActions();
	}
}

bool SpriteBase::isRideAttack()
{
	return (m_roledata.acttodo == attack_zs || m_roledata.acttodo == attack_fs || m_roledata.acttodo == attack_ds);
}

void SpriteBase::getPlistPath(char *strpath, int num, bool old)
{
	bool is_ride_attack = isRideAttack();
	if (old && num > 20)
		return;
	if(m_is_change_display)
	{
		sprintf(strpath, "res/monster/m_%s@%d",change_base_url.c_str(),num-1);
	}
	else if(base_url.empty())
	{
		char sub_str[256] = { 0 };
		auto i = m_roledata.spiritUrl.find("/");
		if (std::string::npos != i)
		{
			if (m_type == RIDE_TYPE_UP || m_type == RIDE_TYPE_DOWN)
			{
				memcpy(sub_str, m_roledata.spiritUrl.c_str(), i);
				sub_str[i] = '\0';
			}
			else
			{
				int nCopyLen = m_roledata.spiritUrl.size() - i - 1;
				if (nCopyLen > 0)
					memcpy(sub_str, m_roledata.spiritUrl.c_str() + i + 1, nCopyLen);
				sub_str[nCopyLen] = '\0';
			}
		}
		else
		{
			int nCopyLen = m_roledata.spiritUrl.size();
			if (nCopyLen > 0)
				memcpy(sub_str, m_roledata.spiritUrl.c_str(), nCopyLen);
			sub_str[nCopyLen] = '\0';
		}
		switch (m_type)
		{
		case PLAYER_MANE_TYPE:
		case PLAYER_FEMALE_TYPE:
			sprintf(strpath, "res/roleplist/r_%s", sub_str);
			break;
		case WUQI_TYPE:
		case HOE_TYPE:
			sprintf(strpath, "res/wuqiplist/w_%s", sub_str);
			break;
		case PIFENG_TYPE:
			sprintf(strpath, "res/headplist/p_%s", sub_str);
			break;
		case HEAD_TYPE:
			sprintf(strpath, "res/headplist/h_%s", sub_str);
			break;
		case WING_TYPE_left:
		case WING_TYPE:
			sprintf(strpath, "res/wingplist/wing_%s", sub_str);
			break;
		case RIDE_TYPE_UP:
		case RIDE_TYPE_DOWN:
			sprintf(strpath, "res/rideplist/ride_%s", sub_str);
			break;
		case SHOW_TYPE:
			sprintf(strpath, "res/showplist/s_%s", sub_str);
			break;
		case NORMAL_MONSTER:
		case ELIT_MONSTER:
		case BOSS_MONSTER:
			sprintf(strpath, "res/monster/m_%s", m_roledata.spiritUrl.c_str());
			break;
		case NPC_TYPE:
			//sprintf(strpath, "res/npcplist/n_%s", sub_str);
			sprintf(strpath, "res/monster/m_%s", m_roledata.spiritUrl.c_str());
			break;
		default:
			sprintf(strpath, "res/baseplist/b_%s", m_roledata.spiritUrl.c_str());
			break;
		}
		base_url = strpath;
		if(is_ride_attack)
			sprintf(strpath, "%s_q@%d", strpath, num - 1);
		else
			sprintf(strpath, "%s@%d", strpath, num - 1);
	}
	else
	{
		if(is_ride_attack)
			sprintf(strpath, "%s_q@%d", base_url.c_str(), num - 1);
		else
			sprintf(strpath, "%s@%d", base_url.c_str(), num - 1);
	}

	//if (old)
	//{
	//	if (num > 1)
	//	{
	//		sprintf(strpath, "%s%c", strpath, 'a' + num - 2);
	//	}
	//	else
	//	{
	//		sprintf(strpath, "%s", strpath);
	//	}
	//}
	//else
	//{
	//	sprintf(strpath, "%s@%d", strpath, num - 1);
	//}
	
}

/*********************
* 八方向人物动作合成器
*********************/
void SpriteBase::setNowActOld(Animation* act,const char *sprite_url,int count,int dir_id)
{	
	char strurl[128] = {0};
	//if(m_type == MONSTER_TYPE)
	{
		SpriteFrameCache* cache = SpriteFrameCache::getInstance();
		for(int i = 0; i < count ; i++)
		{
			std::string ss = m_roledata.spiritUrl;	
			memset(strurl,0,128);
			if(m_roledata.acttodo ==  collide)
				i = 4;
			sprintf(strurl,"%s%d%04d.png",sprite_url,dir_id,i);
			ss.append(strurl);
			//log(ss.c_str());
			SpriteFrame *frame = cache->getSpriteFrameByName(ss);
			if(frame)
			{
				has_load_res = true;
				act->addSpriteFrame(frame);
				if(m_type > BASE_TYPE) 
				{
					if(m_roledata.acttodo ==  death  && i==(count-1))
					{
						main_sprite->setSpriteFrame(frame);
					}
					else if(((m_type<NORMAL_MONSTER)||(m_type>PET_MONSTER))&&(m_roledata.acttodo ==  attack ||m_roledata.acttodo ==  magicup) && i==0)
					{
						main_sprite->setSpriteFrame(frame);
					}
				}
			}
			else if(i == 0)
			{
				has_load_res = false;
				memset(strurl,0,128);
				if(m_roledata.spiritUrl.length()>1 )//&&(first_load_res ||  __cache_count < 3 ||(m_type >= NORMAL_MONSTER && m_type<PLAYER_MANE_TYPE)) )
				{
					if(m_plist_num > 1)
					{
						for(int i=1;i<=m_plist_num;i++)
						{
							getPlistPath(strurl,i);
							sprintf(strurl,"%s.plist",strurl);
							//if(first_load_res)
								//cache->addSpriteFramesWithFileEx(strurl,this->getActorFlag());
							//else
							//if(__cache_count < 3 && cache->addSpriteFramesWithFileExEx(strurl))
							//{
							//	__cache_count++;
							//}
								
						/*
							if(m_type >= NORMAL_MONSTER && m_type<PLAYER_MANE_TYPE)
							{
								cache->addSpriteFramesWithFileExEx(strurl);
							}
							else
							{
								if(cache->addSpriteFramesWithFileEx(strurl))
								{
									__cache_count++;
								}
							}
							*/

						}
					}
					else
					{
						getPlistPath(strurl);
						sprintf(strurl,"%s.plist",strurl);
						//if(m_type > 1)
						//CCLOG("strurl: %s : type:%d, restype:%d",strurl,m_type,first_load_res?1:0);
		/*				if(first_load_res)
						{
							if(cache->addSpriteFramesWithFileEx(strurl,this->getActorFlag()))
								__cache_count++;
						}
						else if(m_type == NPC_TYPE)
						{
							if(__cache_count < 5 && cache->addSpriteFramesWithFileEx(strurl))
							{
								__cache_count++;
							}
						}
						else
						{
							if(__cache_count < 3 && cache->addSpriteFramesWithFileExEx(strurl))
							{
								__cache_count++;
							}
						}*/
						/*
						if(m_type >= NORMAL_MONSTER && m_type<PLAYER_MANE_TYPE)
						{
							cache->addSpriteFramesWithFileExEx(strurl);
						}
						else
						{
							if(cache->addSpriteFramesWithFileEx(strurl,this->getActorFlag()))
							{
								__cache_count++;
							}
						}
						*/
					}
				}
			}
		}
		return;
	}
	//for(int i = 1; i <= count ; i++)
	//{
	//	std::string ss = m_roledata.spiritUrl;	
	//	sprintf(strurl,"%s%d%04d.png",sprite_url,dir_id,i*5);
	//	ss.append(strurl);
	//	act->addSpriteFrameWithFile(ss);
	//}
}

// >>>SDG
void SpriteBase::setNowAct(Animation* act,const char *sprite_url,int count,int dir_id)
{
	has_load_res = true;
	//if(!isVisible()) return;
	bool bOutError = false;
	bool bLoadPlist = false;
	char ss[256] = { 0 };
	SpriteFrameCache* cache = SpriteFrameCache::getInstance();
	for(int i = 0; i < count ; i++)
	{
		if(m_roledata.acttodo == collide)
			i = 4;
		if(m_is_change_display)
			sprintf(ss, "%s%s%d%04d.png", change_base_url.c_str(), sprite_url, dir_id, i);
		else
			sprintf(ss, "%s%s%d%04d.png", m_roledata.spiritUrl.c_str(), sprite_url, dir_id, i);

		_strss = ss;

		if ((!bLoadPlist) && cache->getSpriteFrameByName(_strss) == nullptr)
		{
			bLoadPlist = true;
			m_need_recalc_plist_num = E_NRPN_NULL;
			loadplist(false);
		}

		SpriteFrame *frame = cache->getSpriteFrameByName(_strss);
		if(frame)
		{
			if (frame->getTextureReal() == nullptr)
				has_load_res = false;

			act->addSpriteFrame(frame);
			if(m_type > BASE_TYPE) 
			{
				if(m_roledata.acttodo ==  death  && i==(count-1))
				{
					main_sprite->setSpriteFrame(frame);
				}
				else if((m_roledata.acttodo ==  attack ||m_roledata.acttodo ==  magicup || m_roledata.acttodo == attack_ds) && i==0)
				{
					if ((m_type < NORMAL_MONSTER)||(m_type > PET_MONSTER))
					{
						main_sprite->setSpriteFrame(frame);
					}
				}
			}
		}
		else
		{
			if (!bOutError)
			{
				bOutError = true;
				CCLOGWIN32("[SpriteBase::setNowAct] error: %s", ss);
			}
		}
		
	}
	if(m_roledata.acttodo == stand&&(m_type >= PLAYER_MANE_TYPE ||(m_type > NPC_TYPE && m_type <NORMAL_MONSTER)))
	{
		for(int i = count-2; i > 0 ; i--)
		{
			if(m_is_change_display)
				break;
			sprintf(ss, "%s%s%d%04d.png", m_roledata.spiritUrl.c_str(), sprite_url, dir_id, i);
			_strss = ss;
			SpriteFrame *frame = cache->getSpriteFrameByName(_strss);
			if(frame)
			{
				act->addSpriteFrame(frame);
			}		
		}
	}
}

void SpriteBase::loadplistold()
{
	if (m_roledata.spiritUrl.length()>1)
	{
		SpriteFrameCache* cache = SpriteFrameCache::getInstance();

		char strurl[256] = { 0 };
		if (m_plist_num > 1)
		{
			for (int i = 1; i <= m_plist_num; i++)
			{
				getPlistPath(strurl, i);
				sprintf(strurl, "%s.plist", strurl);
				cache->addSpriteFramesWithFileAsync(strurl);
			}
		}
		else
		{
			getPlistPath(strurl);
			sprintf(strurl, "%s.plist", strurl);
			cache->addSpriteFramesWithFileAsync(strurl);

			//if(m_type > 1)
			//CCLOG("strurl: %s : type:%d, restype:%d",strurl,m_type,first_load_res?1:0);
			/*			if(first_load_res)
			{
			if(cache->addSpriteFramesWithFileAsync(strurl))
			__cache_count++;
			}
			else if(m_type == NPC_TYPE)
			{
			if (cache->addSpriteFramesWithFileAsync(strurl) )
			{
			__cache_count++;
			}
			}
			else
			{
			if(cache->addSpriteFramesWithFileAsync(strurl))
			{
			__cache_count++;
			}
			}*/

		}
	}
}

void SpriteBase::loadplist(bool old)
{
	if (m_roledata.spiritUrl.length() > 1)
	{
		SpriteFrameCache* cache = SpriteFrameCache::getInstance();

		char strurl[256] = { 0 };

		if (m_need_recalc_plist_num == E_NRPN_NULL)
			m_plist_num = 0;

		static const int s_max_plist_num = 16; // 最多16
		int plist_num = (m_need_recalc_plist_num == E_NRPN_NULL) ? s_max_plist_num : m_plist_num;

		FileUtils* utils = FileUtils::getInstance();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
		bool bCurFilePopupNotify = utils->isPopupNotify();
#endif

		bool plistExist;
		for (int i = 1; i <= plist_num; i++)
		{
			getPlistPath(strurl, i, old);
			sprintf(strurl, "%s.plist", strurl);
			if (m_need_recalc_plist_num == E_NRPN_NULL)
			{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
				if (i == 1)
				{
					plistExist = utils->isFileExist(strurl);
				}
				else
				{
					utils->setPopupNotify(false);
					plistExist = utils->isFileExist(strurl);
					utils->setPopupNotify(bCurFilePopupNotify);
				}
#else
				plistExist = utils->isFileExist(strurl);
#endif

				if (plistExist)
				{
					++m_plist_num;
				}
				else
				{
					break;
				}
			}

			cache->addSpriteFramesWithFileAsync(strurl);
		}

		if (m_need_recalc_plist_num == E_NRPN_NULL)
		{
			if (m_plist_num > 0)
			{
				if (old)
					m_need_recalc_plist_num = E_NRPN_OLD;
				else
					m_need_recalc_plist_num = E_NRPN_NEW;
			}
			else
			{
				m_need_recalc_plist_num = E_NRPN_LOADERROR;
			}
		}
		
	}
}

bool SpriteBase::getActorFlag()
{
	return isactor_flag;
}
void SpriteBase::setActorFlag(bool actorflag)
{
	isactor_flag = actorflag;
}
void SpriteBase::addTextureSprite(Texture2D *a)
{
	if(m_plist_num<0 || m_plist_num > 6 || m_plist_loadnum <0 || m_plist_loadnum > 6 || m_roledata.spiritUrl.length()<2)
	{
		return;
	}
	SpriteFrameCache* cache = SpriteFrameCache::getInstance();  
	char strurl[128] = {0};
	memset(strurl,0,128);
	if(m_plist_num <= 1)
	{
		getPlistPath(strurl);
		if(ccstrlen(strurl)>1)
		{
			sprintf(strurl,"%s.plist",strurl);
			cache->addSpriteFramesWithFile(strurl);
			playAction(m_stand_times,m_roledata.acttodo,m_roledata.dir,0);
		}
	}
	else
	{
		m_plist_loadnum++;
		if(m_plist_loadnum>=m_plist_num)
		{
			for(int i=1;i<=m_plist_num;i++)
			{
				memset(strurl,0,128);
				getPlistPath(strurl,i);
				if(ccstrlen(strurl)<=1)
				{
					return;
				}
				sprintf(strurl,"%s.plist",strurl);
				cache->addSpriteFramesWithFile(strurl);
			}
			playAction(m_stand_times,m_roledata.acttodo,m_roledata.dir,0);
			m_plist_loadnum = 0;
		}
		
	}
}

void SpriteBase::addSpriteFramesWithFile()
{	
	char strurl[128] = {0};
	m_plist_loadnum = 0;
	if(m_plist_num > 1)
	{
		for(int i=1;i<=m_plist_num;i++)
		{
			memset(strurl,0,128);
			getPlistPath(strurl,i);
			sprintf(strurl,"%s.pvr.ccz",strurl);
			std::function<void(Texture2D *)> addTexture = CC_CALLBACK_1(SpriteBase::addTextureSprite,this);
			Director::getInstance()->getTextureCache()->addImageAsync(strurl,addTexture);
		}
	}
	else
	{
		memset(strurl,0,128);
		getPlistPath(strurl);
		sprintf(strurl,"%s.pvr.ccz",strurl);
		std::function<void(Texture2D *)> addTexture = CC_CALLBACK_1(SpriteBase::addTextureSprite,this);
		Director::getInstance()->getTextureCache()->addImageAsync(strurl,addTexture);
	}
}

bool SpriteBase::getResLoadStatus()
{
	return has_load_res;
}

int SpriteBase::getDirIDByDir(Sprite* sp,Commen_Direction dir)
{
	int dir_id = 0;
	switch (dir)
	{
	case dir_up:
		dir_id = 0;
		break;
	case dir_down:
		dir_id = 4;
		break;
	case dir_left:
		if(m_5dir_mode)
		{
			if(sp)
			{
				sp->setFlippedX(true);
			}
		}
		else
		{
			dir_id = 6;
			break;
			//main_sprite->setFlippedX(true);
		}
	case dir_right:
		dir_id = 2;
		break;
	case dir_left_up:
		if(m_5dir_mode)
		{
			if(sp)
			{
				sp->setFlippedX(true);
			}
		}
		else
		{
			dir_id = 7;
			break;
			//main_sprite->setFlippedX(true);
		}
	case dir_right_up:
		dir_id = 1;
		break;
	case dir_left_down:
		if(m_5dir_mode)
		{
			if(sp)
			{
				sp->setFlippedX(true);
			}
		}
		else
		{
			dir_id = 5;
			break;
			//main_sprite->setFlippedX(true);
		}
	case dir_right_down:
		dir_id = 3;
		break;
	default:
		break;
	}
	if(m_roledata.acttodo==death && (m_type < PLAYER_MANE_TYPE && m_type >= NORMAL_MONSTER ))
	{
		if(dir == dir_left_down)
		{
			dir_id = 3;
			if(sp)
			{
				sp->setFlippedX(true);
			}
		}
	}
	return dir_id;
}

Animation* SpriteBase::getNowActByDir()
{
	Animation* act = Animation::create();
	main_sprite->setFlippedX(false);

	int dir_id = dir_undef;
	if (m_roledata.onedir != dir_undef)
		dir_id = getDirIDByDir(main_sprite,m_roledata.onedir);
	else
		dir_id = getDirIDByDir(main_sprite,m_roledata.dir);

	act->setDelayPerUnit(0.2f);
	switch (m_roledata.acttodo)
	{
	case walk:
		if(walk_inited)
		{
			setNowAct(act,"/walk/",m_roledata.maxcut_walk,dir_id);
		}
		act->setDelayPerUnit(m_roledata.actiontime / m_roledata.maxcut_walk);
		//act->setDelayPerUnit(0.08+0.2*m_roledata.actiontime);
		break;
	case run:
		if(run_inited)
		{
			if(m_is_change_display)
			{
				setNowAct(act,"/walk/",m_roledata.maxcut_walk,dir_id);
				act->setDelayPerUnit(m_roledata.actiontime / m_roledata.maxcut_walk);
			}
			else
			{
				setNowAct(act,"/run/",m_roledata.maxcut_run,dir_id);
				act->setDelayPerUnit(m_roledata.actiontime / m_roledata.maxcut_run);
			}
			//act->setDelayPerUnit(m_roledata.actiontime/m_roledata.maxcut_run);
		}
		break;
	case stand:
		if(stand_inited)
		{
			setNowAct(act,"/stand/",m_roledata.maxcut_stand,dir_id);
			//act->setDelayPerUnit(m_roledata.actiontime/m_roledata.maxcut_stand);
			act->setDelayPerUnit(0.4f);
		}
		break;
	case standby:
		if(stand_inited)
		{
			setNowAct(act,"/standby/",m_roledata.maxcut_stand,dir_id);
			//act->setDelayPerUnit(m_roledata.actiontime/m_roledata.maxcut_stand);
		}
		break;
	case attack:
		if(attack_inited)
		{
			setNowAct(act,"/attack/",m_roledata.maxcut_attack,dir_id);
			act->setDelayPerUnit(m_roledata.actiontime/3);
		}
		break;
	case hurt:
		if(hurt_inited)
		{
			setNowAct(act,"/injured/",m_roledata.maxcut_hurt,dir_id);
			//act->setDelayPerUnit(m_roledata.actiontime/m_roledata.maxcut_hurt);
		}
		break;
	case death:
		if(PLAYER_FEMALE_TYPE == m_type)
			setNowAct(act,"/death-1/",m_death_cut,4);
		else
			setNowAct(act,"/death-1/",m_death_cut,3);
		act->setDelayPerUnit(m_roledata.actiontime/m_death_cut);
		break;
	case magicup:
		if(magic_inited)
		{
			setNowAct(act,"/casting/",m_roledata.maxcut_magic,dir_id);
			act->setDelayPerUnit(m_roledata.actiontime/4);
		}
		break;
	case collide:
		if(magic_inited)
		{
			setNowAct(act,"/attack/",1,dir_id);
			//act->setDelayPerUnit(m_roledata.actiontime/m_roledata.maxcut_magic);
		}
		break;
	case dig:
		if(m_type != WUQI_TYPE)
			setNowAct(act,"/dig/",3,dir_id);
		//act->setDelayPerUnit(m_roledata.actiontime/1);
		break;
	case excavate:
		setNowAct(act,"/attack/",m_roledata.maxcut_attack,dir_id);
		act->setDelayPerUnit(m_roledata.actiontime/3); 
		break;
	case attack1:
		setNowAct(act,"/attack01/",m_roledata.maxcut_ex,dir_id);
		act->setDelayPerUnit(m_roledata.actiontime/m_roledata.maxcut_ex);
		break;
	case attack2:
		setNowAct(act,"/attack02/",m_roledata.maxcut_ex,dir_id);
		act->setDelayPerUnit(m_roledata.actiontime/m_roledata.maxcut_ex);
		break;
	case magicup1:
		setNowAct(act,"/casting01/",m_roledata.maxcut_ex,dir_id);
		act->setDelayPerUnit(m_roledata.actiontime/m_roledata.maxcut_ex);
		break;
	case magicup2:
		setNowAct(act,"/casting02/",m_roledata.maxcut_ex,dir_id);
		act->setDelayPerUnit(m_roledata.actiontime/m_roledata.maxcut_ex);
		break;
	case attack_zs:
		setNowAct(act,"/attack-zs/",m_roledata.maxcut_ex,dir_id);
		act->setDelayPerUnit(m_roledata.actiontime/m_roledata.maxcut_ex);
		break;
	case attack_fs:
		setNowAct(act,"/attack-fs/",m_roledata.maxcut_ex,dir_id);
		act->setDelayPerUnit(m_roledata.actiontime/m_roledata.maxcut_ex);
		break;
	case attack_ds:
		setNowAct(act,"/attack-ds/",m_roledata.maxcut_ex,dir_id);
		act->setDelayPerUnit(m_roledata.actiontime/m_roledata.maxcut_ex);
		break;
	case appear:
		setNowAct(act,"/appear/",m_roledata.maxcut_ex,dir_id);
		act->setDelayPerUnit(m_roledata.actiontime/m_roledata.maxcut_ex);
		break;
	case disappear:
		setNowAct(act,"/disappear/",m_roledata.maxcut_ex,dir_id);
		act->setDelayPerUnit(m_roledata.actiontime/m_roledata.maxcut_ex);
		break;
	case change_dis:
		setNowAct(act,"/change/",m_roledata.maxcut_ex,dir_id);
		act->setDelayPerUnit(m_roledata.actiontime/m_roledata.maxcut_ex);
		break;
	case specail:
		setNowAct(act,m_roledata.act_res.c_str(),m_roledata.maxcut_ex,dir_id);
		act->setDelayPerUnit(m_roledata.actiontime/m_roledata.maxcut_ex);
		break;
	default:
		break;
	}
	
	return act;
}

bool SpriteBase::changeState(ActionState actionState)
{
	if( m_currActionState == actionState && actionState!=ACTION_STATE_IDLE)
	{
		if(m_currActionState == ACTION_STATE_WALK||m_currActionState ==ACTION_STATE_RUN)
			return false;
	}
	if(m_currActionState == ACTION_STATE_COLLIDE && m_currActionState != actionState )
	{
		removeStread();
	}
	//if(getActionByTag(1))
	//	stopActionByTag(1);
	//if( actionState==ACTION_STATE_IDLE && has_load_res)
	//{
	//	//if(!((m_currActionState == ACTION_STATE_WALK||m_currActionState ==ACTION_STATE_RUN)&&(actionState==ACTION_STATE_ATTACK||actionState==ACTION_STATE_MAGICUP)))
	//		this->stopAllActions();
	//}
	m_currActionState = actionState;

	return true;
}