#include "BranchLeaf.h"

//Constructor
BranchLeaf::BranchLeaf()
{
	color = -1;
	Leaf = true;
	quadrantCero = NULL;
	quadrantOne = NULL;
	quadrantTwo = NULL;
	quadrantThree = NULL;
}

//Constructor
BranchLeaf::BranchLeaf(char _color)
{
	color = _color;
	Leaf = true;
	quadrantCero = NULL;
	quadrantOne = NULL;
	quadrantTwo = NULL;
	quadrantThree = NULL;
}

//Indica si un nodo es externo
bool BranchLeaf::isLeaf()
{
	return Leaf;
}

//Retorna el color del nodo, sea negro, blanco o gris
char BranchLeaf::getColor()
{
	return color;
}

//Carga el color del nodo
void BranchLeaf::setColor(char _color)
{
	color = _color;
}

//Carga el cuadrante superior izquierdo
void BranchLeaf::setQuadrantCero(BranchLeaf* _quadrantCero)
{
	Leaf = false;
	quadrantCero = _quadrantCero;
}

//Carga el cuadrante superior derecho
void BranchLeaf::setQuadrantOne(BranchLeaf* _quadrantOne)
{
	Leaf = false;
	quadrantOne = _quadrantOne;
}

//Carga el cuadrante inferior derecho
void BranchLeaf::setQuadrantTwo(BranchLeaf* _quadrantTwo)
{
	Leaf = false;
	quadrantTwo = _quadrantTwo;
}

//Carga el cuadrante inferior izquierdo
void BranchLeaf::setQuadrantThree(BranchLeaf* _quadrantThree)
{
	Leaf = false;
	quadrantThree = _quadrantThree;
}

//Retorna el cuadrante superior izquierdo
BranchLeaf* BranchLeaf::getQuadrantCero()
{
	return quadrantCero;
}

//Carga el cuadrante superior derecho
BranchLeaf* BranchLeaf::getQuadrantOne()
{
	return quadrantOne;
}

//Carga el cuadrante inferior derecho
BranchLeaf* BranchLeaf::getQuadrantTwo()
{
	return quadrantTwo;
}

//Carga el cuadrante inferior izquierdo
BranchLeaf* BranchLeaf::getQuadrantThree()
{
	return quadrantThree;
}

//Destructor
BranchLeaf::~BranchLeaf()
{	
	delete quadrantCero;
	delete quadrantOne;
	delete quadrantTwo;
	delete quadrantThree;
}
