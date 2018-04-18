#include "SessionType.h"

// ���� �̸� �Է¹���
void SessionType::SetNameFromKB()
{
	cout << "\tName : ";
	cin >> m_sName;
}

// ���� �� �� ����Ʈ�� �� �Է¹޾� �߰�
void SessionType::SetPaperListFromKB()
{
	InfoChange<PaperType> PaperChange;
	PaperChange.Run(&PaperList);
	PaperChange.~InfoChange();
}

// ���� ���� ��ü  �Է¹���
void SessionType::SetRecordFromKB()
{
	SetNameFromKB();
	cout << "\t-----Messege-----\n\t������ �ԷµǾ����ϴ�\n\t���� �߰��Ͻ÷��� '����' �޴��� �̿����ּ���\n\t-----Messege-----\n";
}

// ����ڿ� ���� ���ڵ� ����
int SessionType::Modify()
{
	while (1)
	{
		int c_Command = GetCommand();
		switch (c_Command)
		{
		case 1:
			this->SetPaperListFromKB();
			break;
		case 0:
			return 1;
			break;
		default:
			cout << "(SessionType)�߸��� �Է��Դϴ�\n";
			break;
		}
	}
	return 0;
}

// InfoChangeŬ������ �������� �� ����ڿ��� �������� ȭ��
void SessionType::DisplayMenu()
{
	cout << "\n\t" << m_sName << "�� ������ �׸� ����\n";
	cout << "\t1 : �� ����Ʈ ����\n";
	cout << "\t0 : ������\n\n";
}

// InfoChangeŬ������ �������� �� ����� ��� �Է¹���
int SessionType::GetCommand()
{
	DisplayMenu();
	int c_Command;

	cout << "���� ->";
	cin >> c_Command;

	return c_Command;
}

// Compare two item types by item id.
bool SessionType::operator>(SessionType item)
{
	return (this->GetName()>item.GetName());
}	//return 1 if this.id > data.id, 0 if not.

	// Compare two item types by item id.
bool SessionType::operator<(SessionType item)
{
	return (this->GetName()<item.GetName());
}	//return 1 if this.id > data.id, 0 if not.

	// Compare two item types by item id.
bool SessionType::operator==(SessionType item)
{
	return (this->GetName() == item.GetName());
}	//return 1 if this.id == data.id, 0 if not.