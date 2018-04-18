#ifndef _LIST_TYPE_H
#define _LIST_TYPE_H

#include <iostream>
#include <fstream>	
#include <string>
using namespace std;

#define MAXSIZE 10

/**
*	Array��� Sorted List (�м���ȸ �̸� ��������)
*	�м���ȸ ������ �� �迭��ҿ� ����
*/
template<class T>
class ListType
{
public:
	/**
	*	����Ʈ ������
	*/
	ListType()
	{
		m_List = new T[MAXSIZE];
		m_Length = 0;
		ResetList();
	}

	/**
	*	�Ҹ���
	*/
	~ListType()
	{
		delete[] m_List;
	}

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
	int GetLength();

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
	int Add(T data);

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
	int GetNextItem(T& data);

	/**
	*	@brief	�Ķ������ �м���ȸ��� ��ġ�ϴ� ����Ʈ�� ���ڵ带 �о����
	*	@pre	����Ʈ �ʱ�ȭ
	*	@post	�Ķ������ �м���ȸ��� ��ġ�ϴ� ����Ʈ�� ���ڵ尡 �Ķ���Ϳ� �����
	*	@param	data	ã�� ���ڵ��� �м���ȸ�� ������ ���ڵ�, �м���ȸ�� �ԷµǾ� �־ ��� ����, �Լ� ����� ���ڵ� ���� ����
	*	@return	��ġ�ϴ� ���ڵ尡 ������ �ش� ���ڵ� ��ġ, �ƴҰ�� -1 ��ȯ
	*/
	int Get(T& data);// Primary key�� �������� �����͸� �˻��ϰ� �ش� �����͸� ������

	/**
	*	@brief	�Ķ������ �м���ȸ�� ��ġ�ϴ� ����Ʈ�� ���ڵ带 ���̳ʸ� ��ġ�� �о����
	*	@pre	����Ʈ �ʱ�ȭ, ����Ʈ �м���ȸ������ �������� ����
	*	@post	�Ķ������ �м���ȸ�� ��ġ�ϴ� ����Ʈ�� ���ڵ尡 �Ķ���Ϳ� �����
	*	@param	data	ã�� ���ڵ��� �м���ȸ�� ������ ���ڵ�, �м���ȸ�� �ԷµǾ� �־ ��� ����, �Լ� ����� ���ڵ� ���� ����
	*	@return	��ġ�ϴ� ���ڵ尡 ������ �ش� ���ڵ� ��ġ, �ƴҰ�� �Է¹��� ���ڵ尡 ���ԵǾ�� �� ��ġ�� ������ (* -1) ��ȯ
	*/
	int GetBinarySearch(T& data);

	/**
	*	@brief	�Ķ������ �м���ȸ��� ��ġ�ϴ� ����Ʈ�� ���ڵ带 ������
	*	@pre	����Ʈ �ʱ�ȭ
	*	@post	�Ķ������ �м���ȸ��� ��ġ�ϴ� ����Ʈ�� ���ڵ尡 �����ǰ�, �� �������� �ִ� ���ڵ尡 �ش��ϴ� �ڸ��� �Ű���
	*	@param	data	������ ���ڵ��� �м���ȸ�� ���� ���ڵ�, �м���ȸ�� �ԷµǾ� �־ ��� ����
	*	@return	���� ������ 1, ���н� 0�� ��ȯ
	*/
	int Delete(T data);

	/**
	*	@brief	�Ķ������ �м���ȸ��� ��ġ�ϴ� ����Ʈ�� ���ڵ带 �Ķ���ͷ� ��ü��
	*	@pre	����Ʈ �ʱ�ȭ
	*	@post	�Ķ������ �м���ȸ��� ��ġ�ϴ� ����Ʈ�� ���ڵ尡 �Ķ������ ������ �ٲ�
	*	@param	data	�ٲ� ���ڵ�
	*	@return	��ü ������ 1, ���н� 0�� ��ȯ
	*/
	int Replace(T data);

