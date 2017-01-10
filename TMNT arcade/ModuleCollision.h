#ifndef __ModuleCollision_H__
#define __ModuleCollision_H__

#include<list>
#include "Module.h"

// TODO 9: Create a matrix of game specific types of collision for early discard
// Example: lasers should not collide with lasers but should collider with walls
// enemy shots will collide with other enemies ? and against walls ?
enum COLLIDER_TYPE
{
	COLLIDER_NONE = -1,
	COLLIDER_WALL,
	COLLIDER_BORDER,
	COLLIDER_PLAYER_BODY,
	COLLIDER_ENEMY_BODY,
	COLLIDER_ENEMY_WEAPON,
	COLLIDER_ENEMY_SHOT,
	COLLIDER_ENEMY_FEET,
	COLLIDER_PLAYER_FEET,
	COLLIDER_PLAYER_WEAPON,
	COLLIDER_PLAYER_JUMP,

	COLLIDER_MAX
};

struct Collider
{
	SDL_Rect rect = { 0,0,0,0 };
	bool to_delete = false;
	COLLIDER_TYPE type;
	Module* callback;

	Collider(SDL_Rect rectangle, COLLIDER_TYPE type, Module* callback = NULL) : 
		rect(rectangle),
		callback(callback),
		type(type)
	{}

	void SetPos(int x, int y)
	{
		rect.x = x;
		rect.y = y;
	}

	bool CheckCollision(const SDL_Rect& r) const;
};

class ModuleCollision : public Module
{
public:

	ModuleCollision();
	~ModuleCollision();

	update_status PreUpdate();
	update_status Update();

	bool CleanUp();

	Collider* AddCollider(const SDL_Rect& rect, COLLIDER_TYPE type, Module* callback = NULL);
	Collider* DeleteCollider(Collider* collider);
	void DebugDraw();

private:

	std::list<Collider*> colliders;
	bool debug = false;
	bool matrix[COLLIDER_MAX][COLLIDER_MAX];
};

#endif // __ModuleCollision_H__