#include "arvore_interface.h"

#include <stdio.h>
#include <stdlib.h>


int cmp (void *p1, void *p2){
    int *a = p1;
    int *b = p2;

    return *a < *b;
}

void processa (void *p){
    int* dado = p;
    printf("\n%d", *dado);
}


int main() {
    pABB pArvore = NULL;
    int isCriado = criaABB(&pArvore, sizeof(int)); 
    if(!isCriado){
        printf("deu ruim");
        return 1;
    }

    int *novo = malloc(sizeof(int));
    *novo = 10;

    int *novo1 = malloc(sizeof(int));
    *novo = 21;

    int *novo2 = malloc(sizeof(int));
    *novo = 32;

    int isIserido = insereABB(pArvore, novo, cmp);
    int isIserido1 = insereABB(pArvore, novo1, cmp);
    int isIserido2 = insereABB(pArvore, novo2, cmp);

    if(isIserido1 && isIserido && isIserido2){
        printf("\n is insErido td \n");
    }

    int percorreu = percursoPreOrdem(pArvore, processa);

    printf("\n ____>>>>> deu certo code: %d\n ", percorreu); 
    return 0;
}