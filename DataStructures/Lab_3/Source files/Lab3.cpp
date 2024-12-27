#include <iostream>
#include "..\Header Files\Stack.h"
#include "..\Header Files\RingBuffer.h"
#include "..\Header Files\Queue.h"
#include "..\Header Files\QueueStacks.h"

#include <string>

// TODO: Комментарий
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

// TODO: Сделать единообразные комментарии, как в .h файлах
// Вывод стека.
void PrintStack(Stack* stack)
{
    for (int i = 0; i < stack->GetSize(); ++i)
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
        std::cout << ringQue->Buffer->Buffer[i] << " ";
    }
    std::cout << std::endl;
}

// Вывод очереди на стеках
void PrintStacksQueue(QueueStacks* stacksQue)
{
    int* data = stacksQue->GetData();
    for (int i = 0; i < stacksQue->GetSize(); i++)
    {
        std::cout << data[i] << " ";
    }

    std::cout << std::endl;
}

// \!brief Для работы со стеком
void StackMenu(Stack* stack)
{
    while (true)
    {
        std::cout << "Текущий стек: " << std::endl;
        PrintStack(stack);
        std::cout << "Выберете действие: " << std::endl;
        std::cout << "\n0. Выйти и удалить стeк.\
            \n1.Добавить элемент.\
		    \n2. Удалить элемент. " << std::endl;
        int stackOption = CheckInput();

        switch (stackOption)
        {

        case 0:
        {
            delete stack;
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
void RingMenu(RingBuffer* cb) 
{
    while (true)
    {
        std::cout << "Текущий кольцевой буфер: " << std::endl;
        PrintRing(cb);
        std::cout << "Выберете действие: " << std::endl;
        std::cout << "\n0. Выйти и удалить текущий кольцевой буфер.\
            \n1. Добавить элемент.\
		    \n2. Удалить элемент.\
            \n3. Получить свободное место. \
            \n4. Получить занятое место. \ " << std::endl;

        int RingItem = CheckInput();

        switch (RingItem)
        {

        case 0:
        {
            delete cb;
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

            break;
        } // case 2

        case 3:
        {
            std::cout << "Свободное место: ";
            std::cout << cb->FreeSpace() << std::endl;
            break;
        } // case 3

        case 4:
        {
            std::cout << "Занятое место: ";
            std::cout << cb->OccupiedSpace() << std::endl;
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
void RingQueueMenu(Queue* ringQue)
{
    while (true)
    {
        std::cout << "Текущая очередь." << std::endl;
        PrintQueue(ringQue);

        std::cout << "Выберете действие: " << std::endl;
        std::cout << "\n0. Выйти и удалить очередь. \
            \n1. Добавить элемент.\
		    \n2. Удалить элемент. " << std::endl;

        int QueueChoice;
        std::cin >> QueueChoice;

        switch (QueueChoice)
        {

        case 0:
        {
            delete ringQue;
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

            break;
        } // case 2

        default:
        {
            std::cout << "Выберете команду.." << std::endl;
        } // default

        } // switch
    } // while true
}

// Для работы с очередью на стеках.
void StacksQueueMenu(QueueStacks* stacksQue)
{
    while (true)
    {
        std::cout << "Текущая очередь." << std::endl;
        PrintStacksQueue(stacksQue);
        std::cout << "Выберете действие: " << std::endl;
        std::cout << "\n0. Удалить очередь и выйти. \
            \n1. Добавить элемент.\
		    \n2. Удалить элемент. " << std::endl;
        int SQueueChoice = CheckInput();
        switch (SQueueChoice)
        {

        case 0:
        {
            delete stacksQue;
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

            break;

        } // case 1

        case 2:
        {
            try
            {
                std::cout << stacksQue->Dequeue() << std::endl;
            }
            catch (std::out_of_range)
            {
                std::cout << "empty" << std::endl;
            }

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

    int structChoice;

    do
    {
        std::cout << "Выберете структуру: " << std::endl;
        std::cout << "\n0. Выйти.\
            \n1. Стек.\
		    \n2. Кольцевой буфер.\
			\n3. Очередь на базе кольцевого буфера.\
			\n4. Очередь на базе двух стеков." <<std::endl;
        structChoice = CheckInput();

        switch (structChoice)
        {
        case 0:
        {
            break;
        }

        case 1:
        {
            Stack* stack = new Stack(8);
            StackMenu(stack);
            break;
        }

        case 2:
        {
            RingBuffer* cb = new RingBuffer(8);
            RingMenu(cb);
            break;
        }

        case 3:
        {
            Queue* ringQue = new Queue(8);
            RingQueueMenu(ringQue);
            break;
        }

        case 4:
        {
            QueueStacks* stacksQue = new QueueStacks(8);
            StacksQueueMenu(stacksQue);
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
