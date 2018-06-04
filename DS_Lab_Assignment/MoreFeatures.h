#ifndef _MORE_FEATURES_H
#define _MORE_FEATURES_H

#include<iostream>
#include<string>
using namespace std;

#include"AVL.h"
#include"ConferenceType.h"

/**
*	사용자 기능 클래스
*/
class MoreFeatures
{
public:
	/**
	*	생성자 : i_List에 리스트 받음
	*/
	MoreFeatures(BinarySearchTree<ConferenceType> * in_List, BinarySearchTree<PaperType> * pi) : i_List(in_List), i_Command(0), Paper_Index(pi) {}

	/**
	*	@brief	추가 기능을 실행한다. (사용자 메뉴)
	*	@pre	.
	*	@post	.
	*/
	void Run();

	/**
	*	@brief	추가 기능 명령 목록을 화면에 출력하고 명령을 입력받는다.
	*	@pre	.
	*	@post	.
	*	@return	입력한 명령
	*/
	int MoreFeaturesGetcommand();

	/**
	*	@brief	학술대회 목록을 간략히 출력한다.
	*	@pre	.
	*	@post	학술대회 목록이 간단히 출력됨.
	*/
	void DisplayConferenceBrief();

	/**
	*	@brief	논문 목록을 간략히 출력한다.
	*	@pre	.
	*	@post	논문 목록이 간단히 출력됨.
	*/
	void DisplayAllPaper();
	
	/**
	*	@brief	논문을 키워드로 검색한다.
	*	@pre	.
	*	@post	검색된 키워드가 강조되어 키워드 포함된 논문 출력.
	*/
	void SearchPaperByString();

	/**
	*	@brief	학술대회을 키워드로 검색한다.
	*	@pre	.
	*	@post	검색된 키워드가 강조되어 키워드 포함된 대회 출력.
	*/
	void SearchConferenceByString();

	///**
	//*	@brief	학술대회을 키워드로 검색한다.
	//*	@pre	.
	//*	@post	검색된 키워드가 강조되어 키워드 포함된 대회 출력.
	//*/
	//void SearchAuthorByString();

	///**
	//*	@brief	저자 목록을 간략히 출력한다.
	//*	@pre	.
	//*	@post	저자 목록이 간단히 출력됨.
	//*/
	//void DisplayAllAuthor();

	/**
	*	@brief	논문이름과 학술대회 이름을을 키워드로 검색한다.
	*	@pre	.
	*	@post	검색된 키워드가 강조되어 키워드 포함된 항목 출력.
	*/
	void SearchAll();
	
protected:
	int i_Command;	///< 사용자로부터 입력받은 명령번호
	BinarySearchTree<ConferenceType> * i_List;	///< 탐색을 실행할 대상 리스트
	BinarySearchTree<PaperType> * Paper_Index;	///< 논문 리스트
};

#endif _MORE_FEATURES_H