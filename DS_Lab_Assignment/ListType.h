#ifndef _LIST_TYPE_H
#define _LIST_TYPE_H

#include <iostream>
#include <fstream>	
#include <string>
using namespace std;

#define MAXSIZE 10

/**
*	Array기반 Sorted List (학술대회 이름 오름차순)
*	학술대회 정보를 각 배열요소에 저장
*/
template<class T>
class ListType
{
public:
	/**
	*	디폴트 생성자
	*/
	ListType()
	{
		m_List = new T[MAXSIZE];
		m_Length = 0;
		ResetList();
	}

	/**
	*	소멸자
	*/
	~ListType()
	{
		delete[] m_List;
	}

	/**
	*	@brief	리스트를 비운다
	*	@pre	.
	*	@post	리스트 모두 비움
	*/
	void MakeEmpty();

	/**
	*	@brief	레코드 수를 반환한다
	*	@pre	.
	*	@post	.
	*	@return	리스트의 현재 레코드 수
	*/
	int GetLength();

	/**
	*	@brief	리스트가 비어 있는지 검사한다
	*	@pre	.
	*	@post	.
	*	@return	리스트가 비어 있으면 true, 비어 있지 않으면 false 반환
	*/
	bool IsEmpty();

	/**
	*	@brief	리스트 레코드 수가 MAXSIZE에 도달해 꽉 찼는지 검사
	*	@pre	.
	*	@post	.
	*	@return	리스트가 꽉 찼으면 true, 아니면 false를 반환
	*/
	bool IsFull();

	/**
	*	@brief	새로운 데이터를 리스트에 추가
	*	@pre	리스트 초기화
	*	@post	새로운 레코드가 리스트에 추가됨
	*	@param	data	추가할 레코드 데이터
	*	@return	추가 성공시 1, 실패시 0을 반환
	*/
	int Add(T data);

	/**
	*	@brief	리스트 리터레이터를 초기화한다
	*	@pre	리스트 초기화
	*	@post	이터레이터가 리셋됨
	*/
	void ResetList();

	/**
	*	@brief	리스트 이터레이터를 다음으로 넘기고 리스트 레코드 읽어들임
	*	@pre	리스트와 이터레이터가 초기화 되지 않아야 한다
	*	@post	이터레이터가 다음 리스트로 넘어감
	*	@param	data	현재 이터레이터가 가리키는 레코드를 저장할 변수 (초기화 필요 없음)
	*	@return	이터레이터가 레코드 끝에 도달하지 않았으면 현재 이터레이터 위치, 아닐 경우 -1 반환
	*/
	int GetNextItem(T& data);

	/**
	*	@brief	파라미터의 학술대회명과 일치하는 리스트의 레코드를 읽어들임
	*	@pre	리스트 초기화
	*	@post	파라미터의 학술대회명과 일치하는 리스트의 레코드가 파라미터에 저장됨
	*	@param	data	찾을 레코드의 학술대회를 가지는 레코드, 학술대회만 입력되어 있어도 상관 없음, 함수 실행시 레코드 내용 저장
	*	@return	일치하는 레코드가 있으면 해당 레코드 위치, 아닐경우 -1 반환
	*/
	int Get(T& data);// Primary key를 기준으로 데이터를 검색하고 해당 데이터를 가져옴

	/**
	*	@brief	파라미터의 학술대회와 일치하는 리스트의 레코드를 바이너리 서치로 읽어들임
	*	@pre	리스트 초기화, 리스트 학술대회순으로 오름차순 정렬
	*	@post	파라미터의 학술대회와 일치하는 리스트의 레코드가 파라미터에 저장됨
	*	@param	data	찾을 레코드의 학술대회를 가지는 레코드, 학술대회만 입력되어 있어도 상관 없음, 함수 실행시 레코드 내용 저장
	*	@return	일치하는 레코드가 있으면 해당 레코드 위치, 아닐경우 입력받은 레코드가 삽입되어야 할 위치를 음수로 (* -1) 반환
	*/
	int GetBinarySearch(T& data);

	/**
	*	@brief	파라미터의 학술대회명과 일치하는 리스트의 레코드를 삭제함
	*	@pre	리스트 초기화
	*	@post	파라미터의 학술대회명과 일치하는 리스트의 레코드가 삭제되고, 맨 마지막에 있는 레코드가 해당하는 자리로 옮겨짐
	*	@param	data	삭제할 레코드의 학술대회명를 갖는 레코드, 학술대회명만 입력되어 있어도 상관 없음
	*	@return	삭제 성공시 1, 실패시 0을 반환
	*/
	int Delete(T data);

