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

    // !brief Конструктор.
    RingBuffer(int Size);

    // !brief
    int GetElement();

    // !brief
    void Resize(int newSize);

    // !brief Возвращает свободное место.
    int FreeSpace();

    // !brief Возвращает занятое место.
    int OccupiedSpace();

    // !brief Добавление элемента в буфер.
    void Add(int value);

    // !brief Извлечение элемента из буфера.
    int Remove();

    // !brief Деструктор.
    ~RingBuffer();
};