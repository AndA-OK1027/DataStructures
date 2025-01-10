#pragma once
#include <iostream>

// !\brief �������� ��������� �������� ����������� ������.
struct TreapNode
{

public:

    // !\brief ����
    int Key;

    // !\brief ���������.
    int Priority;

    // !\brief ��������� �� ����� �������.
    TreapNode* Left;

    // !\brief ��������� �� ������ �������.
    TreapNode* Right;

    // !\brief �����������.
    // !\param key - ����.
    TreapNode(int key);

};

