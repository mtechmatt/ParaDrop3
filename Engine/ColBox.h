#pragma once

class ColBox {
	ColBox(int t, int b, int l, int r) {
		top = t;
		bottom = b;
		left = l;
		right = r;
}
public:
	int top;
	int bottom;
	int left;
	int right;
};