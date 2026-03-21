#pragma once
#include "Point3D.h"
#include "Vector3D.h"
#include <vector>

class Face {
public:
	std::vector<int> indices;
	Vector3D normal;

	void CalculateNormal(const std::vector<Point3D>& vertices);
};