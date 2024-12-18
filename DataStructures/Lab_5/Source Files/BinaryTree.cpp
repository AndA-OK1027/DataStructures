#include <iostream>
#include <memory>

#include "../Header Files/BinaryTree.h"

using namespace std;

int key;
unique_ptr<TreeNode> left;
unique_ptr<TreeNode> right;

BinaryTree::TreeNode(int value) : key(value), left(nullptr), right(nullptr) {}

unique_ptr<TreeNode> root;

void addNode(std::unique_ptr<TreeNode>& node, int key) 
{
    if (!node)
    {
        node = std::make_unique<TreeNode>(key);
    }
    else if (key < node->key)
    {
        addNode(node->left, key);
    }
    else
    {
        addNode(node->right, key);
    }
}

std::unique_ptr<TreeNode>& findNode(std::unique_ptr<TreeNode>& node, int key)
{
    if (!node || node->key == key)
    {
        return node;
    }
    else if (key < node->key)
    {
        return findNode(node->left, key);
    }
    else
    {
        return findNode(node->right, key);
    }
}

void deleteNode(std::unique_ptr<TreeNode>& node, int key)
{
    if (!node) return;

    if (key < node->key)
    {
        deleteNode(node->left, key);
    }
    else if (key > node->key)
    {
        deleteNode(node->right, key);
    }
    else
    {
        if (!node->left)
        {
            node = std::move(node->right);
        }
        else if (!node->right)
        {
            node = std::move(node->left);
        }
        else
        {
            // Найти минимальный элемент в правом поддереве
            TreeNode* minRight = findMin(node->right.get());
            node->key = minRight->key;
            deleteNode(node->right, minRight->key);
        }
    }
}

TreeNode* findMin(TreeNode* node)
{
    while (node->left)
    {
        node = node->left.get();
    }
    return node;
}

TreeNode* findMax(TreeNode* node)
{
    while (node->right)
    {
        node = node->right.get();
    }
    return node;
}

BinaryTree::BinaryTree() : root(nullptr) {}

void add(int key)
{
    addNode(root, key);
}

void remove(int key)
{
    deleteNode(root, key);
}

bool search(int key)
{
    return (findNode(root, key) != nullptr);
}

int findMin()
{
    if (!root) throw std::runtime_error("Tree is empty");
    return findMin(root.get())->key;
}

int findMax()
{
    if (!root) throw std::runtime_error("Tree is empty");
    return findMax(root.get())->key;
}


int main() 
{
    BinaryTree bst;
    bst.add(10);
    bst.add(5);
    bst.add(20);
    bst.add(3);
    bst.add(7);

    std::cout << "Минимум: " << bst.findMin() << std::endl; // 3
    std::cout << "Максимум: " << bst.findMax() << std::endl; // 20
    std::cout << "Поиск 7: " << (bst.search(7) ? "Найден" : "Не найден") << std::endl; // Найден
    bst.remove(5);
    std::cout << "Поиск 5 после удаления: " << (bst.search(5) ? "Найден" : "Не найден") << std::endl; // Не найден

    return 0;
}