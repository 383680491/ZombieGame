//#include "MapView.h"
#include "FindPath.h"
#include "sprites/SpriteMonster.h"
//#include "effects/MagicCtrlMgr.h"
#include "common/MakeNumbers.h"
//#include "socket/LuaMsgBuffer.h"
//#include "socket/LuaSocket.h"
#include "CCLuaEngine.h"
//#include "effects/FlyAction.h"
//#include "pbc/pbc.h"

USING_NS_CC;

// -------------------------------------------------------------
static int lastsendx = -1,lastsendy = -1;
static int errormove = 0;
static int errorlastx = -1,errorlasty = -1;
static int errorsendx = -1,errorsendy = -1;
// -------------------------------------------------------------

unsigned short maxlock_num = 5;
MapView* g_MapView = nullptr;
static struct _DisplayNode *DisplayMap = NULL;
static bool s_show_hurt = true;

void MapView::resetShowHurt(bool visible)  
{
	s_show_hurt = visible;
}
//static	std::mutex _infoMutex;

//static	std::mutex _textureinfoMutex;

//static SortNode* head_node = NULL;


//static std::vector<LuaMsgData*> s_lua_msgs;


//void MapView::DoPushLuaMsg(LuaMsgData *data)  
//{
//	if(data != nullptr)
//		s_lua_msgs.push_back(data);
//	if(s_lua_msgs.size() >= 64)
//		MapView::DoPopLuaMsgs();
//}
//
//void MapView::DoPopLuaMsgs()  
//{
//	if(!s_lua_msgs.empty())
//	{
//		int num = s_lua_msgs.size();
//		CLuaParam luaParams[128];
//		luaParams[0] = num;
//		for(int i=0;i<num;i++)
//			luaParams[i + 1] = static_cast<void*>(&s_lua_msgs[i]->pbuff);
//		LuaSocket::getInstance()->runLuaFunc("g_NetMsgDispacher", luaParams, num+1);
//
//		for (auto msg : s_lua_msgs) {			
//			CC_SAFE_DELETE(msg);
//			
//		}
//		s_lua_msgs.clear();
//	}
//}
//
//
//void CheckMsgs(int objid)  
//{
//	bool need_do = false;
//	if(!s_lua_msgs.empty())
//	{
//		for (auto msg : s_lua_msgs) {
//			if (msg->msgId == 1010 && objid == msg->objId )
//			{
//				need_do = true;
//			}
//		}
//	}
//	if(need_do)
//	{
//		MapView::DoPopLuaMsgs();
//	}
//}


Node* MapView::getBloodNode()
{
	if (g_MapView)
		return g_MapView->blood_node;
	return nullptr;
}
void MapView::resetBloodNode()  
{
	//wing_down_node = NULL;
	//wing_up_node = NULL;
	//weapon_down_node = NULL;
	//weapon_up_node = NULL;
	//head_node = NULL;
}

MirBatchDrawLabel* MapView::getNameNode()
{
	if (g_MapView)
		return g_MapView->s_name_node;
	return nullptr;
}
//SortNode*MapView::getHeadNode()  
//{
//	return head_node;
//}
//SortNode*MapView::getRideNode()  
//{
//	return dress_node;
//}
Node* MapView::getTitleNode()
{
	if (g_MapView)
		return g_MapView->title_node;
	return nullptr;
}
SortNode* MapView::getDressNode()
{
	if (g_MapView)
		return g_MapView->dress_node;
	return nullptr;
}

void MapView::setDressNodeReorder()
{
	if (g_MapView && g_MapView->dress_node)
		g_MapView->dress_node->setReorder();
}

//SortNode*MapView::getWingDownNode()  
//{
//	return dress_node;
//}
//Node*MapView::getWingUpNode()  
//{
//	return dress_node;
//}
Node* MapView::getTheTopNode()
{
	if (g_MapView)
		return g_MapView->top_node;
	return nullptr;
}
Node* MapView::getTheDownNode()
{
	if (g_MapView)
		return g_MapView->down_node;
	return nullptr;
}
Node* MapView::getSkillNode()
{
	if (g_MapView)
		return g_MapView->s_skill_node;
	return nullptr;
}
Node* MapView::getSkillDownNode()
{
	if (g_MapView)
		return g_MapView->s_skill_downnode;
	return nullptr;
}
//Node*MapView::getWeaponUpNode()  
//{
//	return dress_node;
//}
//SortNode*MapView::getWeaponDownNode()  
//{
//	return dress_node;
//}


























MapView::MapView()
: m_pMap(nullptr)
, m_item_node(nullptr)
, m_hit_node(nullptr)
, title_node(nullptr)
, s_skill_node(nullptr)
, down_node(nullptr)
, s_skill_downnode(nullptr)
, top_node(nullptr)
, blood_node(nullptr)
, dress_node(nullptr)
, s_name_node(nullptr)
, m_isNewMap(true)
, waitpos_count(0)
//, _mapNode(nullptr)
{
	AStarPath = NULL;
	AStarMap = NULL;
	AStarMap2 = NULL;
	//m_effect = NULL;
	map_speed = 0;
	addmovespeed = 0;
	m_rocker_dir = dir_undef;
	role_main = NULL;
	m_walk_cb = 0;
	m_rock_cb = 0;
	m_hurt_cb = 0;
	m_touch_move_cb = 0;
	_m_time = 0;
	_m_rock_time = 0;
	_m_rock_time_ex = 0;
	m_mapId = 0;
	move_speed = SPEED;
	m_dir = dir_undef;
	is_act_map = true;
	islock_num = 0;
	set_rock = false;
	attack_flag = false;
	//load_Thread = NULL;
	m_touch_tile = Point(0,0);
	_move_end_tile = Point(0,0);
	server_pos = Point(0,0);
	_isnear_ = false;
	loadall = false;
	last_dir = dir_undef;
	//_infoMutex.lock();
	while (DisplayMap != NULL)
	{
		struct _DisplayNode* pNode = DisplayMap;
		DisplayMap = DisplayMap->Next;
		delete(pNode);
	}
	DisplayMap = NULL;
	MapView::resetBloodNode();
	mapstr.clear();
	//_infoMutex.unlock();


	g_MapView = this;
}

MapView::~MapView()
{
	//if(load_Thread)
	//{
	//	if(load_Thread->joinable())
	//		load_Thread->join();
	//	delete load_Thread;
	//	load_Thread = NULL;
	//}

	//assert(g_MapView == this);

	AStarPath = nullptr;
	if (g_MapView == this)
		g_MapView = nullptr;

	m_block_str.clear();
	if(AStarMap != NULL)
	{
		free(AStarMap);
		AStarMap = NULL;
	}
	if(AStarMap2 != NULL)
	{
		free(AStarMap2);
		AStarMap2 = NULL;
	}
	m_pMap = NULL;
	//_mapNode = NULL;
	m_item_node = NULL;
	//_infoMutex.lock();
	while (DisplayMap != NULL)
	{
		struct _DisplayNode* pNode = DisplayMap;
		DisplayMap = DisplayMap->Next;
		delete(pNode);
	}
	DisplayMap = NULL;
	MapView::resetBloodNode();
	mapstr.clear();
	removeWalkCb();
	removeRockerCb();
	removeTouchMoveCb();
	removeHurtCb();
	role_main = nullptr;
	SpriteMonster::clearMapTile();
}

bool MapView::loadMapNew(const std::string& filename, const  int mapId, const Point mpos)
{
	m_mapId = mapId;
	m_isNewMap = true;
	//_mapNode = nullptr;
	m_block_str.clear();

	if (!filename.empty() && FileUtils::getInstance()->isFileExist(filename))
	{
		// 地图节点
		cocos2d::experimental::TMXTiledMap * _tmxMap = cocos2d::experimental::TMXTiledMap::create(filename);
		if (_tmxMap)
		{
			m_mapSize = _tmxMap->getMapSize();
			m_perTileSize = _tmxMap->getTileSize();

			_tmxMap->setExtFatSize(m_perTileSize);

			_tmxMap->setLoadSpriteFrameFunction([](const std::string & imgName, int32_t) { return MapSimpleResLoadMgr::getInstance()->getSpriteFrameByImgName(imgName); });

			_tmxMap->setFixArtifactsByStrechingTexel(true);

			_tmxMap->setAnchorPoint(Point::ZERO);
			_tmxMap->setPosition(Point::ZERO);

			/*
			将 alpha 层和 block 层中的数据读取到游戏后将其移除降低内存占用
			*/
			cocos2d::experimental::TMXLayer * pBolckLayer = _tmxMap->getLayer("block");
			cocos2d::experimental::TMXLayer * pAlphaLayer = _tmxMap->getLayer("alpha");

			int sizeHint = 0;
			int sizeHintAlpha = 0;
			int sizeHintBlock = 0;

			if (pAlphaLayer)
			{
				Size s = pAlphaLayer->getLayerSize();
				sizeHintAlpha = s.width * s.height;
			}

			if (pBolckLayer)
			{
				Size s = pBolckLayer->getLayerSize();
				sizeHintBlock = s.width * s.height;
			}
			else
			{
				Size s = _tmxMap->getMapSize();
				sizeHintBlock = s.width * s.height;
			}

			sizeHint = max(sizeHintAlpha, sizeHintBlock);
			if (sizeHint > 0)
				m_block_str.resize(sizeHint, '0');

			if (pAlphaLayer)
			{
				const uint32_t* tiles = pAlphaLayer->getTiles();

				for (int ib = 0; ib < sizeHintAlpha; ++ib)
				{
					if (tiles[ib] != 0)
					{
						m_block_str[ib] = '2';
					}
				}
			}
			if (pBolckLayer)
			{
				const uint32_t* tiles = pBolckLayer->getTiles();

				for (int ib = 0; ib < sizeHintBlock; ++ib)
				{
					if (tiles[ib] != 0)
					{
						m_block_str[ib] = '1';
					}
				}
			}


			//FileUtils::getInstance()->writeStringToFile(m_block_str, "res/mapnew/a.txt");

			_tmxMap->removeLayer("alpha");
			_tmxMap->removeLayer("block");

			Size mapSize = m_mapSize;
			mapSize.width *= m_perTileSize.width;
			mapSize.height *= m_perTileSize.height;

			_tmxMap->setPosition(0, mapSize.height - m_perTileSize.height);

			Node * _mapNode = Node::create();
			_mapNode->addChild(_tmxMap);
			addChild(_mapNode);
		}
	}
	else
	{
		m_perTileSize = Size(48, 32);
		m_mapSize = Size(400, 400);
		m_block_str.resize(m_mapSize.width*m_mapSize.height, '0');
	}

	return loadMap_imp(filename, mapId, mpos);
}

bool MapView::loadMap_imp(const std::string& filename, const  int mapId, const Point mpos)
{
	m_mapId = mapId;
	role_pos = mpos;
	start_tile = mpos;

	m_pMap = Node::create();//TMXTiledMap::create(filename);
	if (m_pMap)
	{
		addChild(m_pMap);
	}

	m_winSize = Director::getInstance()->getWinSize();

	m_item_node = Node::create();
	addChild(m_item_node, 4, 316);

	dress_node = SortNode::create();
	dress_node->setPosition(0, 0);
	addChild(dress_node, 7);
	//dress_node->setVisible(false);

	top_node = Node::create();
	top_node->setPosition(0, 0);
	addChild(top_node, 11);

	s_skill_node = Node::create();
	s_skill_node->setPosition(0, 0);
	addChild(s_skill_node, 10);

	blood_node = SortNode::create();
	blood_node->setPosition(0, 0);
	blood_node->setNeedSort(false);
	addChild(blood_node, 10);
	//blood_node->setVisible(false);

	TTFConfig lab_ttf;
	lab_ttf.fontFilePath = "fonts/msyh.ttf";
	lab_ttf.fontSize = 16;
	lab_ttf.outlineSize = 1;
	s_name_node = MirBatchDrawLabel::createWithTTF(lab_ttf);
	s_name_node->setPosition(Point(0, 0));
	addChild(s_name_node, 10);

	title_node = Node::create();
	title_node->setPosition(0, 0);
	addChild(title_node, 10);
	//title_node->setVisible(false);
	//ride_node = SortNode::create();
	//ride_node->setPosition(0,0);
	//addChild(ride_node,5);

	down_node = Node::create();
	down_node->setPosition(0, 0);
	addChild(down_node, 3);

	s_skill_downnode = Node::create();
	s_skill_downnode->setPosition(0, 0);
	addChild(s_skill_downnode, 3);

	auto pot = filename.find_last_of('.');
	mapstr = filename;
	mapstr.replace(pot, 4, "/");

	float scale = Director::getInstance()->getMapScale();
	//setScale(scale);
	setScale(1);
	scale = 1;

	/*Point space = CC_POINT_PIXELS_TO_POINTS(tile2Space(role_pos));
	Point pos = (Point(m_winSize.width / 2, m_winSize.height / 2) - space)*scale;
	Point edgeSize = Point(m_mapSize.width*m_perTileSize.width - m_winSize.width, m_mapSize.height*m_perTileSize.height - m_winSize.height)*scale;
	Point edgeSize1 = Point(m_winSize.width, m_winSize.height)*(scale - 1) / 2;
	edgeSize = edgeSize + edgeSize1;
	if (pos.x >  edgeSize1.x) pos.x = edgeSize1.x;
	if (pos.y >  edgeSize1.y) pos.y = edgeSize1.y;
	if (pos.x < -edgeSize.x) pos.x = -edgeSize.x;
	if (pos.y < -edgeSize.y) pos.y = -edgeSize.y;
	setPosition(pos);*/

	auto dispatcher = Director::getInstance()->getEventDispatcher();
	auto myListener = EventListenerTouchOneByOne::create();

	//如果不加入此句消息依旧会向下传递
	myListener->setSwallowTouches(true);

	myListener->onTouchBegan = [=](Touch* touch, Event* event)
	{
		this->stopRocker();
		return true;
	};

	myListener->onTouchMoved = [=](Touch* touch, Event* event)
	{
	};

	myListener->onTouchEnded = [=](Touch* touch, Event* event)
	{
		Point start = touch->getStartLocation();
		Point dest = touch->getLocation();
		Point span = dest - start;
		Point tile = screen2Tile(dest);
		if (dest.getDistance(start) < 30 && !isBlock(tile) && role_main != NULL&&role_main->getCurrActionState() <= ACTION_STATE_CREATE)
		{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
			printf("getCurrMemory = [%d]\r\n", Device::getPss());
#endif
			playStandEffect(tile2Space(tile));
			//if(m_rocker_dir >= dir_undef || set_rock)
			{
				m_touch_tile = tile;
				m_rocker_dir = dir_undef;
				if (AStarPath == NULL && role_main != NULL && role_main->getCurrActionState() == ActionState::ACTION_STATE_IDLE)
					_m_time = move_speed;
				AStarPath = NULL;
			}
		}
		else if (abs(span.x)<80 && abs(span.y)>50 && m_touch_move_cb>0)
		{
			LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
			if (pStack != NULL)
			{
				pStack->pushBoolean(span.y > 0);
				pStack->executeFunctionByHandler(m_touch_move_cb, 1);
				pStack->clean();
			}
		}
	};

	//dispatcher->addEventListenerWithSceneGraphPriority(myListener, this);
	//scheduleUpdate();
	//FiniteTimeAction* actbackfun = CallFunc::create([&](){ update(0.01);});
	//runAction(RepeatForever::create(Sequence::create(DelayTime::create(0.01),actbackfun,NULL)));
	//schedule(schedule_selector(MapView::update), 0.05);
	return true;

}

