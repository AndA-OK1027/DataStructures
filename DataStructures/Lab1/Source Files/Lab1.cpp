#include <iostream>
#include "C:\Users\User\source\repos\DataStructures\Lab1\Header Files\DynamicArray.h"
using namespace std;

int main()
{
	DynamicArray* sample = new DynamicArray();
	sample->AddLast(25);
	sample->AddLast(16);
	sample->AddLast(7);
	sample->AddLast(28);
	sample->AddLast(1);

	std::cout << "Current array: \n";
	for (int i = 0; i < sample->Size; i++)
	{
		std::cout <<  sample->GetElement(i) << std::endl;
	}

	//******Μενώ******
	while (true) 
	{
		std::cout << "Choose what to do with array: ";
		std::cout << "\n1. Remove an element by index from an array\
		    \n2. Remove an element by value from an array\
			\n3. Insert an element at the beginning\
			\n4. Insert an element at the end\
			\n5. Insert after a certain element\
			\n6. Sort array\
			\n7. Linear search for an element in an array\
			\n8. Binary search for an element in an array\n";
		int menuItem;
		std::cin >> menuItem;
		std::cout << "Your input: " << std::endl;
		std::cout << menuItem << std::endl;
		switch (menuItem)
		{
		case 1:
			//Remove item(index)                  %
			std::cout << "Choose index of element to remove" << std::endl;
			int index;
			std::cin >> index;
			try
			{
				sample->RemoveByIndex(index);
			}
			catch(out_of_range)
			{
				std::cout << "No found index" << std::endl;
			}
			for (int i = 0; i < sample->Size; i++)
			{
				std::cout << '\n' + sample->GetElement(i) << std::endl;
			}

			break;


		case 2:
			//Remove item(value)
			std::cout << "Choose item to remove" << std::endl;
			int item2;
			std::cin >> item2;
			try 
			{
				sample->RemoveByValue(item2);
			}
			catch(out_of_range)
			{
				std::cout << "No found item" << std::endl;
			}
			for (int i = 0; i < sample->Size; i++)
			{
				std::cout << '\n' + sample->GetElement(i) << std::endl;
			}

			break;

		case 3:
			//Insert at the beggining
			std::cout << "Choose item to insert" << std::endl;
			int item3;
			std::cin >> item3;
			sample->AddFirst(item3);
			for (int i = 0; i < sample->Size; i++)
			{
				std::cout << sample->GetElement(i) << std::endl;
			}
			break;


		case 4:
			//Insert at the end        
			std::cout << "Choose item to insert" << std::endl;
			int item4;
			std::cin >> item4;
			sample->AddLast(item4);
			for (int i = 0; i < sample->Size; i++)
			{
				std::cout << sample->GetElement(i) << std::endl;
			}
			break;

		case 5:
			//Insert after a certain element
			std::cout << "Choose an item to insert and after what item" << std::endl;
			int item5;
			int afterItem;
			std::cin >> item5;
			std::cin >> afterItem;
			sample->InsertAfter(item5, afterItem);
			for (int i = 0; i < sample->Size; i++)
			{
				std::cout << sample->GetElement(i) << std::endl;
			}

			break;

		case 6:
			//Sorting                           %
			std::cout << "Soting array... " << std::endl;
			sample->SortArray();
			for (int i = 0; i < sample->Size; i++)
			{
				std::cout << sample->GetElement(i) << std::endl;
			}
			break;
		case 7:
			//Linear search           %
			std::cout << "What item to look for" << std::endl;
			int item7;
			std::cin >> item7;
			std::cout << "Index: " << sample->LinearSearch(item7);

			break;

		case 8:
			//Binary search                          %
			std::cout << "What item to look for" << std::endl;
			int item8;
			std::cin >> item8;
			sample->SortArray();
			std::cout << "Sorted Array: " << std::endl;
			for (int i = 0; i < sample->Size; i++)
			{
				std::cout << sample->GetElement(i) << std::endl;
			}

			std::cout << "Index: " << sample->BinarySearch(item8);
			break;

		default:
			std::cout << "\nChoose a valid command. ";
			break;
		}

	}

	delete sample;
	return 0;
}