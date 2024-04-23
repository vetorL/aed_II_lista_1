#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define V 4
#define LATAM 320
#define GOL 737

typedef struct s {

    int adj;
    int cia;
    struct s * prox;

} no;

typedef struct {

    int flag;
    int via;
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
        g[i].via = -1;
        g[i].inicio = NULL;

    }

    return g;

}

void inserirAresta(vertice * g, int i, int j, int c) {

    no * novo = (no *) malloc(sizeof(no));

    novo->adj = j;
    novo->cia = c;
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

    int n = f->inicio->adj;

    no * aux = f->inicio;

    f->inicio = f->inicio->prox;

    free(aux);

    if(!f->inicio) {
        f->fim = NULL;
    }

    return n;

}

void largura(vertice * g, int i, int j, int c) {

    fila f;
    inicializarFila(&f);
    entrarFila(&f, i);
    g[i].flag = 1;

    while(f.inicio) {

        i = sairFila(&f);
        g[i].flag = 2;
        no * p = g[i].inicio;

        while(p) {

            if(g[p->adj].flag == 0 && p->cia == c) {
                g[p->adj].via = i;
                if(p->adj == j) {
                    return;
                }
                entrarFila(&f, p->adj);
                g[p->adj].flag = 1;
            }

            p = p->prox;

        }

    }

}

void exibir(vertice * g, int v) {

    for(int i = 1; i <= v; i++) {

        printf("%d (%d) ==>", i, g[i].via);

        puts("");

    }

}

no * caminhoUsado(vertice * g, int b) {

    no * resp;

    int via = b;

    while(via != -1) {
        no * novo = (no *) malloc(sizeof(no));

        printf("%d ", via);

        novo->adj = via;
        novo->prox = resp;

        resp = novo;

        via = g[via].via;
    }

    puts("");

    return resp;

}

int main() {

    vertice * g = criaLista(V);

    inserirAresta(g, 1, 2, LATAM);
    inserirAresta(g, 1, 3, GOL);
    inserirAresta(g, 2, 3, LATAM);
    inserirAresta(g, 3, 4, LATAM);
    inserirAresta(g, 3, 4, GOL);
    inserirAresta(g, 2, 4, GOL);

    int a = 1;
    int b = 4;

    largura(g, a, b, GOL);

    caminhoUsado(g, b);

    puts("");

}