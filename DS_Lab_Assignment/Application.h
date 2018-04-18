#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "LinkedListType.h"
#include "ConferenceType.h"
#include "InfoChange.h"

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
		f_Command = 0;
	}

	/**
	*	�Ҹ���
	*/
	~Application() {}

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

	int MoreFeaturesGetcommand();

	void MoreFeatures();

	/**
	*	@brief	���ο� ���ڵ带 �߰���
	*	@pre	����Ʈ�� �ʱ�ȭ�� �Ǿ� �־�� �Ѵ�
	*	@post	���ο� ���ڵ尡 ����Ʈ�� �߰��ȴ�
	*	@return	����Ʈ�� �߰��� ���������� �Ǿ����� 1, �����ϸ� 0�� ����
	*/
	int AddConference();

	/**
	*	@brief	ȭ�鿡 ��� �м���ȸ�� �м����� ��������� ����ϰ� ����ڷκ��� �Է¹޾� �ڼ��� ���� ���
	*	@pre	.
	*	@post	.
	*/
	void GetConferenceInfo();

	/**
	*	@brief	ȭ�鿡 ��� �м���ȸ�� �м����� ��������� ���ڷ� ���
	*	@pre	.
	*	@post	.
	*/
	void DisplayAllConferencesSimple();

	/**
	*	@brief	ȭ�鿡 ��� �м���ȸ�� �м����� ��������� ���
	*	@pre	.
	*	@post	.
	*/
	void DisplayAllConferences();

	/**
	*	@brief	����Ʈ �����͸� �ҷ��� ���� ����
	*	@pre	�ش� ���ϸ��� ������ ���
	*	@post	�о� �� ������ ����
	*	@param	fileName	�о� �� ���� ����
	*	@return	������ ���������� �������� 1, ���н� 0�� ����
	*/
	int OpenInFile(char *fileName);

	/**
	*	@brief	����Ʈ�� ������ ���� ����
	*	@pre	����Ʈ �ʱ�ȭ
	*	@post	����Ʈ�� ����� ���� ����
	*	@param	fileName	����Ʈ ������ ���� �̸�
	*	@return	������ ���������� �������� 1, ���н� 0�� ����
	*/
	int OpenOutFile(char *fileName);

	/**
	*	@brief	������ ���� ����Ʈ�� �����͸� �ҷ���
	*	@pre	�ش� ������ ���� ���� ���� ���¿��� ��
	*	@post	����Ʈ�� ���Ϸκ��� ��� ���ڵ带 ����
	*	@return	���ڵ� �ҷ����⿡ �����ϸ� 1, ���н� 0�� ����
	*/
	int ReadDataFromFile();

	/**
	*	@brief	������ ���� ����Ʈ���� �����͸� ��� ������
	*	@pre	�ش� ������ ���� ���� ���� ���¿��� ��
	*	@post	����Ʈ�� ��� ���ڵ尡 ���Ͽ� �����
	*	@return	���忡 �����ϸ� 1, ���н� 0�� ����
	*/
	int WriteDataToFile();

	/**
	*	@brief  �м���ȸ�� �Է¹޾� �ش� �м���ȸ�� ���� ���ڵ带 ������
	*	@pre	�ش� �м���ȸ�� ���� ���ڵ尡 �����ϰ� ����Ʈ�� ����
	*	@post	�ش� �м���ȸ�� ���� ���ڵ尡 �����ǰ�, �� �������� �ִ� ���ڵ尡 ������ ���ڵ� �ڸ��� �Ű���
	*	@return	���ڵ� ���� ������ 1, ���н� 0�� ����
	*/
	int DeleteConference();

	/**
	*	@brief	���ڵ带 �Է¹޾� �Է¹��� ���ڵ��� �м���ȸ�� ���� ����Ʈ�� ���ڵ带 ����
	*	@pre	�ش� �м���ȸ�� ���� ���ڵ尡 �����ϰ� ����Ʈ�� ����
	*	@post	�ش� �м���ȸ�� ���� ���ڵ��� ������ �Է¹��� ���ڵ��� �������� �����
	*	@return	���� ������ 1, ���н� 0�� ����
	*/
	int ReplaceConference();

	/**
	*	@brief	�м���ȸ�� �Է¹޾� �ش� �м���ȸ�� ���� ���ڵ带 ����Ʈ���� ã�� ȭ�鿡 ���
	*	@pre	�ش� �м���ȸ�� ���� ���ڵ尡 �����ϰ� ����Ʈ�� ����
	*	@post	�ش� �м���ȸ�� ���� ���ڵ尡 ȭ�鿡 ��µ�
	*	@return	��� ������ 1, ���н� 0�� ����
	*/
	int RetrieveByName();

	void PaperSearch();

private:
	ifstream m_InFile;		///< input file descriptor.
	ofstream m_OutFile;		///< output file descriptor.
	LinkedListType<ConferenceType> m_List;		///< item list.
	int m_Command;			///< current command number.
	int f_Command;
};

#endif	// _APPLICATION_H