#include "MapViewBase.h"
//#include "effects/MagicCtrlMgr.h"
#include "common/MakeNumbers.h"
//#include "pbc/pbc.h"
//#include "socket/vsdef.h"

USING_NS_CC;

Commen_Direction MapViewBase::getDirByTile(Point tile) 
{
	if(abs(tile.x)> 1) tile.x = tile.x/abs(tile.x);
	if(abs(tile.y)> 1) tile.y = tile.y/abs(tile.y);
	Point d_tile = Point((int)tile.x,(int)tile.y);
	if(tile == Point(0,-1))
		return dir_up;
	else if(tile ==Point(0,1))
		return dir_down;
	else if(tile ==Point(-1,0))
		return dir_left;
	else if(tile ==Point(1,0))
		return dir_right;
	else if(tile ==Point(1,-1))
		return dir_right_up;
	else if(tile == Point(1,1))
		return dir_right_down;
	else if(tile ==Point(-1,-1))
		return dir_left_up;
	else if(tile ==Point(-1,1))
		return dir_left_down;
	return dir_right_up;
}

Point MapViewBase::getTileByDir(Commen_Direction dir) 
{
	switch (dir)
	{
	case dir_up:
		return  Point(0,-1);
	case dir_down:
		return  Point(0,1);
	case dir_left:
		return  Point(-1,0);
	case dir_right:
		return  Point(1,0);
	case dir_left_up:
		return  Point(-1,-1);
	case dir_right_up:
		return  Point(1,-1);
	case dir_left_down:
		return  Point(-1,1);
	case dir_right_down:
		return  Point(1,1);
	default:
		return  Point(0,-1);
	}

}


