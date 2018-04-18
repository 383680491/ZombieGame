#ifndef _MAPTILENODE_H_
#define _MAPTILENODE_H_
#include "cocos2d.h"

class MapTileNode : public cocos2d::Node
{
public: 
	MapTileNode();
	virtual ~MapTileNode(void);
	static MapTileNode * create();
	CC_SYNTHESIZE(cocos2d::Point, m_tile_point, TilePoint);
	int getTilePointY();
	int getTilePointX();
	virtual void visit(cocos2d::Renderer *renderer, const cocos2d::Mat4& parentTransform, uint32_t parentFlags);
};
#endif