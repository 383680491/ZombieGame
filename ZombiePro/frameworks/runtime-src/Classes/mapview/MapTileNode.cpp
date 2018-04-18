#include "MapTileNode.h"
#include "MapView.h"
USING_NS_CC;

MapTileNode::MapTileNode()
{
	m_tile_point = Point();
}

MapTileNode::~MapTileNode(void)
{
}

MapTileNode * MapTileNode::create()
{
    MapTileNode * ret = new (std::nothrow) MapTileNode();
    if (ret && ret->init())
    {
        ret->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(ret);
    }
    return ret;
}

int MapTileNode::getTilePointY()
{
	return (int)m_tile_point.y;
}
int MapTileNode::getTilePointX()
{
	return (int)m_tile_point.x;
}

void MapTileNode::visit(Renderer* renderer, const Mat4 &parentTransform, uint32_t parentFlags)
{
    // quick return if not visible. children won't be drawn.
	if ( !isVisible() )
		return;
    _director->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
    _director->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, _modelViewTransform);
    if(!_children.empty())
    {
        sortAllChildren();
		uint32_t flags = parentFlags;
		flags |= (_transformUpdated ? FLAGS_TRANSFORM_DIRTY : 0);
		flags |= (_contentSizeDirty ? FLAGS_CONTENT_SIZE_DIRTY : 0);
		if(flags & FLAGS_DIRTY_MASK)
			_modelViewTransform = this->transform(parentTransform);
		_transformUpdated = false;
		_contentSizeDirty = false;
        for(auto it=_children.cbegin(); it != _children.cend(); ++it)
            (*it)->visit(renderer, _modelViewTransform, flags);
    }
    _director->popMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);  
}