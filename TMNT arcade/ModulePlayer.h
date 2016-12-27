#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "Point.h"
#include "Time.h"
#include <random>
#include <chrono>
#include <time.h>

struct SDL_Texture;

class ModulePlayer : public Module
{
public:
	ModulePlayer(bool active = true);
	~ModulePlayer();

	bool Start();
	update_status Update();
	void OnCollision(Collider* c1, Collider* c2);
	bool CleanUp();
	


public:

	SDL_Texture* graphics = nullptr;
	Animation* current_animation = nullptr;
	Animation idle;
	Animation idleLeft;
	Animation up;
	Animation jump;
	Animation jumpLeft;
	Animation upLeft;
	Animation right;
	Animation left;
	Animation atack1;
	Animation atack1Left;
	Animation atack2;
	Animation atack2Left;
	Animation down;
	iPoint position;
	bool destroyed = false;
	Collider* collider;
	bool faceRight = true;
	bool inAir = false;
	bool jumped = false;
	bool goingDown = false;
	bool attacking = false;
	int jumpPos;

	uint64_t timeSeed2;
	mt19937_64 range2;
	double randomVar;


};

#endif