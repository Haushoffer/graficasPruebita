#include "stdafx.h"
#include <math.h>
#include <iostream>
using std::cout;
#include "Vector3D.h"

Vector3D::Vector3D():x(0.0),y(0.0),z(0.0) {}
Vector3D::Vector3D(double a) : x(a), y(a), z(a) {}
Vector3D::Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}
Vector3D::Vector3D(const Vector3D& v) : x(v.x), y(v.y), z(v.z) {}
Vector3D::~Vector3D() {}


Vector3D Vector3D::operator*(double t) const            // Multiplicar el vector por un numero por la derecha  
{
	return ( Vector3D(x * t, y * t, z * t) );
}

double Vector3D::operator*(const Vector3D & v) const   // Producto escalar
{
	return ( x * v.x + y * v.y + z * v.z );
}
Vector3D Vector3D::operator+ (const Vector3D& _v)const
{
	return(Vector3D(x + _v.x, y + _v.y, z + _v.z));
}
Vector3D Vector3D::operator/ (const double _a)const
{
	return (Vector3D(x / _a, y / _a, z / _a));
}

Vector3D& Vector3D::hat(void) {
	double length = sqrt(x * x + y * y + z * z);
	x /= length; y /= length; z /= length;
	return (*this);
}

void Vector3D::Normalizar()
{
	double Length = sqrt(x * x + y * y + z * z);
	x /= Length;
	y /= Length;
	z /= Length;
}
void Vector3D::Mostrar()
{
	cout << "< ";
	cout << x;
	cout << ", ";
	cout << y;
	cout << ", ";
	cout << z;
	cout << " >";
}


Vector3D Vector3D::operator^(const Vector3D& v) const {
	return (Vector3D(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x));
}
