#include "archivodb.h"

//Constructor
ArchivoDB::ArchivoDB()
{
	crono = 0;	
}

//Lee el archivo y carga las listas
bool ArchivoDB::cargarDB()
{	
	bool usu = false;
	bool sig = false;
	bool twe = false;
	
	ifstream archivo("entrada.in");
    if (archivo.fail()){
    	return false;	
    } else {	    	
    	int x;
    	int y;    	
    	int tipo = 0;
		char linea[192];
		string auxStr1;
		string auxStr2;
		string auxStr3;
		string auxStr4;
		string auxLinea;
    	
    	while(!archivo.eof())
	    {
	        archivo.getline(linea, sizeof(linea));	        
	        auxLinea = string(linea);
	        
	        if (auxLinea == "usuarios"){
	        	tipo = 1;
				archivo.getline(linea, sizeof(linea));	        
	        	auxLinea = string(linea);
				usu = true;	
	        } else
	        if (auxLinea == "siguiendos"){
	        	tipo = 2;
				archivo.getline(linea, sizeof(linea));	        
	        	auxLinea = string(linea);
				sig = true;		
	        } else
	        if (auxLinea == "tweets"){		
	        	tipo = 3;
	        	archivo.getline(linea, sizeof(linea));	        
	        	auxLinea = string(linea);
	        	twe = true;
	        }
	        
	        switch(tipo) {			
				case 1:{
					if (auxLinea.find_first_not_of(" \t\n") != string::npos){
						x = auxLinea.find(" ", 0);
						auxStr1 = auxLinea.substr(0, x);
						++x;
						
						y = auxLinea.find(" ", x);
						auxStr2 = auxLinea.substr(x, (y-x));
						++y;
						
						x = auxLinea.find(" ", y);
						auxStr3 = auxLinea.substr(y, (x-y));
						++x;
						
						y = auxLinea.length();
						auxStr4 = auxLinea.substr(x, (y-x));
						
						tableUsuarios.agrInicio(Usuario(auxStr1, auxStr2, auxStr3, auxStr4));
					}
					break;
				}			
				case 2:{
					if (auxLinea.find_first_not_of(" \t\n") != string::npos){
						x = auxLinea.find(" ", 0);
						auxStr1 = auxLinea.substr(0, x);
						++x;
					
						y = auxLinea.length();
						auxStr2 = auxLinea.substr(x, (y-x));
											
						tableUsuarios.objetoEn(tableUsuarios.indiceDe(Usuario(" ", auxStr1, auxStr1, " ")))->addSiguiendo(Siguiendo(auxStr2));
					}
					break;
				}					
				case 3:{
					if (auxLinea.find_first_not_of(" \t\n") != string::npos){
						x = auxLinea.find(" ", 0);
						auxStr1 = auxLinea.substr(0, x);
						++x;
					
						y = auxLinea.length();
						auxStr2 = auxLinea.substr(x, (y-x));
						
						tableUsuarios.objetoEn(tableUsuarios.indiceDe(Usuario(" ", auxStr1, auxStr1, " ")))->addTweet(Tweet(crono, auxStr2));
						++crono;
					}
					break;
				}		
			}
	    }
    }
	
    archivo.close();
    
    return (usu && sig && twe);    
}

//Guarda en el archivo el contenido de las listas
bool ArchivoDB::guardarDB()
{	
	bool usu = true;
	bool sig = true;
	bool twe = true;
	
	ofstream archivo("entrada.in");
    if (archivo.fail()){
    	return false;	
    } else {	    	
		Lista<Tweet> tweetsAux;
		
		archivo << "usuarios" << endl;
		for(int i = 0; i < tableUsuarios.tamanno(); i++){
			Usuario auxUsuario = *tableUsuarios.objetoEn(i);
			Lista<Tweet> tweets = auxUsuario.getTweets();
			for(int x = 0; x < tweets.tamanno(); x++){
				Tweet auxTweet = *tweets.objetoEn(x);
				auxTweet.setUsuNombre(auxUsuario.getUsuNombre());
				tweetsAux.agrOrden(auxTweet);
			}
			archivo << auxUsuario.getNombre() << " " << auxUsuario.getCorreo() << " " << auxUsuario.getUsuNombre() << " " << auxUsuario.getClave() << endl;		
		    if (archivo.fail()){
                usu = false;
            }
		}
		
		archivo << "siguiendos" << endl;
		for(int i = 0; i < tableUsuarios.tamanno(); i++){
			Usuario auxUsuario = *tableUsuarios.objetoEn(i);
		    Lista<Siguiendo> siguiendos = auxUsuario.getSiguiendos();
			for(int x = 0; x < siguiendos.tamanno(); x++){
				Siguiendo auxSiguiendo = *siguiendos.objetoEn(x);
				archivo << auxUsuario.getUsuNombre() << " " << auxSiguiendo.getSigNombre() << endl;
				if (archivo.fail()){
                	sig = false;
            	}
			}	
		}
		
		archivo << "tweets" << endl;
		while (tweetsAux.tamanno() != 0){
			Tweet auxTweet = tweetsAux.quiFinal();
			archivo << auxTweet.getUsuNombre() << " " << auxTweet.getMensaje() << endl;
			if (archivo.fail()){
                twe = false;
            }
		}	
	}
    archivo.close();
	return (usu && sig && twe);  
}

