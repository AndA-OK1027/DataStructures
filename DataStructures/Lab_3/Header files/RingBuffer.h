#pragma once
struct RingBuffer
{
public:
	
    // !brief
    int* Buffer;

    // !brief
    int Head;

    // !brief
    int Tail;
    
    // !brief
    int Size;

    // !brief
    int Capacity;

    // !brief �����������.
    RingBuffer(int Size);

    // !brief
    int GetElement();

    // !brief
    void Resize(int newSize);

    // !brief ���������� ��������� �����.
    int FreeSpace();

    // !brief ���������� ������� �����.
    int OccupiedSpace();

    // !brief ���������� �������� � �����.
    void Add(int value);

    // !brief ���������� �������� �� ������.
    int Remove();

    // !brief ����������.
    ~RingBuffer();
};