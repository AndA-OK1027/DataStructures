#include "..\Header Files\HashTable.h"
#include <string>

using namespace std;

// \!brief Начальная емкость хеш-таблицы
const int INITIAL_CAPACITY = 12; 
// \!brief Порог загрузки для перехеширования
const double LOAD_FACTOR = 0.7; 

HashTable::HashTable(int size) : Capacity(INITIAL_CAPACITY), Size(size), Count(0)
{
	Table = new Item * [Size];
	memset(Table, 0, Size * sizeof(Item*));
}

Item::Item(string key, string value) : key(key), value(value), next(nullptr) {}

int HashTable::Hash(string key) 
{
	int hash = 0;

	for (char ch : key)
	{
		hash = (hash * 1664525) + static_cast<unsigned char>(ch) + 1013904223;
	}

	return hash;
}

int HashTable::GetIndex(string key)
{
	return Hash(key) % Size;
}

void HashTable::Rehash()
{
	// Увеличиваем размер в 2 раза.
	int oldSize = Size;
	Size *= 2; 
	// Выделяем память под новую таблицу, оставляя старую
	Item** newTable = new Item * [Size];
	memset(newTable, 0, Size * sizeof(Item*));

	for (int i = 0; i < oldSize; ++i) 
	{
		Item* current = Table[i];
		while (current)
		{
			int newIndex = GetIndex(current->key);
			Item* next = current->next;

			current->next = newTable[newIndex];
			newTable[newIndex] = current;

			current = next;
		}

		delete[] Table;
		Table = newTable;
	}
}

void HashTable::Insert(string key, string value)
{
	int index = GetIndex(key);

	// Проверка на дубликаты.
	for (Item* current = Table[index]; current != nullptr; current = current->next)
	{
		if (current->key == key)
		{
			return;
		}
	}

	Item* newItem = new Item(key, value);
	newItem->next = Table[index];
	Table[index] = newItem;
	Count++;
	
	// При привышениии коэффициэнта загрузки перехэширование.
	if (Count / Size >= LOAD_FACTOR)
	{
		Rehash();
	}
}

void HashTable::Remove(string key)
{
	int index = GetIndex(key);
	Item* current = Table[index];
	Item* prev = nullptr;

	while (current != nullptr)
	{
		if (current->key == key)
		{
			if (prev != nullptr)
			{
				prev->next = current->next;
			}
			else
			{
				Table[index] = current->next;
			}

			delete current;
			Count--;
			return;
		}

		prev = current;
		current = current->next;
	}
}

string HashTable::Find(const std::string& key)
{
	int index = GetIndex(key);

	for (Item* current = Table[index]; current != nullptr; current = current->next)
	{
		if (current->key == key)
		{
			return current->value;
		}
	}

	return "";
}

Item* HashTable::GetBucket(int index) 
{
	// Получаем элемент внутреннего массива по индексу.
	return Table[index];
}

HashTable::~HashTable()
{
	for (int i = 0; i < Size; i++)
	{
		Item* current = Table[i];
		while (current != nullptr)
		{
			Item* next = current->next;
			delete current;
			current = next;
		}
	}

	delete[] Table;
}