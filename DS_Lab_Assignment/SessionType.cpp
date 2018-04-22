#include "SessionType.h"

// 세션 이름 입력받음
void SessionType::SetNameFromKB()
{
	cout << "\tName : ";
	cin >> m_sName;
}

// 세션 내 논문 리스트에 논문 입력받아 추가
void SessionType::SetPaperListFromKB()
{
	cout << "\t논문 리스트를 수정합니다\n";
	if (PaperList==NULL)
		MakePaperList();
	LinkedListType<PaperType> temp = *PaperList;
	InfoChange<PaperType> PaperChange;
	PaperChange.Run(&temp);
	SetPaperList(&temp);
}

// 세션 정보 전체  입력받음
void SessionType::SetRecordFromKB()
{
	SetNameFromKB();
	cout << "\t-----Messege-----\n\t세션이 입력되었습니다\n\t논문을 추가하시려면 '수정' 메뉴를 이용해주세요\n\t-----Messege-----\n";
}

// 사용자에 의한 레코드 수정
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
			cout << "(SessionType)잘못된 입력입니다\n";
			break;
		}
	}
	return 0;
}

// InfoChange클래스가 접근했을 때 사용자에게 보여지는 화면
void SessionType::DisplayMenu()
{
	cout << "\n\t" << m_sName << "의 수정할 항목 선택\n";
	cout << "\t1 : 논문 리스트 수정\n";
	cout << "\t0 : 나가기\n\n";
}

// InfoChange클래스가 접근했을 때 사용자 명령 입력받음
int SessionType::GetCommand()
{
	DisplayMenu();
	int c_Command;

	cout << "선택 ->";
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
/*
SessionType & SessionType::operator=(const SessionType & c)
{
	m_sName = c.m_sName;
	return *this;
}
*/