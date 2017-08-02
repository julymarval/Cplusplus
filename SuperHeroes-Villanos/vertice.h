#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>
#include "lista.h"
using namespace std;

class Vertice
{
	public:
		int id;
		Lista<int> hijos;
		Lista<float> aristaHijo;
		float aristaAcumulada;
		int padre;
		
		Vertice();
		Vertice(int);
		void agrSecuencia(float, int);
		void agrHijo(int, float);
		int obtHijo(int);
		float obtArista(int);
		int totalHijos();
		bool igual(Vertice);
};

#endif
