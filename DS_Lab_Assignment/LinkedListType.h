#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include "DoublyIterator.h"

/**
*	�м���ȸ ������ ���ԵǴ� ����Ʈ���� ����
*/
template <typename T>
class DoublyIterator;

template <typename T>
struct NodeType
{
	T data;	///< ��忡 ���ԵǴ� ������
	NodeType* prev = NULL;	///< ���� ���带 ����Ű�� ������
	NodeType* next = NULL;	///< ���� ��带 ����Ű�� ������
};

/**
*	�м���ȸ ������ ���ԵǴ� ����Ʈ���� ����
*/
template <typename T>
class LinkedListType
{
	friend class DoublyIterator<T>;
public:
	/**
	*	����Ʈ ������
	*/
	LinkedListType();

	/**
	*	�Ҹ���
	*/
	~LinkedListType();

	/**
	*	@brief	����Ʈ�� ���Ե� ���� �߻� �̸��� �˷��ش�
	*	@pre	.
	*	@post	����Ʈ ��� ���
	*	@return	TName
	*/
	string GetTName();

	/**
	*	@brief	����Ʈ�� ����
	*	@pre	.
	*	@post	����Ʈ ��� ���
	*/
	void MakeEmpty();

	/**

	*	@brief	���ڵ� ���� ��ȯ�Ѵ�
	*	@pre	.
	*	@post	.
	*	@return	����Ʈ�� ���� ���ڵ� ��
	*/
	int GetLength() const;

	/**
	*	@brief	����Ʈ�� ��� �ִ��� �˻��Ѵ�
	*	@pre	.
	*	@post	.
	*	@return	����Ʈ�� ��� ������ true, ��� ���� ������ false ��ȯ
	*/
	bool IsEmpty();

	/**
	*	@brief	����Ʈ ���ڵ� ���� MAXSIZE�� ������ �� á���� �˻�
	*	@pre	.
	*	@post	.
	*	@return	����Ʈ�� �� á���� true, �ƴϸ� false�� ��ȯ
	*/
	bool IsFull();

	/**
	*	@brief	���ο� �����͸� ����Ʈ�� �߰�
	*	@pre	����Ʈ �ʱ�ȭ
	*	@post	���ο� ���ڵ尡 ����Ʈ�� �߰���
	*	@param	data	�߰��� ���ڵ� ������
	*	@return	�߰� ������ 1, ���н� 0�� ��ȯ
	*/
	int Add(T item);

	/**
	*	@brief	�Ķ������ �м���ȸ��� ��ġ�ϴ� ����Ʈ�� ���ڵ带 ������
	*	@pre	����Ʈ �ʱ�ȭ
	*	@post	�Ķ������ �м���ȸ��� ��ġ�ϴ� ����Ʈ�� ���ڵ尡 �����ǰ�, �� �������� �ִ� ���ڵ尡 �ش��ϴ� �ڸ��� �Ű���
	*	@param	data	������ ���ڵ��� �м���ȸ�� ���� ���ڵ�, �м���ȸ�� �ԷµǾ� �־ ��� ����
	*	@return	���� ������ 1, ���н� 0�� ��ȯ
	*/
	int Delete(T item);

	/**
	*	@brief	�Ķ������ �м���ȸ��� ��ġ�ϴ� ����Ʈ�� ���ڵ带 �Ķ���ͷ� ��ü��
	*	@pre	����Ʈ �ʱ�ȭ
	*	@post	�Ķ������ �м���ȸ��� ��ġ�ϴ� ����Ʈ�� ���ڵ尡 �Ķ������ ������ �ٲ�
	*	@param	data	�ٲ� ���ڵ�
	*	@return	��ü ������ 1, ���н� 0�� ��ȯ
	*/
	int Replace(T item);

	/**
	*	@brief	����Ʈ �� ��� ���ڵ� ��� (T�� ���� ��� ���� �ٸ�)
	*	@pre	����Ʈ �ʱ�ȭ
	*	@post	����Ʈ �� ��� ���� (ItemType�� ����) ���
	*/
	void DisplayAll();