bool MapView::isBlock(Point tile)
{
	if ((tile.x >= m_mapSize.width || tile.y >= m_mapSize.height || tile.x<0 || tile.y<0) || (tile.x == 0 && tile.y == 0))
		return true;
	int x = tile.x;
	int y = tile.y;
	return (m_block_str.at(y*int(m_mapSize.width) + x) == '1');
}

Point MapView::tile2Space(Point tile)
{
	int sx = (tile.x + 0.5) * m_perTileSize.width;
	int sy = (m_mapSize.height - (tile.y + 0.5))* m_perTileSize.height;
	return Point(sx, sy);
}

Point MapView::space2Tile(Point pos)
{
	int ty = m_mapSize.height - ceil(pos.y / m_perTileSize.height);
	int tx = floor(pos.x / m_perTileSize.width);
	return Point(tx, ty);
}






























bool MapView::isHasAllLoaded()
{
	return AStarMap != NULL;
}

/*void MapView::onMsgHandler(int idx)
{
	if (g_MapView == nullptr)
		return;

	LuaMsgBuffer* pBuff = LuaSocket::getInstance()->getCurrectRunMsg(idx);
	if (pBuff == nullptr)
	{
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
		CCLOG("[MapView::onMsgHandler] error index: %d", idx);
#endif
		return;
	}

	int msgid = pBuff->getMsgId();

	switch (msgid)
	{
	case 1014:
		g_MapView->onDoMove_pbcBuffer(*pBuff);
		break;
	case 1039:
		g_MapView->onDoMove_netBuffer(*pBuff);
		break;
	case 1040:
		g_MapView->onDoMove_netBuffer2(*pBuff);
		break;
	case 3000:
		g_MapView->onPlaySkill_pbcBuffer(*pBuff);
		break;
	case 3023:
		g_MapView->onPlaySkill_netBuffer(*pBuff);
		break;
	case 3024:
		g_MapView->onPlaySkill_netBuffer2(*pBuff);
		break;
	case 3012:
		g_MapView->onCrash(*pBuff);
		break;
	case 3002:
		g_MapView->onShowHurt(*pBuff);
		break;
	case 3020:
		g_MapView->onSkillMove(*pBuff);
		break;
	case 1034:
		g_MapView->onMoveFailed(*pBuff);
		break;
	default:
		break;
	}
}*/

/*void MapView::onMoveFailed(LuaMsgBuffer& pBuff)
{
	LuaSocket::getInstance()->clearMoveDt();

	if(role_main == nullptr)
		return;
	struct pbc_slice slice;
	slice.buffer = (void*)pBuff.getMsgBody();
	slice.len = pBuff.getMsgBodyLen();
	struct pbc_rmessage * m = pbc_rmessage_new(g_registerEnv, "FrameMoveFailedProtocol", &slice);
	if (m == NULL) {
		return;
	}
	short pos_x =  (short)pbc_rmessage_integer(m , "curX" , 0 , NULL);
	short pos_y =  (short)pbc_rmessage_integer(m , "curY" , 0 , NULL);
	pbc_rmessage_delete(m);
	if(!isStoryMap(m_mapId) && role_main->getCurrActionState()< ACTION_STATE_CREATE)
	{
		lastsendx = pos_x;
		lastsendy = pos_y;

		waitpoint.clear();
		waitpos_count = 0;
		islock_num = 0;

		server_pos = Point(pos_x,pos_y);
		role_main->setServerTile(server_pos);
		if(start_tile != server_pos)
		{
			CCLOG("domove failed: -> pos_x:%d -> pos_y:%d",(int)server_pos.x,(int)server_pos.y);
			role_main->stopAllActions();
			role_main->clearServerPoints();
			role_main->setPosition(tile2Space(server_pos));
			role_main->standed();
			scroll2Tile(server_pos);
			last_dir = dir_undef;
			if(AStarPath != NULL)
			{
				Point end_pos = Point();
				while(AStarPath->Next!= NULL)
				{
					AStarPath = AStarPath->Next;
					end_pos = Point(AStarPath->X,AStarPath->Y);
				}
				if(end_pos!=Point())
					moveMapByPosEx(end_pos,false);
			}
			dir_next_tile = server_pos;
			
			if(m_rock_cb>0)
			{
				LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
				if (pStack != NULL)
				{
					pStack->pushInt(pos_x);
					pStack->pushInt(pos_y);
					pStack->executeFunctionByHandler(m_rock_cb, 2);
					pStack->clean();
				}
			}
		}

	}
}*/

/*void MapView::onDoMove_netBuffer(LuaMsgBuffer& pBuff)
{
	int objId =  pBuff.popInt();
	short pos_x =  (unsigned char)pBuff.popChar();
	short pos_y =  (unsigned char)pBuff.popChar();

	onDoMove(objId, pos_x, pos_y);
}

void MapView::onDoMove_netBuffer2(LuaMsgBuffer& pBuff)
{
	int objId =  pBuff.popInt();
	short pos_x =  pBuff.popShort();
	short pos_y =  pBuff.popShort();

	onDoMove(objId, pos_x, pos_y);
}

void MapView::onDoMove_pbcBuffer(LuaMsgBuffer& pBuff)
{
	if(role_main == nullptr)
		return;
	struct pbc_slice slice;
	slice.buffer = (void*)pBuff.getMsgBody();
	slice.len = pBuff.getMsgBodyLen();
	struct pbc_rmessage * m = pbc_rmessage_new(g_registerEnv, "FrameMoveToRetProtocol", &slice);
	if (m == NULL) {
		return;
	}
	int objId =  pbc_rmessage_integer(m , "id" , 0 , NULL);
	short pos_x =  (short)pbc_rmessage_integer(m , "x" , 0 , NULL);
	short pos_y =  (short)pbc_rmessage_integer(m , "y" , 0 , NULL);
	char dir =  (char)pbc_rmessage_integer(m , "dir" , 0 , NULL);

	pbc_rmessage_delete(m);

	onDoMove(objId, pos_x, pos_y);
}
*/
void MapView::onDoMove(int objId, short pos_x, short pos_y)
{
	if(role_main == nullptr)
		return;
	
	if(role_main->getTag() == objId)
	{
		//static unsigned int last =  GetTickCount();
		//unsigned int cur = GetTickCount();

		//CCLOG("[MapView::onDoMove] %u", cur - last );

		//last = cur;

		//LuaSocket::getInstance()->clearMoveDt();

		Director* pDirector = Director::getInstance();
		if (pDirector && pDirector->isDisplayStats() && pDirector->getDisplayType() == 100)
		{
			if (!waitpoint.empty())
				waitpoint.erase(waitpoint.begin());
		}
		if (waitpos_count > 0)
			--waitpos_count;

		moveLock(false);

		if(server_pos != Point(pos_x,pos_y))
		{
			server_pos = Point(pos_x,pos_y);
			role_main->setServerTile(server_pos);
			
			if(m_rock_cb>0)
			{
				LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
				if (pStack != NULL)
				{
					pStack->pushInt(pos_x);
					pStack->pushInt(pos_y);
					pStack->executeFunctionByHandler(m_rock_cb, 2);
					pStack->clean();
				}
			}
		}
	}
	else
	{
		//log("objid:%d -> pos_x:%d -> pos_y:%d",objId,pos_x,pos_y);
		if(m_item_node != nullptr)
		{
			SpriteMonster *r_node = dynamic_cast<SpriteMonster *>(m_item_node->getChildByTag(objId));
			if((r_node != nullptr) && r_node->isAlive())
			{
				//if(isBlock(Point(pos_x,pos_y)))
				//{
				//	return;
				//}
				Point server_tile = r_node->getServerTile();
				if(server_tile != Point(pos_x,pos_y) )
				{
					r_node->setServerTile( Point(pos_x,pos_y));
					if(r_node->hasServerPoints())
					{
						action_queue temp_p;
						temp_p.q_type = ACTION_MOVE_TYPE;
						temp_p.pos = Point(pos_x,pos_y);
						r_node->insertServerPoint(temp_p);
					}
					else
					{
						action_queue temp_p;
						temp_p.q_type = ACTION_MOVE_TYPE;
						temp_p.pos = Point(pos_x,pos_y);
						r_node->insertServerPoint(temp_p);
						onDelayMove(r_node,Point(pos_x,pos_y)); 
					}
				}
			}
		}
	}
}

