#pragma once
#include <string>

using namespace std;

// !\brief Определение структуры элемента таблицы.
struct HashTableItem
{
	// !\brief Ключ
	string Key;
	 
	// !\brief Значение
	string Value;

	// !\brief Указатель на следующую пару.
	HashTableItem* Next;

	// !\brief Конструктор элемета.
	// !\param key - ключ.
	// !\param value - значение.
	HashTableItem(string key, string value);

	// !\brief Конструктор элемета.
	HashTableItem();
};
