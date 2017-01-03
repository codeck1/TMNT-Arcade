#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::Enemy(const Enemy & e) : idle(e.idle), idleLeft(e.idleLeft), up(e.up), upLeft(e.upLeft),
right(e.right), left(e.left), attack1(e.attack1), attack1Left(e.attack1Left), attack2(e.attack2),
attack2Left(e.attack2Left), attackAir(e.attackAir), attackAirLeft(e.attackAirLeft), position(e.position),
eliminated(e.eliminated), colliderFeet(e.colliderFeet), colliderBody(e.colliderBody), colliderWeapon(e.colliderWeapon),
colliderJump(e.colliderJump), faceRight(e.faceRight), inAir(e.inAir), jumped(e.jumped), goingDown(e.goingDown),
attacking(e.attacking), jumpPos(e.jumpPos), jumpInit(e.jumpInit), currentState(e.currentState)
{
}

Enemy::~Enemy()
{
}

bool Enemy::Start()
{
	return false;
}

bool Enemy::Update()
{
	//Llamar a IA
	return false;
}
