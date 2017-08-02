#pragma once
#ifndef BINARIEIMAGE_H
#define BINARIEIMAGE_H

#include <iostream>
#include <string>
#include <cmath>
#include "Freeimage.h"

using namespace std;

class BinarieImage
{
	private:
		int width;
		int height;
		bool monoColor;		
		bool binarieImage;
		unsigned char colorBase;
		unsigned char *image;

	public:
		BinarieImage(unsigned char*, int, int);
		BinarieImage(unsigned char*, int, int, unsigned char);
		int getWidth();
		int getHeight();
		unsigned char getColorBase();
		unsigned char getPixelColor(int, int);
		bool isMonoColor();
		bool isBinarieImage();
		void printImage();
};

#endif

