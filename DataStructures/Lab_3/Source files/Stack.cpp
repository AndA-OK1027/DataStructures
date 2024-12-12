#include "C:\Users\User\source\repos\DataStructures\Lab_3\Header Files\Stack.h"
#include <iostream>

int* Data;

int Top; 

int Capacity;

Stack::Stack(int size)
{
    Top = -1;
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
    return Top + 1;
}

void Stack::Push(int value)
{
    if (Top == Capacity - 1) 
    {
        Resize();
    }
    Data[++Top] = value;
}

int Stack::Pop()
{
    if (Top == -1) 
    {
        throw std::out_of_range("Стек пуст!");
    }
    return Data[Top--];
}
