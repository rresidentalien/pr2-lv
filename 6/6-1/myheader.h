#ifndef MYHEADER_H
#define MYHEADER_H

//#define _CRT_SECURE_NO_WARNINGS

int** allocateMatrix(int n, int m);
void inputMatrix(int **M, int n, int m);
void printMatrix(int **M, int n, int m);
void matrixTimesK(int **M, int n, int m, int k);

#endif