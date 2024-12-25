#include "..\Header Files\Stack.h"
#include <iostream>

Stack::Stack(int size)
{
    Top = 0;
    Capacity = size;
    Data = new int[Capacity];
}

Stack::~Stack()
{
    delete[] Data;
}

void Stack::Resize()
{
    Capacity ++;
}

int Stack::GetSize()
{
    return Top;
}

void Stack::Push(int value)
{
    Resize();
    Data[++Top] = value;
}

int Stack::Pop()
{
    if (Top == 0) 
    {
        throw std::out_of_range("Стек пуст!");
    }
    return Data[--Top];
}
