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

void percursoEmOrdemNo(NoABB *noArvore, void (* processa)(void *p)){
    if(!noArvore){
        return;
    }
    percursoEmOrdemNo(noArvore->esquerda, processa);
    processa(noArvore->dados);
    percursoEmOrdemNo(noArvore->direita, processa);
}

void percursoPosOrdemNo(NoABB *noArvore, void (* processa)(void *p)){
    if(!noArvore){
        return;
    }
    percursoPosOrdemNo(noArvore->esquerda, processa);
    percursoPosOrdemNo(noArvore->direita, processa);
    processa(noArvore->dados);
}

int buscaNo(NoABB *NoABB, void *item, int (* cmp)(void *p1, void *p2)){
    if(!NoABB){
        return FRACASSO;
    }
    if(NoABB->dados == item){
        return SUCESSO;
    }
    if(cmp(item, NoABB->dados)){
        return buscaNo(NoABB->esquerda, item, cmp);
    } else {
        return buscaNo(NoABB->direita, item, cmp);
    }

}

int insereNo (NoABB **noArvore, NoABB *noPai, void *dado, int (* cmp)(void *p1, void *p2)){
    if(!*noArvore){
        *noArvore = malloc(sizeof(NoABB));
        if(!*noArvore){
            return FRACASSO;
        }
        (*noArvore)->pai = noPai;
        (*noArvore)->dados = dado;
        (*noArvore)->direita = NULL;
        (*noArvore)->esquerda = NULL;
        return SUCESSO;
    } else{
        if(cmp(dado, (*noArvore)->dados)){
            return insereNo(&(*noArvore)->esquerda, *noArvore, dado, cmp);
        } else {
            return insereNo(&(*noArvore)->direita, *noArvore, dado, cmp);
        }
    }
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
        if(!p){
            return FRACASSO;
        }

        return insereNo(&p->raiz, NULL, novo, cmp);

}

int percursoPreOrdem(pABB pa, void (* processa)(void *p)){
    if(testaVaziaABB(pa)){
        return FRACASSO;
    }
    percursoPreOrdemNo(pa->raiz, processa);
    return SUCESSO;
}

int percursoEmOrdem(pABB pa, void (* processa)(void *p)){
    if(testaVaziaABB(pa)){
        return FRACASSO;
    }
    percursoEmOrdemNo(pa->raiz, processa);
    return SUCESSO;
}

int percursoPosOrdem(pABB pa, void (* processa)(void *p)){
    if(testaVaziaABB(pa)){
        return FRACASSO;
    }
    percursoPosOrdemNo(pa->raiz, processa);
    return SUCESSO;

}

int buscaABB(pABB p, void *item, int (* cmp)(void *p1, void *p2)){
        if(!p){
            return FRACASSO;
        }

        return buscaNo(p->raiz, item, cmp);

}