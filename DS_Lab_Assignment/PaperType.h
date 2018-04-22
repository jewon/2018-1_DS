#ifndef _PAPER_TYPE_H
#define _PAPER_TYPE_H

#include<iostream>
#include<string>
using namespace std;

/**
*	������Ÿ��
*/
class PaperType
{
public:
	/**
	*	����Ʈ ������
	*/
	PaperType()
	{
		m_pName = "noName";
		m_pAuthor = "noAuthor";
		m_pPages = 0;
	}


	/**
	*	����Ʈ �Ҹ���
	*/
	~PaperType() 
	{}

	/**
	*	@brief	�������� �߻�ȭ�� Ÿ���̸��� �˷���
	*	@pre	.
	*	@post	.
	*	@return	�߻�ȭ�� Ÿ���̸�
	*/
	string WhatType()
	{
		return "��";
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
	*	@brief	���� ��ȯ
	*	@pre	���� �ʱ�ȭ
	*	@post	.
	*	@return	����
	*/
	string GetName()
	{
		return m_pName;
	}

	/**
	*	@brief	���ڸ� ��ȯ
	*	@pre	���ڸ� �ʱ�ȭ
	*	@post	.
	*	@return	���ڸ�
	*/
	string GetAuthor()
	{
		return m_pAuthor;
	}

	/**
	*	@brief	���� �Է�
	*	@pre	.
	*	@post	���� �Էµ�
	*	@param	inName	�Է��� ����
	*/
	void SetName(string inName)
	{
		m_pName = inName;
	}

	/**
	*	@brief	���ֳ���� �Է�
	*	@pre	.
	*	@post	���ֳ���� �Էµ�
	*	@param	inDate	�Է��� ���ֳ����
	*/
	void SetAuthor(string inAuthor)
	{
		m_pAuthor = inAuthor;
	}

	/**
	*	@brief	������ �� �Է�
	*	@pre	.
	*	@post	������ �� �Էµ�
	*	@param	inPages	�Է��� ������ ��
	*/
	void SetPages(int inPages)
	{
		m_pPages = inPages;
	}

	/**
	*	@brief	�� ���ڵ� �Է�
	*	@pre	.
	*	@post	�� ���ڵ尡 �Էµ�
	*	@param	inName	�Է��� �̸�
	*	@param	inAuthor	�Է��� ����
	*	@parm	inPages		�Է��� ������ ��
	*/
	void SetRecord(string inName, string inAuthor, int inPages)
	{
		SetName(inName);
		SetAuthor(inAuthor);
		SetPages(inPages);
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
	*	@brief	���ڸ� ���
	*	@pre	���ڸ� ����
	*	@post	���ڸ� ���
	*/
	void DisplayAuthorOnScreen()
	{
		cout << "\tAuthor : " << m_pAuthor << endl;
	};

	/**
	*	@brief	������ �� ���
	*	@pre	������ �� ����
	*	@post	������ �� ���
	*/
	void DisplayPagesOnScreen()
	{
		cout << "\tTimes : " << m_pPages << endl;
	};

	/**
	*	@brief	���ڵ� ���
	*	@pre	���ڵ� ��ü �Էµ�
	*	@post	���ڵ� ��ü ���
	*/
	void DisplayRecordOnScreen()
	{
		DisplayNameOnScreen();
		DisplayAuthorOnScreen();
		DisplayPagesOnScreen();
	};

	void DisplayBriefOnScreen()
	{
		cout << "\t" << m_pName << "(" << m_pAuthor << ", " << m_pPages << "pages)\n";
	}

	/**
	*	@brief	����ڷκ��� �̸� �Է¹���
	*	@pre	.
	*	@post	�̸��� �Էµ�
	*/
	void SetNameFromKB();

	/**
	*	@brief	����ڷκ��� ���ڸ� �Է¹���
	*	@pre	.
	*	@post	���ڸ��� �Էµ�
	*/
	void SetAuthorFromKB();

	/**
	*	@brief	����ڷκ��� ������ �� �Է¹���
	*	@pre	.
	*	@post	������ �� �Էµ�
	*/
	void SetPagesFromKB();

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
	bool operator>(PaperType item);

	/**
	*	@brief	�̸��� �������� �� ������ ���ϴ� ���۷�����
	*/
	bool operator<(PaperType item);

	/**
	*	@brief	�̸��� �������� �� ������ ���ϴ� ���۷�����
	*/
	bool operator==(PaperType item);


protected:
	string m_pName;		///< ������
	string m_pAuthor;	///< ������
	int m_pPages;		///< ��������
};
#endif // _PAPER_TYPE_H