#include "MakeNumbers.h"
//#include "../ImagePaths.h"
#include <string>
using namespace std;  
/*
这个类主要是显示组合自定义图片类型的伤害数值。
*/


MakeNumbers::MakeNumbers()
{
	with_rect = false;
}

MakeNumbers* MakeNumbers::create(const string&pszFileName,int attckmun,int span, bool bAutoSize)
{
	MakeNumbers *pRet = new MakeNumbers();
    if (pRet)
    {
		pRet->init(pszFileName,attckmun,span,bAutoSize);
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}


MakeNumbers* MakeNumbers::createWithSymbol(const string&pszFileName,int attckmun,int span, bool bAutoSize)
{
	MakeNumbers *pRet = new MakeNumbers();	
    if (pRet)
    {
		pRet->initSymbol(pszFileName,attckmun,span,bAutoSize);
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}
MakeNumbers* MakeNumbers::createWithRect(const string&pszFileName,int attckmun,int span,Rect rect)
{
	MakeNumbers *pRet = new MakeNumbers();
    if (pRet)
    {
		pRet->setMyRect(rect);
		pRet->init(pszFileName,attckmun,span);
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}

MakeNumbers* MakeNumbers::createWithSymbolRect(const string&pszFileName,int attckmun,int span,Rect rect)
{
	MakeNumbers *pRet = new MakeNumbers();
    if (pRet)
    {
		pRet->setMyRect(rect);
		pRet->initSymbol(pszFileName,attckmun,span);
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}

bool MakeNumbers::init(const string&pszFileName,int attckmun,int span, bool bAutoSize)
{	
	//获取整张素材图片，图片内容为0123456789；
	Texture2D *number_all = Director::getInstance()->getTextureCache()->addImage(pszFileName);
	if(number_all==NULL)
		return false;

	//获取整张图片长宽
	float x = 0;
	float y = 0;
	float allwight = 0;
	float allhigth = 0;
	if(with_rect)
	{
		x = m_rect.origin.x;
		y = m_rect.origin.y;
		allwight = m_rect.size.width;
		allhigth = m_rect.size.height;
	}
	else
	{
		allwight = number_all->getContentSize().width;
		allhigth = number_all->getContentSize().height;
	}
	//获取单张图片长宽
	float onewight = allwight/10;
	float onehigth = allhigth;

	char char_attckmun[256] = {0};
	sprintf(char_attckmun,"%d",attckmun);

	int nNumLen = ccstrlen(char_attckmun);
	for (int i = 0; i < nNumLen; i++)
	{
		//依次解析每个数值大小
		char nownumber =  char_attckmun[i];
		//将解析数值去寻找图片
		Rect imgrect_moren = Rect(x+onewight*(nownumber - '0'),y,onewight,onehigth);
		Sprite* numbers_now = Sprite::createWithTexture(number_all,imgrect_moren);
		//将得到的图片依次尾追在“-”图片得后面
		if(numbers_now)
		{
			if (bAutoSize)
				numbers_now->setAnchorPoint(Vec2::ZERO);
			numbers_now->setPosition(Point(( onewight+span)*i,0));
			addChild(numbers_now,2,10+i);
		}
	}

	if (bAutoSize)
		setContentSize(Size((onewight+span)*(nNumLen), onehigth));

	return true;
}

bool MakeNumbers::initSymbol(const string&pszFileName,int attckmun,int span, bool bAutoSize)
{
	//获取整张素材图片，图片内容为-0123456789；
	Texture2D *number_all = Director::getInstance()->getTextureCache()->addImage(pszFileName);
	if(number_all==NULL)
		return false;

	//获取整张图片长宽
	float x = 0;
	float y = 0;
	float allwight = 0;
	float allhigth = 0;
	if(with_rect)
	{
		x = m_rect.origin.x;
		y = m_rect.origin.y;
		allwight = m_rect.size.width;
		allhigth = m_rect.size.height;
	}
	else
	{
		allwight = number_all->getContentSize().width;
		allhigth = number_all->getContentSize().height;
	}
	//获取单张图片长宽
	float onewight = allwight/11;
	float onehigth = allhigth;
	//获取第一个符号扣血-作为首张图片的底图
	Rect imgrect_moren = Rect(x,y,onewight,onehigth);
	Sprite* numbers = Sprite::createWithTexture(number_all,imgrect_moren);
	if(numbers==NULL)
		return false;

	if (bAutoSize)
		numbers->setAnchorPoint(Vec2::ZERO);
	
	char char_attckmun[256] = {0};
	sprintf(char_attckmun,"%d",attckmun);

	//循环解析出“-”符号号后面的具体数值伤害
	int nNumLen = ccstrlen(char_attckmun);
	for (int i = 0; i < nNumLen; i++)
	{
		//依次解析每个数值大小
		char nownumber = char_attckmun[i];
		//将解析数值去寻找图片
		Rect imgrect_moren = Rect(x+onewight*(nownumber - '0')+onewight,y,onewight,onehigth);
		Sprite* numbers_now = Sprite::createWithTexture(number_all,imgrect_moren);
		//将得到的图片依次尾追在“-”图片得后面
		if(numbers_now)
		{
			if (bAutoSize)
				numbers_now->setAnchorPoint(Vec2::ZERO);
			numbers_now->setPosition(Point(( onewight+span)*(i+1),0));
			addChild(numbers_now,2,10+i);
		}
	}

	addChild(numbers);

	if (bAutoSize)
		setContentSize(Size((onewight+span)*(nNumLen+1), onehigth));
	return true;
}

MakeNumbers::~MakeNumbers(void)
{
}

