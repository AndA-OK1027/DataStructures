#pragma once

// \!brief Определение структуры кольцевой буфер.
struct RingBuffer
{
public:
	
    // \!brief Внутренний массив кольцевого буфера.
    int* Buffer;

    // \!brief Первый элемент.
    int Head;

    // \!brief Последний эелемент
    int Tail;
    
    // \!brief Размер данного буфера.
    int Size;

    // \!brief Вместимость буфера.
    int Capacity;

    // \!brief Конструктор.
    // \!param size - размер 
    RingBuffer(int size);

    // \!brief Получение последнего элемента.
    // \!returns Последний добавленный элемент.
    int GetElement();

    // \!brief Возвращает свободное место.
    // \!returns Оставшееся свободное место в буфере
    int FreeSpace();

    // \!brief Возвращает занятое место.
    // \!returns Занятое место в буфере
    int OccupiedSpace();

    // \!brief Добавление элемента в буфер.
    // \!param value - значение для добавления. 
    void Add(int value);

    // \!brief Извлечение элемента из буфера.
    // \!returns true - если элемент удаляется, false - если нет
    bool Remove();

    // \!brief Деструктор.
    ~RingBuffer();
};