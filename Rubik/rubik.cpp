#include "rubik.h"

//Constructor
Rubik::Rubik()
{	
	numMoves = 0;
	actions = "";	
}

//Constructor
Rubik::Rubik(char _red[3][3], char _blue[3][3], char _green[3][3], char _white[3][3], char _orange[3][3], char _yellow[3][3])
{
	numMoves = 0;
	actions = "";	
	loadMatriz(red, _red);
	loadMatriz(blue, _blue);
	loadMatriz(green, _green);
	loadMatriz(white, _white);
	loadMatriz(orange, _orange);
	loadMatriz(yellow, _yellow);
}

//Gira el lado rojo del cubo hacia la derecha
void Rubik::rotateRedRight()
{
	++numMoves;
	actions = actions + "r 0\n";
	
	char auxVecCenter[8];
	char auxVecUp[3];
	char auxVecRight[3];
	char auxVecDown[3];
	char auxVecLeft[3];
	
	auxVecCenter[0] = red[0][0];
	auxVecCenter[1] = red[0][1];
	auxVecCenter[2] = red[0][2];
	auxVecCenter[3] = red[1][2];
	auxVecCenter[4] = red[2][2];
	auxVecCenter[5] = red[2][1];
	auxVecCenter[6] = red[2][0];
	auxVecCenter[7] = red[1][0];
	
	auxVecUp[0] = white[2][0];
	auxVecUp[1] = white[2][1];
	auxVecUp[2] = white[2][2];
	
	auxVecRight[0] = blue[0][0];
	auxVecRight[1] = blue[1][0];
	auxVecRight[2] = blue[2][0];
	
	auxVecDown[0] = yellow[0][2];
	auxVecDown[1] = yellow[0][1];
	auxVecDown[2] = yellow[0][0];
	
	auxVecLeft[0] = green[2][2];
	auxVecLeft[1] = green[1][2];
	auxVecLeft[2] = green[0][2];
	
	red[0][2] = auxVecCenter[0];
	red[1][2] = auxVecCenter[1];
	red[2][2] = auxVecCenter[2];
	red[2][1] = auxVecCenter[3];
	red[2][0] = auxVecCenter[4];
	red[1][0] = auxVecCenter[5];
	red[0][0] = auxVecCenter[6];
	red[0][1] = auxVecCenter[7];
	
	white[2][0] = auxVecLeft[0];
	white[2][1] = auxVecLeft[1];
	white[2][2] = auxVecLeft[2];
	
	blue[0][0] = auxVecUp[0];
	blue[1][0] = auxVecUp[1];
	blue[2][0] = auxVecUp[2];
	
	yellow[0][2] = auxVecRight[0];
	yellow[0][1] = auxVecRight[1];
	yellow[0][0] = auxVecRight[2];
	
	green[2][2] = auxVecDown[0];
	green[1][2] = auxVecDown[1];
	green[0][2] = auxVecDown[2];
}

//Gira el lado azul del cubo hacia la derecha
void Rubik::rotateBlueRight()
{
	++numMoves;
	actions = actions + "b 0\n";
	
	char auxVecCenter[8];
	char auxVecUp[3];
	char auxVecRight[3];
	char auxVecDown[3];
	char auxVecLeft[3];
	
	auxVecCenter[0] = blue[0][0];
	auxVecCenter[1] = blue[0][1];
	auxVecCenter[2] = blue[0][2];
	auxVecCenter[3] = blue[1][2];
	auxVecCenter[4] = blue[2][2];
	auxVecCenter[5] = blue[2][1];
	auxVecCenter[6] = blue[2][0];
	auxVecCenter[7] = blue[1][0];
	
	auxVecUp[0] = white[2][2];
	auxVecUp[1] = white[1][2];
	auxVecUp[2] = white[0][2];
	
	auxVecRight[0] = orange[0][0];
	auxVecRight[1] = orange[1][0];
	auxVecRight[2] = orange[2][0];
	
	auxVecDown[0] = yellow[2][2];
	auxVecDown[1] = yellow[1][2];
	auxVecDown[2] = yellow[0][2];
	
	auxVecLeft[0] = red[2][2];
	auxVecLeft[1] = red[1][2];
	auxVecLeft[2] = red[0][2];
	
	blue[0][2] = auxVecCenter[0];
	blue[1][2] = auxVecCenter[1];
	blue[2][2] = auxVecCenter[2];
	blue[2][1] = auxVecCenter[3];
	blue[2][0] = auxVecCenter[4];
	blue[1][0] = auxVecCenter[5];
	blue[0][0] = auxVecCenter[6];
	blue[0][1] = auxVecCenter[7];
	
	white[2][2] = auxVecLeft[0];
	white[1][2] = auxVecLeft[1];
	white[0][2] = auxVecLeft[2];
	
	orange[0][0] = auxVecUp[0];
	orange[1][0] = auxVecUp[1];
	orange[2][0] = auxVecUp[2];
	
	yellow[2][2] = auxVecRight[0];
	yellow[1][2] = auxVecRight[1];
	yellow[0][2] = auxVecRight[2];
	
	red[2][2] = auxVecDown[0];
	red[1][2] = auxVecDown[1];
	red[0][2] = auxVecDown[2];
}

