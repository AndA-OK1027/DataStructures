#pragma once
#include <iostream>
#include "..\Header Files\Node.h"
#include "..\Header Files\List.h"

// !brief Определение структуры двусвязного списка.
struct List
{ 
public:
    // !brief Начало списка
    Node* Head;

    // !brief Конец списка
    Node* Tail;

    // !brief Размер списка
    int Size;

    // \!brief Получение размера списка
    // \returns Размер списка
    int GetSize() const;

    // !brief Конструктор
    List();

    // !brief Деструктор
    ~List();

    // !brief Добавление элемента в конец
    void AddLast(int value);

    // !brief Вставка элемента в начало
    void AddFirst(int value);

    // !brief Удаление элемента.
    void Remove(int value);

    // !brief Вставка после определенного элемента.
    // \param newValue: новый элемент
    // \param beforeValue: элеемнт после которого вставить
    void InsertAfter(int newValue, int afterValue);

    // !brief Вставка перед определенным элементом.
    // \param newValue: новый элемент
    // \param beforeValue: элеемнт перед которым вставить
    void InsertBefore(int newValue, int beforeValue);
    
    // !brief Сортировка
    void Sort();

    // Линейный поиск.
    // \return есть ли элемент.
    int LinearSearch(int value);
};