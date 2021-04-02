#pragma once 
#include <vector>

class Vector {
public:
	Vector();
	Vector(std::initializer_list<float> values);

	std::vector<float> values;

};