#ifndef _AVL_H
#define _AVL_H

#include <iostream>
#include <string>
using namespace std;

// Tree를 구성하는 Node (node data, left 포인터, right 포인터)
template<class ItemType>
struct Node
{
	ItemType data;
	Node* left;
	Node* right;
	int height;
};

// Binary Search Tree 
template<class ItemType>
class BinarySearchTree
{
	//friend class Admin; // Admin이 GetData() 사용할 수 있도록 함

public:
	// 생성자
	BinarySearchTree();
	// 소멸자
	~BinarySearchTree();

	/**
	*	@brief	리스트에 포함된 정보 추상 이름을 알려준다
	*	@pre	.
	*	@post	.
	*	@return	TName
	*/
	string GetTName();

	/**
	*	@brief	Tree가 Empty인지 확인
	*	@pre	none
	*	@post	none
	*	@return	Tree가 비어있으면 true리턴, 아니면 false 리턴
	*/
	bool IsEmpty();

	/**
	*	@brief	Tree가 Full인지 확인
	*	@pre	none
	*	@post	none
	*	@return	Tree가 Full이면 true 리턴, 아니면 false 리턴
	*/
	bool IsFull();

	/**
	*	@brief	Tree를 비운다
	*	@pre	none
	*	@post	none
	*/
	void MakeEmpty();

	/**
	*	@brief	Tree에 node가 몇 개인지 확인함
	*	@pre	none
	*	@post	none
	*	@return	Tree의 node 개수를 리턴
	*/
	int GetLength();

	/**
	*	@brief	특정 노드를 root로 하는 Tree의 height를 확인함
	*	@pre	none
	*	@post	none
	*	@param	p	확인할 노드 포인터
	*	@return	p의 자식 노드가 있으면 height, 없으면 -1
	*/
	int GetHeight(Node<ItemType> * p);

	/**
	*	@brief	sigle left rotation
	*	@pre	none
	*	@post	none
	*	@param	p	rotation전 root node 포인터
	*	@return	rotation후 root node 포인터
	*/
	Node<ItemType> * single_rotation_left(Node<ItemType> * p);

	/**
	*	@brief	sigle right rotation
	*	@pre	none
	*	@post	none
	*	@param	p	rotation전 root node 포인터
	*	@return	rotation후 root node 포인터
	*/
	Node<ItemType> * single_rotation_right(Node<ItemType> * p);

	/**
	*	@brief	double left-right rotation
	*	@pre	none
	*	@post	none
	*	@param	p	rotation전 root node 포인터
	*	@return	rotation후 root node 포인터
	*/
	Node<ItemType> * double_rotation_left(Node<ItemType> * p);

	/**
	*	@brief	double right-left rotation
	*	@pre	none
	*	@post	none
	*	@param	p	rotation전 root node 포인터
	*	@return	rotation후 root node 포인터
	*/
	Node<ItemType> * double_rotation_right(Node<ItemType> * p);

	/**
	*	@brief	Tree에 새 node를 추가한다
	*	@pre	ItemType의 객체를 생성
	*	@post	Tree에 새 node가 추가됨
	*	@return	추가 성공시 1, 실패시 0을 반환
	*/
	int Add(ItemType item);

	/**
	*	@brief	Tree에서 지우고자 하는 node를 찾고 지움
	*	@pre	ItemType의 객체를 생성
	*	@post	Tree에서 입력한 node가 삭제됨
	*	@return	삭제 성공시 1, 실패시 0을 반환
	*/
	int Delete(ItemType item);

	/**
	*	@brief	파라미터의 이름과 일치하는 리스트의 레코드를 파라미터로 대체함
	*	@pre	리스트 초기화
	*	@post	파라미터의 학술대회명과 일치하는 리스트의 레코드가 파라미터의 내용대로 바뀜
	*	@param	item	바꿀 레코드
	*	@return	대체 성공시 1, 실패시 0을 반환
	*/
	int Replace(ItemType item);

