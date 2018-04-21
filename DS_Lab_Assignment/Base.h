#ifndef _BASE_H
#define _BASE_H

#include<iostream>
#include<string>

#include "LinkedListType.h"
#include "ConferenceType.h"

template <typename T>
struct ListPointerNode
{
	LinkedListType<T> * ListPointer  = NULL;	///< ��忡 ���ԵǴ� ������ = ����Ʈ������
	ListPointerNode * next = NULL;	///< ���� ��带 ����Ű�� ������
};

// ����Ʈ�� �Ҵ�� ���� ���� �� ����Ʈ ������ ����
class Base
{

public:
	Base() {}
	void Update();
	LinkedListType<SessionType> * SessionListAdd();
	LinkedListType<PaperType> * PaperListAdd();
	void SessionListDeleete(LinkedListType<SessionType> * list);
	void PapaerListDelete(LinkedListType<PaperType> * list);


protected:
	LinkedListType<ConferenceType> * i_pList;
	ListPointerNode<SessionType> * s_LP;
	int s_LP_length;
	ListPointerNode<PaperType> * p_LP;
	int p_LP_length;
};

#endif _BASE_H
