#pragma once
#include "SpriteBase.h"
using namespace cocos2d;

class SpriteCharacterBase : public SpriteBase 
{
public:
	SpriteCharacterBase()	{}
	virtual ~SpriteCharacterBase()	{}

	virtual Node* getSkillNode() = 0;
	virtual Node* getSkillDownNode() = 0;

protected:

};

class UISpriteCharacter : public SpriteCharacterBase 
{
public:
	static UISpriteCharacter* create(const std::string& pszFileName);

	UISpriteCharacter();
	virtual ~UISpriteCharacter();

	virtual Node* getSkillNode()		{ return this; }
	virtual Node* getSkillDownNode()	{ return this; }
	virtual Node* getBuffSkillNode()	{ return this; }

	void insertActionChild(SpriteBase* sprite);
	void insertBloodNode(int height);
	void setHP(int hp);
	int getHP(){return m_hp;};

	virtual bool setSpriteDir(Commen_Direction dir) override;

	virtual void playAction(float times,Commen_ActionToDo action,Commen_Direction dir,int loop,float ltimes=0.0f);

	virtual bool standed();
	bool MagicOneTime_ex(float times, const Point& newpoint);
	void doSetOpacity_ex();
	void doSetOpacity();
	void doStanded();
	bool moveInTheDir_ex(float times, Point newpoint,Commen_Direction dir,float movetimes);
	bool walkInTheDir_ex(float times, Point newpoint, Commen_Direction dir);
	bool collideInTheDir(float times,Point newpoint,Commen_Direction dir);
	void removeStread();
	void setOpacity(GLubyte opact);
	CC_SYNTHESIZE(unsigned int, m_maxhp, MaxHP);
	CC_SYNTHESIZE(double, m_spead, Speed);

protected:
	Vector<SpriteBase*> m_sprites;
	int show_offx;
	int show_h;
	Sprite* m_blood_bg;
	Sprite *m_blood_pro;
	int m_hp;
};