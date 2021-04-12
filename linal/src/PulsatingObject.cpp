#include "../include/PulsatingObject.hpp"

void PulsatingObject::pulse() {
	if (!scale_up)
	{
		scaling_vector = { 0.999, 0.999, 0.999, 0.999 };
		size--;
		if (size <= -cap)
		{
			scale_up = !scale_up;
		}
		//std::cout << scale_up << " DOWN! " << std::endl;
	}
	else{
		scaling_vector = { 1.001, 1.001, 1.001, 1.001 };
		size++;
		if (size >= cap)
		{
			scale_up = !scale_up;
		}
		//std::cout << scale_up << " UP! " << std::endl;
	}

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
		Matrix move_matrix = math_.translation_matrix(Vector4{ to_origin });
		points[i] = Vector3{ math_.multiply(Vector4{points[i]}, move_matrix) };
	}

	//Scaling
	for (int i = 0; i < points.size(); ++i)
	{
		Matrix scalingmatrix = math_.scale(scaling_vector);
		points[i] = Vector3{ math_.multiply(Vector4{points[i]}, scalingmatrix) };
	}

	//Move back
	for (int i = 0; i < points.size(); ++i)
	{
		Matrix move_matrix = math_.translation_matrix(to_origin);
		points[i] = Vector3{ math_.multiply(Vector4{points[i]}, move_matrix) };
	}

};