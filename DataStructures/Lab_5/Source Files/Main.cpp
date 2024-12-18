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

    std::cout << "Минимум: " << bst.findMin() << std::endl; // 3
    std::cout << "Максимум: " << bst.findMax() << std::endl; // 20
    std::cout << "Поиск 7: " << (bst.search(7) ? "Найден" : "Не найден") << std::endl; // Найден
    bst.remove(5);
    std::cout << "Поиск 5 после удаления: " << (bst.search(5) ? "Найден" : "Не найден") << std::endl; // Не найден

    return 0;
}