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
	BinarySearchTree<PaperType> * SessionListToChange = NULL;
	BinarySearchTree<AuthorType> * PaperListToChange = NULL;

	while (1)
	{
		// ��� �Է¹���
		m_Command = GetCommand();
		switch (m_Command)
		{
		case 1: // �м���ȸ ���� ����
			ChangeConference.Run(Root_List);
			break; 
		case 2: // ���� ���� ����
			SessionListToChange = GetChangeSessionList();
			if(SessionListToChange != NULL)
				ChangeSession.Run(SessionListToChange);
			break;
		case 3: // �� ���� ����
			PaperListToChange = GetChangePaperList();
			if(PaperListToChange != NULL)
				ChangePaper.Run(PaperListToChange);
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
	cout << "\t   2 : ���� ���� ����" << endl;
	cout << "\t   3 : �� ���� ����" << endl;
	//cout << "\t   4 : ������ ��ü ���� ����" << endl;
	cout << "\t   0 : ���� �޴���" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

BinarySearchTree<PaperType> * Admin::GetChangeSessionList()
{
	Root_List->DisplayAllBrief();
	ConferenceType item;
	cout << "\t������ ������ �ִ� ���۷��� �̸��� �Է��ϼ���" << endl;
	item.SetNameFromKB();

	if (Root_List == NULL)
	{
		cout << "\t-----Error Massage-----\n\t���۷��� ����Ʈ�� ��� �ֽ��ϴ�. ���� ���۷����� �߰����ּ���.\n\t-----Error Massage-----\n";
		return NULL;
	}

	ConferenceType * pItem = Root_List->GetData(item);
	if (pItem != NULL)
		if (pItem->GetSessionList() != NULL)
			return pItem->GetSessionList();
		else
			return pItem->MakeSessionList();
	else
		cout << "\t-----Error Massage-----\n\t�Է��Ͻ� �̸��� ���� ���۷����� �����ϴ�.\n\t-----Error Massage-----\n";
	return NULL;
}

BinarySearchTree<AuthorType>* Admin::GetChangePaperList()
{
	BinarySearchTree<PaperType> * ChangeSessionList = GetChangeSessionList();
	if (ChangeSessionList->IsEmpty())
	{
		cout << "\t-----Error Massage-----\n\t���� ����Ʈ�� ��� �ֽ��ϴ�. ���� ������ �߰����ּ���.\n\t-----Error Massage-----\n";
		return NULL;
	}
	
	ChangeSessionList->DisplayAllBrief();
	PaperType item;
	cout << "\t������ ���� �ִ� ���� �̸��� �Է��ϼ���" << endl;
	item.SetNameFromKB();

	PaperType * pItem = ChangeSessionList->GetData(item);
	if (pItem!=NULL)
		if (pItem->GetPaperList() != NULL)
			return pItem->GetPaperList();
		else
			return pItem->MakePaperList();
	else
		cout << "\t-----Error Massage-----\n\t�Է��Ͻ� �̸��� ���� ������ �����ϴ�.\n\t-----Error Massage-----\n";
	return NULL;
}

//void Admin::PrintALlStructure()
//{
//	cout << "\nConferencList" << endl;
//	Root_List->DoDisplayAllStructure();
//}
