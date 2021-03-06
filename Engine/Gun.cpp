/* (c) M Thorne
	Handles all of the gun drawing and movement */

#include "Gun.H"

void Gun::Draw(Graphics & gfx, Background & bkd)
{
	/* Draw the gun based on its angle*/

	float PI = 3.14176;
	/* first get the Start of the Gun point */
	int gunBaseX = 800;// (gfx.ScreenWidth / 2);   //middle of the screen (base)
	int gunBaseY = Graphics::ScreenHeight - bkd.groundHeight - (bkd.baseHeight / 2); //Top of the Base

	/* Calculate the end points based on the gunAngle */
	/* Remember we are passed 0 to +180. 90 is vertical */
	// Sine of the angle will give us the vertical amount ie Sin 90 =1 all thje way "up"
	// CoSine will give us the Horizonal Offset
	float gunEndY = 35 * cos(angle*PI / 180);
	gunEndY = gunBaseY - gunEndY;

	float gunEndX = 35 * sin(angle*PI / 180);
	gunEndX = gunEndX + (gfx.ScreenWidth / 2);
	/*
	gfx.DrawLine(gunBaseX, gunBaseY, (int)gunEndX, (int)gunEndY, Colors::Gray);
	gfx.DrawLine(gunBaseX + 1, gunBaseY + 1, (int)gunEndX + 1, (int)gunEndY + 1, Colors::Gray);
	gfx.DrawLine(gunBaseX - 1, gunBaseY - 1, (int)gunEndX - 1, (int)gunEndY - 1, Colors::Gray);

	*/
	gfx.DrawLine(800, gunBaseY, (int)gunEndX, (int)gunEndY, Colors::Gray);
	//Set the Gun Tip lcoation as this will be a spawnpoint for the bullets.
	gunTip.x = gunEndX;
	gunTip.y = gunEndY;
}

void Gun::UpdateGun(int dir, float dt)
{
	/* Move the guns angle based on the tiom,e passed and the key pressed 
		Trap angle limits also */
	if ((dir==-1) && angle > -89 ){
		angle = angle - (gunMoveStep*dt);
		}

	if ((dir==1) && angle < 89) {
		angle = angle + (gunMoveStep*dt);
	}
}

int Gun::GetGunAngle()
{
	return (int)angle;
}

int Gun::GetGunTipX()
{
	return gunTip.x;
}

int Gun::GetGunTipY()
{
	return gunTip.y;
}
