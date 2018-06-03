#ifndef _SESSION_TYPE_H
#define _SESSION_TYPE_H

#include <iostream>
#include <string>
using namespace std;

#include"AVL.h"
#include"InfoChange.h"
#include"AuthorType.h"

/**
*	����Ÿ�� Ŭ����
*/
class PaperType
{
public:
	/**
	*	����Ʈ ������
	*/
	PaperType()
	{
		PaperList = NULL;
	}

	/**
	*	�Ҹ���
	*/
	~PaperType() 
	{
		PaperList = NULL;
	}

	/**
	*	@brief	������ ��������� ���ο� ������Ʈ �Ҵ�
	*	@pre	ConferencTyepe �ʱ�ȭ
	*	@post	PaperList�� �� ���� ����Ʈ �Ҵ�
	*/
	BinarySearchTree<AuthorType> * MakePaperList()
	{
		PaperList = new BinarySearchTree<AuthorType>;
		return PaperList;
	}

	/**
	*	@brief	������ ��������� �Ҵ�� �� ����Ʈ ����
	*	@pre	PaperList�� �Ҵ��
	*	@post	PaperList�� ������
	*/
	void DeletePaperList()
	{
		if(PaperList != NULL)
			delete PaperList;
		PaperList = NULL;
	}

	/**
	*	@brief	�������� �߻�ȭ�� Ÿ���̸��� �˷���
	*	@pre	.
	*	@post	.
	*	@return	�߻�ȭ�� Ÿ���̸�
	*/
	string WhatType()
	{
		return "����";
	}

	/**
	*	@brief	�����ΰ� �����ϴ� �߻�ȭ�� �������� �˷���
	*	@pre	.
	*	@post	.
	*	@return	�߻�ȭ�� ���� ���� ������ ������ ������ ��Ʈ��
	*/
	string WhatInclude()
	{
		return "�̸�\t������Ʈ";
	}

	/**
	*	@brief	���Ǹ� ��ȯ
	*	@pre	���Ǹ� �ʱ�ȭ
	*	@post	.
	*	@return	���Ǹ�
	*/
	string GetName()
	{
		return m_sName;
	}

	/**
	*	@brief	�� ����Ʈ ��ȯ
	*	@pre	�� ����Ʈ �ʱ�ȭ
	*	@post	.
	*	@return	�� ����Ʈ
	*/
	BinarySearchTree <AuthorType> * GetPaperList()
	{
		return PaperList;
	}
	
	/**
	*	@brief	���Ǹ� �Է�
	*	@pre	.
	*	@post	���Ǹ� �Էµ�
	*	@param	inName	�Է��� ���Ǹ�
	*/
	void SetName(string inName)
	{
		m_sName = inName;
	}

	/**
	*	@brief	������Ʈ �Է�
	*	@pre	.
	*	@post	������Ʈ �Էµ�
	*	@param	inPaperList	�Է��� ������Ʈ
	*/
	void SetPaperList(BinarySearchTree <AuthorType> * inPaperList)
	{
		if(PaperList != NULL)
			delete PaperList;
		PaperList = inPaperList;
	}

	/**
	*	@brief	����ڷκ��� �����̸� �Է¹���
	*	@pre	.
	*	@post	�����̸��� �Էµ�
	*/
	void SetNameFromKB();

	/**
	*	@brief	����ڷκ��� �� ����Ʈ �Է¹��� ���� ����
	*	@pre	.
	*	@post	�� ����Ʈ �Է� �Լ� ����
	*/
	void SetPaperListFromKB();

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
	*	@brief	���� ������ �����ε�(PaperList�����͸� ���������ʰ� NULL�� ��)
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
		if (PaperList != NULL)
			cout << "\tPapers : " << PaperList->GetLength() << endl;
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
	*	@brief	���� �� ���� ���� ���
	*	@pre	.
	*	@post	���� ���� ���
	*/
	//void DoDisplayStructure()
	//{
	//	cout << "  ��  " << m_sName << endl;
	//	if (PaperList != NULL)
	//		PaperList->DisplayAllStructure(2);
	//	else
	//		cout << "    ��  (Empty List)" << endl;
	//}

protected:
	string m_sName;		///< �����̸�
	BinarySearchTree <AuthorType> * PaperList;	///< ���ǿ� ��ǥ�� �� ����Ʈ
};

#endif // _SESSION_TYPE_H
