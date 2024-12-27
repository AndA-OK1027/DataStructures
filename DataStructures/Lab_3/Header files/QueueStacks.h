#pragma once
#include "Stack.h"

// TODO: Полетела кодировка
struct QueueStacks 
{
public: 

    // \!brief ���� ��� ����������.
    Stack Stack1;

    // \!brief ���� ��� ����������.
    Stack Stack2;

    // \!brief �����������
    // \!param ������ �������.
    QueueStacks(int size);

    // \!brief ������� ���������� � �������
    // \!param �������� ��� ����������.
    void Enqueue(int value);

    // \!brief ������� ���������� �� �������
    // \!returns ��������� �� �������.
    int Dequeue();

    // \!brief ���������� ������ ������ 
    // \!returns ��������� �� �������.
    int* GetData();

    // \!brief ���������� ������ �������. 
    // \!returns ������ �������.
    int GetSize();

    // \!brief ����������.
    ~QueueStacks();
};