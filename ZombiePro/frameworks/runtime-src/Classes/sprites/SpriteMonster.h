#ifndef _SPIRIT_MASTER_
#define _SPIRIT_MASTER_

#include "SpriteCharacterBase.h"
#include "MirControl/MirTextNode.h"

enum EOpacityNodeByTag
{
	E_ONTAG_BODY	= 8010501,
	E_ONTAG_WEAPON	= 8010101,
	E_ONTAG_WING	= 8010201,
	E_ONTAG_RIDE	= 8010301,

};


typedef enum {
	ADD_WEAPON_TYPE = 55,
	ADD_WEAPONHOE_TYPE = 56,
	ADD_HEAD_TYPE = 57,
	ADD_WING_TYPE = 67,
	ADD_RIDE_TYPE = 68,
	ADD_ANOTHER_TYPE = 8,
}AddNodeType;

typedef enum {
	ACTION_MOVE_TYPE = 0,
	ACTION_ATTACK_TYPE,
	ACTION_CRASH_TYPE,
	ACTION_CRASHED_TYPE,
	ACTION_SKILLMOVE_TYPE,
}ActionQueueType;

struct action_queue{
	ActionQueueType q_type;
	int skill_id;
	int skill_lvl;
	/*
	 * 技能类型
	 * 1、强化小火球发送的是技能阶段[初级、中级、高级、专家等]
	 */
	int skillColor;
	int tarId;
	cocos2d::Point pos;
	cocos2d::Point start_pos;
	action_queue()
		: q_type(ACTION_MOVE_TYPE)
		, skill_id(0)
		, skill_lvl(0)
		, skillColor(0)
		, tarId(0)
	{}
};

class SpriteMonster : public SpriteCharacterBase 
{
public:
	static SpriteMonster* create(const std::string&pszFileName);

	SpriteMonster();
	virtual ~SpriteMonster(void);
	virtual void visit(cocos2d::Renderer *renderer, const cocos2d::Mat4& parentTransform, uint32_t parentFlags);
	bool initWithFileExt(const std::string& pszFileName);
	virtual void hasHurted(float delay,float times);
	virtual void setBaseUrl(const std::string&pszFileName)override;
	virtual void setType(SpriteType var)override;
	
	static void clearMapTile();
	static void setMaxNumOneTile(int num);
	static void setHideCenterRect(bool hide);
	static int getMonstersCountOnRect(cocos2d::Rect rc);

	void showNameAndBlood(bool show,int height = 0);
	void setVisibleNameAndBlood(bool val);
	void setNameAndBloodPos(bool is_lock_height, int offx = 0, int height = 0);
	void setLockHeight(bool is_lock_height) { m_is_lock_height = is_lock_height; }

	virtual void playAction(float times,Commen_ActionToDo action,Commen_Direction dir,int loop,float ltimes=0.0f)override;
	virtual bool standed();
	virtual void doStanded();
	void doStandedAction();
	virtual void doSetOpacity();
	virtual void doSetOpacity_ex();
	virtual void standedby();
	virtual void walkToPos(float times,cocos2d::Point pos,bool stand = true);
	virtual bool walkInTheDir(float times,cocos2d::Point pos,Commen_Direction dir);
	virtual bool walkInTheDir_ex(float times,cocos2d::Point pos,Commen_Direction dir);
	virtual bool attackToPos(float times,cocos2d::Point newpoint);
	virtual bool attackOneTime(float times,cocos2d::Point newpoint);
	virtual bool magicUpToPos(float times,cocos2d::Point newpoint);
	virtual bool attackAction(float times,int a_num,Commen_Direction dir,int a_type);
	virtual bool magicAction(float times,int a_num,Commen_Direction dir,int a_type);
	virtual bool appeared(float times,int a_num,Commen_Direction dir);
	virtual bool disappeared(float times,int a_num,Commen_Direction dir);
	virtual bool changeDisplay(float times,int a_num,Commen_Direction dir);
	virtual void stopInTheTime();
	bool attackOneTime_ex(float times, const cocos2d::Point& newpoint);
	bool MagicOneTime_ex(float times, const cocos2d::Point& newpoint);
	bool DoMagicWithoutAction(const cocos2d::Point& newpoint);
	virtual void gotoDeath(Commen_Direction dir,float times = 1.0f);
	virtual void setPosition(const cocos2d::Point &position)override;
	virtual void setPosition(float x, float y)override;
	virtual void onEnter() override;
	virtual void onExit()override;
	virtual bool setSpriteDir(Commen_Direction dir)override;
	virtual bool setSpriteOneDir(Commen_Direction dir)override;

