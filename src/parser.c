#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"

// Legge il numero di qubits dal file .init
int parse_qubits(char *filename) {

    // Apre file in lettura
    FILE *file = fopen(filename, "r");

    // Controlla apertura file
    if(file == NULL) {

        printf("Errore apertura file: %s\n", filename);

        return -1;
    }

    // Buffer per leggere una riga
    char line[256];

    // Legge il file riga per riga
    while(fgets(line, sizeof(line), file)) {

        // DEBUG:
        // stampa la riga letta
        printf("Riga letta: %s", line);

        // Cerca "#qubits" nella riga
        if(strstr(line, "#qubits")) {

            int n;

            // Estrae il numero dopo #qubits
            sscanf(line, "#qubits %d", &n);

            fclose(file);

            return n;
        }
    }

    fclose(file);

    // Nessun #qubits trovato
    return -1;
}