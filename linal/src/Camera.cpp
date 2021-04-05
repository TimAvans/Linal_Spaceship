#include "../include/Camera.hpp"

Vector4 Camera::calculate_up() {
	return Transform::multiply(direction, right);
};

Vector4 Camera::calculate_right() {
	return Transform::multiply(up, direction);

};

Vector4 Camera::calculate_direction() {
	return Transform::subtract(eye, lookat);
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

Matrix Camera::translated_to_O() {
	Matrix m1;
	m1._14 = eye.x() * -1;
	m1._24 = eye.y() * -1;
	m1._34 = eye.z() * -1;

	return Transform::multiply(inverted_translation_matrix(), m1);
};