#include "Background.h"

void Background::Draw(Graphics & gfx)
{
	//Draw the ground:
	gfx.DrawRect(0, Graphics::ScreenHeight - groundHeight, Graphics::ScreenWidth, Graphics::ScreenHeight, Colors::Sand);

	//Draw the Night sky
	gfx.DrawRect(0, 0, Graphics::ScreenWidth, Graphics::ScreenHeight - groundHeight, Colors::BlueNightSky);
	/* TODO lets add some stars */
	/* TODO lets add a gradient to very dark at the top */

	//Draw the little base house
	gfx.DrawRect(basePostXMid-(baseWidth/2), Graphics::ScreenHeight - groundHeight - (baseHeight/2), basePostXMid - (baseWidth / 2)+baseWidth, Graphics::ScreenHeight - groundHeight, Colors::Gray);
	/* we can add to this later to have windows and stuff */
}
