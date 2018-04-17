#include "SortNode.h"
#include "MapTileNode.h"
USING_NS_CC;

static int s_Max_SortStep = 1;
static int m_redraw_num;

void SortNode::insertQueuq()
{
	m_redraw_num++;
}


bool SortNodeComparisonLess(Node* n1, Node* n2)
{
    //return( n1->getLocalZOrder() < n2->getLocalZOrder() ||
    //       ( n1->getLocalZOrder() == n2->getLocalZOrder() && (n1->getPositionY() - n2->getPositionY())>5 )
    //       );
	//int spany = n1->getPositionY() - n2->getPositionY();
	////return n1->getPositionY() > n2->getPositionY();
	//return( spany > 5 || ( spany > -5 && spany <= 5) && (n1->getLocalZOrder() < n2->getLocalZOrder() ||
	//	( n1->getLocalZOrder() == n2->getLocalZOrder() && n1->getOrderOfArrival() < n2->getOrderOfArrival() ))
	//	);
	return (((MapTileNode*)n1)->getTilePointY() < ((MapTileNode*)n2)->getTilePointY()) || 
			((MapTileNode*)n1)->getTilePointY() == ((MapTileNode*)n2)->getTilePointY() && (n1->getLocalZOrder() < n2->getLocalZOrder() ||
		( n1->getLocalZOrder() == n2->getLocalZOrder() && n1->getOrderOfArrival() < n2->getOrderOfArrival() )
		);
}

void SortNode::setMaxSortStep(int num)
{
	s_Max_SortStep = num;
}


SortNode::SortNode()
{
	m_needsort = true;
	m_nSortStep = 0;
	m_redraw_num = 0;
}

SortNode::~SortNode(void)
{
}

SortNode * SortNode::create()
{
    SortNode * ret = new (std::nothrow) SortNode();
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

void SortNode::sortAllChildren()
{
    if (m_needsort)
    {
		if (_reorderChildDirty)
		{
			if (m_nSortStep == 0)
				std::sort(std::begin(_children), std::end(_children), SortNodeComparisonLess);
			_reorderChildDirty = false;
		}

		++m_nSortStep;
		if (m_nSortStep >= s_Max_SortStep)
			m_nSortStep = 0;
    }
	
}
void SortNode::setReorder()
{
	_reorderChildDirty = true;
}

void SortNode::visit(Renderer* renderer, const Mat4 &parentTransform, uint32_t parentFlags)
{
	if (!_visible)
		return;

	//m_redraw_num = 0;
	//m_redraw_node.clear();
	uint32_t flags = processParentFlags(parentTransform, parentFlags);
    // quick return if not visible. children won't be drawn.
    _director->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
    _director->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, _modelViewTransform);
	
    if(!_children.empty())
    {
		sortAllChildren();
		for (size_t i = 0, ics = _children.size(); i < ics; i++)
		{
			//int num = m_redraw_num;
			_children.at(i)->visit(renderer, _modelViewTransform, flags);
			//if(num<m_redraw_num)
			//{
			//	m_redraw_node.push_back(_children.at(i));
			//}
		}
    }
	//for (ssize_t i = 0, ics = m_redraw_node.size(); i < ics && i<m_redraw_num; i++) {
	//	m_redraw_node.at(i)->visit(renderer, _modelViewTransform, flags);
	//}

	//m_redraw_num = 0;
    _director->popMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);  
}
