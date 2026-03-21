#include "Mesh.h"
#include <cmath>

void Mesh::GenerateHemisphere(float radius, int slices, int stacks, float angleLimit)
{
	vertices.clear();
	faces.clear();

	float pi = 3.1415926f;

	float maxPhi = angleLimit * pi / 180.0f;

	for (int i = 0; i <= stacks; i++)
	{
		float phi = maxPhi * i / stacks;
		for (int j = 0; j <= slices; j++)
		{
			float theta = 2 * pi * j / slices;

			float x = radius * sin(phi) * cos(theta);
			float y = radius * cos(phi);
			float z = radius * sin(phi) * sin(theta);

			vertices.push_back(Point3D(x, y, z));
		}
	}

	for (int i = 0; i < stacks; i++)
	{
		for (int j = 0; j < slices; j++)
		{
			int first = i * (slices + 1) + j;
			int second = first + slices + 1;

			Face f1;
			f1.indices = { first, second, first + 1 };

			Face f2;
			f2.indices = { second, second + 1, first + 1 };

			faces.push_back(f1);
			faces.push_back(f2);
		}
	}
}
