#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ============================
// Estruturas para Lista
// ============================

typedef struct No {
    int dado;
    struct No* prox;
} No;

// ============================
// Lista Encadeada Simples
// ============================

No* criar_no(int dado) {
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = dado;
    novo->prox = NULL;
    return novo;
}

void inserir_inicio(No** lista, int dado) {
    No* novo = criar_no(dado);
    novo->prox = *lista;
    *lista = novo;
}

void inserir_fim(No** lista, int dado) {
    No* novo = criar_no(dado);
    if (*lista == NULL) {
        *lista = novo;
        return;
    }
    No* atual = *lista;
    while (atual->prox != NULL) atual = atual->prox;
    atual->prox = novo;
}

void inserir_posicao(No** lista, int dado, int pos) {
    if (pos == 0) {
        inserir_inicio(lista, dado);
        return;
    }
    No* atual = *lista;
    for (int i = 0; atual != NULL && i < pos - 1; i++)
        atual = atual->prox;
    if (atual == NULL) return;
    No* novo = criar_no(dado);
    novo->prox = atual->prox;
    atual->prox = novo;
}

int contar_nos(No* lista) {
    int cont = 0;
    while (lista) {
        cont++;
        lista = lista->prox;
    }
    return cont;
}

int buscar_elemento(No* lista, int dado) {
    while (lista) {
        if (lista->dado == dado) return 1;
        lista = lista->prox;
    }
    return 0;
}

