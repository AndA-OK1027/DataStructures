#pragma once
#include "Stack.h"

// TODO: Полетела кодировка
struct QueueStacks 
{
public: 

    // \!brief Стек для добавления.
    Stack* Stack1;

    // \!brief Стек для удаления.
    Stack* Stack2;

    // \!brief Конструктор.
    // \!param size - размер массива.
    QueueStacks(int size);

    // \!brief Добавление элемента в очередь.
    // \!param Указатель на массив.
    void Enqueue(int value);

    // \!brief Удаляет элемент из очереди.
    // \!returns Указатель на массив.
    int Dequeue();

    // \!brief Возвращает массив данных.
    // \!returns Указатель на массив.
    int* GetData();

    // \!brief Вспомогательная функция для получения размера. 
    // \!returns Размер очереди.
    int GetSize();

    // \!brief Деструктор.
    ~QueueStacks();
};