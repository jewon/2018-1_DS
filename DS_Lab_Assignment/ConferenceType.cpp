#include "ConferenceType.h"


// �̸� �Է¹���
void ConferenceType::SetNameFromKB()
{
	cout << "\tName : ";
	cin >> m_hName;
}

// ���ֳ���� �Է¹���
void ConferenceType::SetDateFromKB()
{
	cout << "\tDate : ";
	cin >> m_hDate;
}

// Paper ����Ʈ �Է¹���
void ConferenceType::SetPaperListFromKB()
{
	cout << "\tPaper ����Ʈ�� �����մϴ�\n";
	if (PaperList==NULL)
		MakePaperList();
	BinarySearchTree<PaperType> temp = *PaperList;
	InfoChange<PaperType> SessionChange;
	SessionChange.Run(&temp);
	SetPaperList(&temp);
}

// ���ڵ� ��ü �Է¹���
void ConferenceType::SetRecordFromKB()
{
	cout << "\t�м���ȸ �߰�\n";
	SetNameFromKB();
	SetDateFromKB();
	cout << "\t-----Messege-----\n\t�м���ȸ�� �ԷµǾ����ϴ�\n\tPaper�� �߰��Ͻ÷��� '����' �޴��� �̿����ּ���\n\t-----Messege-----\n";
}

// ���Ϸκ��� ���ڵ� �о����
int ConferenceType::ReadDataFromFile(ifstream& fin)
{
	getline(fin, m_hName);
	getline(fin, m_hDate);
	fin.ignore(2, '\n'); //operator>>�� ���๮�ڸ� �о������ �����Ƿ� ������ ����
	fin.ignore(2, '\n'); //���๮�� 1�� ���� (���ڵ� ���п�)
	if (fin.peek() == '\n')
		fin.eof(); //���๮�ڰ� ���� 2�� �ԷµǸ� �Է��� ������ �ν�

	return 1;
};


// ���ڵ� ���Ͽ� ��
int ConferenceType::WriteDataToFile(ofstream& fout)
{
	fout << m_hName << '\n';
	fout << m_hDate << '\n' << '\n'; // ���� ���ڵ����� �˸������� ���๮�� ���� ����

	return 1;
}

// ����ڿ� ���� ���ڵ� ����
int ConferenceType::Modify()
{
	while (1)
	{
		int c_Command = GetCommand();
		switch (c_Command)
		{
		case 1:
			this->SetDateFromKB();
			break;
		case 0:
			return 1;
			break;
		default:
			cout << "\t(ConferenceType)�߸��� �Է��Դϴ�\n";
			break;
		}
	}
	return 0;
}

// InfoChangeŬ������ �������� �� ����ڿ��� �������� ȭ��
void ConferenceType::DisplayMenu()
{
	cout << "\n\t" << m_hName << "�� ������ �׸� ����\n";
	cout << "\t1 : ���۳����\n";
	cout << "\tPaper ����Ʈ�� ������ Paper ���� �޴��� �̿����ּ���.\n";
	cout << "\t0 : ������\n\n";
}

// InfoChangeŬ������ �������� �� ����� ��� �Է¹���
int ConferenceType::GetCommand()
{
	DisplayMenu();
	int c_Command;

	cout << "\t���� ->";
	cin >> c_Command;

	return c_Command;
}

// Compare two item types by item id.
bool ConferenceType::operator>(ConferenceType item)
{
	return (this->GetName()>item.GetName());
}	//return 1 if this.id > data.id, 0 if not.

	// Compare two item types by item id.
bool ConferenceType::operator<(ConferenceType item)
{
	return (this->GetName()<item.GetName());
}	//return 1 if this.id > data.id, 0 if not.

	// Compare two item types by item id.
bool ConferenceType::operator==(ConferenceType item)
{
	return (this->GetName() == item.GetName());
}	//return 1 if this.id == data.id, 0 if not.

// ���Կ����� �����ε�(���� ����Ʈ ���Ἲ ���� ���� Paper����Ʈ�� �������� ����)
ConferenceType & ConferenceType::operator=(const ConferenceType & c)
{
	m_hName = c.m_hName;		///< �м���ȸ��
	m_hDate = c.m_hDate;		///< ���۳����(YYYY.MM.DD)
	PaperList = NULL;	///< Paper ����Ʈ

	return *this;
}