#include "twitter.h"

//Constructor
Twitter::Twitter()
{
	archBD.cargarDB();
}

//Registra un usuario
bool Twitter::regUsuario(string _nombre, string _correo, string _usuNombre, string _clave)
{	
	return archBD.insertarUsu(Usuario(_nombre, _correo, _usuNombre, _clave));
}

//Registra un usuario
bool Twitter::iniSesion(string _usuNombre, string _clave)
{	
	Usuario auxUsu = archBD.selecionarUsu(_usuNombre);
	if (!auxUsu.esNull()){
		if (auxUsu.getClave() == _clave){
			usuNombre = _usuNombre; 
			return true;	
		}
	}
	return false;
}

//Muestras el listados de seguidores de un usuario determinado
bool Twitter::verSeguidores(string _usuNombre)
{	
	Lista<Usuario> auxUsu = archBD.seguidoresUsu(_usuNombre);
	if (auxUsu.tamanno() == 0){
		cout << "El usuario no posee seguidores" << endl;
		return false;
	} else {
		for(int i = 0; i < auxUsu.tamanno(); i++){
			cout << auxUsu.objetoEn(i)->getUsuNombre() << endl;
		}
		return true;
	}
}

//Muestras el listados de seguiendos de un usuario determinado
bool Twitter::verSiguiendos(string _usuNombre)
{
	Lista<Siguiendo> auxSiguiendos = archBD.siguiendosUsu(_usuNombre);
	if (auxSiguiendos.tamanno() == 0){
		cout << "El usuario no esta siguendo a alguien" << endl;
		return false;
	} else {
		for(int i = 0; i < auxSiguiendos.tamanno(); i++){
			cout << auxSiguiendos.objetoEn(i)->getSigNombre() << endl;
		}
		return true;
	}
}

//Crea un tweet
bool Twitter::crearTweet(string _tweet)
{
	if (_tweet.size() <= 140 && (_tweet.find_first_not_of(" \t\n") != string::npos)){
		archBD.insertarTweet(usuNombre, Tweet(0, _tweet));
		cout << "Tweet guardado con \202xito" << endl;
		return true;
	} else {
		cout << "El tweet debe tener un m\240ximo de 140 caracteres y no estar vacio" << endl;
		return false;	
	}
}

//Muestras el listados de tweets de un usuario determinado
bool Twitter::verTweets(string _usuNombre)
{
	Lista<Siguiendo> auxSiguiendos;
	auxSiguiendos.agrInicio(Siguiendo(_usuNombre));
	
	Lista<Tweet> auxTweets = archBD.tweetUsus(auxSiguiendos);
	
	if (auxTweets.tamanno() == 0){
		cout << "El usuario no posee tweets" << endl;
		return false;
	} else {
		for(int i = 0; i < auxTweets.tamanno(); i++){
			cout << "     " << i + 1 << ") " << auxTweets.objetoEn(i)->getMensaje() << endl;
		}
		return true;
	}
}

//Elimina un tweet del usuario
bool Twitter::eliminarTweet()
{
	if (verTweets(usuNombre)){	
		string linea;							
		cout << endl;
		cout << "\t" << "Seleccion: ";
		getline(cin, linea, '\n');
		
		bool auxBool = false;		
		int tweetIndice = atoi(linea.c_str());				
		if (tweetIndice != 0){
			--tweetIndice;
			auxBool = archBD.borrarTweet(usuNombre, tweetIndice);
		}
		if (auxBool){
			cout << "Tweet eliminado con \202xito" << endl;
			return true;
		} else {
			cout << "Seleccion invalida" << endl;
		}		
	}
	return false;
}

//Muestras el listados de usuarios que un usuario determinado puede seguir
Lista<Siguiendo> Twitter::verUsuSeguibles(string _usuNombre)
{
	Lista<Siguiendo> auxSiguiendos;
	auxSiguiendos.agrInicio(Siguiendo(_usuNombre));
	
	auxSiguiendos = archBD.selecSigConExcepcion(auxSiguiendos);
	
	if (auxSiguiendos.tamanno() == 0){
		cout << "No hay usuarios validos" << endl;
		return auxSiguiendos;
	} else {
		for(int i = 0; i < auxSiguiendos.tamanno(); i++){
			cout << "     " << i + 1 << ") " << auxSiguiendos.objetoEn(i)->getSigNombre() << endl;
		}
		return auxSiguiendos;
	}
}

//Asigna al usuario un siguiendo
bool Twitter::seguirUsu()
{
	Lista<Siguiendo> auxSiguiendos = verUsuSeguibles(usuNombre);
	if (auxSiguiendos.tamanno() != 0){
		string linea;								
		cout << endl;
		cout << "\t" << "Seleccion: ";
		getline(cin, linea, '\n');
				
		int sigIndice = atoi(linea.c_str());
		--sigIndice;				
		if (sigIndice != -1 && sigIndice < auxSiguiendos.tamanno() && sigIndice >= 0){			
			Siguiendo auxSiguiendo = *auxSiguiendos.objetoEn(sigIndice);
			if (archBD.insertarSiguiendo(usuNombre, auxSiguiendo)){
				cout << "Usuario seguido con \202xito" << endl;
				return true;
			} else {
				cout << "El usuario ya est\240 siendo seguido" << endl;
			}
		} else {
			cout << "Seleccion invalida" << endl;	
		}		
	}
	return false;
}

//Retira un siguiendo al usuario
bool Twitter::dejarSeguirUsu()
{
	Lista<Siguiendo> auxSiguiendos = verUsuSeguibles(usuNombre);
	if (auxSiguiendos.tamanno() != 0){
		string linea;								
		cout << endl;
		cout << "\t" << "Seleccion: ";
		getline(cin, linea, '\n');
				
		int sigIndice = atoi(linea.c_str());
		--sigIndice;				
		if (sigIndice != -1 && sigIndice < auxSiguiendos.tamanno() && sigIndice >= 0){			
			Siguiendo auxSiguiendo = *auxSiguiendos.objetoEn(sigIndice);
			if (archBD.borrarSiguiendo(usuNombre, auxSiguiendo)){
				cout << "Operacion exitosa" << endl;
				return true;
			} else {
				cout << "El usuario no est\240 siendo seguido" << endl;
			}
		} else {
			cout << "Seleccion invalida" << endl;	
		}		
	}
	return false;
}

//Muestras el listado de tweets que el usuario puede ver
bool Twitter::verMuro()
{
	Lista<Siguiendo> auxSiguiendos;
	auxSiguiendos = archBD.siguiendosUsu(usuNombre).copiarLista();
	auxSiguiendos.agrInicio(Siguiendo(usuNombre));
	
	Lista<Tweet> auxTweets = archBD.tweetUsus(auxSiguiendos);
	
	if (auxTweets.tamanno() == 0){
		cout << "No hay tweets que mostrar" << endl;
		return false;
	} else {
		for(int i = 0; i < auxTweets.tamanno(); i++){
			cout << "     " << i + 1 << ") " << auxTweets.objetoEn(i)->getMensaje() << endl;
		}
		return true;
	}
}

//Guarda los cambios hechos
bool Twitter::guardarArchivo()
{
	if (archBD.guardarDB()){
		cout << "Documento guardado con \202xito" << endl;
		return true;
	} else {
		cout << "Error al guardar el documento" << endl;
		return false;
	}
}



