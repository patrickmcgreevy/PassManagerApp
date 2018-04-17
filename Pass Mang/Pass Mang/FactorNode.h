#pragma once

class FactorNode
{
public:
	FactorNode();
	FactorNode(int n);
	~FactorNode();

	int getFac();
	FactorNode *getpNext();

	void setFac(int n);
	void setpNext(FactorNode *pNode);


private:
	int factor;
	FactorNode *mpNext;
};