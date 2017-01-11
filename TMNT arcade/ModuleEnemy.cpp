#include "ModuleEnemy.h"
#include "Application.h"
#include "ModuleAudio.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePLayer.h"
#include "ModuleCollision.h"

ModuleEnemy::ModuleEnemy()
{

	//Animaciones de cada enemigo y sonidos. Prototipos

	//ENEMY 1

	//going left
	enemy1.left.frames.push_back({ 172, 80, 52, 64 });
	enemy1.left.frames.push_back({ 96, 80, 52, 64 });
	enemy1.left.frames.push_back({ 19, 80, 52, 64 });
	enemy1.left.frames.push_back({ 337, 0, 52, 64 });
	enemy1.left.frames.push_back({ 253, 0, 52, 64 });
	enemy1.left.frames.push_back({ 176, 0, 52, 64 });
	enemy1.left.frames.push_back({ 98, 0, 52, 64 });
	enemy1.left.frames.push_back({ 17, 0, 52, 64 });
	enemy1.left.pivotY = -5;
	enemy1.left.loop = true;
	enemy1.left.speed = 0.2f;

	//going right
	enemy1.right.frames.push_back({ 589, 80, 52, 64 });
	enemy1.right.frames.push_back({ 671, 80, 52, 64 });
	enemy1.right.frames.push_back({ 757, 80, 52, 64 });
	enemy1.right.frames.push_back({ 433, 0, 52, 64 });
	enemy1.right.frames.push_back({ 508, 0, 52, 64 });
	enemy1.right.frames.push_back({ 593, 0, 52, 64 });
	enemy1.right.frames.push_back({ 674, 0, 52, 64 });
	enemy1.right.frames.push_back({ 751, 0, 52, 64 });
	enemy1.right.pivotY = -5;
	enemy1.right.loop = true;
	enemy1.right.speed = 0.2f;

	//going upLeft
	enemy1.upLeft.frames.push_back({ 14, 240, 52, 64 });
	enemy1.upLeft.frames.push_back({ 333, 160, 52, 64 });
	enemy1.upLeft.frames.push_back({ 252, 160, 52, 64 });
	enemy1.upLeft.frames.push_back({ 176, 160, 52, 64 });
	enemy1.upLeft.frames.push_back({ 96, 160, 52, 64 });
	enemy1.upLeft.frames.push_back({ 17, 160, 52, 64 });
	enemy1.upLeft.frames.push_back({ 336, 81, 52, 64 });
	enemy1.upLeft.frames.push_back({ 256, 81, 52, 64 });
	enemy1.upLeft.pivotY =- 5;
	enemy1.upLeft.loop = true;
	enemy1.upLeft.speed = 0.2f;

	//going up
	enemy1.up.frames.push_back({ 749, 240, 52, 64 });
	enemy1.up.frames.push_back({ 431, 160, 52, 64 });
	enemy1.up.frames.push_back({ 509, 160, 52, 64 });
	enemy1.up.frames.push_back({ 595, 160, 52, 64 });
	enemy1.up.frames.push_back({ 671, 160, 52, 64 });
	enemy1.up.frames.push_back({ 753, 160, 52, 64 });
	enemy1.up.frames.push_back({ 433, 81, 52, 64 });
	enemy1.up.frames.push_back({ 512, 81, 52, 64 });
	enemy1.up.pivotY = -5;
	enemy1.up.loop = true;
	enemy1.up.speed = 0.2f;

	//attack1
	enemy1.attack1.frames.push_back({ 577, 643, 60, 64 });
	enemy1.attack1.frames.push_back({ 668, 643, 60, 64 });
	enemy1.attack1.frames.push_back({ 753, 643, 60, 64 });
	enemy1.attack1.pivotY = -10;
	enemy1.attack1.loop = false;
	enemy1.attack1.speed = 0.12f;

	//attack1Left
	enemy1.attack1Left.frames.push_back({ 161, 643, 60, 64 });
	enemy1.attack1Left.frames.push_back({ 91, 643, 60, 64 });
	enemy1.attack1Left.frames.push_back({ 16, 643, 60, 64 });
	enemy1.attack1Left.pivotY = -10;
	enemy1.attack1Left.loop = false;
	enemy1.attack1Left.speed = 0.12f;

	//attack2
	enemy1.attack2.frames.push_back({ 417, 478, 60, 64 });
	enemy1.attack2.frames.push_back({ 496, 478, 60, 64 });
	enemy1.attack2.frames.push_back({ 571, 478, 60, 64 });
	enemy1.attack2.frames.push_back({ 571, 478, 60, 64 });
	enemy1.attack2.frames.push_back({ 571, 478, 60, 64 });
	enemy1.attack2.frames.push_back({ 571, 478, 60, 64 });
	enemy1.attack2.pivotY = -10;
	enemy1.attack2.loop = false;
	enemy1.attack2.speed = 0.15f;

	//attack2Left
	enemy1.attack2Left.frames.push_back({ 326, 478, 60, 64 });
	enemy1.attack2Left.frames.push_back({ 242, 478, 60, 64 });
	enemy1.attack2Left.frames.push_back({ 160, 478, 60, 64 });
	enemy1.attack2Left.frames.push_back({ 160, 478, 60, 64 });
	enemy1.attack2Left.frames.push_back({ 160, 478, 60, 64 });
	enemy1.attack2Left.frames.push_back({ 160, 478, 60, 64 });
	enemy1.attack2Left.pivotY = -10;
	enemy1.attack2Left.loop = false;
	enemy1.attack2Left.speed = 0.15f;

	//reciveDamage
	enemy1.reciveDamage.frames.push_back({ 250, 800, 60, 64 });
	enemy1.reciveDamage.frames.push_back({ 167, 800, 60, 64 });
	enemy1.reciveDamage.frames.push_back({ 81, 800, 60, 64 });
	enemy1.reciveDamage.frames.push_back({ 9, 800, 60, 64 });
	enemy1.reciveDamage.pivotY = -10;
	enemy1.reciveDamage.loop = false;
	enemy1.reciveDamage.speed = 0.2f;

	//reciveDamageLeft
	enemy1.reciveDamageLeft.frames.push_back({ 508, 800, 60, 64 });
	enemy1.reciveDamageLeft.frames.push_back({ 584, 800, 60, 64 });
	enemy1.reciveDamageLeft.frames.push_back({ 658, 800, 60, 64 });
	enemy1.reciveDamageLeft.frames.push_back({ 746, 800, 60, 64 });
	enemy1.reciveDamageLeft.pivotY = -10;
	enemy1.reciveDamageLeft.loop = false;
	enemy1.reciveDamageLeft.speed = 0.2f;

	//reciveDamage2
	enemy1.reciveDamage2.frames.push_back({ 16, 1940, 60, 64 });
	enemy1.reciveDamage2.frames.push_back({ 99, 1940, 60, 64 });
	enemy1.reciveDamage2.frames.push_back({ 99, 1940, 60, 64 });
	enemy1.reciveDamage2.frames.push_back({ 99, 1940, 60, 64 });
	enemy1.reciveDamage2.frames.push_back({ 99, 1940, 60, 64 });
	enemy1.reciveDamage2.frames.push_back({ 253, 1855, 60, 64 });
	enemy1.reciveDamage2.frames.push_back({ 329, 1855, 60, 64 });
	enemy1.reciveDamage2.pivotY = -20;
	enemy1.reciveDamage2.loop = false;
	enemy1.reciveDamage2.speed = 0.2f;

	//reciveDamage2Left
	enemy1.reciveDamage2Left.frames.push_back({ 738, 1940, 60, 64 });
	enemy1.reciveDamage2Left.frames.push_back({ 663, 1940, 60, 64 });
	enemy1.reciveDamage2Left.frames.push_back({ 663, 1940, 60, 64 });
	enemy1.reciveDamage2Left.frames.push_back({ 663, 1940, 60, 64 });
	enemy1.reciveDamage2Left.frames.push_back({ 663, 1940, 60, 64 });
	enemy1.reciveDamage2Left.frames.push_back({ 498, 1855, 60, 64 });
	enemy1.reciveDamage2Left.frames.push_back({ 414, 1855, 60, 64 });
	enemy1.reciveDamage2Left.pivotY = -20;
	enemy1.reciveDamage2Left.loop = false;
	enemy1.reciveDamage2Left.speed = 0.2f;

	//reciveDamage3
	enemy1.reciveDamage3.frames.push_back({ 332, 1940, 60, 64 });
	enemy1.reciveDamage3.frames.push_back({ 251, 1940, 60, 64 });
	enemy1.reciveDamage3.frames.push_back({ 171, 1940, 60, 64 });
	enemy1.reciveDamage3.frames.push_back({ 17, 2016, 60, 64 });
	enemy1.reciveDamage3.frames.push_back({ 91, 2016, 60, 64 });
	enemy1.reciveDamage3.frames.push_back({ 159, 1998, 60, 64 });
	enemy1.reciveDamage3.pivotY = -20;
	enemy1.reciveDamage3.loop = false;
	enemy1.reciveDamage3.speed = 0.2f;

	//reciveDamage3Left
	enemy1.reciveDamage3Left.frames.push_back({ 418, 1940, 60, 64 });
	enemy1.reciveDamage3Left.frames.push_back({ 498, 1940, 60, 64 });
	enemy1.reciveDamage3Left.frames.push_back({ 576, 1940, 60, 64 });
	enemy1.reciveDamage3Left.frames.push_back({ 565, 2016, 60, 64 });
	enemy1.reciveDamage3Left.frames.push_back({ 657, 2016, 60, 64 });
	enemy1.reciveDamage3Left.frames.push_back({ 740, 1998, 60, 64 });
	enemy1.reciveDamage3Left.pivotY = -20;
	enemy1.reciveDamage3Left.loop = false;
	enemy1.reciveDamage3Left.speed = 0.2f;


	//ENEMY 2

	//going left
	enemy2.left.frames.push_back({ 172, 80, 52, 64 });
	enemy2.left.frames.push_back({ 96, 80, 52, 64 });
	enemy2.left.frames.push_back({ 19, 80, 52, 64 });
	enemy2.left.frames.push_back({ 337, 0, 52, 64 });
	enemy2.left.frames.push_back({ 253, 0, 52, 64 });
	enemy2.left.frames.push_back({ 176, 0, 52, 64 });
	enemy2.left.frames.push_back({ 98, 0, 52, 64 });
	enemy2.left.frames.push_back({ 17, 0, 52, 64 });
	enemy2.left.pivotY = -5;
	enemy2.left.loop = true;
	enemy2.left.speed = 0.2f;

	//going right
	enemy2.right.frames.push_back({ 589, 80, 52, 64 });
	enemy2.right.frames.push_back({ 671, 80, 52, 64 });
	enemy2.right.frames.push_back({ 757, 80, 52, 64 });
	enemy2.right.frames.push_back({ 433, 0, 52, 64 });
	enemy2.right.frames.push_back({ 508, 0, 52, 64 });
	enemy2.right.frames.push_back({ 593, 0, 52, 64 });
	enemy2.right.frames.push_back({ 674, 0, 52, 64 });
	enemy2.right.frames.push_back({ 751, 0, 52, 64 });
	enemy2.right.pivotY = -5;
	enemy2.right.loop = true;
	enemy2.right.speed = 0.2f;

	//going upLeft
	enemy2.upLeft.frames.push_back({ 14, 240, 52, 64 });
	enemy2.upLeft.frames.push_back({ 333, 160, 52, 64 });
	enemy2.upLeft.frames.push_back({ 252, 160, 52, 64 });
	enemy2.upLeft.frames.push_back({ 176, 160, 52, 64 });
	enemy2.upLeft.frames.push_back({ 96, 160, 52, 64 });
	enemy2.upLeft.frames.push_back({ 17, 160, 52, 64 });
	enemy2.upLeft.frames.push_back({ 336, 81, 52, 64 });
	enemy2.upLeft.frames.push_back({ 256, 81, 52, 64 });
	enemy2.upLeft.pivotY = -5;
	enemy2.upLeft.loop = true;
	enemy2.upLeft.speed = 0.2f;

	//going up
	enemy2.up.frames.push_back({ 749, 240, 52, 64 });
	enemy2.up.frames.push_back({ 431, 160, 52, 64 });
	enemy2.up.frames.push_back({ 509, 160, 52, 64 });
	enemy2.up.frames.push_back({ 595, 160, 52, 64 });
	enemy2.up.frames.push_back({ 671, 160, 52, 64 });
	enemy2.up.frames.push_back({ 753, 160, 52, 64 });
	enemy2.up.frames.push_back({ 433, 81, 52, 64 });
	enemy2.up.frames.push_back({ 512, 81, 52, 64 });
	enemy2.up.pivotY = -5;
	enemy2.up.loop = true;
	enemy2.up.speed = 0.2f;

	//attack1
	enemy2.attack1.frames.push_back({ 577, 643, 60, 64 });
	enemy2.attack1.frames.push_back({ 668, 643, 60, 64 });
	enemy2.attack1.frames.push_back({ 753, 643, 60, 64 });
	enemy2.attack1.pivotY = -10;
	enemy2.attack1.loop = false;
	enemy2.attack1.speed = 0.07f;

	//attack1Left
	enemy2.attack1Left.frames.push_back({ 161, 643, 60, 64 });
	enemy2.attack1Left.frames.push_back({ 91, 643, 60, 64 });
	enemy2.attack1Left.frames.push_back({ 16, 643, 60, 64 });
	enemy2.attack1Left.pivotY = -10;
	enemy2.attack1Left.loop = false;
	enemy2.attack1Left.speed = 0.07f;

	//attack2Left
	enemy2.attack2Left.frames.push_back({ 251, 1749, 60, 64 });
	enemy2.attack2Left.frames.push_back({ 166, 1749, 60, 64 });
	enemy2.attack2Left.frames.push_back({ 16, 643, 60, 64 });
	enemy2.attack2Left.frames.push_back({ 16, 643, 60, 64 });
	enemy2.attack2Left.frames.push_back({ 16, 643, 60, 64 });
	enemy2.attack2Left.frames.push_back({ 16, 643, 60, 64 });
	enemy2.attack2Left.pivotY = -10;
	enemy2.attack2Left.loop = false;
	enemy2.attack2Left.speed = 0.1f;

	//attack2
	enemy2.attack2.frames.push_back({ 317, 1749, 60, 64 });
	enemy2.attack2.frames.push_back({ 397, 1749, 60, 64 });
	enemy2.attack2.frames.push_back({ 753, 643, 60, 64 });
	enemy2.attack2.frames.push_back({ 753, 643, 60, 64 });
	enemy2.attack2.frames.push_back({ 753, 643, 60, 64 });
	enemy2.attack2.frames.push_back({ 753, 643, 60, 64 });
	enemy2.attack2.pivotY = -10;
	enemy2.attack2.loop = false;
	enemy2.attack2.speed = 0.1f;

	//reciveDamage
	enemy2.reciveDamage.frames.push_back({ 250, 800, 60, 64 });
	enemy2.reciveDamage.frames.push_back({ 167, 800, 60, 64 });
	enemy2.reciveDamage.frames.push_back({ 81, 800, 60, 64 });
	enemy2.reciveDamage.frames.push_back({ 9, 800, 60, 64 });
	enemy2.reciveDamage.pivotY = -10;
	enemy2.reciveDamage.loop = false;
	enemy2.reciveDamage.speed = 0.2f;

	//reciveDamageLeft
	enemy2.reciveDamageLeft.frames.push_back({ 508, 800, 60, 64 });
	enemy2.reciveDamageLeft.frames.push_back({ 584, 800, 60, 64 });
	enemy2.reciveDamageLeft.frames.push_back({ 658, 800, 60, 64 });
	enemy2.reciveDamageLeft.frames.push_back({ 746, 800, 60, 64 });
	enemy2.reciveDamageLeft.pivotY = -10;
	enemy2.reciveDamageLeft.loop = false;
	enemy2.reciveDamageLeft.speed = 0.2f;

	//reciveDamage2
	enemy2.reciveDamage2.frames.push_back({ 16, 1940, 60, 64 });
	enemy2.reciveDamage2.frames.push_back({ 99, 1940, 60, 64 });
	enemy2.reciveDamage2.frames.push_back({ 99, 1940, 60, 64 });
	enemy2.reciveDamage2.frames.push_back({ 99, 1940, 60, 64 });
	enemy2.reciveDamage2.frames.push_back({ 99, 1940, 60, 64 });
	enemy2.reciveDamage2.frames.push_back({ 253, 1855, 60, 64 });
	enemy2.reciveDamage2.frames.push_back({ 329, 1855, 60, 64 });
	enemy2.reciveDamage2.pivotY = -20;
	enemy2.reciveDamage2.loop = false;
	enemy2.reciveDamage2.speed = 0.2f;

	//reciveDamage2Left
	enemy2.reciveDamage2Left.frames.push_back({ 738, 1940, 60, 64 });
	enemy2.reciveDamage2Left.frames.push_back({ 663, 1940, 60, 64 });
	enemy2.reciveDamage2Left.frames.push_back({ 663, 1940, 60, 64 });
	enemy2.reciveDamage2Left.frames.push_back({ 663, 1940, 60, 64 });
	enemy2.reciveDamage2Left.frames.push_back({ 663, 1940, 60, 64 });
	enemy2.reciveDamage2Left.frames.push_back({ 498, 1855, 60, 64 });
	enemy2.reciveDamage2Left.frames.push_back({ 414, 1855, 60, 64 });
	enemy2.reciveDamage2Left.pivotY = -20;
	enemy2.reciveDamage2Left.loop = false;
	enemy2.reciveDamage2Left.speed = 0.2f;

	//reciveDamage3
	enemy2.reciveDamage3.frames.push_back({ 332, 1940, 60, 64 });
	enemy2.reciveDamage3.frames.push_back({ 251, 1940, 60, 64 });
	enemy2.reciveDamage3.frames.push_back({ 171, 1940, 60, 64 });
	enemy2.reciveDamage3.frames.push_back({ 17, 2016, 60, 64 });
	enemy2.reciveDamage3.frames.push_back({ 91, 2016, 60, 64 });
	enemy2.reciveDamage3.frames.push_back({ 159, 1998, 60, 64 });
	enemy2.reciveDamage3.pivotY = -20;
	enemy2.reciveDamage3.loop = false;
	enemy2.reciveDamage3.speed = 0.2f;

	//reciveDamage3Left
	enemy2.reciveDamage3Left.frames.push_back({ 418, 1940, 60, 64 });
	enemy2.reciveDamage3Left.frames.push_back({ 498, 1940, 60, 64 });
	enemy2.reciveDamage3Left.frames.push_back({ 576, 1940, 60, 64 });
	enemy2.reciveDamage3Left.frames.push_back({ 565, 2016, 60, 64 });
	enemy2.reciveDamage3Left.frames.push_back({ 657, 2016, 60, 64 });
	enemy2.reciveDamage3Left.frames.push_back({ 740, 1998, 60, 64 });
	enemy2.reciveDamage3Left.pivotY = -20;
	enemy2.reciveDamage3Left.loop = false;
	enemy2.reciveDamage3Left.speed = 0.2f;

}

