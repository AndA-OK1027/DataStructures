#include <iostream>
#include "..\Header Files\Stack.h"
#include "..\Header Files\RingBuffer.h"
#include "..\Header Files\Queue.h"
#include "..\Header Files\QueueStacks.h"

void PrintStack(Stack* stack)
{
    for (int i = 0; i < stack->GetSize(); i++)
    {
        std::cout << stack->Data[i] << " ";
    }
    std::cout << std::endl;
}

void PrintRing(RingBuffer* cb)
{
    for (int i = 0; i < cb->Tail; i++)
    {
        std::cout << cb->Buffer[i] << " ";
    }
    std::cout << std::endl;
}

void PrintQueue(Queue* qu)
{
    for (int i = 0; i < qu->GetSize(); i++)
    {
        std::cout << qu->Buffer->Buffer[i] << std::endl;
    }
}

void PrintStacksQueue(QueueStacks* quu)
{
    for (int i = 0; i < quu->Stack1->GetSize(); i++)
    {
        PrintStack(quu->Stack1);
    }
}

int main()
{
    setlocale(LC_ALL, "ru");

    Stack* stack = new Stack(2);
    stack->Push(77);
    stack->Push(13);
    stack->Push(8);

    RingBuffer* cb = new RingBuffer(6);
    cb->Add(67);
    cb->Add(7777);
    
    Queue* qu = new Queue(5);
    qu->Enqueue(7);
    qu->Enqueue(88);
    qu->Enqueue(9);
    //PrintQueue(qu);

    QueueStacks* quu = new QueueStacks(4);
    quu->Enqueue(8);
    quu->Enqueue(9);
    quu->Enqueue(77);
    //PrintStacksQueue(quu);

    while (true)
    {
        int structChoice;
        std::cout << "Выберете структуру: " << std::endl;
        std::cout << "\n1. Стек.\
		    \n2. Кольцевой буфер.\
			\n3. Очередь на базе кольцевого буфера.\
			\n4. Очередь на базе двух стеков." <<std::endl;
        std::cin >> structChoice;

        switch (structChoice)
        {
        case 1:
            std::cout << "Текущий стек: " << std::endl;
            PrintStack(stack);
            int stackOption;
            std::cout << "Выберете действие: " << std::endl;
            std::cout << "\n1. Добавить элемент.\
		    \n2. Удалить элемент. " << std::endl;
            std::cin >> stackOption;
            switch (stackOption)
            {
            case 1:
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
            case 2:
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
            default:
                break;
            }
            break;

        case 2:
            std::cout << "Текущий кольцевой буфер: " << std::endl;
            PrintRing(cb);
            std::cout << "Выберете действие: " << std::endl;
            std::cout << "\n1. Добавить элемент.\
		    \n2. Удалить элемент.\
            \n3. Получить свободное место. \
            \n4. Получить занятое место. \ " << std::endl;
            int RingItem;
            std::cin >> RingItem;
            switch (RingItem)
            {
            case 1:
                int AddValue;
                std::cin >> AddValue;
                try
                {
                    cb->Add(AddValue);
                }
                catch (std::out_of_range)
                {
                    std::cout << "Буфер переполнен. " << std::endl;
                }
                PrintRing(cb);

                break;
            case 2:
                try
                {
                    cb->Remove();
                }
                catch (std::out_of_range)
                {
                    std::cout << "Буфер пуст. " << std::endl;
                }
                PrintRing(cb);

                break;
            case 3:
                std::cout << cb->FreeSpace();
                break;
            case 4:
                std::cout << cb->OccupiedSpace();
                break;
            default:
                break;
            }
            break;

        case 3:
            std::cout << "Текущая очередь." << std::endl;
            PrintQueue(qu);
            std::cout << "Выберете действие: " << std::endl;
            std::cout << "\n1. Добавить элемент.\
		    \n2. Удалить элемент. " << std::endl;
            int QueueChoice;
            std::cin >> QueueChoice;
            switch (QueueChoice)
            {
            case 1:
                std::cout << "Введите элемент:" << std::endl;
                int QueueValue;
                std::cin >> QueueValue;
                try
                {
                    qu->Enqueue(QueueValue);
                }
                catch (std::out_of_range)
                {
                    std::cout << "Невозможно добавить" << std::endl;
                }
                PrintQueue(qu);
                break;

            case 2:
                try
                {
                    qu->Dequeue();
                }
                catch (std::out_of_range)
                {
                    std::cout << "empty" << std::endl;
                }
                PrintQueue(qu);
                break;

            default:
                break;
            }
            break;

        case 4:
            std::cout << "Текущая очередь." << std::endl;
            PrintStacksQueue(quu);
            std::cout << "Выберете действие: " << std::endl;
            std::cout << "\n1. Добавить элемент.\
		    \n2. Удалить элемент. " << std::endl;
            int SQueueChoice;
            std::cin >> SQueueChoice;
            switch (SQueueChoice)
            {
            case 1:

                std::cout << "Введите элемент:" << std::endl;
                int AddValue;
                std::cin >> AddValue;
                try
                {
                    quu->Enqueue(AddValue);
                }
                catch (std::out_of_range)
                {
                    std::cout << "Невозможно добавить" << std::endl;
                }
                PrintStacksQueue(quu);
                break;

            case 2:
                try
                {
                    quu->Dequeue();
                }
                catch (std::out_of_range)
                {
                    std::cout << "empty" << std::endl;
                }
                PrintStacksQueue(quu);
                break;
            }
            break;
        default:
            std::cout << "Выберите команду: " << std::endl;
            break;
        }
    }

    return 0;
}
