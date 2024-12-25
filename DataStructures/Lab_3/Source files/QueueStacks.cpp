#include "..\Header Files\QueueStacks.h"
#include <iostream>

Stack* Stack1;
Stack* Stack2;

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
    if (Stack1->GetSize() == 0)
    {
        throw new std::out_of_range("Очередь пуста. ");
    }

    if (Stack2->GetSize() == 0)
    {
        while (Stack1->GetSize() != 0)
        {
            Stack2->Push(Stack1->Pop());
        }
    }

    return Stack2->Pop();
}

QueueStacks::~QueueStacks()
{
    delete Stack1;
    delete Stack2;
}
