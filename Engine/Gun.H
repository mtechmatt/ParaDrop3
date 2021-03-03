#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include "Background.h"
#include "Location.h"

class Gun
{
public:
	void Draw(Graphics& gfx, Background& bkd);
	void UpdateGun(Keyboard& kbd, float dt);
	int GetGunAngle();
	int GetGunTipX();
	int GetGunTipY();
	Location gunTip;
	float angle = 0;

private:
	int gunBaseX;
	int gunBaseY;
	int barrelLength = 35;
	float gunMoveStep = 75;
};