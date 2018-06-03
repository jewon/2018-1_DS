#include "PaperType.h"

// ���� �̸� �Է¹���
void PaperType::SetNameFromKB()
{
	cout << "\tName : ";
	cin >> m_sName;
}

// ���� �� �� ����Ʈ�� �� �Է¹޾� �߰�
void PaperType::SetPaperListFromKB()
{
	cout << "\t�� ����Ʈ�� �����մϴ�\n";
	if (PaperList==NULL)
		MakePaperList();
	BinarySearchTree<AuthorType> temp = *PaperList;
	InfoChange<AuthorType> PaperChange;
	PaperChange.Run(&temp);
	SetPaperList(&temp);
}

// ���� ���� ��ü  �Է¹���
void PaperType::SetRecordFromKB()
{
	SetNameFromKB();
	cout << "\t-----Messege-----\n\t������ �ԷµǾ����ϴ�\n\t���� �߰��Ͻ÷��� '����' �޴��� �̿����ּ���\n\t-----Messege-----\n";
}

// ����ڿ� ���� ���ڵ� ����
int PaperType::Modify()
{
	while (1)
	{
		int c_Command = GetCommand();
		switch (c_Command)
		{
		case 0:
			return 1;
			break;
		default:
			cout << "(PaperType)�߸��� �Է��Դϴ�\n";
			break;
		}
	}
	return 0;
}

// InfoChangeŬ������ �������� �� ����ڿ��� �������� ȭ��
void PaperType::DisplayMenu()
{
	cout << "\n\t" << m_sName << "�� ������ �׸� ����\n";
	cout << "\t������ ������ �� �ִ� �׸��� �����ϴ�.\n\t�̸��� �����Ͻ÷��� ���� �� �������ּ���.\n";
	cout << "\t0 : ������\n\n";
}

// InfoChangeŬ������ �������� �� ����� ��� �Է¹���
int PaperType::GetCommand()
{
	DisplayMenu();
	int c_Command;

	cout << "���� ->";
	cin >> c_Command;

	return c_Command;
}

// Compare two item types by item id.
bool PaperType::operator>(PaperType item)
{
	return (this->GetName()>item.GetName());
}	//return 1 if this.id > data.id, 0 if not.

	// Compare two item types by item id.
bool PaperType::operator<(PaperType item)
{
	return (this->GetName()<item.GetName());
}	//return 1 if this.id > data.id, 0 if not.

	// Compare two item types by item id.
bool PaperType::operator==(PaperType item)
{
	return (this->GetName() == item.GetName());
}	//return 1 if this.id == data.id, 0 if not.

PaperType & PaperType::operator=(const PaperType & c)
{
	m_sName = c.m_sName;
	PaperList = NULL;

	return *this;
}