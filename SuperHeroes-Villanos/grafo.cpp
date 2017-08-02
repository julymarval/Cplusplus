#include "grafo.h"
#include "vertice.h"
#include "lista.h"

//Constructor
Grafo::Grafo()
{

}

//Constructor
Grafo::Grafo(int _numeroVertices)
{
  for(int i = 0; i < _numeroVertices; i++){
  	Vertice nuevo(i);
    vertices.agrFinal(nuevo);
  }
}

//Agrega un vertice
void Grafo::agrVertice()
{
  Vertice nuevo(vertices.tamanno());
  vertices.agrFinal(nuevo);
}

//Agrega una conexion entre los vertices
void Grafo::agrConexion(int _padre, int _hijo, float _distancia)
{
	vertices.objetoEn(_padre)->agrHijo(_hijo, _distancia);
	vertices.objetoEn(_hijo)->agrHijo(_padre, _distancia);
}

//Encuentra la ruta mas corta desde el nodo inicial a un nodo final
Lista<int> Grafo::RutaMinimaEntreNodos(int _inicio, int _fin)
{
	Lista<int> rutaCorta;
	Lista<Vertice> verticesRevisados = RutaMinima(_inicio);

	Vertice final = *vertices.objetoEn(_fin);
	if (!verticesRevisados.contiene(final)) {
		return rutaCorta;
	}
	
	Vertice temp = *verticesRevisados.objetoEn(verticesRevisados.indiceDe(_fin));
	rutaCorta.agrFinal(temp.id);
	while(temp.padre != -1) {
    	temp = *verticesRevisados.objetoEn(verticesRevisados.indiceDe(temp.padre));
    	rutaCorta.agrFinal(temp.id);
 	}
 	return rutaCorta;
}

//Encuentra la ruta mas corta desde el nodo inicial a todos los demas
Lista<Vertice> Grafo::RutaMinima(int _inicio)
{
	Lista<Vertice> colaConsulta;
	Lista<Vertice> listaConsutado;
	Vertice inicial = *vertices.objetoEn(_inicio);
	
	colaConsulta.agrFinal(inicial);
	while (colaConsulta.tamanno() != 0) {
		Vertice temp = colaConsulta.quiInicio();	
		listaConsutado.agrFinal(temp);
		for(int i = 0; i < temp.totalHijos(); i++){
			Vertice hijo = *vertices.objetoEn(temp.obtHijo(i));
			if (!listaConsutado.contiene(hijo)) {
				hijo.agrSecuencia((temp.aristaAcumulada + temp.obtArista(i)), temp.id);	
				if (!colaConsulta.contiene(hijo)) {
					colaConsulta.agrFinal(hijo);
				} else {
					int indice = colaConsulta.indiceDe(hijo);
					Vertice *aux = colaConsulta.objetoEn(indice);
					if (aux->aristaAcumulada > hijo.aristaAcumulada) {
						colaConsulta.quitarEn(indice);
						colaConsulta.agrFinal(hijo);	
					}
				}
			}
		}
	}
	return listaConsutado;	
}


