#ifndef __ModuleStage1_H__
#define __ModuleStage1_H__

#include "Module.h"

struct SDL_Texture;
struct Collider;

class ModuleStage1 : public Module
{
public:
	ModuleStage1(bool active = true);
	~ModuleStage1();

	bool Start();
	update_status Update();
	bool CleanUp();
	int blockCamera = SCREEN_WIDTH*2;
	bool enemiesClear = true;
	int stageCamera = SCREEN_WIDTH/2;
	Collider* wallLeft;
	Collider* wallRight;
	int wallRightLimit, wallLeftLimit;
public:
	
	SDL_Texture* background = nullptr;
	SDL_Texture* stars = nullptr;
};

#endif // __ModuleStage1_H__