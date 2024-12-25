#pragma once
#include "Stack.h"

struct QueueStacks 
{
public: 

    // \!brief Стек для добавления.
    Stack Stack1;

    // \!brief Стек для извлечения.
    Stack Stack2;

    // \!brief Конструктор
    // \!param Размер очереди.
    QueueStacks(int size);

    // \!brief Функция добавления в очередь
    // \!param Значение для добавления.
    void Enqueue(int value);

    // \!brief Функция извлечения из очереди
    // \!returns Указатель на очередь.
    int Dequeue();

    // \!brief Возвращает массив данных 
    // \!returns Указатель на очередь.
    int* GetData();

    // \!brief Возвращает размер очереди. 
    // \!returns Размер очереди.
    int GetSize();

    // \!brief Деструктор.
    ~QueueStacks();
};