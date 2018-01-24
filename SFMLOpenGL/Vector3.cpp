#include "Vector3.h"
#include <iostream>

double Vector3::getX()
{
	return x;
}

void Vector3::setX(double value)
{
	x = value;
}

double Vector3::getY()
{
	return y;
}

void Vector3::setY(double value)
{
	y = value;
}

double Vector3::getZ()
{
	return z;
}

void Vector3::setZ(double value)
{
	z = value;
}

Vector3::Vector3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Vector3::Vector3(double x1, double y1, double z1)
{
	x = x1;
	y = y1;
	z = z1;
}

Vector3::Vector3(Vector3 * V)
{
	x = V->x;
	y = V->y;
	z = V->z;

}

double Vector3::length() 
{
	return (double)sqrt(x * x + y * y + z * z);
}

double Vector3::lengthSquared() 
{
	// A method to return the length squared of the vector
	return (x * x + y * y + z * z);
}

void Vector3::normalise()
{
	// A method to reduce the length of the vector to 1.0 
	// keeping the direction the same
	if (length() > 0.0)
	{  // Check for divide by zero
		double magnit = length();
		x /= magnit;
		y /= magnit;
		z /= magnit;
	}
}

Vector3 Vector3::operator+(Vector3 V1)
{
	// An overloaded operator + to return the sum of 2 vectors
	return Vector3(x + V1.x, y + V1.y, z + V1.z);
}

Vector3 Vector3::operator-(Vector3 V1)
{
	// An overloaded operator - to return the difference of 2 vectors
	return Vector3(x - V1.x, y - V1.y, z - V1.z);
}

Vector3 Vector3::operator-()
{
	// An overloaded operator - to return the negation of a single vector
	return Vector3(x*-1, y*-1, z*-1);
}

double Vector3::operator*(Vector3 V1)
{
	// An overloaded operator * to return the scalar product of 2 vectors
	return (x * V1.x, y * V1.y, z * V1.z);
}

Vector3 Vector3::operator*(double k)
{
	// An overloaded operator * to return the product of a scalar by a vector
	return Vector3(x * (float)k, y * (float)k, z * (float)k);
}

Vector3 Vector3::operator*(float k)
{
	// An overloaded operator * to return the product of a scalar by a vector
	return Vector3(x * k, y * k, z * k);
}

Vector3 Vector3::operator*(int k)
{
	// An overloaded operator * to return the product of a scalar by a vector
	return Vector3(x * k, y * k, z * k);
}

Vector3 Vector3::operator^(Vector3 V1)
{
	// An overloaded operator ^ to return the vector product of 2 vectors
	return Vector3(V1.y * z - V1.z * y, V1.z * x - V1.x * z, V1.x * y - V1.y * x);
}



std::string Vector3::toString()
{
	char tmpbuf[256];
	sprintf_s(tmpbuf, "[%g, %g, %g]", x, y, z);
	return tmpbuf;
}
