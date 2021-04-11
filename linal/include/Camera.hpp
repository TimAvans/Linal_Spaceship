#pragma once
#include "Vector4.hpp"
#include "Transform.hpp"
#include "GameObject.hpp"

class Camera : public GameObject{
public:
	Camera() : GameObject( { Vector4{ 0, 0, -10, 1 } }) {
		projection_matrix._11 = scale_;
		projection_matrix._22 = scale_;
		projection_matrix._33 = -far_ / (far_ - near_);
		projection_matrix._34 = -1;
		projection_matrix._43 = (-far_ * near_) / (far_ - near_);
		projection_matrix._44 = 0;


		direction = math.subtract(points[0], lookat);

		math.normalize(direction);

		up = { 0, 1, 0, 1 };

		right = math.multiply(up, direction);

		math.normalize(right);

		calculate_up();	

		math.normalize(up);
	};

	Transform math;

	Vector4 lookat{0, 0, 10, 1};
	Vector4 direction{4};
	Vector4 up{4};
	Vector4 right{4};

	float far_ = 1000;
	float near_ = 10;
	float a_ = 90;
	float scale_ = near_ * tan(a_ * 0.5);

	Matrix projection_matrix;

	void calculate_up();
	void calculate_right();
	void calculate_direction();

	Matrix inverted_translation_matrix();
	Matrix translation_matrix();
	Matrix translated_to_O();

	void move(bool isPosMovement) override;
private:
	float speed = 5.0f;
};