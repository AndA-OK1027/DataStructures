#include <iostream>
#include "..\Header Files\HashTable.h"
#include "../Header Files/Dictionary.h"
#include <string>

using namespace std;

// !\brief ��������� ���� ������������ �� �������� ��������.
// !\returns �����, ��������� �������������, ���� ������� ������������� ������ �� �������. 
int CheckInput()
{
	cout << "��� ����: ";

	string input;

	while (true)
	{
		try
		{
			cin >> input;
			size_t pos;
			// ������� ������������� ������ � �����
			int value = stoi(input, &pos);
			// �������� �� ��, ��� �� ������� ������ �������������.
			if (pos == input.length())
			{
				return value;
			}
			else
			{
				std::cout << "������� �������� �������� (���������� �������). ��������� ����: ";
			}
		}
		catch (std::invalid_argument& e)
		{
			std::cout << "������� �������� �������� (�� �����). ��������� ����: ";
		}

	}
}

// !\brief ����� ���-������� � �������.
// !\param dict - �������.
void Print(Dictionary& dict)
{
	cout << "���-�������:" << endl;
	for (size_t i = 0; i < dict.GetSize(); ++i)
	{
		cout << i << ": ";
		HashTableItem* current = dict.GetBucket(i);

		if (current == nullptr)
		{
			cout << "�����";
		}
		else
		{
			for (; current != nullptr; current = current->Next)
			{
				cout << "[" << current->Key << "] -> " << current->Value;
				if (current->Next != nullptr)
				{
					cout << "; ";
				}
			}
		}

		cout << endl;
	}

	cout << "�������:" << endl;
	for (size_t i = 0; i < dict.GetSize(); ++i)
	{
		HashTableItem* current = dict.GetBucket(i);

		for (; current != nullptr; current = current->Next)
		{
			std::cout << current->Key << ": " << current->Value << std::endl;
		}
	}
}

// !\brief ������� ����.
int main()
{
	setlocale(LC_ALL, "ru");

	Dictionary* dict = new Dictionary(8);

	Print(*dict);

	int userChoice;

	do
	{
		cout << "�������� ��������." << endl;
		cout << "0. �����" << endl;
		cout << "1. �������� �������" << endl;
		cout << "2. ������� �������" << endl;
		cout << "3. ����� �������" << endl;
		userChoice = CheckInput();

		switch (userChoice)
		{

		case 0:
		{
			delete dict;
			break;
		}

		case 1:
		{
			string addKey;
			string addValue;
			cout << "1. �������� �������" << endl;
			cout << "������� ����." << endl;
			cin >> addKey;
			cout << "������� ��������." << endl;
			cin >> addValue;
			dict->Insert(addKey, addValue);
			Print(*dict);

			break;
		}

		case 2:
		{
			string deleteKey;
			cout << "2. ������� �������" << endl;
			cout << "������� ����." << endl;
			cin >> deleteKey;
			dict->Remove(deleteKey);
			Print(*dict);

			break;
		}

		case 3:
		{
			string findKey;
			string foundValue;

			cout << "3. ����� �������" << endl;
			cout << "������� ����." << endl;
			cin >> findKey;
			foundValue = dict->Find(findKey);

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
	} while (userChoice != 0);

	return 0;
}