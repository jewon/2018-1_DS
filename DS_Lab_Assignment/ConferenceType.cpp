#include "ConferenceType.h"


// 이름 입력받음
void ConferenceType::SetNameFromKB()
{
	cout << "\tName : ";
	cin >> m_hName;
}

// 개최년월일 입력받음
void ConferenceType::SetDateFromKB()
{
	cout << "\tDate : ";
	cin >> m_hDate;
}

// Paper 리스트 입력받음
void ConferenceType::SetPaperListFromKB()
{
	cout << "\tPaper 리스트를 수정합니다\n";
	if (PaperList==NULL)
		MakePaperList();
	BinarySearchTree<PaperType> temp = *PaperList;
	InfoChange<PaperType> SessionChange;
	SessionChange.Run(&temp);
	SetPaperList(&temp);
}

// 레코드 전체 입력받음
void ConferenceType::SetRecordFromKB()
{
	cout << "\t학술대회 추가\n";
	SetNameFromKB();
	SetDateFromKB();
	cout << "\t-----Messege-----\n\t학술되회가 입력되었습니다\n\tPaper을 추가하시려면 '수정' 메뉴를 이용해주세요\n\t-----Messege-----\n";
}

// 파일로부터 레코드 읽어들임
int ConferenceType::ReadDataFromFile(ifstream& fin)
{
	getline(fin, m_hName);
	getline(fin, m_hDate);
	fin.ignore(2, '\n'); //operator>>는 개행문자를 읽어들이지 않으므로 강제로 무시
	fin.ignore(2, '\n'); //개행문자 1개 무시 (레코드 구분용)
	if (fin.peek() == '\n')
		fin.eof(); //개행문자가 연속 2개 입력되면 입력의 끝으로 인식

	return 1;
};


// 레코드 파일에 씀
int ConferenceType::WriteDataToFile(ofstream& fout)
{
	fout << m_hName << '\n';
	fout << m_hDate << '\n' << '\n'; // 다음 레코드임을 알리기위해 개행문자 연속 삽입

	return 1;
}

// 사용자에 의한 레코드 수정
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
			cout << "\t(ConferenceType)잘못된 입력입니다\n";
			break;
		}
	}
	return 0;
}

// InfoChange클래스가 접근했을 때 사용자에게 보여지는 화면
void ConferenceType::DisplayMenu()
{
	cout << "\n\t" << m_hName << "의 수정할 항목 선택\n";
	cout << "\t1 : 시작년월일\n";
	cout << "\tPaper 리스트의 수정은 Paper 수정 메뉴를 이용해주세요.\n";
	cout << "\t0 : 나가기\n\n";
}

// InfoChange클래스가 접근했을 때 사용자 명령 입력받음
int ConferenceType::GetCommand()
{
	DisplayMenu();
	int c_Command;

	cout << "\t선택 ->";
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

// 대입연산자 오버로딩(내부 리스트 무결성 유지 위해 Paper리스트는 대입하지 않음)
ConferenceType & ConferenceType::operator=(const ConferenceType & c)
{
	m_hName = c.m_hName;		///< 학술대회명
	m_hDate = c.m_hDate;		///< 시작년월일(YYYY.MM.DD)
	PaperList = NULL;	///< Paper 리스트

	return *this;
}