#include "vertice.h"
#include "lista.h"

//Constructor
Vertice::Vertice()
{
  id = -1;
  aristaAcumulada = 0;
  padre = -1;
}

//Constructor
Vertice::Vertice(int _id)
{
  id = _id;
  aristaAcumulada = 0;
  padre = -1;
}

//Agrega la secuensia dentro de la ruta
void Vertice::agrSecuencia(float _aristaAcumulada, int _padre)
{
  aristaAcumulada = _aristaAcumulada;
  padre = _padre;
}

//Agrega el id de un vertice hijo y la arista hasta el
void Vertice::agrHijo(int _hijo, float _arista)
{
  hijos.agrFinal(_hijo);
  aristaHijo.agrFinal(_arista);
}

//Retorna el id de un vertice hijo de acuerdo al indice, este indice depende 
//del orden en que el hijo fue agregado
int Vertice::obtHijo(int _indice)
{
  int *aux = hijos.objetoEn(_indice);	
  if (aux == NULL) {
  	return -1;
  }
  return *aux;	
}

//Retorna el tamano de la harista que une al vertice con el hijo de acuerdo 
//al indice, este indice depende del orden en que el hijo fue agregado
float Vertice::obtArista(int _indice)
{
  float *aux = aristaHijo.objetoEn(_indice);	
  if (aux == NULL) {
  	return -1;
  }
  return *aux;
}

//Retorna el numero de hijos
int Vertice::totalHijos()
{
  return hijos.tamanno();
}

//Metodo empleado para determinar la igualdad entre dos objetos de esta clase, 
//disenado para ser usado solo con Lista() 
bool Vertice::igual(Vertice _vertice)
{
  if (id == _vertice.id) {
  	return true;
  }
  return false;
}
