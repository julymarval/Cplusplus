#include "BinarieImage.h"

//Constructor
BinarieImage::BinarieImage(unsigned char* _image, int _width, int _heigth)
{
	image = _image;
	width = _width;
	height = _heigth;
	
	monoColor = true;
	binarieImage = true;

	unsigned char colorOne = image[0];
	unsigned char colorTwo = image[0];
	int size = width * height;
	for(int i = 1; i < size; i++){
		if (monoColor && colorOne != image[i]){
			colorTwo = _image[i];
			monoColor = false;			
		}
		if (!monoColor && colorOne != image[i] && colorTwo != image[i]){
			binarieImage = false;
		}		
	}

	if (colorOne > colorTwo){
		colorBase = colorTwo;
	} else {
		colorBase = colorOne;
	}
}

//Constructor
BinarieImage::BinarieImage(unsigned char* _image, int _width, int _heigth, unsigned char _colorBase)
{
	image = _image;
	width = _width;
	height = _heigth;
	
	monoColor = true;
	binarieImage = true;

	unsigned char colorOne = image[0];
	unsigned char colorTwo = image[0];
	int size = width * height;
	for(int i = 1; i < size; i++){
		if (monoColor && colorOne != image[i]){
			colorTwo = _image[i];
			monoColor = false;			
		}
		if (!monoColor && colorOne != image[i] && colorTwo != image[i]){
			binarieImage = false;
		}		
	}

	colorBase = _colorBase;
}

//Returna el ancho de la imagen, es decir del VectorMatriz
int BinarieImage::getWidth()
{
	return width;
}
	
//Returna el alto de la imagen, es decir del VectorMatriz
int BinarieImage::getHeight()
{
	return height;
}

//Returna el color que actua de fondo para la imagen
unsigned char BinarieImage::getColorBase()
{
	return colorBase;
}

//Retorna el contenido del VectorMatriz segun un par de indices especificados, como se haria con una Matriz
unsigned char BinarieImage::getPixelColor(int _h, int _w)
{
	return image[_h * height + _w];
}

//Indica si la imagen esta formada por pixeles de un unico color
bool BinarieImage::isMonoColor()
{
	return monoColor;
}

//Indica si la imagen es binaria, es decir que esta por un maximo dos colores
bool BinarieImage::isBinarieImage()
{
	return binarieImage;
}

//Imprime la imagen por consola
void BinarieImage::printImage()
{
	for(int i = 0; i < height ; i++){
		cout << "\t";
		for(int j = 0; j < width; j++){
			if(image[i * height + j] > colorBase){
				cout << 1 << " ";
			} else {
				cout << 0 << " ";
			}
		}
		cout << endl;
	}
}

