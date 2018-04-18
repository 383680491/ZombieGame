#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
//#include "conio.h"
#include "FindPath.h"
USING_NS_CC;
static unsigned int MapWidth;					// 地图宽
static unsigned int MapHeight;					// 地图高
// 8个方向邻居跟自己位置偏移，从12点方向开始，顺时针
const int DIR_XY[8][2] = {{0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1},{-1, 1}, {-1, 0}, {-1, -1}};
const int DIR_G[8] = {10, 14, 10, 14, 10, 14, 10, 14};

// 在地图更新时，建立新的Astar寻路用的地图寻路格子信息
// BlockValue 就是地图格子上定义好的阻挡信息，'*' 表示可以通行，其他不能通行
//struct _AstarNode *NewAstarMap(int W, TileMap tiles)
//{
//	struct _AstarNode *AstarMap;
//	
//	AstarMap = (struct _AstarNode *)malloc(W * W * sizeof(struct _AstarNode));
//	if (AstarMap == NULL)
//	{
//		return(NULL);
//	}
//
//	memset(AstarMap, 0, W * W * sizeof(struct _AstarNode));
//	
//	MapWidth = W;
//	MapHeight = W;
//
//	struct _AstarNode *Node = AstarMap;		
//	for(int y=0; y<W; y++)
//	{
//
//		for(int x=0; x<W; x++)
//		{
//			Node->X = x;
//			Node->Y = y;
//			int tileIdx = x * 1000 + y;
//			TileMap::iterator it = tiles.find(tileIdx);
//			if ((it != tiles.end())&&!(it->second.isBlock()))
//			{
//				Node->Value = 0;
//			}
//			else
//			{
//				Node->Value = 1;
//			}
//			Node ++;
//		}
//	}
//	
//	return(AstarMap);
//}

struct _AstarNode *NewAstarMap(Size mapSize, MapView* pMapLayer)
{
	struct _AstarNode *AstarMap;
	
	AstarMap = (struct _AstarNode *)malloc(mapSize.width * mapSize.height * sizeof(struct _AstarNode));
	if (AstarMap == NULL)
	{
		return(NULL);
	}

	memset(AstarMap, 0, mapSize.width * mapSize.height * sizeof(struct _AstarNode));
	
	MapWidth = mapSize.width;
	MapHeight = mapSize.height;

	struct _AstarNode *Node = AstarMap;
	for(int y=0; y<mapSize.height; y++)
	{
		for(int x=0; x<mapSize.width; x++)
		{
			Node->X = x;
			Node->Y = y;
			//if(pMapLayer->isHasStopThead())
			//{
			//	return NULL;
			//}
			if (!pMapLayer->isBlock(Point(x,y)))
			{
				Node->Value = 0;
			}
			else
			{
				Node->Value = 1;
			}
			Node ++;
		}
	}
	return(AstarMap);
}

struct _AstarNode *NewAstarMap(Size mapSize, const struct _AstarNode* aNode)
{
	struct _AstarNode *AstarMap;
	AstarMap = (struct _AstarNode *)malloc(mapSize.width * mapSize.height * sizeof(struct _AstarNode));
	if (AstarMap == NULL)
	{
		return(NULL);
	}
	memset(AstarMap, 0, mapSize.width * mapSize.height * sizeof(struct _AstarNode));
	memcpy(AstarMap,aNode, mapSize.width * mapSize.height * sizeof(struct _AstarNode));
	return(AstarMap);
}

// 每开始一次新的寻路，初始化Astar地图信息
void InitAstarMap(struct _AstarNode *AstarMap)
{
	struct _AstarNode *Node = AstarMap;

	for(unsigned int y=0; y<MapHeight; y++)
	{
		for (unsigned int x = 0; x<MapWidth; x++)
		{
			Node->F = 0;
			Node->G = 0;
			Node->Father = NULL;
			Node->Status = 0;
			Node->Next = NULL;

			Node ++;
		}
	}
	return;		
}

// 在邻居中中找小等于自己的最大F值所在的节点, 它还要必须在OpenList中
// 后面要用它来加快在OpenList中的定位
struct _AstarNode *FindNearNode(struct _AstarNode *AstarNode)
{
	struct _AstarNode *Node;
	struct _AstarNode *Max_Node = NULL;
	unsigned int Max_F = 0;

