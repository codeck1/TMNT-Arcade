#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleStage1.h"
#include "ModuleEnemy.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleStage1::ModuleStage1(bool active) : Module(active)
{}

ModuleStage1::~ModuleStage1()
{}

// Load assets
bool ModuleStage1::Start()
{
	LOG("Loading space scene");
	
	background = App->textures->Load("rtype/stage.png");

	App->player->Enable();
	App->particles->Enable();
	App->collision->Enable();
	App->audio->PlayMusic("rtype/stage1.wav", 1.0f);
	positionEnemy.x = -20;
	positionEnemy.y = 100;
	wallLeftLimit = 0;
	wallRightLimit = SCREEN_WIDTH;
	blockCamera = 450;
	App->collision->AddCollider({ 0,0,1350, 127 }, COLLIDER_WALL, this);
	App->collision->AddCollider({ 0,SCREEN_HEIGHT,1350, 100 }, COLLIDER_WALL, this);
	wallLeft = App->collision->AddCollider({ wallLeftLimit,-20,2,SCREEN_HEIGHT*2 }, COLLIDER_BORDER, this);
	wallRight = App->collision->AddCollider({ wallRightLimit,-20,2,SCREEN_HEIGHT*2 }, COLLIDER_BORDER, this);

	App->particles->AddParticle(App->particles->fire, 0, 157, 0);
	App->particles->AddParticle(App->particles->fire, 301, 157, 0);
	App->particles->AddParticle(App->particles->fire, 602, 157, 0);
	App->particles->AddParticle(App->particles->fire, 903, 157, 0);
	App->particles->AddParticle(App->particles->fire, 1204, 157, 0);
	App->particles->AddParticle(App->particles->fire2, 0, 168, 0);
	App->particles->AddParticle(App->particles->fire2, 301, 168, 0);
	App->particles->AddParticle(App->particles->fire2, 602, 168, 0);
	App->particles->AddParticle(App->particles->fire2, 903, 168, 0);
	App->particles->AddParticle(App->particles->fire2, 1204, 168, 0);
	App->particles->AddParticle(App->particles->door, 411, 48, 0);
	App->particles->AddParticle(App->particles->door, 700, 49, 0);
	App->particles->AddParticle(App->particles->door, 828, 49, 0);
	App->particles->AddParticle(App->particles->door2, 949, 50, 0);
	App->particles->AddParticle(App->particles->door2, 1078, 50, 0);

	App->enemy->AddEnemy(App->enemy->enemy1, positionEnemy, TYPE1);
	positionEnemy.x = -50;
	positionEnemy.y = 160;
	App->enemy->AddEnemy(App->enemy->enemy1, positionEnemy, TYPE1);
	positionEnemy.x = 500;
	positionEnemy.y = 100;
	App->enemy->AddEnemy(App->enemy->enemy1, positionEnemy, TYPE1);

	state = 1;

	return true;
}

// UnLoad assets
bool ModuleStage1::CleanUp()
{
	LOG("Unloading space scene");

 	App->textures->Unload(background);
	App->player->Disable();
	App->collision->Disable();
	App->particles->Disable();
	
	return true;
}

// Update: draw background
update_status ModuleStage1::Update()
{
	if (blockCamera - (App->player->position.x) <= stageCamera && App->enemy->enemiesClear)
	{
		switch (state)
		{
		case 1:

			blockCamera = 900;
			state++;
			positionEnemy.x = 1000;
			positionEnemy.y = 150;
			App->enemy->AddEnemy(App->enemy->enemy2, positionEnemy, TYPE2);
			App->enemy->enemiesClear = false;

			break;

		case 2:

			blockCamera = 1350;
			state++;

			positionEnemy.x = 1400;
			positionEnemy.y = 150;
			App->enemy->AddEnemy(App->enemy->enemy2, positionEnemy, TYPE2);
			positionEnemy.x = 400;
			positionEnemy.y = 100;
			App->enemy->AddEnemy(App->enemy->enemy1, positionEnemy, TYPE1);
			
			App->enemy->enemiesClear = false;
			break;

		case 3:
			if (blockCamera == 1350)
			{
				state++;
				positionEnemy.x = 1400;
				positionEnemy.y = 150;
				App->enemy->AddEnemy(App->enemy->enemy2, positionEnemy, TYPE2);
				positionEnemy.x = 600;
				positionEnemy.y = 150;
				App->enemy->AddEnemy(App->enemy->enemy2, positionEnemy, TYPE2);
				end = true;
				App->enemy->enemiesClear = false;
			}
			break;

		case 4:
			state++;
			App->player->currentState = END;
			break;
		}
		
	}


	if (blockCamera - (App->player->position.x) >= stageCamera && (-App->renderer->camera.x/SCREEN_SIZE + SCREEN_WIDTH) - (App->player->position.x) <= (stageCamera))
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