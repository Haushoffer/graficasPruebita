#include "stdafx.h"
#include "Tracer.h"

// -------------------------------------------------------------------- default constructor

Tracer::Tracer(void)
	: world_ptr(NULL)
{}


// -------------------------------------------------------------------- constructor

Tracer::Tracer(Mundo* _worldPtr)
	: world_ptr(_worldPtr)
{}



// -------------------------------------------------------------------- destructor

Tracer::~Tracer(void) {
	if (world_ptr)
		world_ptr = NULL;
}


// -------------------------------------------------------------------- trace_ray

ColorRGB Tracer::trace_ray(const Rayo& ray) const {
	return (negro);
}


// -------------------------------------------------------------------- trace_ray

ColorRGB Tracer::trace_ray(const Rayo ray, const int depth) const {
	return (negro);
}



