#pragma once

// !\brief Описание структуры элемента бинарного дерева поиска.
struct TreeNode
{
    // !\brief Ключ элемента дерева.
    int Key;
    // !\brief Указатель на левый элемент.
    TreeNode* Left;
    // !\brief Указатель на правый элемент.
    TreeNode* Right;

    // !\brief Конструктор элемента дерева.
    // !\param value - значение для ключа.
    TreeNode(int value);
};