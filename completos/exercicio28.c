#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 7
#define RESTAURANTE 39028
#define HOTEL 9439
#define OUTRO 74893

typedef struct s {

    int adj;
    struct s * prox;

} no;

typedef struct {

    int flag;
    int estabelecimento;
    no * inicio;

} vertice;

typedef struct {

    no * inicio;
    no * fim;

} fila;

vertice * criaLista(int v) {

    vertice * g = (vertice *) malloc(sizeof(vertice) * (v+1)); 

    for(int i = 1; i <= v; i++) {

        g[i].flag = 0;
        g[i].estabelecimento = -1;
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

void inicializarFila(fila * f) {

    f->inicio = NULL;
    f->fim = NULL;

}

void entrarFila(fila * f, int n) {

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

int sairFila(fila * f) {

    if(!f->inicio) {
        return -1;
    }

    no * aux;

    int n = f->inicio->adj;

    aux = f->inicio;

    f->inicio = f->inicio->prox;

    free(aux);

    if(!f->inicio) {
        f->fim = NULL;
    }

    return n;

}

int estabelecimentoMaisProximo(vertice * g, int i, int e) {

    fila f;
    inicializarFila(&f);
    entrarFila(&f, i);
    g[i].flag = 1;

    while(f.inicio) {

        i = sairFila(&f);
        g[i].flag = 2;
        no * p = g[i].inicio;

        while(p) {

            if(g[p->adj].estabelecimento == e) {
                return p->adj;
            }

            if(g[p->adj].flag == 0) {
                entrarFila(&f, p->adj);
                g[p->adj].flag = 1;
            }

            p = p->prox;

        }


    }

}

int main() {

    vertice * g = criaLista(V);

    inserirAresta(g, 1, 2);
    inserirAresta(g, 1, 3);

    inserirAresta(g, 2, 4);

    inserirAresta(g, 4, 5);

    inserirAresta(g, 3, 6);

    inserirAresta(g, 6, 7);

    g[1].estabelecimento = OUTRO;
    g[2].estabelecimento = OUTRO;
    g[3].estabelecimento = OUTRO;
    g[4].estabelecimento = RESTAURANTE;
    g[5].estabelecimento = HOTEL;
    g[6].estabelecimento = HOTEL;
    g[7].estabelecimento = RESTAURANTE;

    printf("%d\n", estabelecimentoMaisProximo(g, 1, RESTAURANTE));

}