#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 3

typedef struct s {

    int adj;
    int custo;
    struct s * prox;

} no;

typedef struct {

    int flag;
    int custoTotal;
    int populacao;
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
        g[i].custoTotal = 0;
        g[i].populacao = 0;
        g[i].inicio = NULL;

    }

    return g;
    
}

void inserirAresta(vertice * g, int i, int j, int custoPedagio) {

    no * novo = (no *) malloc(sizeof(no));

    novo->adj = j;
    novo->custo = custoPedagio;
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

int largura(vertice * g, int i) {

    fila f;
    inicializarFila(&f);
    entrarFila(&f, i);
    g[i].flag = 1;

    while(f.inicio) {

        i = sairFila(&f);
        g[i].flag = 2;
        no * p = g[i].inicio;

        while(p) {

            if(g[p->adj].flag == 0) {
                entrarFila(&f, p->adj);
                g[p->adj].flag = 1;
                g[p->adj].custoTotal = g[i].custoTotal + p->custo;
            }

            if(g[p->adj].populacao >= 1000) {
                return g[p->adj].custoTotal;
            }

            p = p->prox;

        }

    }

}

int main() {

    vertice * g = criaLista(V);

    inserirAresta(g, 1, 2, 10);
    inserirAresta(g, 2, 3, 25);

    g[1].populacao = 500;
    g[2].populacao = 50;
    g[3].populacao = 5000;

    printf("%d eh o custo \n", largura(g, 1));

}