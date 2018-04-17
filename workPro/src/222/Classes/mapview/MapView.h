#ifndef  __SCENE_VIEW_H__
#define  __SCENE_VIEW_H__

//#include "socket/LuaMsgData.h"
//#include "FindPath.h"
#include "cocos2d.h"
#include "mapview/MapViewBase.h"
//#include "effects/CCEffects.h"
#include "sprites/SpritePlayer.h"
#include "MirControl/MirBatchDrawLabel.h"
#include "SortNode.h"
//#include "socket/LuaMsgBuffer.h"
#include <queue>
//#include <thread>

#define PI				3.14159
#define SPEED				0.20
#define MAP_SPAN			10

#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

struct _DisplayNode
{
	unsigned int x, y;					// F, G值
	unsigned int tag;			// 父亲指针
	cocos2d::Sprite* sp;
	bool Status;				// false:不显示  true:显示
	bool loaded;				// false:不显示  true:显示
	struct _DisplayNode *Next;			// OpenList中下一个节点
};

struct _moveNode
{
	cocos2d::Point now_pos;					
	Commen_Direction dir;			
	struct _moveNode *Next;			
};


class MapView : public MapViewBase
{
	friend class LuaSocket;
	friend class MapViewResLoadMgr;
	friend class SpriteMonster;

public:
	MapView();
	virtual ~MapView();
	//static void DoPopLuaMsgs();
	//static void DoPushLuaMsg(LuaMsgData *data);
	static cocos2d::Node* getBloodNode();
	static void resetBloodNode();
	static MirBatchDrawLabel* getNameNode();
	static cocos2d::Node* getTitleNode();
	static SortNode* getDressNode();
	static void setDressNodeReorder();
	//static SortNode* getWingDownNode();
	//static cocos2d::Node* getWingUpNode();
	//static SortNode* getWeaponDownNode();
	//static cocos2d::Node* getWeaponUpNode();
	//static SortNode* getHeadNode();
	static cocos2d::Node* getSkillNode();
	static cocos2d::Node* getSkillDownNode();
	//static SortNode* getRideNode();
	static cocos2d::Node* getTheTopNode();
	static cocos2d::Node* getTheDownNode();
	//创建一个场景层
	static MapView *create();
	static MapView *create(const std::string& filename, const int mapId, const cocos2d::Point pos = cocos2d::Point());


	virtual void setScale(float scale);

	void loadSpritesPre();
	bool isHasAllLoaded();
	//bool isHasStopThead();
	void setBlockRectValue(cocos2d::Rect rect,const char* value);
	//该tile位置是否阻挡
	bool isBlock(cocos2d::Point tile);
	//该tile位置是否透明
	bool isOpacity(cocos2d::Point tile);
	

	static float getFlyTime(const cocos2d::Vec2& startpos, const cocos2d::Vec2& endpos, float flySpeed);

	//tile坐标转空间坐标
	virtual cocos2d::Point tile2Space(cocos2d::Point tile);
	//空间坐标转tile坐标
	virtual cocos2d::Point space2Tile(cocos2d::Point pos);

	//tile坐标转位置坐标
	//cocos2d::Point tile2Point(cocos2d::Point tile);
	
	//滚屏到指定tile为中心的位置
	void scroll2Tile(cocos2d::Point tile,float speed = 0.0f);

	cocos2d::Point getDestPosition(cocos2d::Point start_pos,int span);

	//获取寻路对象
	//AStarFinder* getPathFinder() { return &m_pathFinder; }
	
	void moveMapByPos(cocos2d::Point cp,bool isnear = true);
	void moveMonsterByPos(cocos2d::Point cp,SpriteMonster*,float sp = 3.0,bool isnear = true,std::vector<cocos2d::Point>* tabl = NULL);

	void update(float dt);

	void startRocker(Commen_Direction dir, float distance);
	void stopRocker();
	void resetSpeed(double distance);
	

	CC_SYNTHESIZE(SpritePlayer*, role_main, MainRole);
	CC_SYNTHESIZE(bool,is_act_map, MapActionFlag);

	void initDataAndFunc(cocos2d::Point start = cocos2d::Point());
	
	void registerWalkCb(int handler);
	void registerRockerCb(int handler);
	void registerTouchMoveCb(int handler);
	void registerHurtCb(int handler);
	void removeWalkCb();
	void removeTouchMoveCb();
	void removeRockerCb();
	void removeHurtCb();

