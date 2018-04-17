#ifndef _FINDPATH_
#define _FINDPATH_

#include "cocos2d.h"
#include "MapView.h"

// ��512*512��С�ĵ�ͼ���㷨����24*512*512���ڴ棬ԼΪ6M
struct _AstarNode
{
	unsigned int F, G;					// F, Gֵ
	struct _AstarNode *Father;			// ����ָ��
	struct _AstarNode *Next;			// OpenList����һ���ڵ�
	unsigned short X, Y;				// �ڵ�ͼ�ϵ�XY����
	unsigned char Value;				// ����ֵ, Խ���ʾԽ����ͨ��
	unsigned char Status;				// 0:Init  1:Opened  2:Clsoed
};
// �ڵ�ͼ����ʱ�������µ�AstarѰ·�õĵ�ͼѰ·������Ϣ
struct _AstarNode *NewAstarMap(cocos2d::Size mapSize, MapView* pMapLayer);
struct _AstarNode *NewAstarMap(cocos2d::Size mapSize, const struct _AstarNode* aNode);

// ÿ��ʼһ���µ�Ѱ·����ʼ��Astar��ͼ��Ϣ
void InitAstarMap(struct _AstarNode *AstarMap);

// Ѱ·, ���ص���·���Ŀ�ʼ�㣬Ȼ��Next��Nextһ·����ȥ
struct _AstarNode *FindPath(int SrcX, int SrcY, int DstX, int DstY, struct _AstarNode *AstarMap);

#endif