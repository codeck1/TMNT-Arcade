#ifndef __AI_H_
#define __AI_H_


#include<list>
#include "Globals.h"
#include "Animation.h"
#include "Point.h"
#include "ModuleCollision.h"
#include "Enemy.h"




struct SDL_Texture;


class AI
{
public:
	AI();
	~AI();
	iPoint StateMachine(State state, iPoint position, iPoint playerPos);


public:
	iPoint enemyPos;

};

#endif
