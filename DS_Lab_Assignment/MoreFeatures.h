#ifndef _MORE_FEATURES_H
#define _MORE_FEATURES_H

#include<iostream>
#include<string>
using namespace std;

#include"LinkedListType.h"
#include"ConferenceType.h"

class MoreFeatures
{
public:
	/**
	*	생성자 : i_List에 리스트 받음
	*/
	MoreFeatures(LinkedListType<ConferenceType>& in_List) : i_List(in_List), i_Command(0) {}

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
	*	@brief	논문 검색을 수행한다.
	*	@pre	.
	*	@post	논문 검색 결과가 콘솔에 출력된다.
	*/
	void PaperSearch();

	/**
	*	@brief	학술대회 목록을 간략히 출력한다.
	*	@pre	.
	*	@post	학술대회 목록이 간단히 출력됨.
	*/
	void DisplayConferenceBrief();
	
protected:
	int i_Command;
	const LinkedListType<ConferenceType> & i_List;
};

#endif _MORE_FEATURES_H