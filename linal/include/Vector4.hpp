#pragma once
#include "Vector.hpp"

class Vector4 : public Vector {
public:
	Vector4(float x, float y, float z, float w) : Vector{ x, y, z, w } {}
	Vector4(Vector v) : Vector{ v.values[0], v.values[1], v.values[2], 1 } {};
	Vector4(int i) : Vector{} {};

	float x() { return values[0]; };
	float y() { return values[1]; };
	float z() { return values[2]; };
	float w() { return values[3]; };
private:

};