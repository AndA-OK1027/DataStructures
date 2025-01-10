#pragma once
#include <iostream>

// !\brief Описание структуры элемента декартового дерева.
struct TreapNode
{

public:

    // !\brief Ключ
    int Key;

    // !\brief Приоритет.
    int Priority;

    // !\brief Указатель на левый элемент.
    TreapNode* Left;

    // !\brief Указатель на правый элемент.
    TreapNode* Right;

    // !\brief Конструктор.
    // !\param key - ключ.
    TreapNode(int key);

};