//Gira el lado verde del cubo hacia la derecha
void Rubik::rotateGreenRight()
{
	++numMoves;
	actions = actions + "g 0\n";
	
	char auxVecCenter[8];
	char auxVecUp[3];
	char auxVecRight[3];
	char auxVecDown[3];
	char auxVecLeft[3];
	
	auxVecCenter[0] = green[0][0];
	auxVecCenter[1] = green[0][1];
	auxVecCenter[2] = green[0][2];
	auxVecCenter[3] = green[1][2];
	auxVecCenter[4] = green[2][2];
	auxVecCenter[5] = green[2][1];
	auxVecCenter[6] = green[2][0];
	auxVecCenter[7] = green[1][0];
	
	auxVecUp[0] = white[0][0];
	auxVecUp[1] = white[1][0];
	auxVecUp[2] = white[2][0];
	
	auxVecRight[0] = red[0][0];
	auxVecRight[1] = red[1][0];
	auxVecRight[2] = red[2][0];
	
	auxVecDown[0] = yellow[0][0];
	auxVecDown[1] = yellow[1][0];
	auxVecDown[2] = yellow[2][0];
	
	auxVecLeft[0] = orange[2][2];
	auxVecLeft[1] = orange[1][2];
	auxVecLeft[2] = orange[0][2];
	
	green[0][2] = auxVecCenter[0];
	green[1][2] = auxVecCenter[1];
	green[2][2] = auxVecCenter[2];
	green[2][1] = auxVecCenter[3];
	green[2][0] = auxVecCenter[4];
	green[1][0] = auxVecCenter[5];
	green[0][0] = auxVecCenter[6];
	green[0][1] = auxVecCenter[7];
	
	white[0][0] = auxVecLeft[0];
	white[1][0] = auxVecLeft[1];
	white[2][0] = auxVecLeft[2];
	
	red[0][0] = auxVecUp[0];
	red[1][0] = auxVecUp[1];
	red[2][0] = auxVecUp[2];
	
	yellow[0][0] = auxVecRight[0];
	yellow[1][0] = auxVecRight[1];
	yellow[2][0] = auxVecRight[2];
	
	orange[2][2] = auxVecDown[0];
	orange[1][2] = auxVecDown[1];
	orange[0][2] = auxVecDown[2];
}

//Gira el lado blanco del cubo hacia la derecha
void Rubik::rotateWhiteRight()
{
	++numMoves;
	actions = actions + "w 0\n";
	
	char auxVecCenter[8];
	char auxVecUp[3];
	char auxVecRight[3];
	char auxVecDown[3];
	char auxVecLeft[3];
	
	auxVecCenter[0] = white[0][0];
	auxVecCenter[1] = white[0][1];
	auxVecCenter[2] = white[0][2];
	auxVecCenter[3] = white[1][2];
	auxVecCenter[4] = white[2][2];
	auxVecCenter[5] = white[2][1];
	auxVecCenter[6] = white[2][0];
	auxVecCenter[7] = white[1][0];
	
	auxVecUp[0] = orange[0][2];
	auxVecUp[1] = orange[0][1];
	auxVecUp[2] = orange[0][0];
	
	auxVecRight[0] = blue[0][2];
	auxVecRight[1] = blue[0][1];
	auxVecRight[2] = blue[0][0];
	
	auxVecDown[0] = red[0][2];
	auxVecDown[1] = red[0][1];
	auxVecDown[2] = red[0][0];
	
	auxVecLeft[0] = green[0][2];
	auxVecLeft[1] = green[0][1];
	auxVecLeft[2] = green[0][0];
	
	white[0][2] = auxVecCenter[0];
	white[1][2] = auxVecCenter[1];
	white[2][2] = auxVecCenter[2];
	white[2][1] = auxVecCenter[3];
	white[2][0] = auxVecCenter[4];
	white[1][0] = auxVecCenter[5];
	white[0][0] = auxVecCenter[6];
	white[0][1] = auxVecCenter[7];
	
	orange[0][2] = auxVecLeft[0];
	orange[0][1] = auxVecLeft[1];
	orange[0][0] = auxVecLeft[2];
	
	blue[0][2] = auxVecUp[0];
	blue[0][1] = auxVecUp[1];
	blue[0][0] = auxVecUp[2];
	
	red[0][2] = auxVecRight[0];
	red[0][1] = auxVecRight[1];
	red[0][0] = auxVecRight[2];
	
	green[0][2] = auxVecDown[0];
	green[0][1] = auxVecDown[1];
	green[0][0] = auxVecDown[2];
}

