#pragma once
#include "RingBuffer.h"

// !brief ������� �� ���� ���������� ������.
struct Queue
{
public:

    // \!brief ��������� �����
    RingBuffer* Buffer;

    // \!brief 
    int GetSize();

    // \!brief �����������
    Queue(int size);

    // \!brief ���������� ������� �������.
    void Resize();

    // \!brief ������� ���������� � �������
    void Enqueue(const int& value);

    // \!brief ������� ���������� �� �������
    int Dequeue();

    // \!brief ������������ ������
    ~Queue();
};