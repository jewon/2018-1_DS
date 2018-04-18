#include"InfoChange.h"

template<typename T>
void InfoChange<T>::Run()
{
	i_Command = GetCommand();

	switch (i_Command)
	{
	case 0:
		i_List.DisplayAll();
	case 1:
		this->Add();
	case 2:
		this->Delete();
	case 3:
		this->Change();
	}
	default:
		cout << "\t �߸��� �Է��Դϴ�\n";
		break;
}

template<typename T>
int InfoChange<T>::GetCommand()
{
	string tName = i_List.GetTName();
	int command;
	cout << tName << " ����Ʈ ����" << endl;

	cout << "\t   0 : " << tNmae << " ����Ʈ ��ü ����";
	cout << "\t   1 : " << tName << " �߰�" << endl;
	cout << "\t   2 : " << tName << " ����" << endl;
	cout << "\t   3 : " << tName << " ����(��������Ʈ ����)" << endl;

	cout << "\t   �Է� ->";
	cin >> command;
	cout << endl;

	return command;
}

template<typename T>
int InfoChange<T>::Add()
{
	T item;
	item.SetRecordFromKB();

	if (!i_List.Add(item))
	{
		cout << "���ڵ带 �߰����� ���߽��ϴ�" << endl;
		return 0;
	}
	i_List.DisplayAll();

	return 1;
}

template<typename T>
int InfoChange<T>::Delete()
{
	T item;
	item.SetNameFromKB();

	if (!i_List.Delete(item))
	{
		cout << "�Է��Ͻ� �̸��� ���� ���ڵ尡 �����ϴ�" << endl;
		return 0;
	}
	i_List.DisplayAll();

	return 1;
}

template<typename T>
int InfoChange<T>::Change()
{
	i_List.DisplayAll();
	T item;
	cout << "������ ���ڵ� �̸��� �Է��ϼ���" << endl;
	item.SetNameFromKB();
	
	Get(item); // ���� �̸��� item�� ã��
	item.DisplayRecordOnScreen(); // ȭ�鿡 ���
	
	item.Modify(); // item ����

	if (!i_List.Replace(item))
	{	// ��ü ���н�
		cout << "������ �߸��Ǿ����ϴ�. ���� ���·� ����˴ϴ�." << endl;
		return 0;
	}
	return 1;
}

