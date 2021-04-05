#pragma once
#include <vector>
#include "Vector3.hpp"

class DrawableObject {
public:
	DrawableObject(std::vector<Vector3> points, std::vector<std::pair<int, int>> lines, Vector3 heading) {
		this->lines = lines; this->points = points; this->heading = heading;
	};	
	DrawableObject() {};
	//All points from the drawableobject
	std::vector<Vector3> points;
	//Indices from the points vector
	std::vector<std::pair<int, int>> lines;

	Vector3 heading;

	void rotate_object(Vector3 rotation_vector);
	void move(bool isPosMovement);
private:
};