#include <cstdio>
#define MAX_LIST_SIZE 100

class ArrayList
{
    int data[MAX_LIST_SIZE]; // 실제로 항목 값들이 들어감.
    int length;              // 현재 리스트 내의 항목들의 개수
public:
    ArrayList(void) { length = 0; } // 생성자

    void insert(int pos, int e)
    {
        if (!isFull() && pos >= 0 && pos <= length)
        {
            for (int i = length; i > pos; i--)
            {
                data[i] = data[i - 1];
            }
            data[pos] = e;
            length++;
        }
        else
            printf("포화상태 오류 또는 삽입 위치 오류");
    }

    void remove(int pos)
    {
        if (!isEmpty() && 0 <= pos && pos < length)
        {
            for (int i = pos + 1; i < length; i++)
            {
                data[i - 1] = data[i];
            }
            length--;
        }
        else
            printf("공백상태 오류 또는 삭제 위치 오류");
    }

    int getEntry(int pos) { return data[pos]; }       // pos번째 항목 반환
    bool isEmpty() { return length == 0; }            // 공백 상태 검사
    bool isFull() { return length == MAX_LIST_SIZE; } // 포화 상태 검사
    bool find(int item)
    {
        for (int i = 0; i < length; i++)
        {
            if (data[i] == item)
            {
                return true;
            }
        }
        return false;
    }

    void replace(int pos, int e)
    {
        data[pos] = e;
    }

    int size() { return length; }

    void display()
    {
        printf(" [배열로구현한리스트 전체 항목수 = %2d] : ", size());
        for (int i = 0; i < size(); i++)
        {
            printf("[%2d] ", data[i]);
        }
        printf("\n");
    }
    void clear() { length = 0; }
};