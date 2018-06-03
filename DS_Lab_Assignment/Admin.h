#ifndef _ADMIN_H
#define _ADMIN_H

#include <iostream>
#include <string>
using namespace std;

#include "AVL.h"
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
	void Run(BinarySearchTree<ConferenceType> * inList);

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
	BinarySearchTree<PaperType> * GetChangeSessionList();

	/**
	*	@brief	������Ʈ�� ������ �����Ѵ�.
	*	@pre	.
	*	@post	.
	*	@return	.
	*/
	BinarySearchTree<AuthorType> * GetChangePaperList();



	/**
	*	@brief	���� ����Ʈ�� ���Ե� ��� �����͸� ����ȭ�� ����Ѵ�.
	*	@pre	.
	*	@post	��µ�
	*/
//	void PrintALlStructure();

protected:
	int m_Command;		///< ����� ���
	BinarySearchTree<ConferenceType> * Root_List;		///< ���۷��� ����Ʈ ������
};

#endif _ADMIN_H