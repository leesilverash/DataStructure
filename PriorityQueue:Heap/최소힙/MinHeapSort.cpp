#include <cstdlib>
#include "MinHeap.h"

void display(int data[], int size, char* msg){
    printf("%s = ", msg);
    for(int i = 0 ; i < size; i++){
        printf("%d  ", data[i]);
    }
    printf("\n");
}
int main(){
    MinHeap heap;
    int size = 10;
    int data[size];

    for(int i = 0 ; i < 10 ; i++){
        data[i] = rand() % 100;
    }
    display(data, size, "정렬 전: ");
    heap.heapSort(data, 10);
    display(data, size, "정렬 후: ");
}