//Gira el lado naraja del cubo hacia la derecha
void Rubik::rotateOrangeRight()
{
	++numMoves;
	actions = actions + "o 0\n";
	
	char auxVecCenter[8];
	char auxVecUp[3];
	char auxVecRight[3];
	char auxVecDown[3];
	char auxVecLeft[3];
	
	auxVecCenter[0] = orange[0][0];
	auxVecCenter[1] = orange[0][1];
	auxVecCenter[2] = orange[0][2];
	auxVecCenter[3] = orange[1][2];
	auxVecCenter[4] = orange[2][2];
	auxVecCenter[5] = orange[2][1];
	auxVecCenter[6] = orange[2][0];
	auxVecCenter[7] = orange[1][0];
	
	auxVecUp[0] = white[0][2];
	auxVecUp[1] = white[0][1];
	auxVecUp[2] = white[0][0];
	
	auxVecRight[0] = green[0][0];
	auxVecRight[1] = green[1][0];
	auxVecRight[2] = green[2][0];
	
	auxVecDown[0] = yellow[2][0];
	auxVecDown[1] = yellow[2][1];
	auxVecDown[2] = yellow[2][2];
	
	auxVecLeft[0] = blue[2][2];
	auxVecLeft[1] = blue[1][2];
	auxVecLeft[2] = blue[0][2];
	
	orange[0][2] = auxVecCenter[0];
	orange[1][2] = auxVecCenter[1];
	orange[2][2] = auxVecCenter[2];
	orange[2][1] = auxVecCenter[3];
	orange[2][0] = auxVecCenter[4];
	orange[1][0] = auxVecCenter[5];
	orange[0][0] = auxVecCenter[6];
	orange[0][1] = auxVecCenter[7];
	
	white[0][2] = auxVecLeft[0];
	white[0][1] = auxVecLeft[1];
	white[0][0] = auxVecLeft[2];
	
	green[0][0] = auxVecUp[0];
	green[1][0] = auxVecUp[1];
	green[2][0] = auxVecUp[2];
	
	yellow[2][0] = auxVecRight[0];
	yellow[2][1] = auxVecRight[1];
	yellow[2][2] = auxVecRight[2];
	
	blue[2][2] = auxVecDown[0];
	blue[1][2] = auxVecDown[1];
	blue[0][2] = auxVecDown[2];
}

