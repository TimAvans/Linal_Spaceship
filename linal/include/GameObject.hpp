#pragma once
#include <vector>
#include "Vector3.hpp"
#include <iostream>

class GameObject{
public:
	GameObject(std::vector<Vector3> points) {
		this->points = points;
	};	
	GameObject() {
	};

	std::vector<Vector3> points;

	virtual void move(bool isPosMovement);

private:

};