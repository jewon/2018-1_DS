///*
//
//���Ŀ� ����Ʈ �����͸� �ε����ϰ�, �Ҵ� ���� ������ �� Ŭ�����Դϴ�. (���� ���X)
//
//*/
//
//#ifndef _BASE_H
//#define _BASE_H
//
//#include<iostream>
//#include<string>
//
//#include "LinkedListType.h"
//#include "ConferenceType.h"
//
//template <typename T>
//struct ListPointerNode
//{
//	LinkedListType<T> * ListPointer  = NULL;	///< ��忡 ���ԵǴ� ������ = ����Ʈ������
//	ListPointerNode * next = NULL;	///< ���� ��带 ����Ű�� ������
//};
//
///**
//*	����Ʈ ������ �Ҵ� �� ����, �ε���
//*/
//class Base
//{
//
//public:
//	Base();
//	void Update();
//	LinkedListType<ConferenceType> * Setup();
//	LinkedListType<SessionType> * SessionListAdd();
//	LinkedListType<PaperType> * PaperListAdd();
//	void SessionListDelete(LinkedListType<SessionType> * list);
//	void PapaerListDelete(LinkedListType<PaperType> * list);
//
//
//protected:
//	LinkedListType<ConferenceType> * i_pList;
//	ListPointerNode<SessionType> * s_LP;
//	int s_LP_length;
//	ListPointerNode<PaperType> * p_LP;
//	int p_LP_length;
//};
//
//Base::Base()
//{
//	i_pList = new LinkedListType<ConferenceType>;
//	s_LP = NULL;
//	p_LP = NULL;
//	s_LP_length = 0;
//	p_LP_length = 0;
//}
//
//void Base::Update()
//{
//
//}
//
//LinkedListType<ConferenceType>* Base::Setup()
//{
//	return i_pList;
//}
//
//LinkedListType<SessionType>* Base::SessionListAdd()
//{
//	ListPointerNode<SessionType> * NewSessionListNode = new ListPointerNode<SessionType>;
//	NewSessionListNode->ListPointer = new LinkedListType<SessionType>;
//
//	if (s_LP_length == 0)
//		s_LP->ListPointer = NewSessionListNode->ListPointer; // ������ �ϵ�ī��
//	else
//	{
//		ListPointerNode<SessionType> * temp = s_LP;
//		while (temp->next != NULL)
//			temp = temp->next; // ������ ���� �̵�
//		temp->next = NewSessionListNode;
//	}
//
//	s_LP_length++;
//
//	return NewSessionListNode->ListPointer;
//}
//
//LinkedListType<PaperType>* Base::PaperListAdd()
//{
//	ListPointerNode<PaperType> * NewPaperListNode = new ListPointerNode<PaperType>;
//	NewPaperListNode->ListPointer = new LinkedListType<PaperType>;
//
//	if (p_LP_length == 0)
//		p_LP->ListPointer = NewPaperListNode->ListPointer; // ������ �ϵ�ī��
//	else
//	{
//		ListPointerNode<PaperType> * temp = p_LP;
//		while (temp->next != NULL)
//			temp = temp->next; // ������ ���� �̵�
//		temp->next = NewPaperListNode;
//	}
//
//	p_LP_length++;
//
//	return NewPaperListNode->ListPointer;
//}
//
//void Base::SessionListDelete(LinkedListType<SessionType>* inListPointer)
//{
//	if (s_LP_length == 0)
//		return;
//
//	ListPointerNode<SessionType> * temp = s_LP;
//	ListPointerNode<SessionType> * pre_temp = NULL;
//	while (temp != NULL)
//	{ // temp�����͸� �̵���Ű�鼭 ã��
//		if (temp->ListPointer == inListPointer)
//			break;
//		pre_temp = temp;
//		temp = temp->next;
//	}
//
//	if (temp == NULL) // ������ ���µ� �� ã������ ����
//		return;
//
//	if (pre_temp != NULL) // ó�� ��尡 �ƴϸ�
//		pre_temp->next = temp->next; // ���� ��带 ���� ���� ����(���� ��尡 ������ NULL�̵�)
//
//	else // ù ����
//		s_LP = temp->next; // ù ��带 ���� ���� ����(������ NULL)
//
//	delete temp->ListPointer; // ����� ����Ʈ �Ҵ� ����
//	delete temp; // ��� �Ҵ� ����
//
//	return;
//}
//
//void Base::PapaerListDelete(LinkedListType<PaperType>* inListPointer)
//{
//	if (p_LP_length == 0)
//		return;
//
//	ListPointerNode<PaperType> * temp = p_LP;
//	ListPointerNode<PaperType> * pre_temp = NULL;
//	while (temp != NULL)
//	{ // temp�����͸� �̵���Ű�鼭 ã��
//		if (temp->ListPointer == inListPointer)
//			break;
//		pre_temp = temp;
//		temp = temp->next;
//	}
//
//	if (temp == NULL) // ������ ���µ� �� ã������ ����
//		return;
//
//	if (pre_temp != NULL) // ó�� ��尡 �ƴϸ�
//		pre_temp->next = temp->next; // ���� ��带 ���� ���� ����(���� ��尡 ������ NULL�̵�)
//
//	else // ù ����
//		p_LP = temp->next; // ù ��带 ���� ���� ����(������ NULL)
//
//	delete temp->ListPointer; // ����� ����Ʈ �Ҵ� ����
//	delete temp; // ��� �Ҵ� ����
//
//	return;
//}
//
//
//#endif _BASE_H