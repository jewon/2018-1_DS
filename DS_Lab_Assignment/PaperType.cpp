#include "PaperType.h"

// 세션 이름 입력받음
void PaperType::SetNameFromKB()
{
	cout << "\tName : ";
	cin >> m_sName;
}

// 세션 내 논문 리스트에 논문 입력받아 추가
void PaperType::SetPaperListFromKB()
{
	cout << "\t논문 리스트를 수정합니다\n";
	if (PaperList==NULL)
		MakePaperList();
	BinarySearchTree<AuthorType> temp = *PaperList;
	InfoChange<AuthorType> PaperChange;
	PaperChange.Run(&temp);
	SetPaperList(&temp);
}

// 세션 정보 전체  입력받음
void PaperType::SetRecordFromKB()
{
	SetNameFromKB();
	cout << "\t-----Messege-----\n\t세션이 입력되었습니다\n\t논문을 추가하시려면 '수정' 메뉴를 이용해주세요\n\t-----Messege-----\n";
}

// 사용자에 의한 레코드 수정
int PaperType::Modify()
{
	while (1)
	{
		int c_Command = GetCommand();
		switch (c_Command)
		{
		case 0:
			return 1;
			break;
		default:
			cout << "(PaperType)잘못된 입력입니다\n";
			break;
		}
	}
	return 0;
}

// InfoChange클래스가 접근했을 때 사용자에게 보여지는 화면
void PaperType::DisplayMenu()
{
	cout << "\n\t" << m_sName << "의 수정할 항목 선택\n";
	cout << "\t세션은 수정할 수 있는 항목이 없습니다.\n\t이름을 수정하시려면 삭제 후 생성해주세요.\n";
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
	PaperList = NULL;

	return *this;
}