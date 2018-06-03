#include "PaperType.h"

// Paper 이름 입력받음
void PaperType::SetNameFromKB()
{
	cout << "\tName : ";
	cin >> m_sName;
}

// 페이지 수 입력받음
void PaperType::SetPagesFromKB()
{
	cout << "\tPages : ";
	cin >> m_sPage;
}

// Paper 내 Author 리스트에 Author 입력받아 추가
void PaperType::SetAuthorListFromKB()
{
	cout << "\tAuthor 리스트를 수정합니다\n";
	if (AuthorList==NULL)
		MakeAuthorList();
	BinarySearchTree<AuthorType> temp = *AuthorList;
	InfoChange<AuthorType> PaperChange;
	PaperChange.Run(&temp);
	SetAuthorList(&temp);
}

// Paper 정보 전체  입력받음
void PaperType::SetRecordFromKB()
{
	SetNameFromKB();
	SetPagesFromKB();
	cout << "\t-----Messege-----\n\tPaper이 입력되었습니다\n\tAuthor을 추가하시려면 '수정' 메뉴를 이용해주세요\n\t-----Messege-----\n";
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
	cout << "\n\t" << m_sName << "의 수정할 항목 선택\n";
	cout << "\t1 : 페이지 수 수정\n";
	cout << "\t0 : 나가기\n\n";
}

// InfoChange클래스가 접근했을 때 사용자 명령 입력받음
int PaperType::GetCommand()
{
	DisplayMenu();
	int c_Command;

	cout << "선택 ->";
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