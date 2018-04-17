#pragma once
#include "functions.h"

vector<int> *calcFactors(List &primeList, int n)
{
	vector<int> *pVec = new vector<int>;
	int x = 0;

	if (pVec != nullptr)
	{
		if (n > 2)
		{
			x = primeList.findLPF(n);
			calcNextFactor(primeList, pVec, (n / x));
			pVec->push_back(x);
		}
	}

	return pVec;
}

void calcNextFactor(List &primeList, vector<int> *pVec, int n)
{
	int x = 0;
	if (n > 2)
	{
		x = primeList.findLPF(n);
		calcNextFactor(primeList, pVec, (n / x));
		pVec->push_back(x);
	}
}

void printFactors(vector<int> *pVec)
{
	for (int i = 0; i < pVec->size(); ++i)
	{
		cout << (*pVec)[i] << endl;
	}
}