#ifndef _9SPIRIT_TOUCH_H_
#define _9SPIRIT_TOUCH_H_

#include "cocos2d.h"

#include "ui/UIScale9Sprite.h"

class Touch9Sprite : public  cocos2d::ui::Scale9Sprite
{
public: 
	Touch9Sprite();
	virtual ~Touch9Sprite(void);
	static Touch9Sprite* create();
	static Touch9Sprite* create(const char* file,const cocos2d::Size rect);
	virtual bool initTouch();
	bool isTouchInside(cocos2d::Touch* touch);
	void registerTouchDownHandler(int handler);
	void registerTouchUpHandler(int handler);
	void setTouchEnable(bool enable = true);
	void setActionEnable(bool enable = true){needAction = enable; };
private:
	int m_scriptSelectedHandler;
	int m_scriptUnselectedHandler;
	bool m_touch_enable;
	bool m_smalltobig;
	bool needAction;
};
#endif