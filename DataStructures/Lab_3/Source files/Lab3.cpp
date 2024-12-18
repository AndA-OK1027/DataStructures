#include <iostream>
#include "..\Header Files\Stack.h"
#include "..\Header Files\RingBuffer.h"
#include "..\Header Files\Queue.h"
#include "..\Header Files\QueueStacks.h"

// Вывод стека.
void PrintStack(Stack* stack)
{
    for (int i = 0; i < stack->GetSize(); i++)
    {
        std::cout << stack->Data[i] << " ";
    }
    std::cout << std::endl;
}

// Вывод кольцевого буфера.
void PrintRing(RingBuffer* cb)
{
    for (int i = 0; i < cb->Size; ++i)
    {
        std::cout << cb->Buffer[i] << " ";
    }
    std::cout << std::endl;
}

// Вывод очереди на кольцевом буфере.
void PrintQueue(Queue* ringQue)
{
    for (int i = 0; i < ringQue->GetSize(); i++)
    {
        std::cout << ringQue->Buffer->Buffer[i] << std::endl;
    }
}

// Вывод очереди на стеках
void PrintStacksQueue(QueueStacks* stacksQue)
{
    for (int i = 0; i < stacksQue->Stack1->GetSize(); i++)
    {
        PrintStack(stacksQue->Stack1);
    }
}

// \!brief Для работы со стеком
void StackMenu()
{
    while (true)
    {
        Stack* stack = new Stack(2);
        stack->Push(77);
        stack->Push(13);
        stack->Push(8);

        std::cout << "Текущий стек: " << std::endl;
        PrintStack(stack);
        int stackOption;
        std::cout << "Выберете действие: " << std::endl;
        std::cout << "\n0. Выйти и удалить стэк.\
            \n1.Добавить элемент.\
		    \n2. Удалить элемент. " << std::endl;
        std::cin >> stackOption;

        switch (stackOption)
        {

        case 0:
        {
            stack->~Stack();
            return;
        } // case 0

        case 1:
        {
            std::cout << "Введите элемент:" << std::endl;
            int stackItem;
            try
            {
                std::cin >> stackItem;
                stack->Push(stackItem);
            }
            catch (std::exception)
            {
                std::cout << "Ошибка!" << std::endl;
            }

            PrintStack(stack);

            break;
        } // case 1

        case 2:
        {
            try
            {
                stack->Pop();
            }
            catch (std::out_of_range)
            {
                std::cout << "Стек пуст!" << std::endl;
            }

            PrintStack(stack);

            break;

        } // case 2

        default:
        {
            std::cout << "Выберите команду.. " << std::endl;
        }

        } // switch stackoption 

    } // while true
}

// Для работы с кольцевым буфером.
void RingMenu() 
{
    while (true)
    {
        RingBuffer* cb = new RingBuffer(3);
        cb->Add(1);
        cb->Add(2);
        PrintRing(cb);

        std::cout << "Текущий кольцевой буфер: " << std::endl;
        PrintRing(cb);
        std::cout << "Выберете действие: " << std::endl;
        std::cout << "\n0. Выйти и удалить текущий кольцевой буфер.\
            \n1. Добавить элемент.\
		    \n2. Удалить элемент.\
            \n3. Получить свободное место. \
            \n4. Получить занятое место. \ " << std::endl;

        int RingItem;
        std::cin >> RingItem;

        switch (RingItem)
        {

        case 0:
        {
            cb->~RingBuffer();
            return;
        } // case 0

        case 1:
        {
            int AddValue;
            std::cout << "Введите значение. " << std::endl;
            std::cin >> AddValue;
            try
            {
                cb->Add(AddValue);
            }
            catch (std::out_of_range)
            {
                std::cout << "Буфер переполнен. " << std::endl;
            }

            std::cout << "Текущий кольцевой буфер: " << std::endl;
            PrintRing(cb);

            break;
        } // case 1

        case 2:
        {
            try
            {
                cb->Remove();
            }
            catch (std::out_of_range)
            {
                std::cout << "Буфер пуст. " << std::endl;
            }

            std::cout << "Текущий кольцевой буфер: " << std::endl;
            PrintRing(cb);

            break;
        } // case 2

        case 3:
        {
            std::cout << "Свободное место: : " << std::endl;
            std::cout << cb->FreeSpace();
            break;
        } // case 3

        case 4:
        {
            std::cout << "Заянтое место: " << std::endl;
            std::cout << cb->OccupiedSpace();
            break;
        } // case 4

        default:
        {
            std::cout << "Выберите команду.." << std::endl;
        } // default

        } // switch
    }
}

