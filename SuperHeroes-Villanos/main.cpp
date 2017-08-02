#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include "lista.h"
#include "estacion.h"
#include "grafo.h"
#include "supers.h"
using namespace std;

float calcularDistancia(int _x1, int _y1, int _x2, int _y2)
{
	return sqrt((_x1 - _x2)*(_x1 - _x2) + (_y1 - _y2)*(_y1 - _y2));
}

float calcularDistanciaEstaciones(Estacion* _origen, Estacion* _destino)
{
	int x1 = _origen->obtX();
	int y1 = _origen->obtY();
	int x2 = _destino->obtX();
	int y2 = _destino->obtY();
	return calcularDistancia(x1, y1, x2, y2);
}

string imprimirCiudades(Lista<Estacion> _estaciones, Lista<int> _ruta)
{
	string aux = "";
	int max = _ruta.tamanno();	
	for(int i = 0; i < max; i++){
		aux = aux + (_estaciones.objetoEn(_ruta.quiFinal())->obtNombre()) + " ";
	}	
	return aux;
}

void batallas(Lista<Supers> _heroes, Lista<Supers> _villanos)
{
	while ((_heroes.tamanno() != 0) && (_villanos.tamanno() != 0)) {
		Supers *heroe = _heroes.objetoEn(0);
		Supers *villano = _villanos.objetoEn(0);
		cout << heroe->obtNombre() << " " << villano->obtNombre() << endl;
		
		villano->recivirDano(heroe->obtAtaque());
		if (!villano->estaVido()) {
			_villanos.quiInicio();	
		} else {
			heroe->recivirDano(villano->obtAtaque());
			if (!heroe->estaVido()) {
				_heroes.quiInicio();
			}	
		}
	}
}

