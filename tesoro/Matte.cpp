#include "stdafx.h"
#include "Matte.h"

// ---------------------------------------------------------------- default constructor

Matte::Matte(void)
	: Material(),
	ambient_brdf(new Lambertian),
	diffuse_brdf(new Lambertian)
{}



// ---------------------------------------------------------------- copy constructor

Matte::Matte(const Matte& m)
	: Material(m)
{
	if (m.ambient_brdf)
		ambient_brdf = m.ambient_brdf->clone();
	else  ambient_brdf = NULL;

	if (m.diffuse_brdf)
		diffuse_brdf = m.diffuse_brdf->clone();
	else  diffuse_brdf = NULL;
}


// ---------------------------------------------------------------- clone

// ---------------------------------------------------------------- assignment operator

Matte&
Matte::operator= (const Matte& rhs) {
	if (this == &rhs)
		return (*this);

	Material::operator=(rhs);

	if (ambient_brdf) {
		delete ambient_brdf;
		ambient_brdf = NULL;
	}

	if (rhs.ambient_brdf)
		ambient_brdf = rhs.ambient_brdf->clone();

	if (diffuse_brdf) {
		delete diffuse_brdf;
		diffuse_brdf = NULL;
	}

	if (rhs.diffuse_brdf)
		diffuse_brdf = rhs.diffuse_brdf->clone();

	return (*this);
}


// ---------------------------------------------------------------- destructor

Matte::~Matte(void) {

	if (ambient_brdf) {
		delete ambient_brdf;
		ambient_brdf = NULL;
	}

	if (diffuse_brdf) {
		delete diffuse_brdf;
		diffuse_brdf = NULL;
	}
}


// ---------------------------------------------------------------- shade

//ColorRGB
//Matte::shade(ShadeRec& sr) {
//	Vector3D 	wo = sr.ray.vecD*-1;
//	ColorRGB 	L = ambient_brdf->rho(sr, wo) * sr.m.ambient_ptr->L(sr);
//	int 		num_lights = sr.m.luces.size();
//
//	for (int j = 0; j < num_lights; j++) {
//		Vector3D wi = sr.m.luces[j]->obtenerDireccion(sr);
//		float ndotwi = sr.normal * wi;
//
//		if (ndotwi > 0.0)
//			L += diffuse_brdf->f(sr, wo, wi) * sr.m.luces[j]->L(sr) * ndotwi;
//	}
//
//	return (L);
//}
//


