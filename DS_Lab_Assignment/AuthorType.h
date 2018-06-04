#ifndef _PAPER_TYPE_H
#define _PAPER_TYPE_H

#include<iostream>
#include<string>
using namespace std;

/**
*	������Ÿ��
*/
class AuthorType
{
public:
	/**
	*	����Ʈ ������
	*/
	AuthorType()
	{
		m_pName = "noName";
	}


	/**
	*	����Ʈ �Ҹ���
	*/
	~AuthorType() 
	{}

	/**
	*	@brief	�������� �߻�ȭ�� Ÿ���̸��� �˷���
	*	@pre	.
	*	@post	.
	*	@return	�߻�ȭ�� Ÿ���̸�
	*/
	string WhatType()
	{
		return "Author";
	}

	/**
	*	@brief	�����ΰ� �����ϴ� �߻�ȭ�� �������� �˷���
	*	@pre	.
	*	@post	.
	*	@return	�߻�ȭ�� ���� ���� ������ ������ ������ ��Ʈ��
	*/
	string WhatInclude()
	{
		return "�̸�\t����\t������";
	}

	/**
	*	@brief	Author�� ��ȯ
	*	@pre	Author�� �ʱ�ȭ
	*	@post	.
	*	@return	Author��
	*/
	string GetName()
	{
		return m_pName;
	}

	/**
	*	@brief	Author�� �Է�
	*	@pre	.
	*	@post	Author�� �Էµ�
	*	@param	inName	�Է��� Author��
	*/
	void SetName(string inName)
	{
		m_pName = inName;
	}

	/**
	*	@brief	Author ���ڵ� �Է�
	*	@pre	.
	*	@post	Author ���ڵ尡 �Էµ�
	*	@param	inName	�Է��� �̸�
	*	@param	inAuthor	�Է��� ����
	*	@param	inPages		�Է��� ������ ��
	*/
	void SetRecord(string inName, string inAuthor, int inPages)
	{
		SetName(inName);
	}

	/**
	*	@brief	�̸� ���
	*	@pre	�̸� ����
	*	@post	�̸� ���
	*/
	void DisplayNameOnScreen()
	{
		cout << "\tName : " << m_pName << endl;
	};

	/**
	*	@brief	���ڵ� ���
	*	@pre	���ڵ� ��ü �Էµ�
	*	@post	���ڵ� ��ü ���
	*/
	void DisplayRecordOnScreen()
	{
		DisplayNameOnScreen();
	};

	/**
	*	@brief	�����͸� 1�� �̳��� ������ ���
	*	@pre	.
	*	@post	������ ��µ�
	*/
	void DisplayBriefOnScreen()
	{
		cout << "\t" << m_pName << endl;
	}

	/**
	*	@brief	����ڷκ��� �̸� �Է¹���
	*	@pre	.
	*	@post	�̸��� �Էµ�
	*/
	void SetNameFromKB();

	/**
	*	@brief	����ڷκ��� ���ڵ� ��ü �Է¹���
	*	@pre	.
	*	@post	���ڵ尡 �Էµ�
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
	bool operator>(AuthorType item);

	/**
	*	@brief	�̸��� �������� �� ������ ���ϴ� ���۷�����
	*/
	bool operator<(AuthorType item);

	/**
	*	@brief	�̸��� �������� �� ������ ���ϴ� ���۷�����
	*/
	bool operator==(AuthorType item);

	bool NameFind(string f) { return  false; }
protected:
	string m_pName;		///< Author����
};
#endif // _PAPER_TYPE_H