	/**
	*	@brief	����Ʈ �� ��� ���ڵ� ������ ��� (T�� ���� ��� ���� �ٸ�)
	*	@pre	����Ʈ �ʱ�ȭ
	*	@post	����Ʈ �� ��� ���� (ItemType�� ���� ������) ���
	*/
	void DisplayAllBrief();

	/**
	*	@brief	���� ����Ʈ�� ����Ʈ B�� ������ ���� ����Ʈ�� ����
	*	@pre	����Ʈ �ʱ�ȭ, A,B ����Ʈ�� ������ ����
	*	@parm	������ ����Ʈ
	*	@return	����� ���� ����Ʈ
	*	@post	����ƮB�� ���� ����Ʈ�� �ڿ� �̾��� �����
	*/
	LinkedListType<T> Connect(LinkedListType<T>* ListB);

	/**
	*	@brief	�Ķ������ �м���ȸ��� ��ġ�ϴ� ����Ʈ�� ���ڵ带 �о����
	*	@pre	����Ʈ �ʱ�ȭ
	*	@post	�Ķ������ �м���ȸ��� ��ġ�ϴ� ����Ʈ�� ���ڵ尡 �Ķ���Ϳ� �����
	*	@param	data	ã�� ���ڵ��� �м���ȸ�� ������ ���ڵ�, �м���ȸ�� �ԷµǾ� �־ ��� ����, �Լ� ����� ���ڵ� ���� ����
	*	@return	��ġ�ϴ� ���ڵ尡 ������ �ش� ���ڵ� ��ġ, �ƴҰ�� -1 ��ȯ
	*/
	int Get(T &item);

	/**
	*	@brief	����Ʈ ���ͷ����͸� �ʱ�ȭ�Ѵ�
	*	@pre	����Ʈ �ʱ�ȭ
	*	@post	���ͷ����Ͱ� ���µ�
	*/
	void ResetList();

	/**
	*	@brief	����Ʈ ���ͷ����͸� �������� �ѱ�� ����Ʈ ���ڵ� �о����
	*	@pre	����Ʈ�� ���ͷ����Ͱ� �ʱ�ȭ ���� �ʾƾ� �Ѵ�
	*	@post	���ͷ����Ͱ� ���� ����Ʈ�� �Ѿ
	*	@param	data	���� ���ͷ����Ͱ� ����Ű�� ���ڵ带 ������ ���� (�ʱ�ȭ �ʿ� ����)
	*	@return	���ͷ����Ͱ� ���ڵ� ���� �������� �ʾ����� ���� ���ͷ����� ��ġ, �ƴ� ��� -1 ��ȯ
	*/
	void GetNextItem(T& item);

	/**
	*	@brief	����Ʈ�� �̸��� �������� �˻��Ͽ� Ư�� �ܾ ���Ե� ��� ���
	*	@pre	����Ʈ �ʱ�ȭ
	*	@post	Ư�� �ܾ� ���Ե� ��� ���
	*	@param	word	ã�� �ܾ�
	*	@return	��µ� ����� ���� ��ȯ (������ 0)
	*/
	LinkedListType<T> FindByName(string word);

private:
	NodeType<T>* m_pList;	///< ù ��� ����Ű�� ������
	NodeType<T>* m_pLast;
	int m_nLength;	///< ����Ʈ�� ����
	string TName;	///< ���� ����Ʈ ������ �߻� �̸�
};


// ������
template <typename T>
LinkedListType<T>::LinkedListType()
{
	m_nLength = 0;
	m_pList = nullptr;
	m_pLast = nullptr;

	T temp;
	TName = temp.WhatType();
}

// �Ҹ���
template <typename T>
LinkedListType<T>::~LinkedListType()
{
	//����Ʈ���� ��� node ����
	MakeEmpty(); // : ������ �ٸ� �Ҹ��� �ʿ�
}

