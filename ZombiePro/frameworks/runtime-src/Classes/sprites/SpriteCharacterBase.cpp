#include "SpriteCharacterBase.h"
#include "ObjectMoveAction.h"
#include "mapview/MapViewBase.h"


UISpriteCharacter *UISpriteCharacter::create(const std::string& pszFileName)
{
    UISpriteCharacter *pRet = new UISpriteCharacter();
    if (pRet && pRet->initWithFile(pszFileName))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return nullptr;
    }
}

UISpriteCharacter::UISpriteCharacter()
{
}

UISpriteCharacter::~UISpriteCharacter()
{
}

void UISpriteCharacter::insertActionChild(SpriteBase* sprite)
{
	addChild(sprite);
	m_sprites.pushBack(sprite);
}

void UISpriteCharacter::insertBloodNode(int height)
{
	m_blood_bg = Sprite::create("res/mblood.png",Rect(0,9,47,9));
	m_blood_bg->retain();
	addChild(m_blood_bg);
	m_blood_pro = Sprite::create("res/mblood.png", Rect(0, 0, 47, 9));
	if (m_blood_pro->getTexture())
		m_blood_pro->getTexture()->setAliasTexParameters();
	m_blood_pro->setPosition(0, -1);
	m_blood_pro->setAnchorPoint(Point(0.0, 0.0));
	m_blood_bg->addChild(m_blood_pro);
	m_blood_bg->setLocalZOrder(122);
	show_offx = 0;
	show_h = height;
	m_blood_bg->setPosition(getPosition() + Point(show_offx, show_h + 5));
}

void UISpriteCharacter::setHP(int hp)
{
	m_hp = hp;

	float pro = 1.0f;

	if (m_hp <= 0)
	{
		m_hp = 0;
		pro = 0.0f;
	}
	else if (m_hp < m_maxhp && m_hp > 0)
	{
		pro = 1.0f;
		if (m_maxhp > 0)
			pro = (float)hp / (float)m_maxhp;
		if (pro > 1.0f)
			pro = 1.0f;
	}
	else
	{
		pro = 1.0f;
	}

	if (m_blood_pro != NULL)
	{
		float fBloodWidth = pro * 47;
		if (m_hp > 0 && fBloodWidth < 2.0f) // HP>0 至少显示一点红色进度
			fBloodWidth = 2.0f;
		m_blood_pro->setTextureRect(Rect(0, 0, fBloodWidth, 9));
	}
}

bool UISpriteCharacter::setSpriteDir(Commen_Direction dir)
{
	SpriteCharacterBase::setSpriteDir(dir);
	for (auto c_sprite : m_sprites)
	{
		c_sprite->setSpriteDir(dir);
	}

	return true;
}

void UISpriteCharacter::playAction(float times,Commen_ActionToDo action,Commen_Direction dir,int loop,float ltimes)
{
	SpriteCharacterBase::playAction(times, action, dir, loop, ltimes);

	for (auto c_sprite : m_sprites)
	{
		c_sprite->playAction(times, action, dir, loop, ltimes);
	}
	
}

bool UISpriteCharacter::standed()
{
	if(stand_inited&&changeState(ACTION_STATE_IDLE)
		//&&(last_action!=stand||last_action_dir!=m_roledata.dir)
		)
	{
		playAction(m_stand_times,stand,m_roledata.dir,0);
		for (auto c_sprite : m_sprites)
		{
			//initOrderByDir(c_sprite,m_roledata.dir);
			c_sprite->playAction(m_stand_times,stand,m_roledata.dir,0);
		}
	}
	return true;	//资源加载成功返回true
}

bool UISpriteCharacter::MagicOneTime_ex(float times, const Point& newpoint)
{
	if(changeState(ACTION_STATE_MAGICUP))
	{
		// 原地转方向不需要通过这个函数
		if(newpoint != Point() && getPosition() != newpoint)
			setDirByNowPoint(newpoint);
		playAction(times,magicup,m_roledata.dir,1);
		for (auto c_sprite : m_sprites)
		{
			//initOrderByDir(c_sprite,m_roledata.dir);
			c_sprite->playAction(times,magicup,m_roledata.dir,1);
		}
		if(getActorFlag())
		{
			FiniteTimeAction* doset = CallFunc::create(CC_CALLBACK_0(UISpriteCharacter::doSetOpacity_ex,this));
			FiniteTimeAction* actbackfun = CallFunc::create([&](){if(getCurrActionState()<= ACTION_STATE_CREATE) changeState(ACTION_STATE_IDLE);});
			runAction(Sequence::create(DelayTime::create(times+0.5),doset,actbackfun,NULL));
		}
		else
		{
			FiniteTimeAction* doset = CallFunc::create(CC_CALLBACK_0(UISpriteCharacter::doSetOpacity_ex,this));
			FiniteTimeAction* dostand = CallFunc::create(CC_CALLBACK_0(UISpriteCharacter::doStanded,this));
			runAction(Sequence::create(DelayTime::create(times),doset, DelayTime::create(times+0.4),dostand,NULL));
		}
		return true;
	}
	else 
	{
		changeState(ACTION_STATE_IDLE);
	}
	return false;
}