// Для работы с очередбю на кольцевом буфере.
void RingQueueMenu()
{
    Queue* ringQue = new Queue(5);
    ringQue->Enqueue(7);
    ringQue->Enqueue(88);
    ringQue->Enqueue(9);

    std::cout << "Текущая очередь." << std::endl;
    PrintQueue(ringQue);

    std::cout << "Выберете действие: " << std::endl;
    std::cout << "\n1. Добавить элемент.\
		    \n2. Удалить элемент. " << std::endl;

    int QueueChoice;
    std::cin >> QueueChoice;

    switch (QueueChoice)
    {

    case 0:
    {
        ringQue->~Queue();
        return;
    }

    case 1:
    {
        std::cout << "Введите элемент:" << std::endl;
        int QueueValue;
        std::cin >> QueueValue;

        try
        {
            ringQue->Enqueue(QueueValue);
        }
        catch (std::out_of_range)
        {
            std::cout << "Невозможно добавить" << std::endl;
        }

        std::cout << "Текущая очередь." << std::endl;
        PrintQueue(ringQue);

        break;
    } // case 1

    case 2:
    {
        try
        {
            ringQue->Dequeue();
        }
        catch (std::out_of_range)
        {
            std::cout << "empty" << std::endl;
        }

        std::cout << "Текущая очередь." << std::endl;
        PrintQueue(ringQue);

        break;
    } // case 2

    default:
    {
        std::cout << "Выберете команду.." << std::endl;
    } // default

    } // switch
}

// Для работы с очередью на стеках.
void StacksQueueMenu()
{
    QueueStacks* stacksQue = new QueueStacks(4);
    stacksQue->Enqueue(8);
    stacksQue->Enqueue(9);
    stacksQue->Enqueue(77);

    while (true)
    {

        std::cout << "Текущая очередь." << std::endl;
        PrintStacksQueue(stacksQue);
        std::cout << "Выберете действие: " << std::endl;
        std::cout << "\n1. Добавить элемент.\
		    \n2. Удалить элемент. " << std::endl;
        int SQueueChoice;
        std::cin >> SQueueChoice;
        switch (SQueueChoice)
        {

        case 0:
        {
            stacksQue->~QueueStacks();
            return;
        }

        case 1:
        {
            std::cout << "Введите элемент:" << std::endl;
            int AddValue;
            std::cin >> AddValue;

            try
            {
                stacksQue->Enqueue(AddValue);
            }
            catch (std::out_of_range)
            {
                std::cout << "Невозможно добавить" << std::endl;
            }

            std::cout << "Текущая очередь." << std::endl;
            PrintStacksQueue(stacksQue);

            break;

        } // case 1

        case 2:
        {
            try
            {
                stacksQue->Dequeue();
            }
            catch (std::out_of_range)
            {
                std::cout << "empty" << std::endl;
            }

            std::cout << "Текущая очередь." << std::endl;
            PrintStacksQueue(stacksQue);

            break;

        } // case 2

        default: 
        {
            std::cout << "Выберете команду. " << std::endl;
        } // default

        } // switch

    } // while true

}

int main()
{
    setlocale(LC_ALL, "ru");


    while (true)
    {
        int structChoice;
        std::cout << "Выберете структуру: " << std::endl;
        std::cout << "\n0. Выйти.\
            \n1. Стек.\
		    \n2. Кольцевой буфер.\
			\n3. Очередь на базе кольцевого буфера.\
			\n4. Очередь на базе двух стеков." <<std::endl;
        std::cin >> structChoice;

        switch (structChoice)
        {
        case 0:
        {
            return;
        }

        case 1:
        {
            StackMenu();
            break;
        }

        case 2:
        {
            RingMenu();
            break;
        }

        case 3:
        {
            RingQueueMenu();
            break;
        }

        case 4:
        {
            StacksQueueMenu();
            break;
        }

        default:
        {
            std::cout << "Выберите команду: " << std::endl;
        }

        }

    }

    return 0;
}
