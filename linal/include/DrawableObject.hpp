#pragma once
#include <vector>
#include "Vector3.hpp"

class DrawableObject {
public:
	DrawableObject(std::vector<Vector3> points, std::vector<std::pair<int, int>> lines) {
		this->lines = lines; this->points = points;
	};	
	DrawableObject() {};
	//All points from the drawableobject
	std::vector<Vector3> points;
	//Indices from the points vector
	std::vector<std::pair<int, int>> lines;
private:
};