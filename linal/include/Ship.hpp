#pragma once
#include "DrawableObject.hpp"
#include "PulsatingObject.hpp"
#include "Bullet.hpp"

class Ship : public DrawableObject {
public:
	Ship(std::vector<Vector4> points, std::vector<std::pair<int, int>> lines, Vector3 heading)
		: DrawableObject(points, lines, heading) {
	//	colliding_points.push_back(Vector4{ 10, 10, 12, 1 });
	//	colliding_points.push_back(Vector4{ 10, 17.5, 12, 1 });
	//	colliding_points.push_back(Vector4{ 15, 17.5, 12, 1 });
	//	colliding_points.push_back(Vector4{ 15, 10, 12, 1 });
	//	colliding_points.push_back(Vector4{ 10, 10, 13, 1 });
	//	colliding_points.push_back(Vector4{ 10, 17.5, 13, 1 });
	//	colliding_points.push_back(Vector4{ 15, 17.5, 13, 1 });
	//	colliding_points.push_back(Vector4{ 15, 10, 13, 1 });
	};

	Bullet* shoot_bullet();
private:

};