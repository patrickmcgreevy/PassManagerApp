#pragma once

#include "factorStack.h"

factorStack::factorStack()
{
	//factor = 0;
	mpHead = nullptr;
}

//factorStack::factorStack(int n)
//{
//	factor = n;
//	pNext = nullptr;
//}

factorStack::~factorStack()
{
	//delete pNext;
}

void factorStack::pushFactor(int n)
{
	FactorNode *pNewNode = new FactorNode(n);

	if (pNewNode != nullptr)
	{
		pNewNode->setpNext(mpHead);
		mpHead = pNewNode;
	}
}