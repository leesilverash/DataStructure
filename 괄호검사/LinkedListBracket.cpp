#include <cstdio>  //exit함수를 쓰기위한 헤더
#include <cstring> //strlen 함수를 쓰기위한 헤더
#include <cstdlib> //객체에 메모리를 할당하여 주는 헤더


//typedef int element;
typedef char element;
typedef struct StackNode
{                           //스택노드 구조체 정의
    element item;           //아이템 변수
    struct StackNode *link; //이 구조체의 주소
} StackNode;                //이 구조체를 StackNode라 부르자

typedef struct
{                   //이 구조체를 LinkedStackType이라 부르고
    StackNode *top; //top은 스택노드의 포인터값을 가진다.
} LinkedStackType;

//초기화
void init(LinkedStackType *s) //LinkedStackType변수가 가리키는곳의 값 s(s는 곳 StackNode)
{
    s->top = NULL; //s의 탑값이 널이면 이 스택은 비어있다.
}

// 공백 상태 검출 함수
int is_empty(LinkedStackType *s)
{
    return (s->top == NULL);
}

// 포화 상태 검출 함수
int is_full(LinkedStackType *s) //연결리스트 스택은 제한이 없으므로 항상 0값을 가진다.
{
    return 0; //return 0 하면 항상 0
}
//삽입함수
void push(LinkedStackType *s, element item) //StackNode s와 넣을 data값
{
    StackNode *temp = (StackNode *)malloc(sizeof(StackNode)); //StackNode의 메모리 할당하여 *temp에 대입
    if (temp == NULL)
    {                                          //temp값이 비어있다는 것은 메모리를 할당하지 못한 것임
        fprintf(stderr, "메모리 할당 에러\n"); // 에러 출럭
        return;
    }
    else
    {
        temp->item = item; // 메모리 할당이 되었다면 temp가 가리키는 곳(할당된 메모리자리)의
        // item변수값에 지금item값을 대입
        temp->link = s->top; // 할당된 메모리자리의 link에 StackNode의 top값을 대입
        s->top = temp;       // top에다 할당된 메모리값을 넣는다.(초기 탑은 NULL)
    }
}
//삭제함수
element pop(LinkedStackType *s) //s는 StackNode를 가리킴
{
    if (is_empty(s))
    {                                         //top이 null이면 삭제하지 못하므로 is_empty가 1라면으로 대체
        fprintf(stderr, "스택이 비어있음\n"); //에러 메시지 출력
        exit(1);                              //비정상 프로그램 종료
    }
    else
    {
        StackNode *temp = s->top;  //할당된 메모리 자리에 StackNode의 top값을 대입
        element item = temp->item; //할당된 메모리 자리의 item값을 현재의 item에 대입
        s->top = s->top->link;     // StackNode의 top은
        free(temp);
        return item;
    }
}
//피크함수
element peek(LinkedStackType *s)
{
    if (is_empty(s))
    {
        fprintf(stderr, "스택이 비어있음\n");
        exit(1);
    }
    else
    {
        return s->top->item;
    }
}
//-----------------------------------------------------------------------------------------------
//괄호 검사 함수
int check_matching(const char *in)
{
    LinkedStackType s;
    char ch;
    char open_ch;
    int i, n = strlen(in); // n= 문자열의 길이
    init(&s);              // 스택의 초기화
    printf("=====================================");
    printf("\n입력하신 문자열은 %s 입니다.\n", in);

    for (i = 0; i < n; i++)
    {
        ch = in[i];
        switch (ch)
        {
        case '(':
        case '[':
        case '{':
            push(&s, ch);
            printf(" '%c' 이(가) 스택에 저장되었습니다.\n", peek(&s));
            break;
        case ')':
        case ']':
        case '}':
            if (is_empty(&s))
                return 0;
            else
            {
                open_ch = pop(&s);
                printf(" '%c'와 '%c' 을(를) 비교합니다.\n", open_ch, in[i]);
                if ((open_ch == '(' && ch != ')') ||
                    (open_ch == '[' && ch != ']') ||
                    (open_ch == '{' && ch != '}'))
                {
                    printf(" 괄호의 순서가 맞지 않습니다.\n");
                    return 0;
                }
                break;
            }
        }
    }
    if (!is_empty(&s))
    {
        printf(" 괄호가 아직 남아있습니다.");
        return 0; //스택에 남아있다면 오류
    }
    return 1;
}
//

int main()
{
    LinkedStackType s;
    init(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", is_empty(&s));

    if (check_matching("{A[(i+1)]=0}") == 1)
        printf("\n\t괄호검사성공\n");
    else
        printf("\n\t괄호검사실패\n");

    if (check_matching("if((!==0)&&(j==0)") == 1)
        printf("\n\t괄호검사성공\n");
    else
        printf("\n\t괄호검사실패\n");

    if (check_matching("A[(i+1])=0;") == 1)
        printf("\n\t괄호검사성공\n");
    else
        printf("\n\t괄호검사실패\n");

    if (check_matching("a(b)c)") == 1)
        printf("\n\t괄호검사성공\n");
    else
        printf("\n\t괄호검사실패\n");
    if (check_matching("a(b{c)d}") == 1)
        printf("\n\t괄호검사성공\n");
    else
        printf("\n\t괄호검사실패\n");
}
