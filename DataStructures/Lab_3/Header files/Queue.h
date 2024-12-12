#pragma once
#include "RingBuffer.h"

// !brief ������� �� ���� ���������� ������.
struct Queue
{
public:

    // !brief ��������� �����
    RingBuffer* Buffer;

    int GetSize();

    // !brief �����������
    Queue(int size);

    // !brief ������� ���������� � �������
    void Enqueue(int value);

    //! brief ������� ���������� �� �������
    int Dequeue();

    // !brief ������������ ������
    ~Queue();
};