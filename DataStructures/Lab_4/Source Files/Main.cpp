#include <iostream>
#include "..\Header Files\HashTable.h"

using namespace std;

int main()
{
	HashTable* table = new HashTable();
	cout << table->Hash("yy") << endl;
	cout << table->Hash("6") << endl;
	cout << table->Hash("132442") << endl;
	cout << table->Hash("636") << endl;


	return 0;
}