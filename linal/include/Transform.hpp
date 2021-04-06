#pragma once
#include "Vector4.hpp"
#include "Vector3.hpp"


struct Matrix {
public:
	float _11 = 1, _12 = 0, _13 = 0, _14 = 0;
	float _21 = 0, _22 = 1, _23 = 0, _24 = 0;
	float _31 = 0, _32 = 0, _33 = 1, _34 = 0;
	float _41 = 0, _42 = 0, _43 = 0, _44 = 1;
};

class Transform {
public:
	 Matrix multiply(Matrix m1, Matrix m2);
	 Vector4 multiply(Vector4 v1, Matrix m1);
	 Vector4 multiply_test(Vector4 v1, Matrix m1);
	 Vector multiply(Vector v1, float i);
	 Vector4 multiply(Vector v1, Vector v2);
	 Vector4 subtract(Vector v1, Vector v2);
	 Matrix translation_matrix(Vector4 v1);
	 Matrix rotate(float radian_x, float radian_y, float radian_z, bool pos);
	 Matrix move(Vector4 vec, Vector4 move_vec);
	 Matrix scale(Vector4 move_vec);
	 Matrix move_to_origin(Vector4 vec, Vector4 to_origin);
	 void normalize(Vector4& vec);

private:

};
