#include "arvore_interface.h"

#include <stdio.h>

int main() {
    pABB pArvore = NULL;
    int arvore = criaABB(&pArvore, sizeof(int)); 
    if(!arvore){
        printf("deu ruim");
        return 1;
    }

    printf("deu certo :) "); 
    return 0;
}