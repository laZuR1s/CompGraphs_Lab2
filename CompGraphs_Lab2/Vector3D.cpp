#include "Vector3D.h"
#include <cmath>


Vector3D::Vector3D()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector3D::Vector3D(float x, float y, float z)
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

float Vector3D::Length() const
{
	return sqrt(x * x + y * y + z * z);;
}

void Vector3D::Normalize()
{
	float length = Length();
	if (length != 0)
	{
		x /= length;
		y /= length;
		z /= length;
	}
}

float Vector3D::Dot(const Vector3D & other) const
{
	return x*other.x+y*other.y+z*other.z;
}
