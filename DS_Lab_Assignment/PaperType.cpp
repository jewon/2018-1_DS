#include"PaperType.h"

// 이름 입력받음
void PaperType::SetNameFromKB()
{
	cout << "\tName : ";
	cin >> m_pName;
}

// 저자명 입력받음
void PaperType::SetAuthorFromKB()
{
	cout << "\tAuthor : ";
	cin >> m_pAuthor;
}

// 페이지 수 입력받음
void PaperType::SetPagesFromKB()
{
	cout << "\tPages : ";
	cin >> m_pPages;
}

// 레코드 전체 입력받음
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

// 사용자에 의한 레코드 수정
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
			cout << "\t(PaperType)잘못된 입력입니다\n";
			break;
		}
	}
	return 0;
}

// InfoChange클래스가 접근했을 때 사용자에게 보여지는 화면
void PaperType::DisplayMenu()
{
	cout << "\n\t" << m_pName << "의 수정할 항목 선택\n";
	cout << "\t1 : 저자 수정\n";
	cout << "\t2 : 페이지 수 수정\n";
	cout << "\t0 : 나가기\n\n";
}

// InfoChange클래스가 접근했을 때 사용자 명령 입력받음
int PaperType::GetCommand()
{
	DisplayMenu();
	int p_Command;

	cout << "\t선택 ->";
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