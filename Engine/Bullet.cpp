#include "Bullet.h"

void Bullet::Update(float dt)
{
	/* Given that we have our starting point set, and our velicities, lets move by the amount specified. */
		
	if ((posX < 5) || (posX > (Graphics::ScreenWidth - 5)) || (posY < 5) || (posY > Graphics::ScreenHeight)) {
		isActive = false;  //Disable this bullet
		return;
	}

	/* If we are active, compute our movement */
	if (isActive) {
		/* Move our location (this will round to nearest (int) pixel) */
		posX += velX *dt;
		posY += velY*dt;
	}

}


void Bullet::Create(int inposX, int inposY, int firingAngle)
{
	// Define our first position of the bullet.
	posX = inposX;
	posY = inposY;

	const float PI = 3.1417;

	//Calulate our velocities based on the firing angle
	velX = velMultiplier * sin(firingAngle*PI / 180);
	velY = velMultiplier * cos(firingAngle*PI / 180);
	velY = velY * -1; //Invert for "upwards Travel"

					  // We now have our velocities as floats, ready to use in our update functions each "step".
	isActive = true;


}

void Bullet::Draw(Graphics & gfx) const
{
	/* Draw us on the screen */
	gfx.DrawCircle((int)posX, (int)posY, 2, Colors::Green);	
}
