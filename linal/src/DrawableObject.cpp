#include "../include/DrawableObject.hpp"
#include "../include/Transform.hpp"
#include <iostream>

void DrawableObject::rotate_object() {
	for(int i = 0; i < points.size(); ++i)
	{
		Matrix rotationmatrix = Transform::rotate(Vector4(points[i]), 0.01, 0.01, 0.01, true);
		points[i] = Vector3{ Transform::multiply(Vector4{points[i]}, rotationmatrix) };

		std::cout << points[i].x() << ", " << points[i].y() << ", " << points[i].z() <<std::endl;
	}
	std::cout << "---------";
}