#pragma once
#include "List.h"
#include "factorStack.h"
#include <vector>
#include <iostream>


using std::vector;
vector<int> *calcFactors(List& primeList, int n);
void calcNextFactor(List &primeList, vector<int> *pVec, int n);
void printFactors(vector<int> *pVec);