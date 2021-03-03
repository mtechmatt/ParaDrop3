/* (c) M Thorne
	Handles all of the gun drawing and movement */

#include "Gun.H"
#include "Background.h"
#include "Colors.h"

void Gun::Draw(Graphics & gfx, Background & bkd)
{
	/* Draw the gun based on its angle*/

	float PI = 3.14176;
	/* first get the Start of the Gun point */
	int gunBaseX = (gfx.ScreenWidth / 2);   //middle of the screen (base)
	int gunBaseY = Graphics::ScreenHeight - bkd.groundHeight - (bkd.baseHeight / 2); //Top of the Base

	/* Calculate the end points based on the gunAngle */
	/* Remember we are passed 0 to +180. 90 is vertical */
	// Sine of the angle will give us the vertical amount ie Sin 90 =1 all thje way "up"
	// CoSine will give us the Horizonal Offset
	float gunEndY = barrelLength * cos(angle*PI / 180);
	gunEndY = gunBaseY - gunEndY;

	float gunEndX = barrelLength * sin(angle*PI / 180);
	gunEndX = gunEndX + (gfx.ScreenWidth / 2);

	gfx.DrawLine(gunBaseX, gunBaseY, (int)gunEndX, (int)gunEndY, Colors::Gray);
	gfx.DrawLine(gunBaseX + 1, gunBaseY + 1, (int)gunEndX + 1, (int)gunEndY + 1, Colors::Gray);
	gfx.DrawLine(gunBaseX - 1, gunBaseY - 1, (int)gunEndX - 1, (int)gunEndY - 1, Colors::Gray);
	//Set the Gun Tip lcoation as this will be a spawnpoint for the bullets.
	gunTipX = gunEndX;
	gunTipY = gunEndY;
}

void Gun::UpdateGun(Keyboard & kbd, float dt)
{
	/* Move the guns angle based on the tiom,e passed and the key pressed 
		Trap angle limits also */
	if (kbd.KeyIsPressed( VK_LEFT) && angle > -89 ){
		angle = angle - (gunMoveStep*dt);
		}

	if (kbd.KeyIsPressed(VK_RIGHT) && angle < 89) {
		angle = angle + (gunMoveStep*dt);
	}
}
