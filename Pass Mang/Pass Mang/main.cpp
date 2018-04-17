#include "functions.h"

using std::cout;
using std::cin;
using std::endl;


int main()
{
	List primeList;

	primeList.initList(1000);
	primeList.setPrimes();

	//primeList.printList();

	//factorStack stack;

	printFactors(calcFactors(primeList, 1000));
	//cout << "cunt";
}