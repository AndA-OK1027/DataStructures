#pragma once

//! \brief ��������� ������������� �������.
struct DynamicArray 
{
	//! \brief ������ �������
	int Size;

	//! \brief ����������� �������
	int Capacity;

	//! \brief ������.
	int* Array;

	//! \brief ������ ����������/���������� �������
	const int GrowthFactor = 2;

	//! \brief �����������
	DynamicArray();

	//! \brief ����������
	~DynamicArray();

	//! \brief ��������� ������� � ����� �������.
	//! \param value �������� ��������.
	void AddLast(int value);

	//! \brief ��������� ������� � ������ �������.
	//! \param value �������� ��������.
	void AddFirst(int value);

	//! \brief ��������� ������� � ������.
	//! \param index ������ ��������, ���� ����� �������� �������.
	//! \param value �������� ��������.
	void AddElement(int index, int value);

	//! \brief ��������� ������� � ������ ����� ������������� ��������.
	//! \param value �������� ��������
	//! \param afterValue �������, ����� �������� ����� ��� ��������
	void InsertAfter(int value, int afterValue);

	//! \brief ������ ����������� �������.
	//! \param newCapacity �����������, �� ������� ����� ��������
	void Resize(int newCapacity);

	//! \brief ������� ������� ������� �� ������������� �������.
	//! \param index ������ ��������, ������� ����� �������.
	void RemoveByIndex(int index);

	//! \brief ������� �������� �������� �� ��� ������������� ��������.
	//! \param value ���������� ��������, ������� ����� �������.
	void RemoveByValue(int value);

	//! \brief ���������� ������� �� �������.
	//! \param index ������, �� �������� ����� �������� ��������.
	//! \return ���������� ��������, ������� ��������� ��� ��������.
	int GetElement(int index);

	//! \brief ��������� ������.
	void SortArray();

	//! \brief �������� ����� ������� �������� �� ������������� ��������.
	//! \param value ��������, ������ �������� ����� �����.
	int LinearSearch(int value);

	//! \brief �������� ����� ������� �������� �� ������������� ��������.
	//! \param value ��������, ������ �������� ����� �����.
	int BinarySearch(int value);

};
