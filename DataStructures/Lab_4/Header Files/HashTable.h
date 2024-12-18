#pragma once
#include <string>

using namespace std;

// \!brief Определение структуры элемента таблицы.
struct Item
{
	// \!brief Ключ
	string key;
	 
	// \!brief Значение
	string value;

	// \!brief Указатель на следущий элемент.
	Item* next;

	// \!brief Конструктор элемета.
	Item(string key, string value);
};

struct HashTable
{
public:

	// \!brief Максимальный размер.
	int Capacity;

	// \!brief Размер данной таблицы.
	int Size;

	// \!brief Количество элементов
	int Count;

	// \!brief Конструктор хэш-таблицы.
	HashTable(int size);

	// \!brief Массив указателей на элементы хэш-таблицы.
	Item** Table;

	// \!brief Вспомогательная функция для нахождения индекса элемента в таблице.
	int GetIndex(string key);

	// \!brief Хэш-функция
	int Hash(string key);

	// \!brief Перехэширование
	void Rehash();

	// \!brief Вставка элемента.
	void Insert(string key, string value);

	// \!brief Удаление элемента.
	void Remove(string key);

	// \!brief Поиск элемента.
	string Find(const std::string& key);

	// \!brief Вспомогательная функция для получения элемента по индексу.
	Item* GetBucket(int index);

	// \!brief Деструктор.
	~HashTable();
};