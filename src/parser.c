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

    // Buffer per leggere righe
    char line[256];

    // Legge file riga per riga
    while(fgets(line, sizeof(line), file)) {

        // Cerca "#qubits"
        if(strstr(line, "#qubits")) {

            int n;

            // Estrae numero
            sscanf(line, "#qubits %d", &n);

            fclose(file);

            return n;
        }
    }

    fclose(file);

    return -1;
}

// Legge lo stato iniziale dal file .init
Complex *parse_init_state(char *filename,
                          int qubits) {

    // Apre file
    FILE *file = fopen(filename, "r");

    // Controlla apertura
    if(file == NULL) {

        printf("Errore apertura file: %s\n",
               filename);

        return NULL;
    }

    // Dimensione stato:
    // 2^qubits
    int size = 1 << qubits;

    // Alloca vettore stato
    Complex *state =
        malloc(size * sizeof(Complex));

    // Inizializza tutto a 0
    for(int i = 0; i < size; i++) {

        state[i].re = 0;
        state[i].im = 0;
    }

    // Buffer per leggere righe
    char line[512];

    // Legge file riga per riga
    while(fgets(line, sizeof(line), file)) {

        // Cerca riga #init
        if(strstr(line, "#init")) {

            // Cerca inizio '['
            char *start = strchr(line, '[');

            // Cerca fine ']'
            char *end = strchr(line, ']');

            // Controllo validità
            if(start == NULL || end == NULL) {

                fclose(file);

                return NULL;
            }

            // Termina stringa alla ']'
            *end = '\0';

            // Salta il '['
            start++;

            // Divide la stringa usando ','
            char *token = strtok(start, ",");

            int index = 0;

            // Legge tutti i valori
            while(token != NULL &&
                  index < size) {

                // Converte stringa -> double
                double value = atof(token);

                // Salva parte reale
                state[index].re = value;

                // Parte immaginaria = 0
                state[index].im = 0;

                index++;

                // Token successivo
                token = strtok(NULL, ",");
            }

            fclose(file);

            return state;
        }
    }

    fclose(file);

    return NULL;
}