#include "QuadTree.h"

//Constructor
QuadTree::QuadTree()
{
	root = NULL;
	loadded = false;
}

//Genera un arbol a partir de una imagen binaria, ademas de cargar la informacion general del mismo
bool QuadTree::loadTree(BinarieImage _image)
{
	width = _image.getWidth();
	height = _image.getHeight();
	blackNodes = 0;
	whiteNodes = 0;
	grayNodes = 0;
	treeHeight = 0;
	preOrder = "";
	root = loadTreeWithImage(_image, preOrder, blackNodes, whiteNodes, grayNodes, treeHeight);

	cout << "W: " << width << " H: " << height << endl;
	cout << "Nodos negros: " << blackNodes << " Nodos blancos: " << whiteNodes << " Nodos grises: " << grayNodes << endl;
	cout << "Altura del Arbol: " << treeHeight << endl;
	cout << "Pre Orden: " << preOrder << endl;
	loadded = true;
	return true;
}

//Genera un arbol a partir de un string que contiene la representacion en pre-orden del mismo, ademas de cargar la informacion general del mismo
bool QuadTree::loadTree(string _preOrderImage, int _width, int _heigth)
{
	width = _width;
	height = _heigth;
	blackNodes = 0;
	whiteNodes = 0;
	grayNodes = 0;
	treeHeight = 0;
	preOrder = "";
	string auxPreOrderImage = _preOrderImage;
	BranchLeaf *auxNode =  loadTreeWithPreOrder(auxPreOrderImage, _width, _heigth, preOrder, blackNodes, whiteNodes, grayNodes, treeHeight);

	cout << "W: " << width << " H: " << height << endl;
	cout << "Nodos negros: " << blackNodes << " Nodos blancos: " << whiteNodes << " Nodos grises: " << grayNodes << endl;
	cout << "Altura del Arbol: " << treeHeight << endl;
	cout << "Pre Orden: " << preOrder << endl;

	if (_preOrderImage == preOrder){
		root = auxNode;
		loadded = true;
		return true;
	} else {
		return false;
	}
}

//Genera una imagen binaria a partir de la informacion almacenada en el arbol
BinarieImage* QuadTree::downloadTree()
{
	BinarieImage *auxImg = new BinarieImage(downloadTreeImage(root, width, height), width, height);
	return auxImg;
}

//Invierte los colores de la imagen almacenada en memoria
void QuadTree::invertColors()
{
	blackNodes = 0;
	whiteNodes = 0;
	preOrder = "";
	invertNodes(root, preOrder, blackNodes, whiteNodes);
}

//Ejecuta un flip horizontal sobre la imagen almacenada en memoria
void QuadTree::horizontalFlip()
{
	preOrder = "";
	mirrowNodes(root, preOrder);
}

//Returna el ancho de la imagen en memoria
int QuadTree::getWidth()
{
	return width;
}
	
//Returna el alto de la imagen en memoria
int QuadTree::getHeight()
{
	return height;
}

//Retorna el numero de nodos negros que posee el arbol
int QuadTree::getBlackNodes()
{
	return blackNodes;
}

//Retorna el numero de nodos blancos que posee el arbol
int QuadTree::getWhiteNodes()
{
	return whiteNodes;
}

//Retorna el numero de nodos grises que posee el arbol
int QuadTree::getGrayNodes()
{
	return grayNodes;
}

//Retorna la altura del arbol
int QuadTree::getTreeHeight()
{
	return treeHeight;
}

//Retorna la representacion en pre-orden del arbol en memoria
string QuadTree::getPreOrder()
{
	return preOrder;
}


//Indica si el arbol esta cargado
bool QuadTree::isLoadded()
{
	return loadded;
}