void UISpriteCharacter::doSetOpacity()
{
	Point pp = dynamic_cast<UIMapView*>(this->getParent()->getParent())->space2Tile(getPosition());
	setLocalZOrder((int)pp.y);
	setOpacity(255);
}

void UISpriteCharacter::doSetOpacity_ex()
{
	//只执行一个动作，不需要后续动作，不需要执行内容, 平地也不需要设置透明度
}

void UISpriteCharacter::doStanded()
{
	if(getCurrActionState() < ACTION_STATE_CREATE)
		standed();
}

bool UISpriteCharacter::moveInTheDir_ex(float times, Point newpoint,Commen_Direction dir,float movetimes)
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
				//initOrderByDir(c_sprite,dir);
				c_sprite->playAction(actLoopTime, run, dir, 0);
			}
		}
		if(newpoint != Point(0,0))
		{
			if(movetimes == 0) movetimes = times;
			//CCLOG("[UISpriteCharacter::moveInTheDir_ex - 2] %u, %f, %f", Director::getInstance()->getTotalFrames(), getPositionX(), getPositionY());

			//FiniteTimeAction* doset = CallFunc::create(CC_CALLBACK_0(UISpriteCharacter::doSetOpacity_ex,this));
			FiniteTimeAction* dostand = CallFunc::create(CC_CALLBACK_0(UISpriteCharacter::doStanded,this));
			runAction(ObjectMoveAction::create(movetimes,newpoint,CC_CALLBACK_0(UISpriteCharacter::doSetOpacity_ex,this)));
			runAction(Sequence::create( DelayTime::create(movetimes+0.2),dostand,NULL));
		}
		return true;
	}
	return false;
}

bool UISpriteCharacter::walkInTheDir_ex(float times,Point newpoint,Commen_Direction dir)
{
	//removeStread();
	//if(getCurrActionState()<ACTION_STATE_DEAD&&(getCurrActionState() < ACTION_STATE_ATTACK||getCurrActionState()>ACTION_STATE_COLLIDE))
	if(getCurrActionState() < ACTION_STATE_CREATE)
	{
		if(changeState(ACTION_STATE_WALK)||setSpriteDir(dir))
		{
			//float actLoopTime = (0.125+times/2)*4/m_roledata.maxcut_walk;
			float actLoopTime = m_roledata.walkactrate;
			playAction(actLoopTime,walk,dir,0);
			for (auto c_sprite : m_sprites)
			{
				//initOrderByDir(c_sprite,dir);
				c_sprite->playAction(actLoopTime,walk,dir,0);
			}
		}
		if(newpoint != Point(0,0))
		{
			//FiniteTimeAction* doset = CallFunc::create(CC_CALLBACK_0(UISpriteCharacter::doSetOpacity_ex,this));
			FiniteTimeAction* dostand = CallFunc::create(CC_CALLBACK_0(UISpriteCharacter::doStanded,this));
			//runAction(Sequence::create( MoveTo::create(times,newpoint),doset,DelayTime::create(0.2),dostand,NULL));

			runAction(ObjectMoveAction::create(times,newpoint,CC_CALLBACK_0(UISpriteCharacter::doSetOpacity_ex,this)));
			runAction(Sequence::create( DelayTime::create(times+0.25),dostand,NULL));
		}
		return true;
	}
	return false;
}

bool UISpriteCharacter::collideInTheDir(float times,Point newpoint,Commen_Direction dir)
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
				//initOrderByDir(c_sprite,dir);
				c_sprite->playAction(0.4f,collide,dir,0.0f);

				//if (c_sprite->getType() == WING_TYPE && !m_wing_node->isVisible())
				//	continue;

				c_sprite->streakToTheDir(times,dir);
			}
		}
		if(newpoint != Point(0,0))
		{
			FiniteTimeAction* doset = CallFunc::create(CC_CALLBACK_0(UISpriteCharacter::doSetOpacity_ex,this));
			//FiniteTimeAction* dostand = CallFunc::create(CC_CALLBACK_0(UISpriteCharacter::doStanded,this));
			FiniteTimeAction* dostand = CallFunc::create([&](){ 
					if(getCurrActionState()== ACTION_STATE_COLLIDE||getCurrActionState()== ACTION_STATE_IDLE)
					{
						standed();
					}
			});
			runAction(Sequence::create( MoveTo::create(times,newpoint),doset,DelayTime::create( 0.3f),dostand,NULL));
		}
		return true;
	}
	return false;
}

void UISpriteCharacter::removeStread()
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

void UISpriteCharacter::setOpacity(GLubyte opact)
{
	if(main_sprite!=NULL)
		main_sprite->setOpacity(opact);
	for (auto c_sprite : m_sprites)
	{
		if(c_sprite->getTag() < 8000000)
			c_sprite->setOpacity(opact);
		else if(c_sprite->getOpacity() > 0);
			//c_sprite->setOpacity(opact * m_set_opacity_num / 255);
	}
	Node::setOpacity(opact);
}