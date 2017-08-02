#ifndef SIGUIENDO_H
#define SIGUIENDO_H

#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Siguiendo
{
	private:
		string sigNombre;
		bool null;
		
	public:
		Siguiendo();
		Siguiendo(string);
		string getSigNombre();
		bool igual(Siguiendo);
		bool compare(Siguiendo);
		bool esNull();

};

#endif
