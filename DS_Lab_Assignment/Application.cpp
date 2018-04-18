#include "Application.h"

// 이전 버전 코드입니다. (참조용)
/*
void Application::Run()
{
	while (1)
	{
		m_Command = GetCommand();

		switch (m_Command)
		{
		case 1:		// 레코드를 입력받아 추가한다
			AddConference();
			break;
		case 2:		// 레코드 id를 입력받아 해당 레코드가 있으면 삭제한다
			DeleteConference();
			break;
		case 3:		// 레코드를 입력받아 내용을 바꾼다
			ReplaceConference();
			break;
		case 4:		// 레코드 id를 입력받아 해당 레코드가 있으면 출력한다
			RetrieveByName();
			break;
		case 5 :	// 모든 레코드 간략히 출력후 사용자가 골라서 자세히 출력한다
			GetConferenceInfo();
			break;
		case 6:		// 모든 레코드를 출력한다
			DisplayAllConferences();
			break;
		case 7:		// 파일로부터 레코들을 읽어온다
			ReadDataFromFile();
			break;
		case 8:		// 레코드를 파일에 쓴다
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

// 프로그램 실행
void Application::Run()
{
	// 학술대회 리스트를 수정할 수 있도록 가져와 둠
	InfoChange<ConferenceType> ChangeConference;

	// 부가기능 수행을 위한 클래스 로딩


	while (1)
	{
		// 명령 입력받음
		m_Command = GetCommand();
		switch (m_Command)
		{
		case 1: // 학술대회 내용 수정
			ChangeConference.Run(&m_List);
			break;
		case 2: // 검색 기능
			cout << "\t Maybe Unstable... Still Developing\n\n";
			MoreFeatures();
			break;
		/*case 3:		// 파일로부터 레코들을 읽어온다
			ReadDataFromFile();
			break;
		case 4:		// 레코드를 파일에 쓴다
			WriteDataToFile();
			break;*/
		case 0: // 프로그램 종료
			return;
			break;
		default:
			cout << "\t잘못된 입력입니다...\n";
			break;
		}
	}
}

// 명령 목록 화면에 보여주고, 명령 입력받음
int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : 정보 수정" << endl;
	cout << "\t   2 : 검색" << endl;
	//cout << "\t   3 : 파일 읽기" << endl;
	//cout << "\t   4 : 파일 쓰기 " << endl;
	cout << "\t   0 : 종료" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

// 부가기능 수행 (정보 수정에 없는 일부만 구현)
void Application::MoreFeatures()
{
	while (1)
	{
		// 명령 입력받음
		f_Command = MoreFeaturesGetcommand();
		switch (f_Command)
		{
		case 1: // 논문 검색
			PaperSearch();
			break;
		case 2: // 학술대회 한눈에보기
			m_List.DisplayAllBrief();
			break;
		case 0: // 프로그램 종료
			return;
			break;
		default:
			cout << "\t잘못된 입력입니다...\n";
			break;
		}
	}
}

// 부가기능 수행을 위한 메뉴 출력 및 명령 입력
int Application::MoreFeaturesGetcommand()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : 전체 학술대회에서 논문 검색" << endl;
	cout << "\t   2 : 전체 학술대회 한눈에보기" << endl;
	//cout << "\t   3 : 파일 읽기" << endl;
	//cout << "\t   4 : 파일 쓰기 " << endl;
	cout << "\t   0 : 종료" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

// 전체 리스트에서 논문 검색하는 메뉴
void Application::PaperSearch()
{
	string word;
	cout << "\t찾고자 하는 키워드를 입력하세요\n\t";
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


// 아래는 이전 버전 소스입니다.

/*
// 리스트에 새로운 레코드 추가
int Application::AddConference()
{
	// 입력받은 레코드를 리스트에 add, 리스트가 full일 경우는 add하지 않고 0을 리턴
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
		// 현재 list 출력
		DisplayAllConferencesSimple();
		return 1;
	}
}

// 이름을 입력받아 같은 이름을 갖는 레코드를 삭제함
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
	{ //똑같은 이름 가진것만 지우게 된데
		DisplayAllConferencesSimple();
		return 1;
	}
	else
		return 0;
}

// 사용자로부터 레코드 입력받아 이름 같은 레코드 대체함
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

// 사용자로부터 이름 입력받아 해당 이름갖는 레코드 출력
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

// 모든 레코드 간략히 출력후 사용자로부터 입력받아 해당 레코드 자세히 출력
void Application::GetConferenceInfo()
{
	DisplayAllConferencesSimple(); // 요약정보 출력
	int input = 0;
	cout << "Input Conference Number : ";
	cin >> input; // 출력할 번호 입력받음 (번호는 배열번호 + 1)
	while (1)
	{
		if (m_List.Display(input - 1)) // 출력 성공시
			break;
		else
		{ // 출력 실패시
			cout << "Wrong Input. Input Again : ";
			cin >> input; // 다시 입력받아 출력
		}
	}
}

// 모든 레코드 간략하게 출력
void Application::DisplayAllConferencesSimple()
{
	ConferenceType data;

	cout << "\n\tCurrent list" << endl;

	// list의 모든 데이터를 화면에 출력
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

// 모든 레코드 출력
void Application::DisplayAllConferences()
{
	ConferenceType data;

	cout << "\n\tCurrent list" << endl;

	// list의 모든 데이터를 화면에 출력
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


// 입력에 사용할 파일 열기
int Application::OpenInFile(char *fileName)
{
	m_InFile.open(fileName);

								// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (!m_InFile)	return 0;
	else	return 1;
}

// 출력에 사용할 파일 열기
int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

								// 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (!m_OutFile)	return 0;
	else	return 1;
}


// 파일을 열어서 리스트에 레코드를 파일로부터 불러옴
int Application::ReadDataFromFile()
{
	int index = 0;
	ConferenceType data;	// 읽기용 임시 변수

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// file open, open error가 발생하면 0을 리턴
	if (!OpenInFile(filename))
	{
		cout << "File Open Error!";
		return 0;
	}

	// 파일의 모든 내용을 읽어 list에 추가
	while (!m_InFile.eof())
	{
		// array에 학생들의 정보가 들어있는 structure 저장
		data.ReadDataFromFile(m_InFile);
		m_List.Add(data);
	}

	m_InFile.close();	// file close

						// 현재 list 출력
	DisplayAllConferencesSimple();

	return 1;
}


// 파일을 열어, 레코드의 리스트를 파일에 씀
int Application::WriteDataToFile()
{
	ConferenceType data;	// 쓰기용 임시 변수

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	// file open, open error가 발생하면 0을 리턴
	if (!OpenOutFile(filename))
		return 0;

	// list 포인터를 초기화
	m_List.ResetList();

	// list의 모든 데이터를 파일에 쓰기
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