#ifndef __MODULESCENESPACE_H__
#define __MODULESCENESPACE_H__

#include "Module.h"

struct SDL_Texture;
struct Collider;

class ModuleSceneSpace : public Module
{
public:
	ModuleSceneSpace(bool active = true);
	~ModuleSceneSpace();

	bool Start();
	update_status Update();
	bool CleanUp();
	int blockCamera = SCREEN_WIDTH*2;
	bool enemiesClear = true;
	int stageCamera = SCREEN_WIDTH/2;

public:
	
	SDL_Texture* background = nullptr;
	SDL_Texture* stars = nullptr;
};

#endif // __MODULESCENESPACE_H__