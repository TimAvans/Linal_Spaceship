#pragma once
#include "Vector.hpp"

class Vector4 : public Vector {
public:
	Vector4(float x, float y, float z, float w);
	Vector4(Vector& v);
private:
	float x_;
	float y_;
	float z_;
	float w_;
};