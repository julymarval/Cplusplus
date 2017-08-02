#ifndef ARCHIVODB_H
#define ARCHIVODB_H

#include <iostream>
#include <fstream>
#include <string>
#include "lista.h"
#include "usuario.h"
#include "siguiendo.h"
#include "tweet.h"
using namespace std;

class ArchivoDB
{
	private:
		Lista<Usuario> tableUsuarios;
		int crono;
				
	public:
		ArchivoDB();
		bool cargarDB();
		bool guardarDB();
		bool insertarUsu(Usuario);
		Usuario selecionarUsu(string);
		Lista<Usuario> seguidoresUsu(string);
		Lista<Siguiendo> siguiendosUsu(string);
		bool insertarTweet(string, Tweet);
		bool borrarTweet(string, int);
		Lista<Tweet> tweetUsus(Lista<Siguiendo>);
		bool insertarSiguiendo(string, Siguiendo);
		bool borrarSiguiendo(string, Siguiendo);
		Lista<Siguiendo> selecSigConExcepcion(Lista<Siguiendo>);
};

#endif
