#include <iostream>
#include "..\Header Files\HashTable.h"
#include "../Header Files/Dictionary.h"
#include <string>

using namespace std;
// TODO: Не работает удаление элементов таблици и словаря
// !\brief Проверяет ввод пользователя на числовое значение.
// !\returns Число, введенное пользователем, если успешно преобразована строка из консоли. 
int CheckInput()
{
	cout << "Ваш ввод: ";

	string input;

	while (true)
	{
		try
		{
			cin >> input;
			size_t pos;
			// попытка преобразовать строку в число
			int value = stoi(input, &pos);
			// проверка на то, все ли символы строки преобразованы.
			if (pos == input.length())
			{
				return value;
			}
			else
			{
				std::cout << "Введено неверное значение (нечисловые символы). Повторите ввод: ";
			}
		}
		catch (std::invalid_argument& e)
		{
			std::cout << "Введено неверное значение (не число). Повторите ввод: ";
		}

	}
}

// !\brief Вывод хэш-таблицы и словаря.
// !\param dict - словарь.
void Print(Dictionary& dict)
{
	cout << "Хэш-таблица:" << endl;
	for (size_t i = 0; i < dict.GetSize(); ++i)
	{
		cout << i << ": ";
		HashTableItem* current = dict.GetBucket(i);

		if (current == nullptr)
		{
			cout << "Пусто";
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

	cout << "Словарь:" << endl;
	for (size_t i = 0; i < dict.GetSize(); ++i)
	{
		HashTableItem* current = dict.GetBucket(i);

		for (; current != nullptr; current = current->Next)
		{
			std::cout << current->Key << ": " << current->Value << std::endl;
		}
	}
}

// !\brief Главное меню.
int main()
{
	//setlocale(LC_ALL, "ru_RU.UTF-8");
	setlocale(LC_ALL, "ru");

	Dictionary* dict = new Dictionary(8);

	Print(*dict);

	int userChoice;

	do
	{
		cout << "Выберите действие." << endl;
		cout << "0. Выйти" << endl;
		cout << "1. Добавить элемент" << endl;
		cout << "2. Удалить элемент" << endl;
		cout << "3. Найти элемент" << endl;
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
			cout << "1. Добавить элемент" << endl;
			cout << "Введите ключ." << endl;
			cin >> addKey;
			cout << "Введите значение." << endl;
			cin >> addValue;
			dict->Insert(addKey, addValue);
			Print(*dict);

			break;
		}

		case 2:
		{
			string deleteKey;
			cout << "2. Удалить элемент" << endl;
			cout << "Введите ключ." << endl;
			cin >> deleteKey;
			dict->Remove(deleteKey);
			Print(*dict);

			break;
		}

		case 3:
		{
			string findKey;
			string foundValue;

			cout << "3. Найти элемент" << endl;
			cout << "Введите ключ." << endl;
			cin >> findKey;
			foundValue = dict->Find(findKey);

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
	} while (userChoice != 0);

	return 0;
}