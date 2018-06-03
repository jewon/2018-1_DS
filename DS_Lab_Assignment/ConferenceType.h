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
		PaperList = NULL;
	} 

	/**
	*	소멸자
	*/
	~ConferenceType()                       
	{
		PaperList = NULL;
	}

	/**
	*	@brief	포인터 멤버변수에 새로운 Paper리스트 할당
	*	@pre	ConferencTyepe 초기화
	*	@post	PaperList에 새 Paper 리스트 할당
	*/
	BinarySearchTree<PaperType> * MakePaperList()
	{
		if(PaperList == NULL)
			PaperList = new BinarySearchTree<PaperType>;
		return PaperList;
	}

	/**
	*	@brief	포인터 멤버변수에 할당된 Paper 리스트 해제
	*	@pre	PaperList가 할당됨
	*	@post	PaperList가 해제됨
	*/
	void DeletePaperList()
	{
		delete PaperList;
		PaperList = NULL;
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
		return "학술대회명\t시작년월일\tPaper리스트";
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
	*	@brief	Paper 리스트 반환
	*	@pre	Paper 리스트 초기화
	*	@post	.
	*	@return	Paper 리스트(LinkedList)
	*/
	BinarySearchTree <PaperType> * GetPaperList()
	{
		return PaperList;
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
	*	@brief	Paper 리스트 입력
	*	@pre	.
	*	@post	Paper 리스트 입력됨
	*	@param	inPaperList	입력할 Paper 리스트(LinkedList)
	*/
	void SetPaperList(BinarySearchTree <PaperType> * inPaperList)
	{
		if(PaperList!=NULL)
			delete PaperList;
		PaperList = inPaperList;
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
	*	@param	inPaperList	입력할 Paper리스트
	*/
	void SetRecord(string inName, string inDate, int inTimes, string inOrgan, string inSimple, string inPlace, string inDateTime, string inISBN, BinarySearchTree <PaperType> * inPaperList)
	{
		SetName(inName);
		SetDate(inDate);
		SetPaperList(inPaperList);
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
	*	@brief	레코드 출력
	*	@pre	레코드 전체 입력됨
	*	@post	레코드 전체 출력
	*/
	void DisplayRecordOnScreen()
	{
		DisplayNameOnScreen();
		DisplayDateOnScreen();
		if (PaperList != NULL)
			cout << "\tSessions : " << PaperList->GetLength() << endl;
	};

	/**
	*	@brief	레코드 간략하게 출력 ex. 학술대회명(개최년도)
	*	@pre	레코드 전체 입력됨
	*	@post	레코드 전체 간략히 출력
	*/
	void DisplayBriefOnScreen()
	{
		cout << m_hName << "(" << m_hDate.substr(0, 4) << ")" << endl;
	};

	/**
	*	@brief	사용자로부터 이름 입력받음
	*	@pre	.
	*	@post	이름이 입력됨
	*/
	void SetNameFromKB();

	/**
	*	@brief	사용자로부터 개최년월일 입력받음
	*	@pre	.
	*	@post	개최년월일 입력됨
	*/
	void SetDateFromKB();

	/**
	*	@brief	사용자로부터 Paper 리스트 입력받음
	*	@pre	.
	*	@post	BinarySearchTree의 Paper 리스트 입력 함수 실행
	*/
	void SetPaperListFromKB();

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
	*	@brief	Paper 및 내부 구조 출0력
	*	@pre	.
	*	@post	내부 구조 출력
	*/
	//void DoDisplayStructure()
	//{
	//	cout << "├  " << m_hName << endl;
	//	if (PaperList != NULL)
	//		PaperList->DoDisplayAllStructure();
	//	else
	//		cout << "  ├  (Empty List)" << endl;
	//}

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

	/**
	*	@brief	대입연산자 오버로딩(PaperList포인터를 복사하지않고 NULL로 줌)
	*/
	ConferenceType& operator=(const ConferenceType& c);

protected:
	string m_hName;		///< 학술대회명
	string m_hDate;		///< 시작년월일(YYYY.MM.DD)
	BinarySearchTree <PaperType> * PaperList;	///< Paper 리스트 포인터
};

#endif	// _CONFERENCE_TYPE_H
