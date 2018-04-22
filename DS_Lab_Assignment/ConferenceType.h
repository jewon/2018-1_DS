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
*	컨퍼런스타입
*/
class ConferenceType
{
public:
	/**
	*	디폴트 생성자
	*/
	ConferenceType()
	{
		SessionList = NULL;
	} 

	/**
	*	소멸자
	*/
	~ConferenceType()                       
	{
		SessionList = NULL;
	}

	/**
	*	소멸자
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
	*	@brief	스스로의 추상화된 타입이름을 알려줌
	*	@pre	.
	*	@post	.
	*	@return	추상화된 타입이름
	*/
	string WhatType()
	{
		return "학술대회";
	}

	/**
	*	@brief	스스로가 포함하는 추상화된 정보명을 알려줌
	*	@pre	.
	*	@post	.
	*	@return	추상화된 정보 명을 탭으로 구분해 나열한 스트링
	*/
	string WhatInclude()
	{
		return "학술대회명\t시작년월일\t개최횟수\t개최기관명\t학술대회약자\t개최장소\t개최일시\tISBN\t세션리스트";
	}

	/**
	*	@brief	학술대회명 반환
	*	@pre	학술대회명 초기화
	*	@post	.
	*	@return	학술대회명
	*/
	string GetName()
	{
		return m_hName;
	}

	/**
	*	@brief	개최기관명 반환
	*	@pre	개최기관명 초기화
	*	@post	.
	*	@return	개최기관명
	*/
	string GetOrgan()
	{
		return m_hOrgan;
	}

	/**
	*	@brief	개최장소 반환
	*	@pre	개최장소 초기화
	*	@post	.
	*	@return	개최장소
	*/
	string GetPlace()
	{
		return m_hPlace;
	}

	/**
	*	@brief	개최일시 반환
	*	@pre	개최일시 초기화
	*	@post	.
	*	@return	개최일시
	*/
	string GetDateTime()
	{
		return m_hDateTime;
	}

	/**
	*	@brief	ISBN 반환
	*	@pre	ISBN 초기화
	*	@post	.
	*	@return	ISBN
	*/
	string GetISBN()
	{
		return m_hISBN;
	}

	/**
	*	@brief	세션 리스트 반환
	*	@pre	세션 리스트 초기화
	*	@post	.
	*	@return	세션 리스트(LinkedList)
	*/
	LinkedListType <SessionType> * GetSessionList()
	{
		return SessionList;
	}

	/**
	*	@brief	학술대회명 입력
	*	@pre	.
	*	@post	학술대회명 입력됨
	*	@param	inName	입력할 학술대회명
	*/
	void SetName(string inName)
	{
		m_hName = inName;
	}

	/**
	*	@brief	개최년월일 입력
	*	@pre	.
	*	@post	개최년월일 입력됨
	*	@param	inDate	입력할 개최년월일
	*/
	void SetDate(string inDate)
	{
		m_hDate = inDate;
	}

	/**
	*	@brief	개최횟수 입력
	*	@pre	.
	*	@post	개최횟수 입력됨
	*	@param	inTimes	입력할 개최횟수
	*/
	void SetTimes(int inTimes)
	{
		m_hTimes = inTimes;
	}

	/**
	*	@brief	개최기관명 입력
	*	@pre	.
	*	@post	개최기관명 입력됨
	*	@param	inOrgan	입력할 개최기관명
	*/
	void SetOrgan(string inOrgan)
	{
		m_hOrgan = inOrgan;
	}

	/**
	*	@brief	학술대회 약자 입력
	*	@pre	.
	*	@post	학술대회 약자 입력됨
	*	@param	inSimple	입력할 학술대회 약자
	*/
	void SetSimple(string inSimple)
	{
		m_hSimple = inSimple;
	}

	/**
	*	@brief	학술대회 장소 입력
	*	@pre	.
	*	@post	학술대회 장소 입력됨
	*	@param	inPlace	입력할 학술대회 장소
	*/
	void SetPlace(string inPlace)
	{
		m_hPlace = inPlace;
	}

