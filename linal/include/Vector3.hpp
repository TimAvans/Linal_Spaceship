#pragma once
#include "Vector.hpp"
#include "Vector4.hpp"

class Vector3 : public Vector{
public:
	Vector3(float x, float y, float z) : Vector{ x, y, z } {};
	Vector3(Vector vec) : Vector{ vec.values[0], vec.values[1], vec.values[2] } {};
	float x() { return values[0]; };
	float y() { return values[1]; };
	float z() { return values[2]; };
private:

};