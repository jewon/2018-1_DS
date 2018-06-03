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

//void Admin::PrintALlStructure()
//{
//	cout << "\nConferencList" << endl;
//	Root_List->DoDisplayAllStructure();
//}
