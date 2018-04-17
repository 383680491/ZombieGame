#include "SpriteNpc.h"

USING_NS_CC;

SpriteNpc::SpriteNpc()
{	
}


SpriteNpc *SpriteNpc::create(const std::string&pszFileName)
{
    SpriteNpc *pRet = new SpriteNpc();
	
    if (pRet && pRet->initWithFile(pszFileName))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}

SpriteNpc::~SpriteNpc(void)
{
}

