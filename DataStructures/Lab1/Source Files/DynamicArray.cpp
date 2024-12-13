#include <iostream>
#include <stdexcept>
#include "..\Header Files\DynamicArray.h"

//! \brief  Конструктор
DynamicArray :: DynamicArray() : Size(0), Capacity(1), GrowthFactor(2)
{
	Array = new int[Capacity];
}

//! \brief Деструктор
DynamicArray :: ~DynamicArray()
{
	delete[] Array;
}

//! \brief Добавляет элемент в конец массива.
//! \param value Значение элемента.
void DynamicArray :: AddLast(int value)
{
	if (Size == Capacity) 
	{
		Resize(Capacity * GrowthFactor);
	}
	Array[Size] = value;
	Size++;
}

//! \brief Добавляет элемент в начало массива.
//! \param value Значение элемента.
void DynamicArray:: AddFirst(int value)
{
	AddElement(0, value);
}

//! \brief Добавляет элемент в массив.
//! \param index Индекс элемента, куда нужно добавить элемент.
//! \param value Значение элемента.
void DynamicArray:: AddElement(int index, int value)
{
	if (index > Size) 
	{
		throw std::out_of_range("Index out of range");
	}
	if (Size >= Capacity) 
	{
		Resize(Capacity * GrowthFactor);
	}
	// Сдвигаем элементы вправо
	for (int i = Size; i > index; --i) 
	{
		Array[i] = Array[i - 1];
	}
	Array[index] = value;
	Size++;
}

//! \brief Меняет вместимость массива.
//! \param newCapacity Вместимость, до которой нужно изменить
void DynamicArray:: Resize(int newCapacity)
{
	if (newCapacity > Capacity) {
		int* newArray = new int[newCapacity];
		for (int i = 0; i < Size; ++i) {
			newArray[i] = Array[i];
		}
		delete[] Array;
		Array = newArray;
		Capacity = newCapacity;
	}
}

//! \brief Добавляет элемент в массив после определенного элемента.
//! \param value Значение элемента
//! \param afterValue Элемент, после которого нужно его добавить
void DynamicArray:: InsertAfter(int value, int afterValue) 
{
	for (int i = 0; i < Size; i++) {
		if (Array[i] == afterValue) 
		{
			AddElement(i + 1, value);
			return;
		}
	}
}

//! \brief Удаляет элемент массива по индексу.
void DynamicArray:: RemoveByIndex(int index)
{
	if (index >= Size) {
		throw std::out_of_range("Index is out of range");
	}
	for (int i = index; i < Size - 1; ++i) {
		Array[i] = Array[i + 1]; // Сдвигаем элементы влево
	}
	Size--;

	// Уменьшаем массив, если необходимо
	if (Capacity / Size > GrowthFactor && Capacity > 4) 
	{
		Resize(Capacity / GrowthFactor);
	}
}

//! \brief Удаляет значение элемента по его передаваемому значению.
//! \param value Посылаемое значение, которое нужно удалить.
void DynamicArray :: RemoveByValue(int element)
{
	for (int i = 0; i < Size; i++)
	{
		if (Array[i] == element)
		{
			RemoveByIndex(i);
			return;
		}
	}
	throw std::out_of_range("Element not found!");
}

//! \brief Возвращает элемент по индексу.
//! \param index Индекс, по которому нужно получить значение.
//! \return Возвращает значение, которое находится под индексом.
int  DynamicArray:: GetElement(int index)
{
	return Array[index];
}

//! \brief Сортирует массив методом вставки
void DynamicArray:: SortArray()
{
	for (int i = 1; i < Size; i++)
	{
		for (int j = i; j > 0 && Array[j-1] > Array[j]; j--)
		{
			int temp = Array[j - 1];
			Array[j - 1] = Array[j];
			Array[j] = temp;
		}
	}
}

//! \brief Линейный поиск индекса элемента по передаваемому значению.
//! \param value Значение, индекс которого нужно найти.
//! \return Индекс найденного элементa
int DynamicArray :: LinearSearch(int value)
{
	for (int i = 0; i < Size; i++) {
		if (Array[i] == value) {
			return i; // Возвращаем индекс найденного элемента
		}
	}
	return -1; // Элемент не найден
}

//! \brief Бинарный поиск индекса элемента по передаваемому значению.
//! \param value Значение, индекс которого нужно найти.
//! \return Индекс элемента.
int DynamicArray :: BinarySearch(int value)
{
	int left = 0;
	int right = Size;
	while (left < right) 
	{
		int mid = (left + right) / 2;
		if (Array[mid] == value)
		{
			return mid;
		}
		if (Array[mid] > value)
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	return -1;
}
