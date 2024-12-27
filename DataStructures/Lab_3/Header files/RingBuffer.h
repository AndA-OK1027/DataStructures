#pragma once

// TODO: Полетела кодировка
// \!brief ����������� ��������� ��������� �����.
struct RingBuffer
{
public:
	
    // \!brief ���������� ������ ���������� ������.
    int* Buffer;

    // \!brief ������ �������.
    int Head;

    // \!brief ��������� ��������
    int Tail;
    
    // \!brief ������ ������� ������.
    int Size;

    // \!brief ����������� ������.
    int Capacity;

    // \!brief �����������.
    // \!param size - ������ 
    RingBuffer(int size);

    // \!brief ��������� ���������� ��������.
    // \!returns ��������� ����������� �������.
    int GetElement();

    // \!brief ���������� ��������� �����.
    // \!returns ���������� ��������� ����� � ������
    int FreeSpace();

    // \!brief ���������� ������� �����.
    // \!returns ������� ����� � ������
    int OccupiedSpace();

    // \!brief ���������� �������� � �����.
    // \!param value - �������� ��� ����������. 
    void Add(int value);

    // \!brief ���������� �������� �� ������.
    // \!returns true - ���� ������� ���������, false - ���� ���
    bool Remove();

    // \!brief ����������.
    ~RingBuffer();
};