//Metodo recursivo empleado para generar el arbol usando un string que contiene la representacion en pre-orden del mismo
BranchLeaf* QuadTree::loadTreeWithPreOrder(string& _preOrderImage, int _width, int _heigth, string& _order, int& _blackNodes, int& _whiteNodes, int& _grayNodes, int& _heightTree)
{
	BranchLeaf *auxNode = NULL;
	char auxOrder;
	if (_preOrderImage.length() != 0){
		auxOrder = _preOrderImage[0];
	} else {
		auxOrder = '1';
	}
	_preOrderImage.erase(0, 1);

	if (_width < 1 || _heigth < 1){
		return auxNode;
	}

	if (auxOrder == WHITE){
		auxNode = new BranchLeaf(WHITE);
		_whiteNodes++;
		_order.push_back(WHITE);
	} else {
		if (auxOrder == BLACK){
			auxNode = new BranchLeaf(BLACK);
			_blackNodes++;
			_order.push_back(BLACK);
		} else {
			auxNode = new BranchLeaf(GRAY);
			_grayNodes++;
			_order.push_back(GRAY);
			_heightTree++;

			int auxHeightTree[4] = {0, 0, 0, 0};

			auxNode->setQuadrantCero(loadTreeWithPreOrder(_preOrderImage, _width/2, _heigth/2, _order,_blackNodes, _whiteNodes, _grayNodes, auxHeightTree[0]));
			auxNode->setQuadrantOne(loadTreeWithPreOrder(_preOrderImage, _width/2, _heigth/2, _order, _blackNodes, _whiteNodes, _grayNodes, auxHeightTree[1]));
			auxNode->setQuadrantTwo(loadTreeWithPreOrder(_preOrderImage, _width/2, _heigth/2, _order, _blackNodes, _whiteNodes, _grayNodes, auxHeightTree[2]));
			auxNode->setQuadrantThree(loadTreeWithPreOrder(_preOrderImage, _width/2, _heigth/2, _order, _blackNodes, _whiteNodes, _grayNodes, auxHeightTree[3]));	

			int mayorHeight = auxHeightTree[0];
			for (int i = 1; i < 4; i++){
				if (auxHeightTree[i] > mayorHeight){
					mayorHeight = auxHeightTree[i];
				}
			}
		
			_heightTree = _heightTree + mayorHeight;
		}
	}
	return auxNode;
}

//Metodo recursivo empleado para generar el arbol usando una imagen binaria
BranchLeaf* QuadTree::loadTreeWithImage(BinarieImage _image, string& _order, int& _blackNodes, int& _whiteNodes, int& _grayNodes, int& _heightTree)
{
	BranchLeaf *auxNode = NULL;
	if (_image.isMonoColor()){
		if (_image.getPixelColor(0, 0) > _image.getColorBase()){
			auxNode = new BranchLeaf(WHITE);
			_whiteNodes++;
			_order.push_back(WHITE);
		} else {
			auxNode = new BranchLeaf(BLACK);
			_blackNodes++;
			_order.push_back(BLACK);
		}
	} else {
		auxNode = new BranchLeaf(GRAY);
		_grayNodes++;
		_order.push_back(GRAY);
		_heightTree++;

		BinarieImage Quad0 = splitImage(_image, 0, _image.getWidth()/2, 0, _image.getHeight()/2);
		BinarieImage Quad1 = splitImage(_image, _image.getWidth()/2, _image.getWidth(), 0, _image.getHeight()/2);
		BinarieImage Quad2 = splitImage(_image, _image.getWidth()/2, _image.getWidth(), _image.getHeight()/2, _image.getHeight());
		BinarieImage Quad3 = splitImage(_image, 0, _image.getWidth()/2, _image.getHeight()/2, _image.getHeight());

		int auxHeightTree[4] = {0, 0, 0, 0};

		auxNode->setQuadrantCero(loadTreeWithImage(Quad0, _order,_blackNodes, _whiteNodes, _grayNodes, auxHeightTree[0]));
		auxNode->setQuadrantOne(loadTreeWithImage(Quad1, _order, _blackNodes, _whiteNodes, _grayNodes, auxHeightTree[1]));
		auxNode->setQuadrantTwo(loadTreeWithImage(Quad2, _order, _blackNodes, _whiteNodes, _grayNodes, auxHeightTree[2]));
		auxNode->setQuadrantThree(loadTreeWithImage(Quad3, _order, _blackNodes, _whiteNodes, _grayNodes, auxHeightTree[3]));	

		int mayorHeight = auxHeightTree[0];
		for (int i = 1; i < 4; i++){
			if (auxHeightTree[i] > mayorHeight){
				mayorHeight = auxHeightTree[i];
			}
		}
		
		_heightTree = _heightTree + mayorHeight;
	}

	return auxNode;
}

//Metodo empleado para dividir una imagen en cuadrantes
BinarieImage QuadTree::splitImage(BinarieImage _image, int _startW, int _endW, int _startH, int _endH)
{
	int auxWidth = _endW - _startW;
	int auxHeight = _endH - _startH; 

	unsigned char *quarter = new unsigned char[auxWidth * auxHeight];

	int h = 0;	
	for(int stH = _startH; stH < _endH; stH++){	
		int w = 0;
		for(int stW = _startW; stW < _endW; stW++){
			quarter[h * auxHeight + w] = _image.getPixelColor(stH, stW);
			w++;
		}
		h++;
	}

	return BinarieImage(quarter, auxWidth, auxHeight, _image.getColorBase());
}

