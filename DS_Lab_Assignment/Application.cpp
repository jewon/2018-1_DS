#include "Application.h"
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
			RunMoreFeatures();
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

// 명령 목록 화면에 보여주고, 명령 입력받음
int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t-------<메인 메뉴>-------" << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : 정보 수정 (관리자)" << endl;
	cout << "\t   2 : 탐색 (사용자)" << endl;
	cout << "\t   0 : 프로그램 종료" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

// 부가기능 수행 (정보 수정에 없는 일부만 구현)
void Application::RunMoreFeatures()
{
	MoreFeatures M(m_List);
	M.Run();

	return;
}
