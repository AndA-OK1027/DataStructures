#pragma once
#include "Stack.h"

struct QueueStacks 
{
public: 

    Stack* Stack1;
    Stack* Stack2;
    
    // !brief Конструктор
    QueueStacks(int size);

    // !brief Функция добавления в очередь
    void Enqueue(int value);

    // !brief Функция извлечения из очереди
    int Dequeue();

    // !brief Деструктор.
    ~QueueStacks();
};