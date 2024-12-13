#include <iostream>
#include <stdexcept>
#include "..\Header Files\DynamicArray.h"

//! \brief  �����������
DynamicArray :: DynamicArray() : Size(0), Capacity(1), GrowthFactor(2)
{
	Array = new int[Capacity];
}

//! \brief ����������
DynamicArray :: ~DynamicArray()
{
	delete[] Array;
}

//! \brief ��������� ������� � ����� �������.
//! \param value �������� ��������.
void DynamicArray :: AddLast(int value)
{
	if (Size == Capacity) 
	{
		Resize(Capacity * GrowthFactor);
	}
	Array[Size] = value;
	Size++;
}

//! \brief ��������� ������� � ������ �������.
//! \param value �������� ��������.
void DynamicArray:: AddFirst(int value)
{
	AddElement(0, value);
}

//! \brief ��������� ������� � ������.
//! \param index ������ ��������, ���� ����� �������� �������.
//! \param value �������� ��������.
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
	// �������� �������� ������
	for (int i = Size; i > index; --i) 
	{
		Array[i] = Array[i - 1];
	}
	Array[index] = value;
	Size++;
}

//! \brief ������ ����������� �������.
//! \param newCapacity �����������, �� ������� ����� ��������
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

//! \brief ��������� ������� � ������ ����� ������������� ��������.
//! \param value �������� ��������
//! \param afterValue �������, ����� �������� ����� ��� ��������
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

//! \brief ������� ������� ������� �� �������.
void DynamicArray:: RemoveByIndex(int index)
{
	if (index >= Size) {
		throw std::out_of_range("Index is out of range");
	}
	for (int i = index; i < Size - 1; ++i) {
		Array[i] = Array[i + 1]; // �������� �������� �����
	}
	Size--;

	// ��������� ������, ���� ����������
	if (Capacity / Size > GrowthFactor && Capacity > 4) 
	{
		Resize(Capacity / GrowthFactor);
	}
}

//! \brief ������� �������� �������� �� ��� ������������� ��������.
//! \param value ���������� ��������, ������� ����� �������.
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

//! \brief ���������� ������� �� �������.
//! \param index ������, �� �������� ����� �������� ��������.
//! \return ���������� ��������, ������� ��������� ��� ��������.
int  DynamicArray:: GetElement(int index)
{
	return Array[index];
}

//! \brief ��������� ������ ������� �������
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

//! \brief �������� ����� ������� �������� �� ������������� ��������.
//! \param value ��������, ������ �������� ����� �����.
//! \return ������ ���������� �������a
int DynamicArray :: LinearSearch(int value)
{
	for (int i = 0; i < Size; i++) {
		if (Array[i] == value) {
			return i; // ���������� ������ ���������� ��������
		}
	}
	return -1; // ������� �� ������
}

//! \brief �������� ����� ������� �������� �� ������������� ��������.
//! \param value ��������, ������ �������� ����� �����.
//! \return ������ ��������.
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
