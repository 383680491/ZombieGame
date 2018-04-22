#include "NodeAStar.h"

USING_NS_CC;

NodeAStar * NodeAStar::create()
{
	NodeAStar * ret = new (std::nothrow) NodeAStar();
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


NodeAStar::NodeAStar()
:m_pMap(NULL)
{
	
}
NodeAStar::~NodeAStar(void)
{
}


bool NodeAStar::init()
{
	return true;
}

void NodeAStar::createPath()
{
	Size mapSize = m_pMap->getMapSize();
	AStarMap = NewAstarMap(mapSize, m_pMap);
}

void NodeAStar::findPath(Point desPoint)
{
	if (LastDestPoint == desPoint)
		return;

	InitAstarMap(AStarMap);
	LastDestPoint = desPoint;
	Point startPoint = m_pMap->space2Tile(this->getPosition());
	AStarPath = FindPath(startPoint.x, startPoint.y, desPoint.x, desPoint.y, AStarMap);
}

_AstarNode* NodeAStar::getPathNode()
{
	if (AStarPath == NULL)
		return NULL;

	return AStarPath->Next;
}

void NodeAStar::deleteDoneNode()
{
	if (AStarPath == NULL)
		return;

	AStarPath = AStarPath->Next;
}

int NodeAStar::getPathCount()
{
	if (AStarPath == NULL)
		return 0;

	_AstarNode* temp = AStarPath;
	int count = 0;

	while (temp)
	{
		count++;
		temp = temp->Next;
	}

	return count;
}




