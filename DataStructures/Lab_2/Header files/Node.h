#pragma once

struct Node 
{
public:
    // �������� ��������
    int Data;

    // ������ �� ���������
    Node* Next;

    // ������ �� ����������
    Node* Prev;

    // ����������� ��������� �������, ��� ������.
    // \param value: ������������� �������
    Node(int value);
};