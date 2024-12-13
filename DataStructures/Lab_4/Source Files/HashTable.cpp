#include "..\Header Files\HashTable.h"
#include <string>

using namespace std;

int Capacity = 32;

int Size = 0;

int HashTable::Hash(string key) 
{
	unsigned long hash = 0;
	for (char ch : key)
	{
		hash = (hash * 31 + ch) % Capacity;
	}
	return hash % Capacity;
}

void HashTable::Rehash()
{

}

void HashTable::Insert(string key, string value)
{

}