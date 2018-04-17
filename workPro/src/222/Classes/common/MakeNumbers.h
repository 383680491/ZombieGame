#pragma once
#include "cocos2d.h"

USING_NS_CC;
class MakeNumbers : public cocos2d::Node
{
public:
	MakeNumbers();
	virtual ~MakeNumbers(void);
	static MakeNumbers* create(const std::string&pszFileName,int attckmun,int span, bool bAutoSize = false);
	static MakeNumbers* createWithSymbol(const std::string&pszFileName,int attckmun,int span, bool bAutoSize = false);
	static MakeNumbers* createWithSymbolRect(const std::string&pszFileName,int attckmun,int span,cocos2d::Rect rect);

	bool init(const std::string&pszFileName,int attckmun,int span, bool bAutoSize = false);
	bool initSymbol(const std::string&pszFileName,int attckmun,int span, bool bAutoSize = false);
	void setMyRect(cocos2d::Rect re) { m_rect = re; with_rect = true; }

protected:	
	static MakeNumbers* createWithRect(const std::string&pszFileName,int attckmun,int span,cocos2d::Rect rect);

	cocos2d::Rect m_rect;
	bool with_rect;
};

