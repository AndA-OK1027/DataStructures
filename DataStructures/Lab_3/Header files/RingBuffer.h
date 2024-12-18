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
    RingBuffer(int Size);

    // \!brief Получение последнего элемента.
    int GetElement();

    // \!brief Возвращает свободное место.
    int FreeSpace();

    // \!brief Возвращает занятое место.
    int OccupiedSpace();

    // \!brief Добавление элемента в буфер.
    void Add(int value);

    // \!brief Извлечение элемента из буфера.
    bool Remove();

    // \!brief Деструктор.
    ~RingBuffer();
};