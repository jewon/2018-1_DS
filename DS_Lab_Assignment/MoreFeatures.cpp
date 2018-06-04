#include "MoreFeatures.h"

void MoreFeatures::Run()
{
	while (1)
	{
		// 명령 입력받음
		i_Command = MoreFeaturesGetcommand();
		switch (i_Command)
		{
		//case 1: // 학술대회 한눈에보기
		//	DisplayConferenceBrief();
		//	break;
		case 2: // 모든 논문 출력
			DisplayAllPaper();
			break;
		case 3: // 논문 키워드로 검색
			SearchPaperByString();
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

int MoreFeatures::MoreFeaturesGetcommand()
{
	int command;
	cout << endl << endl;
	cout << "\t-------<탐색 메뉴>-------" << endl;
	cout << "\t---ID -- Command ----- " << endl;
	//cout << "\t   1 : 전체 학술대회 한눈에보기" << endl;
	cout << "\t   0 : 메인 메뉴로 돌아가기" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

void MoreFeatures::DisplayAllPaper()
{
	Paper_Index->DisplayAllBrief();
}

void MoreFeatures::SearchPaperByString()
{
	string f;
	cout << "\t 키워드 입력 : ";
	cin >> f;
	
	int founds = Paper_Index->NameSearch(f);
	cout << "\t 검색 완료 (검색 결과" << founds << "개 항목 일치)\n";
}

//void MoreFeatures::DisplayConferenceBrief()
//{
//	ConferenceType temp;
//
//	DoublyIterator<ConferenceType> iter(i_List);
//	if (!iter.NotNull())
//	{
//		cout << "\t아무것도 입력되지 않았습니다.\n";
//		return;
//	}
//	while (iter.NotNull())
//	{
//		temp = iter.Next();
//		temp.DisplayBriefOnScreen();
//	}
//}


