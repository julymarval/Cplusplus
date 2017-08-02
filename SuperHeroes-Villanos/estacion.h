#ifndef ESTACION_H
#define ESTACION_H

#include <iostream>
#include <string>
#include "lista.h"
using namespace std;

class Estacion
{
	private:
		string nombre;
		int x;
		int y;
			
	public:
		Estacion();
		Estacion(string, int, int);		
		string obtNombre();
		int obtX();
		int obtY();
		bool igual(Estacion);
};

#endif
