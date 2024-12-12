#pragma once
struct Stack
{
public:

	// Массив данных
	int* Data;

	// !brief Конец
	int Top;

	int Capacity;

	int GetSize();

	void Resize();

	// !brief Добавление в конец
	void Push(int value);

	// !brief Удаление последнего
	int Pop();

	// !brief Конструктор
	Stack(int size);

	// !brief Деструктор
	~Stack();
};