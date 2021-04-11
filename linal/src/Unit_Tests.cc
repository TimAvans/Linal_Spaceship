#include <gtest/gtest.h>
#include "../include/Transform.hpp"

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

TEST(TestMatrixMultiply, MatrixMultiplyOK) {
	Transform trans;

	Matrix a;
	a._11 = 1;
	a._12 = 2;
	a._13 = 3;
	a._14 = 4;
	a._21 = 5;
	a._22 = 6;
	a._23 = 7;
	a._24 = 8;
	a._31 = 9;
	a._32 = 10;
	a._33 = 11;
	a._34 = 12;
	a._41 = 13;
	a._42 = 14;
	a._43 = 15;
	a._44 = 16;

	Matrix b;
	b._11 = 1;
	b._12 = 2;
	b._13 = 3;
	b._14 = 4;
	b._21 = 2;
	b._22 = 3;
	b._23 = 4;
	b._24 = 5;
	b._31 = 3;
	b._32 = 4;
	b._33 = 5;
	b._34 = 6;
	b._41 = 4;
	b._42 = 5;
	b._43 = 6;
	b._44 = 7;

	Matrix expected;
	expected._11 = 90;
	expected._12 = 100;
	expected._13 = 110;
	expected._14 = 120;

	expected._21 = 118;
	expected._22 = 132;
	expected._23 = 146;
	expected._24 = 160;

	expected._31 = 146;
	expected._32 = 164;
	expected._33 = 182;
	expected._34 = 200;

	expected._41 = 174;
	expected._42 = 196;
	expected._43 = 218;
	expected._44 = 240;


	Matrix result = trans.multiply(a, b);

	EXPECT_EQ(expected._11, result._11); EXPECT_EQ(expected._12, result._12); EXPECT_EQ(expected._13, result._13); EXPECT_EQ(expected._14, result._14);
	EXPECT_EQ(expected._21, result._21); EXPECT_EQ(expected._22, result._22); EXPECT_EQ(expected._23, result._23); EXPECT_EQ(expected._24, result._24);
	EXPECT_EQ(expected._31, result._31); EXPECT_EQ(expected._32, result._32); EXPECT_EQ(expected._33, result._33); EXPECT_EQ(expected._34, result._34);
	EXPECT_EQ(expected._41, result._41); EXPECT_EQ(expected._42, result._42); EXPECT_EQ(expected._43, result._43); EXPECT_EQ(expected._44, result._44);
}

TEST(TestMatrixMultiplyVector, MatrixMultiplyOK) {
	Transform trans;

	Matrix a;
	a._11 = 1;
	a._12 = 2;
	a._13 = 3;
	a._14 = 4;
	a._21 = 5;
	a._22 = 6;
	a._23 = 7;
	a._24 = 8;
	a._31 = 9;
	a._32 = 10;
	a._33 = 11;
	a._34 = 12;
	a._41 = 13;
	a._42 = 14;
	a._43 = 15;
	a._44 = 16;

	Vector4 b{15, 15, 15, 1};

	Vector4 expected{94, 278, 462, 646};

	Vector4 result = trans.multiply(b, a);

	EXPECT_EQ(expected.x(), result.x()); EXPECT_EQ(expected.y(), result.y()); EXPECT_EQ(expected.z(), result.z()); EXPECT_EQ(expected.w(), result.w());
}

TEST(TestMatrixMultiplyScalair, MatrixMultiplyOK) {
	Transform trans;

	float a = 23;

	Vector4 b{ 15, 15, 15, 1 };

	Vector4 expected{ 345, 345, 345, 1 };

	Vector4 result = trans.multiply(b, a);

	EXPECT_EQ(expected.x(), result.x()); EXPECT_EQ(expected.y(), result.y()); EXPECT_EQ(expected.z(), result.z()); EXPECT_EQ(expected.w(), result.w());
}

TEST(TestMatrixMultiplyVectors, MatrixMultiplyOK) {
	Transform trans;

	Vector4 a{ 7, 8, 9, 6 };

	Vector4 b{ 15, 15, 15, 1 };

	Vector4 expected{ 22, 23, 24, 1 };

	Vector4 result = trans.multiply(a, b);

	EXPECT_EQ(expected.x(), result.x()); EXPECT_EQ(expected.y(), result.y()); EXPECT_EQ(expected.z(), result.z()); EXPECT_EQ(expected.w(), result.w());
}

TEST(TestMatrixMultiplySubtract, MatrixMultiplyOK) {
	Transform trans;

	Vector3 a{13, 22, 42};

	Vector3 b{83, 23, 63};

	Vector4 expected{-70, -1, -21, 1};

	Vector4 result = trans.subtract(a, b);

	EXPECT_EQ(expected.x(), result.x()); EXPECT_EQ(expected.y(), result.y()); EXPECT_EQ(expected.z(), result.z()); EXPECT_EQ(expected.w(), result.w());
}