//Gira el lado amarillo del cubo hacia la derecha
void Rubik::rotateYellowRight()
{
	++numMoves;
	actions = actions + "y 0\n";
	
	char auxVecCenter[8];
	char auxVecUp[3];
	char auxVecRight[3];
	char auxVecDown[3];
	char auxVecLeft[3];
	
	auxVecCenter[0] = yellow[0][0];
	auxVecCenter[1] = yellow[0][1];
	auxVecCenter[2] = yellow[0][2];
	auxVecCenter[3] = yellow[1][2];
	auxVecCenter[4] = yellow[2][2];
	auxVecCenter[5] = yellow[2][1];
	auxVecCenter[6] = yellow[2][0];
	auxVecCenter[7] = yellow[1][0];
	
	auxVecUp[0] = red[2][0];
	auxVecUp[1] = red[2][1];
	auxVecUp[2] = red[2][2];
	
	auxVecRight[0] = blue[2][0];
	auxVecRight[1] = blue[2][1];
	auxVecRight[2] = blue[2][2];
	
	auxVecDown[0] = orange[2][0];
	auxVecDown[1] = orange[2][1];
	auxVecDown[2] = orange[2][2];
	
	auxVecLeft[0] = green[2][0];
	auxVecLeft[1] = green[2][1];
	auxVecLeft[2] = green[2][2];
	
	yellow[0][2] = auxVecCenter[0];
	yellow[1][2] = auxVecCenter[1];
	yellow[2][2] = auxVecCenter[2];
	yellow[2][1] = auxVecCenter[3];
	yellow[2][0] = auxVecCenter[4];
	yellow[1][0] = auxVecCenter[5];
	yellow[0][0] = auxVecCenter[6];
	yellow[0][1] = auxVecCenter[7];
	
	red[2][0] = auxVecLeft[0];
	red[2][1] = auxVecLeft[1];
	red[2][2] = auxVecLeft[2];
	
	blue[2][0] = auxVecUp[0];
	blue[2][1] = auxVecUp[1];
	blue[2][2] = auxVecUp[2];
	
	orange[2][0] = auxVecRight[0];
	orange[2][1] = auxVecRight[1];
	orange[2][2] = auxVecRight[2];
	
	green[2][0] = auxVecDown[0];
	green[2][1] = auxVecDown[1];
	green[2][2] = auxVecDown[2];
}

//Gira el lado rojo del cubo hacia la izquierda
void Rubik::rotateRedLeft()
{
	++numMoves;
	actions = actions + "r 1\n";
	
	char auxVecCenter[8];
	char auxVecUp[3];
	char auxVecRight[3];
	char auxVecDown[3];
	char auxVecLeft[3];
	
	auxVecCenter[0] = red[0][2];
	auxVecCenter[1] = red[0][1];
	auxVecCenter[2] = red[0][0];	
	auxVecCenter[3] = red[1][0];	
	auxVecCenter[4] = red[2][0];
	auxVecCenter[5] = red[2][1];
	auxVecCenter[6] = red[2][2];	
	auxVecCenter[7] = red[1][2];
	
	auxVecUp[0] = white[2][2];
	auxVecUp[1] = white[2][1];
	auxVecUp[2] = white[2][0];
	
	auxVecRight[0] = blue[2][0];
	auxVecRight[1] = blue[1][0];
	auxVecRight[2] = blue[0][0];
	
	auxVecDown[0] = yellow[0][0];
	auxVecDown[1] = yellow[0][1];
	auxVecDown[2] = yellow[0][2];
	
	auxVecLeft[0] = green[0][2];
	auxVecLeft[1] = green[1][2];
	auxVecLeft[2] = green[2][2];
	
	red[0][0] = auxVecCenter[0];
	red[1][0] = auxVecCenter[1];
	red[2][0] = auxVecCenter[2];
	red[2][1] = auxVecCenter[3];
	red[2][2] = auxVecCenter[4];
	red[1][2] = auxVecCenter[5];
	red[0][2] = auxVecCenter[6];
	red[0][1] = auxVecCenter[7];
	
	white[2][2] = auxVecRight[0];
	white[2][1] = auxVecRight[1];
	white[2][0] = auxVecRight[2];
	
	blue[2][0] = auxVecDown[0];
	blue[1][0] = auxVecDown[1];
	blue[0][0] = auxVecDown[2];
	
	yellow[0][0] = auxVecLeft[0];
	yellow[0][1] = auxVecLeft[1];
	yellow[0][2] = auxVecLeft[2];
	
	green[0][2] = auxVecUp[0];
	green[1][2] = auxVecUp[1];
	green[2][2] = auxVecUp[2];	
}

