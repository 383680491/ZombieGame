#ifndef _SPIRIT_A_STAR_H_
#define _SPIRIT_A_STAR_H_

#include "cocos2d.h"
#include "mapview/MapView.h"
#include "mapview/FindPath.h"


class NodeAStar : public cocos2d::Node
{
public: 
	NodeAStar();
	virtual ~NodeAStar(void);

	static NodeAStar * create();

	inline void setMap(MapView* map){ m_pMap = map; }
	void createPath();
	void findPath(cocos2d::Point desPoint);
	int getPathCount();
	_AstarNode* getPathNode();
	void deleteDoneNode();
private:
	bool init();

	MapView* m_pMap;
	struct _AstarNode *AStarMap;
	struct _AstarNode *AStarPath;
	cocos2d::Point LastDestPoint;
};
#endif