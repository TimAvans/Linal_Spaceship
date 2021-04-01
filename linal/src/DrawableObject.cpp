#include "../include/DrawableObject.hpp"
#include "../include/Transform.hpp"
#include <iostream>

void DrawableObject::rotate_object() {
	for(int i = 0; i < points.size(); ++i)
	{
		points[i] = Transform::rotate(Vector4(points[i]), 10, true);

		/*	Vector4 a = Transform::multiply(vector, vector2);*/

		// std::cout << a.x() << a.y() << a.z() << a.w() << std::endl;
		std::cout << points[i].x() << ", " << points[i].y() << ", " << points[i].z() <<std::endl;
	}
	std::cout << "---------";
}