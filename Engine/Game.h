/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "FrameTimer.h"
#include "Background.h"
#include "Gun.H"
#include "Bullet.h"
#include "Sound.h"
#include "ParaTrooper.h"
#include "SpriteCodex.h"
#include "Aircraft.h"
#include <random>

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel( float dt );
	void PlayRandomJumpSound();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	FrameTimer ft;
	/********************************/

	/* Random number generation stuff */
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_real_distribution<float> xDist;
	std::uniform_real_distribution<float> yDist;

	std::uniform_real_distribution<float> spACtimer;
	std::uniform_real_distribution<float> spACVelocity;
	std::uniform_real_distribution<float> spParaInterval;

	std::uniform_real_distribution<float> whichSound;

	static constexpr int MaxBullets = 50;
	static constexpr float FireInterval = 0.15f;  /* the minimum time between firing - lower = higher RPM */
	Bullet bullets[MaxBullets]; //Create 500 bullet holders
	int bulletCounter = 0;

	static constexpr int MaxTroopers = 150;
	Paratrooper troopers[MaxTroopers];
	int troopersInAction = 0;

	static constexpr int MaxAircraft = 15;
	Aircraft planes[MaxAircraft];
	int planesInFlight = 0;


	Background bkd;
	Gun gun;
	
	enum e_gameState{startTitle, endTitle, preStartTimer, playingWave1, playingWave2, gameLost};
	e_gameState gameState = playingWave1;

	float diffMulti = 1;

	Sound soundGunFire;
	Sound soundJump1;
	Sound soundJump2;
	Sound soundJump3;
	Sound soundJump4;
	Sound soundExplode1;

	Sound Splat1;

};