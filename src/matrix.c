#include <stdlib.h>
#include "matrix.h"
#include "complex.h"

// Alloca dinamicamente una matrice
Matrix *create_matrix(int rows, int cols) {

    // Alloca struttura Matrix
    Matrix *m = malloc(sizeof(Matrix));

    // Salva dimensioni
    m->rows = rows;
    m->cols = cols;

    // Alloca array di righe
    m->data = malloc(rows * sizeof(Complex *));

    // Alloca ogni riga
    for(int i = 0; i < rows; i++) {

        m->data[i] = malloc(cols * sizeof(Complex));
    }

    return m;
}