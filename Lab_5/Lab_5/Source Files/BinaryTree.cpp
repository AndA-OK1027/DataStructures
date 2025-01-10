#include <iostream>
#include <memory>

#include "../Header Files/BinaryTree.h"

using namespace std;


BinaryTree::BinaryTree() : Root(nullptr) {}

TreeNode* BinaryTree::AddNode(TreeNode* node, int value)
{
    // ���� ����� ���, ������� ���.
    if (node == nullptr) 
    {
        return new TreeNode(value);
    }
    // ���� ���� ������ �����, ��������� � ����� ���������;
    if (node->key > value) 
    {
        node->left = AddNode(node->left, value);
    }
    // ����� � ������.
    else if (node->key < value) 
    {
        node->right = AddNode(node->right, value);
    }
    // ���������� ������������ ��������� �� ����.
    return node; 
}

TreeNode* BinaryTree::FindNode(TreeNode* node, int value)
{
    // ���������� ��������� �� ���������� ����, ���� ������ ����� ��� ������� ������.
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
    // ������ �������
    if (node == nullptr) 
    {
        return node;
    }

    //  ������� ����������.
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
        // ���� � ����� �������� ��� ��� ��������
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

        // ���� � ����� ���������: �������� ����������� ���� �� ������� ���������
        TreeNode* temp = FindMinNode(node->right);
        // �������� �������� ������������ ����
        node->key = temp->key; 
        // ������� ����������� ����
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
