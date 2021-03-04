#pragma once
#include "Vec2.h"
#include "SpriteCodex.h"
#include "Graphics.h"
#include "ColBox.h"
#include "Bullet.h"

class Aircraft {
public:
	Aircraft() = default;
	void Deploy(Vec2 SpP, float in_Vel);
	void Draw(Graphics& gfx);
	void Update(float dt);
	bool isHitting(Bullet& bullet);


	bool isActive = false;
	int GetX();
	int GetY();
	float GetVel();

private:
	int dropRate = 35;
	float xVel = 0.2;
	Vec2 position;
};