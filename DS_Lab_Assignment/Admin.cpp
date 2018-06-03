#include "Admin.h"

// �ΰ� ��� ����
void Admin::Run(BinarySearchTree<ConferenceType> * inList)
{
	Root_List = inList; // ��Ʈ����Ʈ ������

	// ����Ʈ�� ������ �� �ֵ��� Ŭ���� ����� ��
	InfoChange<ConferenceType> ChangeConference;
	InfoChange<PaperType> ChangeSession;
	InfoChange<AuthorType> ChangePaper;

	// ������ ����Ʈ �����͸� ������ ����
	BinarySearchTree<PaperType> * PaperListToChange = NULL;
	BinarySearchTree<AuthorType> * AuthorListToChange = NULL;

	while (1)
	{
		// ��� �Է¹���
		m_Command = GetCommand();
		switch (m_Command)
		{
		case 1: // �м���ȸ ���� ����
			ChangeConference.Run(Root_List);
			break; 
		case 2: // Paper ���� ����
			PaperListToChange = GetChangePaperList();
			if(PaperListToChange != NULL)
				ChangeSession.Run(PaperListToChange);
			break;
		case 3: // Author ���� ����
			AuthorListToChange = GetChangeAuthorList();
			if(AuthorListToChange != NULL)
				ChangePaper.Run(AuthorListToChange);
			break;
		case 4: // �����Է�
			FileIn();
			break;
		//case 4: // ���� ���
		//	PrintALlStructure();
		//	break;
		case 0: // ���α׷� ����
			return;
			break;
		default:
			cout << "\t�߸��� �Է��Դϴ�...\n";
			break;
		}
	}

	Root_List = NULL; // ����Ʈ�� �Ѽ����� �ʱ� ����
}

// ��� ��� ȭ�鿡 �����ְ�, ��� �Է¹���
int Admin::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t-------<������ �޴�>-------" << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : �м���ȸ ���� ����" << endl;
	cout << "\t   2 : Paper ���� ����" << endl;
	cout << "\t   3 : Author ���� ����" << endl;
	cout << "\t   4 : �����Է�" << endl;
	//cout << "\t   4 : ������ ��ü ���� ����" << endl;
	cout << "\t   0 : ���� �޴���" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

BinarySearchTree<PaperType> * Admin::GetChangePaperList()
{
	Root_List->DisplayAllBrief();
	ConferenceType item;
	cout << "\t������ Paper�� �ִ� ���۷��� �̸��� �Է��ϼ���" << endl;
	item.SetNameFromKB();

	if (Root_List == NULL)
	{
		cout << "\t-----Error Massage-----\n\t���۷��� ����Ʈ�� ��� �ֽ��ϴ�. ���� ���۷����� �߰����ּ���.\n\t-----Error Massage-----\n";
		return NULL;
	}

	ConferenceType * pItem = Root_List->GetData(item);
	if (pItem != NULL)
		if (pItem->GetPaperList() != NULL)
			return pItem->GetPaperList();
		else
			return pItem->MakePaperList();
	else
		cout << "\t-----Error Massage-----\n\t�Է��Ͻ� �̸��� ���� ���۷����� �����ϴ�.\n\t-----Error Massage-----\n";
	return NULL;
}

BinarySearchTree<AuthorType>* Admin::GetChangeAuthorList()
{
	BinarySearchTree<PaperType> * ChangePaperList = GetChangePaperList();
	if (ChangePaperList->IsEmpty())
	{
		cout << "\t-----Error Massage-----\n\tPaper ����Ʈ�� ��� �ֽ��ϴ�. ���� Paper�� �߰����ּ���.\n\t-----Error Massage-----\n";
		return NULL;
	}
	
	ChangePaperList->DisplayAllBrief();
	PaperType item;
	cout << "\t������ Author�� �ִ� Paper �̸��� �Է��ϼ���" << endl;
	item.SetNameFromKB();

	PaperType * pItem = ChangePaperList->GetData(item);
	if (pItem!=NULL)
		if (pItem->GetAuthorList() != NULL)
			return pItem->GetAuthorList();
		else
			return pItem->MakeAuthorList();
	else
		cout << "\t-----Error Massage-----\n\t�Է��Ͻ� �̸��� ���� Paper�� �����ϴ�.\n\t-----Error Massage-----\n";
	return NULL;
}

void Admin::FileIn()
{
	ifstream fs;
	fs.open("dblp.txt");

	if (!fs.is_open())
	{
		cout << "���� �Է� ����";
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
			cout << "\t �߸��� �Է��Դϴ� : " << temp;
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
