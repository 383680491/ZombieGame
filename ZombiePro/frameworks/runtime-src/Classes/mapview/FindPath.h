#ifndef _FINDPATH_
#define _FINDPATH_

#include "cocos2d.h"
#include "MapView.h"

// 按512*512大小的地图，算法消耗24*512*512的内存，约为6M
struct _AstarNode
{
	unsigned int F, G;					// F, G值
	struct _AstarNode *Father;			// 父亲指针
	struct _AstarNode *Next;			// OpenList中下一个节点
	unsigned short X, Y;				// 在地图上的XY坐标
	unsigned char Value;				// 格子值, 越大表示越难于通行
	unsigned char Status;				// 0:Init  1:Opened  2:Clsoed
};
// 在地图更新时，建立新的Astar寻路用的地图寻路格子信息
struct _AstarNode *NewAstarMap(cocos2d::Size mapSize, MapView* pMapLayer);
struct _AstarNode *NewAstarMap(cocos2d::Size mapSize, const struct _AstarNode* aNode);

// 每开始一次新的寻路，初始化Astar地图信息
void InitAstarMap(struct _AstarNode *AstarMap);

// 寻路, 返回的是路径的开始点，然后Next，Next一路找下去
struct _AstarNode *FindPath(int SrcX, int SrcY, int DstX, int DstY, struct _AstarNode *AstarMap);

#endif