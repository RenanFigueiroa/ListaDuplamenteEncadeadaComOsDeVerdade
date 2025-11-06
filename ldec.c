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
    
}
