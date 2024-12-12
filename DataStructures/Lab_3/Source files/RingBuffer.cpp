#include "C:\Users\User\source\repos\DataStructures\Lab_3\Header Files\RingBuffer.h"
#include <iostream>

RingBuffer::RingBuffer(int Size)
{
    Capacity = Size;
    Buffer = new int[Capacity];
    Head = 0;
    Tail = 0;
    this->Size = 0;
}

int RingBuffer::FreeSpace()
{
    // Один элемент всегда свободен для различения пустого и полного состояния
    return Capacity - Size - 1;
}

int RingBuffer::OccupiedSpace()
{
    return Size;
}

void RingBuffer::Resize(int newSize)
{
    int* newBuffer = new int[newSize];
    int elementsToCopy = (newSize < Size) ? newSize : Size;

    for (int i = 0; i < elementsToCopy; i++)
    {
        newBuffer[i] = Buffer[(Tail + i) % Capacity];
    }

    delete[] Buffer;
    Buffer = newBuffer;
    Head = elementsToCopy;
    Tail = 0;
    Capacity = newSize;
    Size = elementsToCopy;
}

void RingBuffer::Add(int value)
{
    if (Size == Capacity)
    {
        Resize(Size + 1);
    }
    Buffer[Tail] = value;
    Tail = (Tail + 1) % Capacity;
    Size++;
}


int RingBuffer::Remove()
{
    if (Size == 0)
    {
        throw std::out_of_range("Кольцевой буфер пуст!");
    }
    int value = Buffer[Head];
    Head = (Head + 1) % Capacity;
    Size--;
    return value;
}

int RingBuffer::GetElement()
{
    return Buffer[Tail];
}

RingBuffer::~RingBuffer()
{
    delete[] Buffer;
}

