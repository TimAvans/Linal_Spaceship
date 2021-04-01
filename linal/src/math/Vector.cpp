#include "../../include/Vector.hpp"

Vector::Vector() {
	for (int i = 0; i < 4; ++i)
	{
		values.push_back(0.0f);
	}
}

Vector::Vector(std::initializer_list<float> values) {
	this->values = values;
}