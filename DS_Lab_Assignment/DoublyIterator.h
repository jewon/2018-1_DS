#ifndef _DOUBLY_ITERATOR_H
#define _DOUBLY_ITERATOR_H

#include "LinkedListType.h"

/**
*	template 참조 에러 방지
*/
template <typename T>
class LinkedListType;

/**
*	template 참조 에러 방지
*/
template <typename T>
struct NodeType;

/**
*	더블링크드리스트 이터레이터 클래스
*/
template <typename T>
class DoublyIterator
{
	friend class LinkedListType<T>;
public:
	/**
	*	생성자 : m_List에 리스트를 받고, m_pCurPointer를 시작 노드로 초기화
	*/
	DoublyIterator(const LinkedListType<T>& list) : m_List(list), m_pCurPointer(list.m_pList) {}

	/**
	*	@brief	현재 노드를 가리키는 포인터가 null인지 아닌지 판단하는 메서드.
	*	@pre	이터레이터 초기화
	*	@post	.
	*	@return	NULL이면 true, 아니면 false.
	*/
	bool NotNull();	

	/**
	*	@brief	현재 노드 포인터의 다음 노드가 null인지 아닌지 판단하는 메서드.
	*	@pre	이터레이터 초기화
	*	@post	.
	*	@return	NULL이면 true, 아니면 false.
	*/
	bool NextNotNull();

	/**
	*	@brief	첫 번째 노드의 데이터 반환
	*	@pre	이터레이터 초기화
	*	@post	m_pCurPointer가 첫 노드로 이동
	*	@return	첫 번쨰 노드의 T타입 데이터
	*/
	T First();

	/**
	*	@brief	다음 노드의 데이터 반환
	*	@pre	이터레이터 초기화
	*	@post	m_pCurPointer가 다음 노드로 이동
	*	@return	다음 노드의 T타입 데이터
	*/
	T Next();

	/**
	*	@brief	현재 노드를 반환해주고 이터레이터 포인터를 다음 노드로 옮김
	*	@pre	이터레이터 초기화
	*	@post	m_pCurPointer가 다음 노드로 이동
	*	@return	현재 노드
	*/
	T GetCurrentNode();

private:
	const LinkedListType<T>& m_List;	///< 사용할 리스트의 참조 변수
	NodeType<T>* m_pCurPointer;	///< 이터레이터로 사용하는 포인터 변수
};


// 현재 원소가 null인지 검사
template <typename T>
bool DoublyIterator<T>::NotNull() {
	if (m_pCurPointer == nullptr) {
		return false;
	}
	else return true;
}

// 다음 원소가 null인지 검사
template <typename T>
bool DoublyIterator<T>::NextNotNull() {
	if (m_pCurPointer->next == nullptr) {
	
		return false;
	}
	else return true;
}

// 첫 번째 node
template <typename T>
T DoublyIterator<T>::First() {
	if (m_List.IsEmpty()) {
		m_pCurPointer = m_List.m_pList;
		return m_pCurPointer->data;
	}
}

// 다음 node로 이동 후 item을 return.
template <typename T>
T DoublyIterator<T>::Next() 
{
	T output = m_pCurPointer->data; 
	if (NotNull()) {
		m_pCurPointer = m_pCurPointer->next;
	}
	return output;
}

// 현재 node를 return
template <typename T>
T DoublyIterator<T>::GetCurrentNode() {
	if (m_pCurPointer!=nullptr) {
		return m_pCurPointer->data;
	}
}

#endif // !_DOUBLY_ITERATOR_H
