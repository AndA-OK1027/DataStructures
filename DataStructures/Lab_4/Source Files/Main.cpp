#include <iostream>
#include "..\Header Files\HashTable.h"
#include <string>

using namespace std;

// \!brief ����� ���� ����� ���-�������.
void PrintTable(HashTable& table)
{
	cout << "���-�������:" << endl;
	for (int i = 0; i < table.Size; ++i)
	{
		cout << i << ": ";
		Item* current = table.GetBucket(i);

		if (current == nullptr)
		{
			cout << "�����";
		}
		else
		{
			for (; current != nullptr; current = current->next)
			{
				cout << "[" << current->key << "] -> " << current->value;
				if (current->next != nullptr)
				{
					cout << "; ";
				}
			}
		}
		cout << endl;
	}
}

// \!brief ����� �������.
void PrintDictionary(HashTable& dict)
{
	cout << "�������:" << endl;
	for (int i = 0; i < dict.Size; ++i)
	{
		Item* current = dict.GetBucket(i);

		for (; current != nullptr; current = current->next)
		{
			std::cout << current->key << ": " << current->value << std::endl;
		}
	}
}

// \!brief ����� � ���-������� � �������.
void Print(HashTable& dict)
{
	PrintTable(dict);
	cout << endl;
	PrintDictionary(dict);
}

int main()
{
	setlocale(LC_ALL, "ru");
	HashTable* table = new HashTable(8);
	table->Insert("ty", "5");
	table->Insert("yt", "6");
	Print(*table);

	int userChoice;
	while (true)
	{
		cout << "�������� ��������." << endl;
		cout << "1. �������� �������" << endl;
		cout << "2. ������� �������" << endl;
		cout << "3. ����� �������" << endl;
		cin >> userChoice;

		string addKey;
		string deleteKey;
		string findKey;
		string addValue;
		string foundValue;

		switch (userChoice)
		{

		case 1:
		{
			cout << "1. �������� �������" << endl;
			cout << "������� ����." << endl;
			cin >> addKey;
			cout << "������� ��������." << endl;
			cin >> addValue;
			table->Insert(addKey, addValue);
			Print(*table);

			break;
		}

		case 2:
		{
			cout << "2. ������� �������" << endl;
			cout << "������� ����." << endl;
			cin >> deleteKey;
			table->Remove(deleteKey);
			Print(*table);

			break;
		}

		case 3:
		{
			cout << "3. ����� �������" << endl;
			cout << "������� ����." << endl;
			cin >> findKey;
			foundValue = table->Find(findKey);

			if (foundValue != "")
			{
				cout << "��������: " << foundValue << endl;
			}
			else
			{
				cout << "������� �� ������." << endl;
			}

			break;
		}

		default:
		{
			cout << "�������� ��������� ��������.." << endl;
			break;
		}

		}
	}

	return 0;
}