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
	TYPE2,
	TYPE3
};

enum EnemyState
{
	ENEMYIDLE,
	ENEMYJUMPING,
	ENEMYATTACKING, 
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
	Animation* current_animation = nullptr;
	Animation idle;
	Animation idleLeft;
	Animation up;
	Animation upLeft;
	Animation right;
	Animation left;
	Animation attack1;
	Animation attack1Left;
	Animation attack2;
	Animation attack2Left;
	Animation attackAir;
	Animation attackAirLeft;
	iPoint position;
	bool eliminated = false;
	Collider* colliderFeet;
	Collider* colliderBody;
	Collider* colliderWeapon;
	Collider* colliderJump;
	bool faceRight = true;
	bool inAir = false;
	bool jumped = false;
	bool goingDown = false;
	bool attacking = false;
	int jumpPos;
	int attackingAirX = 0;
	iPoint jumpInit;
	EnemyState currentState = ENEMYIDLE;
	EnemyType eType;


};

#endif
