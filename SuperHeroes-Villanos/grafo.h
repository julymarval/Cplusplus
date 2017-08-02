#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include "vertice.h"
#include "lista.h"
using namespace std;

class Grafo
{
	private:
		Lista<Vertice> vertices;	
	public:
		Grafo();
		Grafo(int);
		void agrVertice();
		void agrConexion(int, int, float);
		Lista<int> RutaMinimaEntreNodos(int , int);
		Lista<Vertice> RutaMinima(int _inicio);
};

#endif
