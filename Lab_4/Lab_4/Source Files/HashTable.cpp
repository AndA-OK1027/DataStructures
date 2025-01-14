#include "..\Header Files\HashTable.h"
#include "..\Header Files\HashTableItem.h"
#include <vector>
#include <random>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int* HashTable::CreatePearsonTable()
{
	int* table = new int[PERMUTATIONS_TABLE_SIZE];
	for (int i = 0; i < PERMUTATIONS_TABLE_SIZE; ++i)
	{
		table[i] = i;
	}

	std::srand(std::time(0));
	for (int i = 0; i < PERMUTATIONS_TABLE_SIZE; ++i)
	{
		int j = std::rand() % PERMUTATIONS_TABLE_SIZE;
		std::swap(table[i], table[j]);
	}

	return table;
}

HashTable::HashTable(int size) : Size(size), Count(0)
{
	Table = new HashTableItem * [Size]();
	for (size_t i = 0; i < Size; ++i)
	{
		Table[i] = nullptr;
	}
	PearsonTable = CreatePearsonTable();
}

int HashTable::Hash(const string key) 
{	
	int hash = 0;
	for (char c : key)
	{
		hash = PearsonTable[(hash + c) % PERMUTATIONS_TABLE_SIZE];
	}

	return hash % Size;
}

void HashTable::Rehash()
{
	size_t oldSize = Size;
	Size *= 2;
	HashTableItem** newTable = new HashTableItem * [Size];

	for (size_t i = 0; i < Size; ++i)
	{
		Table[i] = nullptr;
	}

	for (size_t i = 0; i < oldSize; ++i)
	{
		HashTableItem* current = Table[i];
		while (current)
		{
			int newIndex = Hash(current->Key) % Size;
			HashTableItem* next = current->Next;

			current->Next = newTable[newIndex];
			newTable[newIndex] = current;

			current = next;
		}
	}

	delete[] Table;
	Table = newTable;
}

void HashTable::Insert(const string& key, const string& value)
{
	int index = Hash(key);

	// Проверка на дубликаты.
	for (HashTableItem* current = Table[index]; current != nullptr; current = current->Next)
	{
		if (current->Key == key)
		{
			return;
		}
	}

	HashTableItem* newItem = new HashTableItem(key, value);
	newItem->Next = Table[index];
	Table[index] = newItem;
	Count++;

	if (Count / Size >= LOAD_FACTOR)
	{
		Rehash();
	}
}

void HashTable::Remove(const string& key)
{
	int index = Hash(key);
	HashTableItem* current = Table[index];
	HashTableItem* prev = nullptr;

	while (current != nullptr)
	{
		if (current->Key == key)
		{
			if (prev != nullptr)
			{
				prev->Next = current->Next;
			}
			else
			{
				Table[index] = current->Next;
			}

			delete current;
			Count--;
			return;
		}

		prev = current;
		current = current->Next;
	}
}

string HashTable::Find(const string& key)
{
	int index = Hash(key);

	HashTableItem* current = Table[index];
	while (current)
	{
		if (current->Key == key) 
		{
			return current->Value;
		}
		current = current->Next;
	}

	return "";
}

HashTableItem* HashTable::GetBucket(int index)
{
	return Table[index];
}

HashTable::~HashTable()
{
	for (size_t i = 0; i < Size; i++)
	{
		HashTableItem* current = Table[i];
		while (current != nullptr)
		{
			HashTableItem* next = current->Next;
			delete current;
			current = next;
		}
	}

	delete[] Table;
}