	/**
	*	@brief	파라미터의 학술대회명과 일치하는 리스트의 레코드를 파라미터로 대체함
	*	@pre	리스트 초기화
	*	@post	파라미터의 학술대회명과 일치하는 리스트의 레코드가 파라미터의 내용대로 바뀜
	*	@param	data	바꿀 레코드
	*	@return	대체 성공시 1, 실패시 0을 반환
	*/
	int Replace(T data);

	/**
	*	@brief	파라미터의 학술대회명과 일치하는 리스트의 레코드를 화면에 출력함
	*	@pre	리스트 초기화
	*	@post	파라미터의 학술대회명과 일치하는 리스트의 레코드가 화면에 출력됨
	*	@param	data	출력할 레코드의 학술대회명을 갖는 레코드, 학술대회명만 입력되어 있어도 상관 없음
	*	@return	출력 성공시 1, 실패시 0을 반환
	*/
	int Display(T data);

	/**
	*	@brief	배열 번호를 알고 있는 경우 배열 번호를 파라미터로 받아 레코드를 화면에 출력
	*	@pre	리스트 초기화
	*	@post	파라미터의 배열번호에 해당하는 리스트의 레코드가 화면에 출력됨
	*	@param	ArrayNumber	출력할 레코드의 배열 번호
	*	@return	출력 성공시 1, 실패시 0을 반환
	*/
	int Display(int ArrayNumber);

	/**
	*	@brief	학술 대회 정보 이름에서 입력된 단어가 포함된 레코드를 찾아 화면에 출력
	*	@pre	리스트 초기화
	*	@post	입력된 단어가 포함된 학술대회들을 간단히 출력
	*	@param	data	출력할 레코드의 학술대회명에 들어가는 단어를 학술대회명으로 하는 모든 레코드
	*	@return	출력 성공시 1, 실패시 0을 반환
	*/
	int Search(T data);

private:
	T * m_List;					///< data list
	int m_Length;				///< number of elements in list.
	int m_CurPointer;			///< iterator pointer.
};

// 리스트 초기화 
template<class T>
void ListType<T>::MakeEmpty()
{
	m_Length = 0;
}


// 현재 레코드 수 반환
template<class T>
int ListType<T>::GetLength()
{
	return m_Length;
}

// 리스트가 비어있는지 검사
template<class T>
bool ListType<T>::IsEmpty()
{
	if (m_Length < 1)
		return true;
	else
		return false;
}

// 리스트가 꽉 찼는지 검사
template<class T>
bool ListType<T>::IsFull()
{
	if (m_Length > MAXSIZE - 1)
		return true;
	else
		return false;
}

//학술대회명을 기준으로	데이터를 검색하고 해당 데이터를 data에 가져옴
template<class T>
int ListType<T>::Get(T& data)
{
	ResetList(); //이터레이터 초기화
	T inData; //레코드 비교를 위해 임시 저장할 ConferenceType
	while (1)
	{
		int i = GetNextItem(inData); //레코드 읽어오기
		if (i > -1)
		{//레코드 읽어와지면
			switch (data.CompareByName(inData))
			{
			case EQUAL:
				data = inData; //data에 레코드를 저장하고
				return i; //레코드의 위치를 반환해줌
				break;
			case GREATER: //입력된 학술대회명가 더 크면
				break; //다음 순서로
			case LESS: //입력된 학술대회명가 더 작으면
				return -1; //입력된 학술대회명가 없는 경우이므로 -1 리턴
				break;
			}
		}
		else return -1; // 실패시(빈 리스트일 경우 포함) -1 리턴
	}
}

