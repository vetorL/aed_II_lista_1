#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 6

typedef struct s {

    int adj;
    int contador;
    struct s * prox;

} no;

typedef struct {

    int flag;
    int dist;
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
        g[i].dist = -1;
        g[i].inicio = NULL;

    }

    return g;

}

void inserirAresta(vertice * g, int i, int j, int mensagensEnviadas) {

    no * novo = (no *) malloc(sizeof(no));

    novo->adj = j;
    novo->contador = mensagensEnviadas; 
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

no * largura(vertice * g, int i, int k) {

    no * resp;

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
                g[p->adj].dist = g[i].dist + 1;

                if(g[p->adj].dist > 1) {
                    return resp;
                }

                if(p->contador >= k) {

                    printf("%d\n", p->adj);

                    no * novo = (no *) malloc(sizeof(no));

                    novo->adj = p->adj;
                    novo->prox = resp;

                    resp = novo;

                }

            }

            p = p->prox;

        }

    }

    return resp;

}

int main() {

    vertice * g = criaLista(V);

    inserirAresta(g, 1, 2, 5);
    inserirAresta(g, 2, 1, 20);

    inserirAresta(g, 1, 3, 1);

    inserirAresta(g, 1, 4, 12);

    inserirAresta(g, 1, 5, 8);

    inserirAresta(g, 2, 6, 15);

    int i = 1;
    int k = 10;
    g[i].dist = 0;

    no * resp = largura(g, i, k);

    // while(resp) {

    //     printf("%d", resp->adj);
    //     resp = resp->prox;

    // }


    puts("");

}