void remover_valor(No** lista, int dado) {
    No* atual = *lista;
    No* anterior = NULL;
    while (atual) {
        if (atual->dado == dado) {
            if (anterior) anterior->prox = atual->prox;
            else *lista = atual->prox;
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
}

void remover_todas_ocorrencias(No** lista, int dado) {
    while (*lista && (*lista)->dado == dado) {
        No* temp = *lista;
        *lista = (*lista)->prox;
        free(temp);
    }
    No* atual = *lista;
    while (atual && atual->prox) {
        if (atual->prox->dado == dado) {
            No* temp = atual->prox;
            atual->prox = temp->prox;
            free(temp);
        } else {
            atual = atual->prox;
        }
    }
}

void inverter_lista(No** lista) {
    No* prev = NULL;
    No* atual = *lista;
    No* prox = NULL;
    while (atual) {
        prox = atual->prox;
        atual->prox = prev;
        prev = atual;
        atual = prox;
    }
    *lista = prev;
}

No* encontrar_meio(No* lista) {
    No* lento = lista;
    No* rapido = lista;
    while (rapido && rapido->prox) {
        rapido = rapido->prox->prox;
        lento = lento->prox;
    }
    return lento;
}

void imprimir(No* lista) {
    while (lista) {
        printf("%d -> ", lista->dado);
        lista = lista->prox;
    }
    printf("NULL\n");
}

// Impressão reversa com pilha
void imprimir_reversa(No* lista) {
    int pilha[100];
    int topo = -1;
    while (lista) {
        pilha[++topo] = lista->dado;
        lista = lista->prox;
    }
    while (topo >= 0) {
        printf("%d -> ", pilha[topo--]);
    }
    printf("NULL\n");
}

// ============================
// Pilha com Array
// ============================

typedef struct {
    int dados[100];
    int topo;
} PilhaArray;

void inicializar_pilha_array(PilhaArray* p) {
    p->topo = -1;
}

int esta_vazia(PilhaArray* p) {
    return p->topo == -1;
}

void push(PilhaArray* p, int valor) {
    p->dados[++p->topo] = valor;
}

int pop(PilhaArray* p) {
    return p->dados[p->topo--];
}

int topo(PilhaArray* p) {
    return p->dados[p->topo];
}

// ============================
// Pilha com Lista Encadeada
// ============================

typedef struct NoPilha {
    int dado;
    struct NoPilha* prox;
} NoPilha;

typedef struct {
    NoPilha* topo;
} PilhaLista;

PilhaLista* criar_pilha_lista() {
    PilhaLista* p = (PilhaLista*)malloc(sizeof(PilhaLista));
    p->topo = NULL;
    return p;
}

void push_lista(PilhaLista* p, int dado) {
    NoPilha* novo = (NoPilha*)malloc(sizeof(NoPilha));
    novo->dado = dado;
    novo->prox = p->topo;
    p->topo = novo;
}

int pop_lista(PilhaLista* p) {
    if (!p->topo) return -1;
    NoPilha* temp = p->topo;
    int valor = temp->dado;
    p->topo = temp->prox;
    free(temp);
    return valor;
}

int topo_lista(PilhaLista* p) {
    if (!p->topo) return -1;
    return p->topo->dado;
}

// ============================
// Balanceamento de Parênteses
// ============================

int verificar_balanceamento(const char* str) {
    char pilha[100];
    int topo = -1;
    for (int i = 0; str[i]; i++) {
        char c = str[i];
        if (c == '(' || c == '{' || c == '[')
            pilha[++topo] = c;
        else if (c == ')' || c == '}' || c == ']') {
            if (topo == -1) return 0;
            char topoChar = pilha[topo--];
            if ((c == ')' && topoChar != '(') ||
                (c == '}' && topoChar != '{') ||
                (c == ']' && topoChar != '['))
                return 0;
        }
    }
    return topo == -1;
}

// ============================
// Inversão de String com Pilha
// ============================

void inverter_string(char* str) {
    char pilha[100];
    int topo = -1;
    for (int i = 0; str[i]; i++)
        pilha[++topo] = str[i];
    for (int i = 0; i <= topo; i++)
        str[i] = pilha[topo - i];
}

// ============================
// Verificação de Palíndromo
// ============================

int eh_palindromo(const char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        if (str[i] != str[n - i - 1])
            return 0;
    }
    return 1;
}

// ============================
// Ordenação de Pilha
// ============================

void ordenar_pilha(PilhaArray* p) {
    PilhaArray aux;
    inicializar_pilha_array(&aux);
    while (!esta_vazia(p)) {
        int temp = pop(p);
        while (!esta_vazia(&aux) && topo(&aux) > temp)
            push(p, pop(&aux));
        push(&aux, temp);
    }
    while (!esta_vazia(&aux))
        push(p, pop(&aux));
}

// ============================
// Fila com Array Circular
// ============================

typedef struct {
    int dados[100];
    int frente, tras, tamanho;
} FilaArray;

void inicializar_fila_array(FilaArray* f) {
    f->frente = 0;
    f->tras = -1;
    f->tamanho = 0;
}

int fila_vazia(FilaArray* f) {
    return f->tamanho == 0;
}

void enfileirar(FilaArray* f, int valor) {
    if (f->tamanho == 100) return;
    f->tras = (f->tras + 1) % 100;
    f->dados[f->tras] = valor;
    f->tamanho++;
}

int desenfileirar(FilaArray* f) {
    if (fila_vazia(f)) return -1;
    int valor = f->dados[f->frente];
    f->frente = (f->frente + 1) % 100;
    f->tamanho--;
    return valor;
}

int frente(FilaArray* f) {
    if (fila_vazia(f)) return -1;
    return f->dados[f->frente];
}

// ============================
// Fila com Lista Encadeada
// ============================

typedef struct NoFila {
    int dado;
    struct NoFila* prox;
} NoFila;

typedef struct {
    NoFila* frente;
    NoFila* tras;
} FilaLista;

FilaLista* criar_fila_lista() {
    FilaLista* f = (FilaLista*)malloc(sizeof(FilaLista));
    f->frente = f->tras = NULL;
    return f;
}

void enfileirar_lista(FilaLista* f, int dado) {
    NoFila* novo = (NoFila*)malloc(sizeof(NoFila));
    novo->dado = dado;
    novo->prox = NULL;
    if (f->tras) f->tras->prox = novo;
    else f->frente = novo;
    f->tras = novo;
}

int desenfileirar_lista(FilaLista* f) {
    if (!f->frente) return -1;
    NoFila* temp = f->frente;
    int dado = temp->dado;
    f->frente = temp->prox;
    if (!f->frente) f->tras = NULL;
    free(temp);
    return dado;
}

int frente_lista(FilaLista* f) {
    return f->frente ? f->frente->dado : -1;
}

// ============================
// Detecção de Ciclo
// ============================

int detectar_ciclo(No* lista) {
    No* lento = lista;
    No* rapido = lista;
    while (rapido && rapido->prox) {
        lento = lento->prox;
        rapido = rapido->prox->prox;
        if (lento == rapido) return 1;
    }
    return 0;
}

// ============================
// União de Listas Ordenadas
// ============================

No* unir_listas_ordenadas(No* l1, No* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    if (l1->dado < l2->dado) {
        l1->prox = unir_listas_ordenadas(l1->prox, l2);
        return l1;
    } else {
        l2->prox = unir_listas_ordenadas(l1, l2->prox);
        return l2;
    }
}

// ============================
// Intersecção de Listas
// ============================

No* encontrar_intersecao(No* l1, No* l2) {
    No* a = l1;
    No* b = l2;
    while (a != b) {
        a = a ? a->prox : l2;
        b = b ? b->prox : l1;
    }
    return a;
}

// ============================
// Rotação de Lista
// ============================

void rotacionar_lista(No** lista, int k) {
    if (!*lista || k == 0) return;
    int tamanho = contar_nos(*lista);
    k = k % tamanho;
    if (k == 0) return;

    No* atual = *lista;
    int count = 1;
    while (count < tamanho - k && atual) {
        atual = atual->prox;
        count++;
    }

    No* novo_inicio = atual->prox;
    atual->prox = NULL;

    No* temp = novo_inicio;
    while (temp->prox) temp = temp->prox;
    temp->prox = *lista;
    *lista = novo_inicio;
}

// ============================
// Inversão em Grupos de K
// ============================

void inverter_grupos(No** lista, int k) {
    No* atual = *lista;
    No* prev = NULL;
    No* prox = NULL;
    int count = 0;

    No* temp = atual;
    for (int i = 0; i < k && temp; i++) {
        temp = temp->prox;
        count++;
    }
    if (count < k) return;

    count = 0;
    while (atual && count < k) {
        prox = atual->prox;
        atual->prox = prev;
        prev = atual;
        atual = prox;
        count++;
    }

    if (prox)
        (*lista)->prox = prox, inverter_grupos(&((*lista)->prox), k);

    *lista = prev;
}

// ============================
// Palíndromo em Lista
// ============================

int eh_palindromo_lista(No* lista) {
    No* meio = encontrar_meio(lista);
    No* segundo = meio;
    inverter_lista(&segundo);

    No* p1 = lista;
    No* p2 = segundo;
    int palindromo = 1;
    while (p2) {
        if (p1->dado != p2->dado) {
            palindromo = 0;
            break;
        }
        p1 = p1->prox;
        p2 = p2->prox;
    }
    inverter_lista(&segundo);
    return palindromo;
}

// ============================
// Trapping Rain Water
// ============================

int trapping_rain_water(int* altura, int tamanho) {
    if (tamanho == 0) return 0;
    int esquerda[tamanho], direita[tamanho];
    esquerda[0] = altura[0];
    for (int i = 1; i < tamanho; i++)
        esquerda[i] = (altura[i] > esquerda[i - 1]) ? altura[i] : esquerda[i - 1];

    direita[tamanho - 1] = altura[tamanho - 1];
    for (int i = tamanho - 2; i >= 0; i--)
        direita[i] = (altura[i] > direita[i + 1]) ? altura[i] : direita[i + 1];

    int agua = 0;
    for (int i = 0; i < tamanho; i++) {
        int min = esquerda[i] < direita[i] ? esquerda[i] : direita[i];
        agua += min - altura[i];
    }
    return agua;
}

// ============================
// Gerar Números Binários
// ============================

void gerar_numeros_binarios(int n) {
    FilaArray f;
    inicializar_fila_array(&f);
    enfileirar(&f, 1);
    for (int i = 0; i < n; i++) {
        int num = desenfileirar(&f);
        printf("%d ", num);
        enfileirar(&f, num * 10);
        enfileirar(&f, num * 10 + 1);
    }
    printf("\n");
}
