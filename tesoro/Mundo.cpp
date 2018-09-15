#include "stdafx.h"
#include "Mundo.h"
#include "Constantes.h"

// Objetos geometricos
#include "Esfera.h"
#include "Triangulo.h"
// Tracers
#include "EsferaSola.h"
#include "VariosObjetos.h"
// Utilitarios
#include "Vector3D.h"
#include "Punto3D.h"
#include "Normal.h"
#include "ShadeRec.h"
#include <math.h>
#include "Salida.h"





Mundo::Mundo() : colorFondo(negro), tracer_ptr(NULL) {}

Mundo::~Mundo() 
{
	if (tracer_ptr) {
		delete tracer_ptr;
		tracer_ptr = NULL;
	}

	delete_objects();
	delete_lights();
}
void Mundo::agregarObjetoGeometrico(ObjetoGeometrico* ptr_objeto)
{
	objetos.push_back(ptr_objeto);
}

void Mundo::construir(void) {
	
	vp.establecerRhor(900);
	vp.establecerRver(800);
	vp.establecerS(0.4);
	colorFondo = blanco;
	//tracer_ptr = new EsferaSola(this);
	tracer_ptr = new VariosObjetos(this);

	//esfera.establecerCentro(0.0);
	//esfera.establecerRadio(90);
	// Objetos 
	Esfera* e1 = new Esfera;
	e1->establecerCentro(0.0, 0.0,0.0);
	e1->establecerRadio(70.0); 
	agregarObjetoGeometrico(e1);

	Esfera* e2 = new Esfera;
	e2->establecerCentro(90.0, 0.0, -95.0);
	e2->establecerRadio(90.0);
	agregarObjetoGeometrico(e2);

	// Triangulo
	Punto3D v0(-100.0, 0.0, 0.0);
	Punto3D v1(100.0, 0.0,  0.0);
	Punto3D v2(0.0, 150.0, 0.0);
	Triangulo* t = new Triangulo(v0, v1, v2);
	
	agregarObjetoGeometrico(t);
	
	// Luces
	LuzPuntual* ptrLuzPuntual = new LuzPuntual;
	ptrLuzPuntual->establecerUbicacion(0.0, 100.0, 200.0);
	ptrLuzPuntual->establecerColor(1.0,0.0,0.0);
	agregarLuz(ptrLuzPuntual);

}
// Vista paralela ortografica
void Mundo::dibujarEscena() const
{
	
	Salida salida;
	int dpi = 72;
	int n = vp.Rhor * vp.Rver;
	ColorRGB *colores = new ColorRGB[n];

	ColorRGB colorPixel;
	Rayo	 rayo;
	int Rhor = vp.Rhor;
	int Rver = vp.Rver;
	float s = vp.s;
	float zw = 800;
	rayo.vecD = Vector3D(0.0, 0.0, -1.0);

	for (int fila = 0; fila < Rver; fila++)
	{
		for (int col = 0; col < Rhor; col++)
		{
			// DISPARAMOS UN RAYO---------------------------------------------------------
			double x_w = vp.s * (col - vp.Rhor / 2 + 0.5);   // coordenada x
			double y_w = vp.s * (fila - vp.Rver / 2 + 0.5);  // coordenada y
			double z_w = 100.0;				   		         // coordenada z	
			Punto3D O(x_w, y_w, z_w);				         // Punto O		
			rayo.O = O;
			colorPixel = tracer_ptr->trace_ray(rayo);

			colores[fila * Rhor + col] = colorPixel;
		}
	}
	salida.savebmp("escena.bmp", Rhor, Rver, dpi, colores);
}

void Mundo::agregarLuz(Luz* ptrLuz)
{
	luces.push_back(ptrLuz);
}

ShadeRec Mundo::impactar_objetos(const Rayo& rayo)
{
	ShadeRec sr(*this);
	double t;
	Vector3D normal;
	Punto3D puntoImpactoLocal;
	double tmin = kHugeValue;
	int numObjetos = objetos.size();
	for (int j = 0; j < numObjetos; j++)
	{
		if (objetos[j]->impacto(rayo, t, sr) && (t < tmin))
		{
			//sr.normal = sr.normal;
			//sr.t = t;
			//sr.puntoImpactoLocal = sr.puntoImpactoLocal;
			sr.impactaUnObjeto = true;
			tmin = t;
			//sr.puntoImpactoLocal = rayo.O + rayo.vecD*t;
			normal = sr.normal;
			puntoImpactoLocal = sr.puntoImpactoLocal;
			//sr.normal.Mostrar();
			//sr.color = objetos[j]->obtenerColor();
		}
		if (sr.impactaUnObjeto) {
			sr.t = tmin;
			sr.normal = normal;
			sr.puntoImpactoLocal = puntoImpactoLocal;
		}
	}
	
	return sr;
}

void Mundo::delete_objects(void) {
	int num_objects = objetos.size();

	for (int j = 0; j < num_objects; j++) {
		delete objetos[j];
		objetos[j] = NULL;
	}

	objetos.erase(objetos.begin(), objetos.end());
}

void Mundo::delete_lights(void) {
	int num_lights = luces.size();

	for (int j = 0; j < num_lights; j++) {
		delete luces[j];
		luces[j] = NULL;
	}

	luces.erase(luces.begin(), luces.end());
}



