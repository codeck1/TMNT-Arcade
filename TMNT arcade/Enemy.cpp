#include "Enemy.h"
#include "Application.h"
#include "ModulePlayer.h"

Enemy::Enemy()
{
}

Enemy::Enemy(const Enemy & e) : up(e.up), upLeft(e.upLeft),right(e.right), left(e.left),
attack1(e.attack1), attack1Left(e.attack1Left), attack2(e.attack2),attack2Left(e.attack2Left),
attackAir(e.attackAir), attackAirLeft(e.attackAirLeft), position(e.position),
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

	walk.x = 0;
	walk.y = 0;

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
				if (faceRight)
				{
					if (current_animation != &up)
					{
						current_animation = &up;
					}
				}
				else
					if (current_animation != &upLeft)
					{
						current_animation = &upLeft;
					}
			}
			else
			{
				if ((App->player->position.y - position.y) > 0)
				{
					
					walk.y = 1;
					if (faceRight)
					{
						if (current_animation != &right)
						{
							current_animation = &right;
						}
					}
					else
						if (current_animation != &left)
						{
							current_animation = &left;
						}
				}
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
				faceRight = false;

				if (abs(App->player->position.x - position.x) <= 25)
				{
					currentState = ENEMYATTACKING;
					break;
				}
				walk.x = -1;
				if (current_animation != &left)
				{
					current_animation = &left;
				}
			}
			else
			{
				if ((App->player->position.x - position.x) > 0)
				{
					faceRight = true;
					if (abs(App->player->position.x - position.x) <= 25)
					{
						currentState = ENEMYATTACKING;
						break;
					}
					walk.x = 1;
					if (current_animation != &right)
					{
						current_animation = &right;
					}
				}
				else
					currentState = ENEMYIDLE;

			}
		}
		else
			currentState = ENEMYIDLE;
		break;
		
	case ENEMYATTACKING:
		if (App->player->currentState == BEINGATTACKED)
		{
			if (colliderWeapon != nullptr)
				colliderWeapon = App->collision->DeleteCollider(colliderWeapon);
			break;

		}
		if ((abs(App->player->position.x - position.x) <= 25 )&& abs(App->player->position.y - position.y) == 0)
		{
			if (faceRight)
			{
				if (current_animation != &attack1)
				{
					colliderWeapon = App->collision->AddCollider({ position.x + 30, position.y + 10, 30, 15 }, COLLIDER_ENEMY_WEAPON, (Module*)App->enemy);
					attack1.Reset();
					current_animation = &attack1;
				}
			}
			else
			{
				if (current_animation != &attack1Left)
				{
					colliderWeapon = App->collision->AddCollider({ position.x - 30, position.y + 20, 30, 15 }, COLLIDER_ENEMY_WEAPON, (Module*)App->enemy);
					attack1Left.Reset();
					current_animation = &attack1Left;
				}
			}
		}
		else
			currentState = ENEMYIDLE;

		if ((current_animation == &attack1 || current_animation == &attack1Left) && current_animation->Finished() )
		{
			current_animation = &right;
			if (colliderWeapon != nullptr)
				colliderWeapon = App->collision->DeleteCollider(colliderWeapon);

		}
		break;
	}
	
	position += walk;
	return true;
}
