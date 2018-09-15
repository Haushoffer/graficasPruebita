#include "stdafx.h"
#include "ViewPlane.h"

ViewPlane::ViewPlane():Rver(400), Rhor(400), s(1.0){}
ViewPlane::ViewPlane(const ViewPlane& vp)
	: Rver(vp.Rver),
	Rhor(vp.Rhor),
	s(vp.s)
{}
ViewPlane::ViewPlane(int _Rver, int _Rhor, double _s) : Rver(_Rver), Rhor(_Rhor), s(_s) {}
ViewPlane::~ViewPlane(){}

ViewPlane& ViewPlane::operator=(const ViewPlane& rhs)
{
	if (this == &rhs)
	{
		return (*this);
	}
	Rhor = rhs.Rhor;
	Rver = rhs.Rver;
	s = rhs.s;
	return (*this);
}
void ViewPlane::establecerRhor(const int _Rhor)
{
	Rhor = _Rhor;
} 

void ViewPlane::establecerRver(const int _Rver)
{
	Rver = _Rver;
}
void ViewPlane::establecerS(const float _s)
{
	s = _s;
}



