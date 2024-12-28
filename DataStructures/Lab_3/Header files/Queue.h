#pragma once
#include "RingBuffer.h"

// TODO: Полетела кодировка
// !brief Структура с определением очереди на основе кольцевого буфера.
struct Queue
{
public:

    // \!brief Внутренний кольцевой буфер.
    RingBuffer* Buffer;

    // \!brief Вспомогательная функция для получения размера.
    // \!returns Размер очереди.
    int GetSize();

    // \!brief Конструктор
    // \!param size - размер.
    Queue(int size);

    // \!brief Расширение очереди.
    void Resize();

    // \!brief Добавление элемента в очередь.
    // \!param value - значение.
    void Enqueue(int& value);

    // \!brief Удаление элемента из очереди.
    // \!returns Указатель на массив.
    int Dequeue();

    // \!brief Деструктор.
    ~Queue();
};