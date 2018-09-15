#pragma once
#include "ColorRGB.h"
#include "Punto3D.h"
#include "Normal.h"
#include "Rayo.h"
#include "ShadeRec.h"
#include "Constantes.h"
class ObjetoGeometrico
{
public:
	ObjetoGeometrico();														// Constructor por defecto
	ObjetoGeometrico(const ObjetoGeometrico& _o);							// Constructor copia
	virtual ~ObjetoGeometrico();											// Destructor
	
	virtual bool impacto(const Rayo& r, double& t, ShadeRec& s)const = 0;

	// Las siguientes tres funciones solo se requieren para este capitulo
	void establecerColor(const ColorRGB& c);
	void establecerColor(const float r, const float g, const float b);
	ColorRGB obtenerColor(void);

protected:
	ColorRGB   color;														// usado solo en este capitulo
	ObjetoGeometrico& operator= (const ObjetoGeometrico& rhs);
};



