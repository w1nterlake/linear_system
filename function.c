#include "function.h"

void f0(double *A, int n, char *filename, int *err){
    FILE *fin;
    int count = 0;
    fin = fopen(filename, "r");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(fscanf("%lf", A + i * n + j) == 1){
                count++;
            }
        }
    }
    if(count != n * n){
        *err = 4;
    }

    fclose(fin);
}

void f1(double *A, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            A[i * n + j] = n -MAX(i, j) + 1;
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
            A[i * n + j] = abs(i - j);
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
        case(0):
            f0(A, n, filename, err);
            break;
        case(1):
            f1(A, n);
            break;
        case(2):
            f2(A, n);
            break;
        case(3):
            f3(A, n);
            break;
        case(4):
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

double norm_1(double *X, int n){
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

double scalar(double *A, double *B, int n){
    double sum = 0;
    for(int i = 0; i < n; i++){
        sum += A[i] * B[i];
    }
}

double norm_2(double *X, int n){
    return sqrt(scalar(X, X, n));
}

void made_vector(double *A, double *X, int n){
    double tmp = norm_2(A, n);
    A[0] -= tmp;
    tmp = norm_2(A, n);
    for(int i = 0; i < n; i++){
        A[i] /= tmp;
        X[i] = A[i];
    }
}

