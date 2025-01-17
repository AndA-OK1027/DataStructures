﻿#include "..\Header Files\Stack.h"
#include <iostream>

Stack::Stack(int size) : Size(size), Top(-1)
{
    Data = new int[size];
}

Stack::Stack() : Data(nullptr), Size(0), Top(-1) {}

Stack::~Stack()
{
    while (Top != -1)
    {
        Pop();
    }

    delete[] Data;
}

void Stack::Resize()
{
    Size++;
}

int Stack::GetSize()
{
    return Top + 1;
}

void Stack::Push(int value)
{
    Data[++Top] = value;
    Resize();
}

int Stack::Pop()
{
    if (Top == -1) 
    {
        throw std::out_of_range("Стек пуст!");
    }

    Size--;

    return Data[Top--];
}