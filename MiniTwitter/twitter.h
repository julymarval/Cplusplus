#ifndef TWITTER_H
#define TWITTER_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include "archivodb.h"
#include "lista.h"
#include "usuario.h"
#include "siguiendo.h"
#include "tweet.h"
using namespace std;

class Twitter
{
	private:
		ArchivoDB archBD;
		string usuNombre;
		
	public:
		Twitter();
		bool regUsuario(string, string, string, string);
		bool iniSesion(string, string);	
		bool verSeguidores(string);
		bool verSiguiendos(string);
		bool crearTweet(string);
		bool verTweets(string);
		bool eliminarTweet();
		Lista<Siguiendo> verUsuSeguibles(string);
		bool seguirUsu();
		bool dejarSeguirUsu();
		bool verMuro();
		bool guardarArchivo();
		
};

#endif
