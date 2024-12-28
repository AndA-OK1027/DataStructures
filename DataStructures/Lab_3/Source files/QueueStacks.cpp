#include "..\Header Files\QueueStacks.h"
#include <iostream>

QueueStacks::QueueStacks(int size)
{
    Stack1 = new Stack(size);
    Stack2 = new Stack(size);
}

void QueueStacks::Enqueue(int value)
{
    Stack1->Push(value);
}

int QueueStacks::Dequeue()
{
    if (Stack2->Top == -1)
    {
        throw std::out_of_range("Невозможно удалить, очередь пуста.");
    }

    if (Stack2->Top == -1)
    {
        while (Stack1->Top != -1)
        {
            Stack2->Push(Stack1->Pop());
        }
    }

    return Stack2->Pop();
}

int QueueStacks::GetSize()
{
    return Stack1->GetSize() + Stack2->GetSize();
}

int* QueueStacks::GetData()
{
    int size1 = Stack1->GetSize();
    int size2 = Stack2->GetSize();
    int current = size1 + size2;

    int* data = new int[current];
    int* data1 = Stack1->Data;
    int* data2 = Stack2->Data;

    for (int i = 0; i < size2; ++i)
    {
        data[i] = data2[i];
    }
    for (int i = 0; i < size1; ++i)
    {
        data[size2 + i] = data1[i];
    }

    return data;
}

QueueStacks::~QueueStacks()
{
    delete Stack1;
    delete Stack2;
}
