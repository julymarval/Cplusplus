#include "supers.h"

//Constructor
Supers::Supers()
{
  nombre = "";
  ataque = 0;
  resistencia = 0;
}

//Constructor
Supers::Supers(string _nombre, int _ataque, int _resistencia)
{
  nombre = _nombre;
  ataque = _ataque;
  resistencia = _resistencia;
}

//Retorna el nombre del super
string Supers::obtNombre()
{
  return nombre;
}

//Retorna el ataque del super
int Supers::obtAtaque()
{
  return ataque;
}

//Retorna la resistencia del super
int Supers::obtResistencia()
{
  return resistencia;
}

//Actualiza la resitencia del super segun el dano recivido
void Supers::recivirDano(int _dano)
{
  resistencia = resistencia - _dano;
}

//Indica si el super esta vivo, retorna false si su resistencia llega a cero
bool Supers::estaVido()
{
  if (resistencia <= 0) {
  	return false;
  }
  return true;
}

//Metodo empleado para determinar si un objetos de esta clase es mayor que otro, 
//disenado para ser usado solo con Lista() 
bool Supers::compare(Supers _supers)
{
  if (ataque > _supers.obtAtaque()) {
  	return true;
  } 
  if (ataque == _supers.obtAtaque()) {
 	  if (resistencia > _supers.obtResistencia()) {
 		return true;
	  }
  }
  return false;
}

