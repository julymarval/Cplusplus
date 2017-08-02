#include "estacion.h"
#include "lista.h"

//Constructor
Estacion::Estacion()
{
  nombre = "";
  x = 0;
  y = 0;
}

//Constructor
Estacion::Estacion(string _nombre, int _x, int _y)
{
  nombre = _nombre;
  x = _x;
  y = _y;
}

//Retorna el nombre de la estacion
string Estacion::obtNombre()
{
  return nombre;
}
	
//Retorna la cordenada x de la estacion
int Estacion::obtX()
{
  return x;
}

//Retorna la cordenada y de la estacion
int Estacion::obtY()
{
  return y;
}	

//Metodo empleado para determinar la igualdad entre dos objetos de esta clase, 
//disenado para ser usado solo con Lista() 
bool Estacion::igual(Estacion _estacion)
{
  if (nombre == _estacion.nombre) {
  	return true;
  }
  return false;
}
