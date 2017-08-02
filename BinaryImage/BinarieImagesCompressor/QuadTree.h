#pragma once
#ifndef QUADTREE_H
#define QUADTREE_H

#include <iostream>
#include <string>
#include "BranchLeaf.h"
#include "BinarieImage.h"

using namespace std;

class QuadTree
{
	private:
		BranchLeaf *root;
		int width;
		int height;
		int blackNodes;
		int whiteNodes;
		int grayNodes;
		int treeHeight;
		string preOrder;
		bool loadded;
		BranchLeaf* loadTreeWithPreOrder(string&, int, int, string&, int&, int&, int&, int&);	
		BranchLeaf* loadTreeWithImage(BinarieImage, string&, int&, int&, int&, int&);			
		BinarieImage splitImage(BinarieImage, int, int, int, int);
		unsigned char* downloadTreeImage(BranchLeaf*, int, int);
		void joinImage(unsigned char*&, unsigned char*, int, int, int, int);
		void invertNodes(BranchLeaf*, string&, int&, int&);
		void mirrowNodes(BranchLeaf*, string&);
		

	public:
		static const char BLACK = '0';
		static const char WHITE = '1';
		static const char GRAY = '2';

		QuadTree();
		bool loadTree(BinarieImage);
		bool loadTree(string, int, int);
		BinarieImage* downloadTree();
		void invertColors();
		void horizontalFlip();
		int getWidth();
		int getHeight();
		int getBlackNodes();
		int getWhiteNodes();
		int getGrayNodes();
		int getTreeHeight();
		string getPreOrder();
		bool isLoadded();
		~QuadTree();
};

#endif

