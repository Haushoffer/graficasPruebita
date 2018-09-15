#pragma once
#include "Mundo.h"
#include "ColorRGB.h"
#include "ShadeRec.h"

class Material {
public:

	Material(void);

	Material(const Material& material);

	virtual	~Material(void);

	virtual ColorRGB shade(ShadeRec& sr);

protected:

	Material & operator= (const Material& rhs);
};

