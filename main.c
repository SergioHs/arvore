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

    int isIserido = insereABB(pArvore, novo, cmp);

    int percorreu = percursoPreOrdem(pArvore, processa);

    printf("\n deu certo code: %d", percorreu); 
    return 0;
}