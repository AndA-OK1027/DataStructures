#pragma once

// TODO: Полетела кодировка
struct Stack
{
public:
	// \!brief ������ ������
	int* Data;

	// \!brief ������ ������� �����.
	int Top;
	
	// \!brief ������� �����.
	int Size;

	// \!brief ���������� ������.
	// \!returns ������ �����.
	int GetSize();

	// \!brief ����������.
	void Resize();

	// \!brief ���������� � �����
	// \!param value - �������� ��� ����������.
	void Push(int value);

	// \!brief �������� ����������
	// \!returns ��������� �� ����.
	int Pop();

	// \!brief ����������� �� ���������.
	Stack();

	// \!brief �����������
	// \!param size - ������.
	Stack(int size);

	// \!brief ����������.
	~Stack();
};