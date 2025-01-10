#pragma once

// !\brief �������� ��������� �������� ��������� ������ ������.
struct TreeNode
{
    // !\brief ���� �������� ������.
    int key;
    // !\brief ��������� �� ����� �������.
    TreeNode* left;
    // !\brief ��������� �� ������ �������.
    TreeNode* right;

    // !\brief ����������� �������� ������.
    // !\param value - �������� ��� �����.
    TreeNode(int value);
};