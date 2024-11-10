#include "function.h"


int main(){
    int n;
    double *A, *B, *X;
    scanf("%d", &n);
    A = (double*)malloc(n * n * sizeof(double));
    B = (double*)malloc(n * sizeof(double));
    X = (double*)malloc(n * sizeof(double));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%lf", A + i * n + j);
        }
    }
    

    for(int i = 0; i < n; i++){
        scanf("%lf", B + i);
    }

    solve(A, B, X, n);

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         A[i * n + j] /= sqrt(5);
    //     }
    //     B[i] /= sqrt(5);
    // }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%10.3e ", A[i * n + j]);
        }
        printf("%10.3e", B[i]);
        printf("\n");
    }
    printf("hello");

    free(A);
    free(B);
    free(X);
    return 0;
}