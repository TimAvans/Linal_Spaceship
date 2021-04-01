#include "../../include/Transform.hpp"
#include <cmath>
#include <iostream>

//Matrix Transform::addition(Matrix m1, Matrix m2) {
//}
//
//Matrix Transform::subtraction(Matrix m1, Matrix m2) {
//}

Matrix Transform::multiply(Matrix m2, Matrix m1, bool m) {
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

	//std::cout << matrix._11 << "," << matrix._12 << "," << matrix._13 << "," << matrix._14 << std::endl;
	//std::cout << matrix._21 << "," << matrix._22 << "," << matrix._23 << "," << matrix._24 << std::endl;
	//std::cout << matrix._31 << "," << matrix._32 << "," << matrix._33 << "," << matrix._34 << std::endl;
	//std::cout << matrix._41 << "," << matrix._42 << "," << matrix._43 << "," << matrix._44 << std::endl;

	//std::cout << matrix._14 << "," << matrix._24 << "," << matrix._34 << "," << matrix._44 << std::endl;


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

Vector4 Transform::multiply(Matrix m2, Matrix m1) {
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

	//std::cout << matrix._11 << "," << matrix._12 << "," << matrix._13 << "," << matrix._14 << std::endl;
	//std::cout << matrix._21 << "," << matrix._22 << "," << matrix._23 << "," << matrix._24 << std::endl;
	//std::cout << matrix._31 << "," << matrix._32 << "," << matrix._33 << "," << matrix._34 << std::endl;
	//std::cout << matrix._41 << "," << matrix._42 << "," << matrix._43 << "," << matrix._44 << std::endl;

	//std::cout << matrix._14 << "," << matrix._24 << "," << matrix._34<< "," <<matrix._44 << std::endl;
	
	
	return Vector4{matrix._14, matrix._24, matrix._34, matrix._44};
}
/*
	vector x matrix
	float x = m1.x() * m2._11 + m1.y() * m2._12 + m1.y() * m2._13 + m1.y() * m2._14;
	float y = m1.x() * m2._21 + m1.y() * m2._22 + m1.z() * m2._23 + m1.w() * m2._24;
	float z = m1.x() * m2._31 + m1.y() * m2._32 + m1.z() * m2._33 + m1.w() * m2._34;
	float w = m1.x() * m2._41 + m1.y() * m2._42 + m1.z() * m2._43 + m1.w() * m2._44;

	return { x, y, z, w };

*/
//Matrix Transform::inverse(Matrix m1) {
//
//}

Vector3 Transform::rotate_x(Vector4 vec, int degrees, bool pos) {

	Matrix vector;
	vector._14 = vec.x();
	vector._24 = vec.y();
	vector._34 = vec.z();
	vector._44 = vec.w();

	Matrix mxp;
	mxp._11 = 1; mxp._12 = 0; mxp._13 = 0; mxp._14 = 0;
	mxp._21 = 0; mxp._22 = cos(degrees); mxp._23 = -sin(degrees); mxp._24 = 0;
	mxp._31 = 0; mxp._32 = sin(degrees); mxp._33 = cos(degrees); mxp._34 = 0;
	mxp._41 = 0; mxp._42 = 0; mxp._43 = 0; mxp._44 = 1;	
	
	Matrix mxn;
	mxp._11 = 1; mxp._12 = 0; mxp._13 = 0; mxp._14 = 0;
	mxp._21 = 0; mxp._22 = cos(degrees); mxp._23 = sin(degrees); mxp._24 = 0;
	mxp._31 = 0; mxp._32 = -sin(degrees); mxp._33 = cos(degrees); mxp._34 = 0;
	mxp._41 = 0; mxp._42 = 0; mxp._43 = 0; mxp._44 = 1;

	Vector4 vec4 = multiply(vector, mxp);

	//pos ? vec = multiply(vector, mxp) : vec = multiply(vector, mxn);
	return Vector3(vec4);
}

Vector3 Transform::rotate_y(Vector4 vec, int degrees, bool pos) {

	Matrix vector;
	vector._14 = vec.x();
	vector._24 = vec.y();
	vector._34 = vec.z();
	vector._44 = vec.w();

	Matrix mxp;
	mxp._11 = cos(degrees); mxp._12 = 0; mxp._13 = sin(degrees); mxp._14 = 0;
	mxp._21 = 0; mxp._22 = 1; mxp._23 = 0; mxp._24 = 0;
	mxp._31 = -sin(degrees); mxp._32 = 0; mxp._33 = cos(degrees); mxp._34 = 0;
	mxp._41 = 0; mxp._42 = 0; mxp._43 = 0; mxp._44 = 1;	

	Vector4 vec4 = multiply(vector, mxp);

	//pos ? vec = multiply(vector, mxp) : vec = multiply(vector, mxn);
	return Vector3(vec4);
}

Vector3 Transform::rotate_z(Vector4 vec, int degrees, bool pos) {

	Matrix vector;
	vector._14 = vec.x();
	vector._24 = vec.y();
	vector._34 = vec.z();
	vector._44 = vec.w();

	Matrix mxp;
	mxp._11 = cos(degrees); mxp._12 = -sin(degrees); mxp._13 = 0; mxp._14 = 360;
	mxp._21 = sin(degrees); mxp._22 = cos(degrees); mxp._23 = 0; mxp._24 = 360;
	mxp._31 = 0; mxp._32 = 0; mxp._33 = 1; mxp._34 = 60;
	mxp._41 = 0; mxp._42 = 0; mxp._43 = 0; mxp._44 = 1;	

	Vector4 vec4 = multiply(vector, mxp);

	//pos ? vec = multiply(vector, mxp) : vec = multiply(vector, mxn);
	return Vector3(vec4);
}

Vector3 Transform::rotate(Vector4 vec, int degrees, bool pos) {

	Matrix vectort;
	vectort._14 = vec.x() * -1;
	vectort._24 = vec.y() * -1;
	vectort._34 = vec.z() * -1;
	vectort._44 = vec.w();	
	
	Matrix vector;
	vector._14 = vec.x();
	vector._24 = vec.y();
	vector._34 = vec.z();
	vector._44 = vec.w();

	Matrix m1;
	m1._11 = vec.x() / sqrt((vec.x() * vec.x()) + (vec.z() * vec.z()));
	m1._13 = vec.z() / sqrt((vec.x() * vec.x()) + (vec.z() * vec.z()));
	m1._31 = (vec.z() / sqrt((vec.x() * vec.x()) + (vec.z() * vec.z()))) * -1;
	m1._33 = vec.x() / sqrt((vec.x() * vec.x()) + (vec.z() * vec.z()));

	Matrix m2;
	m2._11 = sqrt((vec.x() * vec.x()) + (vec.z() * vec.z())) / sqrt((vec.x() * vec.x()) + (vec.y() * vec.y()) + (vec.z() * vec.z()));
	m2._12 = vec.y() / sqrt((vec.x() * vec.x()) + (vec.y() * vec.y()) + (vec.z() * vec.z()));
	m2._21 = (vec.y() / sqrt((vec.x() * vec.x()) + (vec.y() * vec.y()) + (vec.z() * vec.z()))) * -1;
	m2._22 = sqrt((vec.x() * vec.x()) + (vec.z() * vec.z())) / sqrt((vec.x() * vec.x()) + (vec.y() * vec.y()) + (vec.z() * vec.z()));

	Matrix m3;
	m3._11 = 1; m3._12 = 0; m3._13 = 0; m3._14 = 0;
	m3._21 = 0; m3._22 = cos(degrees); m3._23 = -sin(degrees); m3._24 = 0;
	m3._31 = 0; m3._32 = sin(degrees); m3._33 = cos(degrees); m3._34 = 0;
	m3._41 = 0; m3._42 = 0; m3._43 = 0; m3._44 = 1;

	Matrix m4;
	m2._11 = sqrt((vec.x() * vec.x()) + (vec.z() * vec.z())) / sqrt((vec.x() * vec.x()) + (vec.y() * vec.y()) + (vec.z() * vec.z()));
	m2._12 = (vec.y() / sqrt((vec.x() * vec.x()) + (vec.y() * vec.y()) + (vec.z() * vec.z()))) * -1;
	m2._21 = vec.y() / sqrt((vec.x() * vec.x()) + (vec.y() * vec.y()) + (vec.z() * vec.z()));
	m2._22 = sqrt((vec.x() * vec.x()) + (vec.z() * vec.z())) / sqrt((vec.x() * vec.x()) + (vec.y() * vec.y()) + (vec.z() * vec.z()));

	Matrix m5;
	m1._11 = vec.x() / sqrt((vec.x() * vec.x()) + (vec.z() * vec.z()));
	m1._13 = (vec.z() / sqrt((vec.x() * vec.x()) + (vec.z() * vec.z()))) * -1;
	m1._31 = vec.z() / sqrt((vec.x() * vec.x()) + (vec.z() * vec.z()));
	m1._33 = vec.x() / sqrt((vec.x() * vec.x()) + (vec.z() * vec.z()));

	auto r1 = multiply(vector, m5, true);
	auto r2 = multiply(r1, m4, true);
	auto r3 = multiply(r2, m3, true);
	auto r4 = multiply(r3, m2, true);
	auto r5 = multiply(r4, m1, true);
	auto r6 = multiply(r5, vectort, true);
	auto r7 = multiply(vec, r6);

	//pos ? vec = multiply(vector, mxp) : vec = multiply(vector, mxn);
	return Vector3(r7);
}


//
//void Transform::rotate_y(Matrix m1, int degrees) {
//
//}
//
//void Transform::rotate_z(Matrix m1, int degrees) {
//
//}
//
//Matrix Transform::translate() {
//}