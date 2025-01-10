#pragma once
#include <string>
#include "HashTable.h"

struct Dictionary 
{
	// !\brief ���������� ���-�������.
	HashTable _dictionary;

	// !\brief �����������.
	Dictionary(int initialSize);

	// !\brief ������� ��������.
	// !\param value - ��������.
	void Insert(std::string& key, std::string& value);

	// !\brief �������� ��������.
	// !\param key - ����.
	void Remove(std::string& key);

	// !\brief ����� ��������.
	// !\param key - ����.
	// !\returns �������� ���������� �����.
	std::string Find(std::string& key);

	// !\brief ���������� ������ �������.
	// !\returns �������
	int GetSize();

	// !\brief ���������� ���-�� ��-��� �������.
	// !\returns �������
	int GetCount();

	// !\brief ��������� �������� �� �������.
	// !\param index - ������ �� �������� ����� ��������.
	// !\returns �������
	HashTableItem* GetBucket(int index);

	// !\brief ����������.
	~Dictionary();
};