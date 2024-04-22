#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define V 7

typedef struct s {

    int adj;
    struct s * prox;

} no;

typedef struct {

    int flag;
    int ocupacao;
    no * inicio;

} vertice;

typedef struct {
    
    no * inicio;
    no * fim;

} FILA;

void inicializarFila(FILA * f) {
    f->inicio = NULL;
    f->fim = NULL;
}

void entrarFila(int n, FILA * f) {
    no * novo = (no *) malloc(sizeof(no));

    novo->adj = n;
    novo->prox = NULL;

    if(f->fim) {
        f->fim->prox = novo;
    } else {
        f->inicio = novo;
    }

    f->fim = novo;
}

int sairFila(FILA * f) {
    no * aux;
    int n;

    if(!f->inicio) {
        return -1;
    }

    n = f->inicio->adj;
    aux = f->inicio;

    f->inicio = f->inicio->prox;

    free(aux);

    if(!f->inicio) {
        f->fim = NULL;
    }

    return n;
}

vertice * criaLista(int v) {

    vertice * g = (vertice *) malloc(sizeof(vertice) * (v+1));

    for(int i = 1; i <= v; i++) {

        g[i].flag = 0;
        g[i].ocupacao = -1;
        g[i].inicio = NULL;

    }

    return g;

}

void inserirAresta(vertice * g, int i, int j) {

    no * novo = (no *) malloc(sizeof(no));

    novo->adj = j;
    novo->prox = g[i].inicio;

    g[i].inicio = novo;

}

int salaVaziaMaisProxima(vertice * g, int i) {

    FILA f;
    inicializarFila(&f);
    entrarFila(i, &f);
    g[i].flag = 1;

    while(f.inicio) {

        i = sairFila(&f);
        g[i].flag = 2;
        no * p = g[i].inicio;

        if(g[i].ocupacao == 0) {
            return i;
        }

        while(p) {
            if(g[p->adj].flag == 0) {
                entrarFila(p->adj, &f);
                g[p->adj].flag = 1;
            }
            p = p->prox;
        }

    }

}

int main() {

    vertice * g = criaLista(V);

    g[1].ocupacao = 15;
    g[2].ocupacao = 10;
    g[3].ocupacao = 20;
    g[4].ocupacao = 0;
    g[5].ocupacao = 30;
    g[6].ocupacao = 0;
    g[7].ocupacao = 0;

    inserirAresta(g, 1, 2);
    inserirAresta(g, 1, 7);
    inserirAresta(g, 2, 4);
    inserirAresta(g, 1, 3);
    inserirAresta(g, 3, 5);
    inserirAresta(g, 5, 6);

    printf("A sala vazia mais proxima eh a %d\n", salaVaziaMaisProxima(g, 1));

}