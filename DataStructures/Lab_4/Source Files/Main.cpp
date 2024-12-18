#include <iostream>
#include "..\Header Files\HashTable.h"
#include <string>

using namespace std;

// \!brief Вывод всех ячеек хэш-таблицы.
void PrintTable(HashTable& table)
{
	cout << "Хэш-таблица:" << endl;
	for (int i = 0; i < table.Size; ++i)
	{
		cout << i << ": ";
		Item* current = table.GetBucket(i);

		if (current == nullptr)
		{
			cout << "Пусто";
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

// \!brief Вывод словаря.
void PrintDictionary(HashTable& dict)
{
	cout << "Словарь:" << endl;
	for (int i = 0; i < dict.Size; ++i)
	{
		Item* current = dict.GetBucket(i);

		for (; current != nullptr; current = current->next)
		{
			std::cout << current->key << ": " << current->value << std::endl;
		}
	}
}

// \!brief Вывод и хэш-таблицы и словаря.
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
		cout << "Выберите действие." << endl;
		cout << "1. Добавить элемент" << endl;
		cout << "2. Удалить элемент" << endl;
		cout << "3. Найти элемент" << endl;
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
			cout << "1. Добавить элемент" << endl;
			cout << "Введите ключ." << endl;
			cin >> addKey;
			cout << "Введите значение." << endl;
			cin >> addValue;
			table->Insert(addKey, addValue);
			Print(*table);

			break;
		}

		case 2:
		{
			cout << "2. Удалить элемент" << endl;
			cout << "Введите ключ." << endl;
			cin >> deleteKey;
			table->Remove(deleteKey);
			Print(*table);

			break;
		}

		case 3:
		{
			cout << "3. Найти элемент" << endl;
			cout << "Введите ключ." << endl;
			cin >> findKey;
			foundValue = table->Find(findKey);

			if (foundValue != "")
			{
				cout << "Значение: " << foundValue << endl;
			}
			else
			{
				cout << "Элемент не найден." << endl;
			}

			break;
		}

		default:
		{
			cout << "Выберите допутимое значение.." << endl;
			break;
		}

		}
	}

	return 0;
}