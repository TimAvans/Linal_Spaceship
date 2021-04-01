#pragma once 
#include <vector>

class Vector {
public:
	Vector(int size);
	Vector(std::initializer_list<float> values);

	std::vector<float> values;

};