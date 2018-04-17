#include "List.h"

// default constructor; will always set mpHead to NULL or nullptr
List::List()
{
	mpHead = nullptr;
}

List::List(const List &copyList)
{
	ListNode *pNew = nullptr, *pPrev = nullptr, *pCur = copyList.mpHead;
	mpHead = nullptr;
	while (pCur != nullptr)
	{
		pNew = new ListNode(pCur->getData());
		if (mpHead == nullptr)
		{
			mpHead = pNew;
		}
		pCur = pCur->getNextPtr();
		if (pPrev == nullptr)
		{
			pPrev = pNew;
		}
		else
		{
			pPrev->setNextPtr(pNew);
			pPrev = pNew;
		}
	}
}

List::~List()                   // destructor - implicitly invoked when a List object leaves scope
{
	//cout << "Inside List's destructor! Freeing each ListNode in the List!" << endl;
	destroyList();
}

// this function must allocate new memory for each of the nodes in rhs to construct "this" object
List & List::operator= (const List &rhs) // overloaded assignment operator - must perform a deep copy
{
	// you must use a loop, which visits each of the nodes in List rhs, and assign the data to the new nodes
	// How to use new operator? ListNode *pMem = new ListNode; new is similar to the results of using malloc ()

	// fill in your code here!
	List tempL(rhs);
	this->setHeadPtr(tempL.getHeadPtr());

	return (*this);
}

// getter
ListNode * List::getHeadPtr() const
{
	return mpHead;
}

// setter
void List::setHeadPtr(ListNode * const pNewHead) 
{
	mpHead = pNewHead;
}

// This function creates a new ListNode on the heap, and uses the ListNode constructor to initialize the node!
bool List::insertAtFront(const int newData)     // inserts newData at the beginning or front of the list
{
	ListNode *pMem = makeNode(newData);
	bool success = false;                   // C++ has built in bool types - false, true

	if (pMem != nullptr)
	{
		success = true; // allocated memory successfully
						// pMem is pointing to a ListNode object, but a List object does not have direct access to it; must use a setter!
		pMem->setNextPtr(mpHead);
		mpHead = pMem;
	}

	return success;
}

// inserts newData at the end of the list
bool List::insertAtEnd(const int newData)
{
	bool success = false;

	// fill in your code here!

	return success;
}

void List::initList(int size)
{
	for (int i = size; i >= 1; --i)
	{
		insertAtFront(i);
	}
}

int List::getElements()
{
	int i = 0;
	ListNode *pCur = mpHead;
	while (pCur != nullptr)
	{
		++i;
		pCur = pCur->getNextPtr();
	}

	return i;
}

void List::setPrimes() // Sets the least prime factor of each int in a list
{
	int nInts = getElements();
	ListNode *pCur = nullptr;
	mpHead->setSPF(1);

	for (int cPrime = 2; cPrime <= nInts; ++cPrime)
	{
		pCur = mpHead;
		for (int i = 1; i <= nInts; ++i)
		{

			if ((pCur->getPrime() == -1) && (pCur->getData() % cPrime == 0))
			{
				pCur->setSPF(cPrime);
			}
			pCur = pCur->getNextPtr();
		}
	}
}

// Finds the least prime factor of n given n is within the list
int List::findLPF(int n)
{
	ListNode *pCur = mpHead;

	while (pCur != nullptr && pCur->getData() != n)
	{
		pCur = pCur->getNextPtr();
	}

	return pCur->getSPF();
}
 
// determines if the list is empty;  
// returns true if the list is empty; false otherwise
bool List::isEmpty()
{
	return (mpHead == nullptr);
}

// deletes the node at the front of the list and returns a copy of the data
// precondition: list must not be empty
int List::deleteAtFront()
{
	int data = 0;

	// fill in your code here! use the delete operator!

	return data;
}

// deletes the node with data == searchValue;
// returns true if the value was found; false otherwise
// precondition: list must not be empty
bool List::deleteNode(const int searchValue)
{
	bool success = false;
	ListNode *pCur = mpHead;
	// fill in your code here! use the delete operator!
	while (pCur != nullptr && pCur->getData() != searchValue)
	{
		pCur = pCur->getNextPtr();
	}

	if (pCur != nullptr)
	{
		delete pCur;
		success = true;
	}
	return success;
}

// deletes the node at the end of the list and returns a copy of the data
// precondition: list must not be empty
int List::deleteAtEnd()
{
	int data = 0;

	// fill in your code here! use the delete operator!
	ListNode *pCur = nullptr, *pPrev = nullptr;
	pCur = mpHead;

	while (pCur != nullptr && pCur->getNextPtr() != nullptr)
	{
		pCur = pCur->getNextPtr();
	}

	if (pCur->getNextPtr() == nullptr)
	{
		delete pCur;
	}
	else
	{
		delete pCur;
	}

	return data;
}

// visits each node, print the node's data
void List::printList()
{
	ListNode *pCur = mpHead;

	while (pCur != nullptr)
	{
		cout << "Integer: " << pCur->getData()<< " LPF: " << pCur->getPrime() << endl;
		pCur = pCur->getNextPtr();
	}
}


//////////// private member functions! //////////////

// allocates memory for a Listnode; initializes the memory with newData
ListNode * List::makeNode(const int newData)    // will only call within insert functions
{
	ListNode *pMem = new ListNode(newData);  // ListNode constructor is invoked!

	return pMem;
}

// we created this function so that we could use recursion to delete the nodes!
void List::destroyListHelper(ListNode * const pMem)
{
	if (pMem != nullptr)
	{
		destroyListHelper(pMem->getNextPtr());
		delete pMem;    // delete from the back of list to the front!
	}
}

// deletes each node to free memory; will call in the destructor
void List::destroyList()
{
	destroyListHelper(mpHead);
}