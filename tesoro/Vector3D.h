#pragma once

class Vector3D
{
public:
	Vector3D();									  // Constructor por defecto 		
	Vector3D(double a);							  // Constructor		
	Vector3D(double x, double y, double z);       // Constructor
	Vector3D(const Vector3D& v);				  // Constructor copia
	~Vector3D();								  // Destructor
	Vector3D operator*(double t) const;           // Multiplicar el vector por un numero por la derecha  
	double operator*(const Vector3D& _v) const;   // Producto escalar
	Vector3D operator+ (const Vector3D& _v) const;// Sumar un vector
	Vector3D operator/ (const double _a)const;	  // Dividir por un numero por la derecha	
	Vector3D& hat();							  // Convertir el vector a un vector unitario y retornar el vector
	void Normalizar();   						  // Convertir el vector a un vector unitario
	void Mostrar();								  // Mostrar el vector	
	Vector3D operator^ (const Vector3D& v) const; // Producto cruz

	// Componentes
	double x, y, z;
};
