#include <cstdio>
int recur (int n){
    if(n==1){
        return n;
    }
    else return (n + recur(n-1));
}
double recur1(int n){
    if(n == 1){
        return 1.0;
    }
    else return (1.0/n + recur1(n-1));
}

int main(){
    printf("%d\n", recur(5));
    printf("%f\n", recur1(5));
}