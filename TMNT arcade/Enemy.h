#ifndef __Enemy_H_
#define __Enemy_H_


#include<list>
#include "Globals.h"
#include "Module.h"
#include "Animation.h"
#include "Point.h"
#include "ModuleCollision.h"

struct SDL_Texture;

enum EnemyType
{
	TYPE1,
	TYPE2
};

enum EnemyState
{
	ENEMYIDLE,
	ENEMYATTACKING, 
	ENEMYBEINGATTACKED,
	ENEMYTAKEDOWN,
	GOINGY,
	GOINGX
};

class Enemy
{
public:
	Enemy();
	Enemy(const Enemy& e);
	~Enemy();
	bool Start();
	bool Update(); 

public:

	SDL_Texture* graphics = nullptr;
	Animation up;
	Animation upLeft;
	Animation right;
	Animation left;
	Animation attack1;
	Animation attack1Left;
	Animation attack2;
	Animation attack2Left;
	Animation reciveDamage;
	Animation reciveDamageLeft;
	Animation reciveDamage2;
	Animation reciveDamage2Left;
	Animation reciveDamage3;
	Animation reciveDamage3Left;
	Animation* current_animation = &right;
	iPoint position;
	bool eliminated = false;
	Collider* colliderFeet;
	Collider* colliderBody;
	Collider* colliderWeapon;
	Collider* colliderJump;
	bool faceRight = true;
	bool jumped = false;
	bool attacking = false;
	int attackingAirX = 0;
	EnemyState currentState = ENEMYIDLE;
	EnemyType eType;
	iPoint walk;
	Collider* collider = NULL;
	int hits = 0;
	bool toDelete = false;
	bool shootImpact = false;

};

#endif
