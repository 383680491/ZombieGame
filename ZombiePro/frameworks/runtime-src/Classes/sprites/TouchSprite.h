#ifndef _SPIRIT_TOUCH_H_
#define _SPIRIT_TOUCH_H_

#include "GraySprite.h"

class TouchSprite : public GraySprite
{
public: 
	TouchSprite();
	virtual ~TouchSprite(void);
	static TouchSprite* create();
	static TouchSprite* create(const std::string&pszFileName,bool enable=false);
	static TouchSprite *createWithFrame(const std::string&normalFrame,const std::string&selectFrame = "");
	virtual bool initTouch();
	bool isTouchInside(cocos2d::Touch* touch);
	void registerTouchDownHandler(int handler);
	void registerTouchUpHandler(int handler);
	void setTouchEnable(bool enable = true);
	void setSelectAction(cocos2d::Action*);
	void setUnSelectAction(cocos2d::Action*);
	void setEnable(bool enable = true);
	void setWithFrame(bool withframe);
	void setSelectFrame(const std::string &frame);
private:
	int m_scriptSelectedHandler;
	int m_scriptUnselectedHandler;
	cocos2d::Action* m_select_action;
	cocos2d::Action* m_unselect_action;
	bool m_touch_enable;
	cocos2d::Sprite* m_selectFrame;
	bool is_with_frame;
	bool m_iInitTouch;
};
#endif