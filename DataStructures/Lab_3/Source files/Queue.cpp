#include "..\Header Files\Queue.h"
#include <iostream>

Queue::Queue(int size) 
{
    Buffer = new RingBuffer(size);
}

int Queue::GetSize()
{
    return Buffer->Size;
}

void Queue::Resize()
{
    // TODO: Недостаточно увеличивать значение Capacity для расширения размера массива.
    // Нужно также пересоздавать сам массив, перенести в новый расширенный массив старые данные
    // и в конце удалить старый массив (как и в лабораторной работе 1 про массивы)
    Buffer->Capacity *= 2;
}

void Queue::Enqueue(int& value) 
{
    if (Buffer->FreeSpace() == 1)
    {
        Resize();
    }
    Buffer->Add(value);
}

int Queue::Dequeue() 
{
    return Buffer->Remove();
}

Queue::~Queue() 
{
    delete Buffer;
}