void MapView::onDelayMove(SpriteMonster*r_node,Point start_point)
{
	if(m_item_node != nullptr)
	{
		if((r_node != nullptr) && r_node->isAlive())
		{
			int objId = r_node->getTag();
			char dir = 0;
			double mo_speed = move_speed;

			mo_speed = r_node->getSpeed();
			Point now_pos = r_node->getPosition();
			Point now_tile = space2Tile(now_pos);
			if(now_tile == start_point) 
			{
				r_node->removeServerPoint();
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
				r_node->removeServerPoint();
				r_node->doSetOpacity();
				return;
			}
			else if(distance>1.5)
			{
				int absx = abs(start_point.x-now_tile.x);
				int absy = abs(start_point.y-now_tile.y);
				int min_abs = min(absx,absy);
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
			if(r_node->getSeverPointsNum()==1)
				move_time = _movespeed*1.1;
			else
			{
				float speedup = getSpeedUp(r_node)/2;
				move_time = _movespeed/(1+speedup);
			}
			if(r_node->getType() < PLAYER_MANE_TYPE)
			{
				if(!r_node->walkInTheDir_ex(move_time,dest_pos,(Commen_Direction)dir))
				{
					FiniteTimeAction* doset = CallFunc::create(CC_CALLBACK_0(SpriteMonster::doSetOpacity,r_node));
					r_node->runAction( Sequence::create(DelayTime::create(0.1f),doset,NULL));
				}
			}
			else
			{
				if(!((SpritePlayer *)r_node)->moveInTheDir_ex(_movespeed,tile2Space(start_point),(Commen_Direction)dir,move_time))
				{
					FiniteTimeAction* doset = CallFunc::create(CC_CALLBACK_0(SpriteMonster::doSetOpacity,r_node));
					r_node->runAction( Sequence::create(DelayTime::create(0.1f),doset,NULL));
				}
			}
		}
	}
}

// 位移类 非普通技能
/*bool MapView::IsCommonSkill(int skillId)
{
	bool isComm = true;

	int rootD = CMagicCtrlMgr::getInstance()->GetMagicRootD3(skillId);
	if(rootD != -1)
	{
		// 十位：技能归类 MAGIC_DEFINE_TYPE
		int iMagicType = rootD/10;
		if(iMagicType == MAGIC_TYPE_DISPLACEMENT)
			return false;
	}

	return true;
}*/

/*void MapView::onPlaySkill_netBuffer(LuaMsgBuffer& pBuff)
{
	if(role_main == nullptr)
		return;

	int objId = pBuff.popInt();
	int tarId = pBuff.popInt();
	int skill_id = (unsigned short)pBuff.popShort();
	int pos_x = (unsigned char)pBuff.popChar();
	int pos_y = (unsigned char)pBuff.popChar();
	int skilLevel = (unsigned char)pBuff.popChar();

	int skillColor = 0;
	if (!pBuff.eof())
		skillColor = (unsigned char)pBuff.popChar();

	onPlaySkill(objId, tarId, skill_id, pos_x, pos_y, skilLevel, skillColor);
}

void MapView::onPlaySkill_netBuffer2(LuaMsgBuffer& pBuff)
{
	if(role_main == nullptr)
		return;

	int objId = pBuff.popInt();
	int tarId = pBuff.popInt();
	int skill_id = (unsigned short)pBuff.popShort();
	int pos_x = pBuff.popShort();
	int pos_y = pBuff.popShort();
	int skilLevel = (unsigned char)pBuff.popChar();

	int skillColor = 0;
	if (!pBuff.eof())
		skillColor = (unsigned char)pBuff.popChar();

	onPlaySkill(objId, tarId, skill_id, pos_x, pos_y, skilLevel, skillColor);
}

void MapView::onPlaySkill_pbcBuffer(LuaMsgBuffer& pBuff)
{
	if(role_main == nullptr)
		return;
	struct pbc_slice slice;
	slice.buffer = (void*)pBuff.getMsgBody();
	slice.len = pBuff.getMsgBodyLen();
	struct pbc_rmessage * m = pbc_rmessage_new(g_registerEnv, "SkillSingProtocol", &slice);
	if (m == nullptr) {
		return;
	}
	int objId = pbc_rmessage_integer(m , "roleId" , 0 , nullptr);
	int tarId = pbc_rmessage_integer(m , "targetId" , 0 , nullptr);
	int skill_id = (int)pbc_rmessage_integer(m , "skillId" , 0 , nullptr);
	int pos_x = (int)pbc_rmessage_integer(m , "targetX" , 0 , nullptr);
	int pos_y = (int)pbc_rmessage_integer(m , "targetY" , 0 , nullptr);
	int skilLevel = (int)pbc_rmessage_integer(m, "skillLevel", 0, nullptr);
	int skillColor = (int)pbc_rmessage_integer(m, "skillColor", 0, nullptr);
	pbc_rmessage_delete(m);

	onPlaySkill(objId, tarId, skill_id, pos_x, pos_y, skilLevel, skillColor);
}

void MapView::onPlaySkill(int objId, int tarId, int skill_id, int pos_x, int pos_y, int skilLevel, int skillColor)
{
	// 非普通技能不处理
	if(!IsCommonSkill(skill_id))
		return;

	if(role_main->getTag() != objId)
	{
		if(m_item_node != nullptr)
		{
			SpriteMonster *r_node = dynamic_cast<SpriteMonster *>(m_item_node->getChildByTag(objId));
			if((r_node != nullptr) && r_node->isAlive())
			{
				Point n_pos = r_node->getParent()->convertToWorldSpace(r_node->getPosition());
				if( !Rect(0,0,m_winSize.width,m_winSize.height).containsPoint(n_pos))
					return;
				if(r_node->hasServerPoints())
				{
					action_queue temp_p;
					temp_p.q_type = ACTION_ATTACK_TYPE;
					temp_p.pos = Point(pos_x,pos_y);
					temp_p.skill_id = skill_id;
					temp_p.skill_lvl = skilLevel;
					temp_p.skillColor = skillColor;
					temp_p.tarId = tarId;
					r_node->insertServerPoint(temp_p);
				}
				else
				{
					action_queue temp_p;
					temp_p.q_type = ACTION_ATTACK_TYPE;
					temp_p.pos = Point(pos_x,pos_y);
					temp_p.skill_id = skill_id;
					temp_p.skill_lvl = skilLevel;
					temp_p.skillColor = skillColor;
					temp_p.tarId = tarId;
					r_node->insertServerPoint(temp_p);
					onDelayPlaySkill(r_node,temp_p); 
				}
			}
		}
	}
}
*/
char MapView::getSpeedUp(SpriteMonster*r_node)
{
	char speedup = 0;
	if(r_node != role_main)
	{
		int num = r_node->getSeverPointsNum();
		speedup = r_node->getTheSpeedUp();
		if(num > 6 && speedup < 3) 
		{
			speedup = 3;
			r_node->setTheSpeedUp(speedup);
		}
		else if(num > 4 && speedup < 2) 
		{
			speedup = 2;
			r_node->setTheSpeedUp(speedup);
		}
		else if(num > 2 && speedup < 1)
		{
			speedup = 1;
			r_node->setTheSpeedUp(speedup);
		}
		else if(num == 1)
		{
			r_node->setTheSpeedUp(0);
		}
	}
	return speedup;
}

/*void MapView::onDelayPlaySkill(SpriteMonster*r_node,action_queue skill_data)
{
	float attack_time = 0.45f;
	float magic_time = 0.55f;
	Point dest_pos = tile2Space(skill_data.pos);
	float speedup = getSpeedUp(r_node)/2;
	attack_time = attack_time/(1+speedup);

	int iWhichAction = MAGIC_ACTION_ATTACK;
	int iMagicType = MAGIC_TYPE_COMMON;
	if(r_node->getOnRide()&&m_touch_move_cb>0)
	{

		LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
		if (pStack != NULL)
		{
			pStack->pushBoolean(false);
			pStack->pushInt(r_node->getTag());
			pStack->executeFunctionByHandler(m_touch_move_cb, 2);
			pStack->clean();
		}	

	}

	int rootD = CMagicCtrlMgr::getInstance()->GetMagicRootD3(skill_data.skill_id);
	if (rootD != -1)
	{
		// 个位： 0 不做动作 1 攻击 2 施法
		iWhichAction = rootD%10;
		// 十位：技能归类 MAGIC_DEFINE_TYPE
		iMagicType = rootD/10;
	}

	int ownerId = r_node->getTag();

	bool bIsExecSus = false;

	if(iWhichAction == MAGIC_ACTION_NONE)
		bIsExecSus = r_node->DoMagicWithoutAction(dest_pos);
	else if(iWhichAction==MAGIC_ACTION_MAGIC && r_node->getType() >= PLAYER_MANE_TYPE)
		bIsExecSus = r_node->MagicOneTime_ex(magic_time,dest_pos);
	else
		bIsExecSus = r_node->attackOneTime_ex(attack_time,dest_pos);
	if(!bIsExecSus)
	{
		r_node->doSetOpacity_ex();
	}
	else
	{
		// 其它对象的buff 或者 地表类技能 技能仅作动作，不再释放效果
		if(iMagicType == MAGIC_TYPE_BUFF || iMagicType == MAGIC_TYPE_FLOOR)
			return;

		if(m_item_node != nullptr)
		{
			unsigned char byResult = CMagicCtrlMgr::getInstance()->IsMagicCanDisplay(skill_data.skill_id);
			if(byResult == 3)
			{
				int dir = 0;
				const cocos2d::Vec2& vRNode = r_node->getPosition();
				if(vRNode == dest_pos)	// 重叠情况特殊
					dir = (int)r_node->getCurrectDir();
				else
					dir = (int)GetDirByPos(vRNode, dest_pos);

				int iTarId = 0;
				// 目标对象
				SpriteMonster *targetItem = dynamic_cast<SpriteMonster *>(m_item_node->getChildByTag(skill_data.tarId));
				if(targetItem != nullptr)
					iTarId = skill_data.tarId;
				else
					iTarId = MAKELONG(((unsigned short)(skill_data.pos.x)), ((unsigned short)(skill_data.pos.y)));
				
				if(skill_data.skill_id == MAGICID_SUPER_FIREBALL || skill_data.skill_id == MAGICID_SUPER_FIREBALL_ARENA)
				{
					int iFireBallNum = 2;
					// 强化小火球 根据等级需要特殊处理
					if(skill_data.skillColor <= 3)
						iFireBallNum = 2;
					else if(skill_data.skillColor >=4 && skill_data.skillColor<= 5)
						iFireBallNum = 3;
					else if(skill_data.skillColor >=6 && skill_data.skillColor<= 7)
						iFireBallNum = 4;
					else
						iFireBallNum = 5;
					
					CMagicCtrlMgr::getInstance()->CreateMagic(MAGICID_SUPER_FIREBALL, 0, ownerId, iTarId, dir);
					for(int i = 0; i < iFireBallNum - 1; ++i)
					{
						CMagicCtrlMgr::getInstance()->CreateMagic(MAGICID_SUPER_FIREBALL_2 + i, 0, ownerId, iTarId, dir);
					}
				}
				else if(skill_data.skill_id == MAGICID_BARTIZAN_ATTACK)
				{
					// 目标处于箭塔 4 个象限情况，特效偏移值不同
					int iOffsetOriX = 0, iOffsetOriY = 0;
					int iOffsetFlyX = 0, iOffsetFlyY = 0;
					int iOriZorder = 0;

					switch(dir)
					{
					case dir_right:
						iOffsetFlyX = 40;
						iOffsetFlyY = 130;
						break;
					case dir_right_down:
						iOffsetFlyX = 30;
						iOffsetFlyY = 110;
						break;
					case dir_down:
						iOffsetFlyX = 0;
						iOffsetFlyY = 100;
						break;
					case dir_left_down:
						iOffsetFlyX = -30;
						iOffsetFlyY = 110;
						break;
					case dir_left:
						iOffsetFlyX = -40;
						iOffsetFlyY = 130;
						break;
					case dir_left_up:
						iOriZorder = 2;
						iOffsetFlyX = -30;
						iOffsetFlyY = 150;
						break;
					case dir_up:
						iOriZorder = 2;
						iOffsetFlyX = 0;
						iOffsetFlyY = 160;
						break;
					case dir_right_up:
						iOriZorder = 2;
						iOffsetFlyX = 30;
						iOffsetFlyY = 150;
						break;
					default:
						break;
					}
					
					CMagicCtrlMgr::getInstance()->CreateOffsetMagic(skill_data.skill_id, iOffsetOriX, iOffsetOriY, iOffsetFlyX, iOffsetFlyY, iOriZorder, ownerId, iTarId, dir);
				}
				else
				{
					CMagicCtrlMgr::getInstance()->CreateMagic(skill_data.skill_id, 0, ownerId, iTarId, dir);
				}
			}
			//else
			//{
			//	LuaMsgBuffer tmpBuff;

			//	tmpBuff.pushInt(ownerId);
			//	tmpBuff.pushInt(skill_data.tarId);
			//	tmpBuff.pushChar(0);
			//	tmpBuff.pushShort(skill_data.skill_id);
			//	tmpBuff.pushShort(skill_data.pos.x);
			//	tmpBuff.pushShort(skill_data.pos.y);

			//	CLuaParam luaParams[2];
			//	luaParams[0] = 3000;
			//	luaParams[1] = static_cast<void*>(&tmpBuff);
			//	LuaSocket::getInstance()->runLuaFunc("NetMsgDispacher", luaParams, 2);
			//}
		}
	}
}
*/
void MapView::onShowHurtNumber(int number,Point pos,char f_type,bool ishit,Point span_pos, int resistType)
{
	if(!s_show_hurt) return;
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

/*void MapView::onShowHurt(LuaMsgBuffer& pBuff)
{
	if(role_main == nullptr)
	{
		return;
	}
	struct pbc_slice slice;
	slice.buffer = (void*)pBuff.getMsgBody();
	slice.len = pBuff.getMsgBodyLen();
	struct pbc_rmessage * m = pbc_rmessage_new(g_registerEnv, "SkillHurtProtocol", &slice);
	if (m == NULL) {
		return;
	}
	int attackId =  pbc_rmessage_integer(m , "roleId" , 0 , NULL);
	char count = (char)pbc_rmessage_size(m, "hurts");

	SpriteMonster *attack_node = nullptr;
	for(int i = 0;i<count;i++)
	{
		struct pbc_rmessage * p = pbc_rmessage_message(m , "hurts", i);
		int objId = pbc_rmessage_integer(p , "id", i ,NULL);
		int hurt = pbc_rmessage_integer(p , "hurt", i ,NULL);
		int cur_blood = pbc_rmessage_integer(p , "now", i ,NULL);
		bool isHit =(bool)pbc_rmessage_integer(p , "crit", i ,NULL);
		int resistType = pbc_rmessage_integer(p , "hurtResistType", i ,NULL);
		unsigned char buff_count = (unsigned char)pbc_rmessage_size(p, "clearbuffs");
		SpriteMonster *r_node = nullptr;
		if(s_show_hurt && (m_show_hurt_count<20 || (role_main->getTag() == objId) || (role_main->getTag() == attackId) )) 
			r_node = (SpriteMonster *)(GetItemRoot()->getChildByTag(objId));
		m_show_hurt_count++;
		//buffID 402:代表伤害来源是来自于3v3闪电特效，需要添加闪电
		int buffID = pbc_rmessage_integer(p, "buffID", i, NULL);
		if(buffID == 402 && r_node){
			Node *node_magicEffect = CMagicCtrlMgr::getInstance()->CreatePichesMagic(11031);
			node_magicEffect->setPosition(r_node->getPosition());
			this->GetItemRoot()->addChild(node_magicEffect);
			node_magicEffect->runAction(Sequence::create(
				DelayTime::create(2)
				, RemoveSelf::create()
				, NULL
			));
		}
		//if(r_node != nullptr)
		{
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
					attack_node  = (SpriteMonster *)(GetItemRoot()->getChildByTag(attackId));
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
			if(role_main->getTag() == objId)
			{
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
			else 
			{
				if(resistType > 0 || cur_blood == 0 || buff_count > 0)
				{
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
			}
		}
	}
	pbc_rmessage_delete(m);
}

void MapView::onSkillMove(LuaMsgBuffer& pBuff)
{
	if(role_main == nullptr)
	{
		return;
	}
	struct pbc_slice slice;
	slice.buffer = (void*)pBuff.getMsgBody();
	slice.len = pBuff.getMsgBodyLen();
	struct pbc_rmessage * m = pbc_rmessage_new(g_registerEnv, "SkillMove", &slice);
	if (m == NULL) {
		return;
	}
	int objId =  pbc_rmessage_integer(m , "entityId" , 0 , NULL);
	int pos_x =  pbc_rmessage_integer(m , "x" , 0 , NULL);
	int pos_y =  pbc_rmessage_integer(m , "y" , 0 , NULL);
	int dir =  pbc_rmessage_integer(m , "dir" , 0 , NULL);
	int effectId =  pbc_rmessage_integer(m , "effectId" , 0 , NULL);
	int targetId =  pbc_rmessage_integer(m , "targetId" , 0 , NULL);
	pbc_rmessage_delete(m);

	if(role_main->getTag() != objId)
	{
		if(m_item_node != nullptr)
		{
			SpriteMonster *r_node = dynamic_cast<SpriteMonster *>(m_item_node->getChildByTag(objId));
			if((r_node != nullptr) && r_node->isAlive())
			{
				r_node->setServerTile(Point(pos_x,pos_y));
				action_queue temp_p;
				temp_p.q_type = ACTION_SKILLMOVE_TYPE;
				temp_p.pos = Point(pos_x, pos_y);
				temp_p.skill_id = effectId;
				temp_p.tarId = targetId;
				if(r_node->hasServerPoints())
				{
					r_node->insertServerPoint(temp_p);
				}
				else
				{
					r_node->insertServerPoint(temp_p);
					onDelaySkillMove(r_node,temp_p); 
				}
			}
		}
	}
	else
	{
		action_queue temp_p;
		temp_p.q_type = ACTION_SKILLMOVE_TYPE;
		temp_p.pos = Point(pos_x, pos_y);
		temp_p.skill_id = effectId;
		temp_p.tarId = targetId;
		if(role_main->hasServerPoints())
		{
			role_main->insertServerPoint(temp_p);
		}
		else
		{
			role_main->insertServerPoint(temp_p);
			onDelaySkillMove(role_main,temp_p); 
		}
		islock_num = 0;
		waitpoint.clear();
		waitpos_count = 0;
		server_pos = Point(pos_x,pos_y);
		role_main->setServerTile(server_pos);
		scroll2Tile(Point(pos_x,pos_y));
	}
}
*/

/*void MapView::onDelaySkillMove(SpriteMonster*r_node,action_queue move_data)
{
	float speedup = getSpeedUp(r_node)/2;
	Point start_pos = space2Tile(r_node->getPosition());
	int dist = max(abs(start_pos.x-move_data.pos.x),abs(start_pos.y-move_data.pos.y));//start_pos.getDistance(crash_data.pos);
	Commen_Direction dir = r_node->getCurrectDir();
	if(start_pos!=move_data.pos)
		dir = getDirByTile(move_data.pos-start_pos);

	float crash_time = 1.5f/(1+speedup);
	if(move_data.skill_id == MAGICID_ZONG_LEI_JUE || move_data.skill_id == MAGICID_BENG_LEI_JUE)
	{
		int iLoopNum = dist/2;
		if (iLoopNum <= 0)
			iLoopNum = 1;

		crash_time = 0.3f/(1+speedup) * iLoopNum;
	}
	
	SpritePlayer* pPlayer = dynamic_cast<SpritePlayer *>(r_node);
	// 当前对象是玩家
	if (pPlayer != nullptr)
		pPlayer->attackOnRide(crash_time,tile2Space(move_data.pos),dir, dist);
	
	
	// 骑战技能
	CMagicCtrlMgr::getInstance()->CreateMagic(move_data.skill_id, 0, r_node->getTag(), move_data.tarId, dir);

	// 纵雷决：移动轨迹一路落雷
	if(move_data.skill_id == MAGICID_ZONG_LEI_JUE || move_data.skill_id == MAGICID_BENG_LEI_JUE)
	{
		// 每两帧创建一个魔法
		cocos2d::Vec2 vStartPos = r_node->getPosition();
		cocos2d::Vec2 vEndPos = tile2Space(move_data.pos);

		Vector<FiniteTimeAction*> sequenceActions;
		int iTotalFrame = dist;
		int i = 0;
		for(float j = 0.0f; j < iTotalFrame; j = j + 1.5f)
		{
			float fTmpX = j*(vEndPos.x - vStartPos.x)/iTotalFrame + vStartPos.x;
			float fTmpY = j*(vEndPos.y - vStartPos.y)/iTotalFrame + vStartPos.y;

			if ( i!=0 && abs(fTmpX-vEndPos.x) < 64 && abs(fTmpY-vEndPos.y) < 32)
				break;

			// (crash_time*0.6f)/iTotalFrame 移动延时
			// 后面每格固定延时
			float fDelayTime = 0.067f;
			// 第一帧播放延时
			if(i==0)
				fDelayTime = (float)(0.4f);

			sequenceActions.pushBack(DelayTime::create(fDelayTime));

			sequenceActions.pushBack(CallFunc::create([=](){
				CMagicCtrlMgr::getInstance()->CreateMagicByPos(MAGICID_ZONG_LEI_JUE_LAST, fTmpX, fTmpY);	
			}));

			i++;
		}

		if(sequenceActions.size() >= 1)
		{
			FiniteTimeAction *actall = Sequence::create(sequenceActions);
			this->runAction(actall);
		}
	}
	

	if(r_node == role_main)
	{
		//FiniteTimeAction* actbackfun = CallFunc::create([&](){ 
			//if(role_main->getCurrActionState()<= ACTION_STATE_CREATE) 
			//	role_main->changeState(ACTION_STATE_IDLE);
			if(m_rock_cb>0)
			{
				LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
				if (pStack != NULL)
				{
					pStack->pushInt((int)start_tile.x);
					pStack->pushInt((int)start_tile.y);
					pStack->pushInt(move_data.skill_id);
					pStack->executeFunctionByHandler(m_rock_cb, 3);
					pStack->clean();
				}
			}
		//});
		//runAction(Sequence::create(DelayTime::create(crash_time),actbackfun,NULL));
	}
}
*/
cocos2d::Node* MapView::GetItemRoot()
{
	return m_item_node;
}
/*
void MapView::onCrash(LuaMsgBuffer& pBuff)
{
	if(role_main == nullptr)
	{
		return;
	}
	struct pbc_slice slice;
	slice.buffer = (void*)pBuff.getMsgBody();
	slice.len = pBuff.getMsgBodyLen();
	struct pbc_rmessage * m = pbc_rmessage_new(g_registerEnv, "SkillCrashRetProtocol", &slice);
	if (m == NULL) {
		return;
	}
	int objId =  pbc_rmessage_integer(m , "roleId" , 0 , NULL);
	short pos_x =  (short)pbc_rmessage_integer(m , "x" , 0 , NULL);
	short pos_y =  (short)pbc_rmessage_integer(m , "y" , 0 , NULL);
	short skill_id =  (short)pbc_rmessage_integer(m , "skillId" , 0 , NULL);
	char count = (char)pbc_rmessage_size(m, "crashs");

	int tarId = 0;
	// 狮子吼类需要指定最终被攻击者的方向
	short tpos_x = pos_x;
	short tpos_y = pos_y;

	for(int i=0; i<count; i++)
	{
		struct pbc_rmessage * p = pbc_rmessage_message(m , "crashs", i);
		tarId = pbc_rmessage_integer(p , "targetId", i ,NULL);
		short start_pos_x = (short)pbc_rmessage_integer(p , "sx", i ,NULL);
		short start_pos_y = (short)pbc_rmessage_integer(p , "sy", i ,NULL);
		tpos_x =(short)pbc_rmessage_integer(p , "dx", i ,NULL);
		tpos_y = (short)pbc_rmessage_integer(p , "dy", i ,NULL);
		if(role_main->getTag() != tarId)
		{
			if(m_item_node != nullptr)
			{
				SpriteMonster *r_node = dynamic_cast<SpriteMonster *>(m_item_node->getChildByTag(tarId));
				if((r_node != nullptr) && r_node->isAlive())
				{
					r_node->setServerTile( Point(tpos_x,tpos_y));
					action_queue temp_p;
					temp_p.q_type = ACTION_CRASHED_TYPE;
					temp_p.pos = Point(tpos_x,tpos_y);
					temp_p.skill_id = skill_id;
					temp_p.start_pos = Point(start_pos_x,start_pos_y);
					if(r_node->hasServerPoints())
					{

						r_node->insertServerPoint(temp_p);
					}
					else
					{
						r_node->insertServerPoint(temp_p);
						onDelayCrashed(r_node,temp_p); 
					}
				}
			}
		}
		else
		{
			cleanAstarPath(true,true);
			//role_main->stopAllActions();
			action_queue temp_p;
			temp_p.q_type = ACTION_CRASHED_TYPE;
			temp_p.pos = Point(tpos_x,tpos_y);
			temp_p.skill_id = skill_id;
			temp_p.start_pos = Point(start_pos_x,start_pos_y);
			if(role_main->hasServerPoints())
			{

				role_main->insertServerPoint(temp_p);
				action_queue save_p = role_main->getServerPoints();
				if(save_p.q_type == ACTION_MOVE_TYPE && temp_p.start_pos != save_p.pos )
				{
					role_main->removeServerPoint();
					onDelayCrashed(role_main,temp_p); 
				}
			}
			else
			{
				role_main->insertServerPoint(temp_p);
				onDelayCrashed(role_main,temp_p); 
				//CCLOG("MapView start  Pos: (%d, %d) end  Pos: (%d, %d)", (int)start_pos_x, (int)start_pos_y, (int)tpos_x, (int)tpos_y );
			}
			server_pos = Point(tpos_x,tpos_y);
			role_main->setServerTile(server_pos);
			islock_num = 0;
			waitpoint.clear();
			waitpos_count = 0;
			scroll2Tile(Point(tpos_x,tpos_y));
			if(m_rock_cb>0)
			{
				LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
				if (pStack != NULL)
				{
					pStack->pushInt(tpos_x);
					pStack->pushInt(tpos_y);
					pStack->executeFunctionByHandler(m_rock_cb, 2);
					pStack->clean();
				}
			}
		}
	}
	pbc_rmessage_delete(m);
	if(role_main->getTag() != objId)
	{
		if(m_item_node != nullptr)
		{
			SpriteMonster *r_node = dynamic_cast<SpriteMonster *>(m_item_node->getChildByTag(objId));
			if((r_node != nullptr) && r_node->isAlive())
			{
				r_node->setServerTile(Point(pos_x,pos_y));
				action_queue temp_p;
				temp_p.q_type = ACTION_CRASH_TYPE;
				if(skill_id == MAGICID_LION_CALL || skill_id == MAGICID_LION_CALL_ARENA)
					temp_p.pos = Point(tpos_x, tpos_y);
				else
					temp_p.pos = Point(pos_x, pos_y);
				temp_p.skill_id = skill_id;
				temp_p.tarId = tarId;
				if(r_node->hasServerPoints())
				{
					r_node->insertServerPoint(temp_p);
				}
				else
				{
					r_node->insertServerPoint(temp_p);
					onDelayCrash(r_node,temp_p); 
				}
			}
		}
	}
	else
	{
		action_queue temp_p;
		temp_p.q_type = ACTION_CRASH_TYPE;
		if(skill_id == MAGICID_LION_CALL || skill_id == MAGICID_LION_CALL_ARENA)
			temp_p.pos = Point(tpos_x, tpos_y);
		else
			temp_p.pos = Point(pos_x, pos_y);
		temp_p.skill_id = skill_id;
		temp_p.tarId = tarId;
		if(role_main->hasServerPoints())
		{
			role_main->insertServerPoint(temp_p);
		}
		else
		{
			role_main->insertServerPoint(temp_p);
			onDelayCrash(role_main,temp_p); 
		}
		islock_num = 0;
		waitpoint.clear();
		waitpos_count = 0;
		if(skill_id == MAGICID_WILD_COLLIDE || skill_id == MAGICID_WILD_COLLIDE_ARENA || skill_id == MAGICID_SUDDEN_KILL || skill_id == MAGICID_SUDDEN_KILL_ARENA)
		{
			server_pos = Point(pos_x,pos_y);
			role_main->setServerTile(server_pos);
			scroll2Tile(Point(pos_x,pos_y));
			//CCLOG("MapView end  Pos: (%d, %d)", (int)pos_x, (int)pos_y );
		}

	}
}
*/

/*
void MapView::onDelayCrash(SpriteMonster*r_node,action_queue crash_data)
{
	float speedup = getSpeedUp(r_node)/2;
	Point start_pos = space2Tile(r_node->getPosition());
	int dist = max(abs(start_pos.x-crash_data.pos.x),abs(start_pos.y-crash_data.pos.y));//start_pos.getDistance(crash_data.pos);
	Commen_Direction dir = r_node->getCurrectDir();
	if(start_pos!=crash_data.pos)
		dir = getDirByTile(crash_data.pos-start_pos);
	float crash_time = 0.15*dist/(1+speedup);
	if(dist == 0)
		crash_time = 0.3f;
	if(r_node->getOnRide()&&m_touch_move_cb>0)
	{

		LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
		if (pStack != NULL)
		{
			pStack->pushBoolean(false);
			pStack->pushInt(r_node->getTag());
			pStack->executeFunctionByHandler(m_touch_move_cb, 2);
			pStack->clean();
		}	
	}
	r_node->standed();

	if(crash_data.skill_id == MAGICID_DISPUTE_FIRE || crash_data.skill_id == MAGICID_DISPUTE_FIRE_ARENA)
	{
		float attack_time = 0.45f;
		attack_time = attack_time/(1+speedup);

		r_node->MagicOneTime_ex(attack_time, cocos2d::Vec2(0, 0));

		CMagicCtrlMgr::getInstance()->CreateMagic(MAGICID_DISPUTE_FIRE, 0, r_node->getTag(), 0, 0);
	}
	else if(crash_data.skill_id == MAGICID_LION_CALL || crash_data.skill_id == MAGICID_LION_CALL_ARENA)
	{
		float attack_time = 0.55f;
		attack_time = attack_time/(1+speedup);

		// 改变朝向，面向其中一个角色[允许重叠]		
		r_node->MagicOneTime_ex(attack_time, tile2Space(crash_data.pos));

		CMagicCtrlMgr::getInstance()->CreateMagic(MAGICID_LION_CALL, 0, r_node->getTag(), 0, (int)(r_node->getCurrectDir()));
	}
	else if(crash_data.skill_id == MAGICID_WILD_COLLIDE || crash_data.skill_id == MAGICID_WILD_COLLIDE_ARENA || crash_data.skill_id == MAGICID_SUDDEN_KILL || crash_data.skill_id == MAGICID_SUDDEN_KILL_ARENA)
	{
		//float attack_time = 0.45f;
		//attack_time = attack_time/(1+speedup);
		//r_node->attackOneTime(attack_time, cocos2d::Vec2(0, 0));

		if(crash_data.skill_id == MAGICID_SUDDEN_KILL)
		{
			// 突斩直接绑定到施放者身上
			CMagicCtrlMgr::getInstance()->CreateMagic(MAGICID_SUDDEN_KILL, 0, r_node->getTag(), 0, dir);
		}
		else if(crash_data.skill_id == MAGICID_SUDDEN_KILL_ARENA)
		{
			CMagicCtrlMgr::getInstance()->CreateMagic(MAGICID_SUDDEN_KILL_ARENA, 0, r_node->getTag(), 0, dir);
		}
		else if(crash_data.skill_id == MAGICID_WILD_COLLIDE)
		{
			CMagicCtrlMgr::getInstance()->CreateMagic(MAGICID_WILD_COLLIDE, 0, r_node->getTag(), 0, dir);
		}
		else if(crash_data.skill_id == MAGICID_WILD_COLLIDE_ARENA)
		{
			CMagicCtrlMgr::getInstance()->CreateMagic(MAGICID_WILD_COLLIDE_ARENA, 0, r_node->getTag(), 0, dir);
		}

		((SpritePlayer *)r_node)->collideInTheDir(crash_time,tile2Space(crash_data.pos),dir);
		if(r_node == role_main)
		{
			FiniteTimeAction* actbackfun = CallFunc::create([&](){ 
				if(role_main->getCurrActionState()<= ACTION_STATE_CREATE) 
					role_main->changeState(ACTION_STATE_IDLE);
				if(m_rock_cb>0)
				{
					LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
					if (pStack != NULL)
					{
						pStack->pushInt((int)start_tile.x);
						pStack->pushInt((int)start_tile.y);
						pStack->pushInt(crash_data.skill_id);
						pStack->executeFunctionByHandler(m_rock_cb, 3);
						pStack->clean();
					}
				}
			});
			runAction(Sequence::create(DelayTime::create(crash_time),actbackfun,NULL));
		}
	}
}
*/
/*void MapView::onDelayCrashed(SpriteMonster*r_node,action_queue crashed_data)
{
	float speedup = getSpeedUp(r_node)/2;
	Point start_pos = crashed_data.start_pos;
	r_node->setPosition(tile2Space(start_pos));
	int dist = max(abs(start_pos.x-crashed_data.pos.x),abs(start_pos.y-crashed_data.pos.y));
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
		((SpritePlayer *)r_node)->moveInTheDir_ex(0.2,tile2Space(crashed_data.pos),dir,crash_time);
		if(r_node == role_main)
		{
			r_node->changeState(ACTION_STATE_CRASHED);
			if( r_node->getSeverPointsNum() <= 1)
			{
				float stand_time = 0.5f;
				if(crashed_data.skill_id == MAGICID_WILD_COLLIDE || crashed_data.skill_id == MAGICID_WILD_COLLIDE_ARENA || crashed_data.skill_id == MAGICID_SUDDEN_KILL || crashed_data.skill_id == MAGICID_SUDDEN_KILL_ARENA)
					stand_time = 1.5f;
				if(crash_time < stand_time)
				{
					FiniteTimeAction* dostandFirst = CallFunc::create([&](){ 
						if(role_main&&role_main->getCurrActionState() == ACTION_STATE_CRASHED)
							role_main->doStandedAction();
					});
					FiniteTimeAction* dostand = CallFunc::create([&](){ 
						if(role_main&&role_main->getCurrActionState() == ACTION_STATE_CRASHED)
							role_main->standed();
					});
					r_node->runAction(Sequence::create(DelayTime::create(crash_time),dostandFirst,DelayTime::create(stand_time -crash_time),dostand,NULL));
				}
				else
				{
					FiniteTimeAction* dostand = CallFunc::create([&](){ 
						if(role_main&&role_main->getCurrActionState() == ACTION_STATE_CRASHED)
							role_main->standed();
					});
					r_node->runAction(Sequence::create(DelayTime::create(crash_time),dostand,NULL));
				}
			}
			else
			{
				FiniteTimeAction* dostand = CallFunc::create([&](){ 
					if(role_main&&role_main->getCurrActionState() == ACTION_STATE_CRASHED)
						role_main->standed();
				});
				r_node->runAction(Sequence::create(DelayTime::create(crash_time-0.05),dostand,NULL));
			}
		}
	}

	if(crashed_data.skill_id == MAGICID_LION_CALL || crashed_data.skill_id == MAGICID_LION_CALL_ARENA)
	{
		Commen_Direction effDir = GetDirByPos(r_node->getPosition(), tile2Space(crashed_data.pos));
		// 狮子吼如果推动，每个对象都有特效
		CMagicCtrlMgr::getInstance()->CreateMagic(MAGICID_LION_CALL_PUSH, 0, 0, r_node->getTag(), effDir);
	}
}
*/

bool MapView::IsOutoffScreen(const cocos2d::Vec2& pos)
{
	if(role_main == nullptr)
		return true;

	const Size& win_size =  Director::getInstance()->getWinSize();

	// 人物为中心点 左右各win_size
	const cocos2d::Vec2& roPos = role_main->getPosition();
	if(pos.x < roPos.x - win_size.width)
		return true;
	if(pos.x > roPos.x + win_size.width)
		return true;
	if(pos.y < roPos.y - win_size.height)
		return true;
	if(pos.y > roPos.y + win_size.height)
		return true;

	return false;
}

MapView *MapView::create(const std::string& filename,int mapId, const Point pos)
{
	MapView *pRet = new MapView();
	if (pRet && pRet->init() && pRet->loadMap(filename, mapId, pos))
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

MapView *MapView::create()
{
	MapView *pRet = new MapView();
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
bool MapView::getDisplayStatus(int x,int y,int x1,int y1)
{
	bool status = false;
	if(x-x1<50&&x1-x<50&&y-y1<50&&y1-y<50)
	{
		if(x<20||y<20||x>(m_mapSize.width-20)||y>(m_mapSize.height-20))
		{
			if(x<20)
			{
				if(y<20)
					status = x1<=40&&y1<=40;
				else if(y>(m_mapSize.height-20))
					status = x1<=40&&y1>(m_mapSize.height-40);
				else 
					status = x1<=40&&abs(y1+5-y)<=22;
			}
			else if(x>(m_mapSize.width-20))
			{
				if(y<20)
					status = x1>=(m_mapSize.width-40)&&y1<=40;
				else if(y>(m_mapSize.height-20))
					status = x1>=(m_mapSize.width-40)&&y1>(m_mapSize.height-40);
				else 
					status = x1>=(m_mapSize.width-40)&& abs(y1+5-y)<=22;
			}
			else if(abs(x1+5-x)<=22)
			{
				if(y<20)
					status = y1<=40;
				else 
					status = y1>(m_mapSize.height-40);
			}
		}
		else if(abs(x1+5-x)<=22&&abs(y1+5-y)<=22)
		{
			status = true;
		}
	}
	return status;
}

void MapView::addMapSprites()
{
	//_infoMutex.lock();
	struct _DisplayNode *Dmap = DisplayMap;
	char imgstr[128] = {0};
	while(Dmap!=NULL)
	{
		if(Dmap->Status&&Dmap->sp == NULL&&(!Dmap->loaded)&&mapstr.size()>0)
		{
			memset(imgstr,0,128);
			sprintf(imgstr,"%sx%d_%d.jpg",mapstr.c_str(),Dmap->x/MAP_SPAN,Dmap->y/MAP_SPAN);
			//std::function<void(Texture2D *)> addTexture = CC_CALLBACK_1(MapView::addTextureSprite1,this);
			//Director::getInstance()->getTextureCache()->addImageAsync(imgstr,addTexture);
			MapViewResLoadMgr::getInstance()->addImageAsync(imgstr);
			
			Dmap->loaded = true;
			//m_textures.pushBack(texture);
		}
		Dmap = Dmap->Next;
	}
	//_infoMutex.unlock();
}

void MapView::setDisplayMap(int x,int y)
{
	if (m_isNewMap)
		return;
	bool need_load = false;
	//_infoMutex.lock();
	struct _DisplayNode *Dmap = DisplayMap;
	while(Dmap!=NULL)
	{
		Dmap->Status = getDisplayStatus(x,y,Dmap->x,Dmap->y);
		if(Dmap->Status&&Dmap->sp == NULL)
		{
			need_load = true;
		}
		Dmap = Dmap->Next;
	}
	//_infoMutex.unlock();
	if(need_load)
	{
		addMapSprites();
		//std::thread Thread = std::thread(&MapView::addMapSprites,this);
		//Thread.detach();  
	}
}


bool MapView::loadMap(const std::string& afilename, const  int mapId, const Point mpos)
{
	if (afilename.length() <= 0)
		return true;

	m_isNewMap = false;
	//_mapNode = nullptr;

	m_block_str = FileUtils::getInstance()->getStringFromFile(afilename);
	if (m_block_str.empty())
		return true;

	//log("%s -> %s",filename.c_str(),st.c_str());
	auto first = m_block_str.find_first_of("\n");
	auto last = m_block_str.find_last_of("\n");
	int width = atoi(m_block_str.substr(0, first - 1).c_str());
	int height = atoi(m_block_str.substr(first + 1, last - 1).c_str());
	m_mapSize = Size(width, height);
	m_block_str = m_block_str.substr(last + 1);

	std::string filename = afilename;
	std::string::size_type pos = 0;
	std::string strSrc = "/block/";
	
	if ((pos = filename.find(strSrc, pos)) != std::string::npos)
	{
		filename.erase(pos, strSrc.size()-1);
	}

	m_perTileSize = Size(48, 32);

	bool ret = loadMap_imp(filename, mapId, mpos);
	return ret;
}



void MapView::setScale(float scale)
{
	if (blood_node)
	{
		if (scale > 1)
		{
			Vector<Node*>& childrens = blood_node->getChildren();
			for (const auto &child : childrens)
				child->setScale(1 / scale);
		}
		else
		{
			Vector<Node*>& childrens = blood_node->getChildren();
			for (const auto &child : childrens)
				child->setScale(1);
		}
		
	}
	Layer::setScale(scale);
}

void MapView::newAstar()
{
	// 动态设置阻挡点的时候可能需要先释放
	if(AStarMap)
	{
		free(AStarMap);
		AStarMap = NULL;
	}
	cleanAstarPath(true,true);
	AStarMap = NewAstarMap(m_mapSize,this);

	if(AStarMap2)
	{
		free(AStarMap2);
		AStarMap2 = NULL;
	}
}

bool MapView::hasPath()
{
	return (AStarPath != NULL) || (m_rocker_dir < dir_undef);
}

void MapView::loadSpritesPre()
{
	if (!m_isNewMap && DisplayMap == NULL)
	{
		struct _DisplayNode *t_Map;
		char imgstr[128] = {0};
		for(int i=0;i<m_mapSize.width;i=i+MAP_SPAN)
		{
			for(int j=0;j<m_mapSize.height;j=j+MAP_SPAN)
			{
				memset(imgstr,0,128);
				sprintf(imgstr,"%sx%d_%d.jpg",mapstr.c_str(),i/MAP_SPAN,j/MAP_SPAN);
				struct _DisplayNode *D_Map;
				D_Map = (struct _DisplayNode *)malloc(sizeof(struct _DisplayNode));
				D_Map->x = i;
				D_Map->y = j;
				D_Map->tag = i/MAP_SPAN*m_mapSize.width+j/MAP_SPAN;
				D_Map->Next = NULL;
				D_Map->sp = NULL;
				D_Map->loaded = false;
				D_Map->Status = true;
				if(DisplayMap == NULL)
				{
					DisplayMap = D_Map;
					t_Map = DisplayMap;
				}
				else
				{
					t_Map->Next = D_Map;
					t_Map = t_Map->Next;
				}
			}	
		}
	}

	newAstar();
	//load_Thread = new std::thread(&MapView::newAstar,this);
	//load_Thread->detach();
	addCacheSpritesPre(); 
}
void MapView::tickCache(float dt)
{
	if(!loadall)
	{
		loadall = true;
		//setDisplayMap(start_tile.x,start_tile.y);
	}
}
void MapView::addCacheSpritesPre()
{
	//_infoMutex.lock();
	struct _DisplayNode *Dmap = DisplayMap;
	char imgstr[128] = {0};
	while(Dmap!=NULL)
	{
		if(Dmap->sp == NULL&&(getDisplayStatus(role_pos.x,role_pos.y,Dmap->x,Dmap->y)))
		{
			memset(imgstr,0,128);
			sprintf(imgstr,"%sx%d_%d.jpg",mapstr.c_str(),Dmap->x/MAP_SPAN,Dmap->y/MAP_SPAN);
			//std::function<void(Texture2D *)> addTexture = CC_CALLBACK_1(MapView::addTextureSprite1,this);
			//Director::getInstance()->getTextureCache()->addImageAsync(imgstr,addTexture);
			MapViewResLoadMgr::getInstance()->addImageAsync(imgstr);
			Dmap->loaded = true;
			//m_textures.pushBack(texture);
		}
		Dmap = Dmap->Next;
	}
	//_infoMutex.unlock();
}

void MapView::addMapSpritesPre()
{
}

void MapView::addCacheSprites()
{
	//_infoMutex.lock();
	struct _DisplayNode *Dmap = DisplayMap;
	char imgstr[128] = {0};
	while(Dmap!=NULL)
	{
		if(Dmap->sp == NULL&&(!Dmap->loaded)&&mapstr.size()>0)
		{
			memset(imgstr,0,128);
			sprintf(imgstr,"%sx%d_%d.jpg",mapstr.c_str(),Dmap->x/MAP_SPAN,Dmap->y/MAP_SPAN);
			//std::function<void(Texture2D *)> addTexture = CC_CALLBACK_1(MapView::addTextureSprite1,this);
			//Director::getInstance()->getTextureCache()->addImageAsync(imgstr,addTexture);
			MapViewResLoadMgr::getInstance()->addImageAsync(imgstr);
			Dmap->loaded = true;
			//m_textures.pushBack(texture);
		}
		Dmap = Dmap->Next;
	}
	//_infoMutex.unlock();
}
void MapView::addTextureSprite(Texture2D *a)
{
}
void MapView::addTextureSprite1(Texture2D *a)
{
	//_infoMutex.lock();
	struct _DisplayNode *Dmap = DisplayMap;
	char imgstr[128] = {0};
	while(Dmap!=NULL&&mapstr.size()>0)
	{
		if(Dmap->sp == NULL)
		{
			memset(imgstr,0,128);
			sprintf(imgstr,"%sx%d_%d.jpg",mapstr.c_str(),Dmap->x/MAP_SPAN,Dmap->y/MAP_SPAN);
			Texture2D *text = Director::getInstance()->getTextureCache()->getTextureForKey(imgstr);
			if(text)
			{
				Sprite *sprite = Sprite::createWithTexture(text);
				if(sprite)
				{
					sprite->setAnchorPoint(Point(0,1));
					//sprite->setVisible(false);
					sprite->setPosition(Point(Dmap->x*m_perTileSize.width, (m_mapSize.height - Dmap->y)* m_perTileSize.height));
					if(m_pMap)
						m_pMap->addChild(sprite,0,Dmap->tag);
					Dmap->sp = sprite;
					Director::getInstance()->getTextureCache()->removeTextureForKey(imgstr);
				}
			}
		}
		Dmap = Dmap->Next;
	}
	//_infoMutex.unlock();
}

//void MapView::stopMapAction()
//{
//	//if(role_main!=NULL)
//	//	stopAllActions();
//}

void MapView::initDataAndFunc(Point start)
{
	if(role_main!=NULL)
	{
		if(start!=Point())
			start_tile = start;
		else
			start_tile = space2Tile(role_main->getPosition());
		m_rocker_dir = dir_undef;
		//resetDisplay(start_tile);
	}
	/*if(m_effect==NULL)
	{
		m_effect = Effects::create(false);
		addChild(m_effect,1);
	}*/
	set_rock = false;
	islock_num = 0;	
	waitpoint.clear();
	waitpos_count = 0;
}



void MapView::setBlockRectValue(Rect rect,const char* value)
{
	if(rect.origin.x + rect.size.width >= m_mapSize.width || rect.origin.y + rect.size.height>= m_mapSize.height || rect.origin.x<0 || rect.origin.y <0
		||rect.size.width < 0 || rect.size.height <0)
		return;
	int x = rect.origin.x;
	int y = rect.origin.y;

	for (int j = y; j <= y + rect.size.height; j++)
	{
		for (int i = x; i <= x + rect.size.width; i++)
			m_block_str.replace((j*int(m_mapSize.width) + i), 1, value);
	}
	
	newAstar();
	//load_Thread = new std::thread(&MapView::newAstar,this);
}

bool MapView::isOpacity(Point tile)
{
	if(tile.x >= m_mapSize.width || tile.y >= m_mapSize.height || tile.x<0 || tile.y<0)
		return true;
	int x = tile.x;
	int y = tile.y;
	return (m_block_str.at(y*int(m_mapSize.width) + x) == '2');
}

float MapView::getFlyTime(const cocos2d::Vec2& startpos, const cocos2d::Vec2& endpos, float flySpeed)
{
	//return FlyAction::getFlyTime(startpos, endpos, flySpeed);
	return 0.0f;
}

Point MapView::screen2Tile(Point point)
{
	return space2Tile(screen2Space(point));
}

Point MapView::tile2Screen(Point tile)
{
	return space2Screen(tile2Space(tile));
}

Point MapView::screen2Space(Point point)
{
	return convertToNodeSpace(point);
	//float scale = Director::getInstance()->getMapScale();
	//return CC_POINT_POINTS_TO_PIXELS((point-getPosition())/scale);
}

Point MapView::space2Screen(Point pos)
{
	////float scale = Director::getInstance()->getMapScale();
	////return (CC_POINT_PIXELS_TO_POINTS(pos)+ getPosition());
	return convertToWorldSpace(pos); 
}




Point MapView::getCenterTile()
{
	Size scrSize = Director::getInstance()->getWinSize();
	return screen2Tile(Point(scrSize.width/2, scrSize.height/2));
}

Point MapView::getDestPosition(Point start_pos,int span)
{
	Commen_Direction dir = role_main->getCurrectDir();
	Point dest_pos = space2Tile(start_pos) + getTileByDir(dir)*span;
	return tile2Space(dest_pos);
}


void MapView::scroll2Tile(Point tile,float speed)
{
	dir_temp_tile = tile;
	start_tile = tile;
	resetDisplay(tile);
	//move_speed = (speed>0.01)?speed:move_speed;

}
void MapView::resetDisplay(const Point tile_pos)
{
	if (m_isNewMap)
		return;

	setDisplayMap(tile_pos.x,tile_pos.y);
	struct _DisplayNode *Dmap = DisplayMap;
	while(Dmap!=NULL)
	{
		if(Dmap->sp != NULL)
			Dmap->sp->setVisible(Dmap->Status);
		Dmap = Dmap->Next;
	}
}

void MapView::freeMapSprite(int num)
{

	//_infoMutex.lock();
	struct _DisplayNode *Dmap = DisplayMap;
	while(Dmap!=NULL)
	{
		if(Dmap->sp != NULL)
		{
			if((abs(Dmap->x-start_tile.x) > num)||(abs(Dmap->y-start_tile.y) > num))
			{
				Dmap->sp->removeFromParent();
				Dmap->sp = NULL;
				Dmap->loaded = false;
			}
		}
		Dmap = Dmap->Next;
	}
	//_infoMutex.unlock();
}

void MapView::scrollMap(Point pos)
{
	if (m_pMap)
	{
		//Size mapSize = m_pMap->getContentSize();
		//Size scrSize = Director::getInstance()->getWinSize();
		float scale = Director::getInstance()->getMapScale();
		Point edgeSize = Point(m_mapSize.width*m_perTileSize.width - m_winSize.width,  m_mapSize.height*m_perTileSize.height - m_winSize.height)*scale;
		Point edgeSize1 = Point(m_winSize.width, m_winSize.height)*(scale-1)/2;
		edgeSize = edgeSize + edgeSize1;
		if (pos.x >  edgeSize1.x) pos.x = edgeSize1.x;
		if (pos.y >  edgeSize1.y) pos.y = edgeSize1.y;
		if (pos.x < -edgeSize.x) pos.x = -edgeSize.x;
		if (pos.y < -edgeSize.y) pos.y = -edgeSize.y;	
		runAction(MoveTo::create(move_speed, pos));
	}
}

void MapView::setPosition(const Point& position)
{
	Layer::setPosition(position);
	//CCLOG("MapView Pos: (%d, %d)", (int)this->getPosition().x, (int)this->getPosition().y);
}

void MapView::moveMapByPos(Point cp,bool isnear)
{
	if(AStarMap == NULL || role_main == NULL || role_main->getCurrActionState()>ACTION_STATE_CREATE) return ;
	if(role_main->getCurrActionState() == ActionState::ACTION_STATE_IDLE)
	{
		moveMapByPosEx(cp,isnear);
		_m_time = move_speed;
	}
	else 
	{
		_move_end_tile = cp;
		_isnear_ = isnear;
	}
}

void MapView::moveMapByPosEx(Point cp,bool isnear)
{
	/*int step = 0;*/
	set_rock = false;
	m_rocker_dir = dir_undef;
	struct _AstarNode *path =  AStarPath;
	InitAstarMap(AStarMap);
	//Point start = space2Tile(role_main->getPosition());
	if(isBlock(cp)&&isnear)
	{
		Commen_Direction dir = dir_right_down;
		Point temp_cp = getNearTiled(cp,dir_right_down);
		do
		{ 
			if(!isBlock(temp_cp))
			{
				cp = temp_cp;
				break;
			}
			temp_cp  = getNearTiled(cp,dir_left_down);
			if(!isBlock(temp_cp))
			{
				cp = temp_cp;
				break;
			}
			temp_cp  = getNearTiled(cp,dir_right_up);
			if(!isBlock(temp_cp))
			{
				cp = temp_cp;
				break;
			}
			temp_cp  = getNearTiled(cp,dir_left_up);
			if(!isBlock(temp_cp))
			{
				cp = temp_cp;
				break;
			}
		}while(false);
		isnear = false;
	}
	AStarPath = FindPath(start_tile.x, start_tile.y, cp.x, cp.y, AStarMap);
	//CCLOG("cp:%d cp:%d",cp.x,cp.y);
	if(AStarPath!=NULL)
	{
		if(AStarPath->Next==NULL)
		{
			AStarPath = NULL;
			if(m_walk_cb>0)
			{
				LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
				if (pStack != NULL)
				{
					pStack->executeFunctionByHandler(m_walk_cb, 0);
					pStack->clean();
				}
			}
			if(m_rock_cb>0)
			{
				LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
				if (pStack != NULL)
				{
					pStack->pushInt(3);
					pStack->executeFunctionByHandler(m_rock_cb, 1);
					pStack->clean();
				}
			}
		}
		else
		{
			m_rocker_dir = dir_undef;	
			if(isnear)
			{
				struct _AstarNode *path =  AStarPath;
				while(path!=NULL&&path->Next!=NULL)
				{
					if(path->Next->Next == NULL)
					{
						path->Next = NULL;
						break;
					}
					//step++;
					path = path->Next;
				}
			}
			if(AStarPath->Next==NULL)
			{
				AStarPath = NULL;
				if(m_walk_cb>0)
				{
					LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
					if (pStack != NULL)
					{
						pStack->executeFunctionByHandler(m_walk_cb, 0);
						pStack->clean();
					}
				}
				if(m_rock_cb>0)
				{
					LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
					if (pStack != NULL)
					{
						pStack->pushInt(3);
						pStack->executeFunctionByHandler(m_rock_cb, 1);
						pStack->clean();
					}
				}
			}
			else
			{
				/*m_steps = step;*/
				if(m_rock_cb>0&&AStarPath!=NULL)
				{
					LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
					if (pStack != NULL)
					{
						pStack->pushInt(0);
						pStack->executeFunctionByHandler(m_rock_cb, 1);
						pStack->clean();
					}
				}
				//sendPointsByAstarPath(AStarPath);
				//if(AStarPath != NULL && role_main!=NULL && role_main->getCurrActionState() == ActionState::ACTION_STATE_IDLE)
				//	_m_time = move_speed;
			}
		}
	}
	else
		AStarPath = path;
}

std::vector<cocos2d::Point> MapView::getPathByPos(Point start,Point dest)
{
	std::vector<cocos2d::Point> ret;

	if( role_main == NULL || role_main->getCurrActionState()>ACTION_STATE_CREATE)
		return ret;

	int i = 0;
	if(AStarMap != NULL)
	{
		InitAstarMap(AStarMap);
		struct _AstarNode *path = FindPath(start.x, start.y, dest.x, dest.y, AStarMap);
		while(path!=NULL)
		{
			ret.push_back(Point(path->X,path->Y));
			path = path->Next;
		}
	}
	return ret;
}

std::vector<cocos2d::Point> MapView::getRolePath()
{
	std::vector<cocos2d::Point> ret;

	if( role_main == NULL || role_main->getCurrActionState()>ACTION_STATE_CREATE)
		return ret;

	int i = 0;
	if(AStarPath != NULL)
	{
		struct _AstarNode *path = AStarPath;
		while(path!=NULL)
		{
			ret.push_back(Point(path->X,path->Y));
			path = path->Next;
			i++;
		}
	}
	return ret;
}

int MapView::getRolePathNum()
{
	if( role_main == NULL || role_main->getCurrActionState()>ACTION_STATE_CREATE) return 0;
	int i = 0;
	if(AStarPath != NULL)
	{
		struct _AstarNode *path = AStarPath;
		while(path!=NULL)
		{
			path = path->Next;
			i++;
		}
	}
	return i;
}

void MapView::moveMonsterByPos(Point cp,SpriteMonster* monster,float sp,bool isnear, std::vector<cocos2d::Point>* tabl)
{
	if(role_main == nullptr || role_main->getCurrActionState()>ACTION_STATE_CREATE)
		return;
	if(AStarMap2==nullptr&&AStarMap!=nullptr)
	{
		AStarMap2 = NewAstarMap(m_mapSize,AStarMap);
	}
	Point m_tile = space2Tile(monster->getPosition());
	int i = 0;
	if(AStarMap2 != nullptr)
	{
		InitAstarMap(AStarMap2);
		struct _AstarNode *path = FindPath(m_tile.x, m_tile.y, cp.x, cp.y, AStarMap2);
		if(path != nullptr)
		{
			struct _AstarNode *path1 = path;
			int steps = 0;
			Point temp_tile = Point(path1->X,path1->Y);
			Point move_pc = tile2Space(temp_tile);
			Commen_Direction temp_dir = getDirByTile(temp_tile-m_tile);
			while(path1!=nullptr)
			{
				if(path1->Next!=nullptr&&path1->Next->Next==nullptr && isnear) 
				{
					path1->Next = nullptr;
				}
				temp_tile = Point(path1->X,path1->Y);
				move_pc = tile2Space(temp_tile);
				temp_dir = getDirByTile(temp_tile-m_tile);
				//monster->walkInTheDir(speed,move_pc,temp_dir);
				monster->setLocalZOrder(path1->Y);
				path1 = path1->Next;
				if(isOpacity(temp_tile))
				{
					monster->setOpacity(100);
				}
				else
				{
					monster->setOpacity(255);
				}
				m_tile = temp_tile;
				steps++;
			}
			float speed = SPEED*sp*steps;
			if(tabl == nullptr)
			{
				monster->walkToPos(speed,move_pc,true);
			}
			else
			{
				path1 = path;
				while(path1!=nullptr)
				{
					tabl->push_back(Point(path1->X,path1->Y));
					path1 = path1->Next;
				}
			}
			sendPointsByAstarPath(path,monster);
		}
	}
}

void MapView::cleanAstarPath(bool stop_rock,bool nosend)
{
	setAttackFlag(false);
	bool has_send = false;
	if(stop_rock)
	{
		start_tile = dir_temp_tile;
		//role_main->setPosition(tile2Space(start_tile));
		if(!nosend&& m_rocker_dir < dir_undef)
		{
			has_send = true;
			sendPointsByPath(m_rocker_dir,0);
		}
		m_rocker_dir = dir_undef;
	}
	if(role_main && AStarPath!=NULL)
	{
		start_tile = dir_temp_tile;
		//role_main->setPosition(tile2Space(start_tile));
		if(!nosend&&!has_send)
			sendPointsByPath(role_main->getCurrectDir(),0);
		AStarPath = NULL;
	}
}

void MapView::moveMapByTouch(Point d_tile)
{
	set_rock = false;
	m_rocker_dir = dir_undef;
	if(AStarMap == NULL || role_main == NULL || role_main->getCurrActionState()>ACTION_STATE_CREATE) return ;
	//int step = 0;
	struct _AstarNode *path =  AStarPath;
	AStarPath = NULL;
	InitAstarMap(AStarMap);

	AStarPath = FindPath(start_tile.x, start_tile.y, d_tile.x, d_tile.y, AStarMap);
	
	if(AStarPath!=NULL)
	{
		path =  AStarPath;
		if(AStarPath->Next==NULL)
		{
			AStarPath = NULL;
		}
		else
		{
			//sendPointsByAstarPath(AStarPath);
			removeWalkCb();
			if(m_rock_cb>0)
			{
				LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
				if (pStack != NULL)
				{
					pStack->pushInt(1);
					pStack->executeFunctionByHandler(m_rock_cb, 1);
					pStack->clean();
				}
			}
		}
	}
	else 
		AStarPath = path;
}

void MapView::setAttackFlag(bool flag)
{
	attack_flag = flag;
	set_rock = false;
}

//void MapView::moveMapByPath(float dt)
void MapView::update(float dt)
{
	//CCLog("update tiem %f",dt);
	m_show_hurt_count = 0;
	if(role_main == NULL)
	{
		_m_time = 0;
		return;
	}
	else if( !isStoryMap(m_mapId) && (role_main->getHP() <= 0 || role_main->getCurrActionState()>ACTION_STATE_CREATE ))
	{
		_m_time = 0;
		cleanAstarPath(true,true);
		//return;
	}

	_m_time += dt;
	_m_rock_time += dt;
	if(is_act_map)
	{
		float scale = Director::getInstance()->getMapScale();
		Point pos = CC_POINT_PIXELS_TO_POINTS(role_main->getPosition());
		pos = (Point(m_winSize.width/2, m_winSize.height/2) - pos)*scale;
	
		Point edgeSize = Point(m_mapSize.width*m_perTileSize.width - m_winSize.width,  m_mapSize.height*m_perTileSize.height - m_winSize.height)*scale;
		Point edgeSize1 = Point(m_winSize.width, m_winSize.height)*(scale-1)/2;
		edgeSize = edgeSize + edgeSize1;
		if (pos.x >  edgeSize1.x) pos.x = edgeSize1.x;
		if (pos.y >  edgeSize1.y) pos.y = edgeSize1.y;
		if (pos.x < -edgeSize.x) pos.x = -edgeSize.x;
		if (pos.y < -edgeSize.y) pos.y = -edgeSize.y;	

		setPosition(pos);
	}

	if(_m_time<move_speed)
		return;
	else
		_m_time = 0;//_m_time -= move_speed;

	move_speed = map_speed;

	if(m_touch_tile!= Point(0,0))
	{
		moveMapByTouch(m_touch_tile);
		m_touch_tile = Point(0,0);
	}
	else if(_move_end_tile!= Point(0,0))
	{
		moveMapByPosEx(_move_end_tile,_isnear_);
		_move_end_tile= Point(0,0);
		_isnear_ = false;
	}	
	//走跑切换去掉if(AStarPath != NULL && m_steps <= 2&&role_main->getUnToAttack()) move_speed = map_speed*2;
	//else if(AStarPath == NULL && m_rocker_dir < dir_undef)  speed = map_speed*2;
	auto status = role_main->getCurrActionState();
	if(attack_flag)
	{
		attack_flag = false;
		sendPointsByPath(m_rocker_dir,0);
		m_rocker_dir = dir_undef;
		start_tile = dir_temp_tile;
		role_main->setPosition(tile2Space(start_tile));
		role_main->standed();
		if(m_walk_cb>0)
		{
			LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
			if (pStack != NULL)
			{
				pStack->executeFunctionByHandler(m_walk_cb, 0);
				pStack->clean();
			}
		}
		return;
	}
	if(role_main->getSeverPointsNum() == 1)
	{
		action_queue temp_p = role_main->getServerPoints();
		if(temp_p.q_type == ACTION_MOVE_TYPE)
			role_main->removeServerPoint();
	}
	if(AStarPath != NULL && AStarPath->Next != NULL &&(m_rocker_dir>= dir_undef))
	{
		if( maxlock_num < 5 &&(islock_num > maxlock_num && !isStoryMap(m_mapId)))
		{
			//if(server_pos!= Point(0,0)&&islock_num>maxlock_num+2)
			//{
			//	role_main->stopAllActions();
			//	role_main->clearServerPoints();
			//	role_main->setPosition(tile2Space(server_pos));
			//	role_main->standed();
			//	scroll2Tile(server_pos);
			//	//AStarPath = NULL;
			//	last_dir = dir_undef;
			//	Point end_pos = Point();
			//	while(AStarPath->Next!= NULL)
			//	{
			//		AStarPath = AStarPath->Next;
			//		end_pos = Point(AStarPath->X,AStarPath->Y);
			//	}
			//	if(end_pos!=Point())
			//		moveMapByPosEx(end_pos,false);
			//	islock_num = 0;
			//	waitpoint.clear();
			//	waitpos_count = 0;
			//	return;
			//}
			//moveLock(true);
			return ;
		}
		Point temp_tile = Point(AStarPath->Next->X,AStarPath->Next->Y);
		//CCLog("x  %d, y %d ",AStarPath->Next->X,AStarPath->Next->Y);
		Point role_move_pc = tile2Space(temp_tile);
		bool do_move = false;
		Commen_Direction temp_dir = getDirByTile(temp_tile-start_tile);
		action_queue temp_p;
		temp_p.q_type = ACTION_MOVE_TYPE;
		temp_p.pos =temp_tile;
		role_main->insertServerPoint(temp_p);

		//if (waitpos_count >= 3)
		//	addmovespeed = 0.1f;
		//else if (waitpos_count >= 1)
		//	addmovespeed = waitpos_count * 0.03333f;
		//else
		//	addmovespeed = 0;
		//move_speed += addmovespeed;
		do_move = role_main->moveInTheDir(move_speed,role_move_pc,temp_dir);
		m_dir = temp_dir;
		if(do_move)
		{
			//if(last_dir != temp_dir)
			//{
			//	int step = 1;
			//	struct _AstarNode *path =  AStarPath;
			//	while(path->Next!=nullptr)
			//	{
			//		Point now = Point(path->X,path->Y);
			//		Point next = Point(path->Next->X,path->Next->Y);
			//		path = path->Next;
			//		if(path->Next==nullptr)
			//			break;
			//		Point next_next = Point(path->Next->X,path->Next->Y);
			//		if( next_next-next == next-now )
			//			step++;
			//		else
			//			break;	
			//	}
			//	sendPointsByPath(temp_dir,step);
			//}
			sendPointsByPath(temp_dir,1);
			last_dir = temp_dir;
			//moveLock(true);
			scroll2Tile(temp_tile);	
			AStarPath = AStarPath->Next;
			m_rocker_dir = dir_undef;
		}
		else if( role_main->getCurrActionState() < ACTION_STATE_ATTACK)
		{
			role_main->setPosition(tile2Space(start_tile));
			role_main->standed();
			if(m_walk_cb>0)
			{
				LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
				if (pStack != NULL)
				{
					pStack->executeFunctionByHandler(m_walk_cb, 0);
					pStack->clean();
				}
			}
			if(m_rock_cb>0)
			{
				LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
				if (pStack != NULL)
				{
					pStack->pushInt(3);
					pStack->executeFunctionByHandler(m_rock_cb, 1);
					pStack->clean();
				}
			}
			//stopAllActions();
		}
	}

	else if(m_rocker_dir < dir_undef)
	{
		last_dir = dir_undef;
		if( maxlock_num < 5 &&(islock_num > maxlock_num && !isStoryMap(m_mapId)))
		{
			//if(server_pos!= Point(0,0)&&islock_num>maxlock_num+2)
			//{
			//	role_main->stopAllActions();
			//	role_main->clearServerPoints();
			//	role_main->setPosition(tile2Space(server_pos));
			//	role_main->standed();
			//	scroll2Tile(server_pos);
			//	dir_next_tile = server_pos;
			//	islock_num = 0;
			//	waitpoint.clear();
			//	waitpos_count = 0;
			//	return;
			//}
			//moveLock(true);
			return ;
		}
		if(isBlock(start_tile)) return;
		Commen_Direction temp_dir = m_rocker_dir;
		start_tile = dir_temp_tile;
		if(isBlock(dir_next_tile))
		{
			Point tile = getNearTiled(dir_next_tile,m_rocker_dir);
			if(!isBlock(tile))
			{
				dir_next_tile = tile;
			}
		}
		if(!isBlock(dir_next_tile))
		{
			Point role_move_pc = tile2Space(dir_next_tile);
			bool do_move = false;
			Commen_Direction temp_dir = getDirByTile(dir_next_tile-start_tile);
			action_queue temp_p;
			temp_p.q_type = ACTION_MOVE_TYPE;
			temp_p.pos =dir_next_tile;
			role_main->insertServerPoint(temp_p);
			
			//if (waitpos_count >= 3)
			//	addmovespeed = 0.1f;
			//else if (waitpos_count >= 1)
			//	addmovespeed = waitpos_count * 0.03333f;
			//else
			//	addmovespeed = 0;
			//move_speed += addmovespeed;
			do_move=role_main->moveInTheDir(move_speed,role_move_pc,temp_dir);
			if(do_move)
			{
				sendPointsByPath(temp_dir,1);
				scroll2Tile(dir_next_tile);	
				AStarPath = NULL;
				dir_next_tile = roleMoveInDirection(m_rocker_dir);
			}
			else if( role_main->getCurrActionState() < ACTION_STATE_ATTACK)
			{
				role_main->setPosition(tile2Space(start_tile));
				role_main->standed();
				if(m_rock_cb>0)
				{
					LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
					if (pStack != NULL)
					{
						pStack->pushInt(4);
						pStack->executeFunctionByHandler(m_rock_cb, 1);
						pStack->clean();
					}
				}
				//stopAllActions();
			}
		}
	}
	else if(AStarPath && AStarPath->Next == NULL)
	{
		start_tile = dir_temp_tile;
		AStarPath = NULL;
		last_dir = dir_undef;
		//role_main->setPosition(tile2Space(start_tile));
		role_main->standed();
		if(m_walk_cb>0)
		{
			LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
			if (pStack != NULL)
			{
				pStack->executeFunctionByHandler(m_walk_cb, 0);
				pStack->clean();
			}
		}
		if(m_rock_cb>0)
		{
			LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
			if (pStack != NULL)
			{
				pStack->pushInt(3);
				pStack->executeFunctionByHandler(m_rock_cb, 1);
				pStack->clean();
			}
		}
	}
	else if(m_rocker_dir == dir_undef)
	{
		AStarPath = NULL;
		set_rock = false;
		//role_main->setPosition(tile2Space(start_tile));
		if(status == ACTION_STATE_WALK || status == ACTION_STATE_RUN)
		{
			role_main->standed();
			if(m_rock_cb>0)
			{
				LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
				if (pStack != NULL)
				{
					pStack->pushInt(4);
					pStack->executeFunctionByHandler(m_rock_cb, 1);
					pStack->clean();
				}
			}
		}
	}
	if (m_item_node)
	{
		int count = m_item_node->getChildrenCount();
		if (count > 800)
		{
			SortNode::setMaxSortStep(4);
			SpriteMonster::setMaxNumOneTile(2);
		}
		else if (count > 400)
		{
			SortNode::setMaxSortStep(2);
			SpriteMonster::setMaxNumOneTile(3);
		}
		else
		{
			SortNode::setMaxSortStep(1);
			SpriteMonster::setMaxNumOneTile(4);
		}
		
		Director* pDirector = Director::getInstance();
		if (pDirector->getShowUserNum() < 100000)
			pDirector->setShowUserNum(count);
				
		if (pDirector && pDirector->isDisplayStats() && pDirector->getDisplayType() == 100)
		{
			char str[512] = {0};
			char str2[64] = {0};
			
			sprintf(str, "%f/%d", addmovespeed, waitpos_count);
			for (int i = 0; i < waitpoint.size() && i < 10; i++)
			{
				sprintf(str2, "/ %d:%d", (int)waitpoint[i].x, (int)waitpoint[i].y);
				ccstrcat(str, str2);
			}
			pDirector->setDisplayLog(str);
		}
	}
}

void MapView::setRockDir(Commen_Direction dir)
{
	if(dir < dir_undef)
	{
		AStarPath = NULL;
		if(!set_rock || dir != m_rocker_dir)
		{
			m_rocker_dir = dir;
			dir_next_tile = roleMoveInDirection(m_rocker_dir);
		}
		set_rock = true;
	}
	else
		m_rocker_dir = dir;
}

bool MapView::getRockDirSet()
{
	return set_rock;
}

Point MapView::getNearTiled(Point dir_tile,Commen_Direction dir)
{
	Point tile = dir_tile;
	switch (dir)
	{
		case dir_up:
			do
			{
				tile.x = dir_tile.x + 1;
				if(!isBlock(tile)) break;
				tile.x = dir_tile.x - 1;
				if(!isBlock(tile)) break;
				tile.y = dir_tile.y + 1;
				tile.x = dir_tile.x + 1;
				if(!isBlock(tile)) break;
				tile.x = dir_tile.x - 1;
				if(!isBlock(tile)) break;
			}while(0);
			break;
		case dir_down:
			do
			{
				tile.x = dir_tile.x + 1;
				if(!isBlock(tile)) break;
				tile.x = dir_tile.x - 1;
				if(!isBlock(tile)) break;
				tile.y = dir_tile.y - 1;
				tile.x = dir_tile.x + 1;
				if(!isBlock(tile)) break;
				tile.x = dir_tile.x - 1;
				if(!isBlock(tile)) break;
			}while(0);
			break;
		case dir_left:
			do
			{
				tile.y = dir_tile.y + 1;
				if(!isBlock(tile)) break;
				tile.y = dir_tile.y - 1;
				if(!isBlock(tile)) break;
				tile.x = dir_tile.x + 1;
				tile.y = dir_tile.y + 1;
				if(!isBlock(tile)) break;
				tile.y = dir_tile.y - 1;
				if(!isBlock(tile)) break;
			}while(0);
			break;
		case dir_right:
			do
			{
				tile.y = dir_tile.y + 1;
				if(!isBlock(tile)) break;
				tile.y = dir_tile.y - 1;
				if(!isBlock(tile)) break;
				tile.x = dir_tile.x - 1;
				tile.y = dir_tile.y + 1;
				if(!isBlock(tile)) break;
				tile.y = dir_tile.y - 1;
				if(!isBlock(tile)) break;
			}while(0);
			break;
		case dir_right_up:
			do
			{
				tile = Point(dir_tile.x-1, dir_tile.y);
				if(!isBlock(tile)) break;
				tile = Point(dir_tile.x, dir_tile.y + 1);
				if(!isBlock(tile)) break;
				tile = Point(dir_tile.x-2, dir_tile.y);
				if(!isBlock(tile)) break;
				tile = Point(dir_tile.x, dir_tile.y+2);
				if(!isBlock(tile)) break;
			}while(0);
			break;
		case dir_right_down:
			do
			{
				tile = Point(dir_tile.x-1, dir_tile.y);
				if(!isBlock(tile)) break;
				tile = Point(dir_tile.x, dir_tile.y - 1);
				if(!isBlock(tile)) break;
				tile = Point(dir_tile.x-2, dir_tile.y);
				if(!isBlock(tile)) break;
				tile = Point(dir_tile.x, dir_tile.y-2);
				if(!isBlock(tile)) break;
			}while(0);
			break;
		case dir_left_down:
			do
			{
				tile = Point(dir_tile.x+1, dir_tile.y);
				if(!isBlock(tile)) break;
				tile = Point(dir_tile.x, dir_tile.y - 1);
				if(!isBlock(tile)) break;
				tile = Point(dir_tile.x+2, dir_tile.y);
				if(!isBlock(tile)) break;
				tile = Point(dir_tile.x, dir_tile.y-2);
				if(!isBlock(tile)) break;
			}while(0);
			break;

		case dir_left_up:
			do
			{
				tile = Point(dir_tile.x+1, dir_tile.y);
				if(!isBlock(tile)) break;
				tile = Point(dir_tile.x, dir_tile.y + 1);
				if(!isBlock(tile)) break;
				tile = Point(dir_tile.x+2, dir_tile.y);
				if(!isBlock(tile)) break;
				tile = Point(dir_tile.x, dir_tile.y+2);
				if(!isBlock(tile)) break;
			}while(0);
			break;
		default:
			break;
	}
	return tile;
}

void MapView::sendPointsByPath(Commen_Direction dir,int step)
{
	if(isStoryMap(m_mapId)) return;
	
	//if(step > 1)
	//{
	//	int i = 0;
	//	Point pos = start_tile;
	//	do
	//	{
	//		i++;
	//		pos = pos + getTileByDir(dir);
	//	}while(!isBlock(pos)&&(i<step));
	//	step = i;
	//}

	if(dir<dir_undef)
	{
		//log("FrameMoveToProtocol: -> pos_x:%d -> pos_y:%d",(int)start_tile.x,(int)start_tile.y);

#if 0
		LuaMsgBuffer* buffer = LuaEventManager::instance()->getLuaEvent(1013);
		struct pbc_wmessage * pbw = pbc_wmessage_new(g_registerEnv, "FrameMoveToProtocol");
		if (pbw == NULL) {
			return;
		}
		pbc_wmessage_integer(pbw, "x", start_tile.x , 0);
		pbc_wmessage_integer(pbw, "y", start_tile.y , 0);
		pbc_wmessage_integer(pbw, "dir",(char)dir , 0);

		//pbc_wmessage_integer(pbw, "speed", map_speed*1000 , 0);
		//pbc_wmessage *pb = pbc_wmessage_message(pbw,"paths");
		//pbc_wmessage_integer(pb, "dir",dir , 0);
		//pbc_wmessage_integer(pb, "len", step , 0);

		//buffer.pushInt(role_main->getRoleId());//角色id
		//buffer.pushShort(map_speed*1000);
		////buffer.pushBool(true);
		////if(move_speed > SPEED*1.2)
		////	buffer.pushChar(1);//移动类型
		////else 
		////	buffer.pushChar(2);//移动类型
		//buffer.pushShort(m_mapId);//地图id
		//buffer.pushShort(start_tile.x);//位置x
		//buffer.pushShort(start_tile.y);//位置y
		//buffer.pushChar(1);
		//buffer.pushChar(dir);
		//buffer.pushChar(step);
		pbc_slice slice;
		pbc_wmessage_buffer(pbw, &slice);
		//buffer->pushShort(slice.len);
		buffer->pushData(slice.buffer, slice.len);
		LuaSocket::getInstance()->sendSocket(buffer);
		pbc_wmessage_delete(pbw);
#else
		int x = start_tile.x;
		int y = start_tile.y;
		/*
		if (x >= 0 && x <= 255 && y >= 0 && y <= 255)
		{
			LuaMsgBuffer* buffer = LuaEventManager::instance()->getLuaEvent(1041);
			buffer->pushUChar(x);
			buffer->pushUChar(y);
			buffer->pushChar(dir);
			LuaSocket::getInstance()->sendSocket(buffer);
		}
		else
		{
			LuaMsgBuffer* buffer = LuaEventManager::instance()->getLuaEvent(1042);
			buffer->pushShort(x);
			buffer->pushShort(y);
			buffer->pushChar(dir);
			LuaSocket::getInstance()->sendSocket(buffer);
		}*/
#endif


		moveLock(true);

		++waitpos_count;
		Director* pDirector = Director::getInstance();
		if (pDirector && pDirector->isDisplayStats())
		{
			if (pDirector->getDisplayType() == 100)
			{
				waitpoint.push_back(start_tile);
			}
			else if (pDirector->getDisplayType() == 101)
			{
				if (lastsendx < 0)
				{
					lastsendx = start_tile.x;
					lastsendy = start_tile.y;
				}
				else
				{
					int disx = start_tile.x - lastsendx;
					int disy = start_tile.y - lastsendy;

					if (abs(disx) > 1 || abs(disy) > 1)
					{
						errormove = 1;
						errorlastx = lastsendx;
						errorlasty = lastsendy;
						errorsendx = start_tile.x;
						errorsendy = start_tile.y;
					}
					char str[128] = {0};
					if (errormove == 1)
						sprintf(str, "%d:%d / %d:%d / %d:%d", disx, disy, errorlastx, errorlasty, errorsendx, errorsendy);
					else
						sprintf(str, "%d:%d", disx, disy);
					pDirector->setDisplayLog(str);

					lastsendx = start_tile.x;
					lastsendy = start_tile.y;
				}
			}
		}
		

		//static unsigned int last =  GetTickCount();
		//unsigned int cur = GetTickCount();

		//CCLOG("[MapView::sendPointsByPath] %u", cur - last );

		//last = cur;
		
		return;
	}
}

void MapView::sendPointsByAstarPathEx()
{
	sendPointsByAstarPath(AStarPath);
	if(m_rock_cb>0&&AStarPath!=NULL)
	{
		LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
		if (pStack != NULL)
		{
			pStack->pushInt(0);
			pStack->executeFunctionByHandler(m_rock_cb, 1);
			pStack->clean();
		}
	}
}


void MapView::sendPointsByAstarPath(struct _AstarNode *startpath,SpriteMonster* monster)
{
	//return;
	if(isStoryMap(m_mapId)) return;
	struct _AstarNode *path =  startpath;
	//CCLOG("sendPointsByAstarPath");
	if(path == NULL || isStoryMap(m_mapId)) return;
	struct _AstarNode *path1 =  path->Next;
	//CCLOG("sendPointsByAstarPath1");
	if(path1==NULL) return;
	//CCLOG("sendPointsByAstarPath2");
	/*
	LuaEventManager *luaEventMgr = LuaEventManager::instance();
	LuaMsgBuffer* buffer = luaEventMgr->getLuaEvent(1013);

	if(monster == NULL)
	{
		buffer->pushInt(role_main->getRoleId());//角色id
		buffer->pushShort(map_speed*1000);
		//if(map_speed > SPEED*1.2 || m_steps <= 2 )
		//	buffer->pushChar(1);//移动类型
		//else 
		//	buffer->pushChar(2);//移动类型
	}
	else
	{
		//CCLOG("id%d",monster->getTag());
		buffer->pushInt(monster->getTag());//角色id
		buffer->pushShort(map_speed*1000);
		//buffer->pushChar(1);//移动类型
	}
	//buffer->pushBool(false);
	buffer->pushShort(m_mapId);//地图id
	buffer->pushShort(path->X);//位置x
	buffer->pushShort(path->Y);//位置y
	*/
	int i = 0,j = 0,step = 0;	
	Commen_Direction old_dir,new_dir;
	old_dir =  getDirByTile(Point(path1->X,path1->Y)-Point(path->X,path->Y));
	//CCLOG("(path1->X:%dpath1->Y:%d",path->X,path->Y);
	while(path->Next!=NULL)
	{
		path = path->Next;
		path1 = path->Next;
		//CCLOG("(path1->X:%dpath1->Y:%d",path->X,path->Y);
		if(path1 != NULL)
		{
			new_dir = getDirByTile(Point(path1->X,path1->Y)-Point(path->X,path->Y));
			if(new_dir != old_dir)
			{   
				//拐点 
				old_dir = new_dir;
				j++;
			}
		}
		step++;
	}
	//buffer->pushChar(j+1);
	path =  startpath;
	path1 =  path->Next;
	if(path1 != NULL)
	{
		old_dir =  getDirByTile(Point(path1->X,path1->Y)-Point(path->X,path->Y));
		//buffer->pushChar(old_dir);
	}
	//CCLOG("old_dir%d",old_dir);
	while(path->Next!=NULL)
	{
		new_dir = getDirByTile(Point(path->Next->X,path->Next->Y)-Point(path->X,path->Y));
		//if(path1 != NULL)
		{
			if(new_dir != old_dir)
			{   
				//拐点 
				old_dir = new_dir;
				//buffer->pushChar(i);
				//buffer->pushChar(old_dir);
				//CCLOG("o_dir%d",old_dir);
				i = 0; 
			}	
		}
		i++;
		path = path->Next;
		path1 = path->Next;
		if(step==0)
			break;
		step--;
	}
	//buffer->pushChar(i);
	//LuaSocket::getInstance()->sendSocket(buffer);

}

void MapView::startRocker(Commen_Direction dir,float distance)
{
	if((_m_rock_time - _m_rock_time_ex)>=0.05 && m_rocker_dir != dir && role_main!=NULL && role_main->getCurrActionState()<=ACTION_STATE_CREATE&&role_main->getCurrActionState()!=ACTION_STATE_COLLIDE)
	{
		if(isBlock(start_tile))
			return;
		if(m_rocker_dir >= dir_undef || set_rock)
		{
			if(role_main->getCurrActionState() == ActionState::ACTION_STATE_IDLE)
				_m_time = move_speed;
			islock_num = 0;
			m_rocker_dir = dir;
			//sendPointsByPath(dir,1);
			if(m_rock_cb>0)
			{
				LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
				if (pStack != NULL)
				{
					pStack->pushInt(2);
					pStack->executeFunctionByHandler(m_rock_cb, 1);
					pStack->clean();
				}
			}
		}
		m_rocker_dir = dir;
		dir_next_tile = roleMoveInDirection(m_rocker_dir);
		_m_rock_time_ex = _m_rock_time;
	}
	set_rock = false;
	AStarPath = NULL;
}

void MapView::stopRocker() 
{	
	set_rock = false;
	if(m_rocker_dir < dir_undef)
	{
		start_tile = dir_temp_tile;
		//sendPointsByPath(m_rocker_dir,0);
		m_rocker_dir = dir_undef;
		if((_m_rock_time - _m_rock_time_ex) < move_speed &&m_rock_cb>0)
		{
			LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
			if (pStack != NULL)
			{
				pStack->pushInt(5);
				pStack->executeFunctionByHandler(m_rock_cb, 1);
				pStack->clean();
			}
		}

	}
}

void MapView::resetSpeed(double speed)
{
	if(role_main!=NULL)
	{
		role_main->setSpeed(speed);
		if(role_main->isChangeModeDisplay()&&role_main->getCurrActionState() == ACTION_STATE_RUN)
		{
			role_main->m_roledata.actiontime = speed*2.8;
			role_main->reloadRes();
		}
	}
	map_speed = speed;
	//scroll2Tile(start_tile);	
}

Point MapView::getSideTilePos(Point pos_dest,int sub) 
{	
	Point tile_start = start_tile;
	Point tile_dest = space2Tile(pos_dest);
	Point sub_tile = tile_dest - tile_start;
	Point r_pos = Point();

	float angle = sub_tile.getAngle();
	float tanAngel = tan(angle);
	Commen_Direction dir = dir_up;
	if(tanAngel < tan(PI/8))
	{
		if(sub_tile.x < 0)
			dir = dir_left;
		else
			dir = dir_right;
	}
	else if(tanAngel > tan(PI*3/8))
	{
		if(sub_tile.y > 0)
			dir = dir_up;
		else
			dir = dir_down;
	}
	else
	{
		if(sub_tile.x < 0 && sub_tile.y < 0)
			dir = dir_left_down;
		else if(sub_tile.x < 0 && sub_tile.y > 0)
			dir = dir_left_up;
		else if(sub_tile.x > 0 && sub_tile.y > 0)
			dir = dir_right_up;
		else
			dir = dir_right_down;
	}
	r_pos = tile_dest - getTileByDir(dir)*sub;

	return r_pos;
}

void MapView::setMaxLockNum(unsigned short lock_num) 
{	
	maxlock_num = lock_num;
}

bool MapView::isShowMonsterPos()
{
	return (maxlock_num > 5);
}

void MapView::moveLock(bool lock) 
{	
	if(maxlock_num >= 5)
	{
		islock_num = 0;
		return;
	}
	if(lock)
		islock_num++;
	else if(islock_num>0)
		islock_num--;
}

void MapView::playStandEffect(Point pos) 
{
	/*if (m_effect)
	{
		m_effect->setPosition(pos-Point(0,20));
		m_effect->playActionData("hitwark",11,0.5,1);
	}*/
}

Point MapView::roleMoveInDirection(Commen_Direction dir) 
{
	Point next_tile = Point();
	switch (dir)
	{
		case dir_up:
			next_tile.x = dir_temp_tile.x;
			next_tile.y = dir_temp_tile.y - 1;
			break;
		case dir_down:
			next_tile.x = dir_temp_tile.x ;
			next_tile.y = dir_temp_tile.y + 1;
			break;
		case dir_left:
			next_tile.x = dir_temp_tile.x - 1;
			next_tile.y = dir_temp_tile.y ;
			break;
		case dir_right:
			next_tile.x = dir_temp_tile.x + 1;
			next_tile.y = dir_temp_tile.y ;
			break;
		case dir_right_up:
			next_tile.x = dir_temp_tile.x + 1;
			next_tile.y = dir_temp_tile.y - 1;
			break;
		case dir_right_down:
			next_tile.x = dir_temp_tile.x + 1;
			next_tile.y = dir_temp_tile.y + 1;
			break;
		case dir_left_down:
			next_tile.x = dir_temp_tile.x - 1;
			next_tile.y = dir_temp_tile.y + 1;
			break;
		case dir_left_up:
			next_tile.x = dir_temp_tile.x - 1;
			next_tile.y = dir_temp_tile.y - 1;
			break;
		default:
			break;
	}
	return next_tile;
}


void MapView::registerHurtCb(int handler)
{
	removeHurtCb();
	m_hurt_cb = handler;
}

void MapView::removeHurtCb()
{
	if(m_hurt_cb > 0)
	{
		LuaEngine::getInstance()->removeScriptHandler(m_hurt_cb);
		m_hurt_cb = 0;
	}
}

void MapView::registerWalkCb(int handler)
{
	removeWalkCb();
	m_walk_cb = handler;
}

void MapView::removeWalkCb()
{
	if(m_walk_cb > 0)
	{
		LuaEngine::getInstance()->removeScriptHandler(m_walk_cb);
		m_walk_cb = 0;
	}
}

void MapView::registerRockerCb(int handler)
{
	removeRockerCb();
	m_rock_cb = handler;
}

void MapView::removeRockerCb()
{
	if(m_rock_cb > 0)
	{
		LuaEngine::getInstance()->removeScriptHandler(m_rock_cb);
		m_rock_cb = 0;
	}
}
void MapView::registerTouchMoveCb(int handler)
{
	removeTouchMoveCb();
	m_touch_move_cb = handler;
}

void MapView::removeTouchMoveCb()
{
	if(m_touch_move_cb > 0)
	{
		LuaEngine::getInstance()->removeScriptHandler(m_touch_move_cb);
		m_touch_move_cb = 0;
	}
}

Commen_Direction MapView::GetDirByPos(const Point& src, const Point& dst)
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

bool MapView::isStoryMap(int mapId)
{
	switch(mapId)
	{
	case 1000:
    case 2116:
	case 2117:
	case 2118:
	case 2119:
	case 2134:
	case 2135:
	case 5001:
	case 5002:
	case 5004:
	case 5006:
	case 5007:
	case 5009:
	case 5018:
	case 5019:
		return true;
	default:
        break;
	}

	return false;
}

// -----------------------------------------------------------
// MapViewResLoadMgr
// -----------------------------------------------------------
static MapViewResLoadMgr *_sharedMapViewResLoadMgr = nullptr;

MapViewResLoadMgr* MapViewResLoadMgr::getInstance()
{
    if (! _sharedMapViewResLoadMgr)
    {
        _sharedMapViewResLoadMgr = new MapViewResLoadMgr();
    }

    return _sharedMapViewResLoadMgr;
}

void MapViewResLoadMgr::destroyInstance()
{
    CC_SAFE_RELEASE_NULL(_sharedMapViewResLoadMgr);
}

MapViewResLoadMgr::MapViewResLoadMgr()
{
}

MapViewResLoadMgr::~MapViewResLoadMgr()
{
}

void MapViewResLoadMgr::addImageAsync(const std::string &path)
{
	Director::getInstance()->getTextureCache()->addImageAsync(path, CC_CALLBACK_1(MapViewResLoadMgr::imageLoaded,this));  
}

void MapViewResLoadMgr::imageLoaded(cocos2d::Texture2D *texture)
{
	if (texture == nullptr)
		return;

	if (g_MapView)
		g_MapView->addTextureSprite1(texture);
}


// -----------------------------------------------------------
// MapSimpleResLoadMgr
// -----------------------------------------------------------
MapSimpleResLoadMgr * MapSimpleResLoadMgr::s_instance = nullptr;

MapSimpleResLoadMgr * MapSimpleResLoadMgr::getInstance()
{
	if (s_instance == nullptr)
	{
		s_instance = new MapSimpleResLoadMgr;
	}
	return s_instance;
}

void MapSimpleResLoadMgr::destroyInstance()
{
	CC_SAFE_RELEASE_NULL(s_instance);
}

MapSimpleResLoadMgr::MapSimpleResLoadMgr()
{
	//Director::getInstance()->getScheduler()->schedule(SEL_SCHEDULE(&MapSimpleResLoadMgr::updateSF), this, 0.03f, false);
}


MapSimpleResLoadMgr::~MapSimpleResLoadMgr()
{
	//Director::getInstance()->getScheduler()->unschedule(SEL_SCHEDULE(&MapSimpleResLoadMgr::updateSF), this);
}

SpriteFrame * MapSimpleResLoadMgr::getSpriteFrameByImgName(const std::string & imgName)
{
	std::string textureFullPath = FileUtils::getInstance()->fullPathForFilename(imgName);
	if (textureFullPath.empty())
	{
		CCLOGWIN32("MapSimpleResLoadMgr::getSpriteFrameByImgName: file %s not exist", imgName.c_str());
		return nullptr;
	}

	Texture2D * tex = Director::getInstance()->getTextureCache()->getTextureForKeyFullPath(textureFullPath);
	if (tex != nullptr)
	{
		/*
		系统里有的就不再重复延迟返回了
		也可以注释掉此段代码测试地图在移动出可视范围后的区域是否已经被释放，再次显示时是否会再次调用此代码加载纹理
		*/
		return SpriteFrame::createWithTexture(tex, Rect(0.f, 0.f, tex->getContentSize().width, tex->getContentSize().height));
	}
	
	// check if file exists
	//if (!FileUtils::getInstance()->isFileExist(textureFullPath))
	//{
	//	CCLOGWIN32("MapSimpleResLoadMgr::getSpriteFrameByImgName: file %s not exist 2", imgName.c_str());
	//	return nullptr;
	//}

	bool hasFound = false;
	VecLoadingSpriteFrame::iterator ret = _sfWaitingToLoad.begin();
	for (; ret != _sfWaitingToLoad.end(); ++ret)
	{
		if (ret->first == textureFullPath)
		{
			hasFound = true;
			break;
		}
	}

	if (!hasFound)
		Director::getInstance()->getTextureCache()->addImageAsync(textureFullPath, CC_CALLBACK_1(MapSimpleResLoadMgr::imageLoaded, this), false);

	SpriteFrame *sf = SpriteFrame::createWithTexture(nullptr, Rect(0.f, 0.f, 2, 2));
	if (sf)
	{
		sf->retain();		
		_sfWaitingToLoad.push_back(std::make_pair(textureFullPath, sf));
	}

	return sf;
}

void MapSimpleResLoadMgr::imageLoaded(cocos2d::Texture2D *texture)
{
	if (texture == nullptr)
		return;
	
	const std::string& textureFullPath = Director::getInstance()->getTextureCache()->GetLoadAsyncTextureFullPath();
	if (textureFullPath.empty())
		return;

	for (auto it = _sfWaitingToLoad.begin(); it != _sfWaitingToLoad.end();)
	{
		if (it->second->getReferenceCount() == 1) // 已经被使用者抛弃
		{
			it->second->release();
			it = _sfWaitingToLoad.erase(it);
			continue;
		}

		if (textureFullPath == it->first)
		{
			it->second->setTexture(texture);
			it->second->release();
			it = _sfWaitingToLoad.erase(it);
			continue;
		}
		
		++it;
	}
}

void MapSimpleResLoadMgr::updateSF(float)
{
	// 模拟加载缓慢及边玩边下载的情况
	std::pair<std::string, SpriteFrame *> sfInfo;
	bool hasFound = false;
	while (true)
	{
		if (_sfWaitingToLoad.empty()) return;

		auto __sfInfo = _sfWaitingToLoad.back();
		_sfWaitingToLoad.pop_back();

		if (__sfInfo.second->getReferenceCount() == 1) // 已经被使用者抛弃
		{
			__sfInfo.second->release();
			continue;;
		}
		sfInfo = __sfInfo;
		hasFound = true;
		break;
	}

	if (hasFound)
	{
		Texture2D * tex = Director::getInstance()->getTextureCache()->addImage(sfInfo.first);
		if (tex != nullptr)
			sfInfo.second->setTexture(tex);
		sfInfo.second->release();
	}

}
