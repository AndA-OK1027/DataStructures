#pragma once
#include "RingBuffer.h"

// TODO: Полетела кодировка
// !brief ������� �� ���� ���������� ������.
struct Queue
{
public:

    // \!brief ��������� �����
    RingBuffer* Buffer;

    // \!brief 
    // \!returns ������ �������.
    int GetSize();

    // \!brief �����������
    // \!param ������ �������.
    Queue(int size);

    // \!brief ���������� ������� �������.
    void Resize();

    // \!brief ������� ���������� � �������
    // \!param �������� ��� ����������.
    void Enqueue(int& value);

    // \!brief ������� ���������� �� �������
    // \!returns ��������� �� �������.
    int Dequeue();

    // \!brief ������������ ������
    ~Queue();
};