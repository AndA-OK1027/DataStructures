#pragma once

// \!brief Структура, описывающая кольцевой буфер.
struct RingBuffer
{
public:
	
    // \!brief Внутренний массив.
    int* Buffer;

    // \!brief Вершина.
    int Head;

    // \!brief Конец.
    int Tail;
    
    // \!brief Размер.
    int Size;

    // \!brief Вместимость.
    int Capacity;

    // \!brief Конструктор
    // \!param size - размер 
    RingBuffer(int size);

    // \!brief Получение элемента.
    // \!returns Последний добавленный элемент.
    int GetElement();

    // \!brief Получение свободного места.
    // \!returns Свободное место в буфере.
    int FreeSpace();

    // \!brief Получение занятого места.
    // \!returns Занятое место в буфере.
    int OccupiedSpace();

    // \!brief Добавление элемента в буфер.
    // \!param value - Значение для добавления. 
    void Add(int value);

    // \!brief Удаление элемента из буфера.
    // \!returns true - если удалось удалить, false - если нет.
    bool Remove();

    // \!brief Деструктор.
    ~RingBuffer();
};