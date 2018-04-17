#include "TouchSprite.h"
#include "CCLuaEngine.h"

USING_NS_CC;

TouchSprite::TouchSprite()
: m_scriptSelectedHandler(0)
, m_scriptUnselectedHandler(0)
{
	m_select_action = NULL;
	m_unselect_action = NULL;
	m_selectFrame = NULL;
	is_with_frame = false;
	m_iInitTouch = false;
}

TouchSprite::~TouchSprite(void)
{
	if(m_scriptUnselectedHandler>0)
		LuaEngine::getInstance()->removeScriptHandler(m_scriptUnselectedHandler);
	if(m_scriptSelectedHandler>0)
		LuaEngine::getInstance()->removeScriptHandler(m_scriptSelectedHandler);
}


bool TouchSprite::isTouchInside(Touch* touch)
{
	if(is_with_frame)
	{
		Point touchLocation = touch->getLocation();
		Point pos = getPosition();
		Point anr = getAnchorPoint();
		Size  size = getContentSize();
		Rect r = Rect(pos.x - size.width * anr.x,
                      pos.y - size.height * anr.y,
                      size.width, size.height);
		r.origin = Point::ZERO;
		Point local = this->convertToNodeSpace(touchLocation);
		return(r.containsPoint(local));
	}
	else
	{
		Point touchs = touch->getLocation();
		Point localPos = convertToNodeSpace(touchs);
		Rect touch_rect = getTextureRect();

		return	touch_rect.containsPoint(localPos);
	}
	return false;
}

void TouchSprite::setWithFrame(bool withframe)
{
	is_with_frame = withframe;
}

void TouchSprite::setSelectFrame(const std::string& frame)
{
	m_selectFrame = Sprite::createWithSpriteFrameName(frame);
	if(m_selectFrame)
	{
		m_selectFrame->setPosition(0,0);
		m_selectFrame->setAnchorPoint(Point(0,0));
		m_selectFrame->setVisible(false);
		addChild(m_selectFrame);
	}
}

void TouchSprite::setTouchEnable(bool enable)
{
	if(enable)
	{
		initTouch();
	}
	m_touch_enable = enable;
}
void TouchSprite::setEnable(bool enable)
{
	if(enable)
	{
	    initTouch();
		removeColorGray();
	}
	else
	{
		addColorGray();
	}
	m_touch_enable = enable;
}
bool TouchSprite::initTouch()
{
	if (m_iInitTouch)
		return true;

	m_iInitTouch = true;

	auto dispatcher = Director::getInstance()->getEventDispatcher();
	auto myListener = EventListenerTouchOneByOne::create();

    myListener->setSwallowTouches(true);

	myListener->onTouchBegan = [=](Touch* touch,Event* event)
	{
		if(!m_touch_enable|| !isVisible())
		{
			return false;
		}
		//DWORD nTime = GetTickCount();
		
		for (Node *c = getParent(); c != nullptr; c = c->getParent())
		{
			if (c->isVisible() == false)
			{
				return false;
			}
		}
		if(isTouchInside(touch))
		{
			if(m_select_action != NULL)
			{
				//runAction(m_select_action);
			}
			if(is_with_frame && m_selectFrame != NULL)
			{
				setOpacity(0);
				m_selectFrame->setVisible(true);
			}
			//CCLOG("b----------------------%d", GetTickCount()-nTime);
			if (!m_scriptSelectedHandler) 
				return true;

			//LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
			//if (pStack == NULL)
			//	return false;

			//pStack->pushObject(this, "TouchSprite");
			//pStack->executeFunctionByHandler(m_scriptSelectedHandler, 1);
			//pStack->clean();

			//CCLOG("----------------------%d", GetTickCount()-nTime);
			return true;  
		}
		return false;
	};

	myListener->onTouchMoved = [=](Touch* touch,Event* event)
	{
		if(is_with_frame && m_selectFrame != NULL && !isTouchInside(touch))
		{
			setOpacity(255);
			m_selectFrame->setVisible(false);
		}
	};

	myListener->onTouchEnded = [=](Touch* touch,Event* event)
	{
		if(m_unselect_action != NULL)
		{
			//runAction(m_unselect_action);
		}
		if (m_scriptUnselectedHandler == 0) 
			return;
		if(is_with_frame && m_selectFrame != NULL)
		{
			setOpacity(255);
			m_selectFrame->setVisible(false);
		}
		//DWORD nTime = GetTickCount();
		if(isTouchInside(touch))
		{
			LuaStack* pStack = LuaEngine::getInstance()->getLuaStack();
			if (pStack)
			{
				pStack->pushInt(this->getTag());
				pStack->pushObject(this, "TouchSprite");
				pStack->executeFunctionByHandler(m_scriptUnselectedHandler, 2);
				pStack->clean();
			}
		}
//#if CC_ENABLE_SCRIPT_BINDING
//        //if (kScriptTypeNone != _scriptType)
//        {
//            BasicScriptData data(this);
//            ScriptEvent scriptEvent(kMenuClickedEvent,&data);
//            ScriptEngineManager::getInstance()->getScriptEngine()->sendEvent(&scriptEvent);
//        }
//#endif
		//CCLOG("end----------------------%d", GetTickCount()-nTime);
	};

	dispatcher->addEventListenerWithSceneGraphPriority(myListener,this);

	return true;
}

TouchSprite *TouchSprite::create(const std::string&pszFileName,bool enable)
{
    TouchSprite *pRet = new TouchSprite();
    if (pRet && pRet->initWithFile(pszFileName))
    {
		pRet->setTouchEnable(enable);
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}

TouchSprite *TouchSprite::createWithFrame(const std::string&normalFrame,const std::string&selectFrame)
{
    TouchSprite *pRet = new TouchSprite(); 
	SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(normalFrame);
    if (pRet && frame && pRet->initWithSpriteFrame(frame))
    {
		pRet->setWithFrame(true);
		if(selectFrame.length()>0)
			pRet->setSelectFrame(selectFrame);
		pRet->setTouchEnable(true);
        pRet->autorelease();
        return pRet;
    }
    else
    {
        CC_SAFE_DELETE(pRet);
        return NULL;
    }
}

TouchSprite *TouchSprite::create()
{
    TouchSprite *pRet = new TouchSprite();
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

void TouchSprite::registerTouchDownHandler(int handler)
{
	;//m_scriptSelectedHandler = handler;
}

void TouchSprite::registerTouchUpHandler(int handler)
{
	if (m_scriptUnselectedHandler != handler)
    {
        if (m_scriptUnselectedHandler != 0)
            cocos2d::LuaEngine::getInstance()->removeScriptHandler(m_scriptUnselectedHandler);

        m_scriptUnselectedHandler = handler;
    }
   
}

void  TouchSprite::setSelectAction(Action* action)
{
	m_select_action = action;
}
void  TouchSprite::setUnSelectAction(Action* action)
{
	m_unselect_action = action;
}
