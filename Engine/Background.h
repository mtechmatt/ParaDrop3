#pragma once

/* Handles background stuff (rendering wise) */

#include "Graphics.h"
#include "Colors.h"

class Background {
public:
	Background() = default;
	void Draw(Graphics& gfx);
	static constexpr int groundHeight = 100;
	static constexpr int baseWidth = 75;
	int baseHeight = 85;
	int basePosYMid = Graphics::ScreenHeight - groundHeight + (0.5f*baseHeight);
	int basePostXMid = (Graphics::ScreenWidth / 2);
private:

};
