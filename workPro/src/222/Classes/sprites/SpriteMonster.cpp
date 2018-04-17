#include "SpriteMonster.h"
#include "mapview/MapView.h"
#include "ObjectMoveAction.h"

USING_NS_CC;

#define CC_SAFE_ADDMAPNODE(p, parent)		do { if(p && parent && isRunning()) { (parent)->addChild(p); } } while(0)
#define CC_SAFE_REMOVEFROMPARENT(p)			do { if(p) { (p)->removeFromParent(); } } while(0)
#define CC_SAFE_CLEANUP_RELEASE_NULL(p)		do { if(p) { (p)->cleanup(); (p)->release(); (p) = nullptr; } } while(0)

//#define MAX_NUM_ONE_TILE 3
static int MAX_NUM_ONE_TILE = 3;
static const int MAP_TILE_COUNT = 35;
static Vector<SpriteMonster*> _s_map_tile[MAP_TILE_COUNT][MAP_TILE_COUNT];
static bool s_hide_center_rect = false;

void resetHideTile(Point old_tile,Point new_tile)
{
	int x = (int)old_tile.x;
	int y = (int)old_tile.y;
	for (auto& item : _s_map_tile[x%MAP_TILE_COUNT][y%MAP_TILE_COUNT])
	{
		if(item->getType() < PLAYER_MANE_TYPE)
		{
			MirTextNode* name = item->getNameBatchLabel();
			if(name!=nullptr)
				name->setOpacity(item->getOpacity());
		}
	}
	for (auto& item : _s_map_tile[x%MAP_TILE_COUNT][(y+MAP_TILE_COUNT-1)%MAP_TILE_COUNT])
	{
		if(item->getType() < PLAYER_MANE_TYPE)
		{
			MirTextNode* name = item->getNameBatchLabel();
			if(name!=nullptr)
				name->setOpacity(item->getOpacity());
		}
	}
	int x1 = (int)new_tile.x;
	int y1 = (int)new_tile.y;
	for (auto& item : _s_map_tile[x1%MAP_TILE_COUNT][y1%MAP_TILE_COUNT])
	{
		if(item->getType() < PLAYER_MANE_TYPE)
		{
			MirTextNode* name = item->getNameBatchLabel();
			if(name!=nullptr)
				name->setOpacity(50);
		}
	}
	for (auto& item : _s_map_tile[x1%MAP_TILE_COUNT][(y1+MAP_TILE_COUNT-1)%MAP_TILE_COUNT])
	{
		if(item->getType() < PLAYER_MANE_TYPE)
		{
			MirTextNode* name = item->getNameBatchLabel();
			if(name!=nullptr)
				name->setOpacity(50);
		}
	}
}

bool monsterComparisonLess(SpriteMonster* n1, SpriteMonster* n2)
{
	return( n1->getOnRide()>n2->getOnRide() || n1->getOnRide() == n2->getOnRide()&& n1->getResId() > n2->getResId() ||
           ( n1->getResId() == n2->getResId() && n1->getOrderOfArrival() < n2->getOrderOfArrival() )
           );
}

int SpriteMonster::getMonstersCountOnRect(Rect rc)
{
	int x = rc.origin.x;
	int y =  rc.origin.y;
	int width = rc.size.width;
	int height = rc.size.height;
	int count = 0;
	for(int i=x;i<x+width;i++)
	{
		for(int j=y;i<x+height;j++)
		{
			for (auto& item : _s_map_tile[i%MAP_TILE_COUNT][j%MAP_TILE_COUNT])
			{
				if(item->getType() < BOSS_MONSTER && item->isVisible()&& item->isAlive())
				{
					count++;
				}
			}
		}
	}
	return count;
}
void SpriteMonster::setMaxNumOneTile(int num)
{
	MAX_NUM_ONE_TILE = num;
}

void SpriteMonster::setHideCenterRect(bool hide)
{
	s_hide_center_rect = hide;
}

void SpriteMonster::clearMapTile()
{
	for(int i=0;i<MAP_TILE_COUNT;i++)
	{
		for(int j=0;j<MAP_TILE_COUNT;j++)
		{
			_s_map_tile[i][j].clear();
		}
	}
}

