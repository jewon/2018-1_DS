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
	BinarySearchTree<PaperType> * PaperListToChange = NULL;
	BinarySearchTree<AuthorType> * AuthorListToChange = NULL;

	while (1)
	{
		// 명령 입력받음
		m_Command = GetCommand();
		switch (m_Command)
		{
		case 1: // 학술대회 내용 수정
			ChangeConference.Run(Root_List);
			break; 
		case 2: // Paper 내용 수정
			PaperListToChange = GetChangePaperList();
			if(PaperListToChange != NULL)
				ChangeSession.Run(PaperListToChange);
			break;
		case 3: // Author 내용 수정
			AuthorListToChange = GetChangeAuthorList();
			if(AuthorListToChange != NULL)
				ChangePaper.Run(AuthorListToChange);
			break;
		case 4: // 파일입력
			FileIn();
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
	cout << "\t   2 : Paper 내용 수정" << endl;
	cout << "\t   3 : Author 내용 수정" << endl;
	cout << "\t   4 : 파일입력" << endl;
	//cout << "\t   4 : 데이터 전체 구조 보기" << endl;
	cout << "\t   0 : 메인 메뉴로" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

BinarySearchTree<PaperType> * Admin::GetChangePaperList()
{
	Root_List->DisplayAllBrief();
	ConferenceType item;
	cout << "\t수정할 Paper이 있는 컨퍼런스 이름을 입력하세요" << endl;
	item.SetNameFromKB();

	if (Root_List == NULL)
	{
		cout << "\t-----Error Massage-----\n\t컨퍼런스 리스트가 비어 있습니다. 먼저 컨퍼런스를 추가해주세요.\n\t-----Error Massage-----\n";
		return NULL;
	}

	ConferenceType * pItem = Root_List->GetData(item);
	if (pItem != NULL)
		if (pItem->GetPaperList() != NULL)
			return pItem->GetPaperList();
		else
			return pItem->MakePaperList();
	else
		cout << "\t-----Error Massage-----\n\t입력하신 이름을 가진 컨퍼런스가 없습니다.\n\t-----Error Massage-----\n";
	return NULL;
}

BinarySearchTree<AuthorType>* Admin::GetChangeAuthorList()
{
	BinarySearchTree<PaperType> * ChangePaperList = GetChangePaperList();
	if (ChangePaperList->IsEmpty())
	{
		cout << "\t-----Error Massage-----\n\tPaper 리스트가 비어 있습니다. 먼저 Paper을 추가해주세요.\n\t-----Error Massage-----\n";
		return NULL;
	}
	
	ChangePaperList->DisplayAllBrief();
	PaperType item;
	cout << "\t수정할 Author이 있는 Paper 이름을 입력하세요" << endl;
	item.SetNameFromKB();

	PaperType * pItem = ChangePaperList->GetData(item);
	if (pItem!=NULL)
		if (pItem->GetAuthorList() != NULL)
			return pItem->GetAuthorList();
		else
			return pItem->MakeAuthorList();
	else
		cout << "\t-----Error Massage-----\n\t입력하신 이름을 가진 Paper이 없습니다.\n\t-----Error Massage-----\n";
	return NULL;
}

void Admin::FileIn()
{
	ifstream fs;
	fs.open("dblp.txt");

	if (!fs.is_open())
	{
		cout << "파일 입력 오류";
		return;
	}

	char temp[100];
	BinarySearchTree<ConferenceType> * cl = new BinarySearchTree<ConferenceType>;
	ConferenceType c;
	PaperType p;
	AuthorType a;

	while (1)
	{
		fs >> temp;
		if (temp[0] == 'c')
			break;
	}

	while (!fs.eof())
	{
		if (temp[0] == '\n')
		{
			fs.ignore(100, '\n');
			continue;
		}

		if (temp[0] == 'c')
		{
			fs >> temp;
			c.SetName(temp);
			fs >> temp;
			c.SetDate(temp);
			fs.ignore(100, '\n');
			cl->Add(c);
			cl->GetData(c)->MakePaperList();
		}

		else if (temp[0] == 'p')
		{
			fs >> temp;
			p.SetName(temp);
			fs >> temp;
			p.SetPage(temp);
			cl->GetData(c)->GetPaperList()->Add(p);
			cl->GetData(c)->GetPaperList()->GetData(p)->MakeAuthorList();
			fs.ignore(100, '\n');
		}

		else if (temp[0] == 'a')
		{
			while (1)
			{
				fs >> temp;
				if (fs.peek() == '\n')
				{
					fs.ignore(100, '\n');
					break;
				}
				a.SetName(temp);
				cl->GetData(c)->GetPaperList()->GetData(p)->GetAuthorList()->Add(a);
			}
		}
		else
		{
			cout << "\t 잘못된 입력입니다 : " << temp;
			return;
		}
		fs >> temp;
	}
	Root_List = cl;
}

int Admin::ReadDataFromFile(ifstream & fin)
{
	return 0;
}

//void Admin::PrintALlStructure()
//{
//	cout << "\nConferencList" << endl;
//	Root_List->DoDisplayAllStructure();
//}
