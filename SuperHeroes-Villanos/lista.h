#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "nodo.h"
using namespace std;

template <class Generica>
class Lista
{
	private:
		int numNodos;
		Nodo<Generica> *inicio;
		
		void definirIndices();
		
	public:
		Lista();
		void agrInicio(Generica);
		void agrFinal(Generica);
		void agrOrden(Generica);
		Generica quiInicio();
		Generica quiFinal();
		Generica quitarEn(int);
		Generica* objetoEn(int);
		bool contiene(Generica);
		int indiceDe(Generica);
		int tamanno();
		void eliminar();		
};

//Constructor
template<typename Generica>
Lista<Generica>::Lista()
{
  numNodos = 0;
  inicio = NULL;
}

//Agrega al inicio
template<typename Generica>
void Lista<Generica>::agrInicio(Generica _info)
{
  Nodo<Generica> *temp = inicio;
  Nodo<Generica> *nuevo = new Nodo<Generica>(_info);
 
  if(inicio == NULL) {
    inicio = nuevo;
  } else {
    nuevo->sigNodo = inicio;
    inicio = nuevo;
  }
  definirIndices();
  numNodos++;
}


//Agrega al final
template<typename Generica>
void Lista<Generica>::agrFinal(Generica _info)
{
  Nodo<Generica> *temp = inicio;
  Nodo<Generica> *nuevo = new Nodo<Generica>(_info);
 
  if(inicio == NULL) {
      inicio = nuevo;
  } else {
    while(temp->sigNodo != NULL) {
      temp = temp->sigNodo;
    }
    temp->sigNodo = nuevo;
  }
  definirIndices();
  numNodos++;
}
 
//Ordena de mayor a menor de acuerdo a un criterio de comparacion, definido 
//en el metodo "compare()" de la clase "Generica", por tanto solo se ha de llamar
//a "agrOrden()", si y solo si, se ha definido dicho metodo, de lo contrario 
//habra un error en tiempo de ejecucion
template<typename Generica>
void Lista<Generica>::agrOrden(Generica _info)
{
  Nodo<Generica> *temp = inicio;
  Nodo<Generica> *nuevo = new Nodo<Generica>(_info);
 
  if(inicio == NULL) {
      inicio = nuevo;
  } else {
  	if (_info.compare(inicio->info)) {
  		nuevo->sigNodo = inicio;
    	inicio = nuevo;
  	} else {
  		while((temp->sigNodo != NULL) && (!_info.compare(temp->sigNodo->info))) {
      		temp = temp->sigNodo;
    	}
    	nuevo->sigNodo = temp->sigNodo;
    	temp->sigNodo = nuevo;
  	}
  }
  definirIndices();
  numNodos++;
} 
 
//Quitar al inicio
template<typename Generica>
Generica Lista<Generica>::quiInicio()
{
  Nodo<Generica> *temp = inicio;

  if(inicio != NULL) {
  	inicio = inicio->sigNodo;
  	definirIndices();
  	Generica retorno = temp->info;
  	temp->eliminar();
  	numNodos--;
  	return retorno;
  }
}

//Quitar al final
template<typename Generica>
Generica Lista<Generica>::quiFinal()
{
  Nodo<Generica> *temp = inicio;
  Nodo<Generica> *aux;
 
  if(inicio != NULL) {
  	if (numNodos == 1) {
  		inicio = temp->sigNodo;
  	} else {
		while(temp->sigNodo != NULL) {
			aux = temp;	
			temp = temp->sigNodo;
		}  	
		aux->sigNodo = temp->sigNodo;
  	}
  	definirIndices();
  	Generica retorno = temp->info;
  	temp->eliminar();
    numNodos--;
  	return retorno;
  }
}

//Quitar un objeto en el indice dado
template<typename Generica>
Generica Lista<Generica>::quitarEn(int _indice)
{
  Nodo<Generica> *temp = inicio;
  Nodo<Generica> *aux;
  
  while(temp != NULL) {
	   if (temp->pos == _indice) {
		  if (_indice == 0) {
		  	inicio = temp->sigNodo;
		  } else {
		  	aux->sigNodo = temp->sigNodo;
		  }
		  definirIndices();
	      Generica retorno = temp->info;
	      temp->eliminar();
	      numNodos--;
          return retorno;		
       }
	aux = temp;	
	temp = temp->sigNodo;
  }  	
}

//Retorna un apuntador al objeto en el indice dado
template<typename Generica>
Generica* Lista<Generica>::objetoEn(int _indice)
{
  Nodo<Generica> *temp = inicio;
	
  while(temp != NULL) {
  	if (temp->pos == _indice) {
  		Generica *retorno = &temp->info;
		return retorno;		
  	}
    temp = temp->sigNodo;
  }
  return NULL;
}
 
//Indica si un objeto dado forma parte de la lista
template<typename Generica>
bool Lista<Generica>::contiene(Generica _info)
{
  int indice = indiceDe(_info);
  if (indice != -1) {
	return true;		
  }
  return false;
}  
  
//Retorna el indice de un objeto dado que forme parte de la lista, para ello se emplea 
//el metodo "igual()" de la clase "Generica", por tanto solo se ha de llamar
//a "contiene()", si y solo si, se ha definido dicho metodo, de lo contrario 
//habra un error en tiempo de ejecucion  
template<typename Generica>
int Lista<Generica>::indiceDe(Generica _info)
{
  Nodo<Generica> *temp = inicio;
  while(temp != NULL) {
  	if (_info.igual(temp->info)) {
	  return temp->pos;		
  	}
    temp = temp->sigNodo;
  }
  return -1;
}   
  
//Indica el munero de nodos en la lista
template<typename Generica>
int Lista<Generica>::tamanno()
{
  return numNodos;
}  
  
//Elimina todos los nodos
template<typename Generica>
void Lista<Generica>::eliminar()
{
  Nodo<Generica> *temp = inicio;
  Nodo<Generica> *aux;
	
  while(temp != NULL) {
    aux = temp;	
    temp = temp->sigNodo;
    aux->eliminar();
  }
  numNodos = 0;
  inicio = NULL;
}

//Define la posicion de cada nodo
template<typename Generica>
void Lista<Generica>::definirIndices()
{
  int indice = 0;
  Nodo<Generica> *temp = inicio;
 
  while(temp != NULL) {
    temp->pos = indice;	
    temp = temp->sigNodo;
    indice++;
  }
}

#endif
