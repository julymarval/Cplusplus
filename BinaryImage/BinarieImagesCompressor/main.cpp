/**************************************
* Algoritmos y Estructura de Datos    *
* Jimenez Yunelis. C.I: 20.653.996    *
* Marval Julyamnis. C.I: 19.255.842   *
* Proyecto 3. Imagenes binarias       *
**************************************/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include "Freeimage.h"
#include "BinarieImage.h"
#include "QuadTree.h"

using namespace std;

//Carga la imagen usando la libreria FreeImage
unsigned char* loadImage(const char* _imgName, int& _width, int& _height){
	//Se obtiene el formato de la imagen.
	FREE_IMAGE_FORMAT formatImage = FreeImage_GetFileType(_imgName);

	//Se carga la imagen utilizando FreeImage.
	FIBITMAP *FIbitmap = FreeImage_Load(formatImage, _imgName, 0);
	FIbitmap = FreeImage_ConvertToStandardType(FIbitmap);
	
	//Se obtiene el ancho y alto de la imagen.
	_width = FreeImage_GetWidth(FIbitmap);
	_height = FreeImage_GetHeight(FIbitmap);
	
	//Se crea la matriz de colores.
	unsigned char *b = new unsigned char[_width * _height];
	
	//Se copian los colores a la matriz creada.
	FreeImage_ConvertToRawBits(b, FIbitmap, _width, 8, FI_RGBA_RED_MASK, 0, 0, TRUE);
	
	//Se cierra el bitmap.
	FreeImage_Unload(FIbitmap);
	return b;
}

// Retorna el formato de un archivo segun su nombre
string getFormat(string _fileName)
{
	string format = "";
	int x = _fileName.find_last_of(".");
	if (x != -1){
		int y = _fileName.length() - x;
		string auxFormat = _fileName.substr(x, y); 
	
		for (int i = 0; i < auxFormat.length(); ++i){
			format += tolower(auxFormat[i]);
		}
	}
	return format;
}

//Indica si una imagen es cuadrada y si su tamano es potencia de dos, mediente la evaluacion de dos numeros que representan su ancho y alto
bool isSquareAndPowerTwoImage(int _width, int _heigth)
{
	if (_width == _heigth && (fmod(log((double) _width) / log((double) 2), 1) == 0)){
		return true;
	}
	return false;
}

