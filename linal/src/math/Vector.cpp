#include "../../include/Vector.hpp"

Vector::Vector(float x, float y, float z) {
	x_ = x;
	y_ = y;
	z_ = z;
}

float Vector::get_x() {
	return x_;
}

float Vector::get_y() {
	return y_;
}

float Vector::get_z() {
	return z_;
}