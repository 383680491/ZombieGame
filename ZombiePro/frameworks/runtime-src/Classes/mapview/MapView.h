#ifndef  __SCENE_VIEW_H__
#define  __SCENE_VIEW_H__

#include "cocos2d.h"
#include <queue>

#define PI				3.14159
#define SPEED				0.20
#define MAP_SPAN			10

#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

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




class MapViewBase : public cocos2d::Layer
{
public:
	MapViewBase()	{}
	virtual ~MapViewBase() {}

	virtual cocos2d::Point tile2Space(cocos2d::Point tile) = 0;
	virtual cocos2d::Point space2Tile(cocos2d::Point pos) = 0;

	//该tile位置是否阻挡
	virtual bool isBlock(cocos2d::Point tile) = 0;
	//该tile位置是否透明
	virtual bool isOpacity(cocos2d::Point tile) = 0;
};



class MapView : public cocos2d::Node
{
public:
	MapView();
	virtual ~MapView();

	//创建一个场景层
	static MapView *create();
	void load(const std::string& filename);


	//该tile位置是否阻挡
	bool isBlock(cocos2d::Point tile);
	//该tile位置是否透明
	bool isOpacity(cocos2d::Point tile);

	//tile坐标转空间坐标
	virtual cocos2d::Point tile2Space(cocos2d::Point tile);
	//空间坐标转tile坐标
	virtual cocos2d::Point space2Tile(cocos2d::Point pos);

	//返回场景layer Size
	cocos2d::Size& getMapSize() { return m_mapSize; }

	cocos2d::Size& getTileSize() { return m_perTileSize; }

	void setPosition(const cocos2d::Point &position);
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

private:
	cocos2d::Size			m_mapSize;
	cocos2d::Size			m_winSize;
	cocos2d::Size			m_perTileSize;
	cocos2d::experimental::TMXTiledMap * m_pMap;
	std::string m_block_str;
};



































#endif