TEST(TestMatrixMakeTranslationMatrix, MatrixMultiplyOK) {
	Transform trans;

	Vector4 a{ 13, 22, 42, 10 };

	Matrix expected;
	expected._14 = 13;
	expected._24 = 22;
	expected._34 = 42;
	expected._44 = 10;

	Matrix result = trans.translation_matrix(a);

	EXPECT_EQ(expected._11, result._11); EXPECT_EQ(expected._12, result._12); EXPECT_EQ(expected._13, result._13); EXPECT_EQ(expected._14, result._14);
	EXPECT_EQ(expected._21, result._21); EXPECT_EQ(expected._22, result._22); EXPECT_EQ(expected._23, result._23); EXPECT_EQ(expected._24, result._24);
	EXPECT_EQ(expected._31, result._31); EXPECT_EQ(expected._32, result._32); EXPECT_EQ(expected._33, result._33); EXPECT_EQ(expected._34, result._34);
	EXPECT_EQ(expected._41, result._41); EXPECT_EQ(expected._42, result._42); EXPECT_EQ(expected._43, result._43); EXPECT_EQ(expected._44, result._44);
}

TEST(TestMatrixRotate, MatrixMultiplyOK) {
	Transform trans;

	Matrix expected;
	expected._11 = 0.58;
	expected._12 = 0.50;
	expected._13 = 0.66;
	expected._14 = 0;

	expected._21 = -0.81;
	expected._22 = 0.31;
	expected._23 = 0.50;
	expected._24 = 0;

	expected._31 = 0.05;
	expected._32 = -0.81;
	expected._33 = 0.58;
	expected._34 = 0;

	expected._41 = 0;
	expected._42 = 0;
	expected._43 = 0;
	expected._44 = 1;

	Matrix result = trans.rotate(15, 15, 15, true);

	EXPECT_EQ(expected._11, std::ceil(result._11 * 100) / 100); EXPECT_EQ(expected._12, std::ceil(result._12 * 100) / 100); EXPECT_EQ(expected._13, std::ceil(result._13 * 100) / 100); EXPECT_EQ(expected._14, std::ceil(result._14 * 100) / 100);
	EXPECT_EQ(expected._21, std::ceil(result._21 * 100) / 100); EXPECT_EQ(expected._22, std::ceil(result._22 * 100) / 100); EXPECT_EQ(expected._23, std::ceil(result._23 * 100) / 100); EXPECT_EQ(expected._24, std::ceil(result._24 * 100) / 100);
	EXPECT_EQ(expected._31, std::ceil(result._31 * 100) / 100); EXPECT_EQ(expected._32, std::ceil(result._32 * 100) / 100); EXPECT_EQ(expected._33, std::ceil(result._33 * 100) / 100); EXPECT_EQ(expected._34, std::ceil(result._34 * 100) / 100);
	EXPECT_EQ(expected._41, std::ceil(result._41 * 100) / 100); EXPECT_EQ(expected._42, std::ceil(result._42 * 100) / 100); EXPECT_EQ(expected._43, std::ceil(result._43 * 100) / 100); EXPECT_EQ(expected._44, std::ceil(result._44 * 100) / 100);
}

TEST(TestMatrixScale, MatrixMultiplyOK) {
	Transform trans;

	Vector4 vec{22, 33, 44, 1};

	Matrix expected;
	expected._11 = 22;
	expected._12 = 0;
	expected._13 = 0;
	expected._14 = 0;

	expected._21 = 0;
	expected._22 = 33;
	expected._23 = 0;
	expected._24 = 0;

	expected._31 = 0;
	expected._32 = 0;
	expected._33 = 44;
	expected._34 = 0;

	expected._41 = 0;
	expected._42 = 0;
	expected._43 = 0;
	expected._44 = 1;


	Matrix result = trans.scale(vec);

	EXPECT_EQ(expected._11, result._11); EXPECT_EQ(expected._12, result._12); EXPECT_EQ(expected._13, result._13); EXPECT_EQ(expected._14, result._14);
	EXPECT_EQ(expected._21, result._21); EXPECT_EQ(expected._22, result._22); EXPECT_EQ(expected._23, result._23); EXPECT_EQ(expected._24, result._24);
	EXPECT_EQ(expected._31, result._31); EXPECT_EQ(expected._32, result._32); EXPECT_EQ(expected._33, result._33); EXPECT_EQ(expected._34, result._34);
	EXPECT_EQ(expected._41, result._41); EXPECT_EQ(expected._42, result._42); EXPECT_EQ(expected._43, result._43); EXPECT_EQ(expected._44, result._44);
}

TEST(TestNormalize, MatrixMultiplyOK) {
	Transform trans;

	Vector4 result{ 22, 44, 88, 4 };

	Vector4 expected{0.22, 0.44, 0.88, 1};

	trans.normalize(result);

	EXPECT_EQ(expected.x(), std::ceil(result.x() * 100) / 100); EXPECT_EQ(expected.y(), std::ceil(result.y() * 100) / 100); EXPECT_EQ(expected.z(), std::ceil(result.z() * 100) / 100);
}

