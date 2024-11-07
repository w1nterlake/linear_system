#include "function.h"


void print_matrix(double *A, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%10.3e ", A[i * n + j]);
        }
    }
}

void f0(double *A, int n, char *filename, int *err){
    int count = 0;
    FILE *fin = fopen(filename, "r");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(fscanf(fin, "%lf", (A + i*n + j)) == 1){
                count++;
            }   
        }
    }
    if(count == n*n){
        *err = 4;
    }
    fclose(fin);
}

void f1(double *A, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            A[i * n + j] = n + 1 - MAX(i, j);
        }
    }
}

void f2(double *A, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            A[i * n + j] = MAX(i, j);
        }
    }
}

void f3(double *A, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            A[i * n + j] = abc(i - j);
        }
    }
}

void f4(double *A, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            A[i * n + j] = 1/(i + j - 1);
        }
    }
}

void fill(double *A, int n, char *filename, int s, int *err){
    switch(s){
        case 0:
            f0(A, n, filename, err);
            break;
        case 1:
            f1(A, n);
            break;
        case 2:
            f2(A, n);
            break;
        case 3:
            f3(A, n);
            break;
        case 4:
            f4(A, n);
            break;
        default:
            break;
    }
}

void fill_right_part(double *A, double *B, int n){
    for(int i = 0; i < n; i ++){
        B[i] = 0;
        for(int j = 0; j < n; j += 2){
            B[i] += A[i * n + j];
        }
    }
}

double norm(double *X, int n){
    double max = 0;
    for(int i = 0; i < n; i++){
        max += fabs(X[i]);
    }
    return max;
}

double discrepancy_1(double *A, double *B, double *X, int n){
    double sum1 = 0, sum2 = 0;
    double num = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            num += A[i * n + j] * X[j];
        }
        sum1 += fabs(num - B[i]);
        sum2 += fabs(B[i]);
    }
    return sum1/sum2;
}

double discrepancy_2(double *X, int n){
    double sum1 = 0, sum2 = 0;
    for(int i = 0; i < n; i++){
        sum1 += fabs(X[i] - (i + 1)%2);
        sum2 += (i + 1) % 2;
    }
    return sum1/sum2;
}

void print_matrix(double *A, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%10.3e ", A[i * n + j]);
        }
        printf("\n");
    }
}

void multiply(double *A, double *C, int n){
    double *X = (double*)malloc(n * sizeof(double));
    double sum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                sum += A[i * n + k] * C[k * n + j];
            }
            X[j] = sum;
            sum = 0;
        }
        for(int l = 0; l < n; l++){
            C[l * n + i] = X[l];
        }
    }
    free(X);
}

int scalar(double *X, double *Y, int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += X[i] * Y[i];
    }
    return sum;
}

void solve_1(double *X, int n){
    double s = sqrt(scalar(X, X, n));
    double
    double d = sqrt(scalar(()))
}