	void cleanAstarPath(bool stop=false,bool nosend = false);
	cocos2d::Point getNearTiled( cocos2d::Point dir_tile,Commen_Direction dir);
	
	//void stopMapAction();
	std::vector<cocos2d::Point> getPathByPos(cocos2d::Point start,cocos2d::Point dest);
	std::vector<cocos2d::Point> getRolePath();
	int getRolePathNum();
	bool loadMapNew(const std::string& filename, const  int mapId, const Point mpos = cocos2d::Point());
	bool loadMap(const std::string& filename, const int mapId, const cocos2d::Point pos = cocos2d::Point());
	bool hasPath();
	#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
		//unsigned long getCurrMemory();
	#endif
	
	//void newAstar2();
	void moveLock(bool);
	void setRockDir(Commen_Direction dir);
	bool getRockDirSet();
	void setAttackFlag(bool);
	cocos2d::Point getCurTile() {return start_tile;};

	virtual void setPosition(const cocos2d::Point &position);
	char getSpeedUp(SpriteMonster*r_node);
		
	// 获取对象根节点
	virtual cocos2d::Node* GetItemRoot();
	virtual cocos2d::Node* getSkillRootNode()	{ return s_skill_node; }

	// 判断对象是否超出屏幕范围
	bool IsOutoffScreen(const cocos2d::Vec2& pos);
	// 获取朝向
	static Commen_Direction GetDirByPos(const Point& src, const Point& dst);
	static void setMaxLockNum(unsigned short lock_num);
	static bool isShowMonsterPos();
	static void resetShowHurt(bool visible);

	//static void onMsgHandler(int idx);	

	bool isStoryMap(int mapId);

	//返回场景layer Size
	cocos2d::Size& getMapSize() { return m_mapSize; }

	cocos2d::Size& getTileSize() { return m_perTileSize; }
private:


	//获取屏幕中央的tile坐标
	cocos2d::Point getCenterTile();

	//空间坐标转屏幕坐标
	cocos2d::Point space2Screen(cocos2d::Point pos);
	//屏幕坐标转空间坐标
	cocos2d::Point screen2Space(cocos2d::Point point);

	//tile坐标转屏幕坐标
	cocos2d::Point tile2Screen(cocos2d::Point tile);
	//屏幕坐标转tile坐标
	cocos2d::Point screen2Tile(cocos2d::Point point);	

	cocos2d::Point getSideTilePos(cocos2d::Point,int);

private:
	bool loadMap_imp(const std::string& filename, const int mapId, const cocos2d::Point pos = cocos2d::Point());
	void resetDisplay(const cocos2d::Point pos = cocos2d::Point());
	void tickCache(float dt);
	void addCacheSpritesPre();
	void addMapSpritesPre();
	void addMapSprites();
	void addCacheSprites();
	void freeMapSprite(int);
	void addTextureSprite(cocos2d::Texture2D *);
	void addTextureSprite1(cocos2d::Texture2D *);
	void scrollMap(cocos2d::Point pos);
	void playStandEffect(cocos2d::Point pos) ;
	void setDisplayMap(int x,int y);
	bool getDisplayStatus(int x,int y,int x1,int y1);
	//bool getDisplayStatus_ex(int x,int y,int x1,int y1);

	float getLeftTime(){ return (move_speed-_m_time);};

	void newAstar();
	void moveMapByPosEx(cocos2d::Point cp,bool isnear);
	//void moveMapByPath(float dt);
	void moveMapByTouch(cocos2d::Point t);

	cocos2d::Point roleMoveInDirection(Commen_Direction dir);

	void sendPointsByPath(Commen_Direction dir,int step);
	void sendPointsByAstarPath(struct _AstarNode *startpath,SpriteMonster* monster = NULL);
	void sendPointsByAstarPathEx();

