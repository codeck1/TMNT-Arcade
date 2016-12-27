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
	idle.pivotY = -5;
	idle.loop = true;
	idle.speed = 0.05f;

	// idleLeft animation
	idleLeft.frames.push_back({ 924, 1339, 103, 61 });
	idleLeft.frames.push_back({ 821, 1339, 103, 61 });
	idleLeft.frames.push_back({ 718, 1339, 103, 61 });
	idleLeft.frames.push_back({ 615, 1339, 103, 61 });
	idleLeft.frames.push_back({ 512, 1339, 103, 61 });
	idleLeft.pivotY = -5;
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

	// Jump
	jump.frames.push_back({ 618,328,103,75 });
	jump.frames.push_back({ 618,328,103,75 });
	jump.frames.push_back({ 618,328,103,75 });
	jump.frames.push_back({ 618,328,103,75 });
	jump.frames.push_back({ 721,328,103,75 });
	jump.frames.push_back({ 824,328,103,75 });
	jump.frames.push_back({ 927,328,103,75 });
	jump.frames.push_back({ 0,438,103,75 });
	jump.frames.push_back({ 103,438,103,75 });
	jump.frames.push_back({ 206,438,103,75 });
	jump.frames.push_back({ 309,438,103,75 });
	jump.frames.push_back({ 412,438,103,75 });
	jump.frames.push_back({ 515,438,103,75 });
	jump.loop = false;
	jump.speed = 0.2f;

	// JumpLeft
	jumpLeft.frames.push_back({ 309,1628,103,75 });
	jumpLeft.frames.push_back({ 309,1628,103,75 });
	jumpLeft.frames.push_back({ 309,1628,103,75 });
	jumpLeft.frames.push_back({ 309,1628,103,75 });
	jumpLeft.frames.push_back({ 206,1628,103,75 });
	jumpLeft.frames.push_back({ 103,1628,103,75 });
	jumpLeft.frames.push_back({ 0,1628,103,75 });
	jumpLeft.frames.push_back({ 927,1738,103,75 });
	jumpLeft.frames.push_back({ 824,1738,103,75 });
	jumpLeft.frames.push_back({ 721,1738,103,75 });
	jumpLeft.frames.push_back({ 618,1738,103,75 });
	jumpLeft.frames.push_back({ 515,1738,103,75 });
	jumpLeft.frames.push_back({ 412,1738,103,75 });
	jumpLeft.loop = false;
	jumpLeft.speed = 0.2f;

	// Atack1
	atack1.frames.push_back({ 640,134,59,75 });
	atack1.frames.push_back({ 739,134,67,75 });
	atack1.frames.push_back({ 841,134,69,75 });
	atack1.frames.push_back({ 927,134,103,75 });
	atack1.pivot = -32;
	atack1.loop = false;
	atack1.speed = 0.2f;

	// Atack1Left
	atack1Left.frames.push_back({ 298,1433,103,75 });
	atack1Left.frames.push_back({ 196,1433,103,75 });
	atack1Left.frames.push_back({ 93,1433,103,75 });
	atack1Left.frames.push_back({ 301,2516,103,75 });
	atack1Left.pivot = 20;
	atack1Left.loop = false;
	atack1Left.speed = 0.2f;

	// Atack2
	atack2.frames.push_back({ 38,234,37,75 });
	atack2.frames.push_back({ 135,234,42,75 });
	atack2.frames.push_back({ 227,234,60,75 });
	atack2.frames.push_back({ 318,234,86,75 });
	atack2.frames.push_back({ 413,234,100,75 });
	atack2.frames.push_back({ 538,234,56,75 });
	atack2.frames.push_back({ 652,234,37,75 });
	atack2.pivot = -40;
	atack2.loop = false;
	atack2.speed = 0.27f;

	// Atack2Left
	atack2Left.frames.push_back({ 902,1535,97,75 });
	atack2Left.frames.push_back({ 810,1535,97,75 });
	atack2Left.frames.push_back({ 719,1535,97,75 });
	atack2Left.frames.push_back({ 624,1535,97,75 });
	atack2Left.frames.push_back({ 523,1535,97,75 });
	atack2Left.frames.push_back({ 401,1535,97,75 });
	atack2Left.frames.push_back({ 301,1535,97,75 });
	atack2Left.pivot = 22;
	atack2Left.loop = false;
	atack2Left.speed = 0.27f;
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
		if(!attacking)
		{
			position.x -= speed;
			if (current_animation != &left && App->input->GetKey(SDL_SCANCODE_W) != KEY_REPEAT && !jumped)
			{
				left.Reset();
				current_animation = &left;
				faceRight = false;
			}
		}
		
		
	}

	if(App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
	{
		if (!attacking)
		{
			position.x += speed;
			if (current_animation != &right && App->input->GetKey(SDL_SCANCODE_W) != KEY_REPEAT && !jumped)
			{
				right.Reset();
				current_animation = &right;
				faceRight = true;
			}
		}
		
	}

	if(App->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT)
	{
		if(!jumped && !attacking)
		{
			position.y += speed;
			if (current_animation != &right && faceRight == true)
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
		}
		

	if(App->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT)
	{
		if (!jumped && !attacking)
		{
			position.y -= speed;
			if (current_animation != &up && faceRight == true)
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
		

	}
	
	if (App->input->GetKey(SDL_SCANCODE_N) == KEY_DOWN)
	{
		
		if (!jumped && !attacking)
		{
			jumped = true;
			if (current_animation != &jump && faceRight == true)
			{
				jump.Reset();
				current_animation = &jump;
			}
			else
			{
				if(current_animation != &jumpLeft)
				jumpLeft.Reset();
				current_animation = &jumpLeft;
			}
			
		}
	}

	if (App->input->GetKey(SDL_SCANCODE_M) == KEY_DOWN)
	{
		seed_seq ss{ uint32_t(timeSeed2 & 0xffffffff), uint32_t(timeSeed2 >> 32) };

		timeSeed2 = chrono::high_resolution_clock::now().time_since_epoch().count();
		range2.seed(ss);
		uniform_real_distribution<double> unif(0, 1);
		randomVar = unif(range2);

		if (current_animation != &atack2 && current_animation != &atack1 && !jumped && faceRight == true)
		{
			if (randomVar >= 0.5)
			{
				atack1.Reset();
				current_animation = &atack1;
				attacking = true;
			}
			else
			{
				atack2.Reset();
				current_animation = &atack2;
				attacking = true;
			}

		}
		if (current_animation != &atack2Left && current_animation != &atack1Left && !jumped && faceRight == false)
		{
			if (randomVar >= 0.5)
			{
				atack1Left.Reset();
				current_animation = &atack1Left;
				attacking = true;
			}
			else
			{
				atack2Left.Reset();
				current_animation = &atack2Left;
				attacking = true;
			}
		}
	}

	//jumping
	if (inAir == false && jumped)
	{
		jumpPos = position.y;
		jumpPos -= 128;
		inAir = true;
	}
	if (inAir == true && jumped)
	{
		if (position.y >= jumpPos && goingDown == false)
		{
			position.y -= 4;
		}
		else
		{
			position.y += 4;
			goingDown = true;
			if (position.y >= jumpPos + 128)
			{
				goingDown = false;
			}
		}
	}

	//ending of actions
	if ((current_animation == &jump || current_animation == &jumpLeft)  && current_animation->Finished())
	{
		inAir = false;
		jumped = false;
	}

	if ((current_animation == &atack1 || current_animation == &atack2 || current_animation == &atack2Left || current_animation == &atack1Left)&& current_animation->Finished())
		attacking = false;

	if(App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN)
	{
		App->particles->AddParticle(App->particles->laser,  position.x + 28, position.y, COLLIDER_PLAYER_SHOT);
	}

	if (App->input->GetKey(SDL_SCANCODE_S) == KEY_IDLE
		&& App->input->GetKey(SDL_SCANCODE_W) == KEY_IDLE
		&& App->input->GetKey(SDL_SCANCODE_D) == KEY_IDLE
		&& App->input->GetKey(SDL_SCANCODE_A) == KEY_IDLE
		&& inAir == false
		&& attacking == false)
	{
		if (faceRight == true)
			current_animation = &idle;
		else
			current_animation = &idleLeft;
	}
	

	// Draw everything --------------------------------------
	if(destroyed == false)
		App->renderer->Blit(graphics, position.x-current_animation->pivot, position.y- current_animation->pivotY, &(current_animation->GetCurrentFrame()));

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

