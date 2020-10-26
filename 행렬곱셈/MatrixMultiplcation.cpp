#include <iostream>

using namespace std;

int** Create_Matrix(int row, int column){
    int **arr = new int* [row];
    
    for(int i=0; i<row; i++){
        arr[i] = new int [column];
    }
    
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            arr[i][j] = random()%10;
        }
    }
    return arr;
}

void Display_Matrix(int **arr, int row, int col){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<< arr[i][j] << " ";
        }
        cout << "\n";
    }
}

int** Multiplication_Matrix(int** matA, int** matB, int** matC, int row_a, int col_a, int col_b){
    
    matC = new int* [row_a];
    
    for(int i=0; i<row_a; i++){
        matC[i] = new int [col_b];
    }
    
    for(int i=0; i<row_a; i++){
        for(int j=0; j<col_b; j++){
            for(int k=0; k<col_a; k++){
                matC[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
    
    return matC;
}

int main(void){
    int row_a, col_a, row_b, col_b;
    
    while(1){
        cout << "행렬 A의 row와 column을 입력하세요.\n";
        cin >> row_a >> col_a;
        
        cout << "행렬 B의 row와 column을 입력하세요.\n";
        cin >> row_b >> col_b;
        
        if(col_a == row_b){
            break;
        }
        else{
            cout << "행렬곱의 정의에 어긋납니다~~\n";
        }
    }
    
    int **matA = Create_Matrix(row_a, col_a);
    int **matB = Create_Matrix(row_b, col_b);

    cout << "\n행렬 A =\n";
    Display_Matrix(matA, row_a, col_a);
    cout << "\n행렬 B =\n";
    Display_Matrix(matB, row_b, col_b);
    
    int **matC = Multiplication_Matrix(matA, matB, matC, row_a, col_a, col_b);
    
    cout << "\nA*B =\n";
    Display_Matrix(matC, row_a, col_b);
    return 0;
}