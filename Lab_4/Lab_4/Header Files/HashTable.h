#pragma once
#include "..\Header Files\HashTableItem.h"
#include <string>

using namespace std;

// !\brief Порог загрузки для перехеширования
const double LOAD_FACTOR = 0.7;

// !\brief Перестановки.
const int PERMUTATIONS_TABLE_SIZE = 256;

struct HashTable
{
public:

	// !\brief Размер данной таблицы.
	int Size;

	// !\brief Количество элементов
	int Count;

	// !\brief Конструктор хэш-таблицы.
	HashTable(int size);

	// !\brief Массив указателей на элементы хэш-таблицы.
	HashTableItem** Table;

	// !\brief Хэш-функция
	// !\param key - ключ.
	// !\returns хеш-сумма.
	int Hash(string key);

	// !\brief Перехэширование
	void Rehash();

	// !\brief Вставка элемента.
	// !\param key - ключ.
	// !\param value - значение.
	void Insert(string& key, string& value);

	// !\brief Удаление элемента.
	// !\param key - ключ.
	void Remove(string& key);

	// !\brief Поиск элемента.
	// !\param key - ключ.
	// !\returns значение найденного ключа.
	string Find(const std::string& key);

	// !\brief Получение элемента по индексу.
	// !\param index - индекс по которому нужно получить.
	// !\returns Элемент
	HashTableItem* GetBucket(int index);

	// !\brief Деструктор.
	~HashTable();
};