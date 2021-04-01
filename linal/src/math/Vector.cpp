#include "../../include/Vector.hpp"

Vector::Vector(int size) {
	for (size_t i = 0; i < size; ++i)
	{
		values.push_back(0.0);
	}
}

Vector::Vector(std::initializer_list<float> values) {
	this->values = values;
}