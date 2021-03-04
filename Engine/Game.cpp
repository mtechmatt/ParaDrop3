/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "SpriteCodex.h"
#include "Background.h"
#include "Gun.H"
#include "Bullet.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	bkd(),
	gun(),
	soundGunFire( L"Sounds\\arkbrick.wav" )
{
	for (int i = 0; i < MaxBullets; i++) {	/* Prep the bullets */
		bullets[i].isActive = false;
	}
}

void Game::Go()
{
	gfx.BeginFrame();
	float elapsedTime = ft.Mark();

	while( elapsedTime > 0.0f )
	{
		const float dt = std::min( 0.011f,elapsedTime );
		UpdateModel( dt );
		elapsedTime -= dt;

	}
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel( float dt )
{
	static float fireRateET;  /* Track fire rate for the gun */
	fireRateET += dt;

	if ((wnd.kbd.KeyIsPressed(VK_SPACE)) && (fireRateET > FireInterval)) {  /* Cionsider fire rate also */
		if (bulletCounter > MaxBullets) {
			bulletCounter = 0;
		}
		bullets[bulletCounter].Create(gun.GetGunTipX(), gun.GetGunTipY(), gun.GetGunAngle()); /* Create/activate a bullet */
		bulletCounter++;
		fireRateET = 0;  /* Reset the firerate timer */
		soundGunFire.Play(); /* Play sound of gun */
	}

	if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
		gun.UpdateGun(1, dt);
	}
	else if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
		gun.UpdateGun(-1, dt);
	}

	/* Update any bullets that are in flight */
	/* Note the bullet object will kill any bullets that leave the screen for us. */
	for (Bullet& b : bullets) {
		if (b.isActive) {
			b.Update(dt);

			/* Check for collision with any paratroppers */


			/* Check for collision with any aircraft */


		}
	}

	/* Update paratroopers falling to earth */

	/* Update the movement of any aircraft */

	/* Do random spawning of aircraft */

}


void Game::ComposeFrame()
{
	bkd.Draw(gfx); /* Draw the background and base */
	gun.Draw(gfx, bkd); /* Draw the gun */

	/* Draw any bullets that are in flight */
	for (const Bullet& b : bullets) {
		if (b.isActive) {
			b.Draw(gfx);
		}
	}

	/* Draw any paratroopers that need to be drawn */


	/* Draw any aircraft that are in flight */
	
}
