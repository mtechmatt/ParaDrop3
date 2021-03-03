#include "Bullet.h"
#include "Colors.h"

void Bullet::Draw(Graphics & gfx)
{
	if (isActive) { /* if we are active, draw us*/
		gfx.DrawCircle((int)posX, (int)posY, 5, Colors::Red);
	}
}

void Bullet::UpdatePosition(float dt)
{
	/* move our bullets position based on the time pass and our recorded launch anngle 
	only do this if we are active, otherwise, just return */
	if (isActive) {
		float posY = posY + (travelVel * cos(launchAngle*3.1416 / 180) * dt);
		float posX = posX + (travelVel * sin(launchAngle*3.1416 / 180) * dt);
	}
}

void Bullet::LaunchBullet(float firingAngle)
{
	/* Called whenever we fire a bullet */
	launchAngle = firingAngle; /* Record our firing angle handed to us by the gun */
	isActive = true; /* make us Active */
}