//***************************
// UIMapView
//***************************
UIMapView *UIMapView::create()
{
	UIMapView *pRet = new UIMapView();
	if (pRet && pRet->init())
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

UIMapView::UIMapView()
: m_item_node(nullptr)
, m_skill_node(nullptr)
, m_hit_node(nullptr)
{
	m_perTileSize = Size(48,32);
	m_mapSize = Size(100,100);
}

UIMapView::~UIMapView()
{
}

bool UIMapView::init()
{
    Layer::init();

	m_perTileSize = Size(48,32);
	m_mapSize = Size(100,100);

	m_item_node = Node::create();
	addChild(m_item_node, 4, 316);

	m_skill_node = Node::create();
	m_skill_node->setPosition(0,0);
	addChild(m_skill_node,10);

    return true;
}


cocos2d::Node* UIMapView::GetItemRoot()
{
	return m_item_node;
}

cocos2d::Node* UIMapView::getSkillRootNode()
{
	return m_skill_node;
}

Point UIMapView::tile2Space(Point tile)
{
	int sx = (tile.x + 0.5) * m_perTileSize.width;
	int sy = (m_mapSize.height - (tile.y+0.5))* m_perTileSize.height;
	return Point(sx,sy);
}

Point UIMapView::space2Tile(Point pos)
{
	int ty = m_mapSize.height - ceil(pos.y/m_perTileSize.height);
	int tx = floor(pos.x/m_perTileSize.width);
	return Point(tx, ty); 
}

bool UIMapView::isBlock(cocos2d::Point tile)
{
	return false;
}

bool UIMapView::isOpacity(cocos2d::Point tile)
{
	return false;
}

/*void UIMapView::onCrash(int skill_id, int roleId_attacker, int roleId_target, int pos_x, int pos_y, int start_pos_x, int start_pos_y, int end_pos_x, int end_pos_y)
{
	// 狮子吼类需要指定最终被攻击者的方向
	UISpriteCharacter *attacker_node = dynamic_cast<UISpriteCharacter *>(m_item_node->getChildByTag(roleId_attacker));
	UISpriteCharacter *target_node = dynamic_cast<UISpriteCharacter *>(m_item_node->getChildByTag(roleId_target));
	//攻击者
	action_queue action_data_attacker;
	action_data_attacker.q_type = ACTION_CRASH_TYPE;
	if(skill_id == MAGICID_LION_CALL || skill_id == MAGICID_LION_CALL_ARENA)
		action_data_attacker.pos = Point(end_pos_x, end_pos_y);
	else
		action_data_attacker.pos = Point(pos_x, pos_y);
	action_data_attacker.skill_id = skill_id;
	action_data_attacker.tarId = roleId_target;
	onDelayCrash(attacker_node, action_data_attacker);
	//被攻击者
	action_queue action_data_target;
	action_data_target.q_type = ACTION_CRASHED_TYPE;
	action_data_target.pos = Point(end_pos_x,end_pos_y);
	action_data_target.skill_id = skill_id;
	action_data_target.start_pos = Point(start_pos_x,start_pos_y);
	onDelayCrashed(target_node, action_data_target);
}*/


char UIMapView::getSpeedUp(UISpriteCharacter *r_node)
{
	char speedup = 0;
	return speedup;
}

/*void UIMapView::onDelayCrash(UISpriteCharacter *r_node,action_queue crash_data)
{
	float speedup = getSpeedUp(r_node)/2;
	Point start_pos = space2Tile(r_node->getPosition());
	int dist = MAX(abs(start_pos.x-crash_data.pos.x),abs(start_pos.y-crash_data.pos.y));//start_pos.getDistance(crash_data.pos);
	Commen_Direction dir = r_node->getCurrectDir();
	if(start_pos!=crash_data.pos)
		dir = getDirByTile(crash_data.pos-start_pos);
	float crash_time = 0.15*dist/(1+speedup);
	if(dist == 0)
		crash_time = 0.3f;
	
	r_node->standed();

	if(crash_data.skill_id == MAGICID_DISPUTE_FIRE || crash_data.skill_id == MAGICID_DISPUTE_FIRE_ARENA)
	{
		float attack_time = 0.45f;
		attack_time = attack_time/(1+speedup);

		r_node->MagicOneTime_ex(attack_time, cocos2d::Vec2(0, 0));

		CMagicCtrlMgr::getInstance()->CreateMagic(MAGICID_DISPUTE_FIRE, 0, r_node->getTag(), 0, 0, this);
	}
	else if(crash_data.skill_id == MAGICID_LION_CALL || crash_data.skill_id == MAGICID_LION_CALL_ARENA)
	{
		float attack_time = 0.55f;
		attack_time = attack_time/(1+speedup);

		// 改变朝向，面向其中一个角色[允许重叠]		
		r_node->MagicOneTime_ex(attack_time, tile2Space(crash_data.pos));

		CMagicCtrlMgr::getInstance()->CreateMagic(MAGICID_LION_CALL, 0, r_node->getTag(), 0, (int)(r_node->getCurrectDir()), this);
	}
	else if(crash_data.skill_id == MAGICID_WILD_COLLIDE || crash_data.skill_id == MAGICID_WILD_COLLIDE_ARENA || crash_data.skill_id == MAGICID_SUDDEN_KILL || crash_data.skill_id == MAGICID_SUDDEN_KILL_ARENA)
	{
		//float attack_time = 0.45f;
		//attack_time = attack_time/(1+speedup);
		//r_node->attackOneTime(attack_time, cocos2d::Vec2(0, 0));

		if(crash_data.skill_id == MAGICID_SUDDEN_KILL)
		{
			// 突斩直接绑定到施放者身上
			CMagicCtrlMgr::getInstance()->CreateMagic(MAGICID_SUDDEN_KILL, 0, r_node->getTag(), 0, dir, this);
		}
		else if(crash_data.skill_id == MAGICID_SUDDEN_KILL_ARENA)
		{
			CMagicCtrlMgr::getInstance()->CreateMagic(MAGICID_SUDDEN_KILL_ARENA, 0, r_node->getTag(), 0, dir, this);
		}
		else if(crash_data.skill_id == MAGICID_WILD_COLLIDE)
		{
			CMagicCtrlMgr::getInstance()->CreateMagic(MAGICID_WILD_COLLIDE, 0, r_node->getTag(), 0, dir, this);
		}
		else if(crash_data.skill_id == MAGICID_WILD_COLLIDE_ARENA)
		{
			CMagicCtrlMgr::getInstance()->CreateMagic(MAGICID_WILD_COLLIDE_ARENA, 0, r_node->getTag(), 0, dir, this);
		}

		((UISpriteCharacter *)r_node)->collideInTheDir(crash_time,tile2Space(crash_data.pos),dir);
	}
}*/

/*void UIMapView::onDelayCrashed(UISpriteCharacter *r_node, action_queue crashed_data)
{
	float speedup = getSpeedUp(r_node)/2;
	Point start_pos = crashed_data.start_pos;
	r_node->setPosition(tile2Space(start_pos));
	int dist = MAX(abs(start_pos.x-crashed_data.pos.x),abs(start_pos.y-crashed_data.pos.y));
	Commen_Direction dir = r_node->getCurrectDir();
	if(start_pos != crashed_data.pos)
		dir = getDirByTile(start_pos-crashed_data.pos);
	float crash_time = 0.15*dist/(1+speedup);
	//r_node->stopAllActions();
	r_node->standed();
	if(r_node->getType() < PLAYER_MANE_TYPE)
	{
		r_node->walkInTheDir_ex(crash_time,tile2Space(crashed_data.pos),dir);
	}
	else
	{
		((UISpriteCharacter *)r_node)->moveInTheDir_ex(0.2,tile2Space(crashed_data.pos),dir,crash_time);
		
	}

	if(crashed_data.skill_id == MAGICID_LION_CALL || crashed_data.skill_id == MAGICID_LION_CALL_ARENA)
	{
		Commen_Direction effDir = GetDirByPos(r_node->getPosition(), tile2Space(crashed_data.pos));
		// 狮子吼如果推动，每个对象都有特效
		CMagicCtrlMgr::getInstance()->CreateMagic(MAGICID_LION_CALL_PUSH, 0, 0, r_node->getTag(), effDir, this);
	}
}*/

Commen_Direction UIMapView::GetDirByPos(const Point& src, const Point& dst)
{
	float x1 = dst.x - src.x;
	float y1 = dst.y - src.y;
	if (x1 == 0.0f)
	{
		if (y1 > 0.0f)
			return dir_up;
		else
			return dir_down;
	}

	if (y1 == 0.0f)
	{
		if (x1 > 0.0f)
			return dir_right;
		else
			return dir_left;
	}

	int j = abs((int)( y1/x1 * 1000 ));

	if (x1 > 0.0f)
	{
		if (y1 > 0.0f)
		{
			if (j < 414)
				return dir_right;
			else if (j < 2414)
				return dir_right_up;
			else
				return dir_up;
		}
		else
		{
			if (j < 414)
				return dir_right;
			else if (j < 2414)
				return dir_right_down;
			else
				return dir_down;
		}
	}
	else
	{
		if (y1 > 0.0f)
		{
			if (j < 414)
				return dir_left;
			else if (j < 2414)
				return dir_left_up;
			else
				return dir_up;
		}
		else
		{
			if (j < 414)
				return dir_left;
			else if (j < 2414)
				return dir_left_down;
			else
				return dir_down;
		}
	}

	return dir_right_down;

	//Commen_Direction dir = dir_right_down;	// 默认为右下
	//float dista = dst.getDistance(src);
	//Point direct = (dst - src).getNormalized();
	//if(dista < 5 || dista > 3000)
	//	return dir;
	//if((direct.x >= -0.000001) && (direct.x <= 0.000001) && (direct.y >= -0.000001) && (direct.y <= 0.000001))
	//	return dir;

	//if((direct.x >= -0.000001) && (direct.x <= 0.000001))
	//{
	//	if(direct.y > 0)
	//		dir = dir_up;
	//	else if(direct.y < 1)
	//		dir = dir_down;
	//}
	//else
	//{
	//	float angle = atan2(abs(direct.y), abs(direct.x));
	//	if(angle < PI/8)
	//	{
	//		if(direct.x < 0)
	//			dir = dir_left;
	//		else
	//			dir = dir_right;
	//	}
	//	else if(angle > PI*3/8)
	//	{
	//		if(direct.y > 0)
	//			dir = dir_up;
	//		else
	//			dir = dir_down;
	//	}
	//	else
	//	{
	//		if(direct.x < 0 && direct.y < 0)
	//			dir = dir_left_down;
	//		else if(direct.x < 0 && direct.y > 0)
	//			dir = dir_left_up;
	//		else if(direct.x > 0 && direct.y > 0)
	//			dir = dir_right_up;
	//		else
	//			dir = dir_right_down;
	//	}
	//}

	//return dir;
}

/*void UIMapView::onShowHurt(LuaMsgBuffer *pBuff)
{
	//预览借用pb解析作为传值工具
	struct pbc_slice slice;
	slice.buffer = (void*)pBuff->getMsgBody();
	slice.len = pBuff->getSendBufLen() - SIZEOF_APPMSG;
	struct pbc_rmessage * m = pbc_rmessage_new(g_registerEnv, "SkillHurtProtocol", &slice);
	if (m == NULL) {
		return;
	}
	int attackId =  pbc_rmessage_integer(m , "roleId" , 0 , NULL);
	char count = (char)pbc_rmessage_size(m, "hurts");
	UISpriteCharacter *attack_node = nullptr;
	for(int i = 0;i<count;i++)
	{
		struct pbc_rmessage * p = pbc_rmessage_message(m , "hurts", i);
		int objId = pbc_rmessage_integer(p , "id", i ,NULL);
		int hurt = pbc_rmessage_integer(p , "hurt", i ,NULL);
		int cur_blood = pbc_rmessage_integer(p , "now", i ,NULL);
		bool isHit =(bool)pbc_rmessage_integer(p , "crit", i ,NULL);
		int resistType = pbc_rmessage_integer(p , "hurtResistType", i ,NULL);
		unsigned char buff_count = (unsigned char)pbc_rmessage_size(p, "clearbuffs");
		UISpriteCharacter *r_node = r_node = (UISpriteCharacter *)(GetItemRoot()->getChildByTag(objId));
		Point role_pos = Point();
		if(r_node != nullptr)
			role_pos = r_node->getPosition();
		Point span_pos = Point(20-CCRANDOM_0_1()*40,80+CCRANDOM_0_1()*30);
		char f_type = 1;
		if(hurt < 0 )
			f_type = 2;
		else if(r_node != nullptr && r_node->getType() >= PLAYER_MANE_TYPE)
			f_type = 3;
		else
		{
			if(attack_node == nullptr)
			{
				attack_node  = (UISpriteCharacter *)(GetItemRoot()->getChildByTag(attackId));
			}
			if(attack_node != nullptr)
			{
				Point att_pos = attack_node->getPosition();
				float distance = role_pos.getDistance(att_pos);
				if(distance < 64 || count > 1)
				{
					span_pos = role_pos - att_pos;
					if(span_pos.x > 0)
						span_pos.x = 60+CCRANDOM_0_1()*40 ;
					else
						span_pos.x = -1*(60+CCRANDOM_0_1()*40) ;
					if(span_pos.y > 0)
						span_pos.y = 40+CCRANDOM_0_1()*40 ;
					else
						span_pos.y = -1*(40+CCRANDOM_0_1()*40) ;
				}
			}
		}
		if(attackId == 0 && hurt == 0)
		{
			pbc_rmessage_delete(m);
			return;
		}
		if(r_node != nullptr)
			onShowHurtNumber(hurt, role_pos, f_type, isHit, span_pos, resistType);
		/*
		if(resistType > 0 || cur_blood == 0 || buff_count > 0)
		{
			//根据clearbuffs数组清除buff,触发盾破特效,预览不使用原有机制
			if(m_hurt_cb>0)
			{
				LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
				if (pStack != NULL)
				{
					pStack->pushInt(objId);
					pStack->pushInt(attackId);
					pStack->pushInt(hurt);
					pStack->pushInt(cur_blood);
					pStack->pushInt(resistType);
					for(int j=0;j<buff_count;j++)
					{
						uint32_t tmpClearBufId = pbc_rmessage_integer(p, "clearbuffs", j, NULL);
						pStack->pushInt(tmpClearBufId);
					}
					pStack->executeFunctionByHandler(m_hurt_cb, 5+buff_count);
					pStack->clean();
				}
			}
		}
		else if(r_node != nullptr)
		{
			int hp = r_node->getHP();
			if( (hp > cur_blood && hurt>0) || (hp < cur_blood && hurt<0))
				r_node->setHP(cur_blood);
		}
		*/
		/*int hp = r_node->getHP();
		if( (hp > cur_blood && hurt>0) || (hp < cur_blood && hurt<0))
			r_node->setHP(cur_blood);
	}
	pbc_rmessage_delete(m);
}*/

void UIMapView::onShowHurtNumber(int number,Point pos,char f_type,bool ishit,Point span_pos, int resistType)
{
	if(number<0)
		number*=-1;
	Node *number_node = nullptr;
	Rect rect = Rect(0,0,220,30);
	if(f_type == 2)
	{
		rect = Rect(0,30,176,25);
	}
	else if(f_type == 3)
	{
		rect = Rect(0,58,176,25);
	}
	if(number > 0)
	{
		number_node = MakeNumbers::createWithSymbolRect("res/mainui/number/hurt.png",number,0,rect);
		if(ishit && number_node)
		{
			Sprite *hit_sp =  Sprite::create("res/mainui/number/hurt.png",Rect(0,82,54,28));
			if(hit_sp)
			{
				hit_sp->setPosition(Point(-15,0));
				hit_sp->setAnchorPoint(Point(1.0,0.5));
				number_node->addChild(hit_sp);
			}
		}
	}
	else
	{
		number_node = Node::create();
		if (number_node)
		{
			Sprite *sp =  Sprite::create(
				resistType == 1 ? "res/mainui/number/mian_yi.png" :		//"无敌"
				(
				resistType == 2 ? "res/mainui/number/mian_yi.png" :		//"魔免"
				(
				resistType == 3 ? "res/mainui/number/mian_yi.png" :		//"物免"
				"res/mainui/number/miss.png"							//"闪避"
				)
				)
				);

			if(sp)
				number_node->addChild(sp);
		}
	}
	if(number_node != nullptr)
	{
		number_node->setCascadeOpacityEnabled(true);
		if(m_hit_node == nullptr)
		{
			m_hit_node = Node::create();
			addChild(m_hit_node,5000);
		}
		m_hit_node->addChild(number_node);
		number_node->setPosition(Point(pos.x,pos.y));
		Vector<FiniteTimeAction*> sequenceActions;
		//if(span_pos.y > 100)
		//{
		//	sequenceActions.pushBack(MoveBy::create(span_pos.y/200,span_pos));
		//	sequenceActions.pushBack(FadeOut::create(0.3));
		//}
		//else
		{
			float distance = span_pos.getDistance(Point(0,0));
			sequenceActions.pushBack(MoveBy::create(distance/700,span_pos));
			sequenceActions.pushBack(DelayTime::create(0.1));
			sequenceActions.pushBack(MoveBy::create(distance/1400,span_pos/3));
			sequenceActions.pushBack(DelayTime::create(0.1));
			sequenceActions.pushBack(Spawn::create(ScaleTo::create(0.3,0.8),FadeOut::create(0.8),NULL));
		}
		sequenceActions.pushBack(RemoveSelf::create());
		FiniteTimeAction *actall = Sequence::create(sequenceActions);
		number_node->runAction(actall);
	}
}

void UIMapView::onDoMove(int objId, short pos_x, short pos_y)
{
	if(m_item_node == nullptr){
		return;
	}
	//log("objid:%d -> pos_x:%d -> pos_y:%d",objId,pos_x,pos_y);
	UISpriteCharacter *r_node = dynamic_cast<UISpriteCharacter *>(m_item_node->getChildByTag(objId));
	//if(isBlock(Point(pos_x,pos_y)))
	//{
	//	return;
	//}
	action_queue temp_p;
	temp_p.q_type = ACTION_MOVE_TYPE;
	temp_p.pos = Point(pos_x, pos_y);
	onDelayMove(r_node,Point(pos_x, pos_y));
}

void UIMapView::onDelayMove(UISpriteCharacter *r_node, Point start_point)
{
	if(m_item_node != nullptr)
	{
		if(r_node != nullptr)
		{
			int objId = r_node->getTag();
			char dir = 0;
			double mo_speed = r_node->getSpeed();
			Point now_pos = r_node->getPosition();
			Point now_tile = space2Tile(now_pos);
			if(now_tile == start_point) 
			{
				r_node->doSetOpacity();
				return;
			}
			//log("domove objid:%d -> pos_x:%d -> pos_y:%d",objId,(int)start_point.x,(int)start_point.y);
			float distance = now_tile.getDistance(start_point);
			Point temp_tile = Point(0,0);
			float _movespeed = (float)mo_speed;
			if(distance>4)
			{
				r_node->setPosition(tile2Space(start_point));
				r_node->doSetOpacity();
				return;
			}
			else if(distance>1.5)
			{
				int absx = abs(start_point.x-now_tile.x);
				int absy = abs(start_point.y-now_tile.y);
				int min_abs = MIN(absx,absy);
				if(now_tile.x == start_point.x || now_tile.y == start_point.y || (absx == absy))
				{
					temp_tile = now_tile;
					if(absy == 0)
					{
						if(now_tile.x > start_point.x)
							dir = dir_left;
						else
							dir = dir_right;
					}
					else if(absx == 0)
					{
						if(now_tile.y > start_point.y)
							dir = dir_up;
						else
							dir = dir_down;
					}
					else
					{
						if(now_tile.x > start_point.x)
						{
							if(now_tile.y > start_point.y)
								dir = dir_left_up;
							else
								dir = dir_left_down;
						}
						else
						{
							if(now_tile.y > start_point.y)
								dir = dir_right_up;
							else
								dir = dir_right_down;
						}
					}
					//num_count = distance;
				}
				else
				{
					dir = getDirByTile(Point(start_point-now_tile));
				}
			}
			else
			{
				dir = getDirByTile(Point(start_point-now_tile));
			}

			temp_tile = now_pos;
			float move_time = _movespeed;
			Point dest_pos = tile2Space(start_point);
			//if(r_node->getSeverPointsNum()==1)
				move_time = _movespeed * 1.1;
			//else
			//{
			//	float speedup = getSpeedUp(r_node)/2;
			//	move_time = _movespeed/(1+speedup);
			//}
			if(r_node->getType() < PLAYER_MANE_TYPE)
			{
				if(!r_node->walkInTheDir_ex(move_time,dest_pos,(Commen_Direction)dir))
				{
					FiniteTimeAction* doset = CallFunc::create(CC_CALLBACK_0(UISpriteCharacter::doSetOpacity,r_node));
					r_node->runAction( Sequence::create(DelayTime::create(0.1f),doset,NULL));
				}
			}
			else
			{
				if(!((UISpriteCharacter *)r_node)->moveInTheDir_ex(_movespeed,tile2Space(start_point),(Commen_Direction)dir,move_time))
				{
					FiniteTimeAction* doset = CallFunc::create(CC_CALLBACK_0(UISpriteCharacter::doSetOpacity,r_node));
					r_node->runAction( Sequence::create(DelayTime::create(0.1f),doset,NULL));
				}
			}
		}
	}
}