#include <iostream>
#include "..\Header files\List.h"
#include "..\Header files\Node.h"

#include <format>

// !brief Вывод списка
void PrintList(List* list)
{
	Node* current = list->Head;
	while (current) 
	{
		std::cout << current->Data << " ";
		current = current->Next;
	}
	std::cout << std::endl;
}

int main()
{
	setlocale(LC_ALL, "ru");

	List* lst = new List();
	lst->AddLast(12345);
	lst->AddLast(54312);
	lst->AddLast(896);
	lst->AddFirst(999);

	while (true)
	{
		std::cout << "Текущий список: " << std::endl;
		PrintList(lst);
		std::cout << "Выберете действие со списком. " << std::endl;
		std::cout << "1. Добавить элемент в начало\
		    \n2. Добавить элемент в конец\
			\n3. Удалить элемент.\
			\n4. Вставить элемент после определенного\
			\n5. Вставить элемент перед определенным\
			\n6. Отсортировать.\
			\n7. Найти элемент." << std::endl;
		int menuItem;
		std::cin >> menuItem;
		switch (menuItem)
		{
		case 1:
			std::cout << "Ваш выбор - добавить элемент в начало. Выберите элемент." << std::endl;
			int value1;
			std::cin >> value1;
			lst->AddFirst(value1);
			std::cout << "Новый список: " << std::endl;
			PrintList(lst);
			std::cout << std::endl;
			break;
		case 2:
			std::cout << "Ваш выбор - добавить элемент в начало. Выберите элемент." << std::endl;
			int value2;
			std::cin >> value2;
			lst->AddLast(value2);
			std::cout << "Новый список: " << std::endl;
			PrintList(lst);
			std::cout << std::endl;
			break;
		case 3:
		{
			std::cout << "Выберите элемент для удаления: " << std::endl;
			int value3;
			std::cin >> value3;
			if (lst->LinearSearch(value3) != -1)
			{

				lst->Remove(value3);
			}
			else
			{
				std::cout << "Такого элемента нет в списке" << std::endl;
			}
			PrintList(lst);
			break;
		}
		case 4:
			std::cout << "Ваш выбор вставить элемент после другого." << std::endl;
			int value4;
			int afterValue;
			std::cout << "Выберите элемент, после которого добавить." << std::endl;
			std::cin >> afterValue;
			std::cout << "Выберите элемент, который добавить." << std::endl;
			std::cin >> value4;
			try
			{
				lst->InsertAfter(value4, afterValue);
			}
			catch (std::exception)
			{
				std::cout << "Такого элемента нет в списке" << std::endl;
			}
			PrintList(lst);
			break;
		case 5:
			std::cout << "Ваш выбор вставить элемент перед другим." << std::endl;
			int value5;
			int beforeValue;
			std::cout << "Выберите элемент, перед которым добавить." << std::endl;
			std::cin >> beforeValue;
			std::cout << "Выберите элемент, который добавить." << std::endl;
			std::cin >> value5;
			try
			{
				lst->InsertBefore(value5, beforeValue);
			}
			catch(std::exception)
			{
				std::cout << "Такого элемента нет в списке" << std::endl;
			}
			PrintList(lst);
			break;
		case 6:
			std::cout << "Ваш выбор - сортировка..." << std::endl;
			lst->Sort();
			std::cout << "Отсортированный список: " << std::endl;
			PrintList(lst);

			break;
		case 7:
			std::cout << "Выберите какой элемент найти." << std::endl;
			int value7;
			std::cin >> value7;
			if (lst->LinearSearch(value7) == -1)
			{
				std::cout << "Элемент не найден." << std::endl;
			}
			else
			{
				lst->LinearSearch(value7);
				std::cout << "Элемент найден." << lst->LinearSearch(value7) << std::endl;
			}
			break;

		default:
			std::cout << "Выберите допустимую команду..." << std::endl;
			break;
		}
	}

	return 0;
}