#pragma once
#include "DrawableObject.hpp"
#include "Bullet.hpp"

class Ship : public DrawableObject{
public:
	Ship(std::vector<Vector4> points, std::vector<std::pair<int, int>> lines, Vector3 heading) 
		: DrawableObject(points, lines, heading) {};

	Bullet shoot_bullet();
private:

};