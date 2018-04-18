#ifndef _SESSION_TYPE_H
#define _SESSION_TYPE_H

#include <iostream>
#include <string>
using namespace std;

#include"LinkedListType.h"
#include"InfoChange.h"
#include"PaperType.h"

class SessionType
{
public:
	/**
	*	����Ʈ ������
	*/
	SessionType()
	{
		m_sName = "noName";
	}

	/**
	*	�Ҹ���
	*/
	~SessionType() 
	{
		
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
	LinkedListType <PaperType> GetPaperList()
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
	void SetPaperList(LinkedListType <PaperType> inPaperList)
	{
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
	bool operator>(SessionType item);

	/**
	*	@brief	�̸��� �������� �� ������ ���ϴ� ���۷�����
	*/
	bool operator<(SessionType item);

	/**
	*	@brief	�̸��� �������� �� ������ ���ϴ� ���۷�����
	*/
	bool operator==(SessionType item);

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
		cout << "\tPapers : " << PaperList.GetLength() << endl;
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
	*	@brief	�� ����Ʈ���� Ű���尡 ���Ե� �� ã�� ����Ʈ�� ��ȯ
	*	@pre	�� ����Ʈ �ʱ�ȭ
	*	@post	.
	*	@parm word	ã�� �ܾ�
	@	@return	Ű���尡 ���Ե� ������ ����Ʈ
	*/
	LinkedListType<PaperType> SearchPaper(string word)
	{
		return PaperList.FindByName(word);
	}

protected:
	string m_sName;		///< �����̸�
	LinkedListType <PaperType> PaperList;	///< ���ǿ� ��ǥ�� �� ����Ʈ
};

#endif // _SESSION_TYPE_H