SpriteMonster *SpriteMonster::create(const std::string&pszFileName)
{
    SpriteMonster *pRet = new (std::nothrow) SpriteMonster();
    if (pRet && pRet->initWithFileExt(pszFileName))
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

SpriteMonster::SpriteMonster()
{	
	//shadow_sprite = NULL;
	m_maxhp = 1;
	show_h = 0;
	show_offx = 0;
	m_hp = 0;
	is_show_blood = false;
	m_onRide = false;
	m_blood_bg = NULL;
	m_blood_pro = NULL;
	m_name_label = NULL;
	m_name_batchlabel = NULL;
	m_facName_batchlabel = NULL;
	m_titleName_batchlabel = NULL;
	m_title_node = NULL;
	//m_head_node = NULL;
	m_weapon_node = NULL;
	m_wing_node = NULL;
	m_ride_node = NULL;
	m_main_node = NULL;
	m_down_node = NULL;
	m_top_node  = NULL;
	m_skill_node = NULL;
	m_skilldown_node = NULL;
	m_buffskill_node  = NULL;
	m_baseSpead = 0.45;
	m_spead = 0.45;
	m_spead_up = 0;
	m_onRide = false;
	m_sprites.clear();
	m_weapon_id = 0;
	m_is_lock_height = false;
	m_need_hide = false;
	m_tile_point = Point();
	m_server_tile = m_tile_point;
	m_show_name = false;
	is_need_resetBloodHeight = true;
	m_monster_id = 0;
	m_facName = "";
	m_titleName = "";
	is_show_wing = true;
	m_isHighRide = false;
	m_isAttackRide = false;
	last_action = hurt;
	last_action_dir = dir_undef;
	m_set_opacity_num = 180;
}

SpriteMonster::~SpriteMonster(void)
{
	CC_SAFE_CLEANUP_RELEASE_NULL(m_blood_bg);
	CC_SAFE_CLEANUP_RELEASE_NULL(m_title_node);
	CC_SAFE_CLEANUP_RELEASE_NULL(m_main_node);
	CC_SAFE_CLEANUP_RELEASE_NULL(m_weapon_node);
	CC_SAFE_CLEANUP_RELEASE_NULL(m_wing_node);
	CC_SAFE_CLEANUP_RELEASE_NULL(m_ride_node);
	CC_SAFE_CLEANUP_RELEASE_NULL(m_down_node);
	CC_SAFE_CLEANUP_RELEASE_NULL(m_top_node);
	CC_SAFE_CLEANUP_RELEASE_NULL(m_buffskill_node);
	CC_SAFE_CLEANUP_RELEASE_NULL(m_skill_node);
	CC_SAFE_CLEANUP_RELEASE_NULL(m_skilldown_node);
	if(getActorFlag()&&g_MapView!=nullptr)
		g_MapView->setMainRole(nullptr);
	if (m_name_batchlabel != NULL)
	{
		m_name_batchlabel->removeFromParent();
		m_name_batchlabel->release();
		m_name_batchlabel = NULL;
	}

	if (m_facName_batchlabel != NULL)
	{
		m_facName_batchlabel->removeFromParent();
		m_facName_batchlabel->release();
		m_facName_batchlabel = NULL;
	}

	if (m_titleName_batchlabel != NULL)
	{
		m_titleName_batchlabel->removeFromParent();
		m_titleName_batchlabel->release();
		m_titleName_batchlabel = NULL;
	}

	//m_sprites.clear();
	//clearServerPoints();
}

void SpriteMonster::setBaseUrl(const std::string& pszFileName)
{
	SpriteBase::setBaseUrl(pszFileName);
	if(getActorFlag()&&m_top_node!= nullptr)
	{
		SpriteBase * cl_sp = getOpacityNodeByTag(E_ONTAG_BODY);
		if(cl_sp!=nullptr)
		{
			cl_sp->setBaseUrl(pszFileName);
			int run_act_num = 12;
			if(getOnRide())
				run_act_num = 8;
			cl_sp->initRunStatus(run_act_num);
		}
	}
}

void SpriteMonster::setShow_H(int sh)
{
	if (sh > show_h)
	{
		show_h = sh;
		//CCLOG("show_h setted from monster.cpp %f", show_h);
	}
}

void SpriteMonster::setServerTilePosByTile(float tx, float ty)
{
	setServerTile(Point(tx,ty));
	if (g_MapView)
	{
		Point pos = g_MapView->tile2Space(Point(tx,ty));
		setPosition(pos);
	}
}

void SpriteMonster::insertServerPoint(action_queue t_point)
{
	if(!server_points.empty())
	{
		action_queue temp_p = server_points.back();
		if((t_point.q_type == ACTION_MOVE_TYPE) && (temp_p.q_type == t_point.q_type) &&(temp_p.pos == t_point.pos))
			return;
	}
	server_points.push(t_point);
}

void SpriteMonster::removeServerPoint()
{
	if(server_points.empty()) 
		return;
	server_points.pop();
}

action_queue SpriteMonster::getServerPoints()
{
	if(!server_points.empty())
	{
		return server_points.front();
	}

	action_queue ret;
	return ret;
}

int SpriteMonster::getSeverPointsNum()
{
	return server_points.size();
}

void SpriteMonster::clearServerPoints()
{
    while(!server_points.empty())
    {
        server_points.pop();
    }
}

void SpriteMonster::doStandedAction()
{
	playAction(m_stand_times,stand,m_roledata.dir,0);
	for (auto c_sprite : m_sprites)
	{
		initOrderByDir(c_sprite,m_roledata.dir);
		c_sprite->playAction(m_stand_times,stand,m_roledata.dir,0);
	}

	is_need_resetBloodHeight = true;

}

void SpriteMonster::doStanded()
{
	if(hasServerPoints())
		return;
	if(getCurrActionState()<ACTION_STATE_CREATE)
	{
		//CCLOG("doStanded"
		standed();
	}
}

void SpriteMonster::doSetOpacity()
{
	if(g_MapView != nullptr)
	{
		Point pp = g_MapView->space2Tile(getPosition());
		setLocalZOrder((int)pp.y);
		if(g_MapView->isOpacity(pp))
			setOpacity(100);
		else
			setOpacity(255);
		if(hasServerPoints())
		{
			action_queue temp_p = getServerPoints();
			if(temp_p.q_type == ACTION_MOVE_TYPE)
			{
				if(!getActorFlag())
					g_MapView->onDelayMove(this,temp_p.pos);
				else
					removeServerPoint();
			}
			else if(temp_p.q_type == ACTION_ATTACK_TYPE)
			{
				if (!getActorFlag())
				{
					//g_MapView->onDelayPlaySkill(this,temp_p);
				}
				else {
					removeServerPoint();
				}
			}
			else if(temp_p.q_type == ACTION_CRASH_TYPE)
			{
				//g_MapView->onDelayCrash(this,temp_p);
			}
			else if(temp_p.q_type == ACTION_CRASHED_TYPE)
			{
				//g_MapView->onDelayCrashed(this,temp_p);
			}
			else if(temp_p.q_type == ACTION_SKILLMOVE_TYPE)
			{
				//g_MapView->onDelaySkillMove(this,temp_p);
			}
		}
	}
}

void SpriteMonster::doSetOpacity_ex()
{
	action_queue temp_p = getServerPoints();
	removeServerPoint();
	if(temp_p.q_type == ACTION_ATTACK_TYPE)
	{
		if(g_MapView != nullptr)
		{
			if(hasServerPoints()&&(!getActorFlag()))
			{
				action_queue temp_p = getServerPoints();
				if(temp_p.q_type == ACTION_MOVE_TYPE)
					g_MapView->onDelayMove(this,temp_p.pos);
				else if(temp_p.q_type == ACTION_ATTACK_TYPE)
				{
					//g_MapView->onDelayPlaySkill(this,temp_p);
				}
				else if(temp_p.q_type == ACTION_CRASH_TYPE)
				{
					//g_MapView->onDelayCrash(this,temp_p);
				}
				else if(temp_p.q_type == ACTION_CRASHED_TYPE)
				{
					//g_MapView->onDelayCrashed(this,temp_p);
				}
				else if(temp_p.q_type == ACTION_SKILLMOVE_TYPE)
				{
					//g_MapView->onDelaySkillMove(this,temp_p);
				}
			}
		}
	}
	else
	{
		doSetOpacity();
	}
}

void SpriteMonster::setOpacity(GLubyte opact)
{
	if(main_sprite!=NULL)
		main_sprite->setOpacity(opact);
	for (auto c_sprite : m_sprites)
	{
		if(c_sprite->getTag() < 8000000)
			c_sprite->setOpacity(opact);
		else if(c_sprite->getOpacity() > 0)
			c_sprite->setOpacity(opact*m_set_opacity_num/255);
	}
	//if(m_title_node)
	//	m_title_node->setOpacity(opact);
	//if(m_name_batchlabel)
	//{
	//	int opa = m_name_batchlabel->getOpacity();
	//	if(opa > 50)
	//		m_name_batchlabel->setOpacity(opact);
	//}
	//if(m_blood_bg)
	//	m_blood_bg->setOpacity(opact);
	//setOpacityNum(opact);
	Node::setOpacity(opact);
}

void SpriteMonster::setColor(const Color3B& color)
{
	if(main_sprite!=NULL)
		main_sprite->setColor(color);
	for (auto c_sprite : m_sprites)
	{
		c_sprite->setColor(color);
	}
}


void SpriteMonster::setWrite(bool isgray)
{
	for (auto c_sprite : m_sprites)
	{
		c_sprite->setWrite(isgray);
	}
}

void SpriteMonster::setGray(bool isgray)
{
	if(main_sprite!=NULL)
	{
		if(isgray)
			main_sprite->setColor(ccColor3B(100,100,100));
		else
			main_sprite->setColor(ccColor3B(255,255,255));
	}
	for (auto c_sprite : m_sprites)
	{
		c_sprite->setGray(isgray);
	}
}


void SpriteMonster::insertActionChild(const std::string&strName, int z,int tag)
{
	SpriteBase * show_sprite = nullptr;

	//if(getActorFlag()&&child != nullptr && child->getMainSprite() != nullptr&&ADD_WING_TYPE!=tag)
	//	child->getMainSprite()->setReDraw(true);
	int run_act_num = 12;
    if(getOnRide())
        run_act_num = 8;
	switch ((AddNodeType)tag)
	{
		case ADD_WEAPON_TYPE:
			if( MapView::getDressNode()!=nullptr)
			{
				if(m_weapon_node != nullptr)
					show_sprite = (SpriteBase *)m_weapon_node->getChildByTag(tag);

				if(show_sprite == nullptr)
				{
					show_sprite = SpriteBase::create(strName);
					if(show_sprite != nullptr)
					{
						show_sprite->initStandStatus(0,0,m_stand_times,m_roledata.dir);
						show_sprite->setType(WUQI_TYPE);
						show_sprite->setOpacity(getOpacity());
						show_sprite->setSpriteOneDir(getSpriteOneDir());

						if (m_weapon_node == nullptr)
						{
							m_weapon_node = MapTileNode::create();
							m_weapon_node->retain();
							CC_SAFE_ADDMAPNODE(m_weapon_node, MapView::getDressNode());
						}

						m_weapon_node->addChild(show_sprite,z,tag);
						m_weapon_node->setPosition(getPosition());
						m_weapon_node->setTilePoint(m_tile_point);
						m_weapon_node->setLocalZOrder(show_sprite->getResId());

						m_sprites.pushBack(show_sprite);

						if(getActorFlag())
						{
							SpriteBase * weapon_sp = getOpacityNodeByTag(E_ONTAG_WEAPON);
							if (weapon_sp)
							{
								weapon_sp->setBaseUrl(strName);
							}
							else
							{
								weapon_sp = SpriteBase::create(strName);

								if(m_top_node)
								{
									m_top_node->addChild(weapon_sp,127,E_ONTAG_WEAPON);
									m_sprites.pushBack(weapon_sp);
								}
							}
							
							weapon_sp->setType(WUQI_TYPE);
							weapon_sp->initStandStatus(0,0,m_stand_times,m_roledata.dir);
							weapon_sp->initRunStatus(run_act_num);
							weapon_sp->setSpriteOneDir(getSpriteOneDir());
							weapon_sp->setOpacity(m_set_opacity_num);
						}

						initOrderByDir(show_sprite,getCurrectDir());
					}
				}
				else
				{
					show_sprite->setBaseUrl(strName);
					if(getActorFlag()&&m_top_node!= nullptr)
					{
						SpriteBase * weapon_sp = getOpacityNodeByTag(E_ONTAG_WEAPON);
						if(weapon_sp!=nullptr)
						{
							weapon_sp->setBaseUrl(strName);
							weapon_sp->initRunStatus(run_act_num);
						}
					}
				}
			}
			break;
		case ADD_WING_TYPE:
			if(MapView::getDressNode()!=nullptr)
			{
				if(m_wing_node != nullptr)
					show_sprite = (SpriteBase *)m_wing_node->getChildByTag(tag);

				if(show_sprite == nullptr)
				{
					show_sprite = SpriteBase::create(strName);
					if(show_sprite != nullptr)
					{
						show_sprite->initStandStatus(0,0,m_stand_times,m_roledata.dir);
						show_sprite->setType(WING_TYPE);
						show_sprite->setOpacity(getOpacity());

						if (m_wing_node == nullptr)
						{
							m_wing_node = MapTileNode::create();
							m_wing_node->retain();
							CC_SAFE_ADDMAPNODE(m_wing_node, MapView::getDressNode());
						}

						m_wing_node->addChild(show_sprite,z,tag);
						m_wing_node->setPosition(getPosition());
						m_wing_node->setTilePoint(m_tile_point);
						m_wing_node->setLocalZOrder(show_sprite->getResId()+4000000);

						m_sprites.pushBack(show_sprite);

						if(getActorFlag())
						{
							SpriteBase * wing_sp = getOpacityNodeByTag(E_ONTAG_WING);
							if (wing_sp)
							{
								wing_sp->setBaseUrl(strName);
							}
							else
							{
								wing_sp = SpriteBase::create(strName);

								if(m_top_node!= nullptr)
								{
									m_top_node->addChild(wing_sp,130,E_ONTAG_WING);
									m_sprites.pushBack(wing_sp);
								}
							}

							wing_sp->setType(WING_TYPE);
							wing_sp->initStandStatus(0,0,m_stand_times,m_roledata.dir);
							wing_sp->initRunStatus(run_act_num);
							wing_sp->setOpacity(0);
						}

						initOrderByDir(show_sprite,getCurrectDir());
					}
				}
				else 
				{
					show_sprite->setBaseUrl(strName);
					if(getActorFlag()&&m_top_node!= nullptr)
					{
						SpriteBase * wing_sp = getOpacityNodeByTag(E_ONTAG_WING);
						if(wing_sp!=nullptr)
						{
							wing_sp->setBaseUrl(strName);
							wing_sp->initRunStatus(run_act_num);
						}
					}
				}
			}
			break;
		case ADD_RIDE_TYPE:
			if(MapView::getDressNode()!=nullptr)
			{
				if(m_ride_node != nullptr)
					show_sprite = (SpriteBase *)m_ride_node->getChildByTag(tag);

				if(show_sprite == nullptr)
				{
					show_sprite = SpriteBase::create(strName);
					if(show_sprite != nullptr)
					{
						show_sprite->initStandStatus(0,0,m_stand_times,m_roledata.dir);
						show_sprite->setType(RIDE_TYPE_UP);
						show_sprite->setOpacity(getOpacity());
						show_sprite->setSpriteOneDir(getSpriteOneDir());

						if (m_ride_node == nullptr)
						{
							m_ride_node = MapTileNode::create();
							m_ride_node->retain();
							CC_SAFE_ADDMAPNODE(m_ride_node, MapView::getDressNode());
						}

						m_ride_node->addChild(show_sprite,z,tag);
						m_ride_node->setPosition(getPosition());
						m_ride_node->setTilePoint(m_tile_point);
						m_ride_node->setLocalZOrder(show_sprite->getResId() + 4000000);
						setPosition(getPosition());
						

						m_sprites.pushBack(show_sprite);
						if(getActorFlag())
						{
							SpriteBase * ride_sp = getOpacityNodeByTag(E_ONTAG_RIDE);
							if(ride_sp)
							{
								ride_sp->setBaseUrl(strName);
							}
							else
							{
								ride_sp = SpriteBase::create(strName);

								if(m_top_node!= nullptr)
								{
									m_top_node->addChild(ride_sp,125,E_ONTAG_RIDE);
									m_sprites.pushBack(ride_sp);
								}
							}

							ride_sp->setType(RIDE_TYPE_UP);
							ride_sp->initStandStatus(0,0,m_stand_times,m_roledata.dir);
							ride_sp->initRunStatus(run_act_num);
							ride_sp->setSpriteOneDir(getSpriteOneDir());
							ride_sp->setOpacity(m_set_opacity_num);
							if(m_isHighRide)
								ride_sp->setPosition(Point(0,20));
							
						}
					}
				}
				else
				{
					show_sprite->setBaseUrl(strName);

					if (m_ride_node)
					{
						m_ride_node->setLocalZOrder(show_sprite->getResId() + 4000000);
						MapView::setDressNodeReorder();
					}

					if(getActorFlag()&&m_top_node!= nullptr)
					{
						SpriteBase * ride_sp = getOpacityNodeByTag(E_ONTAG_RIDE);
						if(ride_sp!=nullptr)
						{
							ride_sp->initRunStatus(run_act_num);
							ride_sp->setBaseUrl(strName);
							ride_sp->setLocalZOrder(125);
							if(m_isHighRide)
								ride_sp->setPosition(Point(0,20));
							else
								ride_sp->setPosition(Point(0,0));
						}
					}
				}
				setPosition(getPosition());
			}
			break;
	}
	
	if(show_sprite!=nullptr)
		show_sprite->initRunStatus(run_act_num);

}

void SpriteMonster::removeActionChild(SpriteBase* child)
{
	ssize_t index = m_sprites.getIndex(child);
    m_sprites.erase(index);
	child->removeFromParent();
}

void SpriteMonster::removeActionChildByTag(int tag)
{
	int opacity_tag = 0;
	switch ((AddNodeType)tag)
	{
		case ADD_WEAPON_TYPE:
			if(m_weapon_node != nullptr)
			{
				SpriteBase *child = (SpriteBase *)m_weapon_node->getChildByTag(tag);
				if(child) 
				{
					removeActionChild(child);
				}
				CC_SAFE_REMOVEFROMPARENT(m_weapon_node);
				CC_SAFE_CLEANUP_RELEASE_NULL(m_weapon_node);

				m_weapon_id = 0;
				opacity_tag = E_ONTAG_WEAPON;
			}
			break;
		case ADD_WING_TYPE:
			if(m_wing_node != nullptr)
			{
				SpriteBase *child = (SpriteBase *)m_wing_node->getChildByTag(tag);
				if(child) 
				{
					removeActionChild(child);
				}
				CC_SAFE_REMOVEFROMPARENT(m_wing_node);
				CC_SAFE_CLEANUP_RELEASE_NULL(m_wing_node);

				opacity_tag = E_ONTAG_WING;
			}
			break;
		case ADD_RIDE_TYPE:
			if(m_ride_node != nullptr)
			{
				SpriteBase *child = (SpriteBase *)m_ride_node->getChildByTag(tag);
				if(child) 
				{
					removeActionChild(child);
				}
				CC_SAFE_REMOVEFROMPARENT(m_ride_node);
				CC_SAFE_CLEANUP_RELEASE_NULL(m_ride_node);

				opacity_tag = E_ONTAG_RIDE;
			}
			break;
	}
	if(getActorFlag()&&m_top_node!= nullptr&&opacity_tag>0)
	{
		SpriteBase * child_sp = getOpacityNodeByTag(opacity_tag);
		if(child_sp!=nullptr)
		{
			removeActionChild(child_sp);
		}
	}

}

void SpriteMonster::resetBloodHeight()
{
	if(is_show_blood && !m_is_lock_height)
	{
		is_need_resetBloodHeight = true;
	//	show_h = main_sprite->getOffsetPosition().y + main_sprite->getTextureRect().size.height;
	//	setPosition(getPosition());
	}
}

void SpriteMonster::showNameAndBlood_imp(bool show)
{
	if (MapView::getBloodNode() == NULL)
		return;

	if (m_name_label != NULL&&m_blood_bg != NULL)
	{
		m_name_label->setVisible(show && isVisible());
		if (m_name_batchlabel != NULL)
		{
			m_name_batchlabel->setVisible(show && isVisible() || getType() == NPC_TYPE);
		}
		//else
		//{
		//	if (getName().length() > 0)
		//	{
		//		Point pos;
		//		if (isNoActorOrNpc())
		//			pos = getPosition() + Point(0, show_h / 3 - 10);
		//		else
		//			pos = getPosition() + Point(0, show_h + 15);
		//	}
		//}

		if (m_facName_batchlabel != NULL)
		{
			m_facName_batchlabel->setVisible(show && isVisible() || getType() == NPC_TYPE);
		}
		//else
		//{
		//	if (getFacName().length() > 0)
		//	{
		//		Point pos;
		//		if (isNoActorOrNpc())
		//			pos = getPosition() + Point(0, show_h / 3 - 10);
		//		else
		//			pos = getPosition() + Point(0, show_h + 15);
		//	}
		//}

		if (m_titleName_batchlabel != NULL)
		{
			m_titleName_batchlabel->setVisible(show && isVisible() || getType() == NPC_TYPE);
		}
		//else
		//{
		//	if (getFacName().length() > 0)
		//	{
		//		Point pos;
		//		if (isNoActorOrNpc())
		//			pos = getPosition() + Point(0, show_h / 3 - 10);
		//		else
		//			pos = getPosition() + Point(0, show_h + 15);
		//	}
		//}
		
		m_blood_bg->setVisible(show && isVisible());
		is_show_blood = show;
		if (m_title_node)
		{
			if (getType() < PLAYER_MANE_TYPE)
				m_title_node->setVisible(isVisible());
			else
				m_title_node->setVisible(isVisible() && isAlive());
		}
	}
}

void SpriteMonster::showNameAndBlood(bool show, int height)
{
	if(MapView::getBloodNode()==NULL)
		return;

	setNameAndBloodPos(height != 0, 0, height);
	showNameAndBlood_imp(show);
}

void SpriteMonster::setVisibleNameAndBlood(bool val)
{
	showNameAndBlood_imp(val);
}

void SpriteMonster::setNameAndBloodPos(bool is_lock_height, int offx, int height)
{
	m_is_lock_height = is_lock_height;

	show_offx = offx;

	if (m_is_lock_height)
	{
		show_h = height;
		resetShowHPosition();
	}
	else
	{
		is_need_resetBloodHeight = true;
		reCalcShowH();
	}

}

void SpriteMonster::playAction(float times,Commen_ActionToDo action,Commen_Direction dir,int loop,float ltimes)
{
	SpriteBase::playAction(times,action,dir,loop,ltimes);
	last_action = action;
	last_action_dir = dir;
}

bool SpriteMonster::standed()
{
	bool has_loadres = this->getResLoadStatus();
	if(stand_inited&&changeState(ACTION_STATE_IDLE)&&(last_action!=stand||last_action_dir!=m_roledata.dir))
	{
		playAction(m_stand_times,stand,m_roledata.dir,0);
		for (auto c_sprite : m_sprites)
		{
			initOrderByDir(c_sprite,m_roledata.dir);
			c_sprite->playAction(m_stand_times,stand,m_roledata.dir,0);
			has_loadres = has_loadres&&c_sprite->getResLoadStatus();
		}

		is_need_resetBloodHeight = true;

	}
	return has_loadres;
}

bool SpriteMonster::setSpriteDir(Commen_Direction dir)
{
	if(m_roledata.dir == dir)
		return false;
	else
	{
		m_roledata.dir = dir;

		if(getType()< PLAYER_MANE_TYPE && getType()>=NORMAL_MONSTER)
		{
			FiniteTimeAction* actbackfun = CallFunc::create([&](){ this->resetBloodHeight();});
			runAction(Sequence::create(DelayTime::create(0.1),actbackfun,NULL));
		}
	}
	return true;
}

bool SpriteMonster::setSpriteOneDir(Commen_Direction dir)
{
	SpriteBase::setSpriteOneDir(dir);
	for (auto c_sprite : m_sprites)
	{
		c_sprite->setSpriteOneDir(dir);
	}

	return true;
}

void SpriteMonster::stopInTheTime()
{
	//removeStread();
	if(changeState(ACTION_STATE_MABI))
	{
		//stopAllActions();
		getMainSprite()->stopAllActions();
		for (auto c_sprite : m_sprites)
		{
			initOrderByDir(c_sprite,m_roledata.dir);
			c_sprite->stopInTheTime();
		}
	}
}

void SpriteMonster::walkToPos(float times,Point newpoint,bool stand)
{
	//removeStread();
	if(getCurrActionState()<ACTION_STATE_CREATE)
	{
		if(changeState(ACTION_STATE_WALK)||setDirByNowPoint(newpoint))
		{
			float walk_time = 0.35;
			if(times < 1)
				walk_time = 0.125+times/2;		
			setDirByNowPoint(newpoint);
			playAction(walk_time,walk,m_roledata.dir,0);
			for (auto c_sprite : m_sprites)
			{
				initOrderByDir(c_sprite,m_roledata.dir);
				c_sprite->playAction(walk_time,walk,m_roledata.dir,0);
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


bool SpriteMonster::walkInTheDir(float times,Point newpoint,Commen_Direction dir)
{
	//removeStread();
	//if(getCurrActionState()<ACTION_STATE_DEAD&&(getCurrActionState() < ACTION_STATE_ATTACK||getCurrActionState()>ACTION_STATE_COLLIDE))
	if(getCurrActionState() < ACTION_STATE_CREATE)
	{
		if(changeState(ACTION_STATE_WALK)||setSpriteDir(dir))
		{
			float walk_time = (0.125+times/2)*4/m_roledata.maxcut_walk;
			playAction(walk_time,walk,dir,0);
			for (auto c_sprite : m_sprites)
			{
				initOrderByDir(c_sprite,dir);
				c_sprite->playAction(walk_time,walk,dir,0);
			}
		}
		if(newpoint != Point(0,0))
		{
			FiniteTimeAction* doset = CallFunc::create(CC_CALLBACK_0(SpriteMonster::doSetOpacity,this));
			runAction(Sequence::create( MoveTo::create(times,newpoint),doset,NULL));
		}
		return true;
	}
	return false;
}

bool SpriteMonster::walkInTheDir_ex(float times,Point newpoint,Commen_Direction dir)
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
				initOrderByDir(c_sprite,dir);
				c_sprite->playAction(actLoopTime,walk,dir,0);
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
				//FiniteTimeAction* doset = CallFunc::create(CC_CALLBACK_0(SpriteMonster::doSetOpacity_ex,this));
				FiniteTimeAction* dostand = CallFunc::create(CC_CALLBACK_0(SpriteMonster::doStanded,this));
				//runAction(Sequence::create( MoveTo::create(times,newpoint),doset,DelayTime::create(0.2),dostand,NULL));

				runAction(ObjectMoveAction::create(times,newpoint,CC_CALLBACK_0(SpriteMonster::doSetOpacity_ex,this)));
				runAction(Sequence::create( DelayTime::create(times+0.25),dostand,NULL));
			}
		}
		return true;
	}
	return false;
}

bool SpriteMonster::attackToPos(float times,Point newpoint)
{
	if(changeState(ACTION_STATE_ATTACK))
	{
		// 原地转方向不需要通过这个函数
		if(newpoint != Point() && getPosition() != newpoint)
			setDirByNowPoint(newpoint);
		float delay_time = times*m_roledata.maxcut_attack/3;
		playAction(times,attack,m_roledata.dir,1);
		for (auto c_sprite : m_sprites)
		{
			initOrderByDir(c_sprite,m_roledata.dir);
			c_sprite->playAction(times,attack,m_roledata.dir,1);
		}
		FiniteTimeAction* actbackfun = CallFunc::create([&](){if(getCurrActionState()<= ACTION_STATE_CREATE) changeState(ACTION_STATE_IDLE);});
		Action *seq_act = Sequence::create(DelayTime::create(delay_time),actbackfun,NULL);
		seq_act->setTag(1);
		runAction(seq_act);
		return true;
	}
	else 
	{
		changeState(ACTION_STATE_IDLE);
	}
	return false;
}


bool SpriteMonster::attackOneTime(float times,Point newpoint)
{
	if(changeState(ACTION_STATE_ATTACK))
	{
		if (!newpoint.isZero() && getPosition() != newpoint)
			setDirByNowPoint(newpoint);
		float delay_time = times*m_roledata.maxcut_attack/3;
		playAction(times,attack,m_roledata.dir,1);
		for (auto c_sprite : m_sprites)
		{
			initOrderByDir(c_sprite,m_roledata.dir);
			c_sprite->playAction(times,attack,m_roledata.dir,1);
		}
		FiniteTimeAction* actbackfun = CallFunc::create([&](){ if(getCurrActionState()<= ACTION_STATE_CREATE) changeState(ACTION_STATE_IDLE);});
		Action *seq_act = Sequence::create(DelayTime::create(delay_time),actbackfun,NULL);
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

bool SpriteMonster::attackOneTime_ex(float times, const cocos2d::Point& newpoint)
{
	if(changeState(ACTION_STATE_ATTACK))
	{
		if (!newpoint.isZero() && getPosition() != newpoint)
			setDirByNowPoint(newpoint);
		playAction(times,attack,m_roledata.dir,1);
		for (auto c_sprite : m_sprites)
		{
			initOrderByDir(c_sprite,m_roledata.dir);
			c_sprite->playAction(times,attack,m_roledata.dir,1);
		}
		float delay_time = times*m_roledata.maxcut_attack/3;
		if(getActorFlag())
		{
			FiniteTimeAction* doset = CallFunc::create(CC_CALLBACK_0(SpriteMonster::doSetOpacity_ex,this));
			FiniteTimeAction* actbackfun = CallFunc::create([&](){if(getCurrActionState()<= ACTION_STATE_CREATE) changeState(ACTION_STATE_IDLE);});
			runAction(Sequence::create(DelayTime::create(times+0.1),doset,actbackfun,NULL));
		}
		else
		{
			FiniteTimeAction* doset = CallFunc::create(CC_CALLBACK_0(SpriteMonster::doSetOpacity_ex,this));
			if(getSeverPointsNum()>1)
			{
				runAction(Sequence::create( DelayTime::create(delay_time),doset,NULL));
			}
			else
			{
				FiniteTimeAction* dostand = CallFunc::create(CC_CALLBACK_0(SpriteMonster::doStanded,this));
				if(getType() < PLAYER_MANE_TYPE)
				{
					runAction(Sequence::create(DelayTime::create(delay_time),doset,dostand,NULL));
				}
				else
				{
					runAction(Sequence::create(DelayTime::create(delay_time),doset,DelayTime::create(0.4),dostand,NULL));
				}			
				
			}
		}
		return true;
	} 
	return false;
}

bool SpriteMonster::MagicOneTime_ex(float times, const cocos2d::Point& newpoint)
{
	if(changeState(ACTION_STATE_MAGICUP))
	{
		// 原地转方向不需要通过这个函数
		if(newpoint != Point() && getPosition() != newpoint)
			setDirByNowPoint(newpoint);
		playAction(times,magicup,m_roledata.dir,1);
		for (auto c_sprite : m_sprites)
		{
			initOrderByDir(c_sprite,m_roledata.dir);
			c_sprite->playAction(times,magicup,m_roledata.dir,1);
		}
		if(getActorFlag())
		{
			FiniteTimeAction* doset = CallFunc::create(CC_CALLBACK_0(SpriteMonster::doSetOpacity_ex,this));
			FiniteTimeAction* actbackfun = CallFunc::create([&](){if(getCurrActionState()<= ACTION_STATE_CREATE) changeState(ACTION_STATE_IDLE);});
			runAction(Sequence::create(DelayTime::create(times+0.5),doset,actbackfun,NULL));
		}
		else
		{
			FiniteTimeAction* doset = CallFunc::create(CC_CALLBACK_0(SpriteMonster::doSetOpacity_ex,this));
			if(getSeverPointsNum()>1)
			{
				runAction(Sequence::create( DelayTime::create(times),doset,NULL));
			}
			else
			{
				FiniteTimeAction* dostand = CallFunc::create(CC_CALLBACK_0(SpriteMonster::doStanded,this));
				runAction(Sequence::create(DelayTime::create(times),doset,DelayTime::create(times+0.4),dostand,NULL));
			}
		}
		return true;
	}
	else 
	{
		changeState(ACTION_STATE_IDLE);
	}
	return false;
}

// 无需动作的魔法
bool SpriteMonster::DoMagicWithoutAction(const cocos2d::Point& newpoint)
{
	if(changeState(ACTION_STATE_IDLE))
	{
		// 原地转方向不需要通过这个函数
		if(newpoint != Point() && getPosition() != newpoint)
			setDirByNowPoint(newpoint);
		
		if(getActorFlag())
		{
			doSetOpacity_ex();
		}
		else
		{
			if(getSeverPointsNum()>1)
			{
				doSetOpacity_ex();;
			}
			else
			{
				doSetOpacity_ex();
				FiniteTimeAction* dostand = CallFunc::create(CC_CALLBACK_0(SpriteMonster::doStanded,this));
				runAction(Sequence::create(DelayTime::create(0.4),dostand,NULL));
			}
		}
		return true;
	}
	return false;
}

bool SpriteMonster::magicUpToPos(float times,Point newpoint)
{
	if(changeState(ACTION_STATE_MAGICUP))
	{
		if(newpoint != Point() && getPosition() != newpoint)
			setDirByNowPoint(newpoint);
		playAction(times,magicup,m_roledata.dir,1);
		for (auto c_sprite : m_sprites)
		{
			initOrderByDir(c_sprite,m_roledata.dir);
			c_sprite->playAction(times,magicup,m_roledata.dir,1);
		}
		FiniteTimeAction* actbackfun = CallFunc::create([&](){if(getCurrActionState()<= ACTION_STATE_CREATE) changeState(ACTION_STATE_IDLE);});
		Action *seq_act = Sequence::create(DelayTime::create(times+0.5),actbackfun,NULL);
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


bool SpriteMonster::attackAction(float times,int a_num,Commen_Direction dir,int a_type)
{
	ActionState state = ACTION_STATE_NONE;
	Commen_ActionToDo action_todo = stand;
	switch (a_type)
	{
	case 1:
		state  = ACTION_STATE_ATTACK_EX1;
		action_todo = attack1;
		break;
	case 2:
		state  = ACTION_STATE_ATTACK_EX2;
		action_todo = attack2;
		break;
	default:
		state  = ACTION_STATE_ATTACK;
		action_todo = attack;
	}
	if(changeState(state))
	{	
		m_roledata.maxcut_ex = a_num;
		playAction(times,action_todo,dir,1);
		for (auto c_sprite : m_sprites)
		{
			c_sprite->m_roledata.maxcut_ex = a_num;
			c_sprite->playAction(times,action_todo,dir,1);
		}
		FiniteTimeAction* actbackfun = CallFunc::create([&](){if(getCurrActionState()<= ACTION_STATE_CREATE) changeState(ACTION_STATE_IDLE);});
		runAction(Sequence::create(DelayTime::create(times),actbackfun,NULL));
		return true;
	}
	return false;
}

bool SpriteMonster::magicAction(float times,int a_num,Commen_Direction dir,int a_type)
{
	ActionState state = ACTION_STATE_NONE;
	Commen_ActionToDo action_todo = stand;
	switch (a_type)
	{
	case 1:
		state  = ACTION_STATE_MAGICUP_EX1;
		action_todo = magicup1;
		break;
	case 2:
		state  = ACTION_STATE_MAGICUP_EX2;
		action_todo = magicup2;
		break;
	default:
		state  = ACTION_STATE_MAGICUP;
		action_todo = magicup;
	}
	if(changeState(state))
	{	
		m_roledata.maxcut_ex = a_num;
		playAction(times,action_todo,dir,1);
		for (auto c_sprite : m_sprites)
		{
			c_sprite->m_roledata.maxcut_ex = a_num;
			c_sprite->playAction(times,action_todo,dir,1);
		}
		FiniteTimeAction* actbackfun = CallFunc::create([&](){if(getCurrActionState()<= ACTION_STATE_CREATE) changeState(ACTION_STATE_IDLE);});
		runAction(Sequence::create(DelayTime::create(times),actbackfun,NULL));
		return true;
	}
	return false;
}

void SpriteMonster::standedby()
{
	if(stand_inited&&getCurrActionState()==ACTION_STATE_IDLE)
	{
		playAction(m_stand_times,standby,m_roledata.dir,0);
		for (auto c_sprite : m_sprites)
		{
			c_sprite->playAction(m_stand_times,standby,m_roledata.dir,0);
		}
	}
}

void SpriteMonster::doSpecailAction(float times,int a_num,Commen_Direction dir,const std::string&typeName)
{
	changeState(ACTION_STATE_SPECAIL);
	m_roledata.maxcut_ex = a_num;
	m_roledata.act_res = typeName;
	playAction(times,specail,dir,1);
	for (auto c_sprite : m_sprites)
	{
		c_sprite->m_roledata.maxcut_ex = a_num;
		c_sprite->m_roledata.act_res = typeName;
		c_sprite->playAction(times,specail,dir,1);
	}
}

bool SpriteMonster::appeared(float times,int a_num,Commen_Direction dir)
{
	if(changeState(ACTION_STATE_CREATE)||setSpriteDir(dir))
	{
		m_roledata.maxcut_ex = a_num;
		playAction(times,appear,dir,1);
		for (auto c_sprite : m_sprites)
		{
			c_sprite->playAction(times,appear,dir,1);
		}
		FiniteTimeAction* actbackfun = CallFunc::create([&](){if(getCurrActionState()<= ACTION_STATE_CREATE) this->standed();});
		runAction(Sequence::create(DelayTime::create(times),actbackfun,NULL));
		return true; 
	}	
	return false;
}

bool SpriteMonster::disappeared(float times,int a_num,Commen_Direction dir)
{
	if(changeState(ACTION_STATE_UNCREATE)||setSpriteDir(dir))
	{
		m_roledata.maxcut_ex = a_num;
		playAction(times,disappear,dir,1);
		for (auto c_sprite : m_sprites)
		{
			c_sprite->playAction(times,disappear,dir,1);
		}
		return true; 
	}	
	return false;
}

bool SpriteMonster::changeDisplay(float times,int a_num,Commen_Direction dir)
{
	if(changeState(ACTION_STATE_CHANGE)||setSpriteDir(dir))
	{
		m_roledata.maxcut_ex = a_num;
		playAction(times,change_dis,dir,1);
		for (auto c_sprite : m_sprites)
		{
			c_sprite->playAction(times,change_dis,dir,1);
		}
		FiniteTimeAction* actbackfun = CallFunc::create([&](){if(getCurrActionState()<= ACTION_STATE_CREATE) this->standed();});
		runAction(Sequence::create(DelayTime::create(times),actbackfun,NULL));
		return true; 
	}	
	return false;
}

void SpriteMonster::gotoDeath(Commen_Direction dir,float times)
{
	//removeStread();
	if(changeState(ACTION_STATE_DEAD))
	{
		m_show_name = false;
		stopAllActions();
		clearServerPoints();
		setSpriteDir(dir);
		playAction(times,death,m_roledata.dir,1);
		for (auto c_sprite : m_sprites)
		{
			initOrderByDir(c_sprite,m_roledata.dir);
			c_sprite->playAction(times,death,m_roledata.dir,1);
		}
		if(m_main_node!= nullptr)
		{
			m_main_node->setTilePoint(Point(10,0));
		}
		if(m_weapon_node!= nullptr)
		{
			m_weapon_node->setTilePoint(Point(10,0));
		}
		if(m_wing_node!= nullptr)
		{
			m_wing_node->setTilePoint(Point(10,0));
		}
	}
}

void SpriteMonster::reloadRes()
{
	Commen_ActionToDo action_type = stand;
	switch (m_currActionState)
	{
		case ACTION_STATE_IDLE:
			action_type = stand;
			break;
		case ACTION_STATE_WALK:
			action_type = walk;
			break;
		case ACTION_STATE_RUN:
			action_type = run;
			break;
		case ACTION_STATE_EXCAVATE:
			action_type = excavate;
			break;
		case ACTION_STATE_DIG:
			action_type = dig;
			break;
		default:
			return;
	}

	if(m_roledata.actiontime > 0 && m_currActionState < ACTION_STATE_CREATE)
	{
		playAction(m_roledata.actiontime,action_type,m_roledata.dir,0);
		for (auto c_sprite : m_sprites)
		{
			initOrderByDir(c_sprite,m_roledata.dir);
			c_sprite->playAction(m_roledata.actiontime,action_type,m_roledata.dir,0);
		}
	}

	reloadPosition();
}

void SpriteMonster::reloadPosition()
{
	setPosition(getPosition());
}

bool SpriteMonster::isAlive()
{
	return m_hp>0;
}


void SpriteMonster::changeModeDisplay(bool isreset,const std::string&url)
{
	SpriteBase::changeModeDisplay(isreset,url);
	if(isreset)
	{
		change_base_url = url;
		//if(getActorFlag()&&m_top_node!= nullptr)
		//{
		//	SpriteBase * cl_sp = (SpriteBase *)m_top_node->getChildByTag(E_ONTAG_BODY);
		//	if(cl_sp!=nullptr)
		//	{
		//		cl_sp->setOpacity(0);
		//	}
		//}
	}
	else
	{
		change_base_url.clear();
		//if(getActorFlag()&&m_top_node!= nullptr)
		//{
		//	SpriteBase * cl_sp = (SpriteBase *)m_top_node->getChildByTag(E_ONTAG_BODY);
		//	if(cl_sp!=nullptr)
		//	{
		//		cl_sp->setOpacity(m_set_opacity_num);
		//	}
		//}
	}
}

bool SpriteMonster::initWithFileExt(const std::string&pszFileName)
{
	//Sprite* blockSprite = Sprite::create();
	//blockSprite->setTextureRect(Rect(0,0,2,2));
	//blockSprite->setColor(Color3B(255,0,0));
	//blockSprite->setOpacity(128);
	//blockSprite->setScaleX(24);
	//blockSprite->setScaleY(16);
	//addChild(blockSprite);

	if(!initWithFile(pszFileName))
		return false;
	//setCascadeOpacityEnabled(true);

	m_name_label = Node::create();
	m_name_label->setAnchorPoint(Point(0.5, 0.5) );
	addChild(m_name_label,122,123);
	m_blood_bg = Sprite::create("res/mblood.png",Rect(0,9,47,9));
	//m_blood_bg->setScale(0.85);
	//m_blood_bg->setCascadeOpacityEnabled(true);
	m_blood_bg->retain();
	if(m_blood_bg != NULL)
	{
		m_blood_pro = Sprite::create("res/mblood.png", Rect(0, 0, 47, 9));
		if (m_blood_pro != NULL)
		{
			if (m_blood_pro->getTexture())
				m_blood_pro->getTexture()->setAliasTexParameters();
			m_blood_pro->setPosition(0, -1);
			m_blood_pro->setAnchorPoint(Point(0.0, 0.0));
			m_blood_bg->addChild(m_blood_pro);
			m_blood_bg->setLocalZOrder(122);
		}

		m_title_node = Node::create();
		m_title_node->setCascadeOpacityEnabled(true);
		m_title_node->retain();
		m_title_node->setLocalZOrder(12);

		m_down_node = Node::create();
		m_down_node->retain();

		m_top_node = Node::create();
		m_top_node->retain();

		main_node->removeFromParentAndCleanup(false);
		m_main_node = MapTileNode::create();
		m_main_node->retain();
		m_main_node->addChild(main_node);

		int res_id = getResId();
		int add_id = 0;
		if (getActorFlag())
		{
			add_id = 5300000;
			//if (main_sprite != nullptr)
			SpriteBase * cl_sp = SpriteBase::create(getBaseUrl());
			cl_sp->initStandStatus(0,0,m_stand_times,m_roledata.dir);
			cl_sp->setType(PLAYER_MANE_TYPE);
			cl_sp->setOpacity(m_set_opacity_num);
			if(m_top_node!= nullptr)
			{
				m_top_node->addChild(cl_sp,128,E_ONTAG_BODY);
				m_sprites.pushBack(cl_sp);
			}
			//	main_sprite->setReDraw(true);
		}
		else if(res_id>4000000 && res_id<5000000 )
		{
			add_id = -3999900;
		}
		else if(res_id>200000 && res_id<4000000)
		{
			add_id = 4000000;
		}
		m_main_node->setLocalZOrder(res_id + add_id);

		m_skill_node = Node::create();
		m_skill_node->retain();

		m_skilldown_node = Node::create();
		m_skilldown_node->retain();

		m_buffskill_node = MapTileNode::create();
		m_buffskill_node->retain();
		m_buffskill_node->setLocalZOrder(999990000);

		ReCreate_name_batchlabel();
		ReCreate_facName_batchlabel();
		ReCreate_titleName_batchlabel();

		showNameAndBlood(false);
	}
	return true;
}

void SpriteMonster::setType(SpriteType var)
{
	SpriteBase::setType(var);

	SpriteBase * cl_sp = getOpacityNodeByTag(E_ONTAG_BODY);
	if(cl_sp!=nullptr)
	{
		cl_sp->setType(var);
	}
}

void SpriteMonster::ReCreate_name_batchlabel()
{
	if (m_name_batchlabel)
	{
		if (m_name_batchlabel->getParent() != MapView::getNameNode())
		{
			m_name_batchlabel->removeFromParent();
			m_name_batchlabel->release();
			m_name_batchlabel = nullptr;
		}
	}
	
	if (m_name_batchlabel == nullptr)
	{
		m_name_batchlabel = MapView::getNameNode()->createLabel(getName().c_str(), 0, getPosition() + Point(show_offx, show_h + 20));
		if (m_name_batchlabel != nullptr)
		{
			m_name_batchlabel->retain();
			if (getActorFlag())
				m_name_batchlabel->setTag(1327);
			m_name_batchlabel->setLineBreakWithoutSpace(true);
			m_name_batchlabel->setVisible((isVisible() && (is_show_blood || m_show_name)) || getType() == NPC_TYPE);

			if (getType() == NPC_TYPE)
				m_name_batchlabel->setPosition(getPosition() + Point(show_offx, show_h + 5));
			else if (isNoActorOrNpc())
				m_name_batchlabel->setPosition(getPosition() + Point(show_offx, show_h / 3 - 10));
			else
				m_name_batchlabel->setPosition(getPosition() + Point(show_offx, show_h + 20));
		}
	}
}

void SpriteMonster::ReCreate_facName_batchlabel()
{
	if (m_facName_batchlabel)
	{
		if (m_facName_batchlabel->getParent() != MapView::getNameNode())
		{
			m_facName_batchlabel->removeFromParent();
			m_facName_batchlabel->release();
			m_facName_batchlabel = nullptr;
		}
	}
	
	if (m_facName_batchlabel == nullptr)
	{
		m_facName_batchlabel = MapView::getNameNode()->createLabel(getFacName().c_str(), 0, getPosition() + Point(show_offx, show_h + 20));
		if (m_facName_batchlabel != nullptr)
		{
			m_facName_batchlabel->retain();
			if (getActorFlag())
				m_facName_batchlabel->setTag(1328);
			m_facName_batchlabel->setLineBreakWithoutSpace(true);
			m_facName_batchlabel->setVisible((isVisible() && (is_show_blood || m_show_name)) || getType() == NPC_TYPE);

			if (isNoActorOrNpc())
				m_facName_batchlabel->setPosition(getPosition() + Point(show_offx, show_h / 3 - 10));
			else
				m_facName_batchlabel->setPosition(getPosition() + Point(show_offx, show_h + 40));
		}
	}
}

void SpriteMonster::ReCreate_titleName_batchlabel()
{
	if (m_titleName_batchlabel)
	{
		if (m_titleName_batchlabel->getParent() != MapView::getNameNode())
		{
			m_titleName_batchlabel->removeFromParent();
			m_titleName_batchlabel->release();
			m_titleName_batchlabel = nullptr;
		}
	}
	
	if (m_titleName_batchlabel == nullptr)
	{
		m_titleName_batchlabel = MapView::getNameNode()->createLabel(getTitleName().c_str(), 0, getPosition() + Point(show_offx, show_h + 20));
		if (m_titleName_batchlabel != nullptr)
		{
			m_titleName_batchlabel->retain();
			if (getActorFlag())
				m_titleName_batchlabel->setTag(1329);
			m_titleName_batchlabel->setLineBreakWithoutSpace(true);
			m_titleName_batchlabel->setVisible((isVisible() && (is_show_blood || m_show_name)) || getType() == NPC_TYPE);

			if (isNoActorOrNpc())
				m_titleName_batchlabel->setPosition(getPosition() + Point(show_offx, show_h / 3 - 10));
			else
				if (this->getFacName().length() > 0)
					m_titleName_batchlabel->setPosition(getPosition() + Point(show_offx, show_h + 60));
				else
					m_titleName_batchlabel->setPosition(getPosition() + Point(show_offx, show_h + 40));
		}
	}
}

void SpriteMonster::onEnter()
{
	SpriteBase::onEnter();

	Node* pBloodNode = MapView::getBloodNode();
	Node* pTitleNode = MapView::getTitleNode();
	Node* pDressNode = MapView::getDressNode();
	Node* pTheDownNode = MapView::getTheDownNode();
	Node* pTheTopNode = MapView::getTheTopNode();
	Node* pSkillNode = MapView::getSkillNode();
	Node* pSkillDownNode = MapView::getSkillDownNode();

	CC_SAFE_ADDMAPNODE(m_blood_bg, pBloodNode);
	CC_SAFE_ADDMAPNODE(m_title_node, pTitleNode);
	CC_SAFE_ADDMAPNODE(m_main_node, pDressNode);
	CC_SAFE_ADDMAPNODE(m_weapon_node, pDressNode);
	CC_SAFE_ADDMAPNODE(m_wing_node, pDressNode);
	CC_SAFE_ADDMAPNODE(m_ride_node, pDressNode);
	CC_SAFE_ADDMAPNODE(m_down_node, pTheDownNode);
	CC_SAFE_ADDMAPNODE(m_top_node, pTheTopNode);
	CC_SAFE_ADDMAPNODE(m_buffskill_node, pDressNode);
	CC_SAFE_ADDMAPNODE(m_skill_node, pSkillNode);
	CC_SAFE_ADDMAPNODE(m_skilldown_node, pSkillDownNode);	

	ReCreate_name_batchlabel();
	ReCreate_facName_batchlabel();
	ReCreate_titleName_batchlabel();
}

void SpriteMonster::onExit()
{
	CC_SAFE_REMOVEFROMPARENT(m_blood_bg);
	CC_SAFE_REMOVEFROMPARENT(m_title_node);
	CC_SAFE_REMOVEFROMPARENT(m_main_node);
	CC_SAFE_REMOVEFROMPARENT(m_weapon_node);
	CC_SAFE_REMOVEFROMPARENT(m_wing_node);
	CC_SAFE_REMOVEFROMPARENT(m_ride_node);
	CC_SAFE_REMOVEFROMPARENT(m_down_node);
	CC_SAFE_REMOVEFROMPARENT(m_top_node);

	if (m_buffskill_node)
	{
		m_buffskill_node->removeFromParentAndCleanup(false);
	}

	//CC_SAFE_REMOVEFROMPARENT(m_buffskill_node);
	CC_SAFE_REMOVEFROMPARENT(m_skill_node);
	CC_SAFE_REMOVEFROMPARENT(m_skilldown_node);

	if (m_name_batchlabel != NULL)
	{
		m_name_batchlabel->removeFromParent();
		m_name_batchlabel->release();
		m_name_batchlabel = NULL;
	}

	if (m_facName_batchlabel != NULL)
	{
		m_facName_batchlabel->removeFromParent();
		m_facName_batchlabel->release();
		m_facName_batchlabel = NULL;
	}

	if (m_titleName_batchlabel != NULL)
	{
		m_titleName_batchlabel->removeFromParent();
		m_titleName_batchlabel->release();
		m_titleName_batchlabel = NULL;
	}


	if(!getActorFlag()&&getType()>=NORMAL_MONSTER)
	{
		int x = ((int)m_tile_point.x)%MAP_TILE_COUNT;
		int y = ((int)m_tile_point.y)%MAP_TILE_COUNT;
		if (x >= 0 && y >= 0)
		{
			ssize_t index = _s_map_tile[x][y].getIndex(this);
			if(index >= 0)
			{
				_s_map_tile[x][y].erase(index);
				if(!getNeedHide() && (_s_map_tile[x][y].size()>=MAX_NUM_ONE_TILE))
				{
					SpriteMonster*find_monster =  _s_map_tile[x][y].at(MAX_NUM_ONE_TILE-1);
					if(find_monster)
						find_monster->setNeedHide(false);
				}
			}
		}
	} 
	SpriteBase::onExit();
}
void SpriteMonster::setVisible(bool isvisible)
{
	Node::setVisible(isvisible);

	if (m_name_batchlabel != NULL)
		m_name_batchlabel->setVisible(isvisible && (is_show_blood || m_show_name));
	if (m_facName_batchlabel != NULL)
		m_facName_batchlabel->setVisible(isvisible && (is_show_blood || m_show_name));
	if (m_titleName_batchlabel != NULL)
		m_titleName_batchlabel->setVisible(isvisible && (is_show_blood || m_show_name));
	if (m_blood_bg != NULL)
		m_blood_bg->setVisible(is_show_blood&&isvisible);
	if (m_title_node != NULL)
	{
		if (getType() < PLAYER_MANE_TYPE)
			m_title_node->setVisible(isvisible);
		else
			m_title_node->setVisible(isvisible&&isAlive());
	}
	if (m_main_node != NULL)
		m_main_node->setVisible(isvisible);
	if (m_weapon_node != NULL)
	{
		//bool is_visible = isvisible&&(!m_onRide||m_isHighRide)&&getCurrActionState()!=ACTION_STATE_DIG&&!m_is_change_display&&(getCurrActionState()!=ACTION_STATE_COLLIDE);
		bool is_visible = isvisible&&(!m_onRide||m_isAttackRide)&&getCurrActionState()!=ACTION_STATE_DIG&&!m_is_change_display;
		m_weapon_node->setVisible(is_visible);
	}
	if (m_wing_node != NULL)
	{
		bool is_visible = isvisible&&is_show_wing&&!m_is_change_display;
		m_wing_node->setVisible(is_visible);
	}
	if(getActorFlag()&&m_top_node!= nullptr)
	{
		int nTag;
		for (auto c_sprite : m_sprites)
		{
			nTag = c_sprite->getTag();
			if(nTag == E_ONTAG_BODY)
				c_sprite->setVisible(!m_is_change_display);
			else if(nTag == E_ONTAG_WEAPON)
				//c_sprite->setVisible(isvisible&&(!m_onRide||m_isHighRide)&&getCurrActionState()!=ACTION_STATE_DIG&&!m_is_change_display&&(getCurrActionState()!=ACTION_STATE_COLLIDE));
				c_sprite->setVisible(isvisible&&(!m_onRide||m_isAttackRide)&&getCurrActionState()!=ACTION_STATE_DIG&&!m_is_change_display);
			else if(nTag == E_ONTAG_WING)
				c_sprite->setVisible(isvisible&&is_show_wing&&!m_is_change_display);
		}
	}
	if (m_ride_node != NULL)
		m_ride_node->setVisible(isvisible);
	if (m_down_node != NULL)
		m_down_node->setVisible(isvisible);
	if (m_top_node != NULL)
		m_top_node->setVisible(isvisible);
	if (m_buffskill_node != NULL)
		m_buffskill_node->setVisible(isvisible&&!m_onRide);
}

void SpriteMonster::visit(Renderer* renderer,const Mat4& parentTransform, uint32_t parentFlags)
{
    // quick return if not visible. children won't be drawn.
	if(!isTree())
	{
		Point n_pos = getParent()->convertToWorldSpace(getPosition());
		const Size& m_win_size =  Director::getInstance()->getWinSize();

		int tmpsh;
		if (main_sprite)
			tmpsh = -main_sprite->getAnchorPointInPoints().y + main_sprite->getOffsetPosition().y + main_sprite->getTextureRect().size.height;
		else
			tmpsh = 0;
		tmpsh = tmpsh > 0 ? tmpsh : 0;
		tmpsh = tmpsh > 150 ? tmpsh*0.5f : tmpsh;

		if ( (m_need_hide && getType() >= PLAYER_MANE_TYPE) 
			|| !Rect(-48,-tmpsh,m_win_size.width+96,m_win_size.height+tmpsh+32).containsPoint(n_pos)
			|| (s_hide_center_rect && Rect((m_win_size.width-960)/2,(m_win_size.height-640)/2,960,640).containsPoint(n_pos)) )
		{
			if (m_name_batchlabel != NULL)
				m_name_batchlabel->setVisible(false);
			if (m_facName_batchlabel != NULL)
				m_facName_batchlabel->setVisible(false);
			if (m_titleName_batchlabel != NULL)
				m_titleName_batchlabel->setVisible(false);
			if (m_blood_bg != NULL)
				m_blood_bg->setVisible(false);
			if (m_title_node != NULL)
				m_title_node->setVisible(false);
			if (m_main_node != NULL)
				m_main_node->setVisible(false);
			if (m_buffskill_node != NULL)
				m_buffskill_node->setVisible(false);
			if (m_weapon_node != NULL)
				m_weapon_node->setVisible(false);
			if (m_wing_node != NULL)
				m_wing_node->setVisible(false);
			if (m_ride_node != NULL)
				m_ride_node->setVisible(false);
			if (m_down_node != NULL)
				m_down_node->setVisible(false);
			if (m_top_node != NULL)
				m_top_node->setVisible(false);

			SpriteBase::visit(renderer, parentTransform, parentFlags);
			return;
		}
	}


	reCalcShowH();

	if (MapView::isShowMonsterPos() && m_name_batchlabel)
	{
		char str[64] = {0};
		sprintf(str, "(%d,%d)", (int)m_tile_point.x, (int)m_tile_point.y);
		m_name_batchlabel->setString(str);
	}

	/*if (MapView::isShowMonsterPos() && m_facName_batchlabel)
	{
		char str[64] = {0};
		sprintf(str, "(%d,%d)", (int)m_tile_point.x, (int)m_tile_point.y);
		m_facName_batchlabel->setString(str);
	}*/
	
	setVisible(isVisible());
	SpriteBase::visit(renderer, parentTransform, parentFlags);
}

void SpriteMonster::reCalcShowH()
{
	if (is_need_resetBloodHeight && !m_is_lock_height)
	{
		if (m_type < PLAYER_MANE_TYPE)
		{
			if (main_sprite && main_sprite->getTextureRect().size.height > 0)
			{
				is_need_resetBloodHeight = false;

				//show_h = -main_sprite->getAnchorPointInPoints().y + main_sprite->getOffsetPosition().y + main_sprite->getTextureRect().size.height + 5;
				int tmpsh = -main_sprite->getAnchorPointInPoints().y + main_sprite->getOffsetPosition().y + main_sprite->getTextureRect().size.height + 5;
				setShow_H(tmpsh);

				resetShowHPosition();
			}
		}
	}
}

void SpriteMonster::resetShowHPosition()
{
	if (m_name_batchlabel != NULL)
	{
		if (getType() == NPC_TYPE)
			m_name_batchlabel->setPosition(getPosition() + Point(show_offx, show_h + 5));
		else if (isNoActorOrNpc())
			m_name_batchlabel->setPosition(getPosition() + Point(show_offx, show_h / 3 - 10));
		else
			m_name_batchlabel->setPosition(getPosition() + Point(show_offx, show_h + 20));
	}

	if (m_facName_batchlabel != NULL)
	{
		if (isNoActorOrNpc())
			m_facName_batchlabel->setPosition(getPosition() + Point(show_offx, show_h / 3 - 10));
		else
			m_facName_batchlabel->setPosition(getPosition() + Point(show_offx, show_h + 40));
	}

	if (m_titleName_batchlabel != NULL)
	{
		if (isNoActorOrNpc())
			m_titleName_batchlabel->setPosition(getPosition() + Point(show_offx, show_h / 3 - 10));
		else
			if (this->getFacName().length() > 0)
				m_titleName_batchlabel->setPosition(getPosition() + Point(show_offx, show_h + 60));
			else
				m_titleName_batchlabel->setPosition(getPosition() + Point(show_offx, show_h + 40));
	}
	
	if (m_blood_bg)
		m_blood_bg->setPosition(getPosition() + Point(show_offx, show_h + 5));

	if (m_title_node)
	{
		if (m_onRide)
		{
			m_title_node->setPosition(getPosition() + Point(show_offx, show_h));
		}
		else
		{
			m_title_node->setPosition(getPosition() + Point(show_offx, show_h));
		}
	}
}


void SpriteMonster::setPosition(const Point& position)
{
	Node::setPosition(position);
}

int _insert_imp(SpriteMonster* pAddMon, int begin, int end, Vector<SpriteMonster*>& vecMapTileMons) 
{
	int curindex = 0;
	bool bAdd = false;
	for (int i = begin; i < end; ++i)
	{
		SpriteMonster* pMon = vecMapTileMons.at(i);
		if (pMon && monsterComparisonLess(pAddMon, pMon))
		{
			vecMapTileMons.insert(i, pAddMon);
			bAdd = true;
			curindex = i;
			break;
		}
	}
	if (!bAdd)
	{
		vecMapTileMons.insert(end, pAddMon);
		curindex = end;
	}

	return curindex;
}

int _insert(SpriteMonster* pAddMon, int begin, int end, Vector<SpriteMonster*>& vecMapTileMons)
{
	int count = end - begin;
	if (count > 32)
	{
		int mid = begin + count / 2;
		SpriteMonster* pMon = vecMapTileMons.at(mid);
		if (pMon && monsterComparisonLess(pAddMon, pMon))
		{
			return _insert(pAddMon, begin, mid, vecMapTileMons);
		}
		else
		{
			return _insert(pAddMon, mid, end, vecMapTileMons);
		}
	}
	else
	{
		return _insert_imp(pAddMon, begin, end, vecMapTileMons);
	}

	return -1;
	
}

void SpriteMonster::setPosition(float x, float y)
{
	Node::setPosition(x,y);

	//if(g_MapView != nullptr)
	//	m_tile_point = g_MapView->space2Tile(Point(x,y));
	//if( MapView::getBloodNode()!=NULL)
	{
		resetShowHPosition();

		if(g_MapView != nullptr)
		{
			Point tile =  g_MapView->space2Tile(Point(x,y));
			if(tile != m_tile_point)
			{
				MapView::setDressNodeReorder();

				if(!getActorFlag()&&getType()>=NORMAL_MONSTER)
				{
					if(m_tile_point!=Point())
					{
						int x = ((int)m_tile_point.x) % MAP_TILE_COUNT;
						int y = ((int)m_tile_point.y) % MAP_TILE_COUNT;
						ssize_t index = _s_map_tile[x][y].getIndex(this);
						if(index >= 0)
						{
							_s_map_tile[x][y].erase(index);
							if(!getNeedHide() && (_s_map_tile[x][y].size()>=MAX_NUM_ONE_TILE))
							{
								SpriteMonster*find_monster =  _s_map_tile[x][y].at(MAX_NUM_ONE_TILE-1);
								if(find_monster)
									find_monster->setNeedHide(false);
							}
						}
					}
					//if(getType() < PLAYER_MANE_TYPE)
					//{
					//	SpriteMonster *role_main = g_MapView->getMainRole();
					//	if(role_main != nullptr)
					//	{
					//		Point r_tile = role_main->getTilePoint();
					//		if(tile == r_tile || (r_tile.x == tile.x && r_tile.y == tile.y + 1) )
					//		{
					//			MirTextNode* name = getNameBatchLabel();
					//			if(name!=nullptr)
					//				name->setOpacity(50);
					//		}
					//		else if(m_tile_point == r_tile || (r_tile.x == m_tile_point.x && r_tile.y == m_tile_point.y + 1) )
					//		{
					//			MirTextNode* name = getNameBatchLabel();
					//			if(name!=nullptr)
					//				name->setOpacity(getOpacity());
					//		}
					//	}
					//}
				}
				//else if(getActorFlag())
				//{
				//	resetHideTile(m_tile_point,tile);
				//}
				m_tile_point = tile;
				if(!getActorFlag()&&getType()>=NORMAL_MONSTER &&(m_main_node != NULL))
				{
					int x = ((int)m_tile_point.x) % MAP_TILE_COUNT;
					int y = ((int)m_tile_point.y) % MAP_TILE_COUNT;

					Vector<SpriteMonster*>& curMapTileVec = _s_map_tile[x][y];
					
					int oldtilesize = curMapTileVec.size();
					int curindex = _insert(this, 0, oldtilesize, curMapTileVec);

					// std::sort(std::begin(_s_map_tile[x][y]), std::end(_s_map_tile[x][y]), monsterComparisonLess);

					int newtilesize = curMapTileVec.size();
					if(newtilesize < MAX_NUM_ONE_TILE)
					{
						setNeedHide(false);
					}
					else
					{
						if(curindex >= MAX_NUM_ONE_TILE)
						{
							setNeedHide(true);
						}
						else if(newtilesize > MAX_NUM_ONE_TILE)
						{
							setNeedHide(false);
							SpriteMonster* find_monster = curMapTileVec.at(MAX_NUM_ONE_TILE);
							if(find_monster)
								find_monster->setNeedHide(true);
						}
						
					}
				}
			}
		}
		if(m_main_node!=NULL)
		{
			m_main_node->setPosition(x,y);	
			m_main_node->setTilePoint(m_tile_point);
		}
		//if(m_head_node!=NULL)
		//	m_head_node->setPosition(x,y);	
		if(m_weapon_node!=NULL)
		{
			m_weapon_node->setPosition(x,y);
			m_weapon_node->setTilePoint(m_tile_point);
		}
		if(m_wing_node!=NULL)
		{
			m_wing_node->setPosition(x,y);
			m_wing_node->setTilePoint(m_tile_point);
		}
		if(m_ride_node!=NULL)
		{
			if(!m_isHighRide)
				m_ride_node->setPosition(x,y);
			else
				m_ride_node->setPosition(x,y+20);
			m_ride_node->setTilePoint(m_tile_point);
		}
		if(m_down_node!=NULL)
			m_down_node->setPosition(x,y);
		if(m_top_node!=NULL)
			m_top_node->setPosition(x,y);
		if(m_skill_node!=NULL)
			m_skill_node->setPosition(x,y);
		if(m_skilldown_node!=NULL)
			m_skilldown_node->setPosition(x,y);
		if(m_buffskill_node!=NULL)
		{
			m_buffskill_node->setPosition(x,y);
			m_buffskill_node->setTilePoint(m_tile_point);
		}
	}
}

void SpriteMonster::setHP(int hp)
{
	if(getActorFlag()&&m_hp<=0 && hp > 0)
	{
		standed();

		//FiniteTimeAction* dostand = CallFunc::create([&]()
		//{
		//	if (getHP() > 0 )
		//	{
		//		standed();
		//	}
		//	else
		//	{
		//		CCLOGWIN32("[SpriteMonster::setHP] <= 0 standed");
		//	}
		//	
		//});
		//runAction(Sequence::create(DelayTime::create(0.05),dostand,NULL));
	}
	m_hp = hp;

	float pro = 1.0f;

	if (m_hp <= 0)
	{
		m_hp = 0;
		pro = 0.0f;
		showNameAndBlood_imp(false);
	}
	else if (m_hp < m_maxhp && m_hp > 0)
	{
		showNameAndBlood_imp(true);

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

void SpriteMonster::setFacName(std::string facName)
{
	if (facName != "")
	{
		m_facName = facName;
	}
	else
	{
		m_facName = "";
	}
}

void SpriteMonster::setTitleName(std::string titleName)
{
	if (titleName != "")
	{
		m_titleName = titleName;
	}
	else
	{
		m_titleName = "";
	}
}

void SpriteMonster::subBlood(int blood)
{
	m_hp -= blood;
	//sub_pecent = ((float)10 * blood) / m_maxhp;
	if (m_hp <= 0)
	{
		update_pecent = 0;
		m_hp = 0;
		showNameAndBlood_imp(false);
	}
	else
	{
		update_pecent = 100;
		if (m_maxhp > 0)
			update_pecent = ((float)m_hp / m_maxhp) * 100;
		if (update_pecent > 100)
			update_pecent = 100;

		showNameAndBlood_imp(true);		
	}

	if (m_blood_pro != NULL && m_blood_bg != NULL)
	{
		float fBloodWidth = (float)update_pecent * 47 / 100;
		if (m_hp > 0 && fBloodWidth < 2.0f) // HP>0 至少显示一点红色进度
			fBloodWidth = 2.0f;

		m_blood_pro->setTextureRect(Rect(0, 0, fBloodWidth, 9));
	}
}

void SpriteMonster::hasHurted(float delay,float times)
{
	if(changeState(ACTION_STATE_HURT))
	{
		FiniteTimeAction* start = CallFunc::create([&](){ setWrite(true);});
		FiniteTimeAction* ended = CallFunc::create([&](){ setWrite(false);});
		getMainNode()->runAction(Sequence::create(DelayTime::create(delay),start,DelayTime::create(times),ended,NULL));
	}
}


void SpriteMonster::initOrderByDir(SpriteBase* c_sprite,Commen_Direction dir)
{
	SpriteType s_type = c_sprite->getType();
	if(s_type == WUQI_TYPE || s_type == HOE_TYPE)
	{
		if( m_weapon_node !=NULL )
		{
			if((!get5DirMode() && (dir == dir_left||dir == dir_left_up||dir == dir_left_down))||dir == dir_up)
			{
				int order = m_weapon_node->getLocalZOrder();
				if(order > 12000000)
				{
					m_weapon_node->setLocalZOrder(order-12000000);
					MapView::setDressNodeReorder();

					if(getActorFlag()&&m_top_node!= nullptr)
					{
						SpriteBase * weapon_sp = getOpacityNodeByTag(E_ONTAG_WEAPON);
						if(weapon_sp!=nullptr)
						{
							weapon_sp->setLocalZOrder(127);
						}
					}
				}
			}
			else
			{
				int order = m_weapon_node->getLocalZOrder();
				if(order < 12000000)
				{
					m_weapon_node->setLocalZOrder(order+12000000);
					MapView::setDressNodeReorder();

					if(getActorFlag()&&m_top_node!= nullptr)
					{
						SpriteBase * weapon_sp = getOpacityNodeByTag(E_ONTAG_WEAPON);
						if(weapon_sp!=nullptr)
						{
							weapon_sp->setLocalZOrder(129);
						}
					}
				}
			}
		}
	}
	else if(s_type == WING_TYPE )
	{
		if((getCurrActionState()!=ACTION_STATE_DIG)&&(dir == dir_left_down||dir == dir_right_down||dir == dir_down|| ( (dir == dir_right || dir == dir_left) &&(getCurrActionState()==ACTION_STATE_ATTACK||getCurrActionState()==ACTION_STATE_MAGICUP) ) ))
		{
			if( m_wing_node != NULL )
			{
				int order = m_wing_node->getLocalZOrder();
				if(order > 22000000)
				{
					m_wing_node->setLocalZOrder(order-22000000);
					MapView::setDressNodeReorder();

					//if(getActorFlag())
					//{
					//	SpriteBase *child = (SpriteBase *)m_wing_node->getChildByTag(ADD_WING_TYPE);
					//	if(child!=nullptr)
					//	{
					//		child->getMainSprite()->setReDraw(false);
					//	}
					//}
				}
				if(getActorFlag()&&m_top_node!= nullptr)
				{
					GLubyte op = 0;
					if(getOnRide())
						op = 0;
					SpriteBase * wing_sp = getOpacityNodeByTag(E_ONTAG_WING);
					if(wing_sp!=nullptr)
					{
						wing_sp->setOpacity(op);
						wing_sp->setLocalZOrder(126);
					}
				}
			}
		}
		else
		{
			if( m_wing_node != NULL )
			{
				int order = m_wing_node->getLocalZOrder();
				if(order < 22000000)
				{
					m_wing_node->setLocalZOrder(order+22000000);
					MapView::setDressNodeReorder();

					//if(getActorFlag())
					//{
					//	SpriteBase *child = (SpriteBase *)m_wing_node->getChildByTag(ADD_WING_TYPE);
					//	if(child!=nullptr)
					//	{
					//		child->getMainSprite()->setReDraw(true);
					//	}
					//}
					if(getActorFlag()&&m_top_node!= nullptr)
					{
						SpriteBase * wing_sp = getOpacityNodeByTag(E_ONTAG_WING);
						if(wing_sp!=nullptr)
						{
							wing_sp->setOpacity(m_set_opacity_num);
							wing_sp->setLocalZOrder(130);
						}
					}
				}
			}
		}
	}
	else if (s_type == RIDE_TYPE_UP)
	{
		if (m_ride_node)
		{
			SpriteBase* ride_sprite = (SpriteBase *)m_ride_node->getChildByTag(ADD_RIDE_TYPE);
			if (ride_sprite && ride_sprite->getResId() == 1026)
			{
				if (dir != dir_down)
				{
					int order = m_ride_node->getLocalZOrder();
					if(order > 32000000)
					{
						m_ride_node->setLocalZOrder(order-32000000);
						MapView::setDressNodeReorder();

						if(getActorFlag()&&m_top_node!= nullptr)
						{
							SpriteBase * ride_sp = getOpacityNodeByTag(E_ONTAG_RIDE);
							if(ride_sp!=nullptr)
							{
								ride_sp->setLocalZOrder(125);
							}
						}
					}
				}
				else
				{
					int order = m_ride_node->getLocalZOrder();
					if(order < 32000000)
					{
						m_ride_node->setLocalZOrder(order+32000000);
						MapView::setDressNodeReorder();

						if(getActorFlag()&&m_top_node!= nullptr)
						{
							SpriteBase * ride_sp = getOpacityNodeByTag(E_ONTAG_RIDE);
							if(ride_sp!=nullptr)
							{
								ride_sp->setLocalZOrder(131);
							}
						}
					}
				}
			}
		}
	}
}


void SpriteMonster::setWingNodeVisble(bool isvisible)
{
	if( m_wing_node != NULL )
	{
		m_wing_node->setVisible(isvisible);
	}
	is_show_wing = isvisible;
}

SpriteBase* SpriteMonster::getOpacityNodeByTag(int tag)
{
	for (auto c_sprite : m_sprites)
	{
		if(c_sprite->getTag() == tag)
			return c_sprite;
	}
	return nullptr;
}

void SpriteMonster::onRetain()
{
	removeFromParent();
}


void SpriteMonster::onRestore()
{
	if (m_skilldown_node != nullptr)
	{
		m_skilldown_node->removeAllChildren();
	}
	if (m_skill_node != nullptr)
	{
		m_skill_node->removeAllChildren();
	}
}

