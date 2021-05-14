#include "arvore_interface.h"

#include <stdio.h>

int cmp (void *p1, void *p2){
    int *a = p1;
    int *b = p2;

    return *a < *b;
}

int processa (void *p){
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

    // int valor1 = 10;
    // int valor2 = 20;
    // int res = cmp(&valor1, &valor2);
    // printf("%d", res);

    printf("\n deu certo :) "); 
    return 0;
}