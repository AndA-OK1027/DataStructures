#pragma once

struct Node 
{
public:
    // Значение элемента
    int Data;

    // Ссылка на следующий
    Node* Next;

    // Ссылка на предыдущий
    Node* Prev;

    // Конструктор создающий элемент, без ссылок.
    // \param value: целочисленный элемент
    Node(int value);
};