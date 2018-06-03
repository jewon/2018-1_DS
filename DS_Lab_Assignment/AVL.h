#pragma once
#include "ConferenceType.h"
#include <iostream>
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
	bool IsEmpty()const;

	/**
	*	@brief	Tree�� Full���� Ȯ��
	*	@pre	none
	*	@post	none
	*	@return	Tree�� Full�̸� true ����, �ƴϸ� false ����
	*/
	bool IsFull()const;

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
	int GetLength() const;

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
	void RetrieveItem(ItemType& item, bool &found)const;

	/**
	*	@brief	Tree�� node�� ��ũ���� ����Ѵ�.
	*	@pre	none
	*	@post	��ũ���� Tree�� InOrder, PreOrder, PostOrder ������� ���� ��µ�.
	*/
	void PrintTree(ostream &out) const;

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

private:
	Node<ItemType>* root;		///< Node Ÿ���� root
	string TName;	///< Ʈ�� ��� ������ Ÿ���̸�
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
inline string BinarySearchTree<ItemType>::GetTName()
{
	return TName;
}

// Tree�� ����ִ��� Ȯ��
template<class ItemType>
bool BinarySearchTree<ItemType>::IsEmpty()const
{
	if (root == NULL)			// root ��尡 NULL�� ��� true ����
		return true;
	else
		return false;			// root ��尡 NULL�� �ƴ� ��� false ����
}

// Tree�� Full���� Ȯ��
template<class ItemType>
bool BinarySearchTree<ItemType>::IsFull()const
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
int BinarySearchTree<ItemType>::GetLength()const
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
Node<ItemType>* BinarySearchTree<ItemType>::single_rotation_left(Node<ItemType>* p)
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
Node<ItemType>* BinarySearchTree<ItemType>::single_rotation_right(Node<ItemType>* p)
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
	p->left = signle_rotation_left(p->left);
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
	Insert(root, item);					// �� node �߰��ϴ� �Լ� ȣ��
	return 1;
}

// Tree�� node�� ����
template<class ItemType>
int BinarySearchTree<ItemType>::Delete(ItemType item)
{
	DeleteItem(root, item);					// �����ϴ� node �����ϴ� �Լ��� ȣ��
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
inline void BinarySearchTree<ItemType>::DisplayAllBrief()
{
	if (!IsEmpty())
		PrintInOrderTraversalBrief(root);
	else
		cout << "\t-----Messege-----\n\t����Ʈ�� ��� �ֽ��ϴ�.\n\t-----Messege-----" << endl;
	return;
}

// Tree���� ã���� �ϴ� ���� node�� �˻�
template<class ItemType>
void BinarySearchTree<ItemType>::RetrieveItem(ItemType& item, bool &found)const
{
	Retrieve(root, item, found);		// Tree �˻� �Լ� ȣ��
}

// Tree�� node�� ������ ������ �����
template<class ItemType>
void BinarySearchTree<ItemType>::PrintTree(ostream &out)const
{
	cout << "[InOrder]" << endl;
	PrintInOrderTraversal(root);			// InOrder ������� ���
	cout << endl << "[PreOrder]" << endl;
	PrintPreOrderTraversal(root);			// PreOrder ������� ���
	cout << endl << "[PostOrder]" << endl;
	PrintPostOrderTraversal(root);			// PostOrder ������� ���
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

// BinarySearchTree�� ���ο� ��� �߰�
template<class ItemType>
void Insert(Node<ItemType>*& root, ItemType item)
{
	if (root == NULL)				// root�� null�� ��� 
	{
		root = new Node<ItemType>;	// root ��� ����
		root->left = NULL;			// root ����̹Ƿ� left�� right�� NULL�� ����
		root->right = NULL;
		root->data = item;			// root ����� ��
		root->height = 0;
	}
	else if (root->data > item)		// root�� �����ϰ�, �� ���� ���ο� item ������ Ŭ ��
	{
		Insert(root->left, item);	// root�� �������� Insert �Լ� �ٽ� ȣ��
			if (root->left->height - root->right->height == 2)
				if (item < root->left->data)

	}
	else if (root->data < item)		// root�� �����ϰ�, �� ���� ���ο� item ������ ���� ��
		Insert(root->right, item);	// root�� ���������� Insert �Լ� �ٽ� ȣ��
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
		Delete(root->left, item);			// �� ���� ���� ��忡 ���縦 �ؼ� ���� ��ó��
	}
}

// ���� ������� �ϴ� ��带 ã�� recursive �Լ�
template<class ItemType>
void DeleteItem(Node<ItemType> *&root, ItemType item)
{
	if (item < root->data)				// root��尪���� item��尡 ���� ��
		DeleteItem(root->left, item);		// ���ʳ��� ���� delete�Լ� ȣ��
	else if (item > root->data)			// root��尪���� item��尡 Ŭ ��
		DeleteItem(root->right, item);		// �����ʳ��� ���� delete�Լ� ȣ��
	else
		DeleteNode(root);				// ã���� �ϴ� ���� ��ġ�ϴ� ��� deletenode �Լ� ȣ��
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
		PrintInOrderTraversal(root->left);		// root�� �������� ���� �ٽ� InOrder �Լ� ȣ��
		root->data.DisplayBriefOnScreen();		// root ���
		PrintInOrderTraversal(root->right);	// root�� ���������� ���� �ٽ� InOrder �Լ� ȣ��
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