	/**
	*	@brief	파라미터의 이름과 일치하는 리스트의 레코드를 읽어들임
	*	@pre	리스트 초기화
	*	@post	파라미터의 학술대회명과 일치하는 리스트의 레코드가 파라미터에 저장됨
	*	@param	item	찾을 레코드의 학술대회를 가지는 레코드, 학술대회만 입력되어 있어도 상관 없음, 함수 실행시 레코드 내용 저장
	*	@return	일치하는 레코드가 있으면 1, 아닐경우 0 반환
	*/
	int Get(ItemType &item);

	/**
	*	@brief	리스트 내 모든 레코드 출력 (T에 따라 출력 내용 다름)
	*	@pre	리스트 초기화
	*	@post	리스트 내 모든 정보 (ItemType에 따라) 출력
	*/
	void DisplayAll();

	/**
	*	@brief	리스트 내 모든 레코드 간략히 출력 (T에 따라 출력 내용 다름)
	*	@pre	리스트 초기화
	*	@post	리스트 내 모든 정보 (ItemType에 따라 간략히) 출력
	*/
	void DisplayAllBrief();

	/**
	*	@brief	입력한 값의 node를 Tree에서 검색함
	*	@pre	찾고자 하는 item과 검색결과에 대한 found 설정
	*	@post	node가 Tree에 있는지 검색결과를 알려줌
	*/
	void RetrieveItem(ItemType& item, bool &found);

	/**
	*	@brief	Tree의 node를 스크린에 출력한다.
	*	@pre	none
	*	@post	스크린에 Tree가 InOrder, PreOrder, PostOrder 방법으로 각각 출력됨.
	*/
	void PrintTree(ostream &out);

	///**
	//*	@brief	리스트 내의 모든 노드들의 이름을 트리모양으로 출력
	//*	@pre	리스트 초기화
	//*	@post	리스트 내의 모든 노드들의 이름이 한 줄씩 트리모양으로 출력됨
	//*	@param	level	리스트의 단계(0단계 최상위~n단계)
	//*/
	//void DisplayAllStructure(int level);

	///**
	//*	@brief	리스트 내의 모든 노드들의 이름을 트리모양으로 출력(하위리스트 포함)
	//*	@pre	(최상위) 리스트 초기화
	//*	@post	DisplayAllStructure를 활용해 모든 리스트 데이터 트리모양으로 출력
	//*/
	//void DoDisplayAllStructure();

	int Insert(Node<ItemType>*& root, ItemType item);


	ItemType * GetData(ItemType &item);
	ItemType * RetrieveP(Node<ItemType> * root, ItemType &item);
	BinarySearchTree<ItemType> operator+(BinarySearchTree<ItemType> const & tree2);
	void InsertAll(Node<ItemType>* root, BinarySearchTree<ItemType>* tree);
	BinarySearchTree<ItemType> clone();
	ItemType** TreeToArr(int &t);
	void AddNodeToVec(Node<ItemType> * root, ItemType *** vec, int &t);
	int NameSearch(string f);
	int NameSearchRecur(string &f, Node<ItemType> * root);

private:
	Node<ItemType>* root;		///< Node 타입의 root
	string TName;	///< 트리 노드 데이터 타입이름

	/**
	*	@brief	root 아래에 새 item를 추가한다(재귀적)
	*	@pre	Add를 통한 호출
	*	@post	root 아래에 새 itme이 추가됨
	*/

};

// 생성자
template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree()
{
	root = NULL;

	ItemType temp;
	TName = temp.WhatType();
}

template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree()
{
	MakeEmpty();
}

template<class ItemType>
string BinarySearchTree<ItemType>::GetTName()
{
	return TName;
}

// Tree가 비어있는지 확인
template<class ItemType>
bool BinarySearchTree<ItemType>::IsEmpty()
{
	if (root == NULL)			// root 노드가 NULL인 경우 true 리턴
		return true;
	else
		return false;			// root 노드가 NULL이 아닌 경우 false 리턴
}

