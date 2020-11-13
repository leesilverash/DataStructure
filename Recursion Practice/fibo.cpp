#include <cstdio>

int fibonacci(int *count, int n)
{
    count[n]++;
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return (fibonacci(count, n - 1) + fibonacci(count, n - 2));
}

int main(void)
{
    int num;
    printf("피보나치 수열 입력: ");
    scanf("%d", &num);
    int *count = new int[num + 1];
    for (int i = 0; i < num + 1; i++)
        count[i] = 0;
    fibonacci(count, num);
    for (int i = num; i >= 0; i--)
        printf("Fibo(%d) = count[%d]번\n", i, count[i]);
    delete[] count;
    return 0;
}
