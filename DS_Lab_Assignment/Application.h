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
		f_Command = 0;
	}

	/**
	*	소멸자
	*/
	~Application() {}

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

	int MoreFeaturesGetcommand();

	void MoreFeatures();

	/**
	*	@brief	새로운 레코드를 추가함
	*	@pre	리스트가 초기화가 되어 있어야 한다
	*	@post	새로운 레코드가 리스트에 추가된다
	*	@return	리스트에 추가가 성공적으로 되었으면 1, 실패하면 0을 리턴
	*/
	int AddConference();

	/**
	*	@brief	화면에 모든 학술대회의 학술정보 요약정보를 출력하고 사용자로부터 입력받아 자세한 정보 출력
	*	@pre	.
	*	@post	.
	*/
	void GetConferenceInfo();

	/**
	*	@brief	화면에 모든 학술대회의 학술정보 요약정보를 약자로 출력
	*	@pre	.
	*	@post	.
	*/
	void DisplayAllConferencesSimple();

	/**
	*	@brief	화면에 모든 학술대회의 학술정보 요약정보를 출력
	*	@pre	.
	*	@post	.
	*/
	void DisplayAllConferences();

	/**
	*	@brief	리스트 데이터를 불러올 파일 열기
	*	@pre	해당 파일명이 존재할 경우
	*	@post	읽어 올 파일을 연다
	*	@param	fileName	읽어 올 파일 네임
	*	@return	파일을 성공적으로 열었으면 1, 실패시 0을 리턴
	*/
	int OpenInFile(char *fileName);

	/**
	*	@brief	리스트를 저장할 파일 열기
	*	@pre	리스트 초기화
	*	@post	리스트가 저장될 파일 지정
	*	@param	fileName	리스트 저장할 파일 이름
	*	@return	파일을 성공적으로 열었으면 1, 실패시 0을 리턴
	*/
	int OpenOutFile(char *fileName);

	/**
	*	@brief	파일을 열어 리스트로 데이터를 불러옴
	*	@pre	해당 파일이 열려 있지 않은 상태여야 함
	*	@post	리스트가 파일로부터 모든 레코드를 받음
	*	@return	레코드 불러오기에 성공하면 1, 실패시 0을 리턴
	*/
	int ReadDataFromFile();

	/**
	*	@brief	파일을 열어 리스트에서 데이터를 모두 저장함
	*	@pre	해당 파일이 열려 있지 않은 상태여야 함
	*	@post	리스트의 모든 레코드가 파일에 저장됨
	*	@return	저장에 성공하면 1, 실패시 0을 리턴
	*/
	int WriteDataToFile();

	/**
	*	@brief  학술대회명를 입력받아 해당 학술대회명를 가진 레코드를 삭제함
	*	@pre	해당 학술대회명를 가진 레코드가 유일하게 리스트에 존재
	*	@post	해당 학술대회명를 가진 레코드가 삭제되고, 맨 마지막에 있는 레코드가 삭제된 레코드 자리로 옮겨짐
	*	@return	레코드 삭제 성공시 1, 실패시 0을 리턴
	*/
	int DeleteConference();

	/**
	*	@brief	레코드를 입력받아 입력받은 레코드의 학술대회명를 가진 리스트의 레코드를 수정
	*	@pre	해당 학술대회명를 가진 레코드가 유일하게 리스트에 존재
	*	@post	해당 학술대회명를 가진 레코드의 내용이 입력받은 레코드의 내용으로 변경됨
	*	@return	변경 성공시 1, 실패시 0을 리턴
	*/
	int ReplaceConference();

	/**
	*	@brief	학술대회명를 입력받아 해당 학술대회명를 가진 레코드를 리스트에서 찾아 화면에 출력
	*	@pre	해당 학술대회명를 가진 레코드가 유일하게 리스트에 존재
	*	@post	해당 학술대회명를 가진 레코드가 화면에 출력됨
	*	@return	출력 성공시 1, 실패시 0을 리턴
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