// Tree가 Full인지 확인
template<class ItemType>
bool BinarySearchTree<ItemType>::IsFull()
{
	Node* room;					// 임시의 node를 만들고
	try
	{
		room = new Node;		// 새 노드를 추가할 수 있는지 확인
		delete room;			// 임시로 만든 room 노드를 지움
		return false;			// isFull에 대한 false 리턴
	}
	catch (std::bad_alloc exception)		// 더 이상 아이템 추가를 할 수 없고 Full일 경우
	{
		return true;					// isFull에 대한 true 리턴
	}
}

// Tree를 비움
template<class ItemType>
void BinarySearchTree<ItemType>::MakeEmpty()
{
	MakeEmptyTree(root);				// Tree 초기화 함수 호출
}

// Tree의 node개수를 알려줌
template<class ItemType>
int BinarySearchTree<ItemType>::GetLength()
{
	return CountNodes(root);			// node 개수를 새는 함수 호출
}

template<class ItemType>
int BinarySearchTree<ItemType>::GetHeight(Node<ItemType> * p)
{
	if (p == NULL)
		return -1;
	else
		return p->height;
}

template<class ItemType>
Node<ItemType>* BinarySearchTree<ItemType>::single_rotation_right(Node<ItemType>* p)
{
	Node<ItemType> * tp;
	tp = p->left;
	p->left = tp->right;
	tp->right = p;
	//height 변경
	if (GetHeight(p->left) > GetHeight(p->right))
		p->height = GetHeight(p->left) + 1;
	else
		p->height = GetHeight(p->right) + 1;

	if (GetHeight(tp->right) > p->height)
		tp->height = GetHeight(tp->right) + 1;
	else
		tp->height = p->height + 1;

	return tp;
}

template<class ItemType>
Node<ItemType>* BinarySearchTree<ItemType>::single_rotation_left(Node<ItemType>* p)
{
	Node<ItemType> * tp;
	tp = p->right;
	p->right = tp->left;
	tp->left = p;
	//height 변경
	if (GetHeight(p->left) > GetHeight(p->right))
		p->height = GetHeight(p->left) + 1;
	else
		p->height = GetHeight(p->right) + 1;

	if (GetHeight(tp->left) > p->height)
		tp->height = GetHeight(tp->left) + 1;
	else
		tp->height = p->height + 1;

	return tp;
}

template<class ItemType>
Node<ItemType>* BinarySearchTree<ItemType>::double_rotation_left(Node<ItemType>* p)
{
	p->left = single_rotation_left(p->left);
	return single_rotation_right(p);
}

template<class ItemType>
Node<ItemType>* BinarySearchTree<ItemType>::double_rotation_right(Node<ItemType>* p)
{
	p->right = single_rotation_right(p->right);
	return single_rotation_left(p);
}

// Tree에 새로운 node 추가
template<class ItemType>
int BinarySearchTree<ItemType>::Add(ItemType item)
{
	// 새 node 추가하는 함수 호출
	if (Insert(root, item) != 1)
		return 0;
	else
		return 1;
}

// Tree의 node를 지움
template<class ItemType>
int BinarySearchTree<ItemType>::Delete(ItemType item)
{
	if (DeleteItem(root, item) != 1)
		return 0;					// 존재하는 node 삭제하는 함수를 호출
	return 1;
}

template<class ItemType>
int BinarySearchTree<ItemType>::Replace(ItemType item)
{
	if (Delete(item) != 1)
		return 0;
	if (Add(item) != 1)
		return 0;
	return 1;
}

template<class ItemType>
int BinarySearchTree<ItemType>::Get(ItemType & item)
{
	bool found;
	RetrieveItem(item, found);

	if (found)
		return 1;
	else
		return 0;
}

template<class ItemType>
void BinarySearchTree<ItemType>::DisplayAll()
{
	if (!IsEmpty())
		PrintInOrderTraversal(root);
	else
		cout << "\t-----Messege-----\n\t리스트가 비어 있습니다.\n\t-----Messege-----" << endl;
	return;
}

