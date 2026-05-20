#ifndef PARSER_H
#define PARSER_H

#include "complex.h"

// Legge numero di qubits dal file .init
int parse_qubits(char *filename);

// Legge vettore iniziale dal file .init
Complex *parse_init_state(char *filename,
                          int qubits);


// Legge lo stato iniziale dal file .init
Complex *parse_init_state(char *filename,
                          int qubits);

#endif