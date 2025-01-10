#pragma once
#include <string>

using namespace std;

// !\brief ����������� ��������� �������� �������.
struct HashTableItem
{
	// !\brief ����
	string Key;
	 
	// !\brief ��������
	string Value;

	// !\brief ��������� �� ��������� ����.
	HashTableItem* Next;

	// !\brief ����������� �������.
	// !\param key - ����.
	// !\param value - ��������.
	HashTableItem(string key, string value);

	// !\brief ����������� �������.
	HashTableItem();
};
