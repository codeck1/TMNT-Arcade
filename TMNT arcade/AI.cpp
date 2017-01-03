#include "AI.h"

AI::AI()
{
	enemyPos.x = 0;
	enemyPos.y = 0;
}

AI::~AI()
{
}

iPoint AI::StateMachine(State state, iPoint position, iPoint playerPos)
{
	switch (state)
	{
		case IDLE:

			if (abs(playerPos.x - position.x) > SCREEN_WIDTH / 2)
			{
				state = GOINGX;
			}
			else
			{
				if (abs(playerPos.y - position.y) > 0)
				{
					state = GOINGY;
				}
				else
				{
					if (abs(playerPos.x - position.x) > 0)
					{
						state = GOINGX;
					}
				}
			}
			break;

		case JUMPING:
			break;
		case ATTACKING:
			break;
		case GOINGY:
			if ((playerPos.y - position.y) < 0)
			{
				enemyPos.y = -2;
			}
			else
			{
				enemyPos.y = 2;
			}
			break;
		case GOINGX:
			if ((playerPos.x - position.x) < 0)
			{
				enemyPos.x = -2;
			}
			else
			{
				enemyPos.x = 2;
			}

		case ATTACK:
			break;
	}
	return enemyPos;
}
