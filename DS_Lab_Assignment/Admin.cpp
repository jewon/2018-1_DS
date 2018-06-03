#include "Admin.h"

// 부가 기능 실행
void Admin::Run(BinarySearchTree<ConferenceType> * inList)
{
	Root_List = inList; // 루트리스트 가져옴

	// 리스트를 수정할 수 있도록 클래스 만들어 둠
	InfoChange<ConferenceType> ChangeConference;
	InfoChange<PaperType> ChangeSession;
	InfoChange<AuthorType> ChangePaper;

	// 수정할 리스트 포인터를 저장할 변수
	BinarySearchTree<PaperType> * SessionListToChange = NULL;
	BinarySearchTree<AuthorType> * PaperListToChange = NULL;

	while (1)
	{
		// 명령 입력받음
		m_Command = GetCommand();
		switch (m_Command)
		{
		case 1: // 학술대회 내용 수정
			ChangeConference.Run(Root_List);
			break; 
		case 2: // 세션 내용 수정
			SessionListToChange = GetChangeSessionList();
			if(SessionListToChange != NULL)
				ChangeSession.Run(SessionListToChange);
			break;
		case 3: // 논문 내용 수정
			PaperListToChange = GetChangePaperList();
			if(PaperListToChange != NULL)
				ChangePaper.Run(PaperListToChange);
			break;
		//case 4: // 구조 출력
		//	PrintALlStructure();
		//	break;
		case 0: // 프로그램 종료
			return;
			break;
		default:
			cout << "\t잘못된 입력입니다...\n";
			break;
		}
	}

	Root_List = NULL; // 리스트를 훼손하지 않기 위함
}

// 명령 목록 화면에 보여주고, 명령 입력받음
int Admin::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t-------<관리자 메뉴>-------" << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : 학술대회 내용 수정" << endl;
	cout << "\t   2 : 세션 내용 수정" << endl;
	cout << "\t   3 : 논문 내용 수정" << endl;
	//cout << "\t   4 : 데이터 전체 구조 보기" << endl;
	cout << "\t   0 : 메인 메뉴로" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

BinarySearchTree<PaperType> * Admin::GetChangeSessionList()
{
	Root_List->DisplayAllBrief();
	ConferenceType item;
	cout << "\t수정할 세션이 있는 컨퍼런스 이름을 입력하세요" << endl;
	item.SetNameFromKB();

	if (Root_List == NULL)
	{
		cout << "\t-----Error Massage-----\n\t컨퍼런스 리스트가 비어 있습니다. 먼저 컨퍼런스를 추가해주세요.\n\t-----Error Massage-----\n";
		return NULL;
	}

	ConferenceType * pItem = Root_List->GetData(item);
	if (pItem != NULL)
		if (pItem->GetSessionList() != NULL)
			return pItem->GetSessionList();
		else
			return pItem->MakeSessionList();
	else
		cout << "\t-----Error Massage-----\n\t입력하신 이름을 가진 컨퍼런스가 없습니다.\n\t-----Error Massage-----\n";
	return NULL;
}

BinarySearchTree<AuthorType>* Admin::GetChangePaperList()
{
	BinarySearchTree<PaperType> * ChangeSessionList = GetChangeSessionList();
	if (ChangeSessionList->IsEmpty())
	{
		cout << "\t-----Error Massage-----\n\t세션 리스트가 비어 있습니다. 먼저 세션을 추가해주세요.\n\t-----Error Massage-----\n";
		return NULL;
	}
	
	ChangeSessionList->DisplayAllBrief();
	PaperType item;
	cout << "\t수정할 논문이 있는 세션 이름을 입력하세요" << endl;
	item.SetNameFromKB();

	PaperType * pItem = ChangeSessionList->GetData(item);
	if (pItem!=NULL)
		if (pItem->GetPaperList() != NULL)
			return pItem->GetPaperList();
		else
			return pItem->MakePaperList();
	else
		cout << "\t-----Error Massage-----\n\t입력하신 이름을 가진 세션이 없습니다.\n\t-----Error Massage-----\n";
	return NULL;
}

//void Admin::PrintALlStructure()
//{
//	cout << "\nConferencList" << endl;
//	Root_List->DoDisplayAllStructure();
//}