	/**
	*	@brief	�Ķ������ �м���ȸ��� ��ġ�ϴ� ����Ʈ�� ���ڵ带 ȭ�鿡 �����
	*	@pre	����Ʈ �ʱ�ȭ
	*	@post	�Ķ������ �м���ȸ��� ��ġ�ϴ� ����Ʈ�� ���ڵ尡 ȭ�鿡 ��µ�
	*	@param	data	����� ���ڵ��� �м���ȸ���� ���� ���ڵ�, �м���ȸ�� �ԷµǾ� �־ ��� ����
	*	@return	��� ������ 1, ���н� 0�� ��ȯ
	*/
	int Display(T data);

	/**
	*	@brief	�迭 ��ȣ�� �˰� �ִ� ��� �迭 ��ȣ�� �Ķ���ͷ� �޾� ���ڵ带 ȭ�鿡 ���
	*	@pre	����Ʈ �ʱ�ȭ
	*	@post	�Ķ������ �迭��ȣ�� �ش��ϴ� ����Ʈ�� ���ڵ尡 ȭ�鿡 ��µ�
	*	@param	ArrayNumber	����� ���ڵ��� �迭 ��ȣ
	*	@return	��� ������ 1, ���н� 0�� ��ȯ
	*/
	int Display(int ArrayNumber);

	/**
	*	@brief	�м� ��ȸ ���� �̸����� �Էµ� �ܾ ���Ե� ���ڵ带 ã�� ȭ�鿡 ���
	*	@pre	����Ʈ �ʱ�ȭ
	*	@post	�Էµ� �ܾ ���Ե� �м���ȸ���� ������ ���
	*	@param	data	����� ���ڵ��� �м���ȸ�� ���� �ܾ �м���ȸ������ �ϴ� ��� ���ڵ�
	*	@return	��� ������ 1, ���н� 0�� ��ȯ
	*/
	int Search(T data);

private:
	T * m_List;					///< data list
	int m_Length;				///< number of elements in list.
	int m_CurPointer;			///< iterator pointer.
};

// ����Ʈ �ʱ�ȭ 
template<class T>
void ListType<T>::MakeEmpty()
{
	m_Length = 0;
}


// ���� ���ڵ� �� ��ȯ
template<class T>
int ListType<T>::GetLength()
{
	return m_Length;
}

// ����Ʈ�� ����ִ��� �˻�
template<class T>
bool ListType<T>::IsEmpty()
{
	if (m_Length < 1)
		return true;
	else
		return false;
}

// ����Ʈ�� �� á���� �˻�
template<class T>
bool ListType<T>::IsFull()
{
	if (m_Length > MAXSIZE - 1)
		return true;
	else
		return false;
}

//�м���ȸ���� ��������	�����͸� �˻��ϰ� �ش� �����͸� data�� ������
template<class T>
int ListType<T>::Get(T& data)
{
	ResetList(); //���ͷ����� �ʱ�ȭ
	T inData; //���ڵ� �񱳸� ���� �ӽ� ������ ConferenceType
	while (1)
	{
		int i = GetNextItem(inData); //���ڵ� �о����
		if (i > -1)
		{//���ڵ� �о������
			switch (data.CompareByName(inData))
			{
			case EQUAL:
				data = inData; //data�� ���ڵ带 �����ϰ�
				return i; //���ڵ��� ��ġ�� ��ȯ����
				break;
			case GREATER: //�Էµ� �м���ȸ�� �� ũ��
				break; //���� ������
			case LESS: //�Էµ� �м���ȸ�� �� ������
				return -1; //�Էµ� �м���ȸ�� ���� ����̹Ƿ� -1 ����
				break;
			}
		}
		else return -1; // ���н�(�� ����Ʈ�� ��� ����) -1 ����
	}
}

