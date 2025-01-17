﻿#pragma once
#include <string>
#include "HashTable.h"

struct Dictionary 
{
	// !\brief Внутренняя хеш-таблица.
	HashTable* _dictionary;

	// !\brief Конструктор.
	Dictionary(int initialSize);

	// !\brief Вставка элемента.
	// !\param value - значение.
	void Insert(const std::string& key, std::string& value);

	// !\brief Удаление элемента.
	// !\param key - ключ.
	void Remove(const std::string& key);

	// !\brief Поиск элемента.
	// !\param key - ключ.
	// !\returns значение найденного ключа.
	std::string Find(const std::string& key);

	// !\brief Возвращает размер словаря.
	// !\returns Элемент
	int GetSize();

	// !\brief Возвращает кол-во эл-тов словаря.
	// !\returns Элемент
	int GetCount();

	// !\brief Получение элемента по индексу.
	// !\param index - индекс по которому нужно получить.
	// !\returns Элемент
	HashTableItem* GetBucket(int index);

	// !\brief Деструктор.
	~Dictionary();
};