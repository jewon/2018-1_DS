#include "Application.h"
// ���α׷� ����
void Application::Run()
{

	while (1)
	{

		// ��� �Է¹���
		m_Command = GetCommand();
		switch (m_Command)
		{
		case 1: // �м���ȸ ���� ����
			RunAdmin();
			break;
		case 2: // �˻� ���
			RunMoreFeatures();
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
	cout << "\t-------<���� �޴�>-------" << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : ���� ���� (������)" << endl;
	cout << "\t   2 : Ž�� (�����)" << endl;
	cout << "\t   0 : ���α׷� ����" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}

// �ΰ���� ���� (���� ������ ���� �Ϻθ� ����)
void Application::RunMoreFeatures()
{
	MoreFeatures M(&m_List, PaperIndex);
	M.Run();

	return;
}

// ������ �޴� ����
void Application::RunAdmin()
{
	Admin A;
	A.Run(&m_List, PaperIndex);
	return;
}

