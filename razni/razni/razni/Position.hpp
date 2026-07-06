#pragma once
#include <cmath>

struct Position {
	int x;
	int y;
};

inline bool areNeightboors(const Position& p1, const Position& p2) {
	return std::abs(p1.x - p2.x) == 1 && std::abs(p1.y - p2.y) == 1;
}