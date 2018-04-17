#pragma once
#include "FactorNode.h"

FactorNode::FactorNode()
{
	factor = 0;
	mpNext = nullptr;
}

FactorNode::FactorNode(int n)
{
	factor = n;
	mpNext = nullptr;
}

FactorNode::~FactorNode()
{
	
}

int FactorNode::getFac()
{
	return factor;
}

FactorNode *FactorNode::getpNext()
{
	return mpNext;
}

void FactorNode::setFac(int n)
{
	factor = n;
}

void FactorNode::setpNext(FactorNode *pNode)
{
	mpNext = pNode;
}