#include "../Header Files/HashTable.h"
#include "../Header Files/Dictionary.h"

Dictionary::Dictionary(int initialSize): _dictionary(initialSize) {}

void Dictionary::Insert(std::string& key, std::string& value)
{
	_dictionary.Insert(key, value);
}

void Dictionary::Remove(std::string& key)
{
	_dictionary.Remove(key);
}

std::string Dictionary::Find( std::string& key)
{
	return _dictionary.Find(key);
}

Dictionary::~Dictionary()
{
	_dictionary.~HashTable();
}

int Dictionary::GetSize()
{
	return _dictionary.Size;
}

int Dictionary::GetCount()
{
	return _dictionary.Count;
}

HashTableItem* Dictionary::GetBucket(int index)
{
	return _dictionary.GetBucket(index);
}