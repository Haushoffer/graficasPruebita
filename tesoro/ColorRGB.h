#pragma once
class ColorRGB
{
public:
	ColorRGB();										// Constructor por defecto
	ColorRGB(double _a);							// Constructor
	ColorRGB(double _r, double _g, double _b);		// Constructor
	ColorRGB(const ColorRGB &c);					// Constructor copia
	~ColorRGB();									// Destructor	

	ColorRGB& operator= (const ColorRGB& rhs);		// Operador de asignacion 
	ColorRGB operator+ (const ColorRGB& c) const;   // Sumar
	ColorRGB& operator+= (const ColorRGB& c);		// Suma compuesta
	ColorRGB operator* (const float _a)const;		// Multiplicacion por un numero por la derecha
	ColorRGB operator/ (const float _a) const;		// Division por un numero por la derecha
	ColorRGB operator* (const ColorRGB& _c)const;	// Multiplicar un color

public:
	double r, g, b;
};




