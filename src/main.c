#include <stdio.h>
#include <stdlib.h>

#include "parser.h"

int main() {

    int q =
        parse_qubits("examples/H2-init.q");

    printf("Qubits: %d\n", q);

    Complex *state =
        parse_init_state("examples/H2-init.q",
                         q);

    int size = 1 << q;

    printf("\nStato iniziale:\n");

    for(int i = 0; i < size; i++) {

        printf("%.2f + i%.2f\n",
               state[i].re,
               state[i].im);
    }

    free(state);

    return 0;
}