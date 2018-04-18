#include"PaperType.h"

// �̸� �Է¹���
void PaperType::SetNameFromKB()
{
	cout << "\tName : ";
	cin >> m_pName;
}

// ���ڸ� �Է¹���
void PaperType::SetAuthorFromKB()
{
	cout << "\tAuthor : ";
	cin >> m_pAuthor;
}

// ������ �� �Է¹���
void PaperType::SetPagesFromKB()
{
	cout << "\tPages : ";
	cin >> m_pPages;
}

// ���ڵ� ��ü �Է¹���
void PaperType::SetRecordFromKB()
{
	SetNameFromKB();
	SetAuthorFromKB();
	SetPagesFromKB();
}

RelationType PaperType::CompareByName(const PaperType & data)
{
	if (this->m_pName.compare(data.m_pName) > 0)
		return GREATER;
	else if (this->m_pName.compare(data.m_pName) < 0)
		return LESS;
	else
		return EQUAL;
}

// ����ڿ� ���� ���ڵ� ����
int PaperType::Modify()
{
	while (1)
	{
		int p_Command = GetCommand();
		switch (p_Command)
		{
		case 1:
			this->SetAuthorFromKB();
			break;
		case 2:
			this->SetPagesFromKB();
			break;
		case 0:
			return 1;
			break;
		default:
			cout << "\t(PaperType)�߸��� �Է��Դϴ�\n";
			break;
		}
	}
	return 0;
}

// InfoChangeŬ������ �������� �� ����ڿ��� �������� ȭ��
void PaperType::DisplayMenu()
{
	cout << "\n\t" << m_pName << "�� ������ �׸� ����\n";
	cout << "\t1 : ���� ����\n";
	cout << "\t2 : ������ �� ����\n";
	cout << "\t0 : ������\n\n";
}

// InfoChangeŬ������ �������� �� ����� ��� �Է¹���
int PaperType::GetCommand()
{
	DisplayMenu();
	int p_Command;

	cout << "\t���� ->";
	cin >> p_Command;

	return p_Command;
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