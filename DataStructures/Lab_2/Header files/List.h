#pragma once
#include <iostream>
#include "..\Header Files\Node.h"
#include "..\Header Files\List.h"

// !brief ����������� ��������� ����������� ������.
struct List
{ 
public:
    // !brief ������ ������
    Node* Head;

    // !brief ����� ������
    Node* Tail;

    // !brief ������ ������
    int Size;

    // \!brief ��������� ������� ������
    // \returns ������ ������
    int GetSize() const;

    // !brief �����������
    List();

    // !brief ����������
    ~List();

    // !brief ���������� �������� � �����
    void AddLast(int value);

    // !brief ������� �������� � ������
    void AddFirst(int value);

    // !brief �������� ��������.
    void Remove(int value);

    // !brief ������� ����� ������������� ��������.
    // \param newValue: ����� �������
    // \param beforeValue: ������� ����� �������� ��������
    void InsertAfter(int newValue, int afterValue);

    // !brief ������� ����� ������������ ���������.
    // \param newValue: ����� �������
    // \param beforeValue: ������� ����� ������� ��������
    void InsertBefore(int newValue, int beforeValue);
    
    // !brief ����������
    void Sort();

    // �������� �����.
    // \return ���� �� �������.
    int LinearSearch(int value);
};