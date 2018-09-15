#include "stdafx.h"
#include "ColorRGB.h"

ColorRGB::ColorRGB():r(0.0), g(0.0), b(0.0){}
ColorRGB::ColorRGB(double _a) : r(_a), g(_a), b(_a) {}
ColorRGB::ColorRGB(double _r, double _g, double _b) : r(_r), g(_g), b(_b) {}
ColorRGB::ColorRGB(const ColorRGB& _c) : r(_c.r), g(_c.g), b(_c.b) {}
ColorRGB::~ColorRGB(){}

ColorRGB& ColorRGB::operator=(const ColorRGB& rhs)
{
	if (this == &rhs)
	{
		return (*this);
	}
	r = rhs.r; g = rhs.g; b = rhs.b;
	return (*this);
}

ColorRGB ColorRGB::operator+(const ColorRGB& _c) const
{
	return(ColorRGB(r+_c.r, g+_c.g, b+_c.b));
}
ColorRGB& ColorRGB::operator+=(const ColorRGB& _c)
{
	r += _c.r; g += _c.g; b += _c.b;
	return (*this);
}

ColorRGB ColorRGB::operator* (const float _a) const
{
	return (ColorRGB(r*_a, g*_a, b*_a));
}

ColorRGB ColorRGB::operator/ (const float _a)const
{
	return (ColorRGB(r/_a, g/_a, b/_a));
}

ColorRGB ColorRGB::operator*(const ColorRGB& _c) const
{
	return (ColorRGB(r * _c.r, g * _c.g,  b * _c.b));
}
