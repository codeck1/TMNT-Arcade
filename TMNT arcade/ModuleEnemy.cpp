#include "ModuleEnemy.h"
#include "Application.h"
#include "ModuleAudio.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"

ModuleEnemy::ModuleEnemy()
{
}

ModuleEnemy::~ModuleEnemy()
{
}

bool ModuleEnemy::Start()
{
	LOG("Loading enemies");
	enemy1.graphics = App->textures->Load("rtype/enemy1.png");
	// Explosion particle
	enemy1.right.frames.push_back({ 206,529,103,75 });

	return false;
}

update_status ModuleEnemy::Update()
{
	for (list<Enemy*>::iterator it = active.begin(); it != active.end();)
	{
		Enemy* e = *it;

		if (e->Update() == false)
		{
			RELEASE(*it);
			it = active.erase(it);
		}
		else
		{
			App->renderer->Blit(e->graphics, e->position.x, e->position.y, &(e->current_animation->GetCurrentFrame()));
			++it;
		}
	}
	return UPDATE_CONTINUE;
}

bool ModuleEnemy::CleanUp()
{
	LOG("Unloading particles");
	if(enemy1.graphics != NULL)
		App->textures->Unload(enemy1.graphics);
	
	for (list<Enemy*>::iterator it = active.begin(); it != active.end(); ++it)
		RELEASE(*it);

	active.clear();

	return true;
}

void ModuleEnemy::AddEnemy(const Enemy & enemy, iPoint position, EnemyType type)
{
	Enemy* e = new Enemy(enemy);
	e->position.x = position.x;
	e->position.y = position.y;
	e->eType = type;
	e->colliderFeet = App->collision->AddCollider({ position.x, position.y + 50, 32, 14 }, COLLIDER_PLAYER_FEET, this);
	e->colliderBody = App->collision->AddCollider({ position.x, position.y + 10, 32, 45 }, COLLIDER_PLAYER_BODY, this);

	active.push_back(e);
}