// �м���ȸ���� �������� �����͸� ����Ž���Ͽ� data�� ������
template<class T>
int ListType<T>::GetBinarySearch(T& data)
{
	if (IsEmpty()) // �� ����Ʈ�̸�
		return -1; //����  -1 ����

	int high = m_Length - 1;
	int low = 0;

	m_CurPointer = high / 2; //�迭 �߰����� ���ͷ����� ����

	switch (m_List[m_CurPointer].CompareByName(data))
	{
	case EQUAL: //�Է°� ���� ��ġ���� ������
		data = m_List[m_CurPointer];
		return m_CurPointer; //�ش� ��ġ�� �������� (0�̻�)
		break;

	case GREATER: //�Էº��� ���� ��ġ���� ũ��
		high = m_CurPointer - 1; //������ġ���� ���� �ʸ� �˻��Ѵ�
		if (high <= low) // �� �˻��� ������ ������
			return -1; // ���� -1 ����
		m_CurPointer = (high + low) / 2; //������ ���ͷ����͸� �˻����� �߰����� ����
		break;

	case LESS: //�Էº��� ���� ��ġ���� ������
		low = m_CurPointer + 1; // ������ġ���� ū �ʸ� �˻��Ѵ�
		if (high < low) // �� �˻��� ������ ������
			return -1; // ���� -1 ����
		m_CurPointer = (high + low) / 2; //������ ���ͷ����͸� �˻����� �߰����� ����
		break;
	}
	return -1;
}

// ����Ʈ�� ���ο� ���ڵ� �߰�
template<class T>
int ListType<T>::Add(T inData)
{
	if (!IsFull())
	{ //MAXSIZE�������� �ʾ�����
		if (GetBinarySearch(inData) < 0)
		{//�ش��ϴ� �м���ȸ�� ���� ���ڵ尡 ������ �߰�
			for (int i = m_Length; i >= 0; i--)
			{
				if (IsEmpty() || m_List[i - 1].CompareByName(inData) == LESS)
				{ // �� ����Ʈ�̰ų� i-1��°�� �� ������
					m_List[i] = inData; // i��°�� inData ����
					m_Length++;
					return i; //���Ե� ��ġ�� ��������
				}
				else
					m_List[i] = m_List[i - 1]; // i-1��°�� i��°�� �о� �ѱ�
			}
			return -1; //for������ �� ���� ���� (-1 ����)
		}
		else
			return -1; //�̹� ���� �м���ȸ�� ���� ���ڵ尡 ������ ���� �Ұ� (-1 ����)
	}
	else
		return -1; //MAXSIZE ���޷� ���� �Ұ� (-1 ����)
}

//����Ʈ���� �Է¹��� �м���ȸ��� ���� ���ڵ� ����
template<class T>
int ListType<T>::Delete(T data)
{
	ResetList();
	int DeleteLoc = Get(data);

	if (DeleteLoc > -1)
	{ // ���� ���ڵ尡 ������ ��쿡�� ����
		for (int i = DeleteLoc; i < m_Length - 1; i++)
			m_List[i] = m_List[i + 1]; //���� ��ġ �ں��� ���ڵ带 �ϳ��� ��ܿ�
		m_Length--;
		return 1;
	}
	else
		return 0;
}

//����Ʈ���� �Է¹��� �м���ȸ��� ���� ���ڵ� ���� ����
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

//����Ʈ���� �Է¹��� �м���ȸ�� ���� ���ڵ带 ȭ�鿡 ���
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

//�Է¹��� �迭��ȣ�� �ش��ϴ� �м���ȸ ������ ȭ�鿡 ���
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

//����Ʈ���� �Է¹��� �м���ȸ�� ���� ���ڵ带 ȭ�鿡 ���
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

// ���ͷ����� �ʱ�ȭ
template<class T>
void ListType<T>::ResetList()
{
	m_CurPointer = -1;
}


// ���ͷ����� ���� ���ڵ�� �ű��, �ش� ���ڵ� ����
template<class T>
int ListType<T>::GetNextItem(T& data)
{
	m_CurPointer++;	// list pointer ����
	if (m_CurPointer == MAXSIZE)	// end of list�̸� -1�� ����
		return -1;
	data = m_List[m_CurPointer];	// ���� list pointer�� ���ڵ带 ����

	return m_CurPointer;
}


#endif	// _UNSORTEDLIST_H