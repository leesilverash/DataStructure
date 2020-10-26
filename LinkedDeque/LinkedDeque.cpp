#include <cstdio>
#include <cstdlib>

//char형을 덱 element의 자료형으로 정의
typedef int element;
//이중 연결 리스트 덱의 노드 구조를 구조체로 정의
typedef struct DQNode
{
    element data;
    struct DQNode *llink;
    struct DQNode *rlink;
} DQNode;

//덱에서 사용하는 포인터 front와 rear를 구조체로 정의
typedef struct
{
    DQNode *front, *rear;
} DQueType;

//공백 덱을 생성하는 연산
DQueType *createDQue()
{
    DQueType *DQ;
    DQ = (DQueType *)malloc(sizeof(DQueType));
    DQ->front = NULL;
    DQ->rear = NULL;
    return DQ;
}

//덱이 공백인지 확인하는 연산
int isEmpty(DQueType *DQ)
{
    if (DQ->front == NULL)
    {
        printf("\n Linked Queue is empty! \n");
        return 1;
    }
    else
        return 0;
}


void insertFront(DQueType *DQ, element item)
{
    DQNode *newNode = (DQNode *)malloc(sizeof(DQNode));
    newNode->data = item;
    if (DQ->front == NULL)
    {
        DQ->front = newNode;
        DQ->rear = newNode;
        newNode->rlink = NULL;
        newNode->llink = NULL;
    }
    else
    {
        DQ->front->llink = newNode;
        newNode->rlink = DQ->front;
        newNode->llink = NULL;
        DQ->front = newNode;
    }
}

void insertRear(DQueType *DQ, element item)
{
    DQNode *newNode = (DQNode *)malloc(sizeof(DQNode));
    newNode->data = item;
    if (DQ->rear == NULL)
    {
        DQ->front = newNode;
        DQ->rear = newNode;
        newNode->rlink = NULL;
        newNode->llink = NULL;
    }
    else
    {
        DQ->rear->rlink = newNode;
        newNode->rlink = NULL;
        newNode->llink = DQ->rear;
        DQ->rear = newNode;
    }
}

element deleteFront(DQueType *DQ)
{
    DQNode *old = DQ->front;
    element item;
    if (isEmpty(DQ))
        return 0;
    else
    {
        item = old->data;
        if (DQ->front->rlink == NULL)
        {
            DQ->front = NULL;
            DQ->rear = NULL;
        }
        else
        {
            DQ->front = DQ->front->rlink;
            DQ->front->llink = NULL;
        }
        free(old);
        return item;
    }
}

//덱의 rear 노드를 삭제하고 반환하는 연산
element deleteRear(DQueType *DQ)
{
    DQNode *old = DQ->rear;
    element item;
    if (isEmpty(DQ))
        return 0;
    else
    {
        item = old->data;
        if (DQ->rear->llink == NULL)
        {
            DQ->front = NULL;
            DQ->rear = NULL;
        }
        else
        {
            DQ->rear = DQ->rear->llink;
            DQ->rear->rlink = NULL;
        }
        free(old);
        return item;
    }
}

//덱의 front 노드를 삭제하는 연산
int removeFront(DQueType *DQ)
{
    DQNode *old = DQ->front;
    if (isEmpty(DQ))
        return 0;
    else if (DQ->front->rlink == NULL)
    {
        DQ->front = NULL;
        DQ->rear = NULL;
    }
    else
    {
        DQ->front = DQ->front->rlink;
        DQ->front->llink = NULL;
    }
    free(old);
    return 1;
}

//덱의 front 노드의 데이터 필드를 반환하는 연산
element peekFront(DQueType *DQ)
{
    element item;
    if (isEmpty(DQ))
        return 0;
    else
    {
        item = DQ->front->data;
        return item;
    }
}

//덱의 rear 노드를 삭제하는 연산
int removeRear(DQueType *DQ)
{
    element item;
    if (isEmpty(DQ))
        return 0;
    else
    {
        item = DQ->front->data;
        return item;
    }
}

//덱의 rear 노드의 데이터 필드를 반환하는 연산
element peekRear(DQueType *DQ)
{
    element item;
    if (isEmpty(DQ))
        return 0;
    else
    {
        item = DQ->rear->data;
        return item;
    }
}

//덱의 front 노드부터 rear 노드까지 출력하는 연산
void printDQ(DQueType *DQ)
{
    DQNode *temp = DQ->front;
    printf("DeQue : [");
    while (temp)
    {
        printf("%3d", temp->data);
        temp = temp->rlink;
    }
    printf(" ] \n");
}

int main(void)
{
    DQueType *DQ1 = createDQue();
    element data;
    printf("front 삽입 1>> ");
    insertFront(DQ1, 1);
    printDQ(DQ1);
    printf("front 삽입 2>> ");
    insertFront(DQ1, 2);
    printDQ(DQ1);
    printf("rear 삽입 3>> ");
    insertRear(DQ1, 3);
    printDQ(DQ1);
    printf("front 삭제 >> ");
    deleteFront(DQ1);
    printDQ(DQ1);
    printf("rear 삭제 >> ");
    deleteRear(DQ1);
    printDQ(DQ1);
    printf("rear 삽입 4>> ");
    insertRear(DQ1, 4);
    printDQ(DQ1);
    printf("front 삽입 5>> ");
    insertFront(DQ1, 5);
    printDQ(DQ1);
    printf("front 삽입 6>> ");
    insertFront(DQ1, 6);
    printDQ(DQ1);

    data = peekFront(DQ1);
    printf("peek Front item : %d \n", data);
    data = peekRear(DQ1);
    printf("peek Rear item : %d \n", data);
}
