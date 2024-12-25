#pragma once
struct Stack
{
public:
	// \!brief Массив данных
	int* Data;

	// \!brief Индекс вершины стека.
	int Top;
	
	// \!brief Емкость стека.
	int Size;

	// \!brief Возвращает размер.
	// \!returns Размер стека.
	int GetSize();

	// \!brief Расширение.
	void Resize();

	// \!brief Добавление в конец
	// \!param value - значение для добавления.
	void Push(int value);

	// \!brief Удаление последнего
	// \!returns Указатель на стек.
	int Pop();

	// \!brief Конструктор по умолчанию.
	Stack();

	// \!brief Конструктор
	// \!param size - Размер.
	Stack(int size);

	// \!brief Деструктор.
	~Stack();
};