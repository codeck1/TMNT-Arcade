#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleStage1.h"
#include "ModuleFonts.h"

ModuleFonts::ModuleFonts(bool active)
{
}

ModuleFonts::~ModuleFonts()
{
}

bool ModuleFonts::Start()
{
	LOG("Loading fonts");

	fonts = App->textures->Load("rtype/UI.png");

	return true;
}

update_status ModuleFonts::Update()
{
	if(App->scene_space->started)
		App->renderer->Blit(fonts, -App->renderer->camera.x/3, 0, NULL);
	
	return UPDATE_CONTINUE;
}

bool ModuleFonts::CleanUp()
{
	LOG("Unloading fonts");

	App->textures->Unload(fonts);

	return true;
}

bool ModuleFonts::Life()
{
	for (std::list<int>::iterator it = lifeRest.begin(); it != lifeRest.end();)
	{

	}
	return true;
}

