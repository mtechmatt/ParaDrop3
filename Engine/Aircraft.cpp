#include "Aircraft.h"

void Aircraft::Deploy(Vec2 spPos, float in_Vel)
{
	position = spPos;
	isActive = true;

	xVel = in_Vel;		
}

void Aircraft::Draw(Graphics& gfx)
{
	if (isActive) {
		if (xVel > 0) {  /* If Vel is +ve then draw a right flying bomber else etc */
			SpriteCodex::DrawBomberL1(position, gfx);
		}
		else {
			SpriteCodex::DrawBomberR1(position, gfx);
		}
	}
}

void Aircraft::Update(float dt)
{
	/* move accross the screen in the right direction */
	if (isActive) {
		if ( 
			((xVel>0) && (position.x>Graphics::ScreenWidth-250)) ||
			((xVel < 0) && (position.x < 10))
			) {  /* Edge Check */
			isActive = false;
		}
		else {			/* Keep moving */
			position.x += xVel * dt;
		}

	}

}

bool Aircraft::isHitting(Bullet & bullet)
{
	/* I have been passed a bullet.
		is it touching me? */
	if (bullet.isActive) {
		/* its active, OK lets see if its on us */
		/* we have my position (position) and we know the bullets size. We also need to set that bullet to not active if contact */
		if ((bullet.posX>position.x) &&
			(bullet.posY>position.y) &&
			(bullet.posX<position.x+250) &&
			(bullet.posY<position.y+80)
			) {   
 				bullet.isActive = false;
				isActive = false; //also kill myself
				return true;
		}
	}	
	return false;
}

int Aircraft::GetX()
{
	return (int)position.x;
}

int Aircraft::GetY()
{
	return (int)position.y;
}

float Aircraft::GetVel()
{
	return xVel;
}
