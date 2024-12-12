#include <iostream>
#include "..\Header files\List.h"
#include "..\Header files\Node.h"

#include <format>

// !brief ����� ������
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
		std::cout << "������� ������: " << std::endl;
		PrintList(lst);
		std::cout << "�������� �������� �� �������. " << std::endl;
		std::cout << "1. �������� ������� � ������\
		    \n2. �������� ������� � �����\
			\n3. ������� �������.\
			\n4. �������� ������� ����� �������������\
			\n5. �������� ������� ����� ������������\
			\n6. �������������.\
			\n7. ����� �������." << std::endl;
		int menuItem;
		std::cin >> menuItem;
		switch (menuItem)
		{
		case 1:
			std::cout << "��� ����� - �������� ������� � ������. �������� �������." << std::endl;
			int value1;
			std::cin >> value1;
			lst->AddFirst(value1);
			std::cout << "����� ������: " << std::endl;
			PrintList(lst);
			std::cout << std::endl;
			break;
		case 2:
			std::cout << "��� ����� - �������� ������� � ������. �������� �������." << std::endl;
			int value2;
			std::cin >> value2;
			lst->AddLast(value2);
			std::cout << "����� ������: " << std::endl;
			PrintList(lst);
			std::cout << std::endl;
			break;
		case 3:
		{
			std::cout << "�������� ������� ��� ��������: " << std::endl;
			int value3;
			std::cin >> value3;
			if (lst->LinearSearch(value3) != -1)
			{

				lst->Remove(value3);
			}
			else
			{
				std::cout << "������ �������� ��� � ������" << std::endl;
			}
			PrintList(lst);
			break;
		}
		case 4:
			std::cout << "��� ����� �������� ������� ����� �������." << std::endl;
			int value4;
			int afterValue;
			std::cout << "�������� �������, ����� �������� ��������." << std::endl;
			std::cin >> afterValue;
			std::cout << "�������� �������, ������� ��������." << std::endl;
			std::cin >> value4;
			try
			{
				lst->InsertAfter(value4, afterValue);
			}
			catch (std::exception)
			{
				std::cout << "������ �������� ��� � ������" << std::endl;
			}
			PrintList(lst);
			break;
		case 5:
			std::cout << "��� ����� �������� ������� ����� ������." << std::endl;
			int value5;
			int beforeValue;
			std::cout << "�������� �������, ����� ������� ��������." << std::endl;
			std::cin >> beforeValue;
			std::cout << "�������� �������, ������� ��������." << std::endl;
			std::cin >> value5;
			try
			{
				lst->InsertBefore(value5, beforeValue);
			}
			catch(std::exception)
			{
				std::cout << "������ �������� ��� � ������" << std::endl;
			}
			PrintList(lst);
			break;
		case 6:
			std::cout << "��� ����� - ����������..." << std::endl;
			lst->Sort();
			std::cout << "��������������� ������: " << std::endl;
			PrintList(lst);

			break;
		case 7:
			std::cout << "�������� ����� ������� �����." << std::endl;
			int value7;
			std::cin >> value7;
			if (lst->LinearSearch(value7) == -1)
			{
				std::cout << "������� �� ������." << std::endl;
			}
			else
			{
				lst->LinearSearch(value7);
				std::cout << "������� ������." << lst->LinearSearch(value7) << std::endl;
			}
			break;

		default:
			std::cout << "�������� ���������� �������..." << std::endl;
			break;
		}
	}

	return 0;
}