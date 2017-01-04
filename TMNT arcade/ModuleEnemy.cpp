#include "ModuleEnemy.h"
#include "Application.h"
#include "ModuleAudio.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"

ModuleEnemy::ModuleEnemy()
{

	//Animaciones de cada enemigo y sonidos. Prototipos


	enemy1.left.frames.push_back({ 17, 0, 52, 64 });
	enemy1.left.frames.push_back({ 98, 0, 52, 64 });
	enemy1.left.frames.push_back({ 176, 0, 52, 64 });
	enemy1.left.frames.push_back({ 253, 0, 52, 64 });
	enemy1.left.frames.push_back({ 337, 0, 52, 64 });
	enemy1.left.frames.push_back({ 19, 80, 52, 64 });
	enemy1.left.frames.push_back({ 96, 80, 52, 64 });
	enemy1.left.frames.push_back({ 172, 80, 52, 64 });
	enemy1.left.pivotY = 10;
	enemy1.left.loop = true;
	enemy1.left.speed = 0.1f;

	enemy1.right.frames.push_back({ 751, 0, 52, 64 });
	enemy1.right.frames.push_back({ 674, 0, 52, 64 });
	enemy1.right.frames.push_back({ 593, 0, 52, 64 });
	enemy1.right.frames.push_back({ 508, 0, 52, 64 });
	enemy1.right.frames.push_back({ 433, 0, 52, 64 });
	enemy1.right.frames.push_back({ 757, 80, 52, 64 });
	enemy1.right.frames.push_back({ 671, 80, 52, 64 });
	enemy1.right.frames.push_back({ 589, 80, 52, 64 });
	enemy1.right.pivotY = 10;
	enemy1.right.loop = true;
	enemy1.right.speed = 0.1f;

	enemy1.upLeft.frames.push_back({ 256, 81, 52, 64 });
	enemy1.upLeft.frames.push_back({ 336, 81, 52, 64 });
	enemy1.upLeft.frames.push_back({ 17, 160, 52, 64 });
	enemy1.upLeft.frames.push_back({ 96, 160, 52, 64 });
	enemy1.upLeft.frames.push_back({ 176, 160, 52, 64 });
	enemy1.upLeft.frames.push_back({ 252, 160, 52, 64 });
	enemy1.upLeft.frames.push_back({ 333, 160, 52, 64 });
	enemy1.upLeft.frames.push_back({ 14, 240, 52, 64 });
	enemy1.upLeft.pivotY = 10;
	enemy1.upLeft.loop = true;
	enemy1.upLeft.speed = 0.1f;
	
	enemy1.up.frames.push_back({ 512, 81, 52, 64 });
	enemy1.up.frames.push_back({ 433, 81, 52, 64 });
	enemy1.up.frames.push_back({ 753, 160, 52, 64 });
	enemy1.up.frames.push_back({ 671, 160, 52, 64 });
	enemy1.up.frames.push_back({ 595, 160, 52, 64 });
	enemy1.up.frames.push_back({ 509, 160, 52, 64 });
	enemy1.up.frames.push_back({ 431, 160, 52, 64 });
	enemy1.up.frames.push_back({ 749, 240, 52, 64 });
	enemy1.up.loop = true;
	enemy1.up.speed = 0.05f;
}

ModuleEnemy::~ModuleEnemy()
{
}

bool ModuleEnemy::Start()
{
	LOG("Loading enemies");
	enemy1.graphics = App->textures->Load("rtype/enemy1.png");
	// Explosion particle

	return true;
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
			App->renderer->Blit(e->graphics, e->position.x, e->position.y+e->current_animation->pivotY, &(e->current_animation->GetCurrentFrame()));
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