template<class ItemType>
void BinarySearchTree<ItemType>::DisplayAllBrief()
{
	if (!IsEmpty())
		PrintInOrderTraversalBrief(root);
	else
		cout << "\t-----Messege-----\n\t리스트가 비어 있습니다.\n\t-----Messege-----" << endl;
	return;
}

// Tree에서 찾고자 하는 값의 node를 검색
template<class ItemType>
void BinarySearchTree<ItemType>::RetrieveItem(ItemType& item, bool &found)
{
	Retrieve(root, item, found);		// Tree 검색 함수 호출
}

// Tree의 node를 각각의 방법대로 출력함
template<class ItemType>
void BinarySearchTree<ItemType>::PrintTree(ostream &out)
{
	cout << "[InOrder]" << endl;
	PrintInOrderTraversal(root);			// InOrder 방법으로 출력
	cout << endl << "[PreOrder]" << endl;
	PrintPreOrderTraversal(root);			// PreOrder 방법으로 출력
	cout << endl << "[PostOrder]" << endl;
	PrintPostOrderTraversal(root);			// PostOrder 방법으로 출력
}

// BinarySearchTree에 새로운 노드 추가
template<class ItemType>
int BinarySearchTree<ItemType>::Insert(Node<ItemType>*& root, ItemType item)
{
	int added = 0;
	if (root == NULL)				// root가 null일 경우 
	{
		root = new Node<ItemType>;	// root 노드 생성
		root->left = NULL;			// root 노드이므로 left와 right는 NULL로 설정
		root->right = NULL;
		root->data = item;			// root 노드의 값
		root->height = 0;
		added = 1;
	}

	else if (root->data > item)		// root가 존재하고, 그 값이 새로운 item 값보다 클 때
	{
		added = Insert(root->left, item);	// root의 왼쪽으로 Insert 함수 다시 호출
		if (GetHeight(root->left) - GetHeight(root->right) == 2)	// rotation
		{
			if (item < root->left->data)
				root = single_rotation_right(root);
			else
				root = double_rotation_left(root);
		}
	}
	else if (root->data < item)		// root가 존재하고, 그 값이 새로운 item 값보다 작을 때
	{
		added = Insert(root->right, item);	// root의 오른쪽으로 Insert 함수 다시 호출
		if (GetHeight(root->right) - GetHeight(root->left) == 2)	// rotation
		{
			if (item > root->right->data)
				root = single_rotation_left(root);
			else
				root = double_rotation_right(root);
		}
	}
	else
		return 0;
	return added;
}

template<class ItemType>
ItemType * BinarySearchTree<ItemType>::RetrieveP(Node<ItemType>* root, ItemType &item)
{
	if (root == NULL)						// root가 NULL인 경우 찾는 item 없음(NULL리턴)
		return NULL;
	else if (item < root->data)				// 찾고자 하는 아이템값이 root값보다 작을 때 
		return RetrieveP(root->left, item);	// 왼쪽 노드로 가서 retrieve 함수 호출
	else if (item > root->data)				// 찾고자 하는 아이템값이 root값보다 클 때
		return RetrieveP(root->right, item);	// 오른쪽 노드로 가서 retrieve 함수 호출
	else
	{										// 찾고자 하는 값과 일치할 때
		item = root->data;					// item에 노드 정보를 복사
		return &(root->data);				// item 주소 리턴
	}
}

template<class ItemType>
BinarySearchTree<ItemType> BinarySearchTree<ItemType>::operator+(BinarySearchTree<ItemType> const & intree)
{
	BinarySearchTree<ItemType> result = this->clone();
	this->InsertAll(intree.root, &result);
	return result;
}

template<class ItemType>
void BinarySearchTree<ItemType>::InsertAll(Node<ItemType>* root, BinarySearchTree<ItemType>* tree)
{
	if (root != NULL)								// root가 존재하는 경우
	{
		InsertAll(root->left, tree);		// root의 왼쪽으로 가서 다시 InOrder 함수 호출
		tree->Add(root->data);			// root 출력
		InsertAll(root->right, tree);	// root의 오른쪽으로 가서 다시 InOrder 함수 호출
	}
}