	void resetBloodHeight();
	void onRetain();
	void onRestore();
	void reloadRes();
	void reloadPosition();
	void insertActionChild(const std::string&strName, int z,int tag);
	void removeActionChild(SpriteBase* child);
	void removeActionChildByTag(int tag);
	virtual void setVisible(bool isvisible);
	virtual void setOpacity(GLubyte opacity) override;
	void setColor(const cocos2d::Color3B& color);
	void setGray(bool isgray);
	void setWrite(bool isgray);
	void initOrderByDir(SpriteBase* c_sprite,Commen_Direction dir);
	void doSpecailAction(float times,int a_num,Commen_Direction dir,const std::string&typeName);
	void subBlood(int blood);
	bool isAlive();
	void setHP(int);
	int getHP() {return m_hp;};
	void setFacName(std::string);
	std::string getFacName() {return m_facName;};
	void setTitleName(std::string);
	std::string getTitleName() {return m_titleName;};
	//CC_SYNTHESIZE(int, m_hp, HP);
	CC_SYNTHESIZE(double, m_baseSpead, BaseSpeed);
	CC_SYNTHESIZE(double, m_spead, Speed);
	CC_SYNTHESIZE(char,m_spead_up, TheSpeedUp);
	CC_SYNTHESIZE(unsigned int, m_monster_id, MonsterId);
	CC_SYNTHESIZE(unsigned int, m_maxhp, MaxHP);
	CC_SYNTHESIZE(bool, m_onRide, OnRide);
	CC_SYNTHESIZE(bool, m_need_hide, NeedHide);
	CC_SYNTHESIZE(bool, m_show_name, NeedShowName);
	CC_SYNTHESIZE(unsigned int, m_attack, Attack);
	CC_SYNTHESIZE(unsigned int, m_weapon_id, WeaponId);
	CC_SYNTHESIZE(cocos2d::Node*, m_name_label, NameLabel);//名字
	CC_SYNTHESIZE(MirTextNode*, m_name_batchlabel, NameBatchLabel);//名字
	CC_SYNTHESIZE(MirTextNode*, m_facName_batchlabel, FacNameBatchLabel);//名字
	CC_SYNTHESIZE(MirTextNode*, m_titleName_batchlabel, TitleNameBatchLabel);//名字
	CC_SYNTHESIZE(cocos2d::Node*, m_title_node, TitleNode);//名字
	CC_SYNTHESIZE(cocos2d::Node*, m_top_node, TopNode);//名字
	CC_SYNTHESIZE(cocos2d::Node*, m_down_node, DownNode);//名字
	CC_SYNTHESIZE(MapTileNode*, m_buffskill_node, BuffSkillNode);//名字
	//CC_SYNTHESIZE(cocos2d::Point, m_tile_point, TilePoint);
	CC_SYNTHESIZE(cocos2d::Point, m_server_tile, ServerTile);
	CC_SYNTHESIZE(bool, m_isHighRide, IsOnHighRide);
	CC_SYNTHESIZE(bool, m_isAttackRide, IsOnAttackRide);
	//CC_SYNTHESIZE(std::string, m_name, TheName);
	std::string getTheName() {return getName();};
	void setTheName(std::string &name) {setName(name);};
	CC_SYNTHESIZE(int, m_level, Level);

	virtual cocos2d::Node* getSkillNode()		{ return m_skill_node; }
	virtual cocos2d::Node* getSkillDownNode()	{ return m_skilldown_node; }

	void setServerTilePosByTile(float tx, float ty);
	
	void insertServerPoint(action_queue t_queue);
	void removeServerPoint();
	void clearServerPoints();
	action_queue getServerPoints();
	int getSeverPointsNum();
	bool hasServerPoints() { return !server_points.empty(); }

	void reCalcShowH();
	void resetShowHPosition();

	void setShow_H(int sh);
	void setWingNodeVisble(bool isvisible);
	virtual void changeModeDisplay(bool isreset,const std::string&url);
	bool isChangeModeDisplay() { return m_is_change_display; }
	void setVirtualOpacityNum(int num) { m_set_opacity_num = num; }
	
protected:
	SpriteBase* getOpacityNodeByTag(int tag);

	void showNameAndBlood_imp(bool show);

	void ReCreate_name_batchlabel();
	void ReCreate_facName_batchlabel();
	void ReCreate_titleName_batchlabel();


	cocos2d::Vector<SpriteBase*> m_sprites;

	std::queue<action_queue>server_points;
	//角色基本数据
	int m_hp;
	int m_set_opacity_num;
	//bool isactor_flag;
	//cocos2d::Sprite* shadow_sprite;
	cocos2d::Sprite* m_blood_bg;//血条
	cocos2d::Sprite* m_blood_pro;//血条

	//cocos2d::Node* m_head_node;//头发
	MapTileNode* m_wing_node;//翅膀
	MapTileNode* m_weapon_node;//武器
	MapTileNode* m_ride_node;//坐骑

	std::string m_facName;//行会名字
	std::string m_titleName;//封号

	MapTileNode* m_main_node;
	float update_pecent;
	//float sub_pecent;
	int show_h;
	int show_offx;
	bool is_show_blood;
	bool is_show_wing;
	bool m_is_lock_height;
	bool is_need_resetBloodHeight;	
	Commen_ActionToDo last_action;
	Commen_Direction last_action_dir;

	cocos2d::Node* m_skill_node;
	cocos2d::Node* m_skilldown_node;
};
#endif//_SPIRIT_MASTER_
