#pragma once
#include "Vector3D.h"
class Punto3D
{
public:
	Punto3D();								    // Constructor por defecto
	Punto3D(const double a);					// Constructor
	Punto3D(double a, double b, double c);      // Constructor
	Punto3D(const Punto3D& p);					// Constructor copia
	~Punto3D();							    	// Destructor
	Punto3D& operator= (const Punto3D& _p);		// Operador de asignacion
	Vector3D operator-(const Punto3D& p) const;	// Restar dos puntos
	Punto3D operator+(const Vector3D& v) const;	// Sumar un vector
		
	double x, y, z;// Coordenadas	
};

