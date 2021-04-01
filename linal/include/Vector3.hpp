#pragma once
#include "Vector.hpp"

class Vector3 : public Vector{
public:
	Vector3(float x, float y, float z) : Vector{ x, y, z } {};
	float x() { return values[0]; };
	float y() { return values[1]; };
	float z() { return values[2]; };
private:

};