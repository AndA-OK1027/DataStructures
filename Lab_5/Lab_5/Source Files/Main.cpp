#include <iostream>
#include <string>
#include "..\Header Files\BinaryTree.h"
#include "..\Header Files\Treap.h"

using namespace std;

// \!brief Проверяет ввод пользователя на числовое значение.
// \!returns Число, введенное пользователем, если успешно преобразована строка из консоли. 
int CheckInput()
{
    std::cout << "Ваш ввод: ";

    std::string input;

    while (true)
    {
        try
        {
            std::cin >> input;
            size_t pos;
            // попытка преобразовать строку в число
            int value = std::stoi(input, &pos);
            // проверка на то, все ли символы строки преобразованы.
            if (pos == input.length())
            {
                return value;
            }
            else
            {
                std::cout << "Введено неверное значение (нечисловые символы). Повторите ввод: ";
            }
        }
        catch (std::invalid_argument& e)
        {
            std::cout << "Введено неверное значение (не число). Повторите ввод: ";
        }

    }
}

// \!brief Вывод двоичного дерева.
// \!param node - корень.
void PrintBinaryTree(TreeNode* node)
{
    if (node == nullptr)
    {
        std::cout << " - ";
        return;
    }

    std::cout << "(" << node->key << " ";
    PrintBinaryTree(node->left);
    std::cout << " ";
    PrintBinaryTree(node->right);
    std::cout << ")";
}

// \!brief Вывод декартового дерева.
// \!param node - корень.
void PrintTreap(TreapNode* node)
{
    if (node == nullptr)
    {
        std::cout << " - ";
        return;
    }

    std::cout << "(" << node->Key << " ";
    PrintTreap(node->Left);
    std::cout << " ";
    PrintTreap(node->Right);
    std::cout << ")";
}

// \!brief Для работы с декартовым деревом.
// \!param treap - дерево.
void TreapMenu(Treap* treap)
{
    while (true)
    {
        std::cout << "Текущий дерево: " << std::endl;
        PrintTreap(treap->Root);
        std::cout << "Выберете действие: " << std::endl;
        std::cout << "\n0. Выйти и удалить дерево.\
            \n1.Добавить элемент.\
            \n2.Удалить элемент.\
		    \n3. Найти элемент. " << std::endl;
        int treeOption = CheckInput();

        switch (treeOption)
        {
        case 0:
        {
            delete treap;
            return;
        } // case 0

        case 1:
        {
            std::cout << "Введите элемент:" << std::endl;
            int AddValue;
            std::cin >> AddValue;
            treap->Insert(AddValue);
            break;
        }// case 1

        case 2:
        {
            std::cout << "Введите элемент:" << std::endl;
            int RemoveValue;
            std::cin >> RemoveValue;
            try
            {
                treap->Remove(RemoveValue);
            }
            catch (exception)
            {
                cout << "Ошибка" << endl;
            }
            break;
            
        }// 2

        case 3:
        {
            std::cout << "Введите элемент:" << std::endl;
            int FindValue;
            std::cin >> FindValue;
            try
            {
                if (treap->Search(FindValue) == nullptr)
                {
                    cout << "Не найден" << endl;
                }
                else
                {
                    cout << "Найден" << endl;
                }
            }
            catch (exception)
            {
                cout << "Ошибка" << endl;
            }
            break;
        }// 3

        default:
        {
            std::cout << "Выберите команду: " << std::endl;
        } // default

        } //switch

    } // while true
}

// \!brief Для работы с декартовым деревом.
// \!param treap - дерево.
void BinaryTreeMenu(BinaryTree* bst)
{
    while (true)
    {
        std::cout << "Текущий дерево: " << std::endl;
        PrintBinaryTree(bst->Root);
        std::cout << "Выберете действие: " << std::endl;
        std::cout << "\n0. Выйти и удалить дерево.\
            \n1. Добавить элемент.\
            \n2. Удалить элемент.\
            \n3. Вывести максимальный элемент.\
		    \n4. Вывести минимальный элемент.\
            \n5. Найти элемент. " << std::endl;
        int treeOption = CheckInput();

        switch (treeOption)
        {
        case 0:
        {
            delete bst;
            return;
        } // case 0

        case 1:
        {
            std::cout << "Введите элемент:" << std::endl;
            int AddValue;
            std::cin >> AddValue;
            bst->Insert(AddValue);
            break;
        }// case 1

        case 2:
        {
            std::cout << "Введите элемент:" << std::endl;
            int RemoveValue;
            std::cin >> RemoveValue;
            try
            {
                bst->Remove(RemoveValue);
            }
            catch (exception)
            {
                cout << "Ошибка" << endl;
            }
            break;
        }// 2

        case 3:
        {
            std::cout << "Максимальный элемент:" << std::endl;
            cout << bst->FindMax() << endl;
            break;
        }// 3

        case 4:
        {
            std::cout << "Минимальный элемент:" << std::endl;
            cout << bst->FindMin() << endl;
            break;
        }

        case 5:
        {
            std::cout << "Введите элемент:" << std::endl;
            int FindValue;
            std::cin >> FindValue;
            try
            {
                if (bst->Search(FindValue) == nullptr)
                {
                    cout << "Не найден" << endl;
                }
                else
                {
                    cout << "Найден" << endl;
                }
            }
            catch (exception)
            {
                cout << "Ошибка" << endl;
            }
            break;
        }

        default:
        {
            std::cout << "Выберите команду: " << std::endl;
        } // default

        } //switch

    } // while true
}

//
int main()
{
    setlocale(LC_ALL, "ru");

    int structChoice;

    do
    {
        std::cout << "Выберете структуру: " << std::endl;
        std::cout << "\n0. Выйти.\
            \n1. Двоичное дерево поиска.\
			\n2. Декартово дерево." << std::endl;
        structChoice = CheckInput();

        switch (structChoice)
        {
        case 0:
        {
            break;
        }

        case 1:
        {
            BinaryTree* bst = new BinaryTree();
            BinaryTreeMenu(bst);
            break;
        }

        case 2:
        {
            Treap* treap = new Treap();
            TreapMenu(treap);
            break;
        }

        default:
        {
            std::cout << "Выберите команду: " << std::endl;
        } // default

        } // switch

    } while (structChoice != 0);

    return 0;
}