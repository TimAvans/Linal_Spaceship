#include "../../include/Transform.hpp"
#include <cmath>
#include <iostream>

Matrix Transform::multiply(Matrix m2, Matrix m1) {
	Matrix matrix;

	//first row
	matrix._11 = (m1._11 * m2._11) + (m1._12 * m2._21) + (m1._13 * m2._31) + (m1._14 * m2._41);
	matrix._12 = (m1._11 * m2._12) + (m1._12 * m2._22) + (m1._13 * m2._32) + (m1._14 * m2._42);
	matrix._13 = (m1._11 * m2._13) + (m1._12 * m2._23) + (m1._13 * m2._33) + (m1._14 * m2._43);
	matrix._14 = (m1._11 * m2._14) + (m1._12 * m2._24) + (m1._13 * m2._34) + (m1._14 * m2._44);

	//second
	matrix._21 = (m1._21 * m2._11) + (m1._22 * m2._21) + (m1._23 * m2._31) + (m1._24 * m2._41);
	matrix._22 = (m1._21 * m2._12) + (m1._22 * m2._22) + (m1._23 * m2._32) + (m1._24 * m2._42);
	matrix._23 = (m1._21 * m2._13) + (m1._22 * m2._23) + (m1._23 * m2._33) + (m1._24 * m2._43);
	matrix._24 = (m1._21 * m2._14) + (m1._22 * m2._24) + (m1._23 * m2._34) + (m1._24 * m2._44);

	//third
	matrix._31 = (m1._31 * m2._11) + (m1._32 * m2._21) + (m1._33 * m2._31) + (m1._34 * m2._41);
	matrix._32 = (m1._31 * m2._12) + (m1._32 * m2._22) + (m1._33 * m2._32) + (m1._34 * m2._42);
	matrix._33 = (m1._31 * m2._13) + (m1._32 * m2._23) + (m1._33 * m2._33) + (m1._34 * m2._43);
	matrix._34 = (m1._31 * m2._14) + (m1._32 * m2._24) + (m1._33 * m2._34) + (m1._34 * m2._44);

	//fourth
	matrix._41 = (m1._41 * m2._11) + (m1._42 * m2._21) + (m1._43 * m2._31) + (m1._44 * m2._41);
	matrix._42 = (m1._41 * m2._12) + (m1._42 * m2._22) + (m1._43 * m2._32) + (m1._44 * m2._42);
	matrix._43 = (m1._41 * m2._13) + (m1._42 * m2._23) + (m1._43 * m2._33) + (m1._44 * m2._43);
	matrix._44 = (m1._41 * m2._14) + (m1._42 * m2._24) + (m1._43 * m2._34) + (m1._44 * m2._44);

	return matrix;
}

Vector4 Transform::multiply(Vector4 m2, Matrix m1) {
	Vector4 v4{4};

	//first row
	v4.values[0] = (m1._11 * m2.x()) + (m1._12 * m2.y()) + (m1._13 * m2.z()) + (m1._14 * m2.w());
	v4.values[1] = (m1._21 * m2.x()) + (m1._22 * m2.y()) + (m1._23 * m2.z()) + (m1._24 * m2.w());
	v4.values[2] = (m1._31 * m2.x()) + (m1._32 * m2.y()) + (m1._33 * m2.z()) + (m1._34 * m2.w());
	v4.values[3] = (m1._41 * m2.x()) + (m1._42 * m2.y()) + (m1._43 * m2.z()) + (m1._44 * m2.w());

	return v4;
}

Matrix Transform::rotate(Vector4 vec, float radian_x, float radian_y, float radian_z, bool pos) {
	
	Matrix mx;
	mx._11 = 1; mx._12 = 0; mx._13 = 0; mx._14 = 0;
	mx._21 = 0; mx._22 = cos(radian_x); mx._23 = -sin(radian_x); mx._24 = 0;
	mx._31 = 0; mx._32 = sin(radian_x); mx._33 = cos(radian_x); mx._34 = 0;
	mx._41 = 0; mx._42 = 0; mx._43 = 0; mx._44 = 1;	
	
	Matrix my;
	my._11 = cos(radian_y); my._12 = 0; my._13 = sin(radian_y); my._14 = 0;
	my._21 = 0; my._22 = 1; my._23 = 0; my._24 = 0;
	my._31 = -sin(radian_y); my._32 = 0; my._33 = cos(radian_y); my._34 = 0;
	my._41 = 0; my._42 = 0; my._43 = 0; my._44 = 1;
	
	Matrix mz;
	mz._11 = cos(radian_z); mz._12 = -sin(radian_z); mz._13 = 0; mz._14 = 0;
	mz._21 = sin(radian_z); mz._22 = cos(radian_z); mz._23 = 0; mz._24 = 0;
	mz._31 = 0; mz._32 = 0; mz._33 = 1; mz._34 = 0;
	mz._41 = 0; mz._42 = 0; mz._43 = 0; mz._44 = 1;

	auto r1 = multiply(mz, my);
	auto r2 = multiply(r1, mx);

	return r2;
}


//SCALING!!!!!!!!!!!!!!!!!!!!
Matrix Transform::move(Vector4 vec, Vector4 move_vec) {
	Matrix current;
	current._14 = vec.x();
	current._24 = vec.y();
	current._34 = vec.z();
	current._44 = vec.w();

	Matrix scaling;
	scaling._11 = move_vec.x();
	scaling._22 = move_vec.y();
	scaling._33 = move_vec.z();
	scaling._44 = 1;

	//auto scaled = multiply(transmov, scaling);

	return multiply(current, scaling);
}

Matrix Transform::move_to_origin(Vector4 vec, Vector4 to_origin) {
	Matrix transmov;
	transmov._14 = to_origin.x();
	transmov._24 = to_origin.y();
	transmov._34 = to_origin.z();
	transmov._44 = to_origin.w();

	return transmov;
}