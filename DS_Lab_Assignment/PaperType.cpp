#include "PaperType.h"

// Paper �̸� �Է¹���
void PaperType::SetNameFromKB()
{
	cout << "\tName : ";
	cin >> m_sName;
}

// ������ �� �Է¹���
void PaperType::SetPagesFromKB()
{
	cout << "\tPages : ";
	cin >> m_sPage;
}

// Paper �� Author ����Ʈ�� Author �Է¹޾� �߰�
void PaperType::SetAuthorListFromKB()
{
	cout << "\tAuthor ����Ʈ�� �����մϴ�\n";
	if (AuthorList==NULL)
		MakeAuthorList();
	BinarySearchTree<AuthorType> temp = *AuthorList;
	InfoChange<AuthorType> PaperChange;
	PaperChange.Run(&temp);
	SetAuthorList(&temp);
}

// Paper ���� ��ü  �Է¹���
void PaperType::SetRecordFromKB()
{
	SetNameFromKB();
	SetPagesFromKB();
	cout << "\t-----Messege-----\n\tPaper�� �ԷµǾ����ϴ�\n\tAuthor�� �߰��Ͻ÷��� '����' �޴��� �̿����ּ���\n\t-----Messege-----\n";
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
	cout << "\n\t" << m_sName << "�� ������ �׸� ����\n";
	cout << "\t1 : ������ �� ����\n";
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
	AuthorList = NULL;

	return *this;
}