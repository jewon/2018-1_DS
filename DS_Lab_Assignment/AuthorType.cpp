#include"AuthorType.h"

// 이름 입력받음
void AuthorType::SetNameFromKB()
{
	cout << "\tName : ";
	cin >> m_pName;
}

// 저자명 입력받음
void AuthorType::SetAuthorFromKB()
{
	cout << "\tAuthor : ";
	cin >> m_pAuthor;
}

// 페이지 수 입력받음
void AuthorType::SetPagesFromKB()
{
	cout << "\tPages : ";
	cin >> m_pPages;
}

// 레코드 전체 입력받음
void AuthorType::SetRecordFromKB()
{
	SetNameFromKB();
	SetAuthorFromKB();
	SetPagesFromKB();
}

// 사용자에 의한 레코드 수정
int AuthorType::Modify()
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
			cout << "\t(AuthorType)잘못된 입력입니다\n";
			break;
		}
	}
	return 0;
}

// InfoChange클래스가 접근했을 때 사용자에게 보여지는 화면
void AuthorType::DisplayMenu()
{
	cout << "\n\t" << m_pName << "의 수정할 항목 선택\n";
	cout << "\t1 : 저자 수정\n";
	cout << "\t2 : 페이지 수 수정\n";
	cout << "\t0 : 나가기\n\n";
}

// InfoChange클래스가 접근했을 때 사용자 명령 입력받음
int AuthorType::GetCommand()
{
	DisplayMenu();
	int p_Command;

	cout << "\t선택 ->";
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