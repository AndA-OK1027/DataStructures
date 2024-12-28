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
    // TODO: Недостаточно увеличивать значение Capacity для расширения размера массива. +
    // Нужно также пересоздавать сам массив, перенести в новый расширенный массив старые данные
    // и в конце удалить старый массив (как и в лабораторной работе 1 про массивы) 
    RingBuffer* newBuffer = new RingBuffer((Buffer->Capacity) * 2);

    for (int i = 0; i < Buffer->Size; ++i)
    {
        newBuffer->Add(Buffer->Buffer[i]);
    }

    delete Buffer;
    Buffer = newBuffer;
}

void Queue::Enqueue(int& value) 
{
    if (Buffer->FreeSpace() == 0)
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