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
*	�м���ȸ ���� ������ ���� ���ø����̼� Ŭ����
*/
class Application
{

public:
	/**
	*	�⺻ ������
	*/
	Application()
	{
		m_Command = 0;
		PaperIndex = NULL;
		//AuthorIndex = NULL;
	}

	/**
	*	�Ҹ���
	*/
	~Application() 
	{
		PaperIndex = NULL;
		//AuthorIndex = NULL;
	}

	/**
	*	@brief	���α׷� ����
	*	@pre	���α׷� ����
	*	@post	���α׷� ��
	*/
	void Run();

	/**
	*	@brief	��� ����� ȭ�鿡 ����ϰ� ����� �Է¹޴´�
	*	@pre	.
	*	@post	.
	*	@return	�Է��� ���
	*/
	int GetCommand();

	/**
	*	@brief	�߰� ��� Ŭ������ ����� �����Ѵ�.
	*	@pre	.
	*	@post	.
	*	@return	.
	*/
	void RunMoreFeatures();

	/**
	*	@brief	������ ����� �����Ѵ�.
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