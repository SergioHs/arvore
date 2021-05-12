typedef struct NoABB{
    void *dados;
    struct NoABB *pai; // (opcional)
    struct NoABB *esquerda;
    struct NoABB *direita;
}NoABB;

typedef struct ABB{
    int tamInfo;
    NoABB *raiz;
}ABB;