	// 是否普通技能
	//bool IsCommonSkill(int skillId);
	//void onMoveFailed(LuaMsgBuffer& pBuff);
	//void onDoMove_netBuffer(LuaMsgBuffer& pBuff);
	//void onDoMove_netBuffer2(LuaMsgBuffer& pBuff);
	//void onDoMove_pbcBuffer(LuaMsgBuffer& pBuff);
	void onDoMove(int objId, short pos_x, short pos_y);
	void onDelayMove(SpriteMonster*r_node,cocos2d::Point start_point);
	//void onPlaySkill_netBuffer(LuaMsgBuffer& pBuff);
	//void onPlaySkill_netBuffer2(LuaMsgBuffer& pBuff);
	//void onPlaySkill_pbcBuffer(LuaMsgBuffer& pBuff);
	//void onPlaySkill(int objId, int tarId, int skill_id, int pos_x, int pos_y, int skilLevel, int skillColor);
	//void onDelayPlaySkill(SpriteMonster*r_node,action_queue skill_data);
	//void onCrash(LuaMsgBuffer& pBuff);
	//void onDelayCrash(SpriteMonster*r_node,action_queue skill_data);
	//void onDelayCrashed(SpriteMonster*r_node,action_queue skill_data);
	//void onShowHurt(LuaMsgBuffer& pBuff);
	void onShowHurtNumber(int number,cocos2d::Point pos,char f_type,bool ishit,cocos2d::Point span_pos, int resistType);
	//void onSkillMove(LuaMsgBuffer& pBuff);
	//void onDelaySkillMove(SpriteMonster*r_node,action_queue move_data);	
private:
	cocos2d::Size			m_mapSize;
	cocos2d::Size			m_winSize;
	cocos2d::Size			m_perTileSize;

	cocos2d::Node*	m_pMap;
	cocos2d::Node*  m_item_node;
	cocos2d::Node*  m_hit_node;	

	cocos2d::Node*  title_node;
	cocos2d::Node*  s_skill_node;
	cocos2d::Node*  s_skill_downnode;
	cocos2d::Node*  down_node;
	cocos2d::Node*  top_node;

	SortNode*  blood_node;
	SortNode*  dress_node;

	MirBatchDrawLabel* s_name_node;

	bool m_isNewMap;
	//cocos2d::Node  *	_mapNode;
	//cocos2d::TMXLayer*		m_pBolck;
	std::string m_block_str;
	bool loadall;
	unsigned short islock_num;
	bool set_rock;
	bool attack_flag;
	bool _isnear_ ;
	cocos2d::Point _move_end_tile;
	struct _AstarNode *AStarMap;
	struct _AstarNode *AStarMap2;
	struct _AstarNode *AStarPath;

	//struct _DisplayNode *DisplayMap;

	cocos2d::Point start_tile;
	cocos2d::Point dir_next_tile;
	cocos2d::Point dir_temp_tile;
	cocos2d::Point m_touch_tile;
	Commen_Direction m_rocker_dir;
	Commen_Direction m_dir;
	float map_speed;
	float move_speed;
	float addmovespeed;
	float _m_time;
	float _m_rock_time;
	float _m_rock_time_ex;

	//Effects *m_effect;
	int rocker_loop;
	int m_walk_cb;
	int m_rock_cb;
	int m_hurt_cb;
	int m_touch_move_cb;
	int m_mapId;
	int m_show_hurt_count;
	cocos2d::Point server_pos;
	cocos2d::Point role_pos;
	//std::string mapstr;
	//cocos2d::Size win;
	//char *blocks;
	//std::thread *load_Thread;
	Commen_Direction last_dir;
	std::string mapstr;
	std::vector<cocos2d::Point> waitpoint;
	int		waitpos_count;
};

extern MapView* g_MapView;

class MapViewResLoadMgr : public cocos2d::Ref
{
public:
	static MapViewResLoadMgr* getInstance();
	static void destroyInstance();

protected:
	MapViewResLoadMgr();

public:
	virtual ~MapViewResLoadMgr();

	void addImageAsync(const std::string &path);
	void imageLoaded(cocos2d::Texture2D *texture);
};

// -----------------------------------------------------------
// SimpleResLoadMgr
// -----------------------------------------------------------
class MapSimpleResLoadMgr : public cocos2d::Ref
{
public:
	static MapSimpleResLoadMgr * getInstance();
	static void destroyInstance();

	MapSimpleResLoadMgr();
	~MapSimpleResLoadMgr();

	cocos2d::SpriteFrame * getSpriteFrameByImgName(const std::string & imgName);

	void imageLoaded(cocos2d::Texture2D *texture);

private:
	void updateSF(float);
private:
	static MapSimpleResLoadMgr * s_instance;
	typedef std::vector<std::pair<std::string, cocos2d::SpriteFrame *>> VecLoadingSpriteFrame;
	VecLoadingSpriteFrame  _sfWaitingToLoad;
};

#endif