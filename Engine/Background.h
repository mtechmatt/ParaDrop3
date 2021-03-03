#pragma once

/* Handles background stuff (rendering wise) */

#include "Graphics.h"
#include "Colors.h"

class Background {
public:
	Background() = default;
	void Draw(Graphics& gfx);
private:
	int groundHeight = 100;
	int baseWidth = 75;
	int baseHeight = 85;
	int basePosYMid = Graphics::ScreenHeight - groundHeight + (0.5*baseHeight);
	int basePostXMid = (Graphics::ScreenWidth / 2);
};
