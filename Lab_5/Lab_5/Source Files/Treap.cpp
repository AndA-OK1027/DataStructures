#include <iostream>
#include <memory>
#include <cstdlib>
#include "../Header Files/Treap.h"

Treap::Treap() : Root(nullptr) {}

Treap::~Treap()
{
	Clear(Root);
}

void Treap::Split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right)
{
	if (node == nullptr)
	{
		left = right = nullptr;
	}
	else if (node->Key <= key)
	{
		Split(node->Right, key, node->Right, right);
		left = node;
	}
	else if (node->Key >= key)
	{
		Split(node->Left, key, left, node->Left);
		right = node;
	}
}

TreapNode* Treap::Merge(TreapNode* left, TreapNode* right)
{
	if (left == nullptr || right == nullptr)
	{
		return left == nullptr ? right : left;
	}
	if (left->Priority > right->Priority)
	{
		left->Right = Merge(left->Right, right);
		return left;
	}
	right->Left = Merge(left, right->Left);
	return right;
}

TreapNode* Treap::InsertNode(TreapNode*& node, int key)
{
	TreapNode* newNode = new TreapNode(key);
	// Если нет корня, создаем.
	if (node == nullptr)
	{
		return newNode;
	}

	// Делим дерево на правое и левое по x
	TreapNode* left;
	TreapNode* right;
	Split(node, key, left, right);

	// Сливаем левое поддерево с новым, затем получившиеся с правым. 
	return Merge(Merge(left, newNode), right);
}

TreapNode* Treap::RemoveNode(TreapNode*& node, int key)
{
	if (node == nullptr)
	{
		return node;
	}
	// 
	if (key < node->Key) 
	{
		node->Left = RemoveNode(node->Left, key);
	}
	else if (key > node->Key) 
	{
		node->Right = RemoveNode(node->Right, key);
	}
	else 
	{
		// Эл-т, который нужно удалить найден.
		if (!node->Left) 
		{
			TreapNode* right = node->Right;
			delete node;
			return right;
		}
		else if (!node->Right) 
		{
			TreapNode* left = node->Left;
			delete node;
			return left;
		}
		else 
		{
			// Если оба дочерних элемента.
			if (node->Left->Priority > node->Right->Priority) 
			{
				node->Left = RemoveNode(node->Left, key);
			}
			else 
			{
				node->Right = RemoveNode(node->Right, key);
			}
		}
	}
	return node;
}

void Treap::Insert(int key)
{
	Root = InsertNode(Root, key);
}

void Treap::Remove(int key)
{
	Root = RemoveNode(Root, key);
}

TreapNode* Treap::Search(int key)
{
	TreapNode* current = Root;
	while (current != nullptr) 
	{
		// Элемент найден?
		if (key == current->Key) return current;
		// Идем в лево если нужен меньший ключ и в право если наоборот.
		current = (key < current->Key) ? current->Left : current->Right;
	}
	// Элемент не найден.
	return nullptr;
}

void Treap::Clear(TreapNode* node)
{
	if (node != nullptr)
	{
		Clear(node->Left);
		Clear(node->Right);
		delete node;
	}
}