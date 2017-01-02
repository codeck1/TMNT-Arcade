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
	
	wallLeftLimit = 0;
	wallRightLimit = SCREEN_WIDTH;
	App->collision->AddCollider({ 0,0,SCREEN_WIDTH*SCREEN_SIZE, 127 }, COLLIDER_WALL, this);
	App->collision->AddCollider({ 0,SCREEN_HEIGHT,SCREEN_WIDTH*SCREEN_SIZE, 100 }, COLLIDER_WALL, this);
	wallLeft = App->collision->AddCollider({ wallLeftLimit,0,2,SCREEN_HEIGHT }, COLLIDER_WALL, this);
	wallRight = App->collision->AddCollider({ wallRightLimit,0,2,SCREEN_HEIGHT }, COLLIDER_WALL, this);
	App->particles->AddParticle(App->particles->fire, 0, 151);
	App->particles->AddParticle(App->particles->fire, 301, 151);
	App->particles->AddParticle(App->particles->fire, 602, 151);
	App->particles->AddParticle(App->particles->fire2, 0, 164);
	App->particles->AddParticle(App->particles->fire2, 301, 164);
	App->particles->AddParticle(App->particles->fire2, 602, 164);






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
			wallLeftLimit += 2;
			wallRightLimit += 2;
			wallLeft->SetPos(wallLeftLimit, 0);
			wallRight->SetPos(wallRightLimit, 0);
		}
	
	// Draw everything --------------------------------------
	App->renderer->Blit(background, 0, 0, NULL);
	
	return UPDATE_CONTINUE;
}