// 학술대회명을 기준으로 데이터를 이진탐색하여 data에 가져옴
template<class T>
int ListType<T>::GetBinarySearch(T& data)
{
	if (IsEmpty()) // 빈 리스트이면
		return -1; //실패  -1 리턴

	int high = m_Length - 1;
	int low = 0;

	m_CurPointer = high / 2; //배열 중간으로 이터레이터 맞춤

	switch (m_List[m_CurPointer].CompareByName(data))
	{
	case EQUAL: //입력과 현재 위치값이 같으면
		data = m_List[m_CurPointer];
		return m_CurPointer; //해당 위치를 리턴해줌 (0이상)
		break;

	case GREATER: //입력보다 현재 위치값이 크면
		high = m_CurPointer - 1; //현재위치보다 작은 쪽만 검색한다
		if (high <= low) // 더 검색할 구간이 없으면
			return -1; // 실패 -1 리턴
		m_CurPointer = (high + low) / 2; //있으면 이터레이터를 검색범위 중간으로 맞춤
		break;

	case LESS: //입력보다 현재 위치값이 작으면
		low = m_CurPointer + 1; // 현재위치보다 큰 쪽만 검색한다
		if (high < low) // 더 검색할 구간이 없으면
			return -1; // 실패 -1 리턴
		m_CurPointer = (high + low) / 2; //있으면 이터레이터를 검색범위 중간으로 맞춤
		break;
	}
	return -1;
}

// 리스트에 새로운 레코드 추가
template<class T>
int ListType<T>::Add(T inData)
{
	if (!IsFull())
	{ //MAXSIZE도달하지 않았으면
		if (GetBinarySearch(inData) < 0)
		{//해당하는 학술대회명를 가진 레코드가 없으면 추가
			for (int i = m_Length; i >= 0; i--)
			{
				if (IsEmpty() || m_List[i - 1].CompareByName(inData) == LESS)
				{ // 빈 리스트이거나 i-1번째가 더 작으면
					m_List[i] = inData; // i번째에 inData 삽입
					m_Length++;
					return i; //삽입된 위치를 리턴해줌
				}
				else
					m_List[i] = m_List[i - 1]; // i-1번째를 i번째로 밀어 넘김
			}
			return -1; //for루프가 다 돌면 실패 (-1 리턴)
		}
		else
			return -1; //이미 같은 학술대회명를 가진 레코드가 있으면 삽입 불가 (-1 리턴)
	}
	else
		return -1; //MAXSIZE 도달로 삽입 불가 (-1 리턴)
}

//리스트에서 입력받은 학술대회명와 같은 레코드 삭제
template<class T>
int ListType<T>::Delete(T data)
{
	ResetList();
	int DeleteLoc = Get(data);

	if (DeleteLoc > -1)
	{ // 지울 레코드가 존재할 경우에만 지움
		for (int i = DeleteLoc; i < m_Length - 1; i++)
			m_List[i] = m_List[i + 1]; //지울 위치 뒤부터 레코드를 하나씩 당겨옴
		m_Length--;
		return 1;
	}
	else
		return 0;
}

//리스트에서 입력받은 학술대회명와 같은 레코드 내용 변경
template<class T>
int ListType<T>::Replace(T data)
{
	ResetList();
	int ReplaceLoc = Get(data);

	if (ReplaceLoc > -1)
	{
		m_List[ReplaceLoc] = data;
		return 1;
	}

	else
		return 0;
}

//리스트에서 입력받은 학술대회명를 가진 레코드를 화면에 출력
template<class T>
int ListType<T>::Display(T data)
{
	ResetList();
	int DisplayLoc = GetBinarySearch(data);

	if (DisplayLoc > -1)
	{
		m_List[DisplayLoc].DisplayRecordOnScreen();
		return 1;
	}

	else
		return 0;
}

//입력받은 배열번호에 해당하는 학술대회 정보를 화면에 출력
template<class T>
int ListType<T>::Display(int ArrayNumber)
{
	if (ArrayNumber > -1 || ArrayNumber < m_Length)
	{
		m_List[ArrayNumber].DisplayRecordOnScreen();
		return 1;
	}
	else
		return 0;
}

//리스트에서 입력받은 학술대회명를 가진 레코드를 화면에 출력
template<class T>
int ListType<T>::Search(T data)
{
	string input = data.getName();
	
	for (int i = 0; i < m_Length; i++)
	{
		if (m_List[i].getName().find(input) > -1)
			m_List[i].DisplayRecordOnScreen();
	}

	return 1;
}

// 이터레이터 초기화
template<class T>
void ListType<T>::ResetList()
{
	m_CurPointer = -1;
}


// 이터레이터 다음 레코드로 옮기고, 해당 레코드 읽음
template<class T>
int ListType<T>::GetNextItem(T& data)
{
	m_CurPointer++;	// list pointer 증가
	if (m_CurPointer == MAXSIZE)	// end of list이면 -1을 리턴
		return -1;
	data = m_List[m_CurPointer];	// 현재 list pointer의 레코드를 복사

	return m_CurPointer;
}


#endif	// _UNSORTEDLIST_H