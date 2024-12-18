#pragma once
#include "Stack.h"

struct QueueStacks 
{
public: 

    Stack* Stack1;
    Stack* Stack2;
    
    // !brief �����������
    QueueStacks(int size);

    // !brief ������� ���������� � �������
    void Enqueue(int value);

    // !brief ������� ���������� �� �������
    int Dequeue();

    // !brief ����������.
    ~QueueStacks();
};