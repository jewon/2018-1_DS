#include "ConferenceType.h"


// 이름 입력받음
void ConferenceType::SetNameFromKB()
{
	cout << "\tName : ";
	cin >> m_hName;
}


// 개최기관 입력받음
void ConferenceType::SetOrganFromKB()
{
	cout << "\tOrganization : ";
	cin >> m_hOrgan;
}

// 개최년월일 입력받음
void ConferenceType::SetDateFromKB()
{
	cout << "\tDate : ";
	cin >> m_hDate;
}

// 개최횟수 입력받음
void ConferenceType::SetTimesFromKB()
{
	cout << "\tTimes : ";
	cin >> m_hTimes;
}

// 학술대회 약자 입력받음
void ConferenceType::SetSimpleFromKB()
{
	cout << "\tSimplename : ";
	cin >> m_hSimple;
}

// 학술대회 장소 입력받음
void ConferenceType::SetPlaceFromKB()
{
	cout << "\tPlace : ";
	cin >> m_hPlace;
}

// 학술대회 일시 입력받음
void ConferenceType::SetDateTimeFromKB()
{
	cout << "\tDateTime : ";
	cin >> m_hDateTime;
}

// 학술대회 ISBN 입력받음
void ConferenceType::SetISBNFromKB()
{
	cout << "\tISBN : ";
	cin >> m_hISBN;
}

// 세션 리스트 입력받음
void ConferenceType::SetSessionListFromKB()
{
	cout << "\t세션 리스트를 수정합니다\n";
	if (SessionList==NULL)
		MakeSessionList();
	LinkedListType<SessionType> temp = *SessionList;
	InfoChange<SessionType> SessionChange;
	SessionChange.Run(&temp);
	SetSessionList(&temp);
}

// 레코드 전체 입력받음
void ConferenceType::SetRecordFromKB()
{
	cout << "\t학술대회 추가\n";
	SetNameFromKB();
	SetDateFromKB();
	SetTimesFromKB();
	SetOrganFromKB();
	SetSimpleFromKB();
	SetPlaceFromKB();
	SetDateTimeFromKB();
	SetISBNFromKB();
	cout << "\t-----Messege-----\n\t학술되회가 입력되었습니다\n\t세션을 추가하시려면 '수정' 메뉴를 이용해주세요\n\t-----Messege-----\n";
}

// 파일로부터 레코드 읽어들임
int ConferenceType::ReadDataFromFile(ifstream& fin)
{
	getline(fin, m_hName);
	getline(fin, m_hDate);
	fin >> m_hTimes;
	fin.ignore(2, '\n'); //operator>>는 개행문자를 읽어들이지 않으므로 강제로 무시
	getline(fin, m_hOrgan);
	getline(fin, m_hSimple);
	fin.ignore(2, '\n'); //개행문자 1개 무시 (레코드 구분용)
	if (fin.peek() == '\n')
		fin.eof(); //개행문자가 연속 2개 입력되면 입력의 끝으로 인식

	return 1;
};


// 레코드 파일에 씀
int ConferenceType::WriteDataToFile(ofstream& fout)
{
	fout << m_hName << '\n';
	fout << m_hDate << '\n';
	fout << m_hTimes << '\n';
	fout << m_hOrgan << '\n';
	fout << m_hSimple << '\n' << '\n'; // 다음 레코드임을 알리기위해 개행문자 연속 삽입

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
	cout << "\t2 : 개최횟수\n";
	cout << "\t3 : 개최기관명\n";
	cout << "\t4 : 학술대회 약자\n";
	cout << "\t5 : 개최장소\n";
	cout << "\t6 : 개최일시\n";
	cout << "\t세션 리스트의 수정은 세션 수정 메뉴를 이용해주세요.\n";
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

// 대입연산자 오버로딩(내부 리스트 무결성 유지 위해 세션리스트는 대입하지 않음)
ConferenceType & ConferenceType::operator=(const ConferenceType & c)
{
	m_hName = c.m_hName;		///< 학술대회명
	m_hDate = c.m_hDate;		///< 시작년월일(YYYY.MM.DD)
	m_hTimes = c.m_hTimes;		///< 개최횟수
	m_hOrgan = c.m_hOrgan;	///< 개최기관명
	m_hSimple = c.m_hSimple;	///< 학술대회 약자
	m_hPlace = c.m_hPlace;	///< 학술대회 개최장소
	m_hDateTime = c.m_hDateTime;		///< 학술대회 개최일시
	m_hISBN = c.m_hISBN;		///< ISBN
	SessionList = NULL;	///< 세션 리스트

	return *this;
}