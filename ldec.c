#include "ldec.h"

No *head = NULL;

No* criar_No(int n) {
    No* novoNo = (No*) malloc(sizeof(No));
    if (novoNo == NULL){
        printf("'Alocacao de Memoria Falhou!/n");
        exit(1);
    }
    novoNo->n = n;
    novoNo->prox = NULL;
    novoNo->ant = NULL;
    return novoNo;
}

void inserir_No_Inicio(int n){
    struct No* novoNo = criar_No(n);
    if (head == NULL) {
        head = novoNo;
        head->prox = head;
        head->ant = head;
    } else {
        struct No* ultimo = head->ant;
        novoNo->prox = head;
        novoNo->ant = ultimo;
        head->ant = novoNo;
        ultimo->prox = novoNo;
    head = novoNo;
    }
    printf("%d inserido no inicio!\n", n);
}

void inserir_final(int n){
    struct No* novoNo = criar_No(n);
    if (head == NULL) {
        head = novoNo;
        head->prox = head;
        head->ant = head; 
    } else {
        struct No* ultimo = head->ant;
        novoNo->prox = head;
        novoNo->ant = ultimo;
        ultimo->prox = novoNo;
        head->ant = novoNo;
    }
    printf("inserido %d no final\n", n);
}

void deletar_Elemento_porTecla(int key) {
    if (head == NULL) {
        printf("A lista está vazia! Nada para deletar.\n");
    return;
    }

    No *curr = head;

    while (curr->n != key) {
        curr = curr->prox;
        if (curr == head) {
            printf("Nó com valor %d não encontrado.\n", key);
        return;
        }
    }

    if (curr->prox == head && curr->ant == head) {
        head = NULL;
        free(curr);
        printf("Elemento %d deletado.\n", key);
        return;
    }

    if (curr == head) {
        No *ultimo = head->ant;
        head = head->prox;
        head->ant = ultimo;
        ultimo->prox = head;
     } else {
         curr->ant->prox = curr->prox;
         curr->prox->ant = curr->ant;
    }

    free(curr);
    printf("Elemento %d deletado.\n", key);
}

void mostrar() {
    if(head == NULL) {
        printf("Lista esta vazia!\n");
    return;
    }

    struct No* current = head;
    printf("\n--- Lista Duplamente Encadeada Circular ---\n");
    do {
        printf("%d <-> ", current->n);
        current = current->prox;
    } while(current != head);
    printf("(Volta ao HEAD %d)\n", head->n);
}