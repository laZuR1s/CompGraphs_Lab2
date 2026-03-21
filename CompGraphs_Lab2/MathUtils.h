#pragma once

#include "Point3D.h"
#include "Vector3D.h"


class MathUtils {
public:
	static Point3D RotateX(const Point3D& p, float angle);
	static Point3D RotateY(const Point3D& p, float angle);
	static Point3D RotateZ(const Point3D& p, float angle);

	static Vector3D Subtract(const Point3D& a, const Point3D& b);
};