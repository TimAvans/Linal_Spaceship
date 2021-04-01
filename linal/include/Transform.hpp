#include "Vector.hpp"

struct Matrix {
public:
	float _11 = 1, _12 = 0, _13 = 0, _14 = 0;
	float _21 = 0, _22 = 1, _23 = 0, _24 = 0;
	float _31 = 0, _32 = 0, _33 = 1, _34 = 0;
	float _41 = 0, _42 = 0, _43 = 0, _44 = 1;
};

class Transform {
public:
	//Matrix addition(Matrix m1, Matrix m2);
	//Matrix subtraction(Matrix m1, Matrix m2);
	Matrix multiply(Matrix m1, Matrix m2);
	//Matrix inverse(Matrix m1);
	void rotate_x(Matrix m1, int degrees, bool pos);
	//void rotate_y(Matrix m1, int degrees);
	//void rotate_z(Matrix m1, int degrees);
	//void translate();
	//void scale();
private:

};