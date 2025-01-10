#pragma once
#include "..\Header Files\HashTableItem.h"
#include <string>

using namespace std;

// !\brief ����� �������� ��� ���������������
const double LOAD_FACTOR = 0.7;

struct HashTable
{
public:

	// !\brief ������ ������ �������.
	int Size;

	// !\brief ���������� ���������
	int Count;

	// !\brief ����������� ���-�������.
	HashTable(int size);

	// !\brief ������ ���������� �� �������� ���-�������.
	HashTableItem** Table;

	// !\brief ���-�������
	// !\param key - ����.
	// !\returns ���-�����.
	int Hash(string key);

	// !\brief ���������������
	void Rehash();

	// !\brief ������� ��������.
	// !\param key - ����.
	// !\param value - ��������.
	void Insert(string key, string value);

	// !\brief �������� ��������.
	// !\param key - ����.
	void Remove(string key);

	// !\brief ����� ��������.
	// !\param key - ����.
	// !\returns �������� ���������� �����.
	string Find(const std::string& key);

	// !\brief ��������� �������� �� �������.
	// !\param index - ������ �� �������� ����� ��������.
	// !\returns �������
	HashTableItem* GetBucket(int index);

	// !\brief ����������.
	~HashTable();
};