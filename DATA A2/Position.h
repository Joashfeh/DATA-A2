#pragma once

struct Position {
	float x;
	float y;

	Position() {
		x = 0;
		y = 0;
	}

	Position(float x, float y) {
		this->x = x;
		this->y = y;
	}

	void Set(float x, float y) {
		this->x = x;
		this->y = y;
	}
};