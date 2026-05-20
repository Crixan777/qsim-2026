#include <stdio.h>

#include "parser.h"

int main() {

    int q =
        parse_qubits("examples/H2-init.q");

    printf("Qubits: %d\n", q);

    return 0;
}