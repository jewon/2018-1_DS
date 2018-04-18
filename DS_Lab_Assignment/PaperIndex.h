#ifndef _SEARCH_H
#define _SEARCH_H

#include "LinkedListType.h"
#include "ConferenceType.h"

#include <iostream>
#include <string>
using namespace std;

class PaperIndex
{
public:
	/**
	*	디폴트 생성자
	*/
	PaperIndex() {}

	PaperIndex(LinkedListType<ConferenceType> ConfList)
	{
		
	}

	void IndexIt(LinkedListType<ConferenceType> ConfList);

private:
	LinkedListType <PaperType> EveryPaperList;
};


#endif _SEARCH_H