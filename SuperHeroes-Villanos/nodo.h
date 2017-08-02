#ifndef NODO_H
#define NODO_H

#include <iostream>
using namespace std;

template <class Generica>
class Nodo
{
	public:
		int pos;
		Generica info;
		Nodo *sigNodo;
		
		Nodo();
		Nodo(Generica);
		void eliminar();	
};

//Constructor
template<typename Generica>
Nodo<Generica>::Nodo()
{
  sigNodo = NULL;
}

//Constructor
template<typename Generica>
Nodo<Generica>::Nodo(Generica _info)
{
  info = _info;
  sigNodo = NULL;
}

//Elimina el nodo
template<typename Generica>
void Nodo<Generica>::eliminar()
{
  delete this;
}

#endif
