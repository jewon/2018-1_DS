#ifndef _SESSION_TYPE_H
#define _SESSION_TYPE_H

#include <iostream>
#include <string>
using namespace std;

#include"AVL.h"
#include"InfoChange.h"
#include"AuthorType.h"

/**
*	Paper타입 클래스
*/
class PaperType
{
public:
	/**
	*	디폴트 생성자
	*/
	PaperType()
	{
		AuthorList = NULL;
	}

	/**
	*	소멸자
	*/
	~PaperType() 
	{
		AuthorList = NULL;
	}

	/**
	*	@brief	포인터 멤버변수에 새로운 Author리스트 할당
	*	@pre	ConferencTyepe 초기화
	*	@post	AuthorList에 새 Paper 리스트 할당
	*/
	BinarySearchTree<AuthorType> * MakeAuthorList()
	{
		AuthorList = new BinarySearchTree<AuthorType>;
		return AuthorList;
	}

	/**
	*	@brief	포인터 멤버변수에 할당된 Author 리스트 해제
	*	@pre	AuthorList가 할당됨
	*	@post	AuthorList가 해제됨
	*/
	void DeleteAuthorList()
	{
		if(AuthorList != NULL)
			delete AuthorList;
		AuthorList = NULL;
	}

	/**
	*	@brief	스스로의 추상화된 타입이름을 알려줌
	*	@pre	.
	*	@post	.
	*	@return	추상화된 타입이름
	*/
	string WhatType()
	{
		return "Paper";
	}

	/**
	*	@brief	스스로가 포함하는 추상화된 정보명을 알려줌
	*	@pre	.
	*	@post	.
	*	@return	추상화된 정보 명을 탭으로 구분해 나열한 스트링
	*/
	string WhatInclude()
	{
		return "이름\tAuthor리스트";
	}

	/**
	*	@brief	Paper명 반환
	*	@pre	Paper명 초기화
	*	@post	.
	*	@return	Paper명
	*/
	string GetName()
	{
		return m_sName;
	}

	/**
	*	@brief	Author 리스트 반환
	*	@pre	Author 리스트 초기화
	*	@post	.
	*	@return	Author 리스트
	*/
	BinarySearchTree <AuthorType> * GetAuthorList()
	{
		return AuthorList;
	}
	
	/**
	*	@brief	Paper명 입력
	*	@pre	.
	*	@post	Paper명 입력됨
	*	@param	inName	입력할 Paper명
	*/
	void SetName(string inName)
	{
		m_sName = inName;
	}

	/**
	*	@brief	Author리스트 입력
	*	@pre	.
	*	@post	Author리스트 입력됨
	*	@param	inAuthorList	입력할 Author리스트
	*/
	void SetAuthorList(BinarySearchTree <AuthorType> * inAuthorList)
	{
		if(AuthorList != NULL)
			delete AuthorList;
		AuthorList = inAuthorList;
	}

	/**
	*	@brief	사용자로부터 Paper이름 입력받음
	*	@pre	.
	*	@post	Paper이름이 입력됨
	*/
	void SetNameFromKB();

	/**
	*	@brief	사용자로부터 page 입력받음
	*	@pre	.
	*	@post	page 입력됨
	*/
	void SetPagesFromKB();

	/**
	*	@brief	사용자로부터 Author 리스트 입력받을 동작 실행
	*	@pre	.
	*	@post	Author 리스트 입력 함수 실행
	*/
	void SetAuthorListFromKB();

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
	bool operator>(PaperType item);

	/**
	*	@brief	이름을 기준으로 두 아이템 비교하는 오퍼레이터
	*/
	bool operator<(PaperType item);

	/**
	*	@brief	이름을 기준으로 두 아이템 비교하는 오퍼레이터
	*/
	bool operator==(PaperType item);

	/**
	*	@brief	대입 연산자 오버로딩(AuthorList포인터를 대입하지않고 NULL로 줌)
	*/
	PaperType & PaperType::operator=(const PaperType & c);

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
		if (AuthorList != NULL)
			cout << "\tPapers : " << AuthorList->GetLength() << endl;
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
	*	@brief	Paper 및 내부 구조 출력
	*	@pre	.
	*	@post	내부 구조 출력
	*/
	//void DoDisplayStructure()
	//{
	//	cout << "  ├  " << m_sName << endl;
	//	if (AuthorList != NULL)
	//		AuthorList->DisplayAllStructure(2);
	//	else
	//		cout << "    ├  (Empty List)" << endl;
	//}

protected:
	string m_sName;		///< Paper이름
	string m_sPage;		///< 논문집 Page
	BinarySearchTree <AuthorType> * AuthorList;	///< 저자 리스트
};

#endif // _SESSION_TYPE_H
