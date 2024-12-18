#pragma once
#include <string>

using namespace std;

// \!brief ����������� ��������� �������� �������.
struct Item
{
	// \!brief ����
	string key;
	 
	// \!brief ��������
	string value;

	// \!brief ��������� �� �������� �������.
	Item* next;

	// \!brief ����������� �������.
	Item(string key, string value);
};

struct HashTable
{
public:

	// \!brief ������������ ������.
	int Capacity;

	// \!brief ������ ������ �������.
	int Size;

	// \!brief ���������� ���������
	int Count;

	// \!brief ����������� ���-�������.
	HashTable(int size);

	// \!brief ������ ���������� �� �������� ���-�������.
	Item** Table;

	// \!brief ��������������� ������� ��� ���������� ������� �������� � �������.
	int GetIndex(string key);

	// \!brief ���-�������
	int Hash(string key);

	// \!brief ���������������
	void Rehash();

	// \!brief ������� ��������.
	void Insert(string key, string value);

	// \!brief �������� ��������.
	void Remove(string key);

	// \!brief ����� ��������.
	string Find(const std::string& key);

	// \!brief ��������������� ������� ��� ��������� �������� �� �������.
	Item* GetBucket(int index);

	// \!brief ����������.
	~HashTable();
};