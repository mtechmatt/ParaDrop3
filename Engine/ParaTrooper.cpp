#include "ParaTrooper.h"

void Paratrooper::Deploy(Vec2 Position, float in_Vel, int in_groundLevel)
{
	position = Position;
	isActive = true;

	groundLevel = in_groundLevel;
	
	hasChute = true;	/* His parachute is in tact */
	xVel = in_Vel;		/* His X velocity is aa factor of the a/c thjat drops him so store it here */
}

void Paratrooper::Draw(Graphics& gfx)
{
	if (isActive) {
		SpriteCodex::DrawPara(position, gfx);
	}
}

void Paratrooper::Update(float dt)
{
	/* move him down the screen - if he is at ground level, stop moving him, remove his chute */
	if (isActive) {
		if (position.y >= groundLevel) {  /* He is at the ground */
			/* Remove his chute - mark him as safe  */
			MadeIt = true;
		}
		else {			/* Keep falling mate */
			position.y += dropRate * dt;
			position.x += xVel * dt;
		}

	}

}