ModuleEnemy::~ModuleEnemy()
{
}

bool ModuleEnemy::Start()
{
	LOG("Loading enemies");
	enemy1.graphics = App->textures->Load("rtype/enemy1.png");
	enemy2.graphics = App->textures->Load("rtype/enemy2.png");
	// Explosion particle

	return true;
}

update_status ModuleEnemy::Update()
{
	RadixSortList(active, active.size(), 100);
	for (list<Enemy*>::iterator it = active.begin(); it != active.end();)
	{
		Enemy* e = *it;

		if (e->toDelete == true)
		{
			e->colliderBody = App->collision->DeleteCollider(e->colliderBody);
			e->colliderFeet = App->collision->DeleteCollider(e->colliderFeet);
			active.remove(e);
			delete e;
			if (active.empty())
			{
				enemiesClear = true;
			}
			break;
		}
		else
		{
			if (e->Update() == false)
			{
				RELEASE(*it);
				it = active.erase(it);
			}
			else
			{
				e->colliderFeet->SetPos(e->position.x + 10, e->position.y + 50);
				e->colliderBody->SetPos(e->position.x + 10, e->position.y + 5);
				App->renderer->Blit(e->graphics, e->position.x, e->position.y - e->current_animation->pivotY, &(e->current_animation->GetCurrentFrame()));
				++it;
			}
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
	e->colliderFeet = App->collision->AddCollider({ position.x, position.y + 50, 32, 14 }, COLLIDER_ENEMY_FEET, this);
	e->colliderBody = App->collision->AddCollider({ position.x, position.y + 10, 32, 45 }, COLLIDER_ENEMY_BODY, this);
	active.push_back(e);
}

void ModuleEnemy::RadixSortList(list<Enemy*>& v, int length, int numMax)
{
	vector <Enemy*> v2;
	vector <vector<Enemy*>> c(10);
	int d;

	for (int i = 0; i <= log10(numMax); ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			v2.clear();
			c[j].clear();
		}

		for (auto& k : v)
		{
			d = Digit(i, k->position.y);
			c[d].push_back(k);
		}

		for (int l = 0; l < c.size(); ++l)
			for (int m = 0; m < c[l].size(); ++m)
				v2.push_back(c[l][m]);

		v.clear();

		for (auto& l : v2)
			v.push_back(l);
	}
}

int ModuleEnemy::Digit(int index, int num)
{
	int aux = 1;
	for (int i = index; i > 0; --i)
		aux *= 10;

	num = num / aux;
	num = num % 10;

	return num;
}

void ModuleEnemy::OnCollision(Collider* c1, Collider* c2)
{
	

	for (list<Enemy*>::iterator it = active.begin(); it != active.end();)
	{
		Enemy* aux = *it;
		if (App->player->jumped)
		{
			if (c2->type == COLLIDER_PLAYER_WEAPON && c1 == aux->colliderBody && aux->currentState != TAKEDDOWN)
			{
				aux->currentState = ENEMYBEINGATTACKED;
			}
		}
		else
		{
			if (c2->type == COLLIDER_PLAYER_WEAPON && c1 == aux->colliderBody && abs(App->player->position.y - aux->position.y)<15 && aux->currentState != TAKEDDOWN)
			{
				aux->currentState = ENEMYBEINGATTACKED;
			}
		}
		//left
		if ((c1->rect.x < c2->rect.x + c2->rect.w) && ((c2->rect.x + c2->rect.w) - c1->rect.x) < c1->rect.w && ((c2->rect.y + c2->rect.h) - c1->rect.y) >4 && (c2->rect.y - (c1->rect.h + c1->rect.y)) <-4 && (c2->type == COLLIDER_WALL))
		{
			aux->position.x += ((c2->rect.x + c2->rect.w) - c1->rect.x);
		}
		else
		{
			//right
			if (c1->rect.x + c1->rect.w > c2->rect.x && ((c2->rect.y + c2->rect.h) - c1->rect.y) >4 && (c2->rect.y - (c1->rect.h + c1->rect.y)) <-4 && (c2->type == COLLIDER_WALL ))
			{
				aux->position.x += (c2->rect.x - (c1->rect.x + c1->rect.w));
			}
			else
			{
				//down
				if ((c1->rect.y < c2->rect.y + c2->rect.h) && ((c1->rect.h + c1->rect.y) - c2->rect.y) > c1->rect.h && (c2->type == COLLIDER_WALL))
				{
					aux->position.y += ((c2->rect.y + c2->rect.h) - c1->rect.y);
				}
				else
				{
					//up
					if (c1->rect.h + c1->rect.y > c2->rect.y && (c2->type == COLLIDER_WALL))
					{
						aux->position.y += (c2->rect.y - (c1->rect.h + c1->rect.y));
					}
				}
			}
		}
		++it;
	}
}
