#pragma once
#include "Graphics.h"

class Bullet {
public:
	void Draw(Graphics& gfx);
	void UpdatePosition(float dt);
	void LaunchBullet(float firingAngle);
private:
	float launchAngle;
	float travelVel=50;
	int posX;
	int posY;
	bool isActive;
};
