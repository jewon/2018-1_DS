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
	*	������ : i_List�� ����Ʈ ����
	*/
	MoreFeatures(LinkedListType<ConferenceType>& in_List) : i_List(in_List), i_Command(0) {}

	/**
	*	@brief	�߰� ����� �����Ѵ�. (����� �޴�)
	*	@pre	.
	*	@post	.
	*/
	void Run();

	/**
	*	@brief	�߰� ��� ��� ����� ȭ�鿡 ����ϰ� ����� �Է¹޴´�.
	*	@pre	.
	*	@post	.
	*	@return	�Է��� ���
	*/
	int MoreFeaturesGetcommand();

	/**
	*	@brief	�� �˻��� �����Ѵ�.
	*	@pre	.
	*	@post	�� �˻� ����� �ֿܼ� ��µȴ�.
	*/
	void PaperSearch();

	/**
	*	@brief	�м���ȸ ����� ������ ����Ѵ�.
	*	@pre	.
	*	@post	�м���ȸ ����� ������ ��µ�.
	*/
	void DisplayConferenceBrief();
	
protected:
	int i_Command;
	const LinkedListType<ConferenceType> & i_List;
};

#endif _MORE_FEATURES_H