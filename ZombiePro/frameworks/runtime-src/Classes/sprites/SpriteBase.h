#ifndef _SPIRIT_BASE_H_
#define _SPIRIT_BASE_H_

#include "cocos2d.h"
#include "Commen_ActionToDo.h"
#include "Commen_Direction.h"
#include "MainRoledata.h"
#include "GraySprite.h"
#include "mapview/MapTileNode.h"

#define PI				3.14159
typedef enum {
	ACTION_STATE_NONE = 0,
	ACTION_STATE_IDLE,
	ACTION_STATE_WALK,
	ACTION_STATE_RUN,
	ACTION_STATE_ATTACK,
	ACTION_STATE_MAGICUP,
	ACTION_STATE_ATTACK_EX1,
	ACTION_STATE_ATTACK_EX2,
	ACTION_STATE_MAGICUP_EX1,
	ACTION_STATE_MAGICUP_EX2,
	ACTION_STATE_COLLIDE,
	ACTION_STATE_HURT,
	ACTION_STATE_DIG,
	ACTION_STATE_EXCAVATE,
	ACTION_STATE_CHANGE,
	ACTION_STATE_SPECAIL,
	ACTION_STATE_CREATE,
	ACTION_STATE_UNCREATE,
	ACTION_STATE_MABI,
	ACTION_STATE_CRASHED,
	ACTION_STATE_DEAD,
	ACTION_STATE_REMOVE,
}ActionState;

typedef enum {
	BASE_TYPE = 0,
	NPC_TYPE = 1,
	WUQI_TYPE = 2,
	HOE_TYPE = 3,
	HEAD_TYPE = 4,
	WING_TYPE_left = 5,
	WING_TYPE = 6,
	RIDE_TYPE_UP = 7,
	RIDE_TYPE_DOWN = 8,
	PIFENG_TYPE = 9,
	NORMAL_MONSTER = 10,
	ELIT_MONSTER,
	BOSS_MONSTER,
	PET_MONSTER = 15,
	PLAYER_MANE_TYPE = 21,
	PLAYER_FEMALE_TYPE = 22,
	ACTOR_TYPE = 30,
	SHOW_TYPE,
	ANOTHER_TYPE=40,
}SpriteType;


enum E_NEED_RECALC_PLIST_NUM
{
	E_NRPN_NULL,
	E_NRPN_OLD,
	E_NRPN_NEW,
	E_NRPN_LOADERROR,
};

class SpriteBase : public MapTileNode
{
public: 
	SpriteBase();
	virtual ~SpriteBase(void);

	virtual bool isTouchInside(cocos2d::Touch* thisPos);
	static SpriteBase* create(const std::string&pszFileName);
	static void subCacheCount();
	static SpriteBase* create(const std::string&pszFileName,cocos2d::Size touch_size);
	//virtual bool init(MainRoledata roledata);  
	virtual void setBaseUrl(const std::string&pszFileName);
	std::string getBaseUrl();
	virtual void playAction(float times,Commen_ActionToDo action,Commen_Direction dir,int loop,float ltimes=0.0f);
	void initStandStatus(int standcut,int maxcut,float times,Commen_Direction dir);
	void initWalkStatus(int maxcut, float actrate = 0.6f);
	void initRunStatus(int maxcut);
	void initAttackStatus(int maxcut);
	void initHurtStatus(int maxcut);
	void initMagicStatus(int maxcut);
	void initMaxDeathCut(int maxcut){ m_death_cut = maxcut; };

