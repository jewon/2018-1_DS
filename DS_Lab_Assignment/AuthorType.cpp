#include"AuthorType.h"

// �̸� �Է¹���
void AuthorType::SetNameFromKB()
{
	cout << "\tName : ";
	cin >> m_pName;
}

void AuthorType::SetRecordFromKB()
{
	SetNameFromKB();
}

// ����ڿ� ���� ���ڵ� ����
int AuthorType::Modify()
{
	while (1)
	{
		int p_Command = GetCommand();
		switch (p_Command)
		{
		case 0:
			return 1;
			break;
		default:
			cout << "\t(AuthorType)�߸��� �Է��Դϴ�\n";
			break;
		}
	}
	return 0;
}

// InfoChangeŬ������ �������� �� ����ڿ��� �������� ȭ��
void AuthorType::DisplayMenu()
{
	cout << "\n\t" << m_pName << "�� ������ �׸� ����\n";
	cout << "\t0 : ������\n\n";
}

// InfoChangeŬ������ �������� �� ����� ���� �Է¹���
int AuthorType::GetCommand()
{
	DisplayMenu();
	int p_Command;

	cout << "\t���� ->";
	cin >> p_Command;

	return p_Command;
}

// Compare two item types by item id.
bool AuthorType::operator>(AuthorType item)
{
	return (this->GetName()>item.GetName());
}	//return 1 if this.id > data.id, 0 if not.

// Compare two item types by item id.
bool AuthorType::operator<(AuthorType item)
{
	return (this->GetName()<item.GetName());
}	//return 1 if this.id > data.id, 0 if not.

	// Compare two item types by item id.
bool AuthorType::operator==(AuthorType item)
{
	return (this->GetName() == item.GetName());
}	//return 1 if this.id == data.id, 0 if not.