//Gira el lado azul del cubo hacia la izquierda
void Rubik::rotateBlueLeft()
{
	++numMoves;
	actions = actions + "b 1\n";
	
	char auxVecCenter[8];
	char auxVecUp[3];
	char auxVecRight[3];
	char auxVecDown[3];
	char auxVecLeft[3];
	
	auxVecCenter[0] = blue[0][2];
	auxVecCenter[1] = blue[0][1];
	auxVecCenter[2] = blue[0][0];	
	auxVecCenter[3] = blue[1][0];	
	auxVecCenter[4] = blue[2][0];
	auxVecCenter[5] = blue[2][1];
	auxVecCenter[6] = blue[2][2];	
	auxVecCenter[7] = blue[1][2];
	
	auxVecUp[0] = white[0][2];
	auxVecUp[1] = white[1][2];
	auxVecUp[2] = white[2][2];
	
	auxVecRight[0] = orange[2][0];
	auxVecRight[1] = orange[1][0];
	auxVecRight[2] = orange[0][0];
	
	auxVecDown[0] = yellow[0][2];
	auxVecDown[1] = yellow[1][2];
	auxVecDown[2] = yellow[2][2];
	
	auxVecLeft[0] = red[0][2];
	auxVecLeft[1] = red[1][2];
	auxVecLeft[2] = red[2][2];
	
	blue[0][0] = auxVecCenter[0];
	blue[1][0] = auxVecCenter[1];
	blue[2][0] = auxVecCenter[2];
	blue[2][1] = auxVecCenter[3];
	blue[2][2] = auxVecCenter[4];
	blue[1][2] = auxVecCenter[5];
	blue[0][2] = auxVecCenter[6];
	blue[0][1] = auxVecCenter[7];
	
	white[0][2] = auxVecRight[0];
	white[1][2] = auxVecRight[1];
	white[2][2] = auxVecRight[2];
	
	orange[2][0] = auxVecDown[0];
	orange[1][0] = auxVecDown[1];
	orange[0][0] = auxVecDown[2];
	
	yellow[0][2] = auxVecLeft[0];
	yellow[1][2] = auxVecLeft[1];
	yellow[2][2] = auxVecLeft[2];
	
	red[0][2] = auxVecUp[0];
	red[1][2] = auxVecUp[1];
	red[2][2] = auxVecUp[2];
}

//Gira el lado verde del cubo hacia la izquierda
void Rubik::rotateGreenLeft()
{
	++numMoves;
	actions = actions + "g 1\n";
	
	char auxVecCenter[8];
	char auxVecUp[3];
	char auxVecRight[3];
	char auxVecDown[3];
	char auxVecLeft[3];
	
	auxVecCenter[0] = green[0][2];
	auxVecCenter[1] = green[0][1];
	auxVecCenter[2] = green[0][0];	
	auxVecCenter[3] = green[1][0];	
	auxVecCenter[4] = green[2][0];
	auxVecCenter[5] = green[2][1];
	auxVecCenter[6] = green[2][2];	
	auxVecCenter[7] = green[1][2];
	
	auxVecUp[0] = white[2][0];
	auxVecUp[1] = white[1][0];
	auxVecUp[2] = white[0][0];
	
	auxVecRight[0] = red[2][0];
	auxVecRight[1] = red[1][0];
	auxVecRight[2] = red[0][0];
	
	auxVecDown[0] = yellow[2][0];
	auxVecDown[1] = yellow[1][0];
	auxVecDown[2] = yellow[0][0];
	
	auxVecLeft[0] = orange[0][2];
	auxVecLeft[1] = orange[1][2];
	auxVecLeft[2] = orange[2][2];
	
	green[0][0] = auxVecCenter[0];
	green[1][0] = auxVecCenter[1];
	green[2][0] = auxVecCenter[2];
	green[2][1] = auxVecCenter[3];
	green[2][2] = auxVecCenter[4];
	green[1][2] = auxVecCenter[5];
	green[0][2] = auxVecCenter[6];
	green[0][1] = auxVecCenter[7];
	
	white[2][0] = auxVecRight[0];
	white[1][0] = auxVecRight[1];
	white[0][0] = auxVecRight[2];
	
	red[2][0] = auxVecDown[0];
	red[1][0] = auxVecDown[1];
	red[0][0] = auxVecDown[2];
	
	yellow[2][0] = auxVecLeft[0];
	yellow[1][0] = auxVecLeft[1];
	yellow[0][0] = auxVecLeft[2];
	
	orange[0][2] = auxVecUp[0];
	orange[1][2] = auxVecUp[1];
	orange[2][2] = auxVecUp[2];	
}

