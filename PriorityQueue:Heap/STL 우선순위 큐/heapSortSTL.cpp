#include <queue>
#include <functional> //최소 힙을 사용하기 위해 필요하다

using namespace std;

void heapSortDec(int a[], int n)
{
    priority_queue<int> MinHeap;

    for (int i = 0; i < n; i++)
    {
        MinHeap.push(a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = MinHeap.top();
        printf("%d ", a[i]);
        MinHeap.pop();
    }
    printf("\n");
}

void heapSortInc(int a[], int n)
{
    priority_queue<int, vector<int>, greater<int> > minHeap;
    for (int i = 0; i < n; i++)
    {
        minHeap.push(a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = minHeap.top();
        printf("%d ", a[i]);
        minHeap.pop();
    }
    printf("\n");
}

int main()
{
    int size = 10;
    int arr[10] = {7, 9, 10, 2, 6, 4, 3, 5, 1, 8};
    printf("내림차순 정렬: ");
    heapSortDec(arr, size);
    printf("오름차순 정렬: ");
    heapSortInc(arr, size);
}