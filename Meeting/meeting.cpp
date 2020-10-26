#include "CircularStudent.h"
#include <cstdio>

    int main(void){
    CircularStudent male, female; //남자 여자
    char name[20];
    char gender; //성별
    printf("미팅 주선 프로그램입니다\n");
    printf("프로그램 종료 원하시면 이름에 '그만'을 입력해주세요\n");

    while(true)
    {
        printf("고객이름: ");
        scanf("%s",&name);

        if (!strcmp(name, "그만"))
            break;

        printf("성별을 입력하세요(f or m)");
        scanf("%s",&gender);

        if (gender == 'm')

            male.enqueue(name);

        else if (gender == 'f')

            female.enqueue(name);

        if (!male.isEmpty() && !female.isEmpty()) //여자 남자 한쌍을 이룰 경우
        {
            char boyfriend[20], girlfriend[20];
            strcpy(boyfriend, male.dequeue());
            strcpy(girlfriend, female.dequeue());

            printf("커플이 탄생했습니다. %s와 %s\n", boyfriend,girlfriend); 
        }
        else
            printf("아직 대상자가 없습니다. 기다려주십시요.\n");
    }
    return 0;
}
