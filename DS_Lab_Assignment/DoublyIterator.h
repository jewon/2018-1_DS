#ifndef _DOUBLY_ITERATOR_H
#define _DOUBLY_ITERATOR_H

#include "LinkedListType.h"

/**
*	template ���� ���� ����
*/
template <typename T>
class LinkedListType;

/**
*	template ���� ���� ����
*/
template <typename T>
struct NodeType;

/**
*	����ũ�帮��Ʈ ���ͷ����� Ŭ����
*/
template <typename T>
class DoublyIterator
{
	friend class LinkedListType<T>;
public:
	/**
	*	������ : m_List�� ����Ʈ�� �ް�, m_pCurPointer�� ���� ���� �ʱ�ȭ
	*/
	DoublyIterator(const LinkedListType<T>& list) : m_List(list), m_pCurPointer(list.m_pList) {}

	/**
	*	@brief	���� ��带 ����Ű�� �����Ͱ� null���� �ƴ��� �Ǵ��ϴ� �޼���.
	*	@pre	���ͷ����� �ʱ�ȭ
	*	@post	.
	*	@return	NULL�̸� true, �ƴϸ� false.
	*/
	bool NotNull();	

	/**
	*	@brief	���� ��� �������� ���� ��尡 null���� �ƴ��� �Ǵ��ϴ� �޼���.
	*	@pre	���ͷ����� �ʱ�ȭ
	*	@post	.
	*	@return	NULL�̸� true, �ƴϸ� false.
	*/
	bool NextNotNull();

	/**
	*	@brief	ù ��° ����� ������ ��ȯ
	*	@pre	���ͷ����� �ʱ�ȭ
	*	@post	m_pCurPointer�� ù ���� �̵�
	*	@return	ù ���� ����� TŸ�� ������
	*/
	T First();

	/**
	*	@brief	���� ����� ������ ��ȯ
	*	@pre	���ͷ����� �ʱ�ȭ
	*	@post	m_pCurPointer�� ���� ���� �̵�
	*	@return	���� ����� TŸ�� ������
	*/
	T Next();

	/**
	*	@brief	���� ��带 ��ȯ���ְ� ���ͷ����� �����͸� ���� ���� �ű�
	*	@pre	���ͷ����� �ʱ�ȭ
	*	@post	m_pCurPointer�� ���� ���� �̵�
	*	@return	���� ���
	*/
	T GetCurrentNode();

private:
	const LinkedListType<T>& m_List;	///< ����� ����Ʈ�� ���� ����
	NodeType<T>* m_pCurPointer;	///< ���ͷ����ͷ� ����ϴ� ������ ����
};


// ���� ���Ұ� null���� �˻�
template <typename T>
bool DoublyIterator<T>::NotNull() {
	if (m_pCurPointer == nullptr) {
		return false;
	}
	else return true;
}

// ���� ���Ұ� null���� �˻�
template <typename T>
bool DoublyIterator<T>::NextNotNull() {
	if (m_pCurPointer->next == nullptr) {
	
		return false;
	}
	else return true;
}

// ù ��° node
template <typename T>
T DoublyIterator<T>::First() {
	if (m_List.IsEmpty()) {
		m_pCurPointer = m_List.m_pList;
		return m_pCurPointer->data;
	}
}

// ���� node�� �̵� �� item�� return.
template <typename T>
T DoublyIterator<T>::Next() 
{
	T output = m_pCurPointer->data; 
	if (NotNull()) {
		m_pCurPointer = m_pCurPointer->next;
	}
	return output;
}

// ���� node�� return
template <typename T>
T DoublyIterator<T>::GetCurrentNode() {
	if (m_pCurPointer!=nullptr) {
		return m_pCurPointer->data;
	}
}

#endif // !_DOUBLY_ITERATOR_H
