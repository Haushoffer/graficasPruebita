#pragma once
#include "Constantes.h"
#include "Rayo.h"
#include "ColorRGB.h"

class Mundo;

class Tracer {
public:

	Tracer(void);

	Tracer(Mundo* _world_ptr);

	virtual	~Tracer(void);

	virtual ColorRGB trace_ray(const Rayo& ray) const;

	virtual ColorRGB trace_ray(const Rayo ray, const int depth) const;

protected:

	Mundo * world_ptr;
};