	for(int i=0; i<8; i++)
	{
		// 计算邻居的XY
		int X = AstarNode->X + DIR_XY[i][0];
		int Y = AstarNode->Y + DIR_XY[i][1];
			
		// 检查是否已经超过地图界限
		if (X < 0 || X >= MapWidth || Y < 0 || Y >= MapHeight)
		{
			continue;
		}

		// 通过自己和邻居的相对位于来计算它的地址
        Node = AstarNode + int(DIR_XY[i][1] * MapWidth + DIR_XY[i][0]);

		// 不在OpenList中，下一个
		if (Node->Status != 1)
		{
			continue;
		}

		// 大于自己的F，下一个
		if (Node->F > AstarNode->F)
		{
			continue;
		}

		if (Node->F > Max_F)
		{
			Max_F = Node->F;
			Max_Node = Node;
		}	
	}

	return(Max_Node);
}

// 插入一个新的OpenList节点
// 暂时采用简单优化的遍历方法
void InsertNode(struct _AstarNode *AstarNode, struct _AstarNode *OpenList)
{
	struct _AstarNode *Node = OpenList->Next;
	struct _AstarNode *PreNode = OpenList;

	// 如果邻居中F值比自己小，而且在OpenList中，以它为起点去扫描
	// 为了最大化效率，这个邻居的F值还是最接近自己的F
	struct _AstarNode *NearNode;
	NearNode = FindNearNode(AstarNode);
	if (NearNode != NULL)
	{
		Node = NearNode;
	}

	AstarNode->Status = 1;		// Opened

	while(Node != NULL)
	{
		if (Node->F > AstarNode->F)
		{
			PreNode->Next = AstarNode;
			AstarNode->Next = Node;
			return;
		}
	
		PreNode = Node;
		Node = Node->Next;	
	}
	
	// 到了这里，表示AstarNode应该插到OpenList的最后
	PreNode->Next = AstarNode;
	AstarNode->Next = NULL;
	
	return;		
}

// 摘取出OpenList的第一个节点
struct _AstarNode *Pop(struct _AstarNode *OpenList)
{
	struct _AstarNode *P = OpenList->Next;
	if(P != NULL)
	{
		OpenList->Next = P->Next;
		P->Next = NULL;
		P->Status = 2;		// Closed
	}
	return(P);
}


// 寻路
// 返回的是路径的开始点，然后Next，Next一路找下去
struct _AstarNode *FindPath(int SrcX, int SrcY, int DstX, int DstY, struct _AstarNode *AstarMap)
{
	bool IsFounded = false;
	struct _AstarNode *StartNode = AstarMap + SrcY * MapWidth + SrcX;	
	struct _AstarNode *StopNode = AstarMap + DstY * MapWidth + DstX;
	struct _AstarNode *CurNode, *ChildNode;
	int G, F, H;

	struct _AstarNode OpenList;
	OpenList.Next = NULL;
	if( SrcX >= MapWidth || SrcY >= MapHeight|| SrcX < 0 || SrcY < 0 )
	{
		return(NULL);	
	}
	if( DstX >= MapWidth || DstY >= MapHeight|| DstX < 0 || DstY < 0 )
	{
		return(NULL);	
	}

	// 如果源本身就是一个阻隔点，直接返回StopNode作为路径的开始点
	if (StartNode->Value > 0)
	{
		return(NULL);	
	}

	// 如果目标本身就是一个阻隔点, 直接返回失败
	if (StopNode->Value > 0)
	{
		return(NULL);	
	}

	// 源和目标一样，直接返回StartNode作为路径的开始点
	if (StartNode->X == StopNode->X && StartNode->Y == StopNode->Y)
	{
		StartNode->Next = NULL;
		return(StartNode);
	}
	
	InsertNode(StartNode, &OpenList);
	
