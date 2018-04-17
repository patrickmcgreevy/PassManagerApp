#pragma once
#include "FactorNode.h"

class factorStack
{
public:
	factorStack();
	factorStack(int n);
	~factorStack();

	void pushFactor(int n);
private:
	//int factor;
	FactorNode *mpHead;
};