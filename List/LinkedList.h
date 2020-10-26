#include "Node.h"

class LinkedList
{
    Node org; //헤드 노드
public:
    LinkedList() : org(0) {} //생성자
    ~LinkedList() { clear(); }

    Node *getHead() { return org.getLink(); }
    bool isEmpty() { return getHead() == NULL; }

    void clear()
    {
        while (!isEmpty())
        {
            delete remove(0);
        }
    }

    Node* getEntry(int pos){
        Node* n = &org;
        for(int i =  -1; i < pos; i++, n=n->getLink())
        {
            if(n==NULL) break;
        }
        return n;
    }

    void insert(int pos, Node *n){
        Node* prev = getEntry(pos-1);
        if(prev != NULL){
            prev->insertNext(n);
        }
    }
    
    void replace(int pos, Node* n){
        Node*prev = getEntry(pos-1);
        if(prev != NULL){
            prev->removeNext();
            prev->insertNext(n);
        }
    }

    Node* remove(int pos){
        Node* prev = getEntry(pos-1);
        return prev -> removeNext();
    }

    int size(){
        int count = 0;
        for(Node *p = getHead(); p!= NULL; p = p->getLink()){
            count++;
        }
        return count;
    }

    void display(){
        printf( "[단순연결리스트 항목 수 = %2d] : ", size());
        for( Node *p = getHead() ; p != NULL; p = p-> getLink()){
            p->display();
        }
        printf("\n");
    }
};
