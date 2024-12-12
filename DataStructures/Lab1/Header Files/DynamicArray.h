#pragma once

//! \brief Структура динамического массива.
struct DynamicArray 
{
	//! \brief Размер массива
	int Size;

	//! \brief Вместимость массива
	int Capacity;

	//! \brief Массив.
	int* Array;

	//! \brief Фактор увеличения/уменьшения массива
	const int GrowthFactor = 2;

	//! \brief Конструктор
	DynamicArray();

	//! \brief Деструктор
	~DynamicArray();

	//! \brief Добавляет элемент в конец массива.
	//! \param value Значение элемента.
	void AddLast(int value);

	//! \brief Добавляет элемент в начало массива.
	//! \param value Значение элемента.
	void AddFirst(int value);

	//! \brief Добавляет элемент в массив.
	//! \param index Индекс элемента, куда нужно добавить элемент.
	//! \param value Значение элемента.
	void AddElement(int index, int value);

	//! \brief Добавляет элемент в массив после определенного элемента.
	//! \param value Значение элемента
	//! \param afterValue Элемент, после которого нужно его добавить
	void InsertAfter(int value, int afterValue);

	//! \brief Меняет вместимость массива.
	//! \param newCapacity Вместимость, до которой нужно изменить
	void Resize(int newCapacity);

	//! \brief Удаляет элемент массива по передаваемому индексу.
	//! \param index Индекс элемента, который нужно удалить.
	void RemoveByIndex(int index);

	//! \brief Удаляет значение элемента по его передаваемому значению.
	//! \param value Посылаемое значение, которое нужно удалить.
	void RemoveByValue(int value);

	//! \brief Возвращает элемент по индексу.
	//! \param index Индекс, по которому нужно получить значение.
	//! \return Возвращает значение, которое находится под индексом.
	int GetElement(int index);

	//! \brief Сортирует массив.
	void SortArray();

	//! \brief Линейный поиск индекса элемента по передаваемому значению.
	//! \param value Значение, индекс которого нужно найти.
	int LinearSearch(int value);

	//! \brief Бинарный поиск индекса элемента по передаваемому значению.
	//! \param value Значение, индекс которого нужно найти.
	int BinarySearch(int value);

};
