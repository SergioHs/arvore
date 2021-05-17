#include "arvore_interface.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define SUCESSO 1
#define FRACASSO 0

void percursoPreOrdemNo (NoABB *noArvore, void (* processa)(void *p)){
    if(!noArvore){
        return;
    }
    processa(noArvore->dados);
    percursoPreOrdemNo(noArvore->esquerda, processa);
    percursoPreOrdemNo(noArvore->direita, processa);
}

int testaVaziaABB(pABB p){
    return !p->raiz;
}

int criaABB(ppABB pp, int tamInfo){
    *pp = malloc(sizeof(ABB));
    if(*pp){
        (*pp)->raiz = NULL;
        (*pp)->tamInfo = tamInfo;
        return SUCESSO;

    } else {
        return FRACASSO;
        
    }
}

int insereABB(pABB p, void *novo, int (* cmp)(void *p1, void *p2)){
        NoABB *noArvore = malloc(sizeof(NoABB));
        if(!noArvore){
            return FRACASSO;
        }

        noArvore->dados = novo;
        noArvore->direita = NULL;
        noArvore->esquerda = NULL;

        if(testaVaziaABB(p)){
            noArvore->pai = NULL;
            p->raiz = noArvore;
        }
}

int percursoPreOrdem(pABB pa, void (* processa)(void *p)){
    if(testaVaziaABB(pa)){
        return FRACASSO;
    }
    percursoPreOrdemNo(pa->raiz, processa);
    return SUCESSO;

}