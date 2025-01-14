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

	TreapNode* current = node;
	while (true)
	{
		if (key < current->Key)
		{
			if (current->Left == nullptr)
			{
				break;
			}

			current = current->Left;
		}
		else
		{
			if (current->Right == nullptr)
			{
				break;
			}

			current = current->Right;
		}
	}

	if (node == nullptr || Root->Priority < newNode->Priority)
	{
		Split(current, key, newNode->Left, newNode->Right);
		Root = newNode;
	}
	else if (current->Key > newNode->Key)
	{
		Split(current->Left, key, newNode->Left, newNode->Right);
		current->Left = newNode;
	}
	else
	{
		Split(current->Right, key, newNode->Left, newNode->Right);
		current->Right = newNode;
	}

	return newNode;
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

	TreapNode* current = Root;
	while (current != nullptr && current->Key != key)
	{
		if (current->Key > key)
		{
			if (current->Left == nullptr ||
				current->Left->Key == key) break;

			current = current->Left;
		}
		else
		{
			if (current->Right == nullptr ||
				current->Right->Key == key) break;

			current = current->Right;
		}
	}

	TreapNode* temp;
	if (current == Root && current->Key == key)
	{
		temp = current;
		Root = Merge(temp->Left, temp->Right);
	}
	else if (current->Key > key)
	{
		if (current->Left == nullptr)
		{
			return false;
		}
		temp = current->Left;
		current->Left = Merge(temp->Left, temp->Right);
	}
	else
	{
		if (current->Right == nullptr)
		{
			return false;
		}
		temp = current->Right;
		current->Right = Merge(temp->Left, temp->Right);
	}

	delete temp;
	return node;
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