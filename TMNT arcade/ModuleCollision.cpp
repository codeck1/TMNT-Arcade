#include "Globals.h"
#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"

using namespace std;

ModuleCollision::ModuleCollision()
{
	matrix[COLLIDER_WALL][COLLIDER_WALL] = false;
	matrix[COLLIDER_WALL][COLLIDER_PLAYER_BODY] = false;
	matrix[COLLIDER_WALL][COLLIDER_ENEMY_BODY] = false;
	matrix[COLLIDER_WALL][COLLIDER_ENEMY_WEAPON] = false;
	matrix[COLLIDER_WALL][COLLIDER_PLAYER_FEET] = true;
	matrix[COLLIDER_WALL][COLLIDER_PLAYER_WEAPON] = false;
	matrix[COLLIDER_WALL][COLLIDER_PLAYER_JUMP] = false;
	matrix[COLLIDER_WALL][COLLIDER_ENEMY_SHOT] = true;
	matrix[COLLIDER_WALL][COLLIDER_BORDER] = false;
	matrix[COLLIDER_WALL][COLLIDER_ENEMY_FEET] = true;

	matrix[COLLIDER_BORDER][COLLIDER_BORDER] = false;
	matrix[COLLIDER_BORDER][COLLIDER_PLAYER_BODY] = false;
	matrix[COLLIDER_BORDER][COLLIDER_ENEMY_BODY] = false;
	matrix[COLLIDER_BORDER][COLLIDER_ENEMY_WEAPON] = false;
	matrix[COLLIDER_BORDER][COLLIDER_PLAYER_FEET] = true;
	matrix[COLLIDER_BORDER][COLLIDER_PLAYER_WEAPON] = false;
	matrix[COLLIDER_BORDER][COLLIDER_PLAYER_JUMP] = true;
	matrix[COLLIDER_BORDER][COLLIDER_ENEMY_SHOT] = true;
	matrix[COLLIDER_BORDER][COLLIDER_WALL] = false;
	matrix[COLLIDER_BORDER][COLLIDER_ENEMY_FEET] = false;


	matrix[COLLIDER_PLAYER_BODY][COLLIDER_WALL] = false;
	matrix[COLLIDER_PLAYER_BODY][COLLIDER_PLAYER_BODY] = false;
	matrix[COLLIDER_PLAYER_BODY][COLLIDER_ENEMY_BODY] = true;
	matrix[COLLIDER_PLAYER_BODY][COLLIDER_ENEMY_WEAPON] = true;
	matrix[COLLIDER_PLAYER_BODY][COLLIDER_PLAYER_FEET] = false;
	matrix[COLLIDER_PLAYER_BODY][COLLIDER_PLAYER_WEAPON] = false;
	matrix[COLLIDER_PLAYER_BODY][COLLIDER_PLAYER_JUMP] = false;
	matrix[COLLIDER_PLAYER_BODY][COLLIDER_ENEMY_SHOT] = true;
	matrix[COLLIDER_PLAYER_BODY][COLLIDER_BORDER] = true;
	matrix[COLLIDER_PLAYER_BODY][COLLIDER_ENEMY_FEET] = false;


	matrix[COLLIDER_ENEMY_BODY][COLLIDER_WALL] = false;
	matrix[COLLIDER_ENEMY_BODY][COLLIDER_PLAYER_BODY] = true;
	matrix[COLLIDER_ENEMY_BODY][COLLIDER_ENEMY_BODY] = false;
	matrix[COLLIDER_ENEMY_BODY][COLLIDER_ENEMY_WEAPON] = false;
	matrix[COLLIDER_ENEMY_BODY][COLLIDER_PLAYER_FEET] = true;
	matrix[COLLIDER_ENEMY_BODY][COLLIDER_PLAYER_WEAPON] = true;
	matrix[COLLIDER_ENEMY_BODY][COLLIDER_PLAYER_JUMP] = true;
	matrix[COLLIDER_ENEMY_BODY][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_ENEMY_BODY][COLLIDER_BORDER] = false;
	matrix[COLLIDER_ENEMY_BODY][COLLIDER_ENEMY_FEET] = false;


	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_WALL] = true;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_PLAYER_BODY] = true;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_ENEMY_BODY] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_ENEMY_WEAPON] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_PLAYER_FEET] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_PLAYER_WEAPON] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_PLAYER_JUMP] = true;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_BORDER] = true;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_ENEMY_FEET] = false;

	matrix[COLLIDER_ENEMY_WEAPON][COLLIDER_WALL] = false;
	matrix[COLLIDER_ENEMY_WEAPON][COLLIDER_PLAYER_BODY] = true;
	matrix[COLLIDER_ENEMY_WEAPON][COLLIDER_ENEMY_BODY] = false;
	matrix[COLLIDER_ENEMY_WEAPON][COLLIDER_ENEMY_WEAPON] = false;
	matrix[COLLIDER_ENEMY_WEAPON][COLLIDER_PLAYER_FEET] = true;
	matrix[COLLIDER_ENEMY_WEAPON][COLLIDER_PLAYER_WEAPON] = false;
	matrix[COLLIDER_ENEMY_WEAPON][COLLIDER_PLAYER_JUMP] = true;
	matrix[COLLIDER_ENEMY_WEAPON][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_ENEMY_WEAPON][COLLIDER_BORDER] = false;
	matrix[COLLIDER_ENEMY_WEAPON][COLLIDER_ENEMY_FEET] = false;


	matrix[COLLIDER_PLAYER_FEET][COLLIDER_WALL] = true;
	matrix[COLLIDER_PLAYER_FEET][COLLIDER_PLAYER_BODY] = false;
	matrix[COLLIDER_PLAYER_FEET][COLLIDER_ENEMY_BODY] = true;
	matrix[COLLIDER_PLAYER_FEET][COLLIDER_ENEMY_WEAPON] = true;
	matrix[COLLIDER_PLAYER_FEET][COLLIDER_PLAYER_FEET] = true;
	matrix[COLLIDER_PLAYER_FEET][COLLIDER_PLAYER_WEAPON] = false;
	matrix[COLLIDER_PLAYER_FEET][COLLIDER_PLAYER_JUMP] = false;
	matrix[COLLIDER_PLAYER_FEET][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_PLAYER_FEET][COLLIDER_BORDER] = false;
	matrix[COLLIDER_PLAYER_FEET][COLLIDER_ENEMY_FEET] = false;

	matrix[COLLIDER_PLAYER_WEAPON][COLLIDER_WALL] = false;
	matrix[COLLIDER_PLAYER_WEAPON][COLLIDER_PLAYER_BODY] = false;
	matrix[COLLIDER_PLAYER_WEAPON][COLLIDER_ENEMY_BODY] = true;
	matrix[COLLIDER_PLAYER_WEAPON][COLLIDER_ENEMY_WEAPON] = false;
	matrix[COLLIDER_PLAYER_WEAPON][COLLIDER_PLAYER_FEET] = false;
	matrix[COLLIDER_PLAYER_WEAPON][COLLIDER_PLAYER_WEAPON] = false;
	matrix[COLLIDER_PLAYER_WEAPON][COLLIDER_PLAYER_JUMP] = false;
	matrix[COLLIDER_PLAYER_WEAPON][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_PLAYER_WEAPON][COLLIDER_BORDER] = false;
	matrix[COLLIDER_PLAYER_WEAPON][COLLIDER_ENEMY_FEET] = false;


	matrix[COLLIDER_PLAYER_JUMP][COLLIDER_WALL] = false;
	matrix[COLLIDER_PLAYER_JUMP][COLLIDER_PLAYER_BODY] = false;
	matrix[COLLIDER_PLAYER_JUMP][COLLIDER_ENEMY_BODY] = true;
	matrix[COLLIDER_PLAYER_JUMP][COLLIDER_ENEMY_WEAPON] = true;
	matrix[COLLIDER_PLAYER_JUMP][COLLIDER_PLAYER_FEET] = false;
	matrix[COLLIDER_PLAYER_JUMP][COLLIDER_PLAYER_WEAPON] = false;
	matrix[COLLIDER_PLAYER_JUMP][COLLIDER_PLAYER_JUMP] = false;
	matrix[COLLIDER_PLAYER_JUMP][COLLIDER_ENEMY_SHOT] = true;
	matrix[COLLIDER_PLAYER_JUMP][COLLIDER_BORDER] = true;
	matrix[COLLIDER_PLAYER_JUMP][COLLIDER_ENEMY_FEET] = false;


	matrix[COLLIDER_ENEMY_FEET][COLLIDER_WALL] = true;
	matrix[COLLIDER_ENEMY_FEET][COLLIDER_PLAYER_BODY] = false;
	matrix[COLLIDER_ENEMY_FEET][COLLIDER_ENEMY_BODY] = false;
	matrix[COLLIDER_ENEMY_FEET][COLLIDER_ENEMY_WEAPON] = false;
	matrix[COLLIDER_ENEMY_FEET][COLLIDER_PLAYER_FEET] = false;
	matrix[COLLIDER_ENEMY_FEET][COLLIDER_PLAYER_WEAPON] = false;
	matrix[COLLIDER_ENEMY_FEET][COLLIDER_PLAYER_JUMP] = false;
	matrix[COLLIDER_ENEMY_FEET][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_ENEMY_FEET][COLLIDER_BORDER] = false;
	matrix[COLLIDER_ENEMY_FEET][COLLIDER_ENEMY_FEET] = false;

}

