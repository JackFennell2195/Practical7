#pragma once

#include <math.h>
#include "string"
#include <SFML/Graphics.hpp>

class Vector3
{
public:
	double getX();
	void setX(double value);

	double getY();
	void setY(double value);
	
	double getZ();
	void setZ(double value);

	Vector3();
	Vector3(double x1, double y1, double z1);
	Vector3(Vector3 * V);
	double length();
	double lengthSquared();
	void normalise();

	Vector3 operator +(Vector3 V1);
	Vector3 operator -(Vector3 V1);
	Vector3 operator -();
	double operator *(Vector3 V1);
	Vector3 operator *(double k);
	Vector3 operator *(float k);
	Vector3 operator *(int k);
	Vector3 operator ^(Vector3 V1);
	std::string Vector3::toString();
	
	

private:
	double x;
	double y;
	double z;
};