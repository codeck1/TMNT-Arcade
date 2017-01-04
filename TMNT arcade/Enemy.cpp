#include "Enemy.h"
#include "Application.h"
#include "ModulePlayer.h"

Enemy::Enemy()
{
}

Enemy::Enemy(const Enemy & e) : idle(e.idle), idleLeft(e.idleLeft), up(e.up), upLeft(e.upLeft),
right(e.right), left(e.left), attack1(e.attack1), attack1Left(e.attack1Left), attack2(e.attack2),
attack2Left(e.attack2Left), attackAir(e.attackAir), attackAirLeft(e.attackAirLeft), position(e.position),
eliminated(e.eliminated), colliderFeet(e.colliderFeet), colliderBody(e.colliderBody), colliderWeapon(e.colliderWeapon),
colliderJump(e.colliderJump), faceRight(e.faceRight), inAir(e.inAir), jumped(e.jumped), goingDown(e.goingDown),
attacking(e.attacking), jumpPos(e.jumpPos), jumpInit(e.jumpInit), currentState(e.currentState), graphics(e.graphics)
{
}

Enemy::~Enemy()
{
}

bool Enemy::Start()
{
	return true;
}

bool Enemy::Update()
{
	iPoint walk;
	walk.x = 0;
	walk.y = 0;
	current_animation = &idleLeft;

	switch (currentState)
	{
	case ENEMYIDLE:

	if (abs(App->player->position.x - position.x) > SCREEN_WIDTH/4)
		{
			currentState = GOINGX;
		}
		else
		{
			if (abs(App->player->position.y - position.y) > 0)
			{
				currentState = GOINGY;
			}
			else
			{
				if (abs(App->player->position.x - position.x) > 0)
				{
					currentState = GOINGX;
				}
			}
		}
		break;

	case ENEMYJUMPING:
		break;
	case GOINGY:
		if(abs(App->player->position.x - position.x) <= SCREEN_WIDTH / 4)
		{
			if ((App->player->position.y - position.y) < 0)
			{
				walk.y = -1;

			}
			else
			{
				if ((App->player->position.y - position.y) > 0)
					walk.y = 1;
				else
					currentState = ENEMYIDLE;
			}
		}
		else
			currentState = ENEMYIDLE;
		
		break;
	case GOINGX:
		if(abs(App->player->position.y - position.y) == 0 || abs(App->player->position.x - position.x) > SCREEN_WIDTH / 4)
		{
			if ((App->player->position.x - position.x) < 0)
			{
				walk.x = -1;
				if (current_animation != &idleLeft)
				{
					current_animation = &idleLeft;
				}
			}
			else
			{
				if ((App->player->position.x - position.x) > 0)
					walk.x = 1;
				else
					currentState = ENEMYIDLE;
			}
		}
		else
			currentState = ENEMYIDLE;
		
	case ENEMYATTACKING:
		break;
	}
	current_animation = &idleLeft;

	position += walk;
	return true;
}
