#ifndef _CONFERENCE_TYPE_H
#define _CONFERENCE_TYPE_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "LinkedListType.h"
#include "SessionType.h"
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
		SessionList = NULL;
	} 

	/**
	*	�Ҹ���
	*/
	~ConferenceType()                       
	{
		SessionList = NULL;
	}

	/**
	*	�Ҹ���
	*/
	LinkedListType<SessionType> * MakeSessionList()
	{
		SessionList = new LinkedListType<SessionType>;
		return SessionList;
	}

	void DeleteSessionList()
	{
		delete SessionList;
		SessionList = NULL;
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
		return "�м���ȸ��\t���۳����\t����Ƚ��\t���ֱ����\t�м���ȸ����\t�������\t�����Ͻ�\tISBN\t���Ǹ���Ʈ";
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
	*	@brief	���ֱ���� ��ȯ
	*	@pre	���ֱ���� �ʱ�ȭ
	*	@post	.
	*	@return	���ֱ����
	*/
	string GetOrgan()
	{
		return m_hOrgan;
	}

	/**
	*	@brief	������� ��ȯ
	*	@pre	������� �ʱ�ȭ
	*	@post	.
	*	@return	�������
	*/
	string GetPlace()
	{
		return m_hPlace;
	}

	/**
	*	@brief	�����Ͻ� ��ȯ
	*	@pre	�����Ͻ� �ʱ�ȭ
	*	@post	.
	*	@return	�����Ͻ�
	*/
	string GetDateTime()
	{
		return m_hDateTime;
	}

	/**
	*	@brief	ISBN ��ȯ
	*	@pre	ISBN �ʱ�ȭ
	*	@post	.
	*	@return	ISBN
	*/
	string GetISBN()
	{
		return m_hISBN;
	}

	/**
	*	@brief	���� ����Ʈ ��ȯ
	*	@pre	���� ����Ʈ �ʱ�ȭ
	*	@post	.
	*	@return	���� ����Ʈ(LinkedList)
	*/
	LinkedListType <SessionType> * GetSessionList()
	{
		return SessionList;
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
	*	@brief	����Ƚ�� �Է�
	*	@pre	.
	*	@post	����Ƚ�� �Էµ�
	*	@param	inTimes	�Է��� ����Ƚ��
	*/
	void SetTimes(int inTimes)
	{
		m_hTimes = inTimes;
	}

	/**
	*	@brief	���ֱ���� �Է�
	*	@pre	.
	*	@post	���ֱ���� �Էµ�
	*	@param	inOrgan	�Է��� ���ֱ����
	*/
	void SetOrgan(string inOrgan)
	{
		m_hOrgan = inOrgan;
	}

	/**
	*	@brief	�м���ȸ ���� �Է�
	*	@pre	.
	*	@post	�м���ȸ ���� �Էµ�
	*	@param	inSimple	�Է��� �м���ȸ ����
	*/
	void SetSimple(string inSimple)
	{
		m_hSimple = inSimple;
	}

	/**
	*	@brief	�м���ȸ ��� �Է�
	*	@pre	.
	*	@post	�м���ȸ ��� �Էµ�
	*	@param	inPlace	�Է��� �м���ȸ ���
	*/
	void SetPlace(string inPlace)
	{
		m_hPlace = inPlace;
	}

	/**
	*	@brief	�м���ȸ �����Ͻ� �Է�
	*	@pre	.
	*	@post	�м���ȸ �����Ͻ� �Էµ�
	*	@param	inDate	�Է��� �����Ͻ�
	*/
	void SetDateTime(string inDateTime)
	{
		m_hDateTime = inDateTime;
	}

	/**
	*	@brief	�м���ȸ ISBN �Է�
	*	@pre	.
	*	@post	�м���ȸ ISBN �Էµ�
	*	@param	inISBN	�Է��� ISBN
	*/
	void SetISBN(string inISBN)
	{
		m_hSimple = inISBN;
	}

	/**
	*	@brief	���� ����Ʈ �Է�
	*	@pre	.
	*	@post	���� ����Ʈ �Էµ�
	*	@param	inSessionList	�Է��� ���� ����Ʈ(LinkedList)
	*/
	void SetSessionList(LinkedListType <SessionType> * inSessionList)
	{
		if(SessionList!=NULL)
			delete SessionList;
		SessionList = inSessionList;
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
	*	@param	inSessionList	�Է��� ���Ǹ���Ʈ
	*/
	void SetRecord(string inName, string inDate, int inTimes, string inOrgan, string inSimple, string inPlace, string inDateTime, string inISBN, LinkedListType <SessionType> * inSessionList)
	{
		SetName(inName);
		SetDate(inDate);
		SetTimes(inTimes);
		SetOrgan(inOrgan);
		SetSimple(inSimple);
		SetPlace(inPlace);
		SetDateTime(inDateTime);
		SetISBN(inISBN);
		SetSessionList(inSessionList);
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
	*	@brief	���ֱ�� ���
	*	@pre	���ֱ�� ����
	*	@post	���ֱ�� ���
	*/
	void DisplayOrganOnScreen()
	{
		cout << "\tOrganization : " << m_hOrgan << endl;
	};

	/**
	*	@brief	����Ƚ�� ���
	*	@pre	����Ƚ�� ����
	*	@post	����Ƚ�� ���
	*/
	void DisplayTimesOnScreen()
	{
		cout << "\tTimes : " << m_hTimes << endl;
	};

	/**
	*	@brief	�м���ȸ ���� ���
	*	@pre	�м���ȸ ���� ����
	*	@post	�м���ȸ ���� ���
	*/
	void DisplaySimpleOnScreen()
	{
		cout << m_hSimple << endl;
	};

	/**
	*	@brief	���ڵ� ���
	*	@pre	���ڵ� ��ü �Էµ�
	*	@post	���ڵ� ��ü ���
	*/
	void DisplayRecordOnScreen()
	{
		DisplayNameOnScreen();
		DisplayOrganOnScreen();
		DisplayDateOnScreen();
		DisplayTimesOnScreen();
		if (SessionList != NULL)
			cout << "\tSessions : " << SessionList->GetLength() << endl;
	};

	/**
	*	@brief	���ڵ� �����ϰ� ��� ex. �м���ȸ��(���ֳ⵵)
	*	@pre	���ڵ� ��ü �Էµ�
	*	@post	���ڵ� ��ü ������ ���
	*/
	void DisplayBriefOnScreen()
	{
		cout << m_hSimple << "(" << m_hDate.substr(0, 4) << ")" << endl;
	};

	/**
	*	@brief	����ڷκ��� �̸� �Է¹���
	*	@pre	.
	*	@post	�̸��� �Էµ�
	*/
	void SetNameFromKB();

	/**
	*	@brief	����ڷκ��� �м���ȸ�� �Է¹���
	*	@pre	.
	*	@post	�м���ȸ���� �Էµ�
	*/
	void SetOrganFromKB();

	/**
	*	@brief	����ڷκ��� ���ֳ���� �Է¹���
	*	@pre	.
	*	@post	���ֳ���� �Էµ�
	*/
	void SetDateFromKB();

	/**
	*	@brief	����ڷκ��� ����Ƚ�� �Է¹���
	*	@pre	.
	*	@post	����Ƚ�� �Էµ�
	*/
	void SetTimesFromKB();

	/**
	*	@brief	����ڷκ��� �м���ȸ ���� �Է¹���
	*	@pre	.
	*	@post	�м���ȸ ���� �Էµ�
	*/
	void SetSimpleFromKB();

	/**
	*	@brief	����ڷκ��� �м���ȸ ��� �Է¹���
	*	@pre	.
	*	@post	�м���ȸ ��� �Էµ�
	*/
	void SetPlaceFromKB();

	/**
	*	@brief	����ڷκ��� �м���ȸ �Ͻ� �Է¹���
	*	@pre	.
	*	@post	�м���ȸ �Ͻ� �Էµ�
	*/
	void SetDateTimeFromKB();

	/**
	*	@brief	����ڷκ��� �м���ȸ ISBN �Է¹���
	*	@pre	.
	*	@post	�м���ȸ ISBN �Էµ�
	*/
	void SetISBNFromKB();

	/**
	*	@brief	����ڷκ��� ���� ����Ʈ �Է¹���
	*	@pre	.
	*	@post	LinkedListType�� ���� ����Ʈ �Է� �Լ� ����
	*/
	void SetSessionListFromKB();

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

	//ConferenceType& operator = (const ConferenceType& c);

	///**
	//*	@brief	�� ����Ʈ���� Ű���尡 ���Ե� �� ã�� ����Ʈ�� ��ȯ
	//*	@pre	�� ����Ʈ �ʱ�ȭ
	//*	@post	.
	//*	@parm word	ã�� �ܾ�
	//@	@return	Ű���尡 ���Ե� ������ ����Ʈ
	//*/
	//LinkedListType<PaperType> SearchPaper(string word)
	//{
	//	LinkedListType<PaperType> FoundPaperList;
	//	if (SessionList->GetLength() == 0)
	//		return FoundPaperList;

	//	DoublyIterator<SessionType> iter(SessionList);
	//	SessionType tempSession;
	//	
	//	tempSession = iter.Next();
	//	FoundPaperList = tempSession.SearchPaper(word);

	//	for (int i = 1; i < SessionList.GetLength(); i++)
	//	{
	//		tempSession = iter.Next();
	//		FoundPaperList.Connect(&tempSession.SearchPaper(word));
	//	}

	//	return FoundPaperList;
	//}

protected:
	string m_hName;		///< �м���ȸ��
	string m_hDate;		///< ���۳����(YYYY.MM.DD)
	int m_hTimes;		///< ����Ƚ��
	string m_hOrgan;	///< ���ֱ����
	string m_hSimple;	///< �м���ȸ ����
	string m_hPlace;	///< �м���ȸ �������
	string m_hDateTime;		///< �м���ȸ �����Ͻ�
	string m_hISBN;		///< ISBN
	LinkedListType <SessionType> * SessionList;	///< ���� ����Ʈ
};

#endif	// _CONFERENCE_TYPE_H
