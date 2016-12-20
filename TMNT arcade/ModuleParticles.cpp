#include <math.h>
#include "ModuleParticles.h"
#include "Application.h"
#include "ModuleAudio.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"

#include "SDL/include/SDL_timer.h"

ModuleParticles::ModuleParticles()
{}

ModuleParticles::~ModuleParticles()
{}

// Load assets
bool ModuleParticles::Start()
{
	LOG("Loading particles");
	graphics = App->textures->Load("rtype/particles.png");

	// Explosion particle
	explosion.fx = App->audio->LoadFx("rtype/explosion.wav");
	explosion.anim.frames.push_back({ 274, 296, 33, 30 });
	explosion.anim.frames.push_back({ 313, 296, 33, 30 });
	explosion.anim.frames.push_back({ 346, 296, 33, 30 });
	explosion.anim.frames.push_back({ 382, 296, 33, 30 });
	explosion.anim.frames.push_back({ 419, 296, 33, 30 });
	explosion.anim.frames.push_back({ 457, 296, 33, 30 });
	explosion.speed.x = 0;
	explosion.speed.y = 0;
	explosion.anim.loop = false;
	explosion.anim.speed = 0.3f;


	// Laser particle
	laser.fx = App->audio->LoadFx("rtype/slimeball.wav");
	laser.anim.frames.push_back({ 200, 120, 32, 12 });
	laser.anim.frames.push_back({ 230, 120, 32, 12 });
	laser.anim.loop = true;
	laser.speed.x = 7;
	laser.speed.y = 0;
	laser.anim.speed = 0.05f;

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

		if(p->Update() == false)
		{
			RELEASE(*it);
			it = active.erase(it);
		}
		else
		{
			App->renderer->Blit(graphics, p->position.x, p->position.y, &(p->anim.GetCurrentFrame()));
			if (p->fx_played == false)
			{
				p->fx_played = true;
				App->audio->PlayFx(p->fx);
			}
			++it;
		}
	}

	return UPDATE_CONTINUE;
}

void ModuleParticles::AddParticle(const Particle& particle, int x, int y, COLLIDER_TYPE collider_type)
{
	Particle* p = new Particle(particle);
	p->position.x = x;
	p->position.y = y;
	if (collider_type != COLLIDER_NONE)
	{
		p->collider = App->collision->AddCollider({ p->position.x, p->position.y, 0, 0 }, collider_type, this);
	}

	active.push_back(p);
}

// -------------------------------------------------------------
// -------------------------------------------------------------

Particle::Particle()
{}

Particle::Particle(const Particle& p) : anim(p.anim), position(p.position), speed(p.speed), fx_played(false), collider(p.collider)
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
	if (anim.Finished())
		ret = false;
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
		if (aux->collider == c1)
		{
			delete aux;
			active.remove(aux);
			break;
		}

		
	}
}

