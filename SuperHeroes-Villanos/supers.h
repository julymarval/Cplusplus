#ifndef SUPERS_H
#define SUPERS_H

#include <iostream>
#include <string>
using namespace std;

class Supers
{
	private:
		string nombre;
		int ataque;
		int resistencia;
	public:
		Supers();
		Supers(string, int, int);
		string obtNombre();
		int obtAtaque();
		int obtResistencia();
		void recivirDano(int);
		bool estaVido();
		bool compare(Supers);
};

#endif
