#include "Base.h"

void Base::Update()
{
	
}

LinkedListType<SessionType>* Base::SessionListAdd()
{
	ListPointerNode<SessionType> * NewSessionListNode = new ListPointerNode<SessionType>;
	NewSessionListNode->ListPointer  = new LinkedListType<SessionType>;

	if (s_LP_length == 0)
		s_LP->ListPointer = NewSessionListNode->ListPointer; // 포인터 하드카피
	else
	{
		ListPointerNode<SessionType> * temp = s_LP;
		while (temp->next != NULL)
			temp = temp->next; // 마지막 노드로 이동
		temp->next = NewSessionListNode;
	}

	s_LP_length++;

	return NewSessionListNode->ListPointer;
}

LinkedListType<PaperType>* Base::PaperListAdd()
{
	ListPointerNode<PaperType> * NewPaperListNode = new ListPointerNode<PaperType>;
	NewPaperListNode->ListPointer = new LinkedListType<PaperType>;

	if (p_LP_length == 0)
		p_LP->ListPointer = NewPaperListNode->ListPointer; // 포인터 하드카피
	else
	{
		ListPointerNode<PaperType> * temp = p_LP;
		while (temp->next != NULL)
			temp = temp->next; // 마지막 노드로 이동
		temp->next = NewPaperListNode;
	}

	p_LP_length++;

	return NewPaperListNode->ListPointer;
}

void Base::SessionListDeleete(LinkedListType<SessionType>* inListPointer)
{
	if (s_LP_length == 0)
		return;
	
	ListPointerNode<SessionType> * temp = s_LP;
	ListPointerNode<SessionType> * pre_temp = NULL;
	while (temp != NULL)
	{ // temp포인터를 이동시키면서 찾음
		if (temp->ListPointer == inListPointer)
			break;
		pre_temp = temp;
		temp = temp->next;
	}

	if (temp == NULL) // 끝까지 갔는데 못 찾았으면 리턴
		return;

	if (pre_temp != NULL) // 처음 노드가 아니면
		pre_temp->next = temp->next; // 이전 노드를 다음 노드와 연결(다음 노드가 없으면 NULL이됨)

	else // 첫 노드면
		s_LP = temp->next; // 첫 노드를 다음 노드로 설정(없으면 NULL)

	delete temp->ListPointer; // 노드의 리스트 할당 해제
	delete temp; // 노드 할당 해제

	return;
}

void Base::PapaerListDelete(LinkedListType<PaperType>* inListPointer)
{
	if (p_LP_length == 0)
		return;

	ListPointerNode<PaperType> * temp = p_LP;
	ListPointerNode<PaperType> * pre_temp = NULL;
	while (temp != NULL)
	{ // temp포인터를 이동시키면서 찾음
		if (temp->ListPointer == inListPointer)
			break;
		pre_temp = temp;
		temp = temp->next;
	}

	if (temp == NULL) // 끝까지 갔는데 못 찾았으면 리턴
		return;

	if (pre_temp != NULL) // 처음 노드가 아니면
		pre_temp->next = temp->next; // 이전 노드를 다음 노드와 연결(다음 노드가 없으면 NULL이됨)

	else // 첫 노드면
		p_LP = temp->next; // 첫 노드를 다음 노드로 설정(없으면 NULL)

	delete temp->ListPointer; // 노드의 리스트 할당 해제
	delete temp; // 노드 할당 해제

	return;
}
