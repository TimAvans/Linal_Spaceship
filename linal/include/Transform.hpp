#include "Vector4.hpp"
#include "Vector3.hpp"

struct Matrix {
public:
	float _11 = 1, _12 = 0, _13 = 0, _14 = 0;
	float _21 = 0, _22 = 1, _23 = 0, _24 = 0;
	float _31 = 0, _32 = 0, _33 = 1, _34 = 0;
	float _41 = 0, _42 = 0, _43 = 0, _44 = 1;
};

static class Transform {
public:
	//Matrix addition(Matrix m1, Matrix m2);
	//Matrix subtraction(Matrix m1, Matrix m2);
	static Vector4 multiply(Matrix m1, Matrix m2);
	static Matrix multiply(Matrix m1, Matrix m2, bool m);
	static Vector4 multiply(Vector4 m2, Matrix m1);
	//Matrix inverse(Matrix m1);
	static Vector3 rotate_x(Vector4 vec, int degrees, bool pos);
	static Vector3 rotate_y(Vector4 vec, int degrees, bool pos);
	static Vector3 rotate_z(Vector4 vec, int degrees, bool pos);
	static Vector3 rotate(Vector4 vec, int degrees, bool pos);
	//void translate();
	//void scale();
private:

};