// Destructor
ModuleCollision::~ModuleCollision()
{}

update_status ModuleCollision::PreUpdate()
{
	// Remove all colliders scheduled for deletion
	for (list<Collider*>::iterator it = colliders.begin(); it != colliders.end();)
	{
		if ((*it)->to_delete == true)
		{
			RELEASE(*it);
			it = colliders.erase(it);
		}
		else
			++it;
	}

	return UPDATE_CONTINUE;
}

update_status ModuleCollision::Update()
{
	
	list<Collider*>::iterator iter;
	for (list<Collider*>::iterator it = colliders.begin(); it != colliders.end(); ++it)
	{
		Collider* previous = *it;
		iter = it;
		for (++iter; iter != colliders.end(); ++iter)
		{
			Collider* current = *iter;
			if (previous->CheckCollision(current->rect) == true)
			{
				if (matrix[previous->type][current->type] && previous->callback)
					previous->callback->OnCollision(previous, current);

				if (matrix[current->type][previous->type] && current->callback)
					current->callback->OnCollision(current, previous);
			}
		}

	}


	if(App->input->GetKey(SDL_SCANCODE_F1) == KEY_DOWN)
		debug = !debug;

	if(debug == true)
		DebugDraw();

	return UPDATE_CONTINUE;
}

void ModuleCollision::DebugDraw()
{
	for (list<Collider*>::iterator it = colliders.begin(); it != colliders.end(); ++it)
	{
		if ((*it)->type == COLLIDER_PLAYER_FEET || (*it)->type == COLLIDER_ENEMY_FEET)
		{
			App->renderer->DrawQuad((*it)->rect, 0, 0, 0, 80);
		}
		else
			if ((*it)->type == COLLIDER_PLAYER_WEAPON || (*it)->type == COLLIDER_ENEMY_WEAPON)
			{
				App->renderer->DrawQuad((*it)->rect, 0, 0, 255, 80);
			}
			else
				if ((*it)->type == COLLIDER_PLAYER_JUMP)
				{
					App->renderer->DrawQuad((*it)->rect, 255, 255, 0, 80);
				}
				else
					if ((*it)->type == COLLIDER_ENEMY_SHOT)
					{
						App->renderer->DrawQuad((*it)->rect, 87, 35, 100, 80);
					}
					else
						App->renderer->DrawQuad((*it)->rect, 255, 0, 0, 80);

	}
		
}

// Called before quitting
bool ModuleCollision::CleanUp()
{
	LOG("Freeing all colliders");

	for (list<Collider*>::iterator it = colliders.begin(); it != colliders.end(); ++it)
		RELEASE(*it);

	colliders.clear();

	return true;
}

Collider* ModuleCollision::AddCollider(const SDL_Rect& rect, COLLIDER_TYPE type, Module* callback)
{
	Collider* ret = new Collider(rect, type, callback);

	colliders.push_back(ret);

	return ret;
}

Collider* ModuleCollision::DeleteCollider(Collider * collider)
{
	if (collider != nullptr)
	{
		colliders.remove(collider);
		RELEASE(collider);
	}
	

	return nullptr;
}

// -----------------------------------------------------

bool Collider::CheckCollision(const SDL_Rect& r) const
{
	return (rect.x < r.x + r.w &&
		rect.x + rect.w > r.x &&
		rect.y < r.y + r.h &&
		rect.h + rect.y > r.y);
}
