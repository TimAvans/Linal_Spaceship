#pragma once
#include <vector>
#include "Vector3.hpp"
#include <iostream>

class GameObject{
public:
	GameObject(std::vector<Vector4> points) {
		this->points = points;
	};	
	GameObject() {
	};

	std::vector<Vector4> points;

	virtual void move(bool isPosMovement) = 0;

	bool shouldDraw = true;
	bool shouldRemove = false;
private:
};