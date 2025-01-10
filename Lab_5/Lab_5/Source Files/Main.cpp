#include <iostream>
#include <string>
#include "..\Header Files\BinaryTree.h"
#include "..\Header Files\Treap.h"

using namespace std;

// \!brief ��������� ���� ������������ �� �������� ��������.
// \!returns �����, ��������� �������������, ���� ������� ������������� ������ �� �������. 
int CheckInput()
{
    std::cout << "��� ����: ";

    std::string input;

    while (true)
    {
        try
        {
            std::cin >> input;
            size_t pos;
            // ������� ������������� ������ � �����
            int value = std::stoi(input, &pos);
            // �������� �� ��, ��� �� ������� ������ �������������.
            if (pos == input.length())
            {
                return value;
            }
            else
            {
                std::cout << "������� �������� �������� (���������� �������). ��������� ����: ";
            }
        }
        catch (std::invalid_argument& e)
        {
            std::cout << "������� �������� �������� (�� �����). ��������� ����: ";
        }

    }
}

// \!brief ����� ��������� ������.
// \!param node - ������.
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

// \!brief ����� ����������� ������.
// \!param node - ������.
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

// \!brief ��� ������ � ���������� �������.
// \!param treap - ������.
void TreapMenu(Treap* treap)
{
    while (true)
    {
        std::cout << "������� ������: " << std::endl;
        PrintTreap(treap->Root);
        std::cout << "�������� ��������: " << std::endl;
        std::cout << "\n0. ����� � ������� ������.\
            \n1.�������� �������.\
            \n2.������� �������.\
		    \n3. ����� �������. " << std::endl;
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
            std::cout << "������� �������:" << std::endl;
            int AddValue;
            std::cin >> AddValue;
            treap->Insert(AddValue);
            break;
        }// case 1

        case 2:
        {
            std::cout << "������� �������:" << std::endl;
            int RemoveValue;
            std::cin >> RemoveValue;
            try
            {
                treap->Remove(RemoveValue);
            }
            catch (exception)
            {
                cout << "������" << endl;
            }
            break;
            
        }// 2

        case 3:
        {
            std::cout << "������� �������:" << std::endl;
            int FindValue;
            std::cin >> FindValue;
            try
            {
                if (treap->Search(FindValue) == nullptr)
                {
                    cout << "�� ������" << endl;
                }
                else
                {
                    cout << "������" << endl;
                }
            }
            catch (exception)
            {
                cout << "������" << endl;
            }
            break;
        }// 3

        default:
        {
            std::cout << "�������� �������: " << std::endl;
        } // default

        } //switch

    } // while true
}

// \!brief ��� ������ � ���������� �������.
// \!param treap - ������.
void BinaryTreeMenu(BinaryTree* bst)
{
    while (true)
    {
        std::cout << "������� ������: " << std::endl;
        PrintBinaryTree(bst->Root);
        std::cout << "�������� ��������: " << std::endl;
        std::cout << "\n0. ����� � ������� ������.\
            \n1. �������� �������.\
            \n2. ������� �������.\
            \n3. ������� ������������ �������.\
		    \n4. ������� ����������� �������.\
            \n5. ����� �������. " << std::endl;
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
            std::cout << "������� �������:" << std::endl;
            int AddValue;
            std::cin >> AddValue;
            bst->Insert(AddValue);
            break;
        }// case 1

        case 2:
        {
            std::cout << "������� �������:" << std::endl;
            int RemoveValue;
            std::cin >> RemoveValue;
            try
            {
                bst->Remove(RemoveValue);
            }
            catch (exception)
            {
                cout << "������" << endl;
            }
            break;
        }// 2

        case 3:
        {
            std::cout << "������������ �������:" << std::endl;
            cout << bst->FindMax() << endl;
            break;
        }// 3

        case 4:
        {
            std::cout << "����������� �������:" << std::endl;
            cout << bst->FindMin() << endl;
            break;
        }

        case 5:
        {
            std::cout << "������� �������:" << std::endl;
            int FindValue;
            std::cin >> FindValue;
            try
            {
                if (bst->Search(FindValue) == nullptr)
                {
                    cout << "�� ������" << endl;
                }
                else
                {
                    cout << "������" << endl;
                }
            }
            catch (exception)
            {
                cout << "������" << endl;
            }
            break;
        }

        default:
        {
            std::cout << "�������� �������: " << std::endl;
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
        std::cout << "�������� ���������: " << std::endl;
        std::cout << "\n0. �����.\
            \n1. �������� ������ ������.\
			\n2. ��������� ������." << std::endl;
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
            std::cout << "�������� �������: " << std::endl;
        } // default

        } // switch

    } while (structChoice != 0);

    return 0;
}