int main() 
{	
	Grafo metro;
	Lista<Estacion> estaciones;
	Lista<Supers> heroes;
	Lista<Supers> villanos;
	

	string linea;
	string data1Str;
	string data2Str;
	string data3Str;
	int data1;
	int data2;
	
	int origenIndice;
	int destinoIndice;	
	int tiempoBomba;
	
	
	//Precargado para Pruebas
	//(Descomentar y no ingresar datos durante la 
	// carga, y terminar con la ruta Origen-Destino)
	//Ej: 
	//	heroes 
	//	villanos 
	//	Miranda Chacao 3
	//	 
	//Solo ingresar los datos para seguir al siguiente paso)
	
	/*
	float distancia;
	Estacion estacion1("Caracas", 0, 0);
	estaciones.agrFinal(estacion1);
	metro.agrVertice();
	
	Estacion estacion2("Chacao", 2, 1);
	estaciones.agrFinal(estacion2);
	metro.agrVertice();
	
	Estacion estacion3("Gotica", 0, 1);
	estaciones.agrFinal(estacion3);
	metro.agrVertice();
	
	Estacion estacion4("Miranda", 3, 4);
	estaciones.agrFinal(estacion4);
	metro.agrVertice();
	
	Estacion estacion5("California", 1, 5);
	estaciones.agrFinal(estacion5);
	metro.agrVertice();

	distancia = calcularDistanciaEstaciones(estaciones.objetoEn(0), estaciones.objetoEn(1));
	metro.agrConexion(0, 1, distancia);
	
	distancia = calcularDistanciaEstaciones(estaciones.objetoEn(0), estaciones.objetoEn(3));
	metro.agrConexion(0, 3, distancia);
	
	distancia = calcularDistanciaEstaciones(estaciones.objetoEn(0), estaciones.objetoEn(4));
	metro.agrConexion(0, 4, distancia);
	
	distancia = calcularDistanciaEstaciones(estaciones.objetoEn(4), estaciones.objetoEn(3));
	metro.agrConexion(4, 3, distancia);
	
	Supers heroe1("IronMan", 20, 15);
	heroes.agrOrden(heroe1);
	
	Supers heroe2("SuperMan", 20, 20);
	heroes.agrOrden(heroe2);
	
	Supers heroe3("SpiderMan", 10, 10);
	heroes.agrOrden(heroe3);
	
	Supers heroe4("Hulk", 15, 50);
	heroes.agrOrden(heroe4);
	
	Supers villano1("Aldrich", 15, 15);
	villanos.agrFinal(villano1);
	
	Supers villano2("Venom", 30, 30);
	villanos.agrFinal(villano2);
	
	Supers villano3("Joker", 8, 8);
	villanos.agrFinal(villano3);
	*/

	//ENTRADA
	
	bool continua = true;
	do {
		getline(cin, linea, '\n');
		
		if (linea != "heroes") {
			int espacio = 0;
			for(int i = linea.find(" ", 0); i != string::npos; i = linea.find(" ", i)) {
	    		espacio++;
	    		i++;
			}		
					
			if (espacio == 2) {
				//Agregar una Ciudad
				
				int x = linea.find(" ", 0);
				data1Str = linea.substr(0, x);
				int y = linea.find(" ", ++x);
				data2Str = linea.substr(x, (y-x));
				int z = linea.length();
				data3Str = linea.substr(++y, (z-y));
				
				data1 = atoi( data2Str.c_str());
				data2 = atoi( data3Str.c_str());
				
				Estacion estacionAux(data1Str, data1, data2);
				estaciones.agrFinal(estacionAux);
				metro.agrVertice();

			} 
			if (espacio == 1) {
				//Agregar una Conexion
				
				int x = linea.find(" ", 0);		
				data1Str = linea.substr(0, x);
				int y = linea.find(" ", ++x);
				data2Str = linea.substr(x, (y-x));
				
				data1 = atoi( data1Str.c_str());
				data2 = atoi( data2Str.c_str());
				
				float distanciaAux = calcularDistanciaEstaciones(estaciones.objetoEn(data1), estaciones.objetoEn(data2));
				metro.agrConexion(data1, data2, distanciaAux);

			}
		} else {
			continua = false;
		}
			
	} while (continua);
	
	continua = true;
	do {
		getline(cin, linea, '\n');
	
		if (linea != "villanos") {
			//Agregar un Heroe
			
			int x = linea.find(" ", 0);
			data1Str = linea.substr(0, x);
			int y = linea.find(" ", ++x);
			data2Str = linea.substr(x, (y-x));
			int z = linea.length();
			data3Str = linea.substr(++y, (z-y));
			
			data1 = atoi( data2Str.c_str());
			data2 = atoi( data3Str.c_str());
			
			Supers heroeAux(data1Str, data1, data2);
			heroes.agrOrden(heroeAux);
		
		} else {
			continua = false;
		}
				
	} while (continua);
	
	continua = true;
	do {
		getline(cin, linea, '\n');
		
		int x = linea.find(" ", 0);		//Nota al Usuario:
		data1Str = linea.substr(0, x);	//El proyecto no plantea una forma clara 
		Estacion aux(data1Str, 0, 0);	//para condicionar, al momento de ingresar el origen y destino
		
		if (!estaciones.contiene(aux)) {
			//Agregar un Villano
		
			int x = linea.find(" ", 0);
			data1Str = linea.substr(0, x);
			int y = linea.find(" ", ++x);
			data2Str = linea.substr(x, (y-x));
			int z = linea.length();
			data3Str = linea.substr(++y, (z-y));
			
			data1 = atoi( data2Str.c_str());
			data2 = atoi( data3Str.c_str());
			
			Supers villanoAux(data1Str, data1, data2);
			villanos.agrFinal(villanoAux);
	
		} else {
			//Agregar Origen-Destino
			
			int x = linea.find(" ", 0);
			data1Str = linea.substr(0, x);
			int y = linea.find(" ", ++x);
			data2Str = linea.substr(x, (y-x));
			int z = linea.length();
			data3Str = linea.substr(++y, (z-y));
			
			Estacion aux1(data1Str, 0, 0);
			origenIndice = estaciones.indiceDe(aux1);
			Estacion aux2(data2Str, 0, 0);
			destinoIndice = estaciones.indiceDe(aux2);
			tiempoBomba = atoi( data3Str.c_str());

			continua = false;			
		}
		
	} while (continua);
	
	cout << endl;
	
	//SALIDA
	
	Lista<int> rutaCorta = metro.RutaMinimaEntreNodos(origenIndice , destinoIndice);
	
	if ((rutaCorta.tamanno() <= tiempoBomba) && (rutaCorta.tamanno() != 0)) {
		string rutaEstaciones = imprimirCiudades(estaciones, rutaCorta);
	
		cout << "Yes " << rutaEstaciones << endl;
		
		batallas(heroes, villanos);
	} else {	
		cout << "No" << endl;
	}
	
	return 0;
}

