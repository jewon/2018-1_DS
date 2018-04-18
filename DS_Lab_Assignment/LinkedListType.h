#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include "DoublyIterator.h"

/**
*	학술대회 정보에 포함되는 리스트들을 정의
*/
template <typename T>
class DoublyIterator;

template <typename T>
struct NodeType
{
	T data;	///< 노드에 포함되는 데이터
	NodeType* prev = NULL;	///< 이전 ㄴ드를 가리키는 포인터
	NodeType* next = NULL;	///< 다음 노드를 가리키는 포인터
};

/**
*	학술대회 정보에 포함되는 리스트들을 정의
*/
template <typename T>
class LinkedListType
{
	friend class DoublyIterator<T>;
public:
	/**
	*	디폴트 생성자
	*/
	LinkedListType();

	/**
	*	소멸자
	*/
	~LinkedListType();

	/**
	*	@brief	리스트에 포함된 정보 추상 이름을 알려준다
	*	@pre	.
	*	@post	리스트 모두 비움
	*	@return	TName
	*/
	string GetTName();

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
	int GetLength() const;

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
	int Add(T item);

	/**
	*	@brief	파라미터의 학술대회명과 일치하는 리스트의 레코드를 삭제함
	*	@pre	리스트 초기화
	*	@post	파라미터의 학술대회명과 일치하는 리스트의 레코드가 삭제되고, 맨 마지막에 있는 레코드가 해당하는 자리로 옮겨짐
	*	@param	data	삭제할 레코드의 학술대회명를 갖는 레코드, 학술대회명만 입력되어 있어도 상관 없음
	*	@return	삭제 성공시 1, 실패시 0을 반환
	*/
	int Delete(T item);

	/**
	*	@brief	파라미터의 학술대회명과 일치하는 리스트의 레코드를 파라미터로 대체함
	*	@pre	리스트 초기화
	*	@post	파라미터의 학술대회명과 일치하는 리스트의 레코드가 파라미터의 내용대로 바뀜
	*	@param	data	바꿀 레코드
	*	@return	대체 성공시 1, 실패시 0을 반환
	*/
	int Replace(T item);

	/**
	*	@brief	리스트 내 모든 레코드 출력 (T에 따라 출력 내용 다름)
	*	@pre	리스트 초기화
	*	@post	리스트 내 모든 정보 (ItemType에 따라) 출력
	*/
	void DisplayAll();

	/**
	*	@brief	리스트 내 모든 레코드 간략히 출력 (T에 따라 출력 내용 다름)
	*	@pre	리스트 초기화
	*	@post	리스트 내 모든 정보 (ItemType에 따라 간략히) 출력
	*/
	void DisplayAllBrief();

	/**
	*	@brief	현재 리스트와 리스트 B를 연결해 현재 리스트에 저장
	*	@pre	리스트 초기화, A,B 리스트의 연속적 정렬
	*	@parm	연결할 리스트
	*	@return	연결된 현재 리스트
	*	@post	리스트B가 현재 리스트의 뒤에 이어져 저장됨
	*/
	LinkedListType<T> Connect(LinkedListType<T>* ListB);

	/**
	*	@brief	파라미터의 학술대회명과 일치하는 리스트의 레코드를 읽어들임
	*	@pre	리스트 초기화
	*	@post	파라미터의 학술대회명과 일치하는 리스트의 레코드가 파라미터에 저장됨
	*	@param	data	찾을 레코드의 학술대회를 가지는 레코드, 학술대회만 입력되어 있어도 상관 없음, 함수 실행시 레코드 내용 저장
	*	@return	일치하는 레코드가 있으면 해당 레코드 위치, 아닐경우 -1 반환
	*/
	int Get(T &item);

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
	void GetNextItem(T& item);

	/**
	*	@brief	리스트의 이름을 기준으로 검색하여 특정 단어가 포함된 노드 출력
	*	@pre	리스트 초기화
	*	@post	특정 단어 포함된 노드 출력
	*	@param	word	찾을 단어
	*	@return	출력된 노드의 갯수 반환 (없으면 0)
	*/
	LinkedListType<T> FindByName(string word);

private:
	NodeType<T>* m_pList;	///< 첫 노드 가리키는 포인터
	NodeType<T>* m_pLast;
	int m_nLength;	///< 리스트의 길이
	string TName;	///< 현재 리스트 내용의 추상 이름
};


