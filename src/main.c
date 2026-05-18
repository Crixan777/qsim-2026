#include <stdio.h>
#include "complex.h"
#include "matrix.h"
#include <stdlib.h>

int main() {

    // Crea prima matrice 2x2
    Matrix *a = create_matrix(2, 2);

    // Inserisce valori in A
    a->data[0][0] = (Complex){1, 0};
    a->data[0][1] = (Complex){2, 0};

    a->data[1][0] = (Complex){3, 0};
    a->data[1][1] = (Complex){4, 0};

    // Crea seconda matrice 2x2
    Matrix *b = create_matrix(2, 2);

    // Inserisce valori in B
    b->data[0][0] = (Complex){5, 0};
    b->data[0][1] = (Complex){6, 0};

    b->data[1][0] = (Complex){7, 0};
    b->data[1][1] = (Complex){8, 0};

    // Moltiplicazione matriciale
    Matrix *c = matrix_mul(a, b);

    // Stampa risultato
    printf("Risultato matrix_mul:\n");

    for(int i = 0; i < c->rows; i++) {

        for(int j = 0; j < c->cols; j++) {

            printf("%.2f ",
                   c->data[i][j].re);
        }

        printf("\n");
    }

    // Crea vettore
    Complex v[2];

    v[0] = (Complex){1, 0};
    v[1] = (Complex){2, 0};

    // Moltiplicazione matrice-vettore
    Complex *result =
        matrix_vector_mul(a, v);

    printf("\nRisultato matrix_vector_mul:\n");

    for(int i = 0; i < 2; i++) {

        printf("%.2f + i%.2f\n",
               result[i].re,
               result[i].im);
    }

    // Libera memoria
    free(result);

    free_matrix(a);
    free_matrix(b);
    free_matrix(c);

    return 0;
}