#pragma once
#ifndef BRANCHLEAF_H
#define BRANCHLEAF_H

#include <iostream>
#include <string>

using namespace std;

class BranchLeaf
{
	private:
		char color;
		bool Leaf;
		BranchLeaf *quadrantCero;
		BranchLeaf *quadrantOne;
		BranchLeaf *quadrantTwo;
		BranchLeaf *quadrantThree;

	public:
		BranchLeaf();
		BranchLeaf(char);
		bool isLeaf();
		char getColor();
		void setColor(char);
		void setQuadrantCero(BranchLeaf*);
		void setQuadrantOne(BranchLeaf*);
		void setQuadrantTwo(BranchLeaf*);
		void setQuadrantThree(BranchLeaf*);
		BranchLeaf* getQuadrantCero();
		BranchLeaf* getQuadrantOne();
		BranchLeaf* getQuadrantTwo();
		BranchLeaf* getQuadrantThree();
		~BranchLeaf();
};

#endif