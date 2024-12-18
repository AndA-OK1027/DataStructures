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
    if (Stack2->Top == -1)
    { // Если второй стек пуст
        while (Stack1->Top != -1)
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
