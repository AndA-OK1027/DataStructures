#include "../Header Files/HashTable.h"
#include "../Header Files/Dictionary.h"

Dictionary::Dictionary(int initialSize)
{
	_dictionary = new HashTable(initialSize);
}

void Dictionary::Insert(const string& key, std::string& value)
{
	_dictionary->Insert(key, value);
}

void Dictionary::Remove(const string& key)
{
	_dictionary->Remove(key);
}

std::string Dictionary::Find(const std::string& key)
{
	return _dictionary->Find(key);
}

Dictionary::~Dictionary()
{
	delete _dictionary;
}

int Dictionary::GetSize()
{
	return _dictionary->Size;
}

int Dictionary::GetCount()
{
	return _dictionary->Count;
}

HashTableItem* Dictionary::GetBucket(int index)
{
	return _dictionary->GetBucket(index);
}