	virtual void visit(cocos2d::Renderer *renderer, const cocos2d::Mat4& parentTransform, uint32_t parentFlags);
	virtual bool standed();
	virtual void standedby(){};
	virtual void moveToPos(float times,cocos2d::Point pos,bool stand = false);
	virtual void walkToPos(float times,cocos2d::Point pos,bool stand = true);
	virtual bool attackToPos(float times,cocos2d::Point newpoint);
	virtual bool attackOneTime(float times,cocos2d::Point newpoint);
	virtual bool magicUpToPos(float times,cocos2d::Point newpoint);
	virtual void hasHurted(float delay,float times);
	virtual bool walkInTheDir(float times,cocos2d::Point pos,Commen_Direction dir);
	virtual bool moveInTheDir(float times,cocos2d::Point pos,Commen_Direction dir,float movetimes = 0.0f);
	virtual bool collideInTheDir(float times,cocos2d::Point pos,Commen_Direction dir);
	virtual void gotoDeath(Commen_Direction dir,float times = 1.0f);
	virtual bool digToTheDir(float times,Commen_Direction dir){return false;};
	virtual bool excavateToTheDir(float times,Commen_Direction dir){return false;};
	virtual bool streakToTheDir(float times,Commen_Direction dir);
	// 骑战类虚影[根据所需格子]
	virtual bool StreakToTheDirRide(float times,Commen_Direction dir, Commen_ActionToDo action, int iTileNum = 5);
	//根据点击坐标获得人物的朝向
	bool setDirByNowPoint(const cocos2d::Point& newpoint);
	virtual void stopInTheTime();
	virtual bool setSpriteDir(Commen_Direction dir);
	virtual bool setSpriteOneDir(Commen_Direction dir);
	virtual Commen_Direction getSpriteOneDir()	{ return m_roledata.onedir; }
	virtual void setOpacity(GLubyte opacity) override;
	//int getOpacity();
	//void setOpacityNum(int opact);
	virtual void removeStread();
	virtual void setColor(const cocos2d::Color3B& color);
	virtual void setGray(bool isgray);
	virtual void setWrite(bool isgray);
	void setBlue(bool isblue);
	bool getResLoadStatus();
	/*cocos2d::Animation* createAnimation(const char* formatStr, int frameCount, int fps);*/
	CC_SYNTHESIZE(ActionState, m_currActionState, CurrActionState);
	CC_SYNTHESIZE(SpriteType, m_type, Type);
	CC_SYNTHESIZE(cocos2d::Sprite*, main_sprite, MainSprite);
	CC_SYNTHESIZE(bool, m_5dir_mode, 5DirMode);
	CC_SYNTHESIZE(int, m_res_id, ResId);
	CC_SYNTHESIZE(cocos2d::Node*, main_node, MainNode);
	bool getActorFlag();
	bool isNoActorOrNpc()	{ return (m_type < PLAYER_MANE_TYPE && m_type != NPC_TYPE); }
	void setActorFlag(bool actorflag);
	virtual bool initWithFile(const std::string&pszFileName);
	Commen_Direction getCurrectDir(){ return m_roledata.dir; }
	void setPlistsNum(int num){ m_plist_num = num; }
	void setTreeFlag(bool istree);
	void setFirstLoadRes(bool first);
	void setLoadResTime(int isadd);
	int getLoadResTime() { return load_times;};
	bool isTree() { return istree_flag;};
	bool changeState(ActionState actionState);
	virtual void changeModeDisplay(bool isreset,const std::string&url){m_is_change_display=isreset;};
	
public: 
		//角色基本数据
	MainRoledata m_roledata;
	bool stand_inited;
	float m_stand_times;
	bool m_is_change_display;
	std::string change_base_url;
private:
	bool isactor_flag;
	bool istree_flag;
	bool walk_inited;
	bool run_inited;
	bool attack_inited;
	bool hurt_inited;
	bool magic_inited;
	E_NEED_RECALC_PLIST_NUM m_need_recalc_plist_num;
	int m_plist_num;
	int m_plist_loadnum;
	int m_death_cut;
	bool has_load_res;
	bool first_load_res;
	int load_times;
	cocos2d::Rect m_touch_rect;
	std::string base_url;
	//cocos2d::Size m_win_size;
	std::string _strss;

private:
	bool isRideAttack();
	cocos2d::Point getTileByDir(Commen_Direction dir) ;
	int getDirIDByDir(cocos2d::Sprite*,Commen_Direction dir) ;
    void setNowActOld( cocos2d::Animation* act, const char *sprite_url,int count,int dir_id);
	void setNowAct(cocos2d::Animation* act,const char *sprite_url,int count,int dir_id);
	cocos2d::Animation* getNowActByDir();
	cocos2d::Animate* updateNowAnt(int RepeatNum);
	void getPlistPath(char *a,int num =1, bool old = true);
	void addSpriteFramesWithFile();
	void addTextureSprite(cocos2d::Texture2D *a);
	void addTextureSpritePre(cocos2d::Texture2D *a);
	void loadplist(bool old);
	void loadplistold();
};
#endif//_SPIRIT_BASE_
