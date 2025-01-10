#include <iostream>
#include <memory>

#include "../Header Files/BinaryTree.h"

using namespace std;


BinaryTree::BinaryTree() : Root(nullptr) {}

TreeNode* BinaryTree::AddNode(TreeNode* node, int value)
{
    // Если корня нет, создаем его.
    if (node == nullptr) 
    {
        return new TreeNode(value);
    }
    // Если ключ меньше корня, добавляем в левое поддерево;
    if (node->key > value) 
    {
        node->left = AddNode(node->left, value);
    }
    // Иначе в правое.
    else if (node->key < value) 
    {
        node->right = AddNode(node->right, value);
    }
    // Возвращаем неизмененный указатель на узел.
    return node; 
}

TreeNode* BinaryTree::FindNode(TreeNode* node, int value)
{
    // Возвращаем указатель на переданный узел, если дерево пусто или элемент найден.
    if (node == nullptr || node->key == value) 
    {
        return node;
    }

    if (node->key > value) 
    {
        return FindNode(node->left, value);
    }
    else
    {
        return FindNode(node->right, value);
    }
}

TreeNode* BinaryTree::DeleteNode(TreeNode* node, int value)
{
    // Нечего удалять
    if (node == nullptr) 
    {
        return node;
    }

    //  Удаляем рекурсивно.
    if (value < node->key) 
    {
        node->left = DeleteNode(node->left, value);
    }
    else if (value > node->key) 
    {
        node->right = DeleteNode(node->right, value);
    }
    else 
    {
        // Узел с одним потомком или без потомков
        if (node->left == nullptr) 
        {
            TreeNode* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr) 
        {
            TreeNode* temp = node->left;
            delete node;
            return temp;
        }

        // Узел с двумя потомками: получить минимальный узел из правого поддерева
        TreeNode* temp = FindMinNode(node->right);
        // Копируем значение минимального узла
        node->key = temp->key; 
        // Удаляем минимальный узел
        node->right = DeleteNode(node->right, temp->key); 
    }
    return node;
}

TreeNode* BinaryTree::FindMinNode(TreeNode* node)
{
    while (node->left != nullptr)
    {
        node = node->left;
    }
    return node;
}

TreeNode* BinaryTree::FindMaxNode(TreeNode* node)
{
    while (node->right != nullptr)
    {
        node = node->right;
    }
    return node;
}

void BinaryTree::Insert(int value)
{
    Root = AddNode(Root, value);
}

void BinaryTree::Remove(int value)
{
    DeleteNode(Root, value);
}

int BinaryTree::FindMin()
{
    return FindMinNode(Root)->key;
}

int BinaryTree::FindMax()
{
    return FindMaxNode(Root)->key;
}

TreeNode* BinaryTree::Search(int key)
{
    if (FindNode(Root, key) != nullptr)
    {
        return FindNode(Root, key);
    }
    else return nullptr;
}
