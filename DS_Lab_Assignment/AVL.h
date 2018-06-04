#ifndef _AVL_H
#define _AVL_H

#include <iostream>
#include <string>
using namespace std;

// Tree�� �����ϴ� Node (node data, left ������, right ������)
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
	//friend class Admin; // Admin�� GetData() ����� �� �ֵ��� ��

public:
	// ������
	BinarySearchTree();
	// �Ҹ���
	~BinarySearchTree();

	/**
	*	@brief	����Ʈ�� ���Ե� ���� �߻� �̸��� �˷��ش�
	*	@pre	.
	*	@post	.
	*	@return	TName
	*/
	string GetTName();

	/**
	*	@brief	Tree�� Empty���� Ȯ��
	*	@pre	none
	*	@post	none
	*	@return	Tree�� ��������� true����, �ƴϸ� false ����
	*/
	bool IsEmpty();

	/**
	*	@brief	Tree�� Full���� Ȯ��
	*	@pre	none
	*	@post	none
	*	@return	Tree�� Full�̸� true ����, �ƴϸ� false ����
	*/
	bool IsFull();

	/**
	*	@brief	Tree�� ����
	*	@pre	none
	*	@post	none
	*/
	void MakeEmpty();

	/**
	*	@brief	Tree�� node�� �� ������ Ȯ����
	*	@pre	none
	*	@post	none
	*	@return	Tree�� node ������ ����
	*/
	int GetLength();

	/**
	*	@brief	Ư�� ��带 root�� �ϴ� Tree�� height�� Ȯ����
	*	@pre	none
	*	@post	none
	*	@param	p	Ȯ���� ��� ������
	*	@return	p�� �ڽ� ��尡 ������ height, ������ -1
	*/
	int GetHeight(Node<ItemType> * p);

	/**
	*	@brief	sigle left rotation
	*	@pre	none
	*	@post	none
	*	@param	p	rotation�� root node ������
	*	@return	rotation�� root node ������
	*/
	Node<ItemType> * single_rotation_left(Node<ItemType> * p);

	/**
	*	@brief	sigle right rotation
	*	@pre	none
	*	@post	none
	*	@param	p	rotation�� root node ������
	*	@return	rotation�� root node ������
	*/
	Node<ItemType> * single_rotation_right(Node<ItemType> * p);

	/**
	*	@brief	double left-right rotation
	*	@pre	none
	*	@post	none
	*	@param	p	rotation�� root node ������
	*	@return	rotation�� root node ������
	*/
	Node<ItemType> * double_rotation_left(Node<ItemType> * p);

	/**
	*	@brief	double right-left rotation
	*	@pre	none
	*	@post	none
	*	@param	p	rotation�� root node ������
	*	@return	rotation�� root node ������
	*/
	Node<ItemType> * double_rotation_right(Node<ItemType> * p);

	/**
	*	@brief	Tree�� �� node�� �߰��Ѵ�
	*	@pre	ItemType�� ��ü�� ����
	*	@post	Tree�� �� node�� �߰���
	*	@return	�߰� ������ 1, ���н� 0�� ��ȯ
	*/
	int Add(ItemType item);

	/**
	*	@brief	Tree���� ������� �ϴ� node�� ã�� ����
	*	@pre	ItemType�� ��ü�� ����
	*	@post	Tree���� �Է��� node�� ������
	*	@return	���� ������ 1, ���н� 0�� ��ȯ
	*/
	int Delete(ItemType item);

	/**
	*	@brief	�Ķ������ �̸��� ��ġ�ϴ� ����Ʈ�� ���ڵ带 �Ķ���ͷ� ��ü��
	*	@pre	����Ʈ �ʱ�ȭ
	*	@post	�Ķ������ �м���ȸ��� ��ġ�ϴ� ����Ʈ�� ���ڵ尡 �Ķ������ ������ �ٲ�
	*	@param	item	�ٲ� ���ڵ�
	*	@return	��ü ������ 1, ���н� 0�� ��ȯ
	*/
	int Replace(ItemType item);

	/**
	*	@brief	�Ķ������ �̸��� ��ġ�ϴ� ����Ʈ�� ���ڵ带 �о����
	*	@pre	����Ʈ �ʱ�ȭ
	*	@post	�Ķ������ �м���ȸ��� ��ġ�ϴ� ����Ʈ�� ���ڵ尡 �Ķ���Ϳ� �����
	*	@param	item	ã�� ���ڵ��� �м���ȸ�� ������ ���ڵ�, �м���ȸ�� �ԷµǾ� �־ ��� ����, �Լ� ����� ���ڵ� ���� ����
	*	@return	��ġ�ϴ� ���ڵ尡 ������ 1, �ƴҰ�� 0 ��ȯ
	*/
	int Get(ItemType &item);

	/**
	*	@brief	����Ʈ �� ��� ���ڵ� ��� (T�� ���� ��� ���� �ٸ�)
	*	@pre	����Ʈ �ʱ�ȭ
	*	@post	����Ʈ �� ��� ���� (ItemType�� ����) ���
	*/
	void DisplayAll();

	/**
	*	@brief	����Ʈ �� ��� ���ڵ� ������ ��� (T�� ���� ��� ���� �ٸ�)
	*	@pre	����Ʈ �ʱ�ȭ
	*	@post	����Ʈ �� ��� ���� (ItemType�� ���� ������) ���
	*/
	void DisplayAllBrief();

	/**
	*	@brief	�Է��� ���� node�� Tree���� �˻���
	*	@pre	ã���� �ϴ� item�� �˻������ ���� found ����
	*	@post	node�� Tree�� �ִ��� �˻������ �˷���
	*/
	void RetrieveItem(ItemType& item, bool &found);

	/**
	*	@brief	Tree�� node�� ��ũ���� ����Ѵ�.
	*	@pre	none
	*	@post	��ũ���� Tree�� InOrder, PreOrder, PostOrder ������� ���� ��µ�.
	*/
	void PrintTree(ostream &out);

	///**
	//*	@brief	����Ʈ ���� ��� ������ �̸��� Ʈ��������� ���
	//*	@pre	����Ʈ �ʱ�ȭ
	//*	@post	����Ʈ ���� ��� ������ �̸��� �� �پ� Ʈ��������� ��µ�
	//*	@param	level	����Ʈ�� �ܰ�(0�ܰ� �ֻ���~n�ܰ�)
	//*/
	//void DisplayAllStructure(int level);

	///**
	//*	@brief	����Ʈ ���� ��� ������ �̸��� Ʈ��������� ���(��������Ʈ ����)
	//*	@pre	(�ֻ���) ����Ʈ �ʱ�ȭ
	//*	@post	DisplayAllStructure�� Ȱ���� ��� ����Ʈ ������ Ʈ��������� ���
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
	Node<ItemType>* root;		///< Node Ÿ���� root
	string TName;	///< Ʈ�� ��� ������ Ÿ���̸�

	/**
	*	@brief	root �Ʒ��� �� item�� �߰��Ѵ�(�����)
	*	@pre	Add�� ���� ȣ��
	*	@post	root �Ʒ��� �� itme�� �߰���
	*/

};

