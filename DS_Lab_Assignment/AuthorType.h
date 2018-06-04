#ifndef _PAPER_TYPE_H
#define _PAPER_TYPE_H

#include<iostream>
#include<string>
using namespace std;

/**
*	페이퍼타입
*/
class AuthorType
{
public:
	/**
	*	디폴트 생성자
	*/
	AuthorType()
	{
		m_pName = "noName";
	}


	/**
	*	디폴트 소멸자
	*/
	~AuthorType() 
	{}

	/**
	*	@brief	스스로의 추상화된 타입이름을 알려줌
	*	@pre	.
	*	@post	.
	*	@return	추상화된 타입이름
	*/
	string WhatType()
	{
		return "Author";
	}

	/**
	*	@brief	스스로가 포함하는 추상화된 정보명을 알려줌
	*	@pre	.
	*	@post	.
	*	@return	추상화된 정보 명을 탭으로 구분해 나열한 스트링
	*/
	string WhatInclude()
	{
		return "이름\t저자\t페이지";
	}

	/**
	*	@brief	Author명 반환
	*	@pre	Author명 초기화
	*	@post	.
	*	@return	Author명
	*/
	string GetName()
	{
		return m_pName;
	}

	/**
	*	@brief	Author명 입력
	*	@pre	.
	*	@post	Author명 입력됨
	*	@param	inName	입력할 Author명
	*/
	void SetName(string inName)
	{
		m_pName = inName;
	}

	/**
	*	@brief	Author 레코드 입력
	*	@pre	.
	*	@post	Author 레코드가 입력됨
	*	@param	inName	입력할 이름
	*	@param	inAuthor	입력할 저자
	*	@param	inPages		입력할 페이지 수
	*/
	void SetRecord(string inName, string inAuthor, int inPages)
	{
		SetName(inName);
	}

	/**
	*	@brief	이름 출력
	*	@pre	이름 존재
	*	@post	이름 출력
	*/
	void DisplayNameOnScreen()
	{
		cout << "\tName : " << m_pName << endl;
	};

	/**
	*	@brief	레코드 출력
	*	@pre	레코드 전체 입력됨
	*	@post	레코드 전체 출력
	*/
	void DisplayRecordOnScreen()
	{
		DisplayNameOnScreen();
	};

	/**
	*	@brief	데이터를 1줄 이내로 간략히 출력
	*	@pre	.
	*	@post	데이터 출력됨
	*/
	void DisplayBriefOnScreen()
	{
		cout << "\t" << m_pName << endl;
	}

	/**
	*	@brief	사용자로부터 이름 입력받음
	*	@pre	.
	*	@post	이름이 입력됨
	*/
	void SetNameFromKB();

	/**
	*	@brief	사용자로부터 레코드 전체 입력받음
	*	@pre	.
	*	@post	레코드가 입력됨
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
	bool operator>(AuthorType item);

	/**
	*	@brief	이름을 기준으로 두 아이템 비교하는 오퍼레이터
	*/
	bool operator<(AuthorType item);

	/**
	*	@brief	이름을 기준으로 두 아이템 비교하는 오퍼레이터
	*/
	bool operator==(AuthorType item);

	bool NameFind(string f) { return  false; }
protected:
	string m_pName;		///< Author제목
};
#endif // _PAPER_TYPE_H