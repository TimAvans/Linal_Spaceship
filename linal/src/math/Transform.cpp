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

Vector3 Transform::rotate_x(Vector4 vec, float degrees, bool pos) {

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

Vector3 Transform::rotate_y(Vector4 vec, float degrees, bool pos) {

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

Vector3 Transform::rotate_z(Vector4 vec, float degrees, bool pos) {

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

	auto r1 = multiply(mz, my, true);
	auto r2 = multiply(r1, mx, true);

	return r2;
}
