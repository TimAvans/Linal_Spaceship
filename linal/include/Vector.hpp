#pragma once 

class Vector {
public:
	Vector(float x, float y, float z);

	//Functions
	float get_x();
	float get_y();
	float get_z();

private:
	float x_;
	float y_;
	float z_;

};