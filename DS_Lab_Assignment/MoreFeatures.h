#ifndef _MORE_FEATURES_H
#define _MORE_FEATURES_H

#include<iostream>
#include<string>
using namespace std;

#include"AVL.h"
#include"ConferenceType.h"

/**
*	����� ��� Ŭ����
*/
class MoreFeatures
{
public:
	/**
	*	������ : i_List�� ����Ʈ ����
	*/
	MoreFeatures(BinarySearchTree<ConferenceType>& in_List) : i_List(in_List), i_Command(0) {}

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

	///**
	//*	@brief	�м���ȸ ����� ������ ����Ѵ�.
	//*	@pre	.
	//*	@post	�м���ȸ ����� ������ ��µ�.
	//*/
	//void DisplayConferenceBrief();
	
protected:
	int i_Command;	///< ����ڷκ��� �Է¹��� ��ɹ�ȣ
	const BinarySearchTree<ConferenceType> & i_List;	///< Ž���� ������ ��� ����Ʈ
};

#endif _MORE_FEATURES_H