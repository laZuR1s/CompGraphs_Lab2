#pragma once

#include "Mesh.h"
#include "Face.h"
#include "Point3D.h"
#include "Vector3D.h"

#include <Windows.h>
#include <vector>


struct Light {
	Vector3D direction;
};

class Renderer {
public:
	float angleX = 0.0f;
	float angleY = 0.0f;
	std::vector<Light> lights;

	void Render(HDC hdc,  Mesh& mesh);
};
