#pragma once
#include <vector>
#include <iostream>
#include "Vector3.hpp"
#include "GameObject.hpp"
#include "Transform.hpp"

class DrawableObject : public GameObject {
public:
	DrawableObject(std::vector<Vector4> points, std::vector<std::pair<int, int>> lines, Vector3 heading) : GameObject(points) {
		this->lines = lines; 
		this->heading = heading;
	};	
	DrawableObject() {};

	//Indices from the points vector
	std::vector<std::pair<int, int>> lines;
	Transform math_;
	Vector3 heading;

	void rotate_object(Vector3 rotation_vector);
	void move(bool isPosMovement) override;
private:
};