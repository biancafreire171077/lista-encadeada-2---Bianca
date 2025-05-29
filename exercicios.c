// ------------------------ lista encadeada simples
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>

// ------------------------ Definição do nó da lista
//typedef struct No {
    //int dado;
    //struct No* prox;
//} No;

// ------------------------ Inserção no início
//void inserir_inicio(No** lista, int valor) {
    //No* novo = (No*)malloc(sizeof(No));
    //novo->dado = valor;
    //novo->prox = *lista;
    //*lista = novo;
//}

// ------------------------ Inserção no fim
//void inserir_fim(No** lista, int valor) {
    //No* novo = (No*)malloc(sizeof(No));
    //novo->dado = valor;
    //novo->prox = NULL;
    //if (*lista == NULL) {
        //*lista = novo;
    //} else {
        //No* temp = *lista;
        //while (temp->prox != NULL) {
           //temp = temp->prox;
        //}
        //temp->prox = novo;
    //}
//}

// ------------------------ Contagem de nós
//int contar_nos(No* lista) {
    //int count = 0;
    //while (lista != NULL) {
        //count++;
        //lista = lista->prox;
    //}
    //return count;
//}

// ------------------------ Busca de elemento
//int buscar_elemento(No* lista, int valor) {
    //while (lista != NULL) {
        //if (lista->dado == valor) return 1;
        //lista = lista->prox;
    //}
    //return 0;
//}

// ------------------------ Inserção em posição específica (0-indexado)
//void inserir_posicao(No** lista, int valor, int pos) {
    //if (pos == 0) {
        //inserir_inicio(lista, valor);
        //return;
    //}
    //No* temp = *lista;
    //for (int i = 0; i < pos - 1 && temp != NULL; i++) {
        //temp = temp->prox;
    //}
    //if (temp == NULL) return;
    //No* novo = (No*)malloc(sizeof(No));
    //novo->dado = valor;
    //novo->prox = temp->prox;
    //temp->prox = novo;
//}

// ------------------------ Remoção por valor
//void remover_valor(No** lista, int valor) {
    //No* temp = *lista;
    //No* anterior = NULL;
    //while (temp != NULL && temp->dado != valor) {
        //anterior = temp;
        //temp = temp->prox;
    //}
    //if (temp == NULL) return;
    //if (anterior == NULL) {
        //*lista = temp->prox;
    //} else {
        //anterior->prox = temp->prox;
    //}
    //free(temp);
//}

// ------------------------ Inversão iterativa
//void inverter_lista(No** lista) {
    //No* prev = NULL;
    //No* atual = *lista;
    //No* prox = NULL;
    //while (atual != NULL) {
        //prox = atual->prox;
        //atual->prox = prev;
        //prev = atual;
        //atual = prox;
    //}
    //*lista = prev;
//}

// ------------------------ Encontrar o nó do meio
//No* encontrar_meio(No* lista) {
    //No* lento = lista;
    //No* rapido = lista;
    //while (rapido != NULL && rapido->prox != NULL) {
        //lento = lento->prox;
        //rapido = rapido->prox->prox;
    //}
    //return lento;
//}

// ------------------------ Impressão reversa usando pilha
//void imprimir_reverso(No* lista) {
    //int pilha[100], topo = -1;
    //while (lista != NULL) {
        //pilha[++topo] = lista->dado;
        //lista = lista->prox;
    //}
    //while (topo >= 0) {
        //printf("%d ", pilha[topo--]);
    //}
    //printf("\n");
//}
