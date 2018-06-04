#include "MoreFeatures.h"

void MoreFeatures::Run()
{
	while (1)
	{
		// ��� �Է¹���
		i_Command = MoreFeaturesGetcommand();
		switch (i_Command)
		{
		case 1: // �м���ȸ �Ѵ�������
			DisplayConferenceBrief();
			break;
		case 2: // �м���ȸ ������ �˻�
			SearchConferenceByString();
			break;
		case 3: // ��� �� ���
			DisplayAllPaper();
			break;
		case 4: // �� Ű����� �˻�
			SearchPaperByString();
			break;
			break;
		case 5: // ���հ˻�
			SearchAll();
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

int MoreFeatures::MoreFeaturesGetcommand()
{
	int command;
	cout << endl << endl;
	cout << "\t-------<Ž�� �޴�>-------" << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : ��ü �м���ȸ �Ѵ�������" << endl;
	cout << "\t   2 : �м���ȸ Ű����� �˻�" << endl;
	cout << "\t   3 : ��ü �� �Ѵ�������" << endl;
	cout << "\t   4 : �� Ű����� �˻�" << endl;
	cout << "\t   5 : ���հ˻�" << endl;
	cout << "\t   0 : ���� �޴��� ���ư���" << endl;

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
	cout << "\t Ű���� �Է� : ";
	cin >> f;
	
	int founds = Paper_Index->NameSearch(f);
	cout << "\t �� �˻� �Ϸ� (�˻� ���" << founds << "�� �׸� ��ġ)\n";
}

void MoreFeatures::SearchConferenceByString()
{
	string f;
	cout << "\t Ű���� �Է� : ";
	cin >> f;

	int founds = i_List->NameSearch(f);
	cout << "\t �м���ȸ �˻� �Ϸ� (�˻� ���" << founds << "�� �׸� ��ġ)\n";
}
//
//void MoreFeatures::SearchAuthorByString()
//{
//	string f;
//	cout << "\t Ű���� �Է� : ";
//	cin >> f;
//
//	int founds = Author_Index->NameSearch(f);
//	cout << "\t ���� �˻� �Ϸ� (�˻� ���" << founds << "�� �׸� ��ġ)\n";
//}
//
//void MoreFeatures::DisplayAllAuthor()
//{
//	Author_Index->DisplayAllBrief();
//}

void MoreFeatures::SearchAll()
{
	string f;
	cout << "\t Ű���� �Է� : ";
	cin >> f;

	int founds = 0;
	cout << "\t �м���ȸ �˻� ���";
	founds += i_List->NameSearch(f);
	cout << "\n\n\t �� �˻� ���";
	founds += Paper_Index->NameSearch(f);
	//founds += Author_Index->NameSearch(f);
	cout << "\n\n\t ���� �˻� �Ϸ� (�� " << founds << "�� �׸� ��ġ)\n";
}

void MoreFeatures::DisplayConferenceBrief()
{
	i_List->DisplayAllBrief();
}


