#include"InfoChange.h"

template<typename T>
void InfoChange<T>::Run()
{
	i_Command = GetCommand();

	switch (i_Command)
	{
	case 0:
		i_List.DisplayAll();
	case 1:
		this->Add();
	case 2:
		this->Delete();
	case 3:
		this->Change();
	}
	default:
		cout << "\t 잘못된 입력입니다\n";
		break;
}

template<typename T>
int InfoChange<T>::GetCommand()
{
	string tName = i_List.GetTName();
	int command;
	cout << tName << " 리스트 변경" << endl;

	cout << "\t   0 : " << tNmae << " 리스트 전체 보기";
	cout << "\t   1 : " << tName << " 추가" << endl;
	cout << "\t   2 : " << tName << " 삭제" << endl;
	cout << "\t   3 : " << tName << " 수정(하위리스트 포함)" << endl;

	cout << "\t   입력 ->";
	cin >> command;
	cout << endl;

	return command;
}

template<typename T>
int InfoChange<T>::Add()
{
	T item;
	item.SetRecordFromKB();

	if (!i_List.Add(item))
	{
		cout << "레코드를 추가하지 못했습니다" << endl;
		return 0;
	}
	i_List.DisplayAll();

	return 1;
}

template<typename T>
int InfoChange<T>::Delete()
{
	T item;
	item.SetNameFromKB();

	if (!i_List.Delete(item))
	{
		cout << "입력하신 이름을 가진 레코드가 없습니다" << endl;
		return 0;
	}
	i_List.DisplayAll();

	return 1;
}

template<typename T>
int InfoChange<T>::Change()
{
	i_List.DisplayAll();
	T item;
	cout << "수정할 레코드 이름을 입력하세요" << endl;
	item.SetNameFromKB();
	
	Get(item); // 같은 이름의 item을 찾아
	item.DisplayRecordOnScreen(); // 화면에 출력
	
	item.Modify(); // item 수정

	if (!i_List.Replace(item))
	{	// 대체 실패시
		cout << "수정이 잘못되었습니다. 이전 상태로 저장됩니다." << endl;
		return 0;
	}
	return 1;
}

