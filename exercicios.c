// ------------------------EX 1 - lista encadeada simples
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

// ------------------------ EX 2 -Contagem de nós
//int contar_nos(No* lista) {
    //int count = 0;
    //while (lista != NULL) {
        //count++;
        //lista = lista->prox;
    //}
    //return count;
//}

// ------------------------ EX 3 -Busca de elemento
//int buscar_elemento(No* lista, int valor) {
    //while (lista != NULL) {
        //if (lista->dado == valor) return 1;
        //lista = lista->prox;
    //}
    //return 0;
//}

// ------------------------ EX 4 - Inserção em posição específica (0-indexado)
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

// ------------------------ EX 5 - Remoção por valor
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

// ------------------------ EX 6 - Inversão iterativa
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

// ------------------------ EX 7 - Encontrar o nó do meio
//No* encontrar_meio(No* lista) {
    //No* lento = lista;
    //No* rapido = lista;
    //while (rapido != NULL && rapido->prox != NULL) {
        //lento = lento->prox;
        //rapido = rapido->prox->prox;
    //}
    //return lento;
//}

// ------------------------  EX 8 - Impressão reversa usando pilha
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

// ------------------------ EX 9 - Pilhas com array 
//#define MAX 100

//typedef struct {
    //int itens[MAX];
    //int topo;
//} PilhaArray;

//void inicializar_pilha(PilhaArray* p) {
    //p->topo = -1;
//}

//int esta_vazia(PilhaArray* p) {
    //return p->topo == -1;
//}

//void push(PilhaArray* p, int valor) {
    //if (p->topo < MAX - 1) {
        //p->itens[++p->topo] = valor;
    //}
//}

//int pop(PilhaArray* p) {
    //if (!esta_vazia(p)) {
        //return p->itens[p->topo--];
    //}
    //return -1;
//}

//int topo(PilhaArray* p) {
    //if (!esta_vazia(p)) {
        //return p->itens[p->topo];
    //}
    //return -1;
//}

// ------------------------ EX 10 -  Pilha com Lista Encadeada
//typedef struct NoPilha {
    //int dado;
    //struct NoPilha* prox;
//} NoPilha;

//void push_lista(NoPilha** topo, int valor) {
    //NoPilha* novo = (NoPilha*)malloc(sizeof(NoPilha));
    //novo->dado = valor;
    //novo->prox = *topo;
    //*topo = novo;
//}

//int pop_lista(NoPilha** topo) {
    //if (*topo == NULL) return -1;
    //int valor = (*topo)->dado;
    //NoPilha* temp = *topo;
    //*topo = (*topo)->prox;
    //free(temp);
    //return valor;
//}

//int topo_lista(NoPilha* topo) {
    //return topo ? topo->dado : -1;
//}

//int esta_vazia_lista(NoPilha* topo) {
    //return topo == NULL;
//}

// ------------------------ EX 11 - Verificação de Parênteses Balanceados
//int verificar_balanceamento(const char* str) {
    //PilhaArray p;
    //inicializar_pilha(&p);
    //for (int i = 0; str[i] != '\0'; i++) {
        //if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            //push(&p, str[i]);
        //} else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            //if (esta_vazia(&p)) return 0;
            //char topoChar = pop(&p);
            //if ((str[i] == ')' && topoChar != '(') ||
                //(str[i] == '}' && topoChar != '{') ||
                //(str[i] == ']' && topoChar != '[')) {
                //return 0;
            //}
        //}
    //}
    //return esta_vazia(&p);
//}

// ------------------------ EX 12 - Inversão de String com Pilha
//void inverter_string(char* str) {
    //PilhaArray p;
    //inicializar_pilha(&p);
    //for (int i = 0; str[i] != '\0'; i++) {
        //push(&p, str[i]);
    //}
    //for (int i = 0; !esta_vazia(&p); i++) {
        //str[i] = pop(&p);
    //}
//}

// ------------------------ EX 14 - Verificação de Palíndromo
//int verificar_palindromo(const char* str) {
    //int len = strlen(str);
    //PilhaArray p;
    //inicializar_pilha(&p);
    //for (int i = 0; i < len; i++) {
        //push(&p, str[i]);
    //}
    //for (int i = 0; i < len; i++) {
        //if (str[i] != pop(&p)) return 0;
    //}
    //return 1;
//}

// ------------------------ EX 15 - Ordenação de Pilha usando Pilha Auxiliar
//void ordenar_pilha(PilhaArray* p) {
    //PilhaArray aux;
    //inicializar_pilha(&aux);
    //while (!esta_vazia(p)) {
        //int temp = pop(p);
        //while (!esta_vazia(&aux) && topo(&aux) > temp) {
            //push(p, pop(&aux));
        //}
        //push(&aux, temp);
    //}
    //while (!esta_vazia(&aux)) {
        //push(p, pop(&aux));
    //}
//}

// ------------------------ EX 16 - Fila com Array Circular
//typedef struct {
    //int itens[MAX];
    //int frente, tras, tamanho;
//} FilaArray;

//void inicializar_fila(FilaArray* f) {
    //f->frente = 0;
    //f->tras = -1;
    //f->tamanho = 0;
//}

//void enfileirar(FilaArray* f, int valor) {
    //if (f->tamanho < MAX) {
        //f->tras = (f->tras + 1) % MAX;
        //f->itens[f->tras] = valor;
        //f->tamanho++;
    //}
//}

//int desenfileirar(FilaArray* f) {
    //if (f->tamanho > 0) {
        //int valor = f->itens[f->frente];
        //f->frente = (f->frente + 1) % MAX;
        //f->tamanho--;
        //return valor;
    //}
    //return -1;
//}

//int frente(FilaArray* f) {
    //return f->tamanho > 0 ? f->itens[f->frente] : -1;
//}

// ------------------------ EX 17 - Fila com Lista Encadeada
//typedef struct NoFila {
    //int dado;
    //struct NoFila* prox;
//} NoFila;

//typedef struct {
    //NoFila* inicio;
    //NoFila* fim;
//} Fila;

//void inicializar_fila_lista(Fila* f) {
    //f->inicio = f->fim = NULL;
//}

//void enfileirar_lista(Fila* f, int valor) {
    //NoFila* novo = (NoFila*)malloc(sizeof(NoFila));
    //novo->dado = valor;
    //novo->prox = NULL;
    //if (f->fim == NULL) {
        //f->inicio = f->fim = novo;
    //} else {
        //f->fim->prox = novo;
        //f->fim = novo;
    //}
//}

//int desenfileirar_lista(Fila* f) {
    //if (f->inicio == NULL) return -1;
    //int valor = f->inicio->dado;
    //NoFila* temp = f->inicio;
    //f->inicio = f->inicio->prox;
    //if (f->inicio == NULL) f->fim = NULL;
    //free(temp);
    //return valor;
//}

// ------------------------
// ------------------------