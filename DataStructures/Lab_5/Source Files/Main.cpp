#include <iostream>
#include "..\Header Files\BinaryTree.h"

using namespace std;

int main()
{
    BinaryTree bst;
    bst.add(10);
    bst.add(5);
    bst.add(20);
    bst.add(3);
    bst.add(7);

    std::cout << "�������: " << bst.findMin() << std::endl; // 3
    std::cout << "��������: " << bst.findMax() << std::endl; // 20
    std::cout << "����� 7: " << (bst.search(7) ? "������" : "�� ������") << std::endl; // ������
    bst.remove(5);
    std::cout << "����� 5 ����� ��������: " << (bst.search(5) ? "������" : "�� ������") << std::endl; // �� ������

    return 0;
}