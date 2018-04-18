#ifndef TILEDEF_H
#define TILEDEF_H

#include "cocos2d.h"
USING_NS_CC;

enum OCC_FLAG
{
	F_BLOCK = 0x01,
	F_ALPHA = 0x02,
};

struct	TileData
{
	Point tile;
	BYTE flag;

	TileData() : flag(0) {}

	bool isBlock()
	{
		return (flag & F_BLOCK) == F_BLOCK;
	}
	bool isAlpha()
	{
		return (flag & F_ALPHA) == F_ALPHA;
	}
	void setBlock(bool bb)
	{
		if (bb)
		{
			flag |= F_BLOCK;
		}
		else
		{
			flag &= ~F_BLOCK;
		}		
	}
	void setAlpha(bool bb)
	{
		if (bb)
		{
			flag |= F_ALPHA;
		}
		else
		{
			flag &= ~F_ALPHA;
		}
	}
};
typedef std::map<unsigned, TileData> TileMap;

#endif