#pragma once

#include<vector>
#include "Point3D.h"
#include "Face.h"

class Mesh {
public: 
	std::vector<Point3D> vertices;
	std::vector<Face> faces;

	void GenerateHemisphere(float radius, int slices, int stacks , float angleLimit);
};
