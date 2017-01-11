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
	life = App->textures->Load("rtype/life.png");
	lifeRest = 8;
	lives = 3;
	return true;
}

update_status ModuleFonts::Update()
{

	if (App->scene_space->IsEnabled())
	{
		App->renderer->Blit(fonts, -App->renderer->camera.x / 3, 0, NULL);
		Life();
	}
		
	
	return UPDATE_CONTINUE;
}

bool ModuleFonts::CleanUp()
{
	LOG("Unloading fonts");

	App->textures->Unload(fonts);

	return true;
}

void ModuleFonts::Life()
{
	if (lives != 0)
	{
		if (lifeRest == 0)
		{
			lives -= 1;
			lifeRest = 8;
		}
		SDL_Rect section = { 0,0,lifeRest * 5,11 };
		App->renderer->Blit(life, -App->renderer->camera.x/SCREEN_SIZE + 220, 16, &section);
	}
	
	return;
}

