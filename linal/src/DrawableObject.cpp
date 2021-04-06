#include "../include/DrawableObject.hpp"

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
		Matrix move_matrix = math_.move_to_origin(Vector4(points[i]), Vector4{ to_origin });
		points[i] = Vector3{ math_.multiply(Vector4{points[i]}, move_matrix) };
	}

	//Rotate
	Matrix rotationmatrix = math_.rotate(rotation_vector.x(), rotation_vector.y(), rotation_vector.z(), true);

	for (int i = 0; i < points.size(); ++i)
	{
		points[i] = Vector3{ math_.multiply(Vector4{points[i]}, rotationmatrix) };
	}

	heading = Vector3{ math_.multiply(Vector4{heading}, rotationmatrix) };
	math_.normalize(Vector4{ heading });

	for (int i = 0; i < to_origin.values.size(); ++i)
	{
		to_origin.values[i] *= -1;
	}

	//Move back to original points
	for (int i = 0; i < points.size(); ++i)
	{
		Matrix move_matrix = math_.move_to_origin(Vector4(points[i]), to_origin);
		points[i] = Vector3{ math_.multiply(Vector4{points[i]}, move_matrix) };
	}
}

void DrawableObject::move(bool isPosMovement) {

	Vector4 rel_heading{ 4 };
	if (!isPosMovement) {
		rel_heading = math_.multiply(heading, -1);
	}
	else {
		rel_heading = heading;
	}

	Vector4 scaling_vector{ (rel_heading.z() / 10) + 1, (rel_heading.z() / 10) + 1, (rel_heading.z() / 10) + 1, 1 };

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
		Matrix move_matrix = math_.move_to_origin(Vector4(points[i]), Vector4{ to_origin });
		points[i] = Vector3{ math_.multiply(Vector4{points[i]}, move_matrix) };
	}

	if (rel_heading.z() != 0) {
		//Scaling
		for (int i = 0; i < points.size(); ++i)
		{
			Matrix scalingmatrix = math_.scale(scaling_vector);
			points[i] = Vector3{ math_.multiply(Vector4{points[i]}, scalingmatrix) };
		}
	}

	for (int i = 0; i < to_origin.values.size(); ++i)
	{
		to_origin.values[i] *= -1;
	}

	//Move back
	for (int i = 0; i < points.size(); ++i)
	{
		Matrix move_matrix = math_.move_to_origin(Vector4(points[i]), to_origin);
		points[i] = Vector3{ math_.multiply(Vector4{points[i]}, move_matrix) };
	}

	//Movement
	for (int i = 0; i < points.size(); ++i)
	{
		Matrix move_matrix = math_.move(Vector4(points[i]), Vector4(rel_heading));

		points[i] = Vector3{ math_.multiply(Vector4{points[i]}, move_matrix) };
	}

}
