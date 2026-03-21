#include "Face.h"
#include "MathUtils.h"

void Face::CalculateNormal(const std::vector<Point3D>& vertices)
{
	if (indices.size() < 3)
		return;

	Point3D p0 = vertices[indices[0]];
	Point3D p1 = vertices[indices[1]];
	Point3D p2 = vertices[indices[2]];

	Vector3D v1 = MathUtils::Subtract(p1, p0);
	Vector3D v2 = MathUtils::Subtract(p2, p0);

	normal.x = v1.y * v2.z - v1.z * v2.y;
	normal.y = v1.z * v2.x - v1.x * v2.z;
	normal.z = v1.x * v2.y - v1.y * v2.x;

	normal.Normalize();
}