// ����Ʈ �����ϴ� ���� �߻��̸� �˷���
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
	// ����Ʈ���� ��� ��� ���� �ϰ� ����Ʈ�� length�� �ʱ�ȭ
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

		// ����ִ� ���
		if (m_pList== nullptr) {
			m_pList = node;
			m_pLast = m_pList;
		}
		// 1�� �̻�
		else {
			NodeType<T>* pNode;	// iterator���� ������ ������ ��ü
			while (iter.NotNull()) {
				// GetCurrentNode�� return by value�̹Ƿ� ���� �� �� �޸� ���� �Ұ��ؼ� ��� ����
				pNode = iter.m_pCurPointer;

				if (node->data > pNode->data) { // �������� �ϴ°� �� ����
					node->next = pNode;
					if (m_nLength == 1) {	// �� ��
						m_pList= node;
					}
					else {	// �߰�
						node->prev = pNode->prev;
						node->prev->next = node;
					}
					pNode->prev = node;
					break;
				}
				else {
					if (!iter.NextNotNull()) {	// �� ��
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

// Ư�� ��Ҹ� ã�� �����ϴ� �Լ�
template <typename T>
int LinkedListType<T>::Delete(T data) 
{
	NodeType<T>* pNode = m_pList;
	int positionIndex = Get(data);
	if (positionIndex) {
		for (int i = 1; i < positionIndex; i++) {
			pNode = pNode->next;
		}
		if (pNode->next != nullptr) {	// ���� �ƴϸ�
			pNode->next->prev = pNode->prev;
		}
		else m_pLast = pNode->prev;
		if (pNode->prev != nullptr) {	// ó���� �ƴϸ�
			pNode->prev->next = pNode->next;
		}
		else m_pList= pNode->next;
		delete pNode;
		m_nLength--;
		return 1;
	}
	else return 0;

}


// Ư�� ��Ҹ� ã�� ���ο� �������� ��ġ��Ű�� �Լ�
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
	int count = 0;	// �� ��°�� ��ġ�ϰ� �ִ��� ���� (������ 0)
					// iterator�� ����ϸ鼭 curPointer�� ������ �� �����Ƿ� return value�� �ǹ̸� ����
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


// ���ͷ����� �ʱ�ȭ
template <typename T>
void LinkedListType<T>::ResetList()
{
	// current pointer �ʱ�ȭ
	// m_pCurPointer = NULL;
}

// ���������� ������, ���� �޸𸮰� ���� ���� �� �̻� �Ҵ��� �Ұ����� ��� �ý��� ���� ó��
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

// ����Ʈ�� ������� �˻�
template <typename T>
bool LinkedListType<T>::IsEmpty() {
	if (m_pList== nullptr) {
		return true;
	}
	else return false;
}

// ����Ʈ�� ���� Item������
template <typename T>
void LinkedListType<T>::GetNextItem(T& item)
{
	// current pointer �� NULL�̶�� ó�� node�� ����Ŵ.
	if (m_pCurPointer == NULL)
	{
		m_pCurPointer = m_pList;
	}
	else
		//current position �� ���� ���� �̵�
		m_pCurPointer = m_pCurPointer->next;

	//item �� current position �� info �� ����
	item = m_pCurPointer->data;
}

// ����Ʈ ���� ��� ������ ���� ���(��������Ʈ ������ ������ ���)
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
		cout << "\t-----Messege-----\n\t����Ʈ�� ��� �ֽ��ϴ�.\n\t-----Messege-----" << endl;
	return;
}

// ����Ʈ ���� �����۵��� ������ ������ ���
template<typename T>
void LinkedListType<T>::DisplayAllBrief()
{
	T data;
	for (int i = 0; i < m_nLength; i++)
		data.DisplayBriefOnScreen();
}

// ���� ����Ʈ�� �Ķ���� ����Ʈ�� ������ (����X)
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

// ����Ʈ ���� ������ �̸��� ���Ե� item�� ã�� ����Ʈ�� ����� ��ȯ
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