// 생성자
template <typename T>
LinkedListType<T>::LinkedListType()
{
	m_nLength = 0;
	m_pList = nullptr;
	m_pLast = nullptr;

	T temp;
	TName = temp.WhatType();
}

// 소멸자
template <typename T>
LinkedListType<T>::~LinkedListType()
{
	//리스트내의 모든 node 제거
	MakeEmpty(); // : 구조상 다른 소멸자 필요
}

// 리스트 포함하는 정보 추상이름 알려줌
template<typename T>
string LinkedListType<T>::GetTName()
{
	return TName;
}

// Initialize list to empty state.
template <typename T>
void LinkedListType<T>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
	// 리스트내의 모든 노드 제거 하고 리스트의 length를 초기화
	NodeType<T>* tempPtr;
	DoublyIterator<T> iter(*this);

	while (iter.NotNull())
	{
		tempPtr = iter.m_pCurPointer;
		iter.Next();
		delete tempPtr;
	}

	m_nLength = 0;
}


// Get number of elements in the list.
template <typename T>
int LinkedListType<T>::GetLength() const
{
	return m_nLength;
}



// Add item into this list.
template <typename T>
int LinkedListType<T>::Add(T item)
{
	if (!IsFull()) {
		NodeType<T>* node = new NodeType<T>;
		DoublyIterator<T> iter(*this);

		node->data = item;
		node->prev = nullptr;
		node->next = nullptr;

		// 비어있는 경우
		if (m_pList== nullptr) {
			m_pList = node;
			m_pLast = m_pList;
		}
		// 1개 이상
		else {
			NodeType<T>* pNode;	// iterator에서 나오는 데이터 객체
			while (iter.NotNull()) {
				// GetCurrentNode는 return by value이므로 수정 및 실 메모리 접근 불가해서 사용 못함
				pNode = iter.m_pCurPointer;

				if (node->data > pNode->data) { // 넣으려고 하는게 더 작음
					node->next = pNode;
					if (m_nLength == 1) {	// 맨 앞
						m_pList= node;
					}
					else {	// 중간
						node->prev = pNode->prev;
						node->prev->next = node;
					}
					pNode->prev = node;
					break;
				}
				else {
					if (!iter.NextNotNull()) {	// 맨 뒤
						pNode->next = node;
						node->prev = pNode;
						m_pLast = node;
						break;
					}
					else iter.Next();
				}
			}
		}

		m_nLength++;
		return 1;
	}
	else return 0;
}

// 특정 요소를 찾아 삭제하는 함수
template <typename T>
int LinkedListType<T>::Delete(T data) 
{
	NodeType<T>* pNode = m_pList;
	int positionIndex = Get(data);
	if (positionIndex) {
		for (int i = 1; i < positionIndex; i++) {
			pNode = pNode->next;
		}
		if (pNode->next != nullptr) {	// 끝이 아니면
			pNode->next->prev = pNode->prev;
		}
		else m_pLast = pNode->prev;
		if (pNode->prev != nullptr) {	// 처음이 아니면
			pNode->prev->next = pNode->next;
		}
		else m_pList= pNode->next;
		delete pNode;
		m_nLength--;
		return 1;
	}
	else return 0;

}


// 특정 요소를 찾아 새로운 내용으로 대치시키는 함수
template <typename T>
int LinkedListType<T>::Replace(T data) {

	T target = data;
	NodeType<T>* pNode = m_pList;
	int positionIndex = Get(target);
	for (int i = 1; i < positionIndex; i++) {
		pNode = pNode->next;
	}
	pNode->data = data;
	return 1;
}


