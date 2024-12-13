#pragma once
#include <string>

using namespace std;

struct HashTable
{
public:
	// !brief
	struct Item 
	{
		// !brief
		string key;

		// !brief
		string value;
	};

	// !brief
	Item* Items;

	// !brief
	int Hash(string key);

	// !brief
	void Rehash();

	// !brief
	void Insert(string key, string value);

};