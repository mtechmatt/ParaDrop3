#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include "Colors.h"
#include "Background.h"
#include "Location.h"

class Gun
{
public:
	void Draw(Graphics& gfx, Background& bkd);
	void UpdateGun(int dir, float dt);
	int GetGunAngle();
	int GetGunTipX();
	int GetGunTipY();
	Location gunTip;
	float angle = 0;

private:
	int gunBaseX;
	int gunBaseY;
	int barrelLength = 35;  //how is this geting changed to a BS number?
	float gunMoveStep = 55;
};