#include "Base.h"

void Base::Update()
{
	
}

LinkedListType<SessionType>* Base::SessionListAdd()
{
	ListPointerNode<SessionType> * NewSessionListNode = new ListPointerNode<SessionType>;
	NewSessionListNode->ListPointer  = new LinkedListType<SessionType>;

	if (s_LP_length == 0)
		s_LP->ListPointer = NewSessionListNode->ListPointer; // ������ �ϵ�ī��
	else
	{
		ListPointerNode<SessionType> * temp = s_LP;
		while (temp->next != NULL)
			temp = temp->next; // ������ ���� �̵�
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
		p_LP->ListPointer = NewPaperListNode->ListPointer; // ������ �ϵ�ī��
	else
	{
		ListPointerNode<PaperType> * temp = p_LP;
		while (temp->next != NULL)
			temp = temp->next; // ������ ���� �̵�
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
	{ // temp�����͸� �̵���Ű�鼭 ã��
		if (temp->ListPointer == inListPointer)
			break;
		pre_temp = temp;
		temp = temp->next;
	}

	if (temp == NULL) // ������ ���µ� �� ã������ ����
		return;

	if (pre_temp != NULL) // ó�� ��尡 �ƴϸ�
		pre_temp->next = temp->next; // ���� ��带 ���� ���� ����(���� ��尡 ������ NULL�̵�)

	else // ù ����
		s_LP = temp->next; // ù ��带 ���� ���� ����(������ NULL)

	delete temp->ListPointer; // ����� ����Ʈ �Ҵ� ����
	delete temp; // ��� �Ҵ� ����

	return;
}

void Base::PapaerListDelete(LinkedListType<PaperType>* inListPointer)
{
	if (p_LP_length == 0)
		return;

	ListPointerNode<PaperType> * temp = p_LP;
	ListPointerNode<PaperType> * pre_temp = NULL;
	while (temp != NULL)
	{ // temp�����͸� �̵���Ű�鼭 ã��
		if (temp->ListPointer == inListPointer)
			break;
		pre_temp = temp;
		temp = temp->next;
	}

	if (temp == NULL) // ������ ���µ� �� ã������ ����
		return;

	if (pre_temp != NULL) // ó�� ��尡 �ƴϸ�
		pre_temp->next = temp->next; // ���� ��带 ���� ���� ����(���� ��尡 ������ NULL�̵�)

	else // ù ����
		p_LP = temp->next; // ù ��带 ���� ���� ����(������ NULL)

	delete temp->ListPointer; // ����� ����Ʈ �Ҵ� ����
	delete temp; // ��� �Ҵ� ����

	return;
}