//Programa principal
int main() {
	char opcion;
    string linea;

	QuadTree *imageOnMemory = new QuadTree();

	do {		
		system("cls");
		cout << endl;
		cout << "\t\t" << "MEN\351" << endl;
		cout << "\t" << "1) Cargar imagen (formato .BMP, .JPG, .PNG, .QT)" << endl;
		cout << "\t" << "2) Salvar imagen en formato quadtree (formato con extensi\242n .QT)" << endl;
		cout << "\t" << "3) Imprimir el n\243mero de nodos Blancos, Negros y Grises, y la altura del \240rbol" << endl;
		cout << "\t" << "4) Invertir los colores" << endl;
		cout << "\t" << "5) Imprimir en pre-orden" << endl;
		cout << "\t" << "6) Flip horizontal (espejo en X)" << endl;
		cout << "\t" << "7) Mostrar imagen" << endl;
		cout << "\t" << "8) Salir" << endl;
		cout << endl;
		cout << "\t" << "Seleccione una opci\242n: ";
				                 
		getline(cin, linea, '\n');
		if (linea.length() != 0){
			opcion = linea[0];
		} else {
			opcion = ' ';
		}
						
		switch(opcion) {			
			case '1':{
				system("cls");
				cout << endl;
				cout << "Indique Nombre del archivo" << endl;
				getline(cin, linea, '\n');

				int alto; 
				int ancho;
				string format = getFormat(linea);
				if (format == ".bmp" || format == ".jpg" || format == ".png"){
					//Validar existencia del archivo
					ifstream archivo(linea);
					if (archivo.fail()){
						cout << endl;
    					cout << "El archivo no pudo ser encontrado" << endl;	
					} else {
						//Leer imagen
						unsigned char *imagen;
						
						imagen = loadImage(linea.c_str(), ancho, alto);
						BinarieImage image(imagen, ancho, alto);

						if (image.isBinarieImage() && isSquareAndPowerTwoImage(ancho, alto)){
							//Cargar QuadTree
							imageOnMemory->loadTree(image);
							cout << endl;
							cout << "La imagen ha sido cargada en memoria" << endl;
						} else {
							cout << endl;
							cout << "La imagen no cumple las condiciones para ser procesada" << endl;
						}
					}
					archivo.close();
				} else {
					if (format == ".qt"){
						//Validar existencia del archivo
						ifstream archivo(linea);
						if (archivo.fail()){
							cout << endl;
    						cout << "El archivo no pudo ser encontrado" << endl;	
						} else {
							//Leer archivo (Ya que no se espesifica, supondremos que el archivo ".QT" solo puede ser creado por el mismo tipo 
							//de aplicaion y por tanto su contenido siempre es correcto, de modo que no se efectuan validasiones sobre 
							//los datos leidos del mismo)
							char line[192];
							string auxLine;
							int x;
							int y;

							archivo.getline(line, sizeof(line));	        
							auxLine = string(line);

							x = auxLine.find(" ", 0);
							ancho = atoi(auxLine.substr(0, x).c_str());
							++x;
									
							y = auxLine.length();
							alto = atoi(auxLine.substr(x, (y-x)).c_str());

							archivo.getline(line, sizeof(line));	        
							auxLine = string(line);

							

							if (isSquareAndPowerTwoImage(ancho, alto)){
								//Cargar QuadTree
								if (imageOnMemory->loadTree(auxLine, ancho, alto)){
									cout << endl;
									cout << "La imagen ha sido cargada en memoria" << endl;
								} else {
									cout << endl;
									cout << "Los datos de la estructura de memoria son inconsistentes" << endl;
								}
							} else {
								cout << endl;
								cout << "Los datos no cumplen las condiciones para ser procesados" << endl;
							}
						}
						archivo.close();
					} else {
						cout << endl;
						cout << "Formato de archivo invalido" << endl;
					}
				}

				cout << endl;					
				system("pause");
				break;
			}
			case '2':{
				system("cls");
				if (imageOnMemory->isLoadded()){					
					cout << endl;
					cout << "Indique Nombre del archivo" << endl;
					getline(cin, linea, '\n');			
									
					string format = getFormat(linea);
					if (format == ".qt"){
						ofstream archivo(linea);
						if (archivo.fail()){
    						cout << endl;
							cout << "Error creando el archivo" << endl;	
						} else {
							archivo << imageOnMemory->getWidth() << " " << imageOnMemory->getHeight() << endl;
							archivo << imageOnMemory->getPreOrder() << endl;

							cout << endl;
							cout << "Archivo creado con exito" << endl;	
						}
						archivo.close();
					} else {
						cout << endl;
						cout << "Formato de archivo invalido: Solo se permite .qt como formato valido" << endl;
					}
				} else {
					cout << endl;
					cout << "No se han cargado datos en memoria" << endl;
				}

				cout << endl;					
				system("pause");
				break;
			}
			case '3':{
				system("cls");	
				if (imageOnMemory->isLoadded()){	
					cout << endl;
					cout << "Informacion del arbol en memoria" << endl;
					cout << endl;
					cout << "B = " << imageOnMemory->getWhiteNodes() << ", N = " << imageOnMemory->getBlackNodes();
					cout << ", G = " << imageOnMemory->getGrayNodes() << ", H = " << imageOnMemory->getTreeHeight() << endl;								
				} else {
					cout << endl;
					cout << "No se han cargado datos en memoria" << endl;
				}

				cout << endl;					
				system("pause");
				break;
			}
			case '4':{
				system("cls");	
				if (imageOnMemory->isLoadded()){	
					cout << endl;
					cout << "Invertir colores" << endl;
					imageOnMemory->invertColors();
					cout << endl;
					cout << "Colores invertidos exitosamente" << endl;
				} else {
					cout << endl;
					cout << "No se han cargado datos en memoria" << endl;
				}

				cout << endl;					
				system("pause");
				break;
			}
			case '5':{	
				system("cls");	
				if (imageOnMemory->isLoadded()){	
					cout << endl;
					cout << "Recorrido en pre-orden del arbol" << endl;
					cout << endl;
					cout << imageOnMemory->getPreOrder() << endl;								
				} else {
					cout << endl;
					cout << "No se han cargado datos en memoria" << endl;
				}

				cout << endl;					
				system("pause");
				break;
			}
			case '6':{				
				system("cls");	
				if (imageOnMemory->isLoadded()){	
					cout << endl;
					cout << "Reflejar imagen" << endl;
					imageOnMemory->horizontalFlip();
					cout << endl;
					cout << "Flip horizontal exitoso" << endl;
				} else {
					cout << endl;
					cout << "No se han cargado datos en memoria" << endl;
				}

				cout << endl;					
				system("pause");
				break;
			}
			case '7':{				
				system("cls");	
				if (imageOnMemory->isLoadded()){	
					cout << endl;
					cout << "Representacion en formato texto de la Imagen binaria en memoria" << endl;
					cout << endl;
					BinarieImage *auxImage = imageOnMemory->downloadTree();	
					auxImage->printImage();
					delete auxImage;
				} else {
					cout << endl;
					cout << "No se han cargado datos en memoria" << endl;
				}

				cout << endl;					
				system("pause");
				break;
			}
			case '8':{	
				//Elimina el espacio en memoria del arbol(a su ves de manera recursiva elimina sus nodos)
				delete imageOnMemory;
				break;
			}
									
		}
	} while (opcion != '8');

	system("pause");
	return 0;
}
