#include "stdafx.h"
#include "Lambertian.h"
#include "Constantes.h"

// ---------------------------------------------------------------------- default constructor

Lambertian::Lambertian(void)
	: BRDF(),
	kd(0.0),
	cd(0.0)
{}


// ---------------------------------------------------------------------- copy constructor

Lambertian::Lambertian(const Lambertian& lamb)
	: BRDF(lamb),
	kd(lamb.kd),
	cd(lamb.cd)
{}


// ---------------------------------------------------------------------- clone

Lambertian*
Lambertian::clone(void) const {
	return (new Lambertian(*this));
}


// ---------------------------------------------------------------------- destructor

Lambertian::~Lambertian(void) {}


// ---------------------------------------------------------------------- assignment operator

Lambertian&
Lambertian::operator= (const Lambertian& rhs) {
	if (this == &rhs)
		return (*this);

	BRDF::operator= (rhs);

	kd = rhs.kd;
	cd = rhs.cd;

	return (*this);
}


// ---------------------------------------------------------------------- f

ColorRGB
Lambertian::f(const ShadeRec& sr, const Vector3D& wo, const Vector3D& wi) const {
	return ( cd * kd * invPI);
}




// ---------------------------------------------------------------------- rho

ColorRGB
Lambertian::rho(const ShadeRec& sr, const Vector3D& wo) const {
	return (cd * kd);
}



