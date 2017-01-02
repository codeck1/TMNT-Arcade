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
	idle.pivot = 30;
	idle.loop = true;
	idle.speed = 0.05f;

	// idleLeft animation
	idleLeft.frames.push_back({ 924, 1339, 103, 61 });
	idleLeft.frames.push_back({ 821, 1339, 103, 61 });
	idleLeft.frames.push_back({ 718, 1339, 103, 61 });
	idleLeft.frames.push_back({ 615, 1339, 103, 61 });
	idleLeft.frames.push_back({ 512, 1339, 103, 61 });
	idleLeft.pivotY = -5;
	idleLeft.pivot = 30;
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
	up.pivot = 15;
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
	upLeft.pivot = 45;
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
	right.pivot = 25;
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
	left.pivot = 35;
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
	jump.pivot = 35;
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
	jumpLeft.pivot = 35;
	jumpLeft.loop = false;
	jumpLeft.speed = 0.2f;

	// attack1
	attack1.frames.push_back({ 640,134,59,75 });
	attack1.frames.push_back({ 739,134,67,75 });
	attack1.frames.push_back({ 841,134,69,75 });
	attack1.frames.push_back({ 927,134,103,75 });
	attack1.pivot = 0;
	attack1.loop = false;
	attack1.speed = 0.2f;

	// attack1Left
	attack1Left.frames.push_back({ 298,1433,103,75 });
	attack1Left.frames.push_back({ 196,1433,103,75 });
	attack1Left.frames.push_back({ 93,1433,103,75 });
	attack1Left.frames.push_back({ 301,2516,103,75 });
	attack1Left.pivot = 40;
	attack1Left.loop = false;
	attack1Left.speed = 0.2f;

	// attack2
	attack2.frames.push_back({ 38,234,37,75 });
	attack2.frames.push_back({ 135,234,42,75 });
	attack2.frames.push_back({ 227,234,60,75 });
	attack2.frames.push_back({ 318,234,86,75 });
	attack2.frames.push_back({ 413,234,100,75 });
	attack2.frames.push_back({ 538,234,56,75 });
	attack2.frames.push_back({ 652,234,37,75 });
	attack2.pivot = -10;
	attack2.loop = false;
	attack2.speed = 0.3f;

	// attack2Left
	attack2Left.frames.push_back({ 902,1535,97,75 });
	attack2Left.frames.push_back({ 810,1535,97,75 });
	attack2Left.frames.push_back({ 719,1535,97,75 });
	attack2Left.frames.push_back({ 624,1535,97,75 });
	attack2Left.frames.push_back({ 523,1535,97,75 });
	attack2Left.frames.push_back({ 401,1535,97,75 });
	attack2Left.frames.push_back({ 301,1535,97,75 });
	attack2Left.pivot = 42;
	attack2Left.loop = false;
	attack2Left.speed = 0.3f;

	// attackAir
	attackAir.frames.push_back({ 927,435,103,75 });
	attackAir.frames.push_back({ 0,527,103,75 });
	attackAir.frames.push_back({ 103,527,103,75 });
	attackAir.pivot = 30;
	attackAir.loop = false;
	attackAir.speed = 0.2f;

	// attackAirLeft
	attackAirLeft.frames.push_back({ 0,1735,103,75 });
	attackAirLeft.frames.push_back({ 927,1827,103,75 });
	attackAirLeft.frames.push_back({ 824,1827,103,75 });
	attackAirLeft.pivot = 30;
	attackAirLeft.loop = false;
	attackAirLeft.speed = 0.2f;

	// attackAir2
	attackAir2.frames.push_back({ 206,529,103,75 });
	attackAir2.frames.push_back({ 309,529,103,75 });
	attackAir2.frames.push_back({ 430,529,103,75 });
	attackAir2.frames.push_back({ 515,529,103,75 });
	attackAir2.frames.push_back({ 620,529,103,75 });
	attackAir2.frames.push_back({ 588,1219,132,75 });
	attackAir2.frames.push_back({ 843,529,103,75 });
	attackAir2.pivot = 30;
	attackAir2.loop = false;
	attackAir2.speed = 0.25f;

	// attackAir2Left
	attackAir2Left.frames.push_back({ 715,1830,103,75 });
	attackAir2Left.frames.push_back({ 617,1830,103,75 });
	attackAir2Left.frames.push_back({ 504,1830,103,75 });
	attackAir2Left.frames.push_back({ 401,1830,103,75 });
	attackAir2Left.frames.push_back({ 270,1830,103,75 });
	attackAir2Left.frames.push_back({ 66,2617,103,75 });
	attackAir2Left.frames.push_back({ 82,1830,103,75 });
	attackAir2Left.pivot = 30;
	attackAir2Left.loop = false;
	attackAir2Left.speed = 0.25f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	graphics = App->textures->Load("rtype/donatello1.png");

	eliminated = false;
	position.x = 150;
	position.y = 150;
	colliderFeet = App->collision->AddCollider({ position.x, position.y+50, 32, 14 }, COLLIDER_PLAYER_FEET, this);
	colliderBody = App->collision->AddCollider({ position.x, position.y +10, 32, 45 }, COLLIDER_PLAYER_BODY, this);

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
	
	switch (currentState)
	{
		case IDLE:
		{

			if (App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
			{
				faceRight = false;
				position.x -= speed;
				if (current_animation != &left && App->input->GetKey(SDL_SCANCODE_W) != KEY_REPEAT && !jumped)
				{
					if (!jumped)
					{
						left.Reset();
						current_animation = &left;
					}

				}
			}

			if (App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
			{
				faceRight = true;
				position.x += speed;
				if (current_animation != &right && App->input->GetKey(SDL_SCANCODE_W) != KEY_REPEAT)
				{
					if (!jumped)
					{
						right.Reset();
						current_animation = &right;
					}

				}
			}

			if (App->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT)
			{
				position.y += speed;
				if (!jumped)
				{
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

			if (App->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT)
			{
				if (!jumped)
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
				currentState = JUMPING;
				jumped = true;
			}


			if (App->input->GetKey(SDL_SCANCODE_M) == KEY_DOWN)
			{
				currentState = ATTACKING;
			}

			break;
		}
			
		case ATTACKING:
		{
			seed_seq ss{ uint32_t(timeSeed2 & 0xffffffff), uint32_t(timeSeed2 >> 32) };

			timeSeed2 = chrono::high_resolution_clock::now().time_since_epoch().count();
			range2.seed(ss);
			uniform_real_distribution<double> unif(0, 1);
			randomVar = unif(range2);

			if (current_animation != &attack2 && current_animation != &attack1 && !jumped && faceRight == true)
			{
				if (randomVar >= 0.5)
				{
					attack1.Reset();
					current_animation = &attack1;
					attacking = true;
				}
				else
				{
					attack2.Reset();
					current_animation = &attack2;
					attacking = true;
				}

			}
			if (current_animation != &attack2Left && current_animation != &attack1Left && !jumped && faceRight == false)
			{
				if (randomVar >= 0.5)
				{
					attack1Left.Reset();
					current_animation = &attack1Left;
					attacking = true;
				}
				else
				{
					attack2Left.Reset();
					current_animation = &attack2Left;
					attacking = true;
				}
			}
			if (current_animation != &attackAir && jumped)
			{
				if (goingDown == false && !attacking)
				{
					if (position.y > jumpPos + 40)
					{
						if (faceRight && current_animation != &attackAir)
						{
							attackAir.Reset();
							current_animation = &attackAir;
							attacking = true;
							goingDown = true;
							jumpPos = position.y;
							attackingAirX = 3;
						}
						if (!faceRight && current_animation != &attackAirLeft)
						{
							attackAirLeft.Reset();
							current_animation = &attackAirLeft;
							attacking = true;
							goingDown = true;
							jumpPos = position.y;
							attackingAirX = -3;
						}
					}
					else
					{
						if (faceRight && current_animation != &attackAir2)
						{
							attackAir2.Reset();
							current_animation = &attackAir2;
							attacking = true;
							goingDown = true;
							jumpPos = position.y;
						}
						if (!faceRight && current_animation != &attackAir2Left)
						{
							attackAir2Left.Reset();
							current_animation = &attackAir2Left;
							attacking = true;
							goingDown = true;
							jumpPos = position.y;
						}
					}

				}
				else
				{
					if (goingDown == true && !attacking)
					{
						if (position.y < jumpInit.y - 40)
						{
							if (faceRight && current_animation != &attackAir)
							{
								attackAir.Reset();
								current_animation = &attackAir;
								attacking = true;
								goingDown = true;
								jumpPos = position.y;
								attackingAirX = 3;
							}
							if (!faceRight && current_animation != &attackAirLeft)
							{
								attackAirLeft.Reset();
								current_animation = &attackAirLeft;
								attacking = true;
								goingDown = true;
								jumpPos = position.y;
								attackingAirX = -3;
							}
						}
						else
						{
							if (faceRight && current_animation != &attackAir2)
							{
								attackAir2.Reset();
								current_animation = &attackAir2;
								attacking = true;
								goingDown = true;
								jumpPos = position.y;
							}
							if (!faceRight && current_animation != &attackAir2Left)
							{
								attackAir2Left.Reset();
								current_animation = &attackAir2Left;
								attacking = true;
								goingDown = true;
								jumpPos = position.y;
							}
						}
					}
				}
			}
			break; 
		}
		case JUMPING:
		{
			if (current_animation != &jump && faceRight == true)
			{
				jump.Reset();
				current_animation = &jump;
			}
			else
			{
				if (current_animation != &jumpLeft && faceRight == false)
				{
					jumpLeft.Reset();
					current_animation = &jumpLeft;
				}
			}
			currentState = IDLE;
			
			break;
		}
			
	default:
		break;
	}

	

	//ending of actions
	if ((current_animation == &attack1 || current_animation == &attack2 || current_animation == &attack2Left || current_animation == &attack1Left || current_animation == &attackAir || current_animation == &attackAirLeft || current_animation == &attackAir2 || current_animation == &attackAir2Left) && current_animation->Finished())
	{
		attacking = false;
		currentState = IDLE;
	}

	//jumping
	if (inAir == false && jumped)
	{
		jumpPos = position.y - 150;
		jumpInit = position;
		inAir = true;
	}
	if (inAir == true && jumped)
	{
		if (position.y > jumpPos && goingDown == false)
		{
			position.y -= 4;
		}
		else
		{
			position.y += 4;
			position.x += attackingAirX;
			goingDown = true;
			if (position.y >= jumpInit.y)
			{
				goingDown = false;
				inAir = false;
				jumped = false;
				attackingAirX = 0;
			}
		}
	}


	if (App->input->GetKey(SDL_SCANCODE_S) == KEY_IDLE
		&& App->input->GetKey(SDL_SCANCODE_W) == KEY_IDLE
		&& App->input->GetKey(SDL_SCANCODE_D) == KEY_IDLE
		&& App->input->GetKey(SDL_SCANCODE_A) == KEY_IDLE
		&& inAir == false
		&& attacking == false
		&& currentState == IDLE)
	{
		if (faceRight == true)
		{
			current_animation = &idle;
			currentState = IDLE;
		}
		else
		{
			current_animation = &idleLeft;
			currentState = IDLE;
		}
	}
	

	// Draw everything --------------------------------------
	if(eliminated == false)
		App->renderer->Blit(graphics, position.x-current_animation->pivot, position.y- current_animation->pivotY, &(current_animation->GetCurrentFrame()));

	colliderFeet->SetPos(position.x+10, position.y+50);
	colliderBody->SetPos(position.x + 10, position.y + 5);
	return UPDATE_CONTINUE;
}

void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	//left
	if ((c1->rect.x < c2->rect.x + c2->rect.w) && ((c2->rect.x + c2->rect.w) - c1->rect.x) < c1->rect.w && ((c2->rect.y + c2->rect.h) - c1->rect.y) >4 && (c2->rect.y - (c1->rect.h + c1->rect.y)) <-4 && c2->type == COLLIDER_WALL)
	{
		position.x += ((c2->rect.x + c2->rect.w) - c1->rect.x);
	}
	else
	{
		//right
		if (c1->rect.x + c1->rect.w > c2->rect.x && ((c2->rect.y + c2->rect.h) - c1->rect.y) >4 && (c2->rect.y - (c1->rect.h + c1->rect.y)) <-4 && c2->type == COLLIDER_WALL)
		{
			position.x += (c2->rect.x - (c1->rect.x + c1->rect.w));
		}
		else
		{
			//down
			if ((c1->rect.y < c2->rect.y + c2->rect.h) && ((c1->rect.h + c1->rect.y) - c2->rect.y) > c1->rect.h && c2->type == COLLIDER_WALL)
			{
				position.y += ((c2->rect.y + c2->rect.h) - c1->rect.y);
			}
			else
			{
				//up
				if (c1->rect.h + c1->rect.y > c2->rect.y && c2->type == COLLIDER_WALL)
				{
					position.y += (c2->rect.y - (c1->rect.h + c1->rect.y));
				}
			}
		}
	}
}

