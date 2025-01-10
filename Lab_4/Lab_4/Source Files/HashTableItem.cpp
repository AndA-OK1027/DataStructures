#pragma once
#include "..\Header Files\HashTableItem.h"

HashTableItem::HashTableItem(string key, string value) : Key(key), Value(value), Next(nullptr) {}

HashTableItem::HashTableItem() : Key(""), Value(""), Next(nullptr) {}