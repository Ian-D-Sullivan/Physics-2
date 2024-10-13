#pragma once

#include <array>
#include <cmath>

using namespace std;

inline float findDistance(array<float, 2> pointA, array<float, 2> pointB) {
	float dX = pointA[0] - pointB[0];
	float dY = pointA[1] - pointB[1];

	return float(sqrt(pow(dX, 2) + pow(dY, 2)));

}