	while(IsFounded == false)
	{
		// 找F值最小的节点作为当前节点
		CurNode = Pop(&OpenList);
		if (CurNode == NULL)		// 如果为NULL，表示 OpenList 已经为空，寻路结束
		{
			break;
		}
		
		// 检查当前节点八个方向的邻居
		// 路径平滑处理，引入DirCount，是为了让保证原方向优先，降低W型路径的出现机会
		static unsigned int DirCount = 0;
		for(int i=0; i<8; i++, DirCount++)
		{
			// 计算邻居的XY
			unsigned int DD = DirCount%8;
			int X = CurNode->X + DIR_XY[DD][0];
			int Y = CurNode->Y + DIR_XY[DD][1];
			
			// 检查是否已经超过地图界限
			if (X < 0 || X >= MapWidth || Y < 0 || Y >= MapHeight)
			{
				continue;
			}
			
			ChildNode = AstarMap + Y * MapWidth + X;
			
			// 邻居是不可通行格子，下一个。（暂时只支持0,1模式）
			if (ChildNode->Value > 0)
			{
				continue;
			}
			
			// 邻居为 Closed，下一个
			if (ChildNode->Status == 2)
			{
				continue;
			}
			
			// 计算邻居的G、H、F值
			G = CurNode->G + DIR_G[DD];
			H = abs(SrcX - DstX)*10 + abs(SrcY - DstY)*10;
			F = H + G;	
			
			if (ChildNode->Status != 1)
			{
				// 不在OpenList，插入
				ChildNode->Father = CurNode;
				ChildNode->G = G;
				ChildNode->F = F;

				InsertNode(ChildNode, &OpenList);
				
				// 检查是否为 目标点，是就表示找到，结束寻路
				if (ChildNode->X == StopNode->X && ChildNode->Y == StopNode->Y)
				{
					IsFounded = true;
					break;
				}
			}
			else
			{
				// 邻居在 OpenList 中，
				// 如果邻居现在的G值比在OpenList的G值小，更新它
				// 下面这段代码不能提前，否则会导致G提前被修改
				if (ChildNode->G > G)
				{
					ChildNode->G = G;
					ChildNode->F = F;
					ChildNode->Father = CurNode;
				}
			}

		}	// end For
		 
	}	// end While

	// 路径存在，从 目标点 回溯到 开始点，产生正向路径
	// 从开始点开始，借用Next来保存路径
	if (IsFounded == true)
	{
		struct _AstarNode *P = StopNode;
		struct _AstarNode *Father;
		
		P->Next = NULL;				// 设置路径最后标志

		while(P != NULL)
		{
			Father = P->Father;

			if (Father == NULL)		// 异常检查，保持不会出现Core
			{
				return(NULL);
			}

			Father->Next = P;
			if (Father->X == StartNode->X && Father->Y == StartNode->Y)
			{
				break;
			}
			else
			{
				P = Father;
			}
		}

		return(Father);
	}
	else
	{
		return(NULL);
	}	
}

//const unsigned char MapBlocks[16][16] = {
//{"               "},
//{"  *****        "},
//{"  *****        "},
//{"    ****       "},
//{"      ****     "},
//{"          **** "},
//{"     ******   *"},
//{"     ***      *"},
//{"     *        *"},
//{"    *         *"},
//{"   *           "},
//{"  *************"},
//{"    *          "},
//{"   *****       "},
//{"        *      "},
//{" ********      "}};       
//
//
//
//int main(void)
//{
//	struct _AstarNode *AStarMap = NewAstarMap(16, 16, (unsigned char *)MapBlocks);
//	if (AStarMap == NULL)
//	{
//		printf("Map Init Error\n");
//		return(0);
//	}
//
//	printf("MapBlocks: [*] OK \n");
//	for(int i=0; i<16; i++)
//	{
//		printf("%02d:|%s|\n", i, (unsigned char *)MapBlocks+i*16);
//	}
//	
//	InitAstarMap(AStarMap);
//
//	struct _AstarNode *Path = FindPath(2, 2, 2, 15, AStarMap);
//	if (Path == NULL)
//	{
//		printf("Path Not Found\n");
//		getch();
//
//		delete(AStarMap);
//		return(0);
//	}
//	
//
//	printf("RoutePoint: ");
//	while(Path->Next != NULL)
//	{
//		printf("[%d,%d]->", Path->X, Path->Y);
//
//		Path = Path->Next;
//	}
//
//	printf("[%d,%d]  End! ", Path->X, Path->Y);
//
//	getch();
//
//	delete(AStarMap);
//}