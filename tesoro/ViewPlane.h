#pragma once
class ViewPlane
{
public:
	ViewPlane();								// Constructor por defecto
	ViewPlane(const ViewPlane& vp);				// Constructor coipa
	ViewPlane(int _Rver, int _Rhor, double _s);	// Constructor
	~ViewPlane();

	ViewPlane& operator= (const ViewPlane& rhs);// Operador de asignacion
	void establecerRhor( const int Rhor );
	void establecerRver( const int Rver );
	void establecerS(const float size);



	// Datos
	int Rver;		// Resolucion vertical
	int Rhor;		// Resolucion horizontal
	double s;		// Tamaño del pixel
};

