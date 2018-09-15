#pragma once
#include "Material.h"
#include "Lambertian.h"

//----------------------------------------------------------------------------- class Matte

class Matte : public Material {
public:

	Matte(void);

	Matte(const Matte& m);

	

	Matte& operator= (const Matte& rhs);

	~Matte(void);

	void set_ka(const float k);

	void set_kd(const float k);

	void set_cd(const ColorRGB c);

	void set_cd(const float r, const float g, const float b);

	void set_cd(const float c);

	//virtual ColorRGB shade(ShadeRec& sr);

private:

	Lambertian* ambient_brdf;
	Lambertian*	diffuse_brdf;
};

inline void
Matte::set_ka(const float ka) {
	ambient_brdf->set_kd(ka);
}


// ---------------------------------------------------------------- set_kd
// this also sets Lambertian::kd, but for a different Lambertian object

inline void
Matte::set_kd(const float kd) {
	diffuse_brdf->set_kd(kd);
}


// ---------------------------------------------------------------- set_cd

inline void
Matte::set_cd(const ColorRGB c) {
	ambient_brdf->set_cd(c);
	diffuse_brdf->set_cd(c);
}


// ---------------------------------------------------------------- set_cd

inline void
Matte::set_cd(const float r, const float g, const float b) {
	ambient_brdf->set_cd(r, g, b);
	diffuse_brdf->set_cd(r, g, b);
}

// ---------------------------------------------------------------- set_cd

inline void
Matte::set_cd(const float c) {
	ambient_brdf->set_cd(c);
	diffuse_brdf->set_cd(c);
}

// ---------------------
