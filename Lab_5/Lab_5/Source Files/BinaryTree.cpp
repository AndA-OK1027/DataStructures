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
    if (node->Key > value) 
    {
        node->Left = AddNode(node->Left, value);
    }
    // Иначе в правое.
    else if (node->Key < value) 
    {
        node->Right = AddNode(node->Right, value);
    }
    // Возвращаем неизмененный указатель на узел.
    return node; 
}

TreeNode* BinaryTree::FindNode(TreeNode* node, int value)
{
    // Возвращаем указатель на переданный узел, если дерево пусто или элемент найден.
    if (node == nullptr || node->Key == value) 
    {
        return node;
    }

    if (node->Key > value) 
    {
        return FindNode(node->Left, value);
    }
    else
    {
        return FindNode(node->Right, value);
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
    if (value < node->Key) 
    {
        node->Left = DeleteNode(node->Left, value);
    }
    else if (value > node->Key) 
    {
        node->Right = DeleteNode(node->Right, value);
    }
    else 
    {
        // Узел с одним потомком или без потомков
        if (node->Left == nullptr) 
        {
            TreeNode* temp = node->Right;
            delete node;
            return temp;
        }
        else if (node->Right == nullptr) 
        {
            TreeNode* temp = node->Left;
            delete node;
            return temp;
        }

        // Узел с двумя потомками: получить минимальный узел из правого поддерева
        TreeNode* temp = FindMinNode(node->Right);
        // Копируем значение минимального узла
        node->Key = temp->Key; 
        // Удаляем минимальный узел
        node->Right = DeleteNode(node->Right, temp->Key); 
    }
    return node;
}

TreeNode* BinaryTree::FindMinNode(TreeNode* node)
{
    while (node->Left != nullptr)
    {
        node = node->Left;
    }
    return node;
}

TreeNode* BinaryTree::FindMaxNode(TreeNode* node)
{
    while (node->Right != nullptr)
    {
        node = node->Right;
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
    return FindMinNode(Root)->Key;
}

int BinaryTree::FindMax()
{
    return FindMaxNode(Root)->Key;
}

TreeNode* BinaryTree::Search(int key)
{
    if (FindNode(Root, key) != nullptr)
    {
        return FindNode(Root, key);
    }
    else return nullptr;
}
