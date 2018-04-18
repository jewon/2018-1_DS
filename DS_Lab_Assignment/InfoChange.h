#ifndef _INFO_CHANGE_H
#define _INFO_CHANGE_H

#include<iostream>
#include<string>
using namespace std;

#include"LinkedListType.h"

/**
*	LinkedListType�� �޾� ����ڰ� ������ �� �ְ� ��
*/
template <typename T>
class InfoChange
{
public :
	/**
	*	�⺻ ������
	*/
	InfoChange() 
	{
		i_List = NULL;
	}

	/**
	*	�� Ÿ�� ����Ʈ�� ���� ������ ���� ������
	*/
	/*InfoChange(LinkedListType<T> &item)
	{
		i_List = item;
		i_Command = 0;
	}*/

	/**
	*	�Ҹ���
	*/
	~InfoChange() 
	{
		i_List = NULL;
	}

	/**
	*	@brief	�������� ����
	*	@pre	�������� ����
	*	@post	�������� ��
	*/
	void Run(LinkedListType<T> * inList);

	/**
	*	@brief	��� ����� ȭ�鿡 ����ϰ� ����� �Է¹޴´�
	*	@pre	.
	*	@post	.
	*	@return	�Է��� ���
	*/
	int GetCommand();

	/**
	*	@brief	���ο� ���ڵ带 �߰���
	*	@pre	����Ʈ�� �ʱ�ȭ�� �Ǿ� �־�� �Ѵ�
	*	@post	���ο� ���ڵ尡 ����Ʈ�� �߰��ȴ�
	*	@return	����Ʈ�� �߰��� ���������� �Ǿ����� 1, �����ϸ� 0�� ����
	*/
	int Add();

	/**
	*	@brief  ���ڵ� �̸��� �Է��� �ش緹�ڵ带 ������
	*	@pre	�ش� �̸�(Primary Key) ���� ���ڵ尡 �����ϰ� ����Ʈ�� ����
	*	@post	�ش� �̸�(Primary Key) ���ڵ尡 ����
	*	@return	���ڵ� ���� ������ 1, ���н� 0�� ����
	*/
	int Delete();

	/**
	*	@brief  ���ڵ带 ������ �ٲ�
	*	@pre	�ش� �̸�(Primary Key) ���� ���ڵ尡 �����ϰ� ����Ʈ�� ����
	*	@post	�ش� �̸�(Primary Key) ���ڵ带 ����� ��ɿ� ���� ����
	*	@return	���ڵ� ���� ������ 1, ���н� 0�� ����
	*/
	int Change();

private:
	LinkedListType <T> * i_List;
	int i_Command;
};

// ���� ���� ����
template<typename T>
void InfoChange<T>::Run(LinkedListType<T> * inList)
{
	i_List = inList;
	while (1)
	{
		i_Command = GetCommand();

		switch (i_Command)
		{
		case 1:
			i_List->DisplayAll();
			break;
		case 2:
			this->Add();
			break;
		case 3:
			this->Delete();
			break;
		case 4:
			this->Change();
			break;
		case 0:
			return;
			break;
		default:
			cout << "\t �߸��� �Է��Դϴ�\n";
			break;
		}
	}
	return;
}

// ����ڷκ��� ��� �Է¹޴� �������̽�
template<typename T>
int InfoChange<T>::GetCommand()
{
	string tName = i_List->GetTName();
	int command;
	cout << "\t" << tName << " ����Ʈ ����" << endl;

	cout << "\t   1 : " << tName << " ����Ʈ ��ü ����" << endl;
	cout << "\t   2 : " << tName << " �߰�" << endl;
	cout << "\t   3 : " << tName << " ����" << endl;
	cout << "\t   4 : " << tName << " ����(��������Ʈ ����)" << endl;
	cout << "\t   0 : " << "���� �ϰ� ������" << endl;

	cout << "\t   �Է� ->";
	cin >> command;
	cout << endl;

	return command;
}

// ��� �߰�
template<typename T>
int InfoChange<T>::Add()
{
	T item;
	item.SetRecordFromKB();

	if (!i_List->Add(item))
	{
		cout << "\t-----Error Massage-----\n\t���ڵ带 ���������� �߰����� ���߽��ϴ�.\n\t-----Error Massage-----\n" << endl;
		return 0;
	}
	i_List->DisplayAll();

	return 1;
}

// ��� ����
template<typename T>
int InfoChange<T>::Delete()
{
	T item;
	item.SetNameFromKB();

	if (!i_List->Delete(item))
	{
		cout << "\t-----Error Massage-----\n\t�Է��Ͻ� �̸��� ���� ���ڵ尡 �����ϴ�.\n\t-----Error Massage-----\n";
		return 0;
	}
	i_List->DisplayAll();

	return 1;
}

// ��� ����
template<typename T>
int InfoChange<T>::Change()
{
	i_List->DisplayAll();
	T item;
	cout << "\t������ ���ڵ� �̸��� �Է��ϼ���" << endl;
	item.SetNameFromKB();

	if(i_List->Get(item)) 
	{ // ���� �̸��� item�� ã��
		item.DisplayRecordOnScreen(); // ȭ�鿡 ���
		item.Modify(); // item ����
		if (!i_List->Replace(item))
		{	// ��ü ���н�
			cout << "\t-----Error Massage-----\n\t������ �߸��Ǿ����ϴ�. ���� ���·� ����˴ϴ�.\n\t-----Error Massage-----\n";
			return 0;
		}
		else
		{
			
			return 1;
		}
	}
	else
	{
		cout << "\t-----Error Massage-----\n\t�Է��Ͻ� �̸��� ���� ���ڵ尡 �����ϴ�.\n\t-----Error Massage-----\n";
	}
}



#endif _INFO_CHANGE_H