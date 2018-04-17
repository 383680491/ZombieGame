#ifndef _SPIRIT_NPC_
#define _SPIRIT_NPC_

#include "SpriteBase.h"



class SpriteNpc : public SpriteBase 
{
public: 

	SpriteNpc();
	virtual ~SpriteNpc(void);
	static SpriteNpc* create(const std::string&pszFileName);
	
 
};
#endif//_SPIRIT_PLAYER_
