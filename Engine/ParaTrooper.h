#pragma once
#include "Vec2.h"
#include "SpriteCodex.h"
#include "Graphics.h"
#include "Bullet.h"

class Paratrooper {
public:
	Paratrooper() = default;
	void Deploy(Vec2 Position, float in_Vel, int in_groundLevel);
	void Draw(Graphics& gfx);
	void Update(float dt);
	bool MadeIt = false;
	bool isActive = false;
	bool isHitting(Bullet& bullet);

private:
	int dropRate = 35;
	int groundLevel;
	bool hasChute = true;
	float xVel;
	Vec2 position;
};