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
		
		if (position.x<24 || position.x > Graphics::ScreenWidth - 24) {
			isActive = false;  // Hes gone off the edge
		}

	}

}

bool Paratrooper::isHitting(Bullet & bullet)
{
	/* I have been passed a bullet.
		is it touching me? */
	if (bullet.isActive) {
		/* its active, OK lets see if its on us */
		/* we have my position (position) and we know the bullets size. We also need to set that bullet to not active if contact */
		if ((bullet.posX > position.x) &&
			(bullet.posY > position.y) &&
			(bullet.posX < position.x + 25) &&
			(bullet.posY < position.y + 40)
			) {
			bullet.isActive = false;
			isActive = false; //also kill myself
			return true;
		}
	}
	return false;
}