	/**
	*	@brief	학술대회 개최일시 입력
	*	@pre	.
	*	@post	학술대회 개최일시 입력됨
	*	@param	inDate	입력할 개최일시
	*/
	void SetDateTime(string inDateTime)
	{
		m_hDateTime = inDateTime;
	}

	/**
	*	@brief	학술대회 ISBN 입력
	*	@pre	.
	*	@post	학술대회 ISBN 입력됨
	*	@param	inISBN	입력할 ISBN
	*/
	void SetISBN(string inISBN)
	{
		m_hSimple = inISBN;
	}

	/**
	*	@brief	세션 리스트 입력
	*	@pre	.
	*	@post	세션 리스트 입력됨
	*	@param	inSessionList	입력할 세션 리스트(LinkedList)
	*/
	void SetSessionList(LinkedListType <SessionType> * inSessionList)
	{
		if(SessionList!=NULL)
			delete SessionList;
		SessionList = inSessionList;
	}

	/**
	*	@brief	학술대회 레코드 입력
	*	@pre	.
	*	@post	학술대회 레코드가 입력됨
	*	@param	inName	입력할 이름
	*	@param	inDate	입력할 시작일
	*	@param	inTimes	입력할 횟수
	*	@param	inOrgan	입력할 기관
	*	@param	inSimple	입력할 약자
	*	@param	inPlace	입력할 장소
	*	@param	inDateTime	입력할 일시
	*	@param	inISBN	입력할 횟수
	*	@param	inSessionList	입력할 세션리스트
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
	*	@brief	이름 출력
	*	@pre	이름 존재
	*	@post	이름 출력
	*/
	void DisplayNameOnScreen()
	{
		cout << "\tName : " << m_hName << endl;
	};

	/**
	*	@brief	개최일 출력
	*	@pre	개최일 존재
	*	@post	개최일 출력
	*/
	void DisplayDateOnScreen()
	{
		cout << "\tDate   : " << m_hDate << endl;
	};

	/**
	*	@brief	개최기관 출력
	*	@pre	개최기관 존재
	*	@post	개최기관 출력
	*/
	void DisplayOrganOnScreen()
	{
		cout << "\tOrganization : " << m_hOrgan << endl;
	};

	/**
	*	@brief	시행횟수 출력
	*	@pre	시행횟수 존재
	*	@post	시행횟수 출력
	*/
	void DisplayTimesOnScreen()
	{
		cout << "\tTimes : " << m_hTimes << endl;
	};

	/**
	*	@brief	학술대회 약자 출력
	*	@pre	학술대회 약자 존재
	*	@post	학술대회 약자 출력
	*/
	void DisplaySimpleOnScreen()
	{
		cout << m_hSimple << endl;
	};

	/**
	*	@brief	레코드 출력
	*	@pre	레코드 전체 입력됨
	*	@post	레코드 전체 출력
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
	*	@brief	레코드 간략하게 출력 ex. 학술대회명(개최년도)
	*	@pre	레코드 전체 입력됨
	*	@post	레코드 전체 간략히 출력
	*/
	void DisplayBriefOnScreen()
	{
		cout << m_hSimple << "(" << m_hDate.substr(0, 4) << ")" << endl;
	};

	/**
	*	@brief	사용자로부터 이름 입력받음
	*	@pre	.
	*	@post	이름이 입력됨
	*/
	void SetNameFromKB();

	/**
	*	@brief	사용자로부터 학술대회명 입력받음
	*	@pre	.
	*	@post	학술대회명이 입력됨
	*/
	void SetOrganFromKB();

	/**
	*	@brief	사용자로부터 개최년월일 입력받음
	*	@pre	.
	*	@post	개최년월일 입력됨
	*/
	void SetDateFromKB();

	/**
	*	@brief	사용자로부터 개최횟수 입력받음
	*	@pre	.
	*	@post	개최횟수 입력됨
	*/
	void SetTimesFromKB();

