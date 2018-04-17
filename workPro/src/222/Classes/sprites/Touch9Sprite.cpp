#include "Touch9Sprite.h"
#include "CCLuaEngine.h"

USING_NS_CC;

Touch9Sprite::Touch9Sprite()
	: m_scriptSelectedHandler(0)
	, m_scriptUnselectedHandler(0)
	,m_smalltobig(false)
	,m_touch_enable(true)
	,needAction(true)
{
}

Touch9Sprite::~Touch9Sprite(void)
{
	if (m_scriptSelectedHandler != 0)
		cocos2d::LuaEngine::getInstance()->removeScriptHandler(m_scriptSelectedHandler);

	if (m_scriptUnselectedHandler != 0)
		cocos2d::LuaEngine::getInstance()->removeScriptHandler(m_scriptUnselectedHandler);
}


bool Touch9Sprite::isTouchInside(Touch* touch)
{
	Point touchs = touch->getLocation();
	Point localPos =  convertToNodeSpace(touchs);
	//Point anc = getAnchorPoint();
	//Point pos = getPosition();
	Size ss = getContentSize();
	//Rect touch_rect = getBoundingBox();
	Rect touch_rect = Rect(0,0,ss.width,ss.height);
	//Rect touch_rect = Rect(pos.x-ss.width*anc.x,pos.y-ss.height*anc.y,ss.width,ss.height);

	return	touch_rect.containsPoint(localPos);
}

void Touch9Sprite::setTouchEnable(bool enable)
{
	m_touch_enable = enable;
}

bool Touch9Sprite::initTouch()
{
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	auto myListener = EventListenerTouchOneByOne::create();

    myListener->setSwallowTouches(true);

	myListener->onTouchBegan = [=](Touch* touch,Event* event)
	{
		if(!m_touch_enable|| !isVisible())
		{
			return false;
		}

		for (Node *c = getParent(); c != nullptr; c = c->getParent())
		{
			if (c->isVisible() == false)
			{
				return false;
			}
		}

		if(isTouchInside(touch))
		{
			if(needAction)
			{
				if(m_smalltobig)
					runAction(ScaleTo::create(0.15,1.15));
				else
					runAction(ScaleTo::create(0.15,0.75));
			}

			if (!m_scriptSelectedHandler) 
				return true;

			LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
			if (pStack == NULL)
				return false;

			pStack->pushObject(this, "Touch9Sprite");
			pStack->executeFunctionByHandler(m_scriptSelectedHandler, 1);
			pStack->clean();
			return true;  
		}
		return false;
	};

	myListener->onTouchMoved = [=](Touch* touch,Event* event)
	{
	};

	myListener->onTouchEnded = [=](Touch* touch,Event* event)
	{
		if(needAction)
		{
			if(m_smalltobig)
				runAction(Sequence::create(ScaleTo::create(0.15,0.85),ScaleTo::create(0.05,1.0),NULL));
			else	
				runAction(Sequence::create(ScaleTo::create(0.15,1.1),ScaleTo::create(0.05,1.0),NULL));
		}
		if (!m_scriptUnselectedHandler) 
			return;
		if(isTouchInside(touch))
		{
			LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
			if (pStack == NULL)
				return;

			pStack->pushObject(this, "Touch9Sprite");
			pStack->executeFunctionByHandler(m_scriptUnselectedHandler, 1);
			pStack->clean();
		}
	};

	dispatcher->addEventListenerWithSceneGraphPriority(myListener,this);

	return true;
}



Touch9Sprite *Touch9Sprite::create(const char* file,const Size s)
{
    Touch9Sprite *pRet = new Touch9Sprite();
	if (pRet && pRet->initWithFile(file))
    {
		pRet->setContentSize(s);
		pRet->initTouch();
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}

Touch9Sprite *Touch9Sprite::create()
{
    Touch9Sprite *pRet = new Touch9Sprite();
    if (pRet && pRet->init()&& pRet->initTouch())
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

void Touch9Sprite::registerTouchDownHandler(int handler)
{
	if (m_scriptSelectedHandler != handler)
    {
        if (m_scriptSelectedHandler != 0)
            cocos2d::LuaEngine::getInstance()->removeScriptHandler(m_scriptSelectedHandler);

        m_scriptSelectedHandler = handler;
    }
}

void Touch9Sprite::registerTouchUpHandler(int handler)
{
	if (m_scriptUnselectedHandler != handler)
    {
        if (m_scriptUnselectedHandler != 0)
            cocos2d::LuaEngine::getInstance()->removeScriptHandler(m_scriptUnselectedHandler);

        m_scriptUnselectedHandler = handler;
    }
}


