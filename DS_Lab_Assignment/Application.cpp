#include "Application.h"
// ���α׷� ����
void Application::Run()
{
	// �м���ȸ ����Ʈ�� ������ �� �ֵ��� ������ ��
	InfoChange<ConferenceType> ChangeConference;

	// �ΰ���� ������ ���� Ŭ���� �ε�


	while (1)
	{
		// ��� �Է¹���
		m_Command = GetCommand();
		switch (m_Command)
		{
		case 1: // �м���ȸ ���� ����
			ChangeConference.Run(&m_List);
			break;
		case 2: // �˻� ���
			cout << "\t Maybe Unstable... Still Developing\n\n";
			MoreFeatures();
			break;
		case 0: // ���α׷� ����
			return;
			break;
		default:
			cout << "\t�߸��� �Է��Դϴ�...\n";
			break;
		}
	}
}

// ��� ��� ȭ�鿡 �����ְ�, ��� �Է¹���
int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : ���� ���� (������)" << endl;
	cout << "\t   2 : Ž�� (�����)" << endl;
	cout << "\t   0 : ����" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

// �ΰ���� ���� (���� ������ ���� �Ϻθ� ����)
void Application::MoreFeatures()
{
	while (1)
	{
		// ��� �Է¹���
		f_Command = MoreFeaturesGetcommand();
		switch (f_Command)
		{
		case 1: // �� �˻�
			PaperSearch();
			break;
		case 2: // �м���ȸ �Ѵ�������
			m_List.DisplayAllBrief();
			break;
		case 0: // ���α׷� ����
			return;
			break;
		default:
			cout << "\t�߸��� �Է��Դϴ�...\n";
			break;
		}
	}
}

// �ΰ���� ������ ���� �޴� ��� �� ��� �Է�
int Application::MoreFeaturesGetcommand()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : ��ü �м���ȸ���� �� �˻�" << endl;
	cout << "\t   2 : ��ü �м���ȸ �Ѵ�������" << endl;
	cout << "\t   0 : ����" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

// ��ü ����Ʈ���� �� �˻��ϴ� �޴�
void Application::PaperSearch()
{
	string word;
	cout << "\tã���� �ϴ� Ű���带 �Է��ϼ���\n\t";
	cin >> word;

	LinkedListType<PaperType> FoundPaperList;

	if (m_List.GetLength() == 0)
		return;

	ConferenceType dummyConf;
	DoublyIterator<ConferenceType> iter(m_List);

	if (iter.NextNotNull())
	{
		dummyConf = iter.Next();
		FoundPaperList = dummyConf.SearchPaper(word);
	}

	while(iter.NextNotNull())
	{
		dummyConf = iter.Next();
		FoundPaperList.Connect(&dummyConf.SearchPaper(word));
	}

	FoundPaperList.DisplayAll();
	return;
}