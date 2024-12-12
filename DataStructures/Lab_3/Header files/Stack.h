#pragma once
struct Stack
{
public:

	// ������ ������
	int* Data;

	// !brief �����
	int Top;

	int Capacity;

	int GetSize();

	void Resize();

	// !brief ���������� � �����
	void Push(int value);

	// !brief �������� ����������
	int Pop();

	// !brief �����������
	Stack(int size);

	// !brief ����������
	~Stack();
};