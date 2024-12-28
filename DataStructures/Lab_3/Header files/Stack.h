#pragma once

// \!brief Структура данных стек.
struct Stack
{
public:
	// \!brief Массив данных.
	int* Data;

	// \!brief Индекс вершины стека.
	int Top;
	
	// \!brief Размер стека.
	int Size;

	// \!brief Вмпомогательная функция для получения размера стека.
	// \!returns Размер стека.
	int GetSize();

	// \!brief Увеличение размера.
	void Resize();

	// \!brief Добавление в стек.
	// \!param value - значение для добавления.
	void Push(int value);

	// \!brief Удаление элемента
	// \!returns Удаленный элемент.
	int Pop();

	// \!brief Конструктор по умолчанию.
	Stack();

	// \!brief Конструктор.
	// \!param size - Размер.
	Stack(int size);

	// \!brief Деструктор.
	~Stack();
};