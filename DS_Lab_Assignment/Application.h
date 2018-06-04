#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "AVL.h"
#include "ConferenceType.h"
#include "MoreFeatures.h"
#include "Admin.h"

#define FILENAMESIZE 1024

/**
*	학술대회 정보 관리를 위한 어플리케이션 클래스
*/
class Application
{

public:
	/**
	*	기본 생성자
	*/
	Application()
	{
		m_Command = 0;
		PaperIndex = NULL;
		//AuthorIndex = NULL;
	}

	/**
	*	소멸자
	*/
	~Application() 
	{
		PaperIndex = NULL;
		//AuthorIndex = NULL;
	}

	/**
	*	@brief	프로그램 실행
	*	@pre	프로그램 시작
	*	@post	프로그램 끝
	*/
	void Run();

	/**
	*	@brief	명령 목록을 화면에 출력하고 명령을 입력받는다
	*	@pre	.
	*	@post	.
	*	@return	입력한 명령
	*/
	int GetCommand();

	/**
	*	@brief	추가 기능 클래스의 기능을 실행한다.
	*	@pre	.
	*	@post	.
	*	@return	.
	*/
	void RunMoreFeatures();

	/**
	*	@brief	관리자 기능을 실행한다.
	*	@pre	.
	*	@post	.
	*	@return	.
	*/
	void RunAdmin();

private:
	BinarySearchTree<ConferenceType> m_List;		///< item list.
	BinarySearchTree<PaperType> * PaperIndex;
	int m_Command;			///< current command number.
};

#endif	// _APPLICATION_H