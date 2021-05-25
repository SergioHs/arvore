#include "arvore_interface.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define SUCESSO 1
#define FRACASSO 0

NoABB* removeUmNo(NoABB **noArvore, void *item, int (*cmp)(void *p1, void *p2))
{
    if (*noArvore == NULL){
        return NULL;

    }else if (cmp(item, (*noArvore)->dados) < 0){
       (*noArvore)->esquerda = removeUmNo(&(*noArvore)->esquerda, item, cmp);


    }else if (cmp(item, (*noArvore)->dados) > 0){
        (*noArvore)->direita = removeUmNo(&(*noArvore)->direita, item, cmp);

    }
    else
    { 
        if ((*noArvore)->esquerda == NULL && (*noArvore)->direita == NULL)
        {
            free((*noArvore)->dados);
            free(*noArvore);
            *noArvore = NULL;
        }
        /* nó só tem filho à direita */
        else if ((*noArvore)->esquerda == NULL)
        {
            NoABB *temporario = *noArvore;
            (*noArvore)->direita->pai = (*noArvore)->pai;
            *noArvore = (*noArvore)->direita;
            free(temporario->dados);
            free(temporario);
        }
        /* só tem filho à esquerda */
        else if ((*noArvore)->direita == NULL)
        {
            NoABB *temporario = *noArvore;
            (*noArvore)->esquerda->pai = (*noArvore)->pai;
            *noArvore = (*noArvore)->esquerda;
            free(temporario->dados);
            free(temporario);
        }
        /* nó tem os dois filhos */
        else
        {
            NoABB *f = (*noArvore)->esquerda;
            while (f->direita != NULL)
            {
                f = f->direita;
            }
            (*noArvore)->dados = f->dados; /* troca as informações */
            f->dados = item;
            (*noArvore)->esquerda = removeUmNo(&(*noArvore)->esquerda, item, cmp);
        }
    }
    return *noArvore;
}

int removeNos(NoABB *p)
{
    if (p == NULL || !p)
    {
        return SUCESSO;
    }

    if (p->esquerda != NULL && p->esquerda)
        removeNos(p->esquerda);
    if (p->direita != NULL && p->direita)
        removeNos(p->direita);

    if (p->dados != NULL)
    {
        p->dados = NULL;
        free(p->dados);
    }

    if (p != NULL)
    {
        p = NULL;
        free(p);
    }

    return SUCESSO;
}

void percursoPreOrdemNo(NoABB *noArvore, void (*processa)(void *p))
{
    if (!noArvore)
    {
        return;
    }
    processa(noArvore->dados);
    percursoPreOrdemNo(noArvore->esquerda, processa);
    percursoPreOrdemNo(noArvore->direita, processa);
}

void percursoEmOrdemNo(NoABB *noArvore, void (*processa)(void *p))
{
    if (!noArvore)
    {
        return;
    }
    percursoEmOrdemNo(noArvore->esquerda, processa);
    processa(noArvore->dados);
    percursoEmOrdemNo(noArvore->direita, processa);
}

void percursoPosOrdemNo(NoABB *noArvore, void (*processa)(void *p))
{
    if (!noArvore)
    {
        return;
    }
    percursoPosOrdemNo(noArvore->esquerda, processa);
    percursoPosOrdemNo(noArvore->direita, processa);
    processa(noArvore->dados);
}

int buscaNo(NoABB *NoABB, void *item, int (*cmp)(void *p1, void *p2))
{
    if (!NoABB)
    {
        return FRACASSO;
    }
    if (NoABB->dados == item)
    {
        return SUCESSO;
    }
    if (cmp(item, NoABB->dados) < 0)
    {
        return buscaNo(NoABB->esquerda, item, cmp);
    }
    else
    {
        return buscaNo(NoABB->direita, item, cmp);
    }
}

int insereNo(NoABB **noArvore, NoABB *noPai, void *dado, int (*cmp)(void *p1, void *p2))
{
    if (!*noArvore)
    {
        *noArvore = malloc(sizeof(NoABB));
        if (!*noArvore)
        {
            return FRACASSO;
        }
        (*noArvore)->pai = noPai;
        (*noArvore)->dados = dado;
        (*noArvore)->direita = NULL;
        (*noArvore)->esquerda = NULL;
        return SUCESSO;
    }
    else
    {
        if (cmp(dado, (*noArvore)->dados) < 0)
        {
            return insereNo(&(*noArvore)->esquerda, *noArvore, dado, cmp);
        }
        else
        {
            return insereNo(&(*noArvore)->direita, *noArvore, dado, cmp);
        }
    }
}

int testaVaziaABB(pABB p)
{
    return !p->raiz;
}

int criaABB(ppABB pp, int tamInfo)
{
    *pp = malloc(sizeof(ABB));
    if (*pp)
    {
        (*pp)->raiz = NULL;
        (*pp)->tamInfo = tamInfo;
        return SUCESSO;
    }
    else
    {
        return FRACASSO;
    }
}

int insereABB(pABB p, void *novo, int (*cmp)(void *p1, void *p2))
{
    if (!p)
    {
        return FRACASSO;
    }

    return insereNo(&p->raiz, NULL, novo, cmp);
}

int percursoPreOrdem(pABB pa, void (*processa)(void *p))
{
    if (testaVaziaABB(pa))
    {
        return FRACASSO;
    }
    percursoPreOrdemNo(pa->raiz, processa);
    return SUCESSO;
}

int percursoEmOrdem(pABB pa, void (*processa)(void *p))
{
    if (testaVaziaABB(pa))
    {
        return FRACASSO;
    }
    percursoEmOrdemNo(pa->raiz, processa);
    return SUCESSO;
}

int percursoPosOrdem(pABB pa, void (*processa)(void *p))
{
    if (testaVaziaABB(pa))
    {
        return FRACASSO;
    }
    percursoPosOrdemNo(pa->raiz, processa);
    return SUCESSO;
}

int buscaABB(pABB p, void *item, int (*cmp)(void *p1, void *p2))
{
    if (!p)
    {
        return FRACASSO;
    }

    return buscaNo(p->raiz, item, cmp);
}

int reiniciaABB(pABB p)
{
    if (p)
    {
        removeNos(p->raiz);
        p->raiz = NULL;
    }
    return SUCESSO;
}

int destroiABB(pABB p)
{
    if (testaVaziaABB(p))
    {
        return SUCESSO;
    }

    if (p->raiz != NULL)
    {
        removeNos(p->raiz);
    }
    p = NULL;
    free(p);

    return SUCESSO;
}

int removeABB(pABB p, void *item, int (*cmp)(void *p1, void *p2))
{
    if (!p)
    {
        return FRACASSO;
    }
    
    return removeUmNo(&p->raiz, item, cmp) != NULL;

}
