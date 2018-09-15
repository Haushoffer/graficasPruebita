#pragma once
#include "Tracer.h"

class EsferaSola : public Tracer {
public:

	EsferaSola(void);

	EsferaSola(Mundo* _worldPtr);

	virtual ~EsferaSola(void);

	virtual ColorRGB trace_ray(const Rayo& ray) const;
};
