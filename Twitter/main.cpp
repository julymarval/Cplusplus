/**************************************
* Algoritmos y Estructura de Datos    *
* Jimenez Yunelis. C.I: 20.653.996    *
* Marval Julyamnis. C.I: 19.255.842   *
* Proyecto 2. Simulacion de un Twitter*
**************************************/

#include <iostream>
#include <string>
#include "twitter.h"
using namespace std;

int main() {
	Twitter twitterAplication;
		
    int x;
	int y;
	char opcion;
    string linea;
	string auxStr1;
	string auxStr2;
	string auxStr3;
	string auxStr4;
	
	do {		
        system("cls");
        cout << endl;
        cout << "\t\t" << "MEN\351" << endl;
        cout << "\t" << "1) Registrar usuario" << endl;
        cout << "\t" << "2) Iniciar sesi\242n" << endl;
        cout << "\t" << "3) Salir" << endl;
        cout << endl;
        cout << "\t" << "Seleccione una opci\242n: ";
                 
        getline(cin, linea, '\n');
        opcion = linea[0];
        
        switch(opcion) {			
			case '1':{				
				system("cls");
				cout << endl;
				cout << "Indique Nombre, Email, Nombre de usuario y Clave" << endl;
				getline(cin, linea, '\n');
        		
    			x = linea.find(" ", 0);
				auxStr1 = linea.substr(0, x);
				++x;
				
				y = linea.find(" ", x);
				auxStr2 = linea.substr(x, (y-x));
				++y;
				
				x = linea.find(" ", y);
				auxStr3 = linea.substr(y, (x-y));
				++x;
				
				y = linea.length();
				auxStr4 = linea.substr(x, (y-x));
				
				if (twitterAplication.regUsuario(auxStr1, auxStr2, auxStr3, auxStr4)){
					cout << "Usuario guardado con \202xito" << endl;
				} else {
					cout << "El usuario ya existe" << endl;
				}
				cout << endl;					
            	system("pause");
				break;
			}			
			case '2':{
				system("cls");
				cout << endl;
				cout << "Indique Nombre de usuario y Clave" << endl;
				getline(cin, linea, '\n');
				
				x = linea.find(" ", 0);
				auxStr1 = linea.substr(0, x);
				++x;
								
				y = linea.length();
				auxStr2 = linea.substr(x, (y-x));
				
				if (twitterAplication.iniSesion(auxStr1, auxStr2)){
					do {		
				        system("cls");
				        cout << endl;
				        cout << "\t" << "1) Ver seguidores" << endl;
				        cout << "\t" << "2) Ver siguiendos" << endl;
				        cout << "\t" << "3) Crear tweet" << endl;
				        cout << "\t" << "4) Eliminar tweet" << endl;
				        cout << "\t" << "5) Seguir" << endl;
				        cout << "\t" << "6) Dejar de seguir" << endl;
				        cout << "\t" << "7) Ver muro" << endl;
				        cout << "\t" << "8) Guardar en archivo" << endl;
				        cout << "\t" << "9) Salir" << endl;
				        cout << endl;
				        cout << "\t" << "Seleccione una opci\242n: ";
				                 
				        getline(cin, linea, '\n');
				        opcion = linea[0];
						
						switch(opcion) {			
							case '1':{
								system("cls");
								cout << endl;
								cout << "Indique Nombre de usuario" << endl;
								getline(cin, linea, '\n');
												
								cout << endl;
								cout << "Los seguidores de " << linea << " son:" << endl;
								twitterAplication.verSeguidores(linea);
								cout << endl;					
				            	system("pause");
								break;
							}
							case '2':{
								system("cls");
								cout << endl;
								cout << "Indique Nombre de usuario" << endl;
								getline(cin, linea, '\n');				

								cout << endl;
								cout << "Los siguiendos de " << linea << " son:" << endl;
								twitterAplication.verSiguiendos(linea);
								cout << endl;					
				            	system("pause");
								break;
							}
							case '3':{
								system("cls");	
								cout << endl;
								cout << "Indique el tweet a crear" << endl;
								getline(cin, linea, '\n');
												
								twitterAplication.crearTweet(linea);
								cout << endl;					
				            	system("pause");
								break;
							}
							case '4':{
								system("cls");	
								cout << endl;
								cout << "Seleccione el tweet que desea eliminar" << endl;				
								cout << endl;														
			
								twitterAplication.eliminarTweet();								
								cout << endl;					
				            	system("pause");
								break;
							}
							case '5':{	
								system("cls");	
								cout << endl;
								cout << "Indique el usuario al cual desea seguir" << endl;				
								cout << endl;	
										
								twitterAplication.seguirUsu();								
								cout << endl;					
				            	system("pause");
								break;
							}
							case '6':{	
								system("cls");	
								cout << endl;
								cout << "Indique el usuario al cual desea dejar de seguir" << endl;				
								cout << endl;			

								twitterAplication.dejarSeguirUsu();
								cout << endl;					
				            	system("pause");
								break;
							}
							case '7':{				
								system("cls");	
								cout << endl;
								cout << "Tweets" << endl;				
								cout << endl;
								
								twitterAplication.verMuro();
								cout << endl;					
				            	system("pause");
								break;
							}
							case '8':{	
								system("cls");	
								cout << endl;			
								
								twitterAplication.guardarArchivo();
								cout << endl;					
				            	system("pause");
								break;
							}
									
						}
					} while (opcion != '9');
					opcion = '3'; //3: Para finalizar el programa 0: Para regrezar al menu anterior	
				} else {
					cout << "Datos invalidos" << endl;
					cout << endl;				
            		system("pause");
				}
				break;
			}							
		}	
    } while (opcion != '3');
	
}
