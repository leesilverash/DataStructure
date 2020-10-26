#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int를 스택 element의 자료형으로 정의
typedef int element;

typedef struct stackNode
{
    element data;
    struct stackNode *link;
} stackNode;

stackNode *top;

//연결 리스트 스택의 삽입 연산
void push(element item)
{
    stackNode *temp = (stackNode *)malloc(sizeof(stackNode));
    temp->data = item;
    temp->link = top;
    top = temp;
}

//연결 리스트 스택의 삭제 후 반환 연산
element pop()
{
    element item;
    stackNode *temp = top;

    if (top == NULL)
    {
        printf("\n\n Stack is empty !\n");
        return 0;
    }
    else
    {
        item = temp->data;
        top = temp->link;
        free(temp);
        return item;
    }
}

//연결 리스트 스택의 top 원소 검색 연산
element peek()
{
    element item;
    if (top == NULL)
    {
        printf("\n\n Stack is empty !\n");
        return 0;
    }
    else
    {
        item = top->data;
        return item;
    }
}

//연결 리스트 스택의 삭제 연산
void del()
{
    stackNode *temp;
    if (top == NULL)
    {
        printf("\n\n Stack is empty !\n");
    }
    else
    {
        temp = top;
        top = top->link;
        free(temp);
    }
}

//연결 리스트 스택의 출력 연산
void printStack()
{
    stackNode *p = top;
    printf("\n STACK [ ");
    while (p)
    {
        printf("%d", p->data);
        p = p->link;
    }
    printf("] ");
}

//후위 표기법을 계산하는 연산
element evalPostfix(char *exp)
{
    int opr1, opr2, value, i = 0;
    //문자열 길이 가져옴
    int length = strlen(exp);
    //받을 문자열
    char symbol;
    //top 초기화
    top = NULL;

    //문자열길이 만큼 반복
    for (i = 0; i < length; i++)
    {
        symbol = exp[i];

        //피연산자면
        if (symbol != '+' && symbol != '-' && symbol != '*' && symbol != '/')
        {
            //문자열이 이므로 계산이 불가하므로 '0'=ASCII로 만들어줌(ex: 51(0)-48(3)= 3)
            value = symbol - '0';
            push(value);
        }
        //연산자면
        else
        {
            opr2 = pop();
            opr1 = pop();
            switch (symbol)
            {
            case '+':
                push(opr1 + opr2);
                break;
            case '-':
                push(opr1 - opr2);
                break;
            case '*':
                push(opr1 * opr2);
                break;
            case '/':
                push(opr1 / opr2);
                break;
            }
        }
    }
    return pop();
}

int main(void)
{
    int result;
    char *express = "35*62/-";

    printf("후위표기식 : %s", express);

    result = evalPostfix(express);
    printf("\n\n 연산결과 => %d", result);

    getchar();
}

