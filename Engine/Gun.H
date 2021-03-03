#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include "Background.h"

class Gun
{
public:
	void Draw(Graphics& gfx, Background& bkd);
	void UpdateGun(Keyboard& kbd, float dt);
	int gunTipX;
	int gunTipY;
private:
	float angle = 0;
	int gunBaseX;
	int gunBaseY;
	int barrelLength = 35;
	float gunMoveStep = 50;
};