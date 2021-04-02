#include "../include/DrawableObject.hpp"
#include "../include/Transform.hpp"
#include <iostream>

void DrawableObject::rotate_object(Vector3 rotation_vector) {
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
	Matrix rotationmatrix = Transform::rotate(rotation_vector.x(), rotation_vector.y(), rotation_vector.z(), true);

	for(int i = 0; i < points.size(); ++i)
	{
		points[i] = Vector3{ Transform::multiply(Vector4{points[i]}, rotationmatrix) };

		std::cout << points[i].x() << ", " << points[i].y() << ", " << points[i].z() <<std::endl;
	}
	heading = Vector3{ Transform::multiply(Vector4{heading}, rotationmatrix) };
	Transform::normalize(heading);

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

void DrawableObject::move(Vector3 movement_vector) {

	Vector4 scaling_vector{ (movement_vector.z() / 10) + 1, (movement_vector.z() / 10) + 1, (movement_vector.z() / 10) + 1, 1 };

	//Move to origin
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
	for (int i = 0; i < points.size(); ++i)
	{
		Matrix move_matrix = Transform::move_to_origin(Vector4(points[i]), Vector4{ to_origin });
		points[i] = Vector3{ Transform::multiply(Vector4{points[i]}, move_matrix) };
	}

	if (movement_vector.z() != 0) {
		//Scaling
		for (int i = 0; i < points.size(); ++i)
		{
			Matrix scalingmatrix = Transform::scale(scaling_vector);
			points[i] = Vector3{ Transform::multiply(Vector4{points[i]}, scalingmatrix) };

		}
	}

	for (int i = 0; i < to_origin.values.size(); ++i)
	{
		to_origin.values[i] *= -1;
	}

	//Move back
	for (int i = 0; i < points.size(); ++i)
	{
		Matrix move_matrix = Transform::move_to_origin(Vector4(points[i]), to_origin);
		points[i] = Vector3{ Transform::multiply(Vector4{points[i]}, move_matrix) };
		std::cout << points[i].x() << ", " << points[i].y() << ", " << points[i].z() << std::endl;
	}

	//Movement
	for (int i = 0; i < points.size(); ++i)
	{
		Matrix move_matrix = Transform::move(Vector4(points[i]), Vector4{ movement_vector.x(), movement_vector.y(), movement_vector.z(), 1 });
		points[i] = Vector3{ Transform::multiply(Vector4{points[i]}, move_matrix) };

		std::cout << points[i].x() << ", " << points[i].y() << ", " << points[i].z() << std::endl;
	}

	std::cout << "---------" <<std::endl;
}