template<class ItemType>
BinarySearchTree<ItemType> BinarySearchTree<ItemType>::clone()
{
	BinarySearchTree<ItemType> result;
	InsertAll(root, &result);
	return result;
}

template<class ItemType>
ItemType** BinarySearchTree<ItemType>::TreeToArr(int &t)
{
	ItemType ** result = new ItemType* [this->GetLength()];
	AddNodeToVec(root, &result, t);
	return result;
}


template<class ItemType>
void BinarySearchTree<ItemType>::AddNodeToVec(Node<ItemType>* root, ItemType *** vec, int& t)
{
	if (root != NULL)// root가 존재하는 경우
	{
		AddNodeToVec(root->left, vec, t);		// root의 왼쪽으로 가서 다시 InOrder 함수 호출
		(*vec)[t] = &(root->data);		// root 출력
		t++;
		AddNodeToVec(root->right, vec, t);	// root의 오른쪽으로 가서 다시 InOrder 함수 호출
	}
}

template<class ItemType>
int BinarySearchTree<ItemType>::NameSearch(string f)
{
		return NameSearchRecur(f, root);
}

template<class ItemType>
int BinarySearchTree<ItemType>::NameSearchRecur(string & f, Node<ItemType>* root)
{
	{
		int found = 0;
		if (root != NULL)								// root가 존재하는 경우
		{
			found += NameSearchRecur(f, root->left);		// root의 왼쪽으로 가서 다시 InOrder 함수 호출
			if (root->data.NameFind(f))			// root 출력
				found++;
			found += NameSearchRecur(f, root->right);	// root의 오른쪽으로 가서 다시 InOrder 함수 호출
		}
		return found;
	}
}

template<class ItemType>
ItemType * BinarySearchTree<ItemType>::GetData(ItemType &item)
{
	return RetrieveP(root, item);
}

/////////////////////////////Global functions//////////////////////////
// Tree를 초기화하는 함수
template<class ItemType>
void MakeEmptyTree(Node<ItemType>*& root)
{
	root = NULL;			// root 노드를 Null로 함
}

// Tree의 node 개수를 세는 함수
template<class ItemType>
int CountNodes(Node<ItemType>* root)
{
	if (root == NULL)		// root 노드가 null일경우 0을 리턴
		return 0;
	else
		return CountNodes(root->left) + CountNodes(root->right) + 1;		// 노드의 왼쪽, 오른쪽에 대한 재귀적 호출과 root에 해당하는 1을 더해서 값을 리턴
}



// 가장 큰 값을 찾는 함수 
template<class ItemType>
void GetPredecessor(Node<ItemType> *root, ItemType& item)
{
	while (root->right != NULL)			// root의 오른쪽이 존재할 경우
		root = root->right;				// root의 오른쪽 노드값이 root에 오도록 한다
	item = root->data;					// root 노드의 값을 item에 복사한다.
}

// 지우려는 노드를 찾으면 실제로 트리에서 그 노드를 지우는 함수
template<class ItemType>
void DeleteNode(Node<ItemType> *&root)
{
	ItemType item;
	Node<ItemType>* tempPtr;			// 임시 노드를 생성하고 root 노드를 임시 노드에 복사
	tempPtr = root;

	if (root->left == NULL)				// 왼쪽노드가 없을 때
	{
		root = root->right;				// 오른쪽 노드가 root가 되도록 복사하고 임시노드를 지움
		delete tempPtr;
	}
	else if (root->right == NULL)		// 오른쪽노드가 없을 때
	{
		root = root->left;				// 왼쪽 노드가 root가 되도록 복사하고 임시노드를 지움
		delete tempPtr;
	}
	else
	{
		GetPredecessor(root->left, item);	// 중간에 있는 노드를 지우고 싶을 때 (left, right, child 노드 있을 경우)
		root->data = item;					// 지우려는 노드보다 작은 노드들 중에 가장 큰 노드를 찾음
		DeleteItem(root->left, item);			// 그 값을 지울 노드에 복사를 해서 지운 것처럼
	}
}

