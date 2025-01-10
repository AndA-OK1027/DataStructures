#pragma once
#include "../Header Files/TreeNode.h"

// !\brief �������� ��������� ��������� ������ ������.
struct BinaryTree
{
private:

    // !\brief ��������� ����.
    // !\param node - ��������� �� ����.
    // !\param key - ���� ������� ����� �������.
    // !\returns ��������� �� ����.
    TreeNode* AddNode(TreeNode* node, int value);

    // !\brief ������� ����.
    // !\param node - ��������� �� ����.
    // !\param value - ���� ������� ����� �������.
    // !\returns ��������� �� ����.
    TreeNode* DeleteNode(TreeNode* node, int value);

    // !\brief ���� ����.
    // !\param node - ��������� �� ����.
    // !\param value - ���� ������� ����� �����.
    // !\returns ��������� �� ����.
    TreeNode* FindNode(TreeNode* node, int value);

    // !\brief ���� ����������� ����.
    // !\param node - ��������� �� ����.
    // !\returns ��������� �� ����.
    TreeNode* FindMinNode(TreeNode* node);

    // !\brief ���� ������������ ����.
    // !\param node - ��������� �� ����.
    // !\returns ��������� �� ����.
    TreeNode* FindMaxNode(TreeNode* node);

public:

    // !\brief ��������� �� ������ ����� ������.
    TreeNode* Root;

    // !\brief �����������.
    BinaryTree();

    // !\brief ��������� ���� � ������.
    // !\param value - ������� ��� ����������.
    void Insert(int value);

    // !\brief ������� ���� �� ������.
    // !\param value - ���� ������� ����� �������.
    // !\returns ��������� �� ����.
    void Remove(int value);

    // !\brief ���� ����������� ���� � ������.
    // !\param node - ��������� �� ����.
    // !\returns ��������� �� ����.
    int FindMin();

    // !\brief ���� ������������ ���� � ������.
    // !\param node - ��������� �� ����.
    // !\returns ��������� �� ����.
    int FindMax();

    // !\brief ����� �� �����.
    TreeNode* Search(int key);

};