#include <stdlib.h>
#include "matrix.h"
#include "complex.h"

// Alloca dinamicamente una matrice
// rows = numero di righe
// cols = numero di colonne
Matrix *create_matrix(int rows, int cols) {

    // Alloca memoria per la struttura Matrix
    Matrix *m = malloc(sizeof(Matrix));

    // Salva numero righe
    m->rows = rows;

    // Salva numero colonne
    m->cols = cols;

    // Alloca array di puntatori alle righe
    m->data = malloc(rows * sizeof(Complex *));

    // Alloca ogni riga della matrice
    for(int i = 0; i < rows; i++) {

        m->data[i] = malloc(cols * sizeof(Complex));

        // Inizializza ogni elemento a 0 + 0i
        for(int j = 0; j < cols; j++) {

            m->data[i][j].re = 0;
            m->data[i][j].im = 0;
        }
    }

    return m;
}

// Libera tutta la memoria associata alla matrice
void free_matrix(Matrix *m) {

    // Libera ogni riga
    for(int i = 0; i < m->rows; i++) {

        free(m->data[i]);
    }

    // Libera array di righe
    free(m->data);

    // Libera struttura Matrix
    free(m);
}

// Moltiplicazione matrice-vettore
// result = m * v
Complex *matrix_vector_mul(Matrix *m, Complex *v) {

    // Alloca vettore risultato
    Complex *result = malloc(m->rows * sizeof(Complex));

    for(int i = 0; i < m->rows; i++) {

        // Inizializza risultato a 0
        result[i].re = 0;
        result[i].im = 0;

        // Prodotto riga-colonna
        for(int j = 0; j < m->cols; j++) {

            // Calcola: m[i][j] * v[j]
            Complex prod =
                complex_mul(m->data[i][j], v[j]);

            // Somma al risultato corrente
            result[i] =
                complex_add(result[i], prod);
        }
    }

    return result;
}

// Moltiplicazione matrice-matrice
// result = a * b
Matrix *matrix_mul(Matrix *a, Matrix *b) {

    // Controllo compatibilità matrici
    // Numero colonne di A deve essere uguale al numero righe di B
    if(a->cols != b->rows) {

        return NULL;
    }

    // Crea matrice risultato
    Matrix *result =
        create_matrix(a->rows, b->cols);

    for(int i = 0; i < a->rows; i++) {

        for(int j = 0; j < b->cols; j++) {

            // Inizializza elemento risultato a 0
            result->data[i][j].re = 0;
            result->data[i][j].im = 0;

            // Prodotto righe-colonne
            for(int k = 0; k < a->cols; k++) {

                // Calcola: A[i][k] * B[k][j]
                Complex prod =
                    complex_mul(
                        a->data[i][k],
                        b->data[k][j]
                    );

                // Somma accumulata
                result->data[i][j] =
                    complex_add(
                        result->data[i][j],
                        prod
                    );
            }
        }
    }

    return result;
}