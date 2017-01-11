#ifndef __ModuleEnemy_H__
#define __ModuleEnemy_H__

#include "Globals.h"
#include "Module.h"
#include "Animation.h"
#include "Point.h"
#include "ModuleCollision.h"
#include "Enemy.h"


struct SDL_Texture;

class ModuleEnemy : public Module
{
public:
	ModuleEnemy();
	~ModuleEnemy();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider*, Collider*);

	void AddEnemy(const Enemy& enemy, iPoint position, EnemyType type);
	void RadixSortList(std::list<Enemy*>& v, int length, int numMax);
	int Digit(int index, int num);

private:
	std::list<Enemy*> active;

public:

	Enemy enemy1, enemy2, enemy3;
	bool enemiesClear = false;
};


#endif