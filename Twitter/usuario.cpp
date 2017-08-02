#include "usuario.h"

//Constructor
Usuario::Usuario()
{
	nombre = "";
	correo = "";
	usuNombre = "";
	clave = "";	
	null = true;
}

//Constructor
Usuario::Usuario(string _nombre, string _correo, string _usuNombre, string _clave)
{
	nombre = _nombre;
	correo = _correo;
	usuNombre = _usuNombre;
	clave = _clave;
	null = false;
}

//Agrega un siguiendo a la lista de siguiendos del usuario
void Usuario::addSiguiendo(Siguiendo _siguiendo)
{
	siguiendos.agrOrden(_siguiendo);
}

//Elimina un siguiendo de la lista de siguiendos del usuario
void Usuario::delSiguiendo(Siguiendo _siguiendo)
{
	siguiendos.quitarEn(siguiendos.indiceDe(_siguiendo));
}

//Retorna la lista de siguiendos del usuario
Lista<Siguiendo> Usuario::getSiguiendos()
{
	return siguiendos;
}

//Indica si el usuario esta siguiendo a otro usuario determinado
bool Usuario::estaSiguiendo(string _usuNombre)
{
	return siguiendos.contiene(Siguiendo(_usuNombre));
}

//Agrega un tweet a la lista de tweets del usuario
void Usuario::addTweet(Tweet _tweet)
{
	tweets.agrOrden(_tweet);
}

//Elimina un tweet de la lista de tweets del usuario
void Usuario::delTweet(int _tweetIndice)
{
	tweets.quitarEn(_tweetIndice);
}

//Retorna la lista de siguiendos del usuario
Lista<Tweet> Usuario::getTweets()
{
	return tweets;
}

//Retorna el nombre del usuario
string Usuario::getNombre()
{
	return nombre;
}

//Retorna el correo electronico del usuario
string Usuario::getCorreo()
{
	return correo;
}

//Retorna el nombre de usuario
string Usuario::getUsuNombre()
{
	return usuNombre;
}

//Retorna la clave del usuario
string Usuario::getClave()
{
	return clave;
}

//Metodo empleado para determinar la igualdad entre dos objetos de esta clase, 
//disenado para ser usado solo con Lista() 
bool Usuario::igual(Usuario _usuario)
{
	if (correo == _usuario.correo || usuNombre == _usuario.usuNombre) {
		return true;
	}
	return false;
}

//Metodo empleado para determinar si un objetos de esta clase es mayor que otro, 
//disenado para ser usado solo con Lista() 
bool Usuario::compare(Usuario _usuario)
{	
	string aux1 = "";
	string aux2 = "";
	for (int i = 1; i < usuNombre.length(); ++i){
        aux1 += tolower(usuNombre[i]);
    }
    for (int i = 1; i < _usuario.usuNombre.length(); ++i){
        aux2 += tolower(_usuario.usuNombre[i]);
    }
	if (strcmp(aux1.c_str(), aux2.c_str()) < 0) {
		return true;
	} 
	return false;
}

//Indica si el objeto es nulo
bool Usuario::esNull()
{
	return null;
}

