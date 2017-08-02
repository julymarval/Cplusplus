#include "siguiendo.h"

//Constructor
Siguiendo::Siguiendo()
{
	sigNombre = "";	
	null = true;
}

//Constructor
Siguiendo::Siguiendo(string _sigNombre)
{
	sigNombre = _sigNombre;	
	null = false;
}

//Retorna el nombre de usuario seguido
string Siguiendo::getSigNombre()
{
	return sigNombre;
}

//Metodo empleado para determinar la igualdad entre dos objetos de esta clase, 
//disenado para ser usado solo con Lista() 
bool Siguiendo::igual(Siguiendo _siguiendo)
{
	if (sigNombre == _siguiendo.sigNombre) {
		return true;
	}
	return false;
}

//Metodo empleado para determinar si un objetos de esta clase es mayor que otro, 
//disenado para ser usado solo con Lista() 
bool Siguiendo::compare(Siguiendo _siguiendo)
{	
	string aux1 = "";
	string aux2 = "";
	for (int i = 1; i < sigNombre.length(); ++i){
        aux1 += tolower(sigNombre[i]);
    }
    for (int i = 1; i < _siguiendo.sigNombre.length(); ++i){
        aux2 += tolower(_siguiendo.sigNombre[i]);
    }
	if (strcmp(aux1.c_str(), aux2.c_str()) < 0) {
		return true;
	} 
	return false;
}

//Indica si el objeto es nulo
bool Siguiendo::esNull()
{
	return null;
}
