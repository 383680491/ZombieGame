local t = {
	DIR_RIGHT = 0,
	DIR_RIGHT_UP = 1,
	DIR_UP = 2,
	DIR_LEFT_UP = 3,
	DIR_LEFT = 4,
    DIR_LEFT_DOWN = 5,
	DIR_DOWN = 6,
	DIR_RIGHT_DOWN = 7,


    ACTION_RUN = 1,
    ACTION_STAND = 2,
    ACTION_ATTACK = 3,
    ACTION_HURT = 4,
    ACTION_DEATH = 5,
    ACTION_APPEAR = 6,
    ACTION_MAGIC_UP = 7,
    ACTION_WALK = 8,
    --碰撞
    ACTIVE_COLLIDE = 9,


    ActionRelative = {
        'run',
        'stand',
        'attack',
        'hurt',
        'death',
        'appear',
        'magic_up',
        'walk'
    }
}

return t