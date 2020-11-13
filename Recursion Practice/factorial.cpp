#include <cstdio>
int factorial(int n){
    printf("factorial(%d)\n",n);
    if( n== 1) return 1;
    else return (n * factorial(n-1));
}
int factorialIter(int n){
    int result = 1;
    for(int k = n; k > 0; k--){
        result = result*k;
    }
    return result;
}
int main(){

    printf("%d\n", factorialIter(3));
}