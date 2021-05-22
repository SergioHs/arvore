#include "arvore_interface.h"

#include <stdio.h>
#include <stdlib.h>


int cmp (void *p1, void *p2){
    char *a = p1;
    char *b = p2;

    return *a < *b;
}

void processa (void *p){
    char* dado = p;
    printf(" %c ", *dado);
}


int main() {
    pABB pArvore = NULL;
    int isCriado = criaABB(&pArvore, sizeof(int)); 
    if(!isCriado){
        printf("deu ruim");
        return 1;
    }

    char* letras = malloc(sizeof(char)*9);
    char* string = "FBADCEGIH";


    printf("|------------PERCORRENDO------------|");

    int i;
    for(i=0; i<9; i++){
        letras[i] = string[i];
        insereABB(pArvore, &letras[i], cmp);
    }

    printf("\n>>>>> Percurso Pre Ordem (RED): "); 
    percursoPreOrdem(pArvore, processa);

    printf("\n>>>>>>> Percurso Em Ordem(ERD): "); 
    percursoEmOrdem(pArvore, processa);

    printf("\n>>>>> Percurso Pos Ordem (EDR): "); 
    percursoPosOrdem(pArvore, processa);
    printf("\n"); 

    printf("\n|---------------BUSCA---------------| \n");

    int j;
    int resultado;
    for(j=0; j<9; j++){
        resultado = buscaABB(pArvore, &letras[j], cmp);
        if(resultado){
            printf("Item buscado: %c - Encontrado.\n", letras[j]);
        }

    }

    char* letraErrada = malloc(sizeof(char));
    *letraErrada = 'X';

    resultado = buscaABB(pArvore, letraErrada, cmp);
    if(!resultado){
        printf("Item buscado: %c - Nao Encontrado.\n", *letraErrada);
    }

    printf("|-------------------------------------| \n");

    return 0;
}