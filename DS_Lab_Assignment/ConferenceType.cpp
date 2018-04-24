#include "ConferenceType.h"


// �̸� �Է¹���
void ConferenceType::SetNameFromKB()
{
	cout << "\tName : ";
	cin >> m_hName;
}


// ���ֱ�� �Է¹���
void ConferenceType::SetOrganFromKB()
{
	cout << "\tOrganization : ";
	cin >> m_hOrgan;
}

// ���ֳ���� �Է¹���
void ConferenceType::SetDateFromKB()
{
	cout << "\tDate : ";
	cin >> m_hDate;
}

// ����Ƚ�� �Է¹���
void ConferenceType::SetTimesFromKB()
{
	cout << "\tTimes : ";
	cin >> m_hTimes;
}

// �м���ȸ ���� �Է¹���
void ConferenceType::SetSimpleFromKB()
{
	cout << "\tSimplename : ";
	cin >> m_hSimple;
}

// �м���ȸ ��� �Է¹���
void ConferenceType::SetPlaceFromKB()
{
	cout << "\tPlace : ";
	cin >> m_hPlace;
}

// �м���ȸ �Ͻ� �Է¹���
void ConferenceType::SetDateTimeFromKB()
{
	cout << "\tDateTime : ";
	cin >> m_hDateTime;
}

// �м���ȸ ISBN �Է¹���
void ConferenceType::SetISBNFromKB()
{
	cout << "\tISBN : ";
	cin >> m_hISBN;
}

// ���� ����Ʈ �Է¹���
void ConferenceType::SetSessionListFromKB()
{
	cout << "\t���� ����Ʈ�� �����մϴ�\n";
	if (SessionList==NULL)
		MakeSessionList();
	LinkedListType<SessionType> temp = *SessionList;
	InfoChange<SessionType> SessionChange;
	SessionChange.Run(&temp);
	SetSessionList(&temp);
}

// ���ڵ� ��ü �Է¹���
void ConferenceType::SetRecordFromKB()
{
	cout << "\t�м���ȸ �߰�\n";
	SetNameFromKB();
	SetDateFromKB();
	SetTimesFromKB();
	SetOrganFromKB();
	SetSimpleFromKB();
	SetPlaceFromKB();
	SetDateTimeFromKB();
	SetISBNFromKB();
	cout << "\t-----Messege-----\n\t�м���ȸ�� �ԷµǾ����ϴ�\n\t������ �߰��Ͻ÷��� '����' �޴��� �̿����ּ���\n\t-----Messege-----\n";
}

// ���Ϸκ��� ���ڵ� �о����
int ConferenceType::ReadDataFromFile(ifstream& fin)
{
	getline(fin, m_hName);
	getline(fin, m_hDate);
	fin >> m_hTimes;
	fin.ignore(2, '\n'); //operator>>�� ���๮�ڸ� �о������ �����Ƿ� ������ ����
	getline(fin, m_hOrgan);
	getline(fin, m_hSimple);
	fin.ignore(2, '\n'); //���๮�� 1�� ���� (���ڵ� ���п�)
	if (fin.peek() == '\n')
		fin.eof(); //���๮�ڰ� ���� 2�� �ԷµǸ� �Է��� ������ �ν�

	return 1;
};


// ���ڵ� ���Ͽ� ��
int ConferenceType::WriteDataToFile(ofstream& fout)
{
	fout << m_hName << '\n';
	fout << m_hDate << '\n';
	fout << m_hTimes << '\n';
	fout << m_hOrgan << '\n';
	fout << m_hSimple << '\n' << '\n'; // ���� ���ڵ����� �˸������� ���๮�� ���� ����

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
		case 2:
			this->SetTimesFromKB();
			break;
		case 3:
			this->SetOrganFromKB();
			break;
		case 4:
			this->SetSimpleFromKB();
			break;
		case 5:
			this->SetPlaceFromKB();
			break;
		case 6:
			this->SetDateTimeFromKB();
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
	cout << "\t2 : ����Ƚ��\n";
	cout << "\t3 : ���ֱ����\n";
	cout << "\t4 : �м���ȸ ����\n";
	cout << "\t5 : �������\n";
	cout << "\t6 : �����Ͻ�\n";
	cout << "\t���� ����Ʈ�� ������ ���� ���� �޴��� �̿����ּ���.\n";
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

// ���Կ����� �����ε�(���� ����Ʈ ���Ἲ ���� ���� ���Ǹ���Ʈ�� �������� ����)
ConferenceType & ConferenceType::operator=(const ConferenceType & c)
{
	m_hName = c.m_hName;		///< �м���ȸ��
	m_hDate = c.m_hDate;		///< ���۳����(YYYY.MM.DD)
	m_hTimes = c.m_hTimes;		///< ����Ƚ��
	m_hOrgan = c.m_hOrgan;	///< ���ֱ����
	m_hSimple = c.m_hSimple;	///< �м���ȸ ����
	m_hPlace = c.m_hPlace;	///< �м���ȸ �������
	m_hDateTime = c.m_hDateTime;		///< �м���ȸ �����Ͻ�
	m_hISBN = c.m_hISBN;		///< ISBN
	SessionList = NULL;	///< ���� ����Ʈ

	return *this;
}