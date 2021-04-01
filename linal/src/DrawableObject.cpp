#include "../include/DrawableObject.hpp"
#include "../include/Transform.hpp"
#include <iostream>

void DrawableObject::rotate_object() {
	for(int i = 0; i < points.size(); ++i)
	{
		points[i] = Transform::rotate_x(Vector4(points[i]), 360, true);

		std::cout << points[i].x() << ", " << points[i].y() << ", " << points[i].z() <<std::endl;
	}
	std::cout << "---------";
}