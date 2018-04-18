#include "Application.h"

// ���� ���� �ڵ��Դϴ�. (������)
/*
void Application::Run()
{
	while (1)
	{
		m_Command = GetCommand();

		switch (m_Command)
		{
		case 1:		// ���ڵ带 �Է¹޾� �߰��Ѵ�
			AddConference();
			break;
		case 2:		// ���ڵ� id�� �Է¹޾� �ش� ���ڵ尡 ������ �����Ѵ�
			DeleteConference();
			break;
		case 3:		// ���ڵ带 �Է¹޾� ������ �ٲ۴�
			ReplaceConference();
			break;
		case 4:		// ���ڵ� id�� �Է¹޾� �ش� ���ڵ尡 ������ ����Ѵ�
			RetrieveByName();
			break;
		case 5 :	// ��� ���ڵ� ������ ����� ����ڰ� ��� �ڼ��� ����Ѵ�
			GetConferenceInfo();
			break;
		case 6:		// ��� ���ڵ带 ����Ѵ�
			DisplayAllConferences();
			break;
		case 7:		// ���Ϸκ��� ���ڵ��� �о�´�
			ReadDataFromFile();
			break;
		case 8:		// ���ڵ带 ���Ͽ� ����
			WriteDataToFile();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}*/

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
		/*case 3:		// ���Ϸκ��� ���ڵ��� �о�´�
			ReadDataFromFile();
			break;
		case 4:		// ���ڵ带 ���Ͽ� ����
			WriteDataToFile();
			break;*/
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
	cout << "\t   1 : ���� ����" << endl;
	cout << "\t   2 : �˻�" << endl;
	//cout << "\t   3 : ���� �б�" << endl;
	//cout << "\t   4 : ���� ���� " << endl;
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
	//cout << "\t   3 : ���� �б�" << endl;
	//cout << "\t   4 : ���� ���� " << endl;
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


// �Ʒ��� ���� ���� �ҽ��Դϴ�.

/*
// ����Ʈ�� ���ο� ���ڵ� �߰�
int Application::AddConference()
{
	// �Է¹��� ���ڵ带 ����Ʈ�� add, ����Ʈ�� full�� ���� add���� �ʰ� 0�� ����
	if (m_List.IsFull())
	{
		cout << "	List is full" << endl;
		return 0;
	}

	ConferenceType item;

	item.SetRecordFromKB();
	if (m_List.Add(item) < 0)
	{
		cout << "	Add Error!" << endl;
		return 0;
	}
	else
	{
		// ���� list ���
		DisplayAllConferencesSimple();
		return 1;
	}
}

// �̸��� �Է¹޾� ���� �̸��� ���� ���ڵ带 ������
int Application::DeleteConference()
{
	if (m_List.IsEmpty())
	{
		cout << "List is Empty" << endl;
		return 0;
	}

	ConferenceType item;
	item.SetNameFromKB();

	if (m_List.Delete(item) > 0)
	{ //�Ȱ��� �̸� �����͸� ����� �ȵ�
		DisplayAllConferencesSimple();
		return 1;
	}
	else
		return 0;
}

// ����ڷκ��� ���ڵ� �Է¹޾� �̸� ���� ���ڵ� ��ü��
int Application::ReplaceConference()
{
	if (m_List.IsEmpty())
	{
		cout << "List is Empty" << endl;
		return 0;
	}

	ConferenceType item;
	item.SetRecordFromKB();

	if (m_List.Replace(item) > 0)
	{
		DisplayAllConferencesSimple();
		return 1;
	}
	else
		return 0;
}

// ����ڷκ��� �̸� �Է¹޾� �ش� �̸����� ���ڵ� ���
int Application::RetrieveByName()
{
	if (m_List.IsEmpty())
	{
		cout << "List is Empty" << endl;
		return 0;
	}

	ConferenceType item;
	item.SetNameFromKB();

	if (m_List.Display(item) > 0)
		return 1;
	else 
		return 0;
}

// ��� ���ڵ� ������ ����� ����ڷκ��� �Է¹޾� �ش� ���ڵ� �ڼ��� ���
void Application::GetConferenceInfo()
{
	DisplayAllConferencesSimple(); // ������� ���
	int input = 0;
	cout << "Input Conference Number : ";
	cin >> input; // ����� ��ȣ �Է¹��� (��ȣ�� �迭��ȣ + 1)
	while (1)
	{
		if (m_List.Display(input - 1)) // ��� ������
			break;
		else
		{ // ��� ���н�
			cout << "Wrong Input. Input Again : ";
			cin >> input; // �ٽ� �Է¹޾� ���
		}
	}
}

// ��� ���ڵ� �����ϰ� ���
void Application::DisplayAllConferencesSimple()
{
	ConferenceType data;

	cout << "\n\tCurrent list" << endl;

	// list�� ��� �����͸� ȭ�鿡 ���
	m_List.ResetList();
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	while (curIndex < length && curIndex != -1)
	{
		cout << "\t" << curIndex + 1 << " : ";
		data.DisplaySimpleOnScreen();
		curIndex = m_List.GetNextItem(data);
	}
}

// ��� ���ڵ� ���
void Application::DisplayAllConferences()
{
	ConferenceType data;

	cout << "\n\tCurrent list" << endl;

	// list�� ��� �����͸� ȭ�鿡 ���
	m_List.ResetList();
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	while (curIndex < length && curIndex != -1)
	{
		cout << "\t" << curIndex + 1 << " : " << endl;
		data.DisplayRecordOnScreen();
		curIndex = m_List.GetNextItem(data);
	}
}


// �Է¿� ����� ���� ����
int Application::OpenInFile(char *fileName)
{
	m_InFile.open(fileName);

								// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if (!m_InFile)	return 0;
	else	return 1;
}

// ��¿� ����� ���� ����
int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

								// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if (!m_OutFile)	return 0;
	else	return 1;
}


// ������ ��� ����Ʈ�� ���ڵ带 ���Ϸκ��� �ҷ���
int Application::ReadDataFromFile()
{
	int index = 0;
	ConferenceType data;	// �б�� �ӽ� ����

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if (!OpenInFile(filename))
	{
		cout << "File Open Error!";
		return 0;
	}

	// ������ ��� ������ �о� list�� �߰�
	while (!m_InFile.eof())
	{
		// array�� �л����� ������ ����ִ� structure ����
		data.ReadDataFromFile(m_InFile);
		m_List.Add(data);
	}

	m_InFile.close();	// file close

						// ���� list ���
	DisplayAllConferencesSimple();

	return 1;
}


// ������ ����, ���ڵ��� ����Ʈ�� ���Ͽ� ��
int Application::WriteDataToFile()
{
	ConferenceType data;	// ����� �ӽ� ����

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if (!OpenOutFile(filename))
		return 0;

	// list �����͸� �ʱ�ȭ
	m_List.ResetList();

	// list�� ��� �����͸� ���Ͽ� ����
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	while (curIndex < length && curIndex != -1)
	{
		data.WriteDataToFile(m_OutFile);
		curIndex = m_List.GetNextItem(data);
	}

	m_OutFile.close();	// file close

	return 1;
}*/