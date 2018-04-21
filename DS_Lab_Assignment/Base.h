#ifndef _BASE_H
#define _BASE_H

#include<iostream>
#include<string>

#include "LinkedListType.h"
#include "ConferenceType.h"

template <typename T>
struct ListPointerNode
{
	LinkedListType<T> * ListPointer  = NULL;	///< 노드에 포함되는 데이터 = 리스트포인터
	ListPointerNode * next = NULL;	///< 다음 노드를 가리키는 포인터
};

// 리스트의 할당과 해제 관리 및 리스트 포인터 색인
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
