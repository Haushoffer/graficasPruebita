#pragma once
#include <vector>
#include "ViewPlane.h"
#include "ColorRGB.h"
#include "Tracer.h"
#include "ObjetoGeometrico.h"
#include "Esfera.h"
#include "Rayo.h"

#include "Luz.h"
#include "LuzPuntual.h"
using namespace std;

class Mundo
{
public:
	Mundo();
	~Mundo();
	
	void agregarObjetoGeometrico(ObjetoGeometrico* ptr_objeto);
	void construir();
	void dibujarEscena() const;
	//void guardarImagen();
	void agregarLuz(Luz* ptrLuz);
	ShadeRec impactar_objetos(const Rayo& rayo);
public:
	ViewPlane vp;
	ColorRGB colorFondo;
	Tracer*	tracer_ptr;
	Esfera esfera;
	vector<ObjetoGeometrico*> objetos;

	vector<Luz*> luces;
	
private:
	void delete_objects(void);

	void delete_lights(void);
};

