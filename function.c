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

double scalar_1(double *X, double *Y, int k, int n){
    double sum = 0;
    for(int i = 0; i < n; i++){
        sum += X[i * n + k] * Y[i];
    }
    return sum;
}

double scalar_2(double *X, double *Y, int n){
    double sum = 0;
    for(int i = 0; i < n; i++){
        sum += X[i] * Y[i];
    }
    return sum;
}

double scalar_3(double *A, double *B, int k, int n){
    double sum = 0;
    for(int i = k; i < n; i++){
        sum += A[i] * B[i];
    }
    return sum;
}
// double norm_2(double *X, int k int n){
//     return sqrt(scalar(X, X, 0, n));
// }

void made_vector(double *A, double *X, int l, int k, int n){
    for(int i = 0; i < n; i++){
        X[i] = A[i * n + k];
    }

    for(int i = 0; i < l; i++){
        X[i] = 0;
    }
    double tmp = sqrt(scalar_2(X, X, n));
    X[l] -= tmp;
    tmp = sqrt(scalar_2(X, X, n));
    for(int i = 0; i < n; i++){
        X[i] /= tmp;
    }
}

void multiply_vector_on_vector(double *A, double *X, int k, int n){
    double tmp = scalar_1(A, X, k, n);
    for(int i = 0; i < n; i++){
        A[i * n + k] -= 2 * tmp * X[i];
    }
}

void multy_right_part(double *X, double *B, int k, int n){
    double tmp = scalar_3(X, B, k, n);
    for(int i = 0; i < n; i++){
        B[i] -= 2 * tmp * X[i];
    }
}

void reverse(double *A, double *B, int n){
    for(int i = 0; i < n; i++){
        if(fabs(A[i * n + i]) < eps){
            return;
        }
        else{
            double tmp = A[i * n + i];
            for(int j = i; j < n; j++){
                A[i * n + j] /= tmp;     
            }
            B[i] /= tmp;
        }
    }
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < i; j++){
            double tmp = A[j * n + i];
            B[j] -= A[j * n + i] * B[i];
            A[j * n + i] -= A[j * n + i] * A[i * n + i];
        }
    }
}

void solve(double *A, double *B, double *X, int n){
    for(int i = 0; i < n - 1; i++){
        made_vector(A, X, i, i, n);
        for(int j = i; j < n; j++){
            multiply_vector_on_vector(A, X, j, n);
        }
        multy_right_part(X, B, i, n);
    }
    reverse(A, B, n);
}