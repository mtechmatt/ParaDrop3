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
			((xVel < 0) && (position.x < 250))
			) {  /* Edge Check */
			isActive = false;
		}
		else {			/* Keep moving */
			position.x += xVel * dt;
		}

	}

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
