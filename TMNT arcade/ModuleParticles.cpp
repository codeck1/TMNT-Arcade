#include <math.h>
#include "ModuleParticles.h"
#include "Application.h"
#include "ModuleAudio.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModuleEnemy.h"


#include "SDL/include/SDL_timer.h"

ModuleParticles::ModuleParticles()
{
	// Explosion particle
	//explosion.fx = App->audio->LoadFx("rtype/explosion.wav");
	// Fire particle
	fire.anim.frames.push_back({ 17, 430, 304, 65 });
	fire.anim.frames.push_back({ 335, 430, 304, 65 });
	fire.anim.frames.push_back({ 17, 495, 304, 65 });
	fire.anim.frames.push_back({ 335, 495, 304, 65 });
	fire.anim.frames.push_back({ 17, 560, 304, 65 });
	fire.anim.frames.push_back({ 335, 560, 304, 65 });
	fire.anim.frames.push_back({ 710, 533, 304, 65 });
	fire.anim.frames.push_back({ 1029, 533, 304, 65 });
	fire.speed.x = 0;
	fire.speed.y = 0;
	fire.anim.loop = true;
	fire.anim.speed = 0.09f;

	//fire2
	fire2.anim.frames.push_back({ 335, 560, 304, 65 });
	fire2.anim.frames.push_back({ 17, 560, 304, 65 });
	fire2.anim.frames.push_back({ 335, 495, 304, 65 });
	fire2.anim.frames.push_back({ 17, 495, 304, 65 });
	fire2.anim.frames.push_back({ 335, 430, 304, 65 });
	fire2.anim.frames.push_back({ 17, 430, 304, 65 });
	fire2.speed.x = 0;
	fire2.speed.y = 0;
	fire2.anim.loop = true;
	fire2.anim.speed = 0.09f;

	//star
	star.anim.frames.push_back({ 131, 329, 12, 12 });
	star.anim.frames.push_back({ 155, 353, 12, 12 });
	star.anim.frames.push_back({ 180, 328, 12, 12 });
	star.speed.x = 0;
	star.speed.y = 0;
	star.anim.loop = true;
	star.anim.speed = 0.2f;

	//door
	door.anim.frames.push_back({ 269, 242, 34, 79 });
	door.anim.frames.push_back({ 309, 242, 34, 79 });
	door.anim.frames.push_back({ 349, 242, 34, 79 });
	door.anim.frames.push_back({ 401, 242, 56, 79 });
	door.speed.x = 0;
	door.speed.y = 0;
	door.anim.loop = false;
	door.anim.speed = 0.2f;
	door.active = false;
	door.door = true;

	//door2
	door2.anim.frames.push_back({ 269, 336, 43, 79 });
	door2.anim.frames.push_back({ 314, 336, 43, 79 });
	door2.anim.frames.push_back({ 362, 336, 43, 79 });
	door2.speed.x = 0;
	door2.speed.y = 0;
	door2.anim.loop = false;
	door2.anim.speed = 0.1f;
	door2.active = false;
	door2.door = true;
}

ModuleParticles::~ModuleParticles()
{}

// Load assets
bool ModuleParticles::Start()
{
	LOG("Loading particles");
	graphics = App->textures->Load("rtype/stagepart.png");
	door.fx = App->audio->LoadFx("rtype/breakdoor.wav");
	door2.fx = App->audio->LoadFx("rtype/elevator.wav");

	return true;
}

// Unload assets
bool ModuleParticles::CleanUp()
{
	LOG("Unloading particles");
	App->textures->Unload(graphics);

	for (list<Particle*>::iterator it = active.begin(); it != active.end(); ++it)
		RELEASE(*it);

	active.clear();

	return true;
}

// Update: draw background
update_status ModuleParticles::Update()
{
	for (list<Particle*>::iterator it = active.begin(); it != active.end();)
	{
		Particle* p = *it;

		if (p->e != nullptr && p->e->shootImpact)
		{
			p->collider = App->collision->DeleteCollider(p->collider);
			delete p;
			active.remove(p);
			break;
		}
		if (p->door && p->anim.Finished())
		{
			iPoint move = p->position;
			move.y += 30;
			App->enemy->AddEnemy(App->enemy->enemy1, move, TYPE1);
			delete p;
			active.remove(p);
			break;
		}
		if (abs(App->player->position.x - p->position.x) < 40)
		{
			p->active = true;
			if (p->fx_played == false)
			{
				p->fx_played = true;
				App->audio->PlayFx(p->fx);
			}
		}
			
		if(p->Update() == false)
		{
			RELEASE(*it);
			it = active.erase(it);
		}
		else
		{
			if(p->active)
				App->renderer->Blit(graphics, p->position.x, p->position.y, &(p->anim.GetCurrentFrame()));
			else
				App->renderer->Blit(graphics, p->position.x, p->position.y, &(p->firstFrame));
			if (p->fx_played == false && !p->door)
			{
				p->fx_played = true;
				App->audio->PlayFx(p->fx);
			}
			++it;
		}
	}

	return UPDATE_CONTINUE;
}

void ModuleParticles::AddParticle(const Particle& particle, int x, int y, const int speed, Enemy* enemy , COLLIDER_TYPE collider_type)
{
	Particle* p = new Particle(particle);
	p->position.x = x;
	p->position.y = y;
	p->speed.x = speed;
	p->e = enemy;
	p->firstFrame = p->anim.frames[0];
	if (collider_type != COLLIDER_NONE)
	{
		if(p != &door)
			p->collider = App->collision->AddCollider({ p->position.x, p->position.y, 0, 0 }, collider_type, this);
	}

	active.push_back(p);
}

// -------------------------------------------------------------
// -------------------------------------------------------------

Particle::Particle()
{}

Particle::Particle(const Particle& p) : anim(p.anim), position(p.position), speed(p.speed), fx_played(false), collider(p.collider), e(p.e), active(p.active), firstFrame(p.firstFrame), door(p.door)
{
	fx = p.fx;
	to_delete = p.to_delete;
}

Particle::~Particle()
{
}

bool Particle::Update()
{
	bool ret = true;
	position.x += speed.x;
	position.y += speed.y;
	if (collider != NULL)
	{
		SDL_Rect r = anim.GetCurrentFrame();
		collider->rect = { position.x, position.y, r.w, r.h };
	}

	return ret;
	
}

void ModuleParticles::OnCollision(Collider* c1, Collider* c2)
{

	for (list<Particle*>::iterator it = active.begin(); it != active.end();)
	{	
		Particle* aux = *it;
		if (aux->collider == c1 && (c2->type == COLLIDER_PLAYER_BODY || c2->type == COLLIDER_BORDER))
		{
			aux->e->shootImpact = true;
			
			break;
		}
		++it;

		
	}
}

