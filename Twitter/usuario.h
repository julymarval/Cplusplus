#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>
#include "lista.h"
#include "siguiendo.h"
#include "tweet.h"
using namespace std;

class Usuario
{
	private:
		string nombre;
		string correo;
		string usuNombre;
		string clave;
		Lista<Siguiendo> siguiendos;
		Lista<Tweet> tweets;
		bool null;
		
	public:
		Usuario();
		Usuario(string, string, string, string);		
		void addSiguiendo(Siguiendo);
		void delSiguiendo(Siguiendo);
		Lista<Siguiendo> getSiguiendos();
		bool estaSiguiendo(string);		
		void addTweet(Tweet);
		void delTweet(int);
		Lista<Tweet> getTweets();		
		string getNombre();
		string getCorreo();
		string getUsuNombre();
		string getClave();
		bool igual(Usuario);
		bool compare(Usuario);
		bool esNull();
		
};

#endif
