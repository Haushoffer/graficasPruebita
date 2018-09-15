#pragma once
#include "Punto3D.h"
#include "Vector3D.h"

class Rayo
{
public:
	Rayo();														// Constructor por defecto
	Rayo(const Punto3D& origen, const Vector3D& direccion);		// Constructor
	Rayo(const Rayo& r);										// Constructor copia
	~Rayo();													// Destructor
	Rayo& operator=(const Rayo& rhs);							// Asignacion

	Punto3D O;													// Origen
	Vector3D vecD;												// Direccion

};


