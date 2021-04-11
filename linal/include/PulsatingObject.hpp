#pragma once
#include "DrawableObject.hpp"
#include "Vector3.hpp"
#include <vector>

class PulsatingObject : public DrawableObject{
public:
	PulsatingObject(std::vector<Vector4> points, std::vector<std::pair<int, int>> lines, Vector3 heading) : DrawableObject(points, lines, heading) {};
	void pulse();
private:
	int size = 0;
	int cap = 1000;
	bool scale_up = true;
	Vector4 scaling_vector{ 1.0001, 1.0001, 1.0001, 1.0001 };
	Transform tf{};
};