	/**
	*	@brief	사용자로부터 학술대회 약자 입력받음
	*	@pre	.
	*	@post	학술대회 약자 입력됨
	*/
	void SetSimpleFromKB();

	/**
	*	@brief	사용자로부터 학술대회 장소 입력받음
	*	@pre	.
	*	@post	학술대회 장소 입력됨
	*/
	void SetPlaceFromKB();

	/**
	*	@brief	사용자로부터 학술대회 일시 입력받음
	*	@pre	.
	*	@post	학술대회 일시 입력됨
	*/
	void SetDateTimeFromKB();

	/**
	*	@brief	사용자로부터 학술대회 ISBN 입력받음
	*	@pre	.
	*	@post	학술대회 ISBN 입력됨
	*/
	void SetISBNFromKB();

	/**
	*	@brief	사용자로부터 세션 리스트 입력받음
	*	@pre	.
	*	@post	LinkedListType의 세션 리스트 입력 함수 실행
	*/
	void SetSessionListFromKB();

	/**
	*	@brief	사용자로부터 레코드 전체 입력받음
	*	@pre	.
	*	@post	레코드가 입력됨
	*/
	void SetRecordFromKB();

	/**
	*	@brief	레코드를 파일에서 읽어들임
	*	@pre	파일이 열려 있음
	*	@post	레코드가 입력됨
	*	@param	fin	파일 이름
	*	@return	성공시 1, 실패시 0 반환
	*/
	int ReadDataFromFile(ifstream& fin);

	/**
	*	@brief	레코드를 파일로 씀
	*	@pre	리스트 초기화, 쓸 파일 열려 있음
	*	@post	쓸 파일에 레코드가 입력됨
	*	@param	fout	파일 이름
	*	@return	성공시 1, 실패시 0 반환
	*/
	int WriteDataToFile(ofstream& fout);

	/**
	*	@brief	Infochange 클래스 접근해 정보 수정시 사용
	*	@pre	레코드 초기화
	*	@post	레코드가 사용자에 의해 수정됨
	*	@return	성공시 1, 실패시 0 반환
	*/
	int Modify();

	/**
	*	@brief	Infochange 클래스 정보 수정시 메뉴 출력함
	*	@pre	.
	*	@post	수정 메뉴 출력
	*/
	void DisplayMenu();

	/**
	*	@brief	Infochange 클래스 정보 수정시 명령 입력 받음
	*	@pre	.
	*	@post	사용자로부터 명령 입력
	*	@return	사용자로부터 입력받은 명령
	*/
	int GetCommand();

	/**
	*	@brief	이름을 기준으로 두 아이템 비교하는 오퍼레이터
	*/
	bool operator>(ConferenceType item);

	/**
	*	@brief	이름을 기준으로 두 아이템 비교하는 오퍼레이터
	*/
	bool operator<(ConferenceType item);

	/**
	*	@brief	이름을 기준으로 두 아이템 비교하는 오퍼레이터
	*/
	bool operator==(ConferenceType item);

	//ConferenceType& operator = (const ConferenceType& c);

	///**
	//*	@brief	논문 리스트에서 키워드가 포함된 논문 찾아 리스트로 반환
	//*	@pre	논문 리스트 초기화
	//*	@post	.
	//*	@parm word	찾을 단어
	//@	@return	키워드가 포함된 논문들의 리스트
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
	string m_hName;		///< 학술대회명
	string m_hDate;		///< 시작년월일(YYYY.MM.DD)
	int m_hTimes;		///< 개최횟수
	string m_hOrgan;	///< 개최기관명
	string m_hSimple;	///< 학술대회 약자
	string m_hPlace;	///< 학술대회 개최장소
	string m_hDateTime;		///< 학술대회 개최일시
	string m_hISBN;		///< ISBN
	LinkedListType <SessionType> * SessionList;	///< 세션 리스트
};

#endif	// _CONFERENCE_TYPE_H
