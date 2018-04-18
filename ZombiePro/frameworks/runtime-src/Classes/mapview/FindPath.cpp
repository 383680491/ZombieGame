#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
//#include "conio.h"
#include "FindPath.h"
USING_NS_CC;
static unsigned int MapWidth;					// ��ͼ��
static unsigned int MapHeight;					// ��ͼ��
// 8�������ھӸ��Լ�λ��ƫ�ƣ���12�㷽��ʼ��˳ʱ��
const int DIR_XY[8][2] = {{0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1},{-1, 1}, {-1, 0}, {-1, -1}};
const int DIR_G[8] = {10, 14, 10, 14, 10, 14, 10, 14};

// �ڵ�ͼ����ʱ�������µ�AstarѰ·�õĵ�ͼѰ·������Ϣ
// BlockValue ���ǵ�ͼ�����϶���õ��赲��Ϣ��'*' ��ʾ����ͨ�У���������ͨ��
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

// ÿ��ʼһ���µ�Ѱ·����ʼ��Astar��ͼ��Ϣ
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

// ���ھ�������С�����Լ������Fֵ���ڵĽڵ�, ����Ҫ������OpenList��
// ����Ҫ�������ӿ���OpenList�еĶ�λ
struct _AstarNode *FindNearNode(struct _AstarNode *AstarNode)
{
	struct _AstarNode *Node;
	struct _AstarNode *Max_Node = NULL;
	unsigned int Max_F = 0;

	for(int i=0; i<8; i++)
	{
		// �����ھӵ�XY
		int X = AstarNode->X + DIR_XY[i][0];
		int Y = AstarNode->Y + DIR_XY[i][1];
			
		// ����Ƿ��Ѿ�������ͼ����
		if (X < 0 || X >= MapWidth || Y < 0 || Y >= MapHeight)
		{
			continue;
		}

		// ͨ���Լ����ھӵ����λ�����������ĵ�ַ
        Node = AstarNode + int(DIR_XY[i][1] * MapWidth + DIR_XY[i][0]);

		// ����OpenList�У���һ��
		if (Node->Status != 1)
		{
			continue;
		}

		// �����Լ���F����һ��
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

// ����һ���µ�OpenList�ڵ�
// ��ʱ���ü��Ż��ı�������
void InsertNode(struct _AstarNode *AstarNode, struct _AstarNode *OpenList)
{
	struct _AstarNode *Node = OpenList->Next;
	struct _AstarNode *PreNode = OpenList;

	// ����ھ���Fֵ���Լ�С��������OpenList�У�����Ϊ���ȥɨ��
	// Ϊ�����Ч�ʣ�����ھӵ�Fֵ������ӽ��Լ���F
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
	
	// ���������ʾAstarNodeӦ�ò嵽OpenList�����
	PreNode->Next = AstarNode;
	AstarNode->Next = NULL;
	
	return;		
}

// ժȡ��OpenList�ĵ�һ���ڵ�
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


// Ѱ·
// ���ص���·���Ŀ�ʼ�㣬Ȼ��Next��Nextһ·����ȥ
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

	// ���Դ�������һ������㣬ֱ�ӷ���StopNode��Ϊ·���Ŀ�ʼ��
	if (StartNode->Value > 0)
	{
		return(NULL);	
	}

	// ���Ŀ�걾�����һ�������, ֱ�ӷ���ʧ��
	if (StopNode->Value > 0)
	{
		return(NULL);	
	}

	// Դ��Ŀ��һ����ֱ�ӷ���StartNode��Ϊ·���Ŀ�ʼ��
	if (StartNode->X == StopNode->X && StartNode->Y == StopNode->Y)
	{
		StartNode->Next = NULL;
		return(StartNode);
	}
	
	InsertNode(StartNode, &OpenList);
	
	while(IsFounded == false)
	{
		// ��Fֵ��С�Ľڵ���Ϊ��ǰ�ڵ�
		CurNode = Pop(&OpenList);
		if (CurNode == NULL)		// ���ΪNULL����ʾ OpenList �Ѿ�Ϊ�գ�Ѱ·����
		{
			break;
		}
		
		// ��鵱ǰ�ڵ�˸�������ھ�
		// ·��ƽ����������DirCount����Ϊ���ñ�֤ԭ�������ȣ�����W��·���ĳ��ֻ���
		static unsigned int DirCount = 0;
		for(int i=0; i<8; i++, DirCount++)
		{
			// �����ھӵ�XY
			unsigned int DD = DirCount%8;
			int X = CurNode->X + DIR_XY[DD][0];
			int Y = CurNode->Y + DIR_XY[DD][1];
			
			// ����Ƿ��Ѿ�������ͼ����
			if (X < 0 || X >= MapWidth || Y < 0 || Y >= MapHeight)
			{
				continue;
			}
			
			ChildNode = AstarMap + Y * MapWidth + X;
			
			// �ھ��ǲ���ͨ�и��ӣ���һ��������ʱֻ֧��0,1ģʽ��
			if (ChildNode->Value > 0)
			{
				continue;
			}
			
			// �ھ�Ϊ Closed����һ��
			if (ChildNode->Status == 2)
			{
				continue;
			}
			
			// �����ھӵ�G��H��Fֵ
			G = CurNode->G + DIR_G[DD];
			H = abs(SrcX - DstX)*10 + abs(SrcY - DstY)*10;
			F = H + G;	
			
			if (ChildNode->Status != 1)
			{
				// ����OpenList������
				ChildNode->Father = CurNode;
				ChildNode->G = G;
				ChildNode->F = F;

				InsertNode(ChildNode, &OpenList);
				
				// ����Ƿ�Ϊ Ŀ��㣬�Ǿͱ�ʾ�ҵ�������Ѱ·
				if (ChildNode->X == StopNode->X && ChildNode->Y == StopNode->Y)
				{
					IsFounded = true;
					break;
				}
			}
			else
			{
				// �ھ��� OpenList �У�
				// ����ھ����ڵ�Gֵ����OpenList��GֵС��������
				// ������δ��벻����ǰ������ᵼ��G��ǰ���޸�
				if (ChildNode->G > G)
				{
					ChildNode->G = G;
					ChildNode->F = F;
					ChildNode->Father = CurNode;
				}
			}

		}	// end For
		 
	}	// end While

	// ·�����ڣ��� Ŀ��� ���ݵ� ��ʼ�㣬��������·��
	// �ӿ�ʼ�㿪ʼ������Next������·��
	if (IsFounded == true)
	{
		struct _AstarNode *P = StopNode;
		struct _AstarNode *Father;
		
		P->Next = NULL;				// ����·������־

		while(P != NULL)
		{
			Father = P->Father;

			if (Father == NULL)		// �쳣��飬���ֲ������Core
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