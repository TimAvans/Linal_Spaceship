#include "../include/DrawableObject.hpp"
#include "../include/Transform.hpp"
#include <iostream>

void DrawableObject::rotate_object() {
	//Calculate the middle of our object and create vector to the origin
	Vector3 to_origin{ 0, 0, 0 };
	for (int i = 0; i < points.size(); ++i)
	{
		to_origin.values[0] += points[i].x();
		to_origin.values[1] += points[i].y();
		to_origin.values[2] += points[i].z();
	}
	for (int i = 0; i < to_origin.values.size(); ++i)
	{
		to_origin.values[i] /= points.size();
		to_origin.values[i] *= -1;
	}

	//Move to origin
	for (int i = 0; i < points.size(); ++i)
	{
		Matrix move_matrix = Transform::move_to_origin(Vector4(points[i]), Vector4{to_origin});
		points[i] = Vector3{ Transform::multiply(Vector4{points[i]}, move_matrix) };
	}

	//Rotate
	for(int i = 0; i < points.size(); ++i)
	{
		Matrix rotationmatrix = Transform::rotate(Vector4(points[i]), 0.1, 0.1, 0.1, true);
		points[i] = Vector3{ Transform::multiply(Vector4{points[i]}, rotationmatrix) };

		std::cout << points[i].x() << ", " << points[i].y() << ", " << points[i].z() <<std::endl;
	}

	for (int i = 0; i < to_origin.values.size(); ++i)
	{
		to_origin.values[i] *= -1;
	}

	//Move back to original points
	for (int i = 0; i < points.size(); ++i)
	{
		Matrix move_matrix = Transform::move_to_origin(Vector4(points[i]), to_origin);
		points[i] = Vector3{ Transform::multiply(Vector4{points[i]}, move_matrix) };
	}

	std::cout << "---------";
}

void DrawableObject::move() {

	//Move to origin
	//Scaling
	//Move back
	//Movement

	for (int i = 0; i < points.size(); ++i)
	{
		Matrix move_matrix = Transform::move(Vector4(points[i]), Vector4{0.1, 0.1, 0.1, 1});
		points[i] = Vector3{ Transform::multiply(Vector4{points[i]}, move_matrix) };

		std::cout << points[i].x() << ", " << points[i].y() << ", " << points[i].z() << std::endl;
	}
	std::cout << "---------";
}
