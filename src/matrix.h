#ifndef MATRIX_H
#define MATRIX_H

#include "complex.h"

// Struttura che rappresenta una matrice di numeri complessi
typedef struct {

    // Numero righe
    int rows;

    // Numero colonne
    int cols;

    // Matrice di numeri complessi
    Complex **data;

} Matrix;

// rows -> numero righe
// cols -> numero colonne
Matrix *create_matrix(int rows, int cols);

// Libera tutta la memoria associata alla matrice
void free_matrix(Matrix *m);

// Moltiplicazione matrice-vettore
// result = m * v
Complex *matrix_vector_mul(Matrix *m, Complex *v);

// Moltiplicazione matrice-matrice
// result = a * b
Matrix *matrix_mul(Matrix *a, Matrix *b);

#endif