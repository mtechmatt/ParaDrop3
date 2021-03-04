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


Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	bkd(),
	gun(),
	soundGunFire( L"Sounds\\arkbrick.wav" ),
	rng(rd()),
	xDist(0, Graphics::ScreenWidth),
	yDist(0, Graphics::ScreenHeight),
	spACtimer(6.5,9),
	spACVelocity(130,190),
	spParaInterval(2.7,4.1)
{
	for (int i = 0; i < MaxBullets; i++) {	/* Prep the bullets */
		bullets[i].isActive = false;
	}
	for (int i = 0; i < MaxTroopers; i++) {
		troopers[i].MadeIt = false; /* triger the construction of our troopers */
	}
	for (int i = 0; i < MaxAircraft; i++) {
		planes[i].isActive = false; /* triger the construction of our aircraft */
	}
}

void Game::Go()
{
	gfx.BeginFrame();
	float elapsedTime = ft.Mark();

	srand((unsigned)time(0));

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
	for (Paratrooper& p : troopers) {
		if (p.isActive) {
			p.Update(dt);
		}
	}

	/* Update the movement of any aircraft */
	/* For each a/.c in flight, chek the spawn interval array (random a bit) and then deploy a trooper from the a/c */
	for (Aircraft& p : planes) {
		if (p.isActive) {
			p.Update(dt);
		}
	}
	
	/*** PLANE SPAWNER ***/
	/* Do random spawning of aircraft */
	static float planesSpawnRateET;  /* Track spawn interval for planes  */
	planesSpawnRateET += dt;
	if (planesSpawnRateET > spACtimer(rng)) {	/*1.5 seconds has elapsed */
		Vec2 SpawnPoint;
		
		float SpawnVel = 0.0f;
		/* Spawn Left or Spawn Right */
		if (xDist(rng) > (0.5*Graphics::ScreenWidth)) {  // Spawn Right, fly left
			SpawnPoint.x = Graphics::ScreenWidth - 250;
			SpawnPoint.y = 100;
			SpawnVel = -spACVelocity(rng);
		}
		else { /* Spawn on the left, fly right */
			SpawnPoint.x = 150;
			SpawnPoint.y = 300;
			SpawnVel = spACVelocity(rng);
		}

		planesInFlight++;

		if (planesInFlight++ > MaxAircraft) {
			planesInFlight = 0;
		}



		planes[planesInFlight].Deploy(SpawnPoint, SpawnVel);
		planesSpawnRateET = 0;
	}


	/*** Para Spawner ***/
	static float paraSpawnRateET[MaxAircraft];  /* Track spawn interval for paratroopers for all aircraft */
	/* go round each aircraft, if active, check the ET, and spawn */
	for (int i=0; i < MaxAircraft; i++) {
		if (planes[i].isActive) {   //This plane is flying
			/* increase its ET */
			paraSpawnRateET[i] += dt;
			if (paraSpawnRateET[i] > spParaInterval(rng)) {  // Spawn a trooper from an a/c every 0.9 seconds
				paraSpawnRateET[i] = 0; //reset its ET
				Vec2 ParaSP;
				ParaSP.x = planes[i].GetX();	/* set our paras spwan to the aircraft */
				ParaSP.y = planes[i].GetY();
				if (planes[i].GetVel() > 0) {  /* flying right*/
					troopersInAction++;
					troopers[troopersInAction].Deploy(ParaSP, 0.5, 1200);
				}
				else {   /* flying left*/
					troopersInAction++;
					troopers[troopersInAction].Deploy(ParaSP, -0.5, 1200);
				}
				if (troopersInAction > MaxTroopers) {
					troopersInAction = 0;
				}

			}

		}


	}
	
	/*
	if (paraSpawnRateET > 1008.5f) {
		Vec2 SpawnPoint;
		SpawnPoint.y = 100;
		SpawnPoint.x = xDist(rng);
		troopersInAction++;
		troopers[troopersInAction].Deploy(SpawnPoint, 0.3, 1200);
		paraSpawnRateET = 0;
	}
	*/
	

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
	for (Paratrooper& p : troopers) {
		if (p.isActive) {
			p.Draw(gfx);
		}
	}

	/* Draw any aircraft that are in flight */
	for (Aircraft& a : planes) {
		if (a.isActive) {
			a.Draw(gfx);
		}
	}

}
