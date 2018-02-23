/* 	
main.c
Autor: Orlando Enrico Liz Silvério Silva
*/
#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main(){
    unsigned int N; // unsigned int -> (0, 2³²-1) 
    
    if(scanf("%u", &N)!=1) printf("Erro\n");

    Matrix matriz;
    criaMatriz(&matriz, N); // aloca e inicializa matriz 
    double *vetor = (double*) calloc((1<<N), sizeof(double)); // double tem maior precisão, (1<<N) = 2^N
    
    unsigned int i, j, k;
    for(i=0; i<N; i++) // leitura da matriz de probabilidades
    	for(j=0; j<N; j++)
    		if(scanf("%lf", &matriz.prob[i][j])!=1) printf("Erro\n");
    
    vetor[(1<<N)-1] = 1; // probabilidade do conjunto com todos os amigos é 1
    
    for(i=(1<<N)-1; i; i--){ // varia o conjunto
    	int aux = i, z = 0;
    	// cardinalidade do conjunto em questão
       	while(aux>0){
       		z++; 
       		aux &= (aux-1); 
    	}
    	z = z*(z-1)/2; // combinação de z elementos tomados 2 a 2

       	for(j=0; j<N; j++) 			// varia o j-ésimo amigo
       		if(i & (1<<j)) 			// valida ele dentro do conjunto em questão
       			for(k=0; k<N; k++) 	// varia o k-ésimo amigo
      				if(i & (1<<k)) 	// valida ele dentro do conjunto em questão
       					vetor[i-(1<<k)] += vetor[i] * matriz.prob[j][k]/z;
    }
    // conjuntos com apenas um amigo são armazenados em potências de 2
   	for(i=0; i<N; i++){
   		printf("%.4lf ", vetor[1<<i]);
   	}
	printf("\n"); 
   	
   	free(vetor);
   	liberaMatriz(&matriz);
    return 0;
}