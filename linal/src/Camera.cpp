#include "../include/Camera.hpp"

void Camera::calculate_up() {
	up = Transform::multiply(direction, right);
};

void Camera::calculate_right() {
	right = Transform::multiply(up, direction);

};

void Camera::calculate_direction() {
	direction = Transform::subtract(points[0], lookat);
};

Matrix Camera::inverted_translation_matrix() {
	Matrix m1;
	m1._11 = right.x();
	m1._12 = right.y();
	m1._13 = right.z();

	m1._21 = up.x();
	m1._22 = up.y();
	m1._23 = up.z();	

	m1._31 = direction.x();
	m1._32 = direction.y();
	m1._33 = direction.z();
	
	return m1;
};

Matrix Camera::translation_matrix() {
	Matrix m1;
	m1._11 = right.x();
	m1._12 = up.y();
	m1._13 = direction.z();

	m1._21 = right.x();
	m1._22 = up.y();
	m1._23 = direction.z();

	m1._31 = right.x();
	m1._32 = up.y();
	m1._33 = direction.z();

	return m1;
};

Matrix Camera::translated_to_O() {
	Matrix m1;
	m1._14 = points[0].x() * -1;
	m1._24 = points[0].y() * -1;
	m1._34 = points[0].z() * -1;

	return Transform::multiply(inverted_translation_matrix(), m1);
};

void Camera::move(bool isPosMovement) {
	points[0].values[0] += speed;
	lookat.values[0] += speed;
}