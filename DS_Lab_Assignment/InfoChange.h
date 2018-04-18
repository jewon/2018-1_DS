#ifndef _INFO_CHANGE_H
#define _INFO_CHANGE_H

#include<iostream>
#include<string>
using namespace std;

#include"LinkedListType.h"

/**
*	LinkedListType을 받아 사용자가 변경할 수 있게 함
*/
template <typename T>
class InfoChange
{
public :
	/**
	*	기본 생성자
	*/
	InfoChange() 
	{
		i_List = NULL;
	}

	/**
	*	각 타입 리스트의 정보 변경을 위한 생성자
	*/
	/*InfoChange(LinkedListType<T> &item)
	{
		i_List = item;
		i_Command = 0;
	}*/

	/**
	*	소멸자
	*/
	~InfoChange() 
	{
		i_List = NULL;
	}

	/**
	*	@brief	정보변경 실행
	*	@pre	정보변경 시작
	*	@post	정보변경 끝
	*/
	void Run(LinkedListType<T> * inList);

	/**
	*	@brief	명령 목록을 화면에 출력하고 명령을 입력받는다
	*	@pre	.
	*	@post	.
	*	@return	입력한 명령
	*/
	int GetCommand();

	/**
	*	@brief	새로운 레코드를 추가함
	*	@pre	리스트가 초기화가 되어 있어야 한다
	*	@post	새로운 레코드가 리스트에 추가된다
	*	@return	리스트에 추가가 성공적으로 되었으면 1, 실패하면 0을 리턴
	*/
	int Add();

	/**
	*	@brief  레코드 이름을 입력해 해당레코드를 삭제함
	*	@pre	해당 이름(Primary Key) 가진 레코드가 유일하게 리스트에 존재
	*	@post	해당 이름(Primary Key) 레코드가 삭제
	*	@return	레코드 삭제 성공시 1, 실패시 0을 리턴
	*/
	int Delete();

	/**
	*	@brief  레코드를 선택해 바꿈
	*	@pre	해당 이름(Primary Key) 가진 레코드가 유일하게 리스트에 존재
	*	@post	해당 이름(Primary Key) 레코드를 사용자 명령에 의해 변경
	*	@return	레코드 삭제 성공시 1, 실패시 0을 리턴
	*/
	int Change();

private:
	LinkedListType <T> * i_List;
	int i_Command;
};

// 정보 수정 실행
template<typename T>
void InfoChange<T>::Run(LinkedListType<T> * inList)
{
	i_List = inList;
	while (1)
	{
		i_Command = GetCommand();

		switch (i_Command)
		{
		case 1:
			i_List->DisplayAll();
			break;
		case 2:
			this->Add();
			break;
		case 3:
			this->Delete();
			break;
		case 4:
			this->Change();
			break;
		case 0:
			return;
			break;
		default:
			cout << "\t 잘못된 입력입니다\n";
			break;
		}
	}
	return;
}

// 사용자로부터 명령 입력받는 인터페이스
template<typename T>
int InfoChange<T>::GetCommand()
{
	string tName = i_List->GetTName();
	int command;
	cout << "\t" << tName << " 리스트 변경" << endl;

	cout << "\t   1 : " << tName << " 리스트 전체 보기" << endl;
	cout << "\t   2 : " << tName << " 추가" << endl;
	cout << "\t   3 : " << tName << " 삭제" << endl;
	cout << "\t   4 : " << tName << " 수정(하위리스트 포함)" << endl;
	cout << "\t   0 : " << "저장 하고 나가기" << endl;

	cout << "\t   입력 ->";
	cin >> command;
	cout << endl;

	return command;
}

// 노드 추가
template<typename T>
int InfoChange<T>::Add()
{
	T item;
	item.SetRecordFromKB();

	if (!i_List->Add(item))
	{
		cout << "\t-----Error Massage-----\n\t레코드를 정상적으로 추가하지 못했습니다.\n\t-----Error Massage-----\n" << endl;
		return 0;
	}
	i_List->DisplayAll();

	return 1;
}

// 노드 삭제
template<typename T>
int InfoChange<T>::Delete()
{
	T item;
	item.SetNameFromKB();

	if (!i_List->Delete(item))
	{
		cout << "\t-----Error Massage-----\n\t입력하신 이름을 가진 레코드가 없습니다.\n\t-----Error Massage-----\n";
		return 0;
	}
	i_List->DisplayAll();

	return 1;
}

// 노드 수정
template<typename T>
int InfoChange<T>::Change()
{
	i_List->DisplayAll();
	T item;
	cout << "\t수정할 레코드 이름을 입력하세요" << endl;
	item.SetNameFromKB();

	if(i_List->Get(item)) 
	{ // 같은 이름의 item을 찾아
		item.DisplayRecordOnScreen(); // 화면에 출력
		item.Modify(); // item 수정
		if (!i_List->Replace(item))
		{	// 대체 실패시
			cout << "\t-----Error Massage-----\n\t수정이 잘못되었습니다. 이전 상태로 저장됩니다.\n\t-----Error Massage-----\n";
			return 0;
		}
		else
		{
			
			return 1;
		}
	}
	else
	{
		cout << "\t-----Error Massage-----\n\t입력하신 이름을 가진 레코드가 없습니다.\n\t-----Error Massage-----\n";
	}
}



#endif _INFO_CHANGE_H