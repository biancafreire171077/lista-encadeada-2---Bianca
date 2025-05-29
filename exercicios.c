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

// ------------------------ EX 13 - Verificação de Palíndromo
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

// ------------------------ EX 14 - Ordenação de Pilha usando Pilha Auxiliar
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

// ------------------------ EX 15 - Fila com Array Circular
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

// ------------------------ EX 16 - Fila com Lista Encadeada
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

// ------------------------ EX 17 - Geração de Números Binários
//void gerar_numeros_binarios(int N) {
    //Fila fila;
    //inicializar_fila_lista(&fila);
    //enfileirar_lista(&fila, 1);

    //for (int i = 0; i < N; i++) {
        //int numero = desenfileirar_lista(&fila);
        //printf("%d\n", numero);
        //enfileirar_lista(&fila, numero * 10);
        //enfileirar_lista(&fila, numero * 10 + 1);
   // }
//}

// ------------------------ EX 18 - Inversão dos Primeiros K Elementos
//void inverter_primeiros_k(Fila* f, int k) {
    //PilhaArray p;
    //inicializar_pilha(&p);

    //for (int i = 0; i < k; i++) {
        //push(&p, desenfileirar_lista(f));
    //}
    //while (!esta_vazia(&p)) {
        //enfileirar_lista(f, pop(&p));
    //}
    //int tamanho = 0;
   // NoFila* temp = f->inicio;
   // while (temp != NULL) {
        //tamanho++;
       // temp = temp->prox;
    //}
    //for (int i = 0; i < tamanho - k; i++) {
        //enfileirar_lista(f, desenfileirar_lista(f));
    //}
//}

// ------------------------ EX 19 - Detecção de Ciclo (Algoritmo de Floyd)
//int detectar_ciclo(No* lista) {
    //No* rapido = lista;
    //No* lento = lista;
    //while (rapido != NULL && rapido->prox != NULL) {
        //lento = lento->prox;
        //rapido = rapido->prox->prox;
        //if (lento == rapido) return 1;
    //}
    //return 0;
//}

// ------------------------ EX 20 - União de Listas Ordenadas
//No* unir_listas_ordenadas(No* l1, No* l2) {
    //if (!l1) return l2;
    //if (!l2) return l1;
    //if (l1->dado < l2->dado) {
        //l1->prox = unir_listas_ordenadas(l1->prox, l2);
        //return l1;
    //} else {
        //l2->prox = unir_listas_ordenadas(l1, l2->prox);
        //return l2;
    //}
//}

// ------------------------ EX 21 - Remoção de Todas as Ocorrências
void remover_todas_ocorrencias(No** lista, int valor) {
    No* atual = *lista;
    No* anterior = NULL;

    while (atual != NULL) {
        if (atual->dado == valor) {
            if (anterior == NULL) {
                // O nó a ser removido é o primeiro
                *lista = atual->prox;
                free(atual);
                atual = *lista;
            } else {
                // O nó está no meio ou no fim
                anterior->prox = atual->prox;
                free(atual);
                atual = anterior->prox;
            }
        } else {
            anterior = atual;
            atual = atual->prox;
        }
    }
}

// ------------------------ EX 22 - Intersecção de Listas:
//No* encontrar_intersecao(No* l1, No* l2) {
    //No* a = l1;
    //No* b = l2;
    //while (a != b) {
        //a = (a == NULL) ? l2 : a->prox;
        //b = (b == NULL) ? l1 : b->prox;
    //}
    //return a;
//}

// ------------------------ EX 23 - Rotação de Lista
//void rotacionar_lista(No** lista, int k) {
    //if (!*lista || k == 0) return;
    //No* temp = *lista;
    //int tamanho = 1;
    //while (temp->prox != NULL) {
        //temp = temp->prox;
        //tamanho++;
    //}
    //temp->prox = *lista; // conecta o fim ao início

    //k = k % tamanho;
    //for (int i = 0; i < tamanho - k; i++) {
        //temp = temp->prox;
    //}
    //*lista = temp->prox;
    //temp->prox = NULL;
//}

// ------------------------ EX 24 - Pilha com Mínimo em O(1)
//typedef struct {
    //int itens[MAX];
    //int minimos[MAX];
    //int topo;
//} PilhaMin;

//void inicializar_pilha_min(PilhaMin* p) {
    //p->topo = -1;
//}

//void push_min(PilhaMin* p, int valor) {
    //if (p->topo < MAX - 1) {
        //p->itens[++p->topo] = valor;
        //if (p->topo == 0) {
            //p->minimos[p->topo] = valor;
        //} else {
            //int min = (valor < p->minimos[p->topo - 1]) ? valor : p->minimos[p->topo - 1];
            //p->minimos[p->topo] = min;
        //}
    //}
//}

//int pop_min(PilhaMin* p) {
    //if (p->topo >= 0) return p->itens[p->topo--];
    //return -1;
//}

//int obter_minimo(PilhaMin* p) {
    //if (p->topo >= 0) return p->minimos[p->topo];
    //return -1;
