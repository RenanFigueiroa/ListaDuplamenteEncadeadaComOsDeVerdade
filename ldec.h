#ifndef LDEC_H
#define LDEC_H

#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #define LIMPAR_TELA "cls"
#else
    #define LIMPAR_TELA "clear"
#endif

typedef struct No{
    int n;
    struct No *prox;
    struct No *ant;
}No;

extern No *head;

No* criar_No(int n);
void inserir_No_Inicio(int n); 
void inserir_final(int n);     
void deletar_Elemento_porTecla(int key); 
void mostrar();

#endif