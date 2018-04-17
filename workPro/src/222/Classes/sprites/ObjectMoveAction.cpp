#include "ObjectMoveAction.h"

USING_NS_CC;

//
// ObjectMoveAction
//
ObjectMoveAction* ObjectMoveAction::create(float duration, const Vec2& position, const std::function<void()> &func)
{
    return ObjectMoveAction::create(duration, Vec3(position.x, position.y, 0), func);
}

ObjectMoveAction* ObjectMoveAction::create(float duration, const Vec3& position, const std::function<void()> &func)
{
    ObjectMoveAction *ret = new (std::nothrow) ObjectMoveAction();
    
    if (ret)
    {
        if (ret->initWithDuration(duration, position, func))
        {
            ret->autorelease();
        }
        else
        {
            delete ret;
            ret = nullptr;
        }
    }
    
    return ret;
}

bool ObjectMoveAction::initWithDuration(float duration, const Vec2& position, const std::function<void()> &func)
{
    return initWithDuration(duration, Vec3(position.x, position.y, 0), func);
}

bool ObjectMoveAction::initWithDuration(float duration, const Vec3& position, const std::function<void()> &func)
{
    bool ret = false;
    
    if (ActionInterval::initWithDuration(duration))
    {
        _endPosition = position;
		_function = func;
        ret = true;
    }
    
    return ret;
}

ObjectMoveAction* ObjectMoveAction::clone() const
{
    // no copy constructor
    auto a = new (std::nothrow) ObjectMoveAction();
    a->initWithDuration(_duration, _endPosition, _function);
    a->autorelease();
    return a;
}

void ObjectMoveAction::startWithTarget(Node *target)
{
    MoveBy::startWithTarget(target);
    _positionDelta = _endPosition - target->getPosition3D();
}

void ObjectMoveAction::step(float dt)
{
	if (_firstTick)
	{
		_firstTick = false;
		_elapsed = dt;
	}
	else
	{
		_elapsed += dt;
	}


	float updateDt = MAX(0,            // needed for rewind. elapsed could be negative
		MIN(1, _elapsed /
		MAX(_duration, FLT_EPSILON)   // division by 0
		)
		);

	if (sendUpdateEventToScript(updateDt, this)) return;

	this->update(updateDt);
}

void ObjectMoveAction::update(float t)
{
	MoveBy::update(t);

	if (_target)
	{
		if (t >= 1)
		{
			if ( _target->getPosition3D() != _endPosition)
				_target->setPosition3D(_endPosition);

			if (_function)
				_function();
		}
	}
}


ObjectMoveAction* ObjectMoveAction::reverse() const
{
    CCASSERT(false, "reverse() not supported in ObjectMoveAction");
    return nullptr;
}
