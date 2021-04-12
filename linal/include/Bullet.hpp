#pragma once
#include "DrawableObject.hpp"
#include "Transform.hpp"
#include "PulsatingObject.hpp"

class Bullet : public DrawableObject{
public:
	Bullet(Vector3 highestpoint, Vector3 heading, PulsatingObject& target) 
		: DrawableObject({ highestpoint, Vector3{highestpoint.x() + heading.x(),highestpoint.y() + heading.y(), highestpoint.z() + heading.z()} }, { {0, 1} }, Vector3{heading.x()/10, heading.y()/10, heading.z()/10}) {
		this->target = &target;
	};
	PulsatingObject* target;

	void CheckCollision();
private:
};