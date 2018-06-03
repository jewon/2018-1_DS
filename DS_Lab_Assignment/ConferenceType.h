#ifndef _CONFERENCE_TYPE_H
#define _CONFERENCE_TYPE_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "AVL.h"
#include "PaperType.h"
#include "InfoChange.h"


/**
*	���۷���Ÿ��
*/
class ConferenceType
{
public:
	/**
	*	����Ʈ ������
	*/
	ConferenceType()
	{
		PaperList = NULL;
	} 

	/**
	*	�Ҹ���
	*/
	~ConferenceType()                       
	{
		PaperList = NULL;
	}

	/**
	*	@brief	������ ��������� ���ο� Paper����Ʈ �Ҵ�
	*	@pre	ConferencTyepe �ʱ�ȭ
	*	@post	PaperList�� �� Paper ����Ʈ �Ҵ�
	*/
	BinarySearchTree<PaperType> * MakePaperList()
	{
		if(PaperList == NULL)
			PaperList = new BinarySearchTree<PaperType>;
		return PaperList;
	}

	/**
	*	@brief	������ ��������� �Ҵ�� Paper ����Ʈ ����
	*	@pre	PaperList�� �Ҵ��
	*	@post	PaperList�� ������
	*/
	void DeletePaperList()
	{
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
		return "�м���ȸ";
	}

	/**
	*	@brief	�����ΰ� �����ϴ� �߻�ȭ�� �������� �˷���
	*	@pre	.
	*	@post	.
	*	@return	�߻�ȭ�� ���� ���� ������ ������ ������ ��Ʈ��
	*/
	string WhatInclude()
	{
		return "�м���ȸ��\t���۳����\tPaper����Ʈ";
	}

	/**
	*	@brief	�м���ȸ�� ��ȯ
	*	@pre	�м���ȸ�� �ʱ�ȭ
	*	@post	.
	*	@return	�м���ȸ��
	*/
	string GetName()
	{
		return m_hName;
	}

	/**
	*	@brief	Paper ����Ʈ ��ȯ
	*	@pre	Paper ����Ʈ �ʱ�ȭ
	*	@post	.
	*	@return	Paper ����Ʈ(LinkedList)
	*/
	BinarySearchTree <PaperType> * GetPaperList()
	{
		return PaperList;
	}

	/**
	*	@brief	�м���ȸ�� �Է�
	*	@pre	.
	*	@post	�м���ȸ�� �Էµ�
	*	@param	inName	�Է��� �м���ȸ��
	*/
	void SetName(string inName)
	{
		m_hName = inName;
	}

	/**
	*	@brief	���ֳ���� �Է�
	*	@pre	.
	*	@post	���ֳ���� �Էµ�
	*	@param	inDate	�Է��� ���ֳ����
	*/
	void SetDate(string inDate)
	{
		m_hDate = inDate;
	}

	/**
	*	@brief	Paper ����Ʈ �Է�
	*	@pre	.
	*	@post	Paper ����Ʈ �Էµ�
	*	@param	inPaperList	�Է��� Paper ����Ʈ(LinkedList)
	*/
	void SetPaperList(BinarySearchTree <PaperType> * inPaperList)
	{
		if(PaperList!=NULL)
			delete PaperList;
		PaperList = inPaperList;
	}

	/**
	*	@brief	�м���ȸ ���ڵ� �Է�
	*	@pre	.
	*	@post	�м���ȸ ���ڵ尡 �Էµ�
	*	@param	inName	�Է��� �̸�
	*	@param	inDate	�Է��� ������
	*	@param	inTimes	�Է��� Ƚ��
	*	@param	inOrgan	�Է��� ���
	*	@param	inSimple	�Է��� ����
	*	@param	inPlace	�Է��� ���
	*	@param	inDateTime	�Է��� �Ͻ�
	*	@param	inISBN	�Է��� Ƚ��
	*	@param	inPaperList	�Է��� Paper����Ʈ
	*/
	void SetRecord(string inName, string inDate, int inTimes, string inOrgan, string inSimple, string inPlace, string inDateTime, string inISBN, BinarySearchTree <PaperType> * inPaperList)
	{
		SetName(inName);
		SetDate(inDate);
		SetPaperList(inPaperList);
	}

