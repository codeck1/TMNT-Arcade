#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleSceneSpace.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleSceneSpace::ModuleSceneSpace(bool active) : Module(active)
{}

ModuleSceneSpace::~ModuleSceneSpace()
{}

// Load assets
bool ModuleSceneSpace::Start()
{
	LOG("Loading space scene");
	
	background = App->textures->Load("rtype/stage.png");

	App->player->Enable();
	App->particles->Enable();
	App->collision->Enable();

	App->audio->PlayMusic("rtype/stage1.ogg", 1.0f);
	
	App->collision->AddCollider({ 0,224,3930, 16 }, COLLIDER_WALL);
	App->collision->AddCollider({ 142, 192, 63, 48 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1376, 0, 560, 15 }, COLLIDER_WALL);
	App->collision->AddCollider({ 1376, 15, 112, 79 }, COLLIDER_WALL);

	return true;
}

// UnLoad assets
bool ModuleSceneSpace::CleanUp()
{
	LOG("Unloading space scene");

 	App->textures->Unload(background);
	App->player->Disable();
	App->collision->Disable();
	App->particles->Disable();
	
	return true;
}

// Update: draw background
update_status ModuleSceneSpace::Update()
{
	if (blockCamera - (App->player->position.x) >=stageCamera && (-App->renderer->camera.x / 3 + SCREEN_WIDTH) - (App->player->position.x) <=(stageCamera))
		{
			App->renderer->camera.x -= 6;
		}
	
	// Draw everything --------------------------------------
	App->renderer->Blit(background, 0, 0, NULL);
	
	return UPDATE_CONTINUE;
}