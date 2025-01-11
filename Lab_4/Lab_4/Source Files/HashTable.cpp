#include "..\Header Files\HashTable.h"
#include "..\Header Files\HashTableItem.h"
#include <vector>
#include <random>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

HashTable::HashTable(int size) : Size(size), Count(0)
{
	Table = new HashTableItem* [Size]();
	for (size_t i = 0; i < Size; ++i) 
	{
		Table[i] = nullptr;
	}
}

int HashTable::Hash(string key) 
{
	// TODO: Вынести число 256 в константу
	std::vector<int> table(256);
	for (int i = 0; i < 256; ++i) 
	{
		table[i] = i;
	}
	// Используем случайное устройство дл¤ генерации случайных чисел
	std::random_device rd;
	std::default_random_engine engine(rd());
	std::shuffle(table.begin(), table.end(), engine);

	// Длина сообщени¤ по модулю 256
	int hash = key.length() % 256; 
	for (char i : key)
	{
		hash = table[(hash + static_cast<int>(i)) % 256]; 
	}
	return hash;
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

void HashTable::Insert(string key, string value)
{
	int index = Hash(key) % Size;

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

void HashTable::Remove(string key)
{
	int index = Hash(key) % Size;
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

string HashTable::Find(const std::string& key)
{
	int index = Hash(key) % Size;

	for (HashTableItem* current = Table[index]; current != nullptr; current = current->Next)
	{
		if (current->Key == key)
		{
			return current->Value;
		}
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