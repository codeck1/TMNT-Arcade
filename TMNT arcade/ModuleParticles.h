#ifndef __MODULEPARTICLES_H__
#define __MODULEPARTICLES_H__

#include<list>
#include "Globals.h"
#include "Module.h"
#include "Animation.h"
#include "Point.h"
#include "ModuleCollision.h"
#include "Enemy.h"

struct SDL_Texture;

struct Particle
{
	bool to_delete = false;
	unsigned int fx;
	iPoint position;
	iPoint speed;
	Animation anim;
	bool fx_played;
	Collider* collider = NULL;
	Enemy* e;
	bool active = true;
	SDL_Rect firstFrame;
	bool door = false;

	Particle();
	Particle(const Particle& p);
	~Particle();
	bool Update();
};

class ModuleParticles : public Module
{
public:
	ModuleParticles();
	~ModuleParticles();
	void OnCollision(Collider*, Collider*);
	bool Start();
	update_status Update();
	bool CleanUp();

	void AddParticle(const Particle& particle, int x, int y, const int speed, Enemy* enemy = nullptr,  COLLIDER_TYPE = COLLIDER_NONE ); // feel free to expand this call

private:

	SDL_Texture* graphics = nullptr;
	std::list<Particle*> active;

public:
	Particle star;
	Particle fire;
	Particle fire2;
	Particle door;
};

#endif // __MODULEPARTICLES_H__