#pragma once

// !\brief Описание структуры элемента бинарного дерева поиска.
struct TreeNode
{
    // !\brief Ключ элемента дерева.
    int key;
    // !\brief Указатель на левый элемент.
    TreeNode* left;
    // !\brief Указатель на правый элемент.
    TreeNode* right;

    // !\brief Конструктор элемента дерева.
    // !\param value - значение для ключа.
    TreeNode(int value);
};