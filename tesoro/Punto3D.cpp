#include "stdafx.h"
#include "Punto3D.h"

Punto3D::Punto3D() : x(0.0), y(0.0), z(0.0) {}
Punto3D::Punto3D( double a) : x(a),y(a),z(a) {}
Punto3D::Punto3D(double a, double b, double c) : x(a),y(b),z(c) {}
Punto3D::Punto3D(const Punto3D& p) : x(p.x), y(p.y), z(p.z) {}

Vector3D Punto3D::operator-(const Punto3D& p) const
{
	return(Vector3D( x - p.x, y - p.y, z - p.z) );
}
Punto3D Punto3D::operator+(const Vector3D& v) const
{
	return ( Punto3D( x + v.x, y + v.y, z + v.z) );
}
Punto3D::~Punto3D()
{
}

Punto3D& Punto3D::operator=(const Punto3D& rhs)
{
	if (this == & rhs)
	{
		return (*this);
	}
	x = rhs.x; y = rhs.y; z = rhs.z;
	return (*this);
}


