#pragma once
#include "factorStack.h"
#include "FactorNode.h"
#include "findNPrimes.h"
#include "List.h"
#include "ListNode.h"
#include <vector>

using std::vector;

class AppWrapper
{
public:
	AppWrapper(int maxInt);
	~AppWrapper();
private:
	List *mpList;
	vector<int> *mpVec;
};
vector<int> *calcFactors(List& primeList, int n);
void calcNextFactor(List &primeList, vector<int> *pVec, int n);
void printFactors(vector<int> *pVec);