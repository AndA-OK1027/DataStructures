#pragma once
#include "RingBuffer.h"

// !brief Очередь на базе кольцевого буфера.
struct Queue
{
public:

    // \!brief Кольцевой буфер
    RingBuffer* Buffer;

    // \!brief 
    int GetSize();

    // \!brief Конструктор
    Queue(int size);

    // \!brief Увеличение размера очереди.
    void Resize();

    // \!brief Функция добавления в очередь
    void Enqueue(const int& value);

    // \!brief Функция извлечения из очереди
    int Dequeue();

    // \!brief Освобождение памяти
    ~Queue();
};