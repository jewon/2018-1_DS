#include "Admin.h"

void Admin::Run(LinkedListType<ConferenceType> * inList)
{
	Root_List = inList; // ��Ʈ����Ʈ ������

	// �м���ȸ ����Ʈ�� ������ �� �ֵ��� ������ ��
	InfoChange<ConferenceType> ChangeConference;
	InfoChange<SessionType> ChangeSession;
	InfoChange<PaperType> ChangePaper;

	LinkedListType<SessionType> * SessionListToChange = NULL;
	LinkedListType<PaperType> * PaperListToChange = NULL;

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
	cout << "\t-------<���� �޴�>-------" << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : �м���ȸ ���� ����" << endl;
	cout << "\t   2 : ���� ���� ����" << endl;
	cout << "\t   0 : �� ���� ����" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

LinkedListType<SessionType> * Admin::GetChangeSessionList()
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
		return pItem->GetSessionList();
	else
		cout << "\t-----Error Massage-----\n\t�Է��Ͻ� �̸��� ���� ���۷����� �����ϴ�.\n\t-----Error Massage-----\n";
	return NULL;
}

LinkedListType<PaperType>* Admin::GetChangePaperList()
{
	LinkedListType<SessionType> * ChangeSessionList = GetChangeSessionList();
	if (ChangeSessionList == NULL)
	{
		cout << "\t-----Error Massage-----\n\t���� ����Ʈ�� ��� �ֽ��ϴ�. ���� ������ �߰����ּ���.\n\t-----Error Massage-----\n";
		return NULL;
	}
	
	ChangeSessionList->DisplayAllBrief();
	SessionType item;
	item.SetNameFromKB();

	if (ChangeSessionList->GetData(item)!=NULL)
		if (item.GetPaperList() == NULL)
			return item.MakePaperList();
		else
			return item.GetPaperList();
	else
		cout << "\t-----Error Massage-----\n\t�Է��Ͻ� �̸��� ���� ������ �����ϴ�.\n\t-----Error Massage-----\n";
	return NULL;
}
