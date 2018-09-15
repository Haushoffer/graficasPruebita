#include "stdafx.h"
#include"Rayo.h"
Rayo::Rayo() : O(0.0), vecD(0.0,0.0,1.0) {}
Rayo::Rayo(const Punto3D& origen, const Vector3D& direccion) : O(origen),vecD(direccion){}
Rayo::Rayo(const Rayo& r) : O(r.O), vecD(r.vecD) {}
Rayo::~Rayo(){}

Rayo& Rayo::operator=(const Rayo& rhs)
{
	if (this == &rhs)
	{
		return (*this);
	}
	O = rhs.O;
	vecD = rhs.vecD;
	return (*this);
}