//Gira el lado blanco del cubo hacia la izquierda
void Rubik::rotateWhiteLeft()
{
	++numMoves;
	actions = actions + "w 1\n";
	
	char auxVecCenter[8];
	char auxVecUp[3];
	char auxVecRight[3];
	char auxVecDown[3];
	char auxVecLeft[3];
	
	auxVecCenter[0] = white[0][2];
	auxVecCenter[1] = white[0][1];
	auxVecCenter[2] = white[0][0];	
	auxVecCenter[3] = white[1][0];	
	auxVecCenter[4] = white[2][0];
	auxVecCenter[5] = white[2][1];
	auxVecCenter[6] = white[2][2];	
	auxVecCenter[7] = white[1][2];
	
	auxVecUp[0] = orange[0][0];
	auxVecUp[1] = orange[0][1];
	auxVecUp[2] = orange[0][2];
	
	auxVecRight[0] = blue[0][0];
	auxVecRight[1] = blue[0][1];
	auxVecRight[2] = blue[0][2];
	
	auxVecDown[0] = red[0][0];
	auxVecDown[1] = red[0][1];
	auxVecDown[2] = red[0][2];
	
	auxVecLeft[0] = green[0][0];
	auxVecLeft[1] = green[0][1];
	auxVecLeft[2] = green[0][2];
	
	white[0][0] = auxVecCenter[0];
	white[1][0] = auxVecCenter[1];
	white[2][0] = auxVecCenter[2];
	white[2][1] = auxVecCenter[3];
	white[2][2] = auxVecCenter[4];
	white[1][2] = auxVecCenter[5];
	white[0][2] = auxVecCenter[6];
	white[0][1] = auxVecCenter[7];
	
	orange[0][0] = auxVecRight[0];
	orange[0][1] = auxVecRight[1];
	orange[0][2] = auxVecRight[2];
	
	blue[0][0] = auxVecDown[0];
	blue[0][1] = auxVecDown[1];
	blue[0][2] = auxVecDown[2];
	
	red[0][0] = auxVecLeft[0];
	red[0][1] = auxVecLeft[1];
	red[0][2] = auxVecLeft[2];
	
	green[0][0] = auxVecUp[0];
	green[0][1] = auxVecUp[1];
	green[0][2] = auxVecUp[2];
}

//Gira el lado naranja del cubo hacia la izquierda
void Rubik::rotateOrangeLeft()
{
	++numMoves;
	actions = actions + "o 1\n";
	
	char auxVecCenter[8];
	char auxVecUp[3];
	char auxVecRight[3];
	char auxVecDown[3];
	char auxVecLeft[3];
	
	auxVecCenter[0] = orange[0][2];
	auxVecCenter[1] = orange[0][1];
	auxVecCenter[2] = orange[0][0];	
	auxVecCenter[3] = orange[1][0];	
	auxVecCenter[4] = orange[2][0];
	auxVecCenter[5] = orange[2][1];
	auxVecCenter[6] = orange[2][2];	
	auxVecCenter[7] = orange[1][2];
	
	auxVecUp[0] = white[0][0];
	auxVecUp[1] = white[0][1];
	auxVecUp[2] = white[0][2];
	
	auxVecRight[0] = green[2][0];
	auxVecRight[1] = green[1][0];
	auxVecRight[2] = green[0][0];
	
	auxVecDown[0] = yellow[2][2];
	auxVecDown[1] = yellow[2][1];
	auxVecDown[2] = yellow[2][0];
	
	auxVecLeft[0] = blue[0][2];
	auxVecLeft[1] = blue[1][2];
	auxVecLeft[2] = blue[2][2];
	
	orange[0][0] = auxVecCenter[0];
	orange[1][0] = auxVecCenter[1];
	orange[2][0] = auxVecCenter[2];
	orange[2][1] = auxVecCenter[3];
	orange[2][2] = auxVecCenter[4];
	orange[1][2] = auxVecCenter[5];
	orange[0][2] = auxVecCenter[6];
	orange[0][1] = auxVecCenter[7];
	
	white[0][0] = auxVecRight[0];
	white[0][1] = auxVecRight[1];
	white[0][2] = auxVecRight[2];
	
	green[2][0] = auxVecDown[0];
	green[1][0] = auxVecDown[1];
	green[0][0] = auxVecDown[2];
	
	yellow[2][2] = auxVecLeft[0];
	yellow[2][1] = auxVecLeft[1];
	yellow[2][0] = auxVecLeft[2];
	
	blue[0][2] = auxVecUp[0];
	blue[1][2] = auxVecUp[1];
	blue[2][2] = auxVecUp[2];	
}

