#include "stdafx.h"
#include "Esfera.h"
#include <math.h>

Esfera::Esfera() : ObjetoGeometrico(), C(0.0), r(1.0) {}
Esfera::Esfera(Punto3D _c, double _r) : ObjetoGeometrico(), C(_c), r(_r){}
Esfera::Esfera(const Esfera& _e) : ObjetoGeometrico(_e), C(_e.C), r(_e.r) {}
Esfera::~Esfera(){}

Esfera& Esfera::operator= (const Esfera& rhs)
{
	if (this == &rhs)
	{
		return (*this);
	}
	ObjetoGeometrico::operator=(rhs);
	C = rhs.C;
	r = rhs.r;
	return (*this);
}
void Esfera::establecerCentro(const Punto3D& _p)
{
	C = _p;
}
void Esfera::establecerCentro(const double _x, const double _y, const double _z)
{
	C.x = _x;
	C.y = _y;
	C.z = _z;
}
void Esfera::establecerRadio(const double _r)
{
	r = _r;
}

bool Esfera::impacto( const Rayo& rayo, double& tmin, ShadeRec& sr) const
{
	double t;
	Vector3D temp = rayo.O - C;
	double a = rayo.vecD * rayo.vecD;
	double b = 2 * (rayo.vecD * (rayo.O - C));
	double c = (rayo.O-C)*(rayo.O-C) - (r * r);
	double discriminante = b*b - 4*a*c;
	if (discriminante < 0)
	{
		return false;
	}
	else
	{
		double e = sqrt(discriminante);
		double denom = 2.0 * a;
		t = (-b - e) / denom;
		if (t > kEpsilon)
		{
			tmin = t;
			sr.normal = (temp + (rayo.vecD * t)) / r;
			sr.puntoImpactoLocal = rayo.O + rayo.vecD * t;
			return true;
		}
		t = (-b + e) / denom;

		if (t > kEpsilon)
		{
			tmin = t;
			sr.normal = (temp + (rayo.vecD * t)) / r;
			sr.puntoImpactoLocal = rayo.O + rayo.vecD * t;
			return true;
		}
	}
	return false;
}


