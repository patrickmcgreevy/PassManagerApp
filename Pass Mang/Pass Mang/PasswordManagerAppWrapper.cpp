#include "PasswordManagerAppWrapper.h"

AppWrapper::AppWrapper(int max)
{
	mpList = new List();
	if (mpList != nullptr)
	{
		mpList->initList(max);
	}
	mpVec = nullptr;
}

AppWrapper::~AppWrapper()
{

}