// ������
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

// Tree�� ����ִ��� Ȯ��
template<class ItemType>
bool BinarySearchTree<ItemType>::IsEmpty()
{
	if (root == NULL)			// root ��尡 NULL�� ��� true ����
		return true;
	else
		return false;			// root ��尡 NULL�� �ƴ� ��� false ����
}

// Tree�� Full���� Ȯ��
template<class ItemType>
bool BinarySearchTree<ItemType>::IsFull()
{
	Node* room;					// �ӽ��� node�� �����
	try
	{
		room = new Node;		// �� ��带 �߰��� �� �ִ��� Ȯ��
		delete room;			// �ӽ÷� ���� room ��带 ����
		return false;			// isFull�� ���� false ����
	}
	catch (std::bad_alloc exception)		// �� �̻� ������ �߰��� �� �� ���� Full�� ���
	{
		return true;					// isFull�� ���� true ����
	}
}

// Tree�� ���
template<class ItemType>
void BinarySearchTree<ItemType>::MakeEmpty()
{
	MakeEmptyTree(root);				// Tree �ʱ�ȭ �Լ� ȣ��
}

// Tree�� node������ �˷���
template<class ItemType>
int BinarySearchTree<ItemType>::GetLength()
{
	return CountNodes(root);			// node ������ ���� �Լ� ȣ��
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
	//height ����
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
	//height ����
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

// Tree�� ���ο� node �߰�
template<class ItemType>
int BinarySearchTree<ItemType>::Add(ItemType item)
{
	// �� node �߰��ϴ� �Լ� ȣ��
	if (Insert(root, item) != 1)
		return 0;
	else
		return 1;
}

// Tree�� node�� ����
template<class ItemType>
int BinarySearchTree<ItemType>::Delete(ItemType item)
{
	if (DeleteItem(root, item) != 1)
		return 0;					// �����ϴ� node �����ϴ� �Լ��� ȣ��
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
		cout << "\t-----Messege-----\n\t����Ʈ�� ��� �ֽ��ϴ�.\n\t-----Messege-----" << endl;
	return;
}

template<class ItemType>
void BinarySearchTree<ItemType>::DisplayAllBrief()
{
	if (!IsEmpty())
		PrintInOrderTraversalBrief(root);
	else
		cout << "\t-----Messege-----\n\t����Ʈ�� ��� �ֽ��ϴ�.\n\t-----Messege-----" << endl;
	return;
}

// Tree���� ã���� �ϴ� ���� node�� �˻�
template<class ItemType>
void BinarySearchTree<ItemType>::RetrieveItem(ItemType& item, bool &found)
{
	Retrieve(root, item, found);		// Tree �˻� �Լ� ȣ��
}

// Tree�� node�� ������ ������ �����
template<class ItemType>
void BinarySearchTree<ItemType>::PrintTree(ostream &out)
{
	cout << "[InOrder]" << endl;
	PrintInOrderTraversal(root);			// InOrder ������� ���
	cout << endl << "[PreOrder]" << endl;
	PrintPreOrderTraversal(root);			// PreOrder ������� ���
	cout << endl << "[PostOrder]" << endl;
	PrintPostOrderTraversal(root);			// PostOrder ������� ���
}

// BinarySearchTree�� ���ο� ��� �߰�
template<class ItemType>
int BinarySearchTree<ItemType>::Insert(Node<ItemType>*& root, ItemType item)
{
	int added = 0;
	if (root == NULL)				// root�� null�� ��� 
	{
		root = new Node<ItemType>;	// root ��� ����
		root->left = NULL;			// root ����̹Ƿ� left�� right�� NULL�� ����
		root->right = NULL;
		root->data = item;			// root ����� ��
		root->height = 0;
		added = 1;
	}

	else if (root->data > item)		// root�� �����ϰ�, �� ���� ���ο� item ������ Ŭ ��
	{
		added = Insert(root->left, item);	// root�� �������� Insert �Լ� �ٽ� ȣ��
		if (GetHeight(root->left) - GetHeight(root->right) == 2)	// rotation
		{
			if (item < root->left->data)
				root = single_rotation_right(root);
			else
				root = double_rotation_left(root);
		}
	}
	else if (root->data < item)		// root�� �����ϰ�, �� ���� ���ο� item ������ ���� ��
	{
		added = Insert(root->right, item);	// root�� ���������� Insert �Լ� �ٽ� ȣ��
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
	if (root == NULL)						// root�� NULL�� ��� ã�� item ����(NULL����)
		return NULL;
	else if (item < root->data)				// ã���� �ϴ� �����۰��� root������ ���� �� 
		return RetrieveP(root->left, item);	// ���� ���� ���� retrieve �Լ� ȣ��
	else if (item > root->data)				// ã���� �ϴ� �����۰��� root������ Ŭ ��
		return RetrieveP(root->right, item);	// ������ ���� ���� retrieve �Լ� ȣ��
	else
	{										// ã���� �ϴ� ���� ��ġ�� ��
		item = root->data;					// item�� ��� ������ ����
		return &(root->data);				// item �ּ� ����
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
	if (root != NULL)								// root�� �����ϴ� ���
	{
		InsertAll(root->left, tree);		// root�� �������� ���� �ٽ� InOrder �Լ� ȣ��
		tree->Add(root->data);			// root ���
		InsertAll(root->right, tree);	// root�� ���������� ���� �ٽ� InOrder �Լ� ȣ��
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
	if (root != NULL)// root�� �����ϴ� ���
	{
		AddNodeToVec(root->left, vec, t);		// root�� �������� ���� �ٽ� InOrder �Լ� ȣ��
		(*vec)[t] = &(root->data);		// root ���
		t++;
		AddNodeToVec(root->right, vec, t);	// root�� ���������� ���� �ٽ� InOrder �Լ� ȣ��
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
		if (root != NULL)								// root�� �����ϴ� ���
		{
			found += NameSearchRecur(f, root->left);		// root�� �������� ���� �ٽ� InOrder �Լ� ȣ��
			if (root->data.NameFind(f))			// root ���
				found++;
			found += NameSearchRecur(f, root->right);	// root�� ���������� ���� �ٽ� InOrder �Լ� ȣ��
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
// Tree�� �ʱ�ȭ�ϴ� �Լ�
template<class ItemType>
void MakeEmptyTree(Node<ItemType>*& root)
{
	root = NULL;			// root ��带 Null�� ��
}

// Tree�� node ������ ���� �Լ�
template<class ItemType>
int CountNodes(Node<ItemType>* root)
{
	if (root == NULL)		// root ��尡 null�ϰ�� 0�� ����
		return 0;
	else
		return CountNodes(root->left) + CountNodes(root->right) + 1;		// ����� ����, �����ʿ� ���� ����� ȣ��� root�� �ش��ϴ� 1�� ���ؼ� ���� ����
}



// ���� ū ���� ã�� �Լ� 
template<class ItemType>
void GetPredecessor(Node<ItemType> *root, ItemType& item)
{
	while (root->right != NULL)			// root�� �������� ������ ���
		root = root->right;				// root�� ������ ��尪�� root�� ������ �Ѵ�
	item = root->data;					// root ����� ���� item�� �����Ѵ�.
}

// ������� ��带 ã���� ������ Ʈ������ �� ��带 ����� �Լ�
template<class ItemType>
void DeleteNode(Node<ItemType> *&root)
{
	ItemType item;
	Node<ItemType>* tempPtr;			// �ӽ� ��带 �����ϰ� root ��带 �ӽ� ��忡 ����
	tempPtr = root;

	if (root->left == NULL)				// ���ʳ�尡 ���� ��
	{
		root = root->right;				// ������ ��尡 root�� �ǵ��� �����ϰ� �ӽó�带 ����
		delete tempPtr;
	}
	else if (root->right == NULL)		// �����ʳ�尡 ���� ��
	{
		root = root->left;				// ���� ��尡 root�� �ǵ��� �����ϰ� �ӽó�带 ����
		delete tempPtr;
	}
	else
	{
		GetPredecessor(root->left, item);	// �߰��� �ִ� ��带 ����� ���� �� (left, right, child ��� ���� ���)
		root->data = item;					// ������� ��庸�� ���� ���� �߿� ���� ū ��带 ã��
		DeleteItem(root->left, item);			// �� ���� ���� ��忡 ���縦 �ؼ� ���� ��ó��
	}
}

// ���� ������� �ϴ� ��带 ã�� recursive �Լ�
template<class ItemType>
int DeleteItem(Node<ItemType> *&root, ItemType item)
{
	if (root == NULL)
		return 0;
	else if (item < root->data)				// root��尪���� item��尡 ���� ��
		DeleteItem(root->left, item);		// ���ʳ��� ���� delete�Լ� ȣ��
	else if (item > root->data)			// root��尪���� item��尡 Ŭ ��
		DeleteItem(root->right, item);		// �����ʳ��� ���� delete�Լ� ȣ��
	else
	{
		DeleteNode(root);				// ã���� �ϴ� ���� ��ġ�ϴ� ��� deletenode �Լ� ȣ��
		return 1;
	}
}

// Tree���� node�� �˻��ϴ� �Լ�
template<class ItemType>
void Retrieve(Node<ItemType> *root, ItemType& item, bool &found)
{
	if (root == NULL)						// root�� NULL�� ��� found�� false 
		found = false;
	else if (item < root->data)				// ã���� �ϴ� �����۰��� root������ ���� �� 
		Retrieve(root->left, item, found);	// ���� ���� ���� retrieve �Լ� ȣ��
	else if (item > root->data)				// ã���� �ϴ� �����۰��� root������ Ŭ ��
		Retrieve(root->right, item, found);	// ������ ���� ���� retrieve �Լ� ȣ��
	else
	{										// ã���� �ϴ� ���� ��ġ�� ��
		item = root->data;					// item�� ��� ������ ����
		found = true;						// found���� true�� �ؼ� ã�� ������ ����
	}
}

// InOrder ������� ����ϴ� �Լ� 
template<class ItemType>
void PrintInOrderTraversal(Node<ItemType>* root)
{
	if (root != NULL)								// root�� �����ϴ� ���
	{
		PrintInOrderTraversal(root->left);		// root�� �������� ���� �ٽ� InOrder �Լ� ȣ��
		root->data.DisplayRecordOnScreen();			// root ���
		PrintInOrderTraversal(root->right);	// root�� ���������� ���� �ٽ� InOrder �Լ� ȣ��
	}
}

// InOrder ������� ������ ����ϴ� �Լ� 
template<class ItemType>
void PrintInOrderTraversalBrief(Node<ItemType>* root)
{
	if (root != NULL)								// root�� �����ϴ� ���
	{
		PrintInOrderTraversalBrief(root->left);		// root�� �������� ���� �ٽ� InOrder �Լ� ȣ��
		root->data.DisplayBriefOnScreen();		// root ���
		PrintInOrderTraversalBrief(root->right);	// root�� ���������� ���� �ٽ� InOrder �Լ� ȣ��
	}
}

// PreOrder ������� ����ϴ� �Լ�
template<class ItemType>
void PrintPreOrderTraversal(Node<ItemType>* root)
{
	if (root != NULL)								// root�� �����ϴ� ���
	{
		root->data.DisplayRecordOnScreen();			// root ���
		PrintPreOrderTraversal(root->left);	// root�� �������� ���� PreOrder �Լ� �ٽ� ȣ��
		PrintPreOrderTraversal(root->right);	// root�� ���������� ���� PreOrder �Լ� �ٽ� ȣ��
	}
}

// PostOrder ������� ����ϴ� �Լ�
template<class ItemType>
void PrintPostOrderTraversal(Node<ItemType>* root)
{
	if (root != NULL)								// root�� �����ϴ� ���
	{
		PrintPostOrderTraversal(root->left);	// root�� �������� ���� �ٽ� PostOrder �Լ� ȣ��
		PrintPostOrderTraversal(root->right);	// root�� ���������� ���� �ٽ� PostOrder �Լ� ȣ��
		root->data.DisplayRecordOnScreen();			// root ���
	}
}

#endif