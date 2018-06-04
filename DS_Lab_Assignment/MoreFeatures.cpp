#include "MoreFeatures.h"

void MoreFeatures::Run()
{
	while (1)
	{
		// 명령 입력받음
		i_Command = MoreFeaturesGetcommand();
		switch (i_Command)
		{
		case 1: // 학술대회 한눈에보기
			DisplayConferenceBrief();
			break;
		case 2: // 학술대회 기워드로 검색
			SearchConferenceByString();
			break;
		case 3: // 모든 논문 출력
			DisplayAllPaper();
			break;
		case 4: // 논문 키워드로 검색
			SearchPaperByString();
			break;
			break;
		case 5: // 통합검색
			SearchAll();
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
	cout << "\t   1 : 전체 학술대회 한눈에보기" << endl;
	cout << "\t   2 : 학술대회 키워드로 검색" << endl;
	cout << "\t   3 : 전체 논문 한눈에보기" << endl;
	cout << "\t   4 : 논문 키워드로 검색" << endl;
	cout << "\t   5 : 통합검색" << endl;
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
	cout << "\t 논문 검색 완료 (검색 결과" << founds << "개 항목 일치)\n";
}

void MoreFeatures::SearchConferenceByString()
{
	string f;
	cout << "\t 키워드 입력 : ";
	cin >> f;

	int founds = i_List->NameSearch(f);
	cout << "\t 학술대회 검색 완료 (검색 결과" << founds << "개 항목 일치)\n";
}
//
//void MoreFeatures::SearchAuthorByString()
//{
//	string f;
//	cout << "\t 키워드 입력 : ";
//	cin >> f;
//
//	int founds = Author_Index->NameSearch(f);
//	cout << "\t 저자 검색 완료 (검색 결과" << founds << "개 항목 일치)\n";
//}
//
//void MoreFeatures::DisplayAllAuthor()
//{
//	Author_Index->DisplayAllBrief();
//}

void MoreFeatures::SearchAll()
{
	string f;
	cout << "\t 키워드 입력 : ";
	cin >> f;

	int founds = 0;
	cout << "\t 학술대회 검색 결과";
	founds += i_List->NameSearch(f);
	cout << "\n\n\t 논문 검색 결과";
	founds += Paper_Index->NameSearch(f);
	//founds += Author_Index->NameSearch(f);
	cout << "\n\n\t 통합 검색 완료 (총 " << founds << "개 항목 일치)\n";
}

void MoreFeatures::DisplayConferenceBrief()
{
	i_List->DisplayAllBrief();
}


