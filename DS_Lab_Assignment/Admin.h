#ifndef _ADMIN_H
#define _ADMIN_H

#include <iostream>
#include <string>
using namespace std;

#include "LinkedListType.h"
#include "ConferenceType.h"

class Admin
{
public:
	Admin() 
	{
		m_Command = 0;
		Root_List = NULL;
	}
	~Admin() 
	{
		Root_List = NULL;
	}
	void Run(LinkedListType<ConferenceType> * inList);

	int GetCommand();
	LinkedListType<SessionType> * Admin::GetChangeSessionList();
	LinkedListType<PaperType> * Admin::GetChangePaperList();

protected:
	int m_Command;
	LinkedListType<ConferenceType> * Root_List;

};

#endif _ADMIN_H