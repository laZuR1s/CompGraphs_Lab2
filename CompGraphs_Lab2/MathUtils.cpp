#include "MathUtils.h"
#include <cmath>

Point3D MathUtils::RotateX(const Point3D& p, float angle)
{
	Point3D result;
	result.x = p.x;
	result.y = p.y * cos(angle) - p.z * sin(angle);
	result.z = p.y * sin(angle) + p.z * cos(angle);

	return result;
}

Point3D MathUtils::RotateY(const Point3D& p, float angle)
{
	Point3D result;
	result.x = p.x * cos(angle) + p.z * sin(angle);
	result.y = p.y;
	result.z = -p.x * sin(angle) + p.z * cos(angle);

	return result;
}

Point3D MathUtils::RotateZ(const Point3D& p, float angle)
{
	Point3D result;
	result.x = p.x * cos(angle) - p.y * sin(angle);
	result.y = p.x * sin(angle) + p.y * cos(angle);
	result.z = p.z;

	return result;
}

Vector3D MathUtils::Subtract(const Point3D& a, const Point3D& b)
{
	return Vector3D(
		a.x - b.x,
		a.y - b.y,
		a.z - b.z
	);
}
