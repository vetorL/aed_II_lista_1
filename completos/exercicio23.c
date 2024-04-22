#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define V 8

typedef struct s {

    int adj;
    struct s * prox;

} no;

typedef struct {

    int flag;
    int ocupacao;
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
        g[i].ocupacao = -1;
        g[i].dist = 999;
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

    int n = f->inicio->adj;

    no * aux = f->inicio;

    f->inicio = f->inicio->prox;

    free(aux);

    if(!f->inicio) {
        f->fim = NULL;
    }

    return n;

}

no * largura(vertice * g, int i) {

    no * resp;

    fila f;
    inicializarFila(&f);
    entrarFila(&f, i);
    g[i].flag = 1;
    g[i].dist = 0;

    while(f.inicio) {
        i = sairFila(&f);
        g[i].flag = 2;
        no * p = g[i].inicio;

        if(g[i].ocupacao == 0) {

            if(resp) {
                if(g[i].dist != g[resp->adj].dist) {
                    return resp;
                }
            }

            no * n = (no *) malloc(sizeof(no));

            no * aux = resp;

            n->adj = i;
            n->prox = NULL;

            if(resp) {
                resp = n;
                n->prox = aux;
            } else {
                resp = n;
            }

        }

        while(p) {
            
            if(g[p->adj].flag == 0) {
                entrarFila(&f, p->adj);
                g[p->adj].dist = g[i].dist + 1;
                g[p->adj].flag = 1;
            }

            p = p->prox;

        }

    }

    return resp;

}

int main() {

    vertice * g = criaLista(V);

    inserirAresta(g, 1, 2);
    inserirAresta(g, 1, 3);
    inserirAresta(g, 3, 4);
    inserirAresta(g, 2, 5);
    inserirAresta(g, 1, 6);
    inserirAresta(g, 6, 7);
    inserirAresta(g, 7, 8);


    g[1].ocupacao = 10;
    g[2].ocupacao = 15;
    g[3].ocupacao = 20;
    g[4].ocupacao = 0;
    g[5].ocupacao = 0;
    g[6].ocupacao = 35;
    g[7].ocupacao = 715;
    g[8].ocupacao = 0;

    // essa combinacao deve retornar uma lista ligada com os vertices 4 e 5

    no * resp = largura(g, 1);

    while(resp) {
        printf("%d ", resp->adj);
        resp = resp->prox;
    }

    puts("");

}