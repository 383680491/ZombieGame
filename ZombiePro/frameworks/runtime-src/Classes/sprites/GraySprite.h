#ifndef _SPIRIT_GRAY_H_
#define _SPIRIT_GRAY_H_

#include "cocos2d.h"

class GraySprite : public cocos2d::Sprite
{
public: 
	GraySprite();
	virtual ~GraySprite(void);
	static GraySprite* create();
	static GraySprite* create(const std::string&pszFileName);
	void addColorGray();
	void removeColorGray();
	void setColorGray(bool);
	void setColorWrite(bool);
	virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4& parentTransform, uint32_t parentFlags);
	virtual void visit(cocos2d::Renderer *renderer, const cocos2d::Mat4& parentTransform, uint32_t parentFlags);
	CC_SYNTHESIZE(bool, m_reDraw, ReDraw);
	CC_SYNTHESIZE(bool, m_doreDraw, DoReDraw);
private:
	cocos2d::PolygonInfo  m_polyInfo;
	cocos2d::TrianglesCommand  m_cmd;
};
#endif