//Inserta un usuario en la lista, y valida que no exista en esta
bool ArchivoDB::insertarUsu(Usuario _usuario)
{
	if (tableUsuarios.contiene(_usuario)){
		return false;
	} else {
		tableUsuarios.agrInicio(_usuario);		
		return true;	
	}	
}

//Retorna la irformacion del usuario, de acuerdo al parametro dado (nombre de usuario o correo)
Usuario ArchivoDB::selecionarUsu(string _usuNombre)
{
	int indice = tableUsuarios.indiceDe(Usuario(" ", _usuNombre, _usuNombre, " "));
	if (indice != -1){
		return *tableUsuarios.objetoEn(indice);
	} else {		
		return Usuario();	
	}	
}

//Retorna la lista de usuarios que siguen a un usuario determinado
Lista<Usuario> ArchivoDB::seguidoresUsu(string _usuNombre)
{
	Lista<Usuario> auxList;
	for(int i = 0; i < tableUsuarios.tamanno(); i++){
		Usuario auxUsuario = *tableUsuarios.objetoEn(i);
		if (auxUsuario.estaSiguiendo(_usuNombre)){
			auxList.agrOrden(auxUsuario);	
		}		
	}
	return auxList;
}

//Retorna la lista de siguiendos de un usuario determinado
Lista<Siguiendo> ArchivoDB::siguiendosUsu(string _usuNombre)
{
	Lista<Siguiendo> auxList;
	int indice = tableUsuarios.indiceDe(Usuario(" ", _usuNombre, _usuNombre, " ")); 
	if (indice != -1){
		auxList = tableUsuarios.objetoEn(indice)->getSiguiendos();
	}	
	return auxList;
}

//Agrega un tweet al listado de tweets de un usuario determinado
bool ArchivoDB::insertarTweet(string _usuNombre, Tweet _tweet)
{
	_tweet.setCrono(crono);
	int indice = tableUsuarios.indiceDe(Usuario(" ", _usuNombre, _usuNombre, " ")); 
	if (indice != -1){
		tableUsuarios.objetoEn(indice)->addTweet(_tweet);
		++crono;
		return true;	
	}
	return false;
}

//Elimina un tweet del listado de tweets de un usuario determinado
bool ArchivoDB::borrarTweet(string _usuNombre, int _tweetIndice)
{
	int indice = tableUsuarios.indiceDe(Usuario(" ", _usuNombre, _usuNombre, " ")); 
	if (indice != -1){
		Usuario *auxUsuario = tableUsuarios.objetoEn(indice);
		if (_tweetIndice < auxUsuario->getTweets().tamanno() && _tweetIndice >= 0){
			auxUsuario->delTweet(_tweetIndice);
			return true;
		}	
	}
	return false;
}

//Retorna una lista de tweets formada por los tweets de un conjunto de usuarios determinado
Lista<Tweet> ArchivoDB::tweetUsus(Lista<Siguiendo> _siguiendo)
{
	Lista<Tweet> auxList;	
	for(int i = 0; i < _siguiendo.tamanno(); i++){
		string auxUsuNombre = _siguiendo.objetoEn(i)->getSigNombre();
		int indice = tableUsuarios.indiceDe(Usuario(" ", auxUsuNombre, auxUsuNombre, " ")); 
		if (indice != -1){
			auxList.concatListaOrden(tableUsuarios.objetoEn(indice)->getTweets());
		}	
	}		
	return auxList;
}

//Agrega un siguiendo al listado de siguiendos de un usuario determinado
bool ArchivoDB::insertarSiguiendo(string _usuNombre, Siguiendo _siguiendo)
{
	int indice = tableUsuarios.indiceDe(Usuario(" ", _usuNombre, _usuNombre, " ")); 
	if (indice != -1){
		Usuario *auxUsuario = tableUsuarios.objetoEn(indice);
		if (!auxUsuario->estaSiguiendo(_siguiendo.getSigNombre())){
			auxUsuario->addSiguiendo(_siguiendo);
			return true;	
		}	
	}
	return false;
}

//Elimina un siguiendo del listado de siguiendos de un usuario determinado
bool ArchivoDB::borrarSiguiendo(string _usuNombre, Siguiendo _siguiendo)
{
	int indice = tableUsuarios.indiceDe(Usuario(" ", _usuNombre, _usuNombre, " ")); 
	if (indice != -1){
		Usuario *auxUsuario = tableUsuarios.objetoEn(indice);
		if (auxUsuario->estaSiguiendo(_siguiendo.getSigNombre())){
			auxUsuario->delSiguiendo(_siguiendo);
			return true;	
		}	
	}
	return false;
}

//Retorna un lista de siguiendos exceptuando a un conjunto de siguiendos determinados
Lista<Siguiendo> ArchivoDB::selecSigConExcepcion(Lista<Siguiendo> _siguiendo)
{
	Lista<Siguiendo> auxList;
	for(int i = 0; i < tableUsuarios.tamanno(); i++){
		Usuario auxUsuario = *tableUsuarios.objetoEn(i);
		auxList.agrOrden(Siguiendo(auxUsuario.getUsuNombre()));		
	}
	for(int i = 0; i < _siguiendo.tamanno(); i++){
		Siguiendo auxSiguiendo = *_siguiendo.objetoEn(i);
		int indice = auxList.indiceDe(auxSiguiendo); 
		if (indice != -1){
			auxList.quitarEn(indice);
		}	
	}	
	return auxList;
}



