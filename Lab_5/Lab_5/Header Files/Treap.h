#pragma once
#include "../Header Files/TreapNode.h"

// !\brief Описание структуры декартового дерева.
struct Treap
{
private:

    // !\brief Разрезание.
    // !\param node - Указатель на узел.
    // !\param key - Ключ по которому разрезать.
    // !\param left - Указатель на левый узел.
    // !\param right - Указатель на правый узел.
    void Split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right);

    // !\brief Слияние.
    // !\param left - Указатель на левый узел.
    // !\param right - Указатель на правый узел.
    // !\returns Указатель на узел.
    TreapNode* Merge(TreapNode* left, TreapNode* right);

    // !\brief Добавление.
    // !\param node - Указатель на узел.
    // !\param key - Ключ по которому добавлять.
    TreapNode* InsertNode(TreapNode*& node, int key);

    // !\brief Удаление.
    // !\param node - Указатель на узел.
    // !\param key - Ключ по которому удалять.
    TreapNode* RemoveNode(TreapNode*& node, int key);

public:

    // !\brief Указатель на корневой элемент.
    TreapNode* Root;

    // !\brief Конструктор.
    Treap();

    // !\brief Добавление.
    // !\param key - Ключ по которому добавлять.
    void Insert(int key);

    // !\brief Удаление.
    // !\param key - Ключ по которому удалять.
    void Remove(int key);

    // !\brief Указатель на корневой элемент.
    // !\param key - Ключ по которому искать.
    TreapNode* Search(int key);

    // !\brief Очищает дерево.
    void Clear(TreapNode* node);

    // !\brief Деструктор.
    ~Treap();
};
