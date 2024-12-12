#include "C:\Users\User\source\repos\DataStructures\Lab_3\Header Files\Queue.h"
#include <iostream>

Queue::Queue(int size) 
{
    Buffer = new RingBuffer(size);
}

int Queue::GetSize()
{
    return Buffer->Size;
}

void Queue::Enqueue(int value) 
{
    /*if (GetSize() == Buffer->Capacity)
    {
        throw std::out_of_range("Очередь переполнена.");
    }*/
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