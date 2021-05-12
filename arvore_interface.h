#include "arvore_privado.h"

typedef ABB* pABB;
typedef ABB** ppABB;

int criaABB(ppABB pp, int tamInfo);
int destroiABB(ppABB pp);
int reiniciaABB(pABB p);

int insereABB(pABB p, void *novo, int (* cmp)(void *p1, void *p2));
int removeABB(pABB p, void *item, int (* cmp)(void *p1, void *p2));
int buscaABB(pABB p, void *item, int (* cmp)(void *p1, void *p2));

int testaVaziaABB(pABB p);
int percursoEmOrdem(pABB pa, void (* processa)(void *p));
int percursoPreOrdem(pABB pa, void (* processa)(void *p));
int percursoPosOrdem(pABB pa, void (* processa)(void *p));