//Metodo recursivo empleado para generar una matriz que representa una imagen binaria, a partir de la estructura almacenada en memoria 
unsigned char* QuadTree::downloadTreeImage(BranchLeaf* _node, int _width, int _heigth)
{
	unsigned char *image = new unsigned char[_width * _heigth];

	if (_node->getColor() == WHITE){
		for(int h = 0; h < _heigth; h++){
			for(int w = 0; w < _width; w++){
				image[h * _heigth + w] = (char)255;//Blanco
			}
		}
	} else {
		if (_node->getColor() == BLACK){
			for(int h = 0; h < _heigth; h++){
				for(int w = 0; w < _width; w++){
					image[h * _heigth + w] = (char)0;//Negro
				}
			}
		} else {
			unsigned char *Quad0 = downloadTreeImage(_node->getQuadrantCero(), _width/2, _heigth/2);
			unsigned char *Quad1 = downloadTreeImage(_node->getQuadrantOne(), _width/2, _heigth/2);
			unsigned char *Quad2 = downloadTreeImage(_node->getQuadrantTwo(), _width/2, _heigth/2);
			unsigned char *Quad3 = downloadTreeImage(_node->getQuadrantThree(), _width/2, _heigth/2);

			joinImage(image, Quad0, 0, _width/2, 0, _heigth/2);
			joinImage(image, Quad1, _width/2, _width, 0, _heigth/2);
			joinImage(image, Quad2, _width/2, _width, _heigth/2, _heigth);
			joinImage(image, Quad3, 0, _width/2, _heigth/2, _heigth);
		}
	}

	return image;
}

//Metodo empleado para unir los cuadrantes que forman una imagen
void QuadTree::joinImage(unsigned char*& _imageOut, unsigned char* _imageIn, int _startW, int _endW, int _startH, int _endH)
{	
	int auxHeight = _endH - _startH; 
	int auxTotalHeight = auxHeight * 2;

	int h = 0;	
	for(int stH = _startH; stH < _endH; stH++){	
		int w = 0;
		for(int stW = _startW; stW < _endW; stW++){
			_imageOut[stH * auxTotalHeight + stW] = _imageIn[h * auxHeight + w];
			w++;
		}
		h++;
	}
}

//Metodo recursivo empleado para invertir los colores de los nodos 
void QuadTree::invertNodes(BranchLeaf* _node, string& _order, int& _blackNodes, int& _whiteNodes)
{
	if (_node->getColor() == WHITE){
		_node->setColor(BLACK);
		_blackNodes++;
		_order.push_back(BLACK);
	} else {
		if (_node->getColor() == BLACK){
			_node->setColor(WHITE);
			_whiteNodes++;
			_order.push_back(WHITE);
		} else {
			_order.push_back(GRAY);

			invertNodes(_node->getQuadrantCero(), _order, _blackNodes, _whiteNodes);
			invertNodes(_node->getQuadrantOne(), _order, _blackNodes, _whiteNodes);
			invertNodes(_node->getQuadrantTwo(), _order, _blackNodes, _whiteNodes);
			invertNodes(_node->getQuadrantThree(), _order, _blackNodes, _whiteNodes);
		}
	}
}

//Metodo recursivo empleado para reflejar(inercambiar) los nodos del arbol 
void QuadTree::mirrowNodes(BranchLeaf* _node, string& _order)
{
	if (_node->getColor() == WHITE){
		_order.push_back(WHITE);
	} else {
		if (_node->getColor() == BLACK){
			_order.push_back(BLACK);
		} else {
			_order.push_back(GRAY);

			BranchLeaf* auxNode;

			auxNode = _node->getQuadrantCero();
			_node->setQuadrantCero(_node->getQuadrantOne());
			_node->setQuadrantOne(auxNode);

			auxNode = _node->getQuadrantThree();
			_node->setQuadrantThree(_node->getQuadrantTwo());
			_node->setQuadrantTwo(auxNode);

			mirrowNodes(_node->getQuadrantCero(), _order);
			mirrowNodes(_node->getQuadrantOne(), _order);
			mirrowNodes(_node->getQuadrantTwo(), _order);
			mirrowNodes(_node->getQuadrantThree(), _order);
		}
	}
}

//Destructor
QuadTree::~QuadTree()
{
	delete root;
}
