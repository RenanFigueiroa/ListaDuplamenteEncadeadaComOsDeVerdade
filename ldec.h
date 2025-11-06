#include <stdio.h>
#include <stdlib.h>

#ifdef  _WIN32
    #define LIMPAR_TELA "cls"
#else
    #define LIMPAR_TELA "clear"
#endif

typedef struct No {
    int n;
    No *prox;
    No *ant;

}No;

struct No *head = NULL;