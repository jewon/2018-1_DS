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
	MoreFeatures(BinarySearchTree<ConferenceType> * in_List, BinarySearchTree<PaperType> * pi) : i_List(in_List), i_Command(0), Paper_Index(pi) {}

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
	*	@brief	�м���ȸ ����� ������ ����Ѵ�.
	*	@pre	.
	*	@post	�м���ȸ ����� ������ ��µ�.
	*/
	void DisplayConferenceBrief();

	/**
	*	@brief	�� ����� ������ ����Ѵ�.
	*	@pre	.
	*	@post	�� ����� ������ ��µ�.
	*/
	void DisplayAllPaper();
	
	/**
	*	@brief	���� Ű����� �˻��Ѵ�.
	*	@pre	.
	*	@post	�˻��� Ű���尡 �����Ǿ� Ű���� ���Ե� �� ���.
	*/
	void SearchPaperByString();

	/**
	*	@brief	�м���ȸ�� Ű����� �˻��Ѵ�.
	*	@pre	.
	*	@post	�˻��� Ű���尡 �����Ǿ� Ű���� ���Ե� ��ȸ ���.
	*/
	void SearchConferenceByString();

	///**
	//*	@brief	�м���ȸ�� Ű����� �˻��Ѵ�.
	//*	@pre	.
	//*	@post	�˻��� Ű���尡 �����Ǿ� Ű���� ���Ե� ��ȸ ���.
	//*/
	//void SearchAuthorByString();

	///**
	//*	@brief	���� ����� ������ ����Ѵ�.
	//*	@pre	.
	//*	@post	���� ����� ������ ��µ�.
	//*/
	//void DisplayAllAuthor();

	/**
	*	@brief	���̸��� �м���ȸ �̸����� Ű����� �˻��Ѵ�.
	*	@pre	.
	*	@post	�˻��� Ű���尡 �����Ǿ� Ű���� ���Ե� �׸� ���.
	*/
	void SearchAll();
	
protected:
	int i_Command;	///< ����ڷκ��� �Է¹��� ��ɹ�ȣ
	BinarySearchTree<ConferenceType> * i_List;	///< Ž���� ������ ��� ����Ʈ
	BinarySearchTree<PaperType> * Paper_Index;	///< �� ����Ʈ
};

#endif _MORE_FEATURES_H