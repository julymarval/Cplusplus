#include "tweet.h"

//Constructor
Tweet::Tweet()
{
	cronologia = 0;
	usuNombre = "";
	mensaje = "";
	null = true;	
}

//Constructor
Tweet::Tweet(int _cronologia, string _mensaje)
{
	cronologia = _cronologia;
	usuNombre = "";
	mensaje = _mensaje;	
	null = false;
}

//Constructor
Tweet::Tweet(int _cronologia, string _usuNombre, string _mensaje)
{
	cronologia = _cronologia;
	usuNombre = _usuNombre;
	mensaje = _mensaje;	
	null = false;
}

//Retorna el indice cronologico del tweet
int Tweet::getCrono()
{
	return cronologia;
}

//Retorna el nombre de usuario que realizo el tweet
string Tweet::getUsuNombre()
{
	return usuNombre;
}

//Retorna el mensaje del tweet
string Tweet::getMensaje()
{
	return mensaje;
}

//Carga la cronologia de la creacion del tweet
void Tweet::setCrono(int _cronologia)
{
	cronologia = _cronologia;
}

//Carga el nombre de usuario que realizo el tweet
void Tweet::setUsuNombre(string _usuNombre)
{
	usuNombre = _usuNombre;
}

//Metodo empleado para determinar si un objetos de esta clase es mayor que otro, 
//disenado para ser usado solo con Lista() 
bool Tweet::compare(Tweet _tweet)
{	
	if (cronologia > _tweet.cronologia) {
		return true;
	} 
	return false;
}

//Indica si el objeto es nulo
bool Tweet::esNull()
{
	return null;
}
