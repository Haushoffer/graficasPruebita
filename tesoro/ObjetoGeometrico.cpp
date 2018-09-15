#include "stdafx.h"
#include "Constantes.h"
#include "ObjetoGeometrico.h"


ObjetoGeometrico::ObjetoGeometrico():color(negro){}
ObjetoGeometrico::ObjetoGeometrico(const ObjetoGeometrico& _o) : color(_o.color) {}
ObjetoGeometrico::~ObjetoGeometrico(){}

ObjetoGeometrico& ObjetoGeometrico::operator=(const ObjetoGeometrico& rhs)
{
	if (this == &rhs)
	{
		return (*this);
	}
	color = rhs.color;
	return (*this);
}

void ObjetoGeometrico::establecerColor(const ColorRGB& _c)
{
	color = _c;
}

void ObjetoGeometrico::establecerColor(const float _r, const float _g, const float _b)
{
	color.r = _r;
	color.g = _g;
	color.b = _b;
}
ColorRGB ObjetoGeometrico::obtenerColor()
{
	return color;
}