//}

// ------------------------ EX 25 - Duas Pilhas em um Array
//typedef struct {
    //int itens[MAX];
    //int topo1;
    //int topo2;
//} DuasPilhas;

//void inicializar_duas_pilhas(DuasPilhas* p) {
    //p->topo1 = -1;
    //p->topo2 = MAX;
//}

//void push1(DuasPilhas* p, int valor) {
    //if (p->topo1 < p->topo2 - 1) {
        //p->itens[++p->topo1] = valor;
    //}
//}

//void push2(DuasPilhas* p, int valor) {
    //if (p->topo1 < p->topo2 - 1) {
        //p->itens[--p->topo2] = valor;
    //}
//}

//int pop1(DuasPilhas* p) {
    //return (p->topo1 >= 0) ? p->itens[p->topo1--] : -1;
//}

//int pop2(DuasPilhas* p) {
    //return (p->topo2 < MAX) ? p->itens[p->topo2++] : -1;
//}

// ------------------------ EX 26 - Avaliação de Expressão Pós-fixa
//int avaliar_posfixa(const char* expr) {
    //PilhaArray p;
    //inicializar_pilha(&p);
    //char* token = strtok((char*)expr, " ");
    //while (token != NULL) {
        //if (isdigit(token[0])) {
            //push(&p, atoi(token));
        //} else {
            //int b = pop(&p);
            //int a = pop(&p);
            //switch (token[0]) {
                //case '+': push(&p, a + b); break;
                //case '-': push(&p, a - b); break;
                //case '*': push(&p, a * b); break;
                //case '/': push(&p, a / b); break;
            //}
        //}
        //token = strtok(NULL, " ");
    //}
    //return pop(&p);
//}

// ------------------------ EX 27 - Fila usando Duas Pilhas
//typedef struct {
    //PilhaArray entrada;
    //PilhaArray saida;
//} FilaDuasPilhas;

//void inicializar_fila_duas_pilhas(FilaDuasPilhas* f) {
    //inicializar_pilha(&f->entrada);
    //inicializar_pilha(&f->saida);
//}

//void enfileirar_duas_pilhas(FilaDuasPilhas* f, int valor) {
    //push(&f->entrada, valor);
//}

//int desenfileirar_duas_pilhas(FilaDuasPilhas* f) {
    //if (esta_vazia(&f->saida)) {
        //while (!esta_vazia(&f->entrada)) {
            //push(&f->saida, pop(&f->entrada));
        //}
    //}
    //return pop(&f->saida);
//}

// ------------------------ EX 28 - Inversão em Grupos de K Nós
//No* inverter_grupos(No* cabeca, int k) {
    //No* atual = cabeca;
    //No* prev = NULL;
    //No* prox = NULL;
    //int contador = 0;

    //No* temp = cabeca;
    //for (int i = 0; i < k && temp != NULL; i++) {
        //temp = temp->prox;
        //contador++;
    //}

    //if (contador < k) return cabeca;

    //contador = 0;
    //while (contador < k && atual != NULL) {
        //prox = atual->prox;
        //atual->prox = prev;
        //prev = atual;
        //atual = prox;
        //contador++;
    //}
    //if (prox != NULL) {
        //cabeca->prox = inverter_grupos(prox, k);
    //}
    //return prev;
//}

// ------------------------ EX 29 - Palíndromo com Espaço O(1)
//int eh_palindromo(No* lista) {
    //if (!lista || !lista->prox) return 1;

    //No* lento = lista;
    //No* rapido = lista;
    //No* prev = NULL;
    //No* temp;

    // Encontrar o meio e inverter a primeira metade
    //while (rapido && rapido->prox) {
        //rapido = rapido->prox->prox;

        //temp = lento->prox;
        //lento->prox = prev;
        //prev = lento;
        //lento = temp;
    //}

    //No* segunda_metade = (rapido == NULL) ? lento : lento->prox;
    //No* primeira_metade = prev;

    //while (primeira_metade && segunda_metade) {
        //if (primeira_metade->dado != segunda_metade->dado) return 0;
        //primeira_metade = primeira_metade->prox;
        //segunda_metade = segunda_metade->prox;
    //}
    //return 1;
//}

// ------------------------ EX 30 - Trapping Rain Water
//int trapping_rain_water(int* arr, int n) {
    //int esquerda[n], direita[n];
    //int agua = 0;

    //esquerda[0] = arr[0];
    //for (int i = 1; i < n; i++) {
        //esquerda[i] = (arr[i] > esquerda[i-1]) ? arr[i] : esquerda[i-1];
    //}

    //direita[n-1] = arr[n-1];
    //for (int i = n-2; i >= 0; i--) {
        //direita[i] = (arr[i] > direita[i+1]) ? arr[i] : direita[i+1];
    //}

    //for (int i = 0; i < n; i++) {
        //int min = (esquerda[i] < direita[i]) ? esquerda[i] : direita[i];
        //agua += min - arr[i];
    //}
    //return agua;
//}
