#include "..\Header Files\RingBuffer.h"
#include <iostream>

// TODO: Полетела кодировка
RingBuffer::RingBuffer(int size)
{
    Capacity = size;
    Size = 0;
    Buffer = new int[size];
    Head = 0;
    Tail = 0;
}

int RingBuffer::FreeSpace()
{
    return Capacity - Size;
}

int RingBuffer::OccupiedSpace()
{
    return Size;
}

void RingBuffer::Add(int value)
{
    Buffer[Tail] = value;
    Tail = (Tail + 1) % Capacity;
    if (Size == Capacity)
    {
        Head = (Head + 1) % Capacity;
    }
    else
    {
        Size++;
    }
}

bool RingBuffer::Remove()
{
    if (Size == 0)
    {
        throw std::out_of_range("��������� ����� ����, ���������� ������� �������.");
    }
    int data = Buffer[Tail];
    Tail = (Tail + 1) % Capacity;
    Size--;
    return true;
}

int RingBuffer::GetElement()
{
    return Buffer[Tail];
}

RingBuffer::~RingBuffer()
{
    delete[] Buffer;
}

