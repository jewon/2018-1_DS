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
	void Run(BinarySearchTree<ConferenceType> * inList, BinarySearchTree<PaperType> *& pi);

	/**
	*	@brief	��� ����� ȭ�鿡 ����ϰ� ����� �Է¹޴´�
	*	@pre	.
	*	@post	.
	*	@return	�Է��� ���
	*/
	int GetCommand();

	/**
	*	@brief	Paper����Ʈ�� ������ �����Ѵ�
	*	@pre	.
	*	@post	.
	*	@return	.
	*/
	BinarySearchTree<PaperType> * GetChangePaperList();

	/**
	*	@brief	Author����Ʈ�� ������ �����Ѵ�.
	*	@pre	.
	*	@post	.
	*	@return	.
	*/
	BinarySearchTree<AuthorType> * GetChangeAuthorList();

	/**
	*	@brief	���ڵ带 ���Ͽ��� �о����
	*	@pre	������Ʈ ������ dblp.txt ����
	*	@post	���ڵ尡 �Էµ�
	*/
	void FileIn();

	/**
	*	@brief	���� ����Ʈ�� ���Ե� ��� �����͸� ����ȭ�� ����Ѵ�.
	*	@pre	.
	*	@post	��µ�
	*/
//	void PrintALlStructure();

	BinarySearchTree<PaperType> * MakerPaperTreeSearch();
	BinarySearchTree<AuthorType>* MakerAuthorTreeSearch();
	bool NameFind(string f) { return false; }

protected:
	int m_Command;		///< ����� ���
	BinarySearchTree<ConferenceType> * Root_List;		///< ���۷��� ����Ʈ ������
};

#endif _ADMIN_H