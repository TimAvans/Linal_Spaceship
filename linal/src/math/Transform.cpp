#include "../../include/Transform.hpp"
#include <cmath>

//Matrix Transform::addition(Matrix m1, Matrix m2) {
//}
//
//Matrix Transform::subtraction(Matrix m1, Matrix m2) {
//}

Matrix Transform::multiply(Matrix m1, Matrix m2) {

	Matrix matrix;

	//first row
	matrix._11 = (m1._11 * m2._11) + (m1._12 * m2._21) + (m1._13 * m2._31) + (m1._14 * m2._41);
	matrix._12 = (m1._11 * m2._12) + (m1._12 * m2._22) + (m1._13 * m2._32) + (m1._14 * m2._42);
	matrix._13 = (m1._11 * m2._13) + (m1._12 * m2._23) + (m1._13 * m2._33) + (m1._14 * m2._43);
	matrix._13 = (m1._11 * m2._14) + (m1._12 * m2._24) + (m1._13 * m2._34) + (m1._14 * m2._44);

	//second
	matrix._21 = (m1._21 * m2._11) + (m1._22 * m2._21) + (m1._23 * m2._31) + (m1._24 * m2._41);
	matrix._22 = (m1._21 * m2._12) + (m1._22 * m2._22) + (m1._23 * m2._32) + (m1._24 * m2._42);
	matrix._23 = (m1._21 * m2._13) + (m1._22 * m2._23) + (m1._23 * m2._33) + (m1._24 * m2._43);
	matrix._23 = (m1._21 * m2._14) + (m1._22 * m2._24) + (m1._23 * m2._34) + (m1._24 * m2._44);

	//third
	matrix._31 = (m1._31 * m2._11) + (m1._32 * m2._21) + (m1._33 * m2._31) + (m1._34 * m2._41);
	matrix._32 = (m1._31 * m2._12) + (m1._32 * m2._22) + (m1._33 * m2._32) + (m1._34 * m2._42);
	matrix._33 = (m1._31 * m2._13) + (m1._32 * m2._23) + (m1._33 * m2._33) + (m1._34 * m2._43);
	matrix._33 = (m1._31 * m2._14) + (m1._32 * m2._24) + (m1._33 * m2._34) + (m1._34 * m2._44);
	
	//fourth
	matrix._41 = (m1._41 * m2._11) + (m1._42 * m2._21) + (m1._43 * m2._31) + (m1._44 * m2._41);
	matrix._42 = (m1._41 * m2._12) + (m1._42 * m2._22) + (m1._43 * m2._32) + (m1._44 * m2._42);
	matrix._43 = (m1._41 * m2._13) + (m1._42 * m2._23) + (m1._43 * m2._33) + (m1._44 * m2._43);
	matrix._44 = (m1._41 * m2._14) + (m1._42 * m2._24) + (m1._43 * m2._34) + (m1._44 * m2._44);

	return matrix;
}

//Matrix Transform::inverse(Matrix m1) {
//
//}

void Transform::rotate_x(Matrix m1, int degrees, bool pos) {
	Matrix mxp;
	mxp._11 = 1; mxp._12 = 0; mxp._13 = 0; mxp._44 = 0;
	mxp._21 = 0; mxp._22 = cos(degrees); mxp._23 = -sin(degrees); mxp._44 = 0;
	mxp._31 = 0; mxp._32 = sin(degrees); mxp._33 = cos(degrees); mxp._44 = 0;
	mxp._41 = 0; mxp._42 = 0; mxp._43 = 0; mxp._44 = 1;	
	
	Matrix mxn;
	mxp._11 = 1; mxp._12 = 0; mxp._13 = 0; mxp._44 = 0;
	mxp._21 = 0; mxp._22 = cos(degrees); mxp._23 = sin(degrees); mxp._44 = 0;
	mxp._31 = 0; mxp._32 = -sin(degrees); mxp._33 = cos(degrees); mxp._44 = 0;
	mxp._41 = 0; mxp._42 = 0; mxp._43 = 0; mxp._44 = 1;

	pos ? m1 = multiply(m1, mxp) : m1 = multiply(m1, mxn);
}

Vector Transform::to_vector() {

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