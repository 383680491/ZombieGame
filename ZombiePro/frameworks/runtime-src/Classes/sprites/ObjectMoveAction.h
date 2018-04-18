#ifndef __OBJECTMOVE_ACTION_H__
#define __OBJECTMOVE_ACTION_H__

#include "cocos2d.h"

class ObjectMoveAction : public cocos2d::MoveBy
{
public:
	static ObjectMoveAction* create(float duration, const cocos2d::Vec2& position, const std::function<void()> &func);
	static ObjectMoveAction* create(float duration, const cocos2d::Vec3& position, const std::function<void()> &func);

	//
    // Overrides
    //
    virtual ObjectMoveAction* clone() const override;
    virtual ObjectMoveAction* reverse() const  override;
    virtual void startWithTarget(cocos2d::Node *target) override;

	virtual void step(float dt) override;
	virtual void update(float time) override;

CC_CONSTRUCTOR_ACCESS:
    ObjectMoveAction() {}
    virtual ~ObjectMoveAction() {}

    /** 
     * initializes the action
     * @param duration in seconds
     */
    bool initWithDuration(float duration, const cocos2d::Vec2& position, const std::function<void()> &func);
    /**
     * initializes the action
     * @param duration in seconds
     */
    bool initWithDuration(float duration, const cocos2d::Vec3& position, const std::function<void()> &func);

protected:
	cocos2d::Vec3 _endPosition;

	/** function that will be called */
    std::function<void()> _function;

private:
	CC_DISALLOW_COPY_AND_ASSIGN(ObjectMoveAction);
};

#endif