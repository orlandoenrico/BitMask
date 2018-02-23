/*
matriz.h
Autor: Orlando Enrico Liz Silvério Silva
*/
#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct {
    double **prob; //matriz 
    int n; //tamanho da matriz
}Matrix;

/*------------------------------------------------------------------------------
 Função:  aloca a matriz de tamanho size x size.
 Entrada: ponteiro para a estrutura que possui a matriz e o seu tamanho.
 Saída:   sem retorno.
------------------------------------------------------------------------------*/
void criaMatriz(Matrix *matrix, int n) ;

/*------------------------------------------------------------------------------
 Função:  libera a memória alocada pela matriz.
 Entrada: ponteiro para a estrutura Matrix, contendo a matriz a ser desalocada.
 Saída:   sem retorno.
------------------------------------------------------------------------------*/
void liberaMatriz(Matrix *matrix) ;

#endif


