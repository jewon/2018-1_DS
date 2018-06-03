#ifndef _ADMIN_H
#define _ADMIN_H

#include <iostream>
#include <string>
using namespace std;

#include "LinkedListType.h"
#include "ConferenceType.h"

/**
*	정보 변경을 위한 관리자 기능
*/
class Admin
{
public:
	/**
	*	기본 생성자
	*/
	Admin() 
	{
		m_Command = 0;
		Root_List = NULL;
	}

	/**
	*	소멸자
	*/
	~Admin() 
	{
		Root_List = NULL;
	}

	/**
	*	@brief	관리자 기능 실행
	*	@pre	기능 시작
	*	@post	기능 끝
	*/
	void Run(LinkedListType<ConferenceType> * inList);

	/**
	*	@brief	명령 목록을 화면에 출력하고 명령을 입력받는다
	*	@pre	.
	*	@post	.
	*	@return	입력한 명령
	*/
	int GetCommand();

	/**
	*	@brief	세션리스트의 변경을 수행한다
	*	@pre	.
	*	@post	.
	*	@return	.
	*/
	LinkedListType<SessionType> * GetChangeSessionList();

	/**
	*	@brief	논문리스트의 변경을 수행한다.
	*	@pre	.
	*	@post	.
	*	@return	.
	*/
	LinkedListType<PaperType> * GetChangePaperList();

	/**
	*	@brief	현재 리스트에 포함된 모든 데이터를 구조화해 출력한다.
	*	@pre	.
	*	@post	출력됨
	*/
//	void PrintALlStructure();

protected:
	int m_Command;		///< 사용자 명령
	LinkedListType<ConferenceType> * Root_List;		///< 컨퍼런스 리스트 포인터
};

#endif _ADMIN_H