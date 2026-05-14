#ifndef COMPLEX_H
#define COMPLEX_H

// Struttura che rappresenta un numero complesso:
// z = re + i*im
typedef struct {

    // Parte reale
    double re;

    // Parte immaginaria
    double im;

} Complex;

// Somma tra due numeri complessi
Complex complex_add(Complex a, Complex b);

// Moltiplicazione tra due numeri complessi
Complex complex_mul(Complex a, Complex b);

// Calcola |z|^2
double complex_abs2(Complex z);

#endif