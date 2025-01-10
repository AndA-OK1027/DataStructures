#pragma once
#include "../Header Files/TreapNode.h"

// !\brief �������� ��������� ����������� ������.
struct Treap
{
private:

    // !\brief ����������.
    // !\param node - ��������� �� ����.
    // !\param key - ���� �� �������� ���������.
    // !\param left - ��������� �� ����� ����.
    // !\param right - ��������� �� ������ ����.
    void Split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right);

    // !\brief �������.
    // !\param left - ��������� �� ����� ����.
    // !\param right - ��������� �� ������ ����.
    // !\returns ��������� �� ����.
    TreapNode* Merge(TreapNode* left, TreapNode* right);

    // !\brief ����������.
    // !\param node - ��������� �� ����.
    // !\param key - ���� �� �������� ���������.
    TreapNode* InsertNode(TreapNode*& node, int key);

    // !\brief ��������.
    // !\param node - ��������� �� ����.
    // !\param key - ���� �� �������� �������.
    TreapNode* RemoveNode(TreapNode*& node, int key);

public:

    // !\brief ��������� �� �������� �������.
    TreapNode* Root;

    // !\brief �����������.
    Treap();

    // !\brief ����������.
    // !\param key - ���� �� �������� ���������.
    void Insert(int key);

    // !\brief ��������.
    // !\param key - ���� �� �������� �������.
    void Remove(int key);

    // !\brief ��������� �� �������� �������.
    // !\param key - ���� �� �������� ������.
    TreapNode* Search(int key);

    // !\brief ������� ������.
    void Clear(TreapNode* node);

    // !\brief ����������.
    ~Treap();
};
