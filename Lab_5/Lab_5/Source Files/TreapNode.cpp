#include "../Header Files/TreapNode.h"
#include <iostream>

TreapNode::TreapNode(int k) : Key(k), Priority(rand()), Left(nullptr), Right(nullptr) {}