// 내가 지우려고 하는 노드를 찾는 recursive 함수
template<class ItemType>
int DeleteItem(Node<ItemType> *&root, ItemType item)
{
	if (root == NULL)
		return 0;
	else if (item < root->data)				// root노드값보다 item노드가 작을 때
		DeleteItem(root->left, item);		// 왼쪽노드로 가서 delete함수 호출
	else if (item > root->data)			// root노드값보다 item노드가 클 때
		DeleteItem(root->right, item);		// 오른쪽노드로 가서 delete함수 호출
	else
	{
		DeleteNode(root);				// 찾고자 하는 값이 일치하는 경우 deletenode 함수 호출
		return 1;
	}
}

// Tree에서 node를 검색하는 함수
template<class ItemType>
void Retrieve(Node<ItemType> *root, ItemType& item, bool &found)
{
	if (root == NULL)						// root가 NULL인 경우 found는 false 
		found = false;
	else if (item < root->data)				// 찾고자 하는 아이템값이 root값보다 작을 때 
		Retrieve(root->left, item, found);	// 왼쪽 노드로 가서 retrieve 함수 호출
	else if (item > root->data)				// 찾고자 하는 아이템값이 root값보다 클 때
		Retrieve(root->right, item, found);	// 오른쪽 노드로 가서 retrieve 함수 호출
	else
	{										// 찾고자 하는 값과 일치할 때
		item = root->data;					// item에 노드 정보를 복사
		found = true;						// found값을 true로 해서 찾는 과정을 멈춤
	}
}

// InOrder 방법으로 출력하는 함수 
template<class ItemType>
void PrintInOrderTraversal(Node<ItemType>* root)
{
	if (root != NULL)								// root가 존재하는 경우
	{
		PrintInOrderTraversal(root->left);		// root의 왼쪽으로 가서 다시 InOrder 함수 호출
		root->data.DisplayRecordOnScreen();			// root 출력
		PrintInOrderTraversal(root->right);	// root의 오른쪽으로 가서 다시 InOrder 함수 호출
	}
}

// InOrder 방법으로 간단히 출력하는 함수 
template<class ItemType>
void PrintInOrderTraversalBrief(Node<ItemType>* root)
{
	if (root != NULL)								// root가 존재하는 경우
	{
		PrintInOrderTraversalBrief(root->left);		// root의 왼쪽으로 가서 다시 InOrder 함수 호출
		root->data.DisplayBriefOnScreen();		// root 출력
		PrintInOrderTraversalBrief(root->right);	// root의 오른쪽으로 가서 다시 InOrder 함수 호출
	}
}

// PreOrder 방법으로 출력하는 함수
template<class ItemType>
void PrintPreOrderTraversal(Node<ItemType>* root)
{
	if (root != NULL)								// root가 존재하는 경우
	{
		root->data.DisplayRecordOnScreen();			// root 출력
		PrintPreOrderTraversal(root->left);	// root의 왼쪽으로 가서 PreOrder 함수 다시 호출
		PrintPreOrderTraversal(root->right);	// root의 오른쪽으로 가서 PreOrder 함수 다시 호출
	}
}

// PostOrder 방법으로 출력하는 함수
template<class ItemType>
void PrintPostOrderTraversal(Node<ItemType>* root)
{
	if (root != NULL)								// root가 존재하는 경우
	{
		PrintPostOrderTraversal(root->left);	// root의 왼쪽으로 가서 다시 PostOrder 함수 호출
		PrintPostOrderTraversal(root->right);	// root의 오른쪽으로 가서 다시 PostOrder 함수 호출
		root->data.DisplayRecordOnScreen();			// root 출력
	}
}

#endif