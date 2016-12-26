#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleFadeToBlack.h"
#include "ModulePlayer.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer::ModulePlayer(bool active) : Module(active)
{
	// idle animation
	idle.frames.push_back({0, 38, 103, 61});
	idle.frames.push_back({ 103, 38, 103, 61 });
	idle.frames.push_back({ 206, 38, 103, 61 });
	idle.frames.push_back({ 309, 38, 103, 61 });
	idle.frames.push_back({ 412, 38, 103, 61 });
	idle.loop = true;
	idle.speed = 0.05f;

	// idleLeft animation
	idleLeft.frames.push_back({ 924, 1339, 103, 61 });
	idleLeft.frames.push_back({ 821, 1339, 103, 61 });
	idleLeft.frames.push_back({ 718, 1339, 103, 61 });
	idleLeft.frames.push_back({ 615, 1339, 103, 61 });
	idleLeft.frames.push_back({ 512, 1339, 103, 61 });
	idleLeft.loop = true;
	idleLeft.speed = 0.05f;

	// move upwards
	up.frames.push_back({718, 638, 103, 75});
	up.frames.push_back({ 821, 638, 103, 75 });
	up.frames.push_back({ 924, 638, 103, 75 });
	up.frames.push_back({ 0, 739, 103, 75 });
	up.frames.push_back({ 103, 739, 103, 75 });
	up.frames.push_back({ 206, 739, 103, 75 });
	up.frames.push_back({ 309, 739, 103, 75 });
	up.frames.push_back({ 412, 739, 103, 75 });
	up.loop = true;
	up.speed = 0.15f;

	// move upwardsLeft
	upLeft.frames.push_back({ 206, 1936, 103, 75 });
	upLeft.frames.push_back({ 103, 1936, 103, 75 });
	upLeft.frames.push_back({ 0, 1936, 103, 75 });
	upLeft.frames.push_back({ 924, 2035, 103, 75 });
	upLeft.frames.push_back({ 821, 2035, 103, 75 });
	upLeft.frames.push_back({ 718, 2035, 103, 75 });
	upLeft.frames.push_back({ 615, 2035, 103, 75 });
	upLeft.frames.push_back({ 512, 2035, 103, 75 });
	upLeft.loop = true;
	upLeft.speed = 0.15f;

	// move right
	right.frames.push_back({927,537,103,75});
	right.frames.push_back({ 0,636,103,75 });
	right.frames.push_back({ 103,636,103,75 });
	right.frames.push_back({ 206,636,103,75 });
	right.frames.push_back({ 309,636,103,75 });
	right.frames.push_back({ 412,636,103,75 });
	right.frames.push_back({ 515,636,103,75 });
	right.frames.push_back({ 618,636,103,75 });
	right.loop = true;
	right.speed = 0.15f;



	// move left
	left.frames.push_back({ 0,1835,103,75 });
	left.frames.push_back({ 927,1935,103,75 });
	left.frames.push_back({ 824,1935,103,75 });
	left.frames.push_back({ 721,1935,103,75 });
	left.frames.push_back({ 618,1935,103,75 });
	left.frames.push_back({ 515,1935,103,75 });
	left.frames.push_back({ 412,1935,103,75 });
	left.frames.push_back({ 309,1935,103,75 });
	left.loop = true;
	left.speed = 0.15f;

}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	graphics = App->textures->Load("rtype/donatello1.png");

	destroyed = false;
	position.x = 150;
	position.y = 120;
	collider = App->collision->AddCollider({ position.x, position.y, 32, 14 }, COLLIDER_PLAYER, this);


	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);

	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	int speed = 2;
	

	if(App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
	{
		position.x -= speed;
		if (current_animation != &left && App->input->GetKey(SDL_SCANCODE_W) != KEY_REPEAT)
		{
			left.Reset();
			current_animation = &left;
			faceRight = false;
		}
		
	}

	if(App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
	{
		position.x += speed;
		if (current_animation != &right && App->input->GetKey(SDL_SCANCODE_W) != KEY_REPEAT)
		{
			right.Reset();
			current_animation = &right;
			faceRight = true;
		}
	}

	if(App->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT)
	{
		position.y += speed;
		if(current_animation != &right && faceRight == true)
		{
			right.Reset();
			current_animation = &right;
		}
		else
		{
			if (current_animation != &left && faceRight == false)
			{
				left.Reset();
				current_animation = &left;
			}
		}
	}

	if(App->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT)
	{
		position.y -= speed;
		if(current_animation != &up && faceRight == true)
		{
			up.Reset();
			current_animation = &up;
		}
		else
		{
			if (current_animation != &upLeft && faceRight == false)
			{
				upLeft.Reset();
				current_animation = &upLeft;
			}
		}

	}

	if(App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN)
	{
		App->particles->AddParticle(App->particles->laser,  position.x + 28, position.y, COLLIDER_PLAYER_SHOT);
	}

	if (App->input->GetKey(SDL_SCANCODE_S) == KEY_IDLE
		&& App->input->GetKey(SDL_SCANCODE_W) == KEY_IDLE
		&& App->input->GetKey(SDL_SCANCODE_D) == KEY_IDLE
		&& App->input->GetKey(SDL_SCANCODE_A) == KEY_IDLE)
	{
		if (faceRight == true)
			current_animation = &idle;
		else
			current_animation = &idleLeft;
	}
	

	// Draw everything --------------------------------------
	if(destroyed == false)
		App->renderer->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));

	collider->SetPos(position.x, position.y);
	return UPDATE_CONTINUE;
}

void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	if (destroyed == false)
	{
		//App->fade->FadeToBlack((Module*)App->scene_space, (Module*)App->scene_intro);
		destroyed = true;
		App->particles->AddParticle(App->particles->explosion, position.x, position.y, COLLIDER_NONE);
	}
}
