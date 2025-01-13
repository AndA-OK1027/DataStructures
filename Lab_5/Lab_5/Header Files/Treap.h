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
    TreapNode* InsertNodeNotOptimized(TreapNode*& node, int key);

    // !\brief Добавление .
    // !\param node - Указатель на узел.
    // !\param key - Ключ по которому добавлять.
    TreapNode* InsertNodeOptimized(TreapNode*& node, int key);

    // !\brief Удаление.
    // !\param node - Указатель на узел.
    // !\param key - Ключ по которому удалять.
    TreapNode* RemoveNodeNotOptimized(TreapNode*& node, int key);

    // !\brief Удаление.
    // !\param node - Указатель на узел.
    // !\param key - Ключ по которому удалять.
    TreapNode* RemoveNodeOptimized(TreapNode*& node, int key);

public:

    // !\brief Указатель на корневой элемент.
    TreapNode* Root;

    // !\brief Конструктор.
    Treap();

    // TODO: Не реализован оптимизированный алгоритм (1 Split) добавления 
    // !\brief Добавление.
    // !\param key - Ключ по которому добавлять.
    void InsertNotOptimized(int key);

    // !\brief Добавление.
    // !\param key - Ключ по которому добавлять.
    void Insert(int key);

    // !\brief Удаление.
    // !\param key - Ключ по которому удалять.
    void RemoveNotOptimized(int key);

    // TODO: Не реализованы алгоритмы удаления 
    // !\brief Удаление.
    // !\param key - Ключ по которому удалять.
    void Remove(int key);

    // !\brief Указатель на корневой элемент.
    // !\param key - Ключ по которому искать.
    TreapNode* Search(int key) const;

    // !\brief Очищает дерево.
    void Clear(TreapNode* node);

    // !\brief Деструктор.
    ~Treap();
};
