#include <iostream>
#include "C:\Users\User\source\repos\DataStructures\Lab_2\Header Files\Node.h"

int Data;
Node* Next;
Node* Prev;

Node::Node(int value) : Data(value), Next(nullptr), Prev(nullptr) {}
