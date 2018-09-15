#pragma once
#include "ObjetoGeometrico.h"
class Esfera: public ObjetoGeometrico
{
public:
	Esfera();										// Constructor por defecto
	Esfera(Punto3D _c, double _r);					// Constructor
	Esfera(const Esfera& _e);						// Constructor copia
	virtual ~Esfera();										// Destructor
	
	Esfera& operator= (const Esfera& rhs);			// Operador de asignacion
	void establecerCentro(const Punto3D& _C);
	void establecerCentro(const double _x, const double _y, const double _z);
	void establecerRadio(const double _r);

	bool impacto(const Rayo& r, double& t, ShadeRec& s)const;


	// Datos
	Punto3D C;
	double r;
	
};

	