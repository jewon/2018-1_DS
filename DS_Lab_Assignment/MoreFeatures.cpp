#include "MoreFeatures.h"

void MoreFeatures::Run()
{
	while (1)
	{
		// ��� �Է¹���
		i_Command = MoreFeaturesGetcommand();
		switch (i_Command)
		{
		//case 1: // �м���ȸ �Ѵ�������
		//	DisplayConferenceBrief();
		//	break;
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
	//cout << "\t   1 : ��ü �м���ȸ �Ѵ�������" << endl;
	cout << "\t   0 : ���� �޴��� ���ư���" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

//void MoreFeatures::DisplayConferenceBrief()
//{
//	ConferenceType temp;
//
//	DoublyIterator<ConferenceType> iter(i_List);
//	if (!iter.NotNull())
//	{
//		cout << "\t�ƹ��͵� �Էµ��� �ʾҽ��ϴ�.\n";
//		return;
//	}
//	while (iter.NotNull())
//	{
//		temp = iter.Next();
//		temp.DisplayBriefOnScreen();
//	}
//}
