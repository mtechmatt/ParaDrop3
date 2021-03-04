#pragma once
#include "Vec2.h"
#include "SpriteCodex.h"
#include "Graphics.h"

class Paratrooper {
public:
	Paratrooper() = default;
	void Deploy(Vec2 Position, float in_Vel, int in_groundLevel);
	void Draw(Graphics& gfx);
	void Update(float dt);
	bool MadeIt = false;
	bool isActive = false;

private:
	int dropRate = 35;
	int groundLevel = 200;
	bool hasChute = true;
	float xVel = 0.2;
	Vec2 position;
};