	/**
	*	@brief	�̸� ���
	*	@pre	�̸� ����
	*	@post	�̸� ���
	*/
	void DisplayNameOnScreen()
	{
		cout << "\tName : " << m_hName << endl;
	};

	/**
	*	@brief	������ ���
	*	@pre	������ ����
	*	@post	������ ���
	*/
	void DisplayDateOnScreen()
	{
		cout << "\tDate   : " << m_hDate << endl;
	};

	/**
	*	@brief	���ڵ� ���
	*	@pre	���ڵ� ��ü �Էµ�
	*	@post	���ڵ� ��ü ���
	*/
	void DisplayRecordOnScreen()
	{
		DisplayNameOnScreen();
		DisplayDateOnScreen();
		if (PaperList != NULL)
			cout << "\tSessions : " << PaperList->GetLength() << endl;
	};

	/**
	*	@brief	���ڵ� �����ϰ� ��� ex. �м���ȸ��(���ֳ⵵)
	*	@pre	���ڵ� ��ü �Էµ�
	*	@post	���ڵ� ��ü ������ ���
	*/
	void DisplayBriefOnScreen()
	{
		cout << m_hName << "(" << m_hDate.substr(0, 4) << ")" << endl;
	};

	/**
	*	@brief	����ڷκ��� �̸� �Է¹���
	*	@pre	.
	*	@post	�̸��� �Էµ�
	*/
	void SetNameFromKB();

	/**
	*	@brief	����ڷκ��� ���ֳ���� �Է¹���
	*	@pre	.
	*	@post	���ֳ���� �Էµ�
	*/
	void SetDateFromKB();

	/**
	*	@brief	����ڷκ��� Paper ����Ʈ �Է¹���
	*	@pre	.
	*	@post	BinarySearchTree�� Paper ����Ʈ �Է� �Լ� ����
	*/
	void SetPaperListFromKB();

	/**
	*	@brief	����ڷκ��� ���ڵ� ��ü �Է¹���
	*	@pre	.
	*	@post	���ڵ尡 �Էµ�
	*/
	void SetRecordFromKB();

	/**
	*	@brief	���ڵ带 ���Ͽ��� �о����
	*	@pre	������ ���� ����
	*	@post	���ڵ尡 �Էµ�
	*	@param	fin	���� �̸�
	*	@return	������ 1, ���н� 0 ��ȯ
	*/
	int ReadDataFromFile(ifstream& fin);

	/**
	*	@brief	���ڵ带 ���Ϸ� ��
	*	@pre	����Ʈ �ʱ�ȭ, �� ���� ���� ����
	*	@post	�� ���Ͽ� ���ڵ尡 �Էµ�
	*	@param	fout	���� �̸�
	*	@return	������ 1, ���н� 0 ��ȯ
	*/
	int WriteDataToFile(ofstream& fout);

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
	*	@brief	Paper �� ���� ���� ��0��
	*	@pre	.
	*	@post	���� ���� ���
	*/
	//void DoDisplayStructure()
	//{
	//	cout << "��  " << m_hName << endl;
	//	if (PaperList != NULL)
	//		PaperList->DoDisplayAllStructure();
	//	else
	//		cout << "  ��  (Empty List)" << endl;
	//}

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
	bool operator>(ConferenceType item);

	/**
	*	@brief	�̸��� �������� �� ������ ���ϴ� ���۷�����
	*/
	bool operator<(ConferenceType item);

	/**
	*	@brief	�̸��� �������� �� ������ ���ϴ� ���۷�����
	*/
	bool operator==(ConferenceType item);

	/**
	*	@brief	���Կ����� �����ε�(PaperList�����͸� ���������ʰ� NULL�� ��)
	*/
	ConferenceType& operator=(const ConferenceType& c);

protected:
	string m_hName;		///< �м���ȸ��
	string m_hDate;		///< ���۳����(YYYY.MM.DD)
	BinarySearchTree <PaperType> * PaperList;	///< Paper ����Ʈ ������
};

#endif	// _CONFERENCE_TYPE_H
