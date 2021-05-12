#include "arvore_interface.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define SUCESSO 1
#define FRACASSO 0

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