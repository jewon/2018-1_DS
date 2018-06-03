#ifndef _SESSION_TYPE_H
#define _SESSION_TYPE_H

#include <iostream>
#include <string>
using namespace std;

#include"AVL.h"
#include"InfoChange.h"
#include"AuthorType.h"

/**
*	PaperŸ�� Ŭ����
*/
class PaperType
{
public:
	/**
	*	����Ʈ ������
	*/
	PaperType()
	{
		AuthorList = NULL;
	}

	/**
	*	�Ҹ���
	*/
	~PaperType() 
	{
		AuthorList = NULL;
	}

	/**
	*	@brief	������ ��������� ���ο� Author����Ʈ �Ҵ�
	*	@pre	ConferencTyepe �ʱ�ȭ
	*	@post	AuthorList�� �� Paper ����Ʈ �Ҵ�
	*/
	BinarySearchTree<AuthorType> * MakeAuthorList()
	{
		AuthorList = new BinarySearchTree<AuthorType>;
		return AuthorList;
	}

	/**
	*	@brief	������ ��������� �Ҵ�� Author ����Ʈ ����
	*	@pre	AuthorList�� �Ҵ��
	*	@post	AuthorList�� ������
	*/
	void DeleteAuthorList()
	{
		if(AuthorList != NULL)
			delete AuthorList;
		AuthorList = NULL;
	}

	/**
	*	@brief	�������� �߻�ȭ�� Ÿ���̸��� �˷���
	*	@pre	.
	*	@post	.
	*	@return	�߻�ȭ�� Ÿ���̸�
	*/
	string WhatType()
	{
		return "Paper";
	}

	/**
	*	@brief	�����ΰ� �����ϴ� �߻�ȭ�� �������� �˷���
	*	@pre	.
	*	@post	.
	*	@return	�߻�ȭ�� ���� ���� ������ ������ ������ ��Ʈ��
	*/
	string WhatInclude()
	{
		return "�̸�\tAuthor����Ʈ";
	}

	/**
	*	@brief	Paper�� ��ȯ
	*	@pre	Paper�� �ʱ�ȭ
	*	@post	.
	*	@return	Paper��
	*/
	string GetName()
	{
		return m_sName;
	}

	/**
	*	@brief	Author ����Ʈ ��ȯ
	*	@pre	Author ����Ʈ �ʱ�ȭ
	*	@post	.
	*	@return	Author ����Ʈ
	*/
	BinarySearchTree <AuthorType> * GetAuthorList()
	{
		return AuthorList;
	}
	
	/**
	*	@brief	Paper�� �Է�
	*	@pre	.
	*	@post	Paper�� �Էµ�
	*	@param	inName	�Է��� Paper��
	*/
	void SetName(string inName)
	{
		m_sName = inName;
	}

	/**
	*	@brief	Author����Ʈ �Է�
	*	@pre	.
	*	@post	Author����Ʈ �Էµ�
	*	@param	inAuthorList	�Է��� Author����Ʈ
	*/
	void SetAuthorList(BinarySearchTree <AuthorType> * inAuthorList)
	{
		if(AuthorList != NULL)
			delete AuthorList;
		AuthorList = inAuthorList;
	}

	/**
	*	@brief	����ڷκ��� Paper�̸� �Է¹���
	*	@pre	.
	*	@post	Paper�̸��� �Էµ�
	*/
	void SetNameFromKB();

	/**
	*	@brief	����ڷκ��� page �Է¹���
	*	@pre	.
	*	@post	page �Էµ�
	*/
	void SetPagesFromKB();

	/**
	*	@brief	����ڷκ��� Author ����Ʈ �Է¹��� ���� ����
	*	@pre	.
	*	@post	Author ����Ʈ �Է� �Լ� ����
	*/
	void SetAuthorListFromKB();

	/**
	*	@brief	����ڷκ��� ���ڵ� ��ü �Է¹���
	*	@pre	.
	*	@post	���ڵ� ��ü �Է�
	*/
	void SetRecordFromKB();

	/**
	*	@brief	Infochange Ŭ���� ������ ���� ������ ���
	*	@pre	���ڵ� �ʱ�ȭ
	*	@post	���ڵ尡 ����ڿ� ���� ������
	*	@return	������ 1, ���н� 0 ��ȯ
	*/
	int Modify();

	/**
	*	@brief	Infochange Ŭ���� ���� ������ �޴� �����
	*	@pre	.
	*	@post	���� �޴� ���
	*/
	void DisplayMenu();

	/**
	*	@brief	Infochange Ŭ���� ���� ������ ��� �Է� ����
	*	@pre	.
	*	@post	����ڷκ��� ��� �Է�
	*	@return	����ڷκ��� �Է¹��� ���
	*/
	int GetCommand();

	/**
	*	@brief	�̸��� �������� �� ������ ���ϴ� ���۷�����
	*/
	bool operator>(PaperType item);

	/**
	*	@brief	�̸��� �������� �� ������ ���ϴ� ���۷�����
	*/
	bool operator<(PaperType item);

	/**
	*	@brief	�̸��� �������� �� ������ ���ϴ� ���۷�����
	*/
	bool operator==(PaperType item);

	/**
	*	@brief	���� ������ �����ε�(AuthorList�����͸� ���������ʰ� NULL�� ��)
	*/
	PaperType & PaperType::operator=(const PaperType & c);

	/**
	*	@brief	�̸� ���
	*	@pre	�̸� ����
	*	@post	�̸� ���
	*/
	void DisplayNameOnScreen()
	{
		cout << "\tName : " << m_sName << endl;
	};

	/**
	*	@brief	���ڵ� ��ü ���
	*	@pre	.
	*	@post	���ڵ� ��ü ���
	*/
	void DisplayRecordOnScreen()
	{
		DisplayNameOnScreen();
		if (AuthorList != NULL)
			cout << "\tPapers : " << AuthorList->GetLength() << endl;
	}

	/**
	*	@brief	���ڵ� ��ü ������ ���
	*	@pre	.
	*	@post	���ڵ� ��ü ������ ���
	*/
	void DisplayBriefOnScreen()
	{
		DisplayNameOnScreen();
	}

	/**
	*	@brief	Paper �� ���� ���� ���
	*	@pre	.
	*	@post	���� ���� ���
	*/
	//void DoDisplayStructure()
	//{
	//	cout << "  ��  " << m_sName << endl;
	//	if (AuthorList != NULL)
	//		AuthorList->DisplayAllStructure(2);
	//	else
	//		cout << "    ��  (Empty List)" << endl;
	//}

protected:
	string m_sName;		///< Paper�̸�
	string m_sPage;		///< ���� Page
	BinarySearchTree <AuthorType> * AuthorList;	///< ���� ����Ʈ
};

#endif // _SESSION_TYPE_H