//Gira el lado amarillo del cubo hacia la izquierda
void Rubik::rotateYellowLeft()
{
	++numMoves;
	actions = actions + "y 1\n";
	
	char auxVecCenter[8];
	char auxVecUp[3];
	char auxVecRight[3];
	char auxVecDown[3];
	char auxVecLeft[3];
	
	auxVecCenter[0] = yellow[0][2];
	auxVecCenter[1] = yellow[0][1];
	auxVecCenter[2] = yellow[0][0];	
	auxVecCenter[3] = yellow[1][0];	
	auxVecCenter[4] = yellow[2][0];
	auxVecCenter[5] = yellow[2][1];
	auxVecCenter[6] = yellow[2][2];	
	auxVecCenter[7] = yellow[1][2];
	
	auxVecUp[0] = red[2][2];
	auxVecUp[1] = red[2][1];
	auxVecUp[2] = red[2][0];
	
	auxVecRight[0] = blue[2][2];
	auxVecRight[1] = blue[2][1];
	auxVecRight[2] = blue[2][0];
	
	auxVecDown[0] = orange[2][2];
	auxVecDown[1] = orange[2][1];
	auxVecDown[2] = orange[2][0];
	
	auxVecLeft[0] = green[2][2];
	auxVecLeft[1] = green[2][1];
	auxVecLeft[2] = green[2][0];
	
	yellow[0][0] = auxVecCenter[0];
	yellow[1][0] = auxVecCenter[1];
	yellow[2][0] = auxVecCenter[2];
	yellow[2][1] = auxVecCenter[3];
	yellow[2][2] = auxVecCenter[4];
	yellow[1][2] = auxVecCenter[5];
	yellow[0][2] = auxVecCenter[6];
	yellow[0][1] = auxVecCenter[7];
	
	red[2][2] = auxVecRight[0];
	red[2][1] = auxVecRight[1];
	red[2][0] = auxVecRight[2];
	
	blue[2][2] = auxVecDown[0];
	blue[2][1] = auxVecDown[1];
	blue[2][0] = auxVecDown[2];
	
	orange[2][2] = auxVecLeft[0];
	orange[2][1] = auxVecLeft[1];
	orange[2][0] = auxVecLeft[2];
	
	green[2][2] = auxVecUp[0];
	green[2][1] = auxVecUp[1];
	green[2][0] = auxVecUp[2];
}

//Retorna el numero de movimientos hechos al cubo
int Rubik::getNumMoves()
{
	return numMoves;
}

//Retorna la secuencia de acciones hechos al cubo
string Rubik::getActions()
{
	return actions;
}

//Determina si el cubo esta terminado(armado)
bool Rubik::isRubikReady()
{
	if (validateSide(red, 'r') && validateSide(blue, 'b') && validateSide(green, 'g') && validateSide(white, 'w') && validateSide(orange, 'o') && validateSide(yellow, 'y')){
		return true;
	}
	return false;
}

//Imprime la secuencia de aciones hechas al cubo
void Rubik::printActions()
{
	cout << actions;
}

//Imprime cada lado del rubik en formato de cubo
void Rubik::printCube()
{
	for (int i = 0; i < 3; i++){
		cout << "\t\t"; 
		for (int j = 0; j < 3; j++){ 
			cout << white[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	for (int i = 0; i < 3; i++){
		cout << "\t "; 
		for (int j = 0; j < 3; j++){ 
			cout << green[i][j] << " ";
		}
		cout << " "; 
		for (int j = 0; j < 3; j++){ 
			cout << red[i][j] << " ";
		}
		cout << " "; 
		for (int j = 0; j < 3; j++){ 
			cout << blue[i][j] << " ";
		}
		cout << " "; 
		for (int j = 0; j < 3; j++){ 
			cout << orange[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	for (int i = 0; i < 3; i++){
		cout << "\t\t"; 
		for (int j = 0; j < 3; j++){ 
			cout << yellow[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

}

//Valida si todas las posiciones de una matriz son iguales al un valor determinda
bool Rubik::validateSide(char _matrizSide[3][3], char _sideDefinition)
{
	for (int i = 0; i < 3; i++){ 
		for (int j = 0; j < 3; j++){ 
			if (_matrizSide[i][j] != _sideDefinition){
				return false;
			}
		}
	}
	return true;
}

//Carga un matriz 3x3 con los valores de otra matriz 3x3
void Rubik::loadMatriz(char _matrizOut[3][3], char _matrizIn[3][3])
{
	for (int i = 0; i < 3; i++){ 
		for (int j = 0; j < 3; j++){ 
			_matrizOut[i][j] = _matrizIn[i][j];
		}
	}	
}


