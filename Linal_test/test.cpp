#include "pch.h"
#include "../linal/include/Transform.hpp"

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

TEST(TestMatrixMultiply, MatrixMultiplyOK) {
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
	expected._11 = 30;
	expected._12 = 40;
	expected._13 = 50;
	expected._14 = 60;

	expected._21 = 70;
	expected._22 = 96;
	expected._23 = 122;
	expected._24 = 148;

	expected._31 = 110;
	expected._32 = 152;
	expected._33 = 194;
	expected._34 = 236;

	expected._41 = 150;
	expected._42 = 208;
	expected._43 = 266;
	expected._44 = 324;

	Matrix result = Transform::multiply(a, b);

	EXPECT_EQ(expected._11, result._11); EXPECT_EQ(expected._12, result._12); EXPECT_EQ(expected._13, result._13); EXPECT_EQ(expected._14, result._14);
	EXPECT_EQ(expected._21, result._21); EXPECT_EQ(expected._22, result._22); EXPECT_EQ(expected._23, result._23); EXPECT_EQ(expected._24, result._24);
	EXPECT_EQ(expected._31, result._31); EXPECT_EQ(expected._32, result._32); EXPECT_EQ(expected._33, result._33); EXPECT_EQ(expected._34, result._34);
	EXPECT_EQ(expected._41, result._41); EXPECT_EQ(expected._42, result._42); EXPECT_EQ(expected._43, result._43); EXPECT_EQ(expected._44, result._44);
	EXPECT_TRUE(true);
}