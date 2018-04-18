#pragma once
#include "cocos2d.h"
#include "sprites/Commen_Direction.h"
#include "sprites/SpriteCharacterBase.h"
//#include "effects/MagicDefine.h"
#include "sprites/SpriteMonster.h"
//#include "socket/LuaMsgBuffer.h"

class MapViewBase : public cocos2d::Layer
{
public:
	MapViewBase()	{}
	virtual ~MapViewBase() {}

	// 获取对象根节点
	virtual cocos2d::Node* GetItemRoot() = 0;
	virtual cocos2d::Node* getSkillRootNode() = 0;

	virtual cocos2d::Point tile2Space(cocos2d::Point tile) = 0;
	virtual cocos2d::Point space2Tile(cocos2d::Point pos) = 0;

	virtual Commen_Direction getDirByTile(cocos2d::Point tile);
	virtual cocos2d::Point getTileByDir(Commen_Direction dir);

	//该tile位置是否阻挡
	virtual bool isBlock(cocos2d::Point tile) = 0;
	//该tile位置是否透明
	virtual bool isOpacity(cocos2d::Point tile) = 0;
};

class UIMapView : public MapViewBase
{
public:
	static UIMapView *create();

	UIMapView();
	virtual ~UIMapView();

	virtual bool init() override;

	virtual cocos2d::Node* GetItemRoot();
	virtual cocos2d::Node* getSkillRootNode();

	virtual cocos2d::Point tile2Space(cocos2d::Point tile);
	virtual cocos2d::Point space2Tile(cocos2d::Point pos);

	//该tile位置是否阻挡
	bool isBlock(cocos2d::Point tile);
	//该tile位置是否透明
	bool isOpacity(cocos2d::Point tile);
	//void onCrash(int skill_id, int roleId_attacker, int roleId_target, int pos_x, int pos_y, int start_pos_x, int start_pos_y, int end_pos_x, int end_pos_y);
	//void onDelayCrash(UISpriteCharacter *r_node, action_queue crash_data);
	//void onDelayCrashed(UISpriteCharacter *r_node, action_queue crashed_data);
	char getSpeedUp(UISpriteCharacter *r_node);
	Commen_Direction GetDirByPos(const Point& src, const Point& dst);
	void onShowHurtNumber(int number,Point pos,char f_type,bool ishit,Point span_pos, int resistType);
	//void onShowHurt(LuaMsgBuffer *pBuff);
	void onDoMove(int objId, short pos_x, short pos_y);
	void onDelayMove(UISpriteCharacter *r_node,Point start_point);

protected:
	cocos2d::Size		m_perTileSize;
	cocos2d::Size		m_mapSize;

	cocos2d::Node*		m_item_node;
	cocos2d::Node*		m_skill_node;
	cocos2d::Node*		m_hit_node;

};
