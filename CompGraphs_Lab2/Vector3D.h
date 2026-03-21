#pragma once


class Vector3D {
public:
	float x, y, z;

	Vector3D();
	Vector3D(float x, float y, float z);

	float Length() const;
	void Normalize();

	float Dot(const Vector3D& other) const;
}