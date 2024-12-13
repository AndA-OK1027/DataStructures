#include <iostream>
#include "..\Header Files\Node.h"

int Data;
Node* Next;
Node* Prev;

Node::Node(int value) : Data(value), Next(nullptr), Prev(nullptr) {}
