#ifndef RUBIK_H
#define RUBIK_H

#include <iostream>
#include <string>

using namespace std;

class Rubik
{
	private:
		int numMoves;
		char red[3][3];
		char blue[3][3];
		char green[3][3];
		char white[3][3];
		char orange[3][3];
		char yellow[3][3];
		string actions;		
		bool validateSide(char[3][3], char);
		void loadMatriz(char[3][3], char[3][3]);
		
	public:
		Rubik();	
		Rubik(char[3][3], char[3][3], char[3][3], char[3][3], char[3][3], char[3][3]);
		void rotateRedRight();
		void rotateBlueRight();
		void rotateGreenRight();
		void rotateWhiteRight();
		void rotateOrangeRight();
		void rotateYellowRight();
		void rotateRedLeft();
		void rotateBlueLeft();
		void rotateGreenLeft();
		void rotateWhiteLeft();
		void rotateOrangeLeft();
		void rotateYellowLeft();
		int getNumMoves();
		string getActions();
		bool isRubikReady();
		void printActions();
		void printCube();
		
};

#endif
