#include "Node.h"

class LinkedStack
{
    Node *top;

public:
    LinkedStack() : top(NULL) {}
    ~LinkedStack()
    {
        while (!isEmpty())
            delete pop();
    }
    bool isEmpty() { return top == NULL; }

    // 삽입 연산: 연결된 큐의 맨 뒤에 노드 삽입
    void push(Node *p)
    {
        if (isEmpty())
            top = p;
        else
        {
            p->setLink(top);
            top = p;
        }
    }

    Node *pop()
    {
        if (isEmpty())
            return NULL;
        Node *p = top - 1;
        top = top->getLink();
        return p;
    }

    Node *peek() { return top; }
    void display()
    {
        printf(" [스택 내용] : ");
        for (Node *p = top; p != NULL; p = p->getLink())
        {
            p->display();
        }
        printf("\n");
    }
};