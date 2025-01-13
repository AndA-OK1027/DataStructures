#include <iostream>
#include <memory>
#include <utility>
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

TreapNode* Treap::InsertNodeNotOptimized(TreapNode*& node, int key)
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

TreapNode* Treap::InsertNodeOptimized(TreapNode*& node, int key)
{
	TreapNode* newNode = new TreapNode(key);

	if (node == nullptr)
	{
		return newNode;
	}

	if (node->Priority > newNode->Priority)
	{
		TreapNode* current = node;
		while (true)
		{
			if (key < current->Key)
			{
				TreapNode* left = current->Left;
				if (!left)
				{
					current->Left = newNode;
					break;
				}
				current = left;
			}
			else
			{
				TreapNode* right = current->Right;
				if (!right)
				{
					current->Right = newNode;
					break;
				}
				current = right;
			}
		}
	}
	else
	{
		TreapNode* leftTemp = nullptr;
		TreapNode* rightTemp = nullptr;

		Split(Root, key, leftTemp, rightTemp);

		newNode->Left = leftTemp;
		newNode->Right = rightTemp;

		return newNode;
	}
}

TreapNode* Treap::RemoveNodeNotOptimized(TreapNode*& node, int key)
{
	if (node == nullptr)
	{
		return node;
	}

	TreapNode* left = nullptr;
	TreapNode* right = nullptr;
	TreapNode* equal = nullptr;

	Split(node, key, left, right);

	Split(right, key + 1, equal, right);

	if (equal == nullptr)
	{
		return nullptr;
	}
	else
	{
		delete equal;
		equal = nullptr;
	}

	return Merge(left, right);
}

TreapNode* Treap::RemoveNodeOptimized(TreapNode*& node, int key)
{
	if (node == nullptr)
	{
		return node;
	}

	if (key > node->Key)
	{
		TreapNode* rightChild = node->Right;
		RemoveNodeOptimized(rightChild, key);
		node->Right = rightChild;
	}
	else if (key < node->Key)
	{
		TreapNode* leftChild = node->Left;
		RemoveNodeOptimized(leftChild, key);
		node->Left = leftChild;
	}
	else
	{
		TreapNode* temp = node;
		TreapNode* result = Merge(node->Left, node->Right);
		node = result;
		return node;
		delete temp;
	}
}

void Treap::InsertNotOptimized(int key)
{
	Root = InsertNodeNotOptimized(Root, key);
}

void Treap::Insert(int key)
{
	Root = InsertNodeOptimized(Root, key);
}

void Treap::RemoveNotOptimized(int key)
{
	if (RemoveNodeNotOptimized(Root, key) == nullptr)
	{
		return;
	}
	else
	{
		Root = RemoveNodeNotOptimized(Root, key);
	}
}

void Treap::Remove(int key)
{
	if (RemoveNodeOptimized(Root, key) == nullptr)
	{
		return;
	}
	else
	{
		Root = RemoveNodeOptimized(Root, key);
	}
}

TreapNode* Treap::Search(int key) const
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