/*
matriz.c
Autor: Orlando Enrico Liz Silvério Silva
*/
#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"


// Aloca a matriz. Size é definido na struct pra poder percorrer
// a matriz de forma direta, sem a necessidade de parâmetros adicionais
void criaMatriz(Matrix *matrix, int n) {
    matrix->n = n;
    matrix->prob = (double**) calloc(matrix->n, sizeof(double*));
 
    int i;
    for (i = 0; i < matrix->n; i++) {
        matrix->prob[i] = (double*) calloc(matrix->n, sizeof(double));
    }
}
 
// Libera a memória alocada para a matriz (Perceba a utilização de "size" aqui)
void liberaMatriz(Matrix *matrix) {
    int i;
    for (i = 0; i < matrix->n; i++) {
        free(matrix->prob[i]);
    }
 
    free(matrix->prob);
}
