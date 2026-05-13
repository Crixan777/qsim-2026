#ifndef COMPLEX_H
#define COMPLEX_H

/* Struttura che rappresenta un numero complesso:
 *
 * z = re + i*im
 *
 * re = parte reale
 * im = parte immaginaria
 */
typedef struct {
    double re;
    double im;
} Complex;

/*
 * Somma tra due numeri complessi.
 *
 * Parametri:
 *  a = primo numero complesso
 *  b = secondo numero complesso
 *
 * Ritorna:
 *  a + b
 */
Complex complex_add(Complex a, Complex b);

/*
 * Moltiplicazione tra due numeri complessi.
 *
 * Parametri:
 *  a = primo numero complesso
 *  b = secondo numero complesso
 *
 * Ritorna:
 *  a * b
 */
Complex complex_mul(Complex a, Complex b);

/*
 * Calcola il modulo quadro di un numero complesso.
 *
 * |z|^2 = re^2 + im^2
 *
 * Questa funzione verrà usata per
 * calcolare le probabilità durante
 * la fase di misura quantistica.
 *
 * Parametri:
 *  z = numero complesso
 *
 * Ritorna:
 *  |z|^2
 */
double complex_abs2(Complex z);

#endif