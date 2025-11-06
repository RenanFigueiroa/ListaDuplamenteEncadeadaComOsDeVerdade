#include <ldec.h>

void msg_erro(char *msg){
    limpar_buffer();
    system(LIMPAR_TELA);
    printf("\n----------------Erro------------------------------\n");
    printf("%s", msg);
    printf("----------------------------------------------------\n");
    printf("\nAperte <ENTER> para voltar ao menu principal.");
    getchar();
}

No* criar_No(int n) {
    No* novoNo = (No*) malloc(sizeof(No));
    if (novoNo == NULL){
        printf("'Alocacao de Memoria Falhou!/n");
    exit(1);
    }
    novoNo->n = n;
    novoNo->prox = NULL;
    novoNo ->ant = NULL;
    return novoNo;
}

void inserir_No_Inicio(int n){
    struct No* novoNo = criar_No(n);
    if (head == NULL) {
        head->prox = head;
        head->ant = head;
    } else {
        struct No* ultimo = head->ant;
        novoNo->prox =head;
        novoNo->ant=ultimo;
        head->ant = novoNo;
        ultimo->prox = novoNo;
        head = novoNo;
    }
    printf("%d inserir no inicio!", n);
}

void inserir_final(int n){
    struct No* novoNo = criar_No(n);
    if (head == NULL) {
        head = novoNo;
        head->prox = head;
        No* ultimo;
        ultimo->prox = novoNo;
        head->ant = novoNo; 
    }
    printf("inserir %d no final\n", n);
}

void deletar_Elemento_porTecla(int key) {
    if (head == NULL)  {
        printf("A lista esta vazia! Nada para deletar");
    return;
    }

    No *curr = head, *ant_1 = NULL;
    while(curr->n !=key) {
        if(curr->prox==head) {
            printf("No com o valor %d\n", key);
            return;
        }
        ant_1 = curr;
        curr = curr->prox;
    }

    if (curr->prox == head && ant_1 == NULL) {
        head = NULL;
        free(curr);
        printf("Elemento %d deletado\n", key);
        return;
    }
    //se for o primeiro No

    if(curr == head) {
        struct No* ultimo = head->ant;
        head=head->prox;
        ultimo->prox = head;
        head->ant = ultimo;
        free(curr);
    }
    else if(curr->prox==head) {
        ant_1->prox=head;
        head->ant = ant_1;
        free(curr);
    }
    else{
        curr->ant->prox = curr->prox;
        curr->prox->ant = curr->ant;
        free(curr);
    }
    printf("Elemento %d deletado\n", key);
}

void mostrar() {
    if(head == NULL) {
        printf("Lista esta vazia!\n");
    return;
    }

    struct No* current = head;
    printf("Lista Duplamente Encadeada Circular\n");
    printf("--- Simulacao de Nucleos de CPU ---\n");
    do {
        printf("%d <->\n", current->n);
        current = current->prox;
    }while(current != head);
    printf("(Head)\n");
}

