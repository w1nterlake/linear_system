#include "function.h"


int main(){
    printf("enter\n");
    int n;
    double *A, *B;
    scanf("%d", &n);
    A = (double*) malloc(n * n * sizeof(double));
    B = (double*)malloc(n * sizeof(double));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%lf", A + i * n + j);
        }
    }

    for(int i = 0; i < n; i++){
        scanf("%lf", B + i);
    }


    solve_1(A, B, n);

    printf("\n");


    print_matrix(A, n);
    
    free(A);
    free(B);
    return 0;
}