#include "complex.h"

// Somma tra due numeri complessi:
// (a + ib) + (c + id) = (a + c) + i(b + d)
Complex complex_add(Complex a, Complex b) {

    // Variabile risultato
    Complex result;

    // Somma delle parti reali
    result.re = a.re + b.re;

    // Somma delle parti immaginarie
    result.im = a.im + b.im;

    return result;
}

// Moltiplicazione tra due numeri complessi:
// (a + ib)(c + id) = (ac - bd) + i(ad + bc)
// i^2 = -1
Complex complex_mul(Complex a, Complex b) {

    // Variabile risultato
    Complex result;

    // Parte reale:
    // ac - bd
    result.re = a.re * b.re - a.im * b.im;

    // Parte immaginaria:
    // ad + bc
    result.im = a.re * b.im + a.im * b.re;

    return result;
}

// Calcola il modulo quadro:
// |z|^2 = re^2 + im^2
double complex_abs2(Complex z) {
    
    return z.re * z.re + z.im * z.im;
}