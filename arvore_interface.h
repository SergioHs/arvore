#include "arvore_privado.h"

typedef ABB* pABB;
typedef ABB** ppABB;

int criaABB(ppABB pp, int tamInfo);
int testaVaziaABB(pABB p);
int insereABB(pABB p, void *novo, int (* cmp)(void *p1, void *p2));
int percursoPreOrdem(pABB pa, void (* processa)(void *p));
int percursoEmOrdem(pABB pa, void (* processa)(void *p));
int percursoPosOrdem(pABB pa, void (* processa)(void *p));
int buscaABB(pABB p, void *item, int (* cmp)(void *p1, void *p2));
int reiniciaABB(pABB p);
int destroiABB(pABB p);

int removeABB(pABB p, void *item, int (* cmp)(void *p1, void *p2));