// Retrieve list element whose key matches item's key (if present).
template <typename T>
int LinkedListType<T>::Get(T &item)
{
	NodeType<T>* pNode;
	DoublyIterator<T> iter(*this);
	int count = 0;	// 몇 번째에 위치하고 있는지 리턴 (없으면 0)
					// iterator를 사용하면서 curPointer를 재사용할 수 없으므로 return value의 의미를 변경
	bool found = false;
	while (iter.NotNull()) {
		count++;
		if (item == iter.GetCurrentNode()) {
			found = true;
			item = iter.GetCurrentNode();
			break;
		}
		else if (item < iter.GetCurrentNode()) {
			break;
		}
		else {
			iter.Next();
		}
	}

	if (found) {
		return count;
	}
	else
		return 0;
}


// 이터레이터 초기화
template <typename T>
void LinkedListType<T>::ResetList()
{
	// current pointer 초기화
	// m_pCurPointer = NULL;
}

// 개수제한은 없지만, 실제 메모리가 가득 차서 더 이상 할당이 불가능한 경우 시스템 예외 처리
template <typename T>
bool LinkedListType<T>::IsFull() {
	try {
		NodeType<T>* temp = nullptr;	// if there is not memory left, temp would not be initialized as NULL and
		delete temp;					// deleting temp(pointer) could not be executed.
		return false;
	}
	catch (bad_alloc& e_ba) {
		cerr << "bad_alloc exception caught : " << e_ba.what() << endl;
		return true;
	}
}

// 리스트가 비었는지 검사
template <typename T>
bool LinkedListType<T>::IsEmpty() {
	if (m_pList== nullptr) {
		return true;
	}
	else return false;
}

// 리스트의 다음 Item가져옴
template <typename T>
void LinkedListType<T>::GetNextItem(T& item)
{
	// current pointer 이 NULL이라면 처음 node를 가리킴.
	if (m_pCurPointer == NULL)
	{
		m_pCurPointer = m_pList;
	}
	else
		//current position 을 다음 노드로 이동
		m_pCurPointer = m_pCurPointer->next;

	//item 에 current position 의 info 를 삽입
	item = m_pCurPointer->data;
}

// 리스트 내의 모든 아이템 정보 출력(하위리스트 정보는 갯수만 출력)
template<typename T>
void LinkedListType<T>::DisplayAll()
{
	DoublyIterator<T> iter(*this);

	if (!IsEmpty())
	{
		T item;
		this->ResetList();
		cout << "\n\t*****" << TName << " List*****\n";
		for (int i = 0; i < this->GetLength(); i++)
		{
			item = iter.Next();
			cout << "\n\t-----" << item.GetName() << "-----\n";
			item.DisplayRecordOnScreen();
		}
		cout << "\n\t*****List End******\n\n";
	}
	else
		cout << "\t-----Messege-----\n\t리스트가 비어 있습니다.\n\t-----Messege-----" << endl;
	return;
}

// 리스트 내의 아이템들의 정보를 간략히 출력
template<typename T>
void LinkedListType<T>::DisplayAllBrief()
{
	T data;
	for (int i = 0; i < m_nLength; i++)
		data.DisplayBriefOnScreen();
}

// 현재 리스트에 파라미터 리스트를 연결함 (소팅X)
template<typename T>
LinkedListType<T> LinkedListType<T>::Connect(LinkedListType<T> * ListB)
{
	DoublyIterator<T> iter(*this);
	DoublyIterator<T> iterB(*ListB);


	this->m_pLast->next = ListB->m_pList;
	ListB->m_pList->prev = this->m_pLast;

	ListB->m_nLength = 0;
	ListB->m_pList = nullptr;
	ListB->m_pLast = nullptr;

	return *this;
}

// 리스트 내의 아이템 이름이 포함된 item을 찾아 리스트로 만들어 반환
template<typename T>
LinkedListType<T> LinkedListType<T>::FindByName(string word)
{
	LinkedListType<T> FoundList;
	string name;
	T temp;
	
	DoublyIterator<T> iter(*this);

	while (iter.NextNotNull())
	{
		temp = iter.Next();
		name = temp.GetName();
		if (name.find(word) != string::npos)
			FoundList.Add(temp);
	}

	return FoundList;
}

#endif	// _LINKED_LIST_H