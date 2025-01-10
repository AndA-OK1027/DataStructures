#pragma once
#include "../Header Files/TreeNode.h"

// !\brief Описание структуры бинарного дерева поиска.
struct BinaryTree
{
private:

    // !\brief Добавляет узел.
    // !\param node - указатель на узел.
    // !\param key - ключ который нужно удалить.
    // !\returns Указатель на узел.
    TreeNode* AddNode(TreeNode* node, int value);

    // !\brief Удаляет узел.
    // !\param node - указатель на узел.
    // !\param value - ключ который нужно удалить.
    // !\returns Указатель на узел.
    TreeNode* DeleteNode(TreeNode* node, int value);

    // !\brief Ищет узел.
    // !\param node - указатель на узел.
    // !\param value - ключ который нужно найти.
    // !\returns Указатель на узел.
    TreeNode* FindNode(TreeNode* node, int value);

    // !\brief Ищет минимальный узел.
    // !\param node - указатель на узел.
    // !\returns Указатель на узел.
    TreeNode* FindMinNode(TreeNode* node);

    // !\brief Ищет максимальный узел.
    // !\param node - указатель на узел.
    // !\returns Указатель на узел.
    TreeNode* FindMaxNode(TreeNode* node);

public:

    // !\brief Указатель на корень всего дерева.
    TreeNode* Root;

    // !\brief Конструктор.
    BinaryTree();

    // !\brief Добавляет узел в дерево.
    // !\param value - элемент для добавления.
    void Insert(int value);

    // !\brief Удаляет узел из дерева.
    // !\param value - ключ который нужно удалить.
    // !\returns Указатель на узел.
    void Remove(int value);

    // !\brief Ищет минимальный узел в дереве.
    // !\param node - указатель на узел.
    // !\returns Указатель на узел.
    int FindMin();

    // !\brief Ищет максимальный узел в дереве.
    // !\param node - указатель на узел.
    // !\returns Указатель на узел.
    int FindMax();

    // !\brief Поиск по ключу.
    TreeNode* Search(int key);

};