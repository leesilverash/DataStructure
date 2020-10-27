#include <cstdio>

class Node2
{
    Node2 *prev;
    Node2 *next;
    int data;

public:
    Node2(int val = 0) : data(val), prev(NULL), next(NULL) {}
    Node2 *getPrev() { return prev; }
    Node2 *getNext() { return next; }
    void setPrev(Node2 *p) { prev = p; }
    void setNext(Node2 *n) { next = n; }
    void display() { printf(" <%2d>", data); }
    bool hasData(int val) { return data == val; }

    void insertNext(Node2 *n)
    {
        if (n != NULL)
        {
            n->prev = this;
            n->next = next;
            if (next != NULL)
                next->prev = n;
            next = n;
        }
    }
    Node2 *remove()
    {
        if (prev != NULL)
            prev->next = next;
        if (next != NULL)
            next->prev = prev;
        return this;
    }
};