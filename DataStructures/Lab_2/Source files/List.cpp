#include <iostream>
#include "C:\Users\User\source\repos\DataStructures\Lab_2\Header Files\Node.h"
#include "C:\Users\User\source\repos\DataStructures\Lab_2\Header Files\List.h"

// Получение размера списка
int List::GetSize() const 
{
    return Size;
}

// !brief Конструктор
List::List() : Head(nullptr), Tail(nullptr), Size(0) {}

// !brief Деструктор
List::~List()
{
    while (Head)
    {
        Node* tmp = Head;
        Head = Head->Next;
        delete tmp;
    }

    Tail = nullptr;
    Size = 0;
}

// !brief Добавление элемента в конец
void List::AddLast(int value) 
{
    Node* newItem = new Node(value);
    if (!Head) 
    {
        Head = newItem;
        Tail = newItem;
    }
    else 
    {
        Tail->Next = newItem;
        newItem->Prev = Tail;
        Tail = newItem;
    }
    Size++;
}

// !brief Вставка элемента в начало
void List::AddFirst(int value) 
{
    Node* newItem = new Node(value);
    if (Head == nullptr) 
    {
        Head = newItem;
        Tail = newItem;
    }
    else 
    {
        newItem->Next = Head;
        Head->Prev = newItem;
        Head = newItem;
    }

    Size++;
}

// !brief Удаление элемента
void List::Remove(int value)
{
    Node* current = Head;
    while (current)
    {
        if (current->Data == value) 
        {
            if (current->Prev)
            {
                current->Prev->Next = current->Next;
            }
            else
            {
                Head = current->Next;
            }

            if (current->Next)
            {
                current->Next->Prev = current->Prev;
            }
            else
            {
                Tail = current->Prev;
            }

            delete current;
            Size--;
            return;
        }

        current = current->Next;
    }
}

// !brief Вставка после определенного элемента
void List::InsertAfter(int newValue, int afterValue) 
{
    Node* current = Head;

    if (LinearSearch(afterValue) == -1)
    {
        throw std::invalid_argument("After element not found");
    }

    while (current) 
    {
        if (current->Data == afterValue) 
        {
            Node* newNode = new Node(newValue);
            newNode->Next = current->Next;
            newNode->Prev = current;
            if (current->Next) 
            {
                current->Next->Prev = newNode;
            }
            else 
            {
                Tail = newNode;
            }
            current->Next = newNode;
            Size++;
            return;
        }

        current = current->Next;
    }
}

// !brief Вставка перед определенным элементом
void List::InsertBefore(int newValue, int beforeValue) 
{
    if (LinearSearch(beforeValue) == -1)
    {
        throw std::invalid_argument("Before element not found");
    }

    Node* current = Head;
    while (current) 
    {
        if (current->Data == beforeValue) 
        {
            Node* newNode = new Node(newValue);
            newNode->Prev = current->Prev;
            newNode->Next = current;
            if (current->Prev) 
            {
                current->Prev->Next = newNode;
            }
            else 
            {
                Head = newNode; 
            }
            current->Prev = newNode;
            Size++;
            return;
        }

        current = current->Next;
    }
    
}

// !brief Сортировка
void List::Sort()
{
    if (Head == NULL) return;

    bool swapped;
    do 
    {
        swapped = false;
        Node* current = Head;
        while (current->Next) 
        {
            if (current->Data > current->Next->Data) 
            {
                std::swap(current->Data, current->Next->Data);
                swapped = true;
            }
            current = current->Next;
        }
    } 
    while (swapped);
}

// !brief Линейный поиск
int List::LinearSearch(int value) 
{
    Node* current = Head;
    int index = 0;
    while (current) 
    {
        if (current->Data == value) 
        {
            return index;
        }
        current = current->Next;
        ++index;
    }

    return -1;
}
