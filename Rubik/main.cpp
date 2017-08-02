#include <iostream>
#include <string>
#include "rubik.h"

using namespace std;

//Función backtracking
void solucionOptima(int *_optNumMoves, string *_optActions, Rubik _acumCube, int *_totalIter) {
	++*_totalIter;
   	//Comprueba si es solución
	if (*_optNumMoves > _acumCube.getNumMoves()){
   		if (_acumCube.isRubikReady()){   			
   			*_optNumMoves = _acumCube.getNumMoves();
   			*_optActions = _acumCube.getActions();
   			return;
   		}   	
	} else {
		return;
   	}
   
   	//Alternativas
    Rubik auxAcumCube;
    
    //Rotamos la cara roja hacia la derecha
    auxAcumCube = _acumCube;
    auxAcumCube.rotateRedRight();
    solucionOptima(_optNumMoves, _optActions, auxAcumCube, _totalIter);
 
    //Rotamos la cara roja hacia la izquierda
    auxAcumCube = _acumCube;
    auxAcumCube.rotateRedLeft();
    solucionOptima(_optNumMoves, _optActions, auxAcumCube, _totalIter);
    
    //Rotamos la cara azul hacia la derecha
    auxAcumCube = _acumCube;
    auxAcumCube.rotateBlueRight();
    solucionOptima(_optNumMoves, _optActions, auxAcumCube, _totalIter);
	    
    //Rotamos la cara azul hacia la izquierda
    auxAcumCube = _acumCube;
    auxAcumCube.rotateBlueLeft();
    solucionOptima(_optNumMoves, _optActions, auxAcumCube, _totalIter);
    
    //Rotamos la cara verde hacia la derecha
    auxAcumCube = _acumCube;
    auxAcumCube.rotateGreenRight();
    solucionOptima(_optNumMoves, _optActions, auxAcumCube, _totalIter);
	    
    //Rotamos la cara verde hacia la izquierda
    auxAcumCube = _acumCube;
    auxAcumCube.rotateGreenLeft();
    solucionOptima(_optNumMoves, _optActions, auxAcumCube, _totalIter);
    
    //Rotamos la cara blanca hacia la derecha
    auxAcumCube = _acumCube;
    auxAcumCube.rotateWhiteRight();
    solucionOptima(_optNumMoves, _optActions, auxAcumCube, _totalIter);
	    
    //Rotamos la cara blanca hacia la izquierda
    auxAcumCube = _acumCube;
    auxAcumCube.rotateWhiteLeft();
    solucionOptima(_optNumMoves, _optActions, auxAcumCube, _totalIter);
    
    //Rotamos la cara naranja hacia la derecha
    auxAcumCube = _acumCube;
    auxAcumCube.rotateOrangeRight();
    solucionOptima(_optNumMoves, _optActions, auxAcumCube, _totalIter);
	    
    //Rotamos la cara naranja hacia la izquierda
    auxAcumCube = _acumCube;
    auxAcumCube.rotateOrangeLeft();
    solucionOptima(_optNumMoves, _optActions, auxAcumCube, _totalIter);
    
    //Rotamos la cara amarilla hacia la derecha
    auxAcumCube = _acumCube;
    auxAcumCube.rotateYellowRight();
    solucionOptima(_optNumMoves, _optActions, auxAcumCube, _totalIter);
	    
    //Rotamos la cara amarilla hacia la izquierda
    auxAcumCube = _acumCube;
    auxAcumCube.rotateYellowLeft();
    solucionOptima(_optNumMoves, _optActions, auxAcumCube, _totalIter);    
}


int main() 
{	
	//Arreglos vacios
	char red[3][3];
	char blue[3][3];
	char green[3][3];
	char white[3][3];
	char orange[3][3];
	char yellow[3][3];
	
	/*
	//Arreglos precargados para pruebas (prueba rapida, segundos)
	char red[3][3] = {{'b', 'b', 'y'}, {'r', 'r', 'y'}, {'r', 'r', 'y'}};
	char blue[3][3] = {{'b', 'b', 'o'}, {'b', 'b', 'o'}, {'b', 'b', 'o'}};
	char green[3][3] = {{'r', 'r', 'r'}, {'g', 'g', 'g'}, {'g', 'g', 'g'}};
	char white[3][3] = {{'w', 'w', 'b'}, {'w', 'w', 'r'}, {'w', 'w', 'r'}};
	char orange[3][3] = {{'w', 'g', 'g'}, {'w', 'o', 'o'}, {'w', 'o', 'o'}};
	char yellow[3][3] = {{'y', 'y', 'o'}, {'y', 'y', 'o'}, {'y', 'y', 'g'}};
	*/
	/*
	//Arreglos precargados para pruebas (prueba lenta, tiempo indefinido)
	char red[3][3] = {{'o', 'g', 'b'}, {'b', 'r', 'y'}, {'w', 'r', 'r'}};
	char blue[3][3] = {{'y', 'b', 'r'}, {'o', 'b', 'g'}, {'w', 'g', 'r'}};
	char green[3][3] = {{'g', 'w', 'g'}, {'b', 'g', 'y'}, {'w', 'b', 'o'}};
	char white[3][3] = {{'r', 'o', 'y'}, {'o', 'w', 'o'}, {'y', 'y', 'o'}};
	char orange[3][3] = {{'g', 'g', 'w'}, {'w', 'o', 'w'}, {'b', 'r', 'b'}};
	char yellow[3][3] = {{'g', 'y', 'b'}, {'r', 'y', 'r'}, {'o', 'w', 'y'}};
	*/
	
	cout << "\tCubo Rubik" << endl;
	cout << endl;
	cout << "Considere:" << endl;
	cout << " - Debe ingresar tres letras por linea, cada tres lineas representan una" << endl;
	cout << "   cara del cubo (3 x 3)" << endl;
	cout << " - Cada cara del cubo debe ser ingresada en un estricto orden, dicho orden es:" << endl;
	cout << "     Rojo, Azul, Verde, Blanco, Naranja y Amarillo" << endl;
	cout << " - Las letras permitidas para definir cada color son:" << endl;
	cout << "     r = Rojo" << endl;
	cout << "     b = Azul" << endl;
	cout << "     g = Verde" << endl;
	cout << "     w = Blanco" << endl;
	cout << "     o = Naranja" << endl;
	cout << "     y = Amarillo" << endl;
	cout << endl;
	cout << "Ingrese los datos:" << endl;
	
	string line;
	string validChar = "rbgwoy";
	int lineNum = 0;
	int matrizNum = 0;
	do{
		getline(cin, line, '\n');
		if (line.length() == 3){
			if (validChar.find(line[0]) != string::npos && validChar.find(line[1]) != string::npos && validChar.find(line[2]) != string::npos){				
				if (lineNum < 3){
					red[matrizNum][0] = line[0];
					red[matrizNum][1] = line[1];
					red[matrizNum][2] = line[2];
					++matrizNum;
				} else
				if (lineNum < 6){
					blue[matrizNum][0] = line[0];
					blue[matrizNum][1] = line[1];
					blue[matrizNum][2] = line[2];
					++matrizNum;
				} else
				if (lineNum < 9){
					green[matrizNum][0] = line[0];
					green[matrizNum][1] = line[1];
					green[matrizNum][2] = line[2];
					++matrizNum;
				} else
				if (lineNum < 12){
					white[matrizNum][0] = line[0];
					white[matrizNum][1] = line[1];
					white[matrizNum][2] = line[2];
					++matrizNum;
				} else
				if (lineNum < 15){
					orange[matrizNum][0] = line[0];
					orange[matrizNum][1] = line[1];
					orange[matrizNum][2] = line[2];
					++matrizNum;
				} else
				if (lineNum < 18){
					yellow[matrizNum][0] = line[0];
					yellow[matrizNum][1] = line[1];
					yellow[matrizNum][2] = line[2];
					++matrizNum;
				}
				
				if (matrizNum == 3){
					matrizNum = 0;	
				}				
				++lineNum;
			} else {
				cout << "Las letras ingresadas son invalidas, ingrese la linea nuevamente y continue la carga de datos:" << endl;	
			}			
		} else {
			cout << "El numero de letras por linea es errado, ingrese la linea nuevamente y continue la carga de datos:" << endl;
		}			
	}while (lineNum < 18);
	
	Rubik cubo(red, blue, green, white, orange, yellow);
	//cubo.printCube();
		
	//Se usa 20 como el maximo de movimientos optiomos, debido a que ese es el llamado Numero de Dios en el cubo rubik 3x3
	//Pd: El llamdo Numero de Dios del cubo rubik ya ha sido investigado y confirmado por otras fuentes, no tendra sentido calcularlo nosotros
	int *optNumMoves = new int(20); 
	int *totalIter = new int(0);
	string *optActions = new string("");
	
	solucionOptima(optNumMoves, optActions, cubo, totalIter); //Llamado a la funcion backtracking
	
	cout << endl;
	cout << "Solucion: " << endl;
	//cout << "Total de iteraciones recursivas: " << *totalIter << endl;
	cout << *optNumMoves << endl;
	cout << *optActions << endl;
		
	return 0;
}
