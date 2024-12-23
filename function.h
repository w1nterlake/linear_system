#ifndef FUNCTION
#define FUNCTION

#define eps 1e-15
#define MAX(n, m) n > m ? n : m

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void print_matrix(double *A, int n); 

void f0(double *A, int n, char *filename, int *err);//

void f1(double *A, int n);//

void f2(double *A, int n);//

void f3(double *A, int n);//

void f4(double *A, int n);//

void fill(double *A, int n, char *filename, int s, int *err);//

void fill_right_part(double *A, double *B, int n);//

double norm_1(double *X, int n);//

double discrepancy_1(double *A, double *B, double *X, int n);//

double discrepancy_2(double *X, int n);//

// void print_matrix(double *A, int n);

// void multiply(double *A, double *C, int n);

double scalar_1(double *X, double *Y, int k, int n);//

double scalar_2(double *X, double *y, int n);

double scalar_3(double *X, double *Y, int k, int n);

void made_vector(double *A, double *X, int l, int k, int n);//

void multiply_vector_on_vector(double *A, double *X, int k, int n);//

void multy_right_part(double *A, double *B, int k, int n);
// double norm_2(double *X, int n);

void solve(double *A, double *B, double *X, int n);

void reverse(double *A, double *B, int n);

void reflection(double *A, int n);

#endif