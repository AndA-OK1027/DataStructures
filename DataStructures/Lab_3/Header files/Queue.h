#pragma once
#include "RingBuffer.h"

// !brief Очередь на базе кольцевого буфера.
struct Queue
{
public:

    // \!brief Кольцевой буфер
    RingBuffer* Buffer;

    // \!brief 
    // \!returns Размер очереди.
    int GetSize();

    // \!brief Конструктор
    // \!param Размер очереди.
    Queue(int size);

    // \!brief Увеличение размера очереди.
    void Resize();

    // \!brief Функция добавления в очередь
    // \!param Значение для добавления.
    void Enqueue(int& value);

    // \!brief Функция извлечения из очереди
    // \!returns Указатель на очередь.
    int Dequeue();

    // \!brief Освобождение памяти
    ~Queue();
};