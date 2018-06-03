#ifndef _ADMIN_H
#define _ADMIN_H

#include <iostream>
#include <string>
using namespace std;

#include "LinkedListType.h"
#include "ConferenceType.h"

/**
*	���� ������ ���� ������ ���
*/
class Admin
{
public:
	/**
	*	�⺻ ������
	*/
	Admin() 
	{
		m_Command = 0;
		Root_List = NULL;
	}

	/**
	*	�Ҹ���
	*/
	~Admin() 
	{
		Root_List = NULL;
	}

	/**
	*	@brief	������ ��� ����
	*	@pre	��� ����
	*	@post	��� ��
	*/
	void Run(LinkedListType<ConferenceType> * inList);

	/**
	*	@brief	��� ����� ȭ�鿡 ����ϰ� ����� �Է¹޴´�
	*	@pre	.
	*	@post	.
	*	@return	�Է��� ���
	*/
	int GetCommand();

	/**
	*	@brief	���Ǹ���Ʈ�� ������ �����Ѵ�
	*	@pre	.
	*	@post	.
	*	@return	.
	*/
	LinkedListType<SessionType> * GetChangeSessionList();

	/**
	*	@brief	������Ʈ�� ������ �����Ѵ�.
	*	@pre	.
	*	@post	.
	*	@return	.
	*/
	LinkedListType<PaperType> * GetChangePaperList();

	/**
	*	@brief	���� ����Ʈ�� ���Ե� ��� �����͸� ����ȭ�� ����Ѵ�.
	*	@pre	.
	*	@post	��µ�
	*/
//	void PrintALlStructure();

protected:
	int m_Command;		///< ����� ���
	LinkedListType<ConferenceType> * Root_List;		///< ���۷��� ����Ʈ ������
};

#endif _ADMIN_H