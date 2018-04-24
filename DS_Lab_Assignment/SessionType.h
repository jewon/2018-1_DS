#ifndef _SESSION_TYPE_H
#define _SESSION_TYPE_H

#include <iostream>
#include <string>
using namespace std;

#include"LinkedListType.h"
#include"InfoChange.h"
#include"PaperType.h"

/**
*	세션타입 클래스
*/
class SessionType
{
public:
	/**
	*	디폴트 생성자
	*/
	SessionType()
	{
		PaperList = NULL;
	}

	/**
	*	소멸자
	*/
	~SessionType() 
	{
		PaperList = NULL;
	}

	/**
	*	@brief	포인터 멤버변수에 새로운 논문리스트 할당
	*	@pre	ConferencTyepe 초기화
	*	@post	PaperList에 새 세션 리스트 할당
	*/
	LinkedListType<PaperType> * MakePaperList()
	{
		PaperList = new LinkedListType<PaperType>;
		return PaperList;
	}

	/**
	*	@brief	포인터 멤버변수에 할당된 논문 리스트 해제
	*	@pre	PaperList가 할당됨
	*	@post	PaperList가 해제됨
	*/
	void DeletePaperList()
	{
		if(PaperList != NULL)
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
		return "세션";
	}

	/**
	*	@brief	스스로가 포함하는 추상화된 정보명을 알려줌
	*	@pre	.
	*	@post	.
	*	@return	추상화된 정보 명을 탭으로 구분해 나열한 스트링
	*/
	string WhatInclude()
	{
		return "이름\t논문리스트";
	}

	/**
	*	@brief	세션명 반환
	*	@pre	세션명 초기화
	*	@post	.
	*	@return	세션명
	*/
	string GetName()
	{
		return m_sName;
	}

	/**
	*	@brief	논문 리스트 반환
	*	@pre	논문 리스트 초기화
	*	@post	.
	*	@return	논문 리스트
	*/
	LinkedListType <PaperType> * GetPaperList()
	{
		return PaperList;
	}
	
	/**
	*	@brief	세션명 입력
	*	@pre	.
	*	@post	세션명 입력됨
	*	@param	inName	입력할 세션명
	*/
	void SetName(string inName)
	{
		m_sName = inName;
	}

	/**
	*	@brief	논문리스트 입력
	*	@pre	.
	*	@post	논문리스트 입력됨
	*	@param	inPaperList	입력할 논문리스트
	*/
	void SetPaperList(LinkedListType <PaperType> * inPaperList)
	{
		if(PaperList != NULL)
			delete PaperList;
		PaperList = inPaperList;
	}

	/**
	*	@brief	사용자로부터 세션이름 입력받음
	*	@pre	.
	*	@post	세션이름이 입력됨
	*/
	void SetNameFromKB();

	/**
	*	@brief	사용자로부터 논문 리스트 입력받을 동작 실행
	*	@pre	.
	*	@post	논문 리스트 입력 함수 실행
	*/
	void SetPaperListFromKB();

	/**
	*	@brief	사용자로부터 레코드 전체 입력받음
	*	@pre	.
	*	@post	레코드 전체 입력
	*/
	void SetRecordFromKB();

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
	bool operator>(SessionType item);

	/**
	*	@brief	이름을 기준으로 두 아이템 비교하는 오퍼레이터
	*/
	bool operator<(SessionType item);

	/**
	*	@brief	이름을 기준으로 두 아이템 비교하는 오퍼레이터
	*/
	bool operator==(SessionType item);

	/**
	*	@brief	대입 연산자 오버로딩(PaperList포인터를 대입하지않고 NULL로 줌)
	*/
	SessionType & SessionType::operator=(const SessionType & c);

	/**
	*	@brief	이름 출력
	*	@pre	이름 존재
	*	@post	이름 출력
	*/
	void DisplayNameOnScreen()
	{
		cout << "\tName : " << m_sName << endl;
	};

	/**
	*	@brief	레코드 전체 출력
	*	@pre	.
	*	@post	레코드 전체 출력
	*/
	void DisplayRecordOnScreen()
	{
		DisplayNameOnScreen();
		if (PaperList != NULL)
			cout << "\tPapers : " << PaperList->GetLength() << endl;
	}

	/**
	*	@brief	레코드 전체 간략히 출력
	*	@pre	.
	*	@post	레코드 전체 간략히 출력
	*/
	void DisplayBriefOnScreen()
	{
		DisplayNameOnScreen();
	}

	/**
	*	@brief	세션 및 내부 구조 출력
	*	@pre	.
	*	@post	내부 구조 출력
	*/
	void DoDisplayStructure()
	{
		cout << "  ├  " << m_sName << endl;
		if (PaperList != NULL)
			PaperList->DisplayAllStructure(2);
		else
			cout << "    ├  (Empty List)" << endl;
	}

protected:
	string m_sName;		///< 세션이름
	LinkedListType <PaperType> * PaperList;	///< 세션에 발표된 논문 리스트
};

#endif // _SESSION_TYPE_H
