#pragma once
#include "ColorRGB.h"
class Salida
{
public:
	Salida();
	~Salida();

	void savebmp(const char* filename, int w, int h, int dpi, ColorRGB* data);

};


