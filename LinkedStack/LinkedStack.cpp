#include "LinkedStack.h"
#include <cstdlib>

int main()
{
    LinkedStack stack;
    for (int i = 1; i < 10; i++)
    {
        stack.push(new Node(i));
    }
    stack.display();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.display();
}
