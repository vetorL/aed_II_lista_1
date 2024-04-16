#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 6

typedef struct s {
    int adj;
    struct s * prox;
} no;

typedef struct {
    int flag;
    no * inicio;
} vertice;

vertice * criaGrafo(int v);
bool inserirAresta(vertice * g, int i, int j);
void prof(vertice * g, int i, int j, bool * achou);

int main() {
    vertice * g = criaGrafo(V);

    inserirAresta(g, 1, 3);
    inserirAresta(g, 1, 5);
    inserirAresta(g, 1, 6);
    inserirAresta(g, 2, 5);
    inserirAresta(g, 2, 6);
    inserirAresta(g, 3, 4);
    inserirAresta(g, 3, 5);
    inserirAresta(g, 5, 6);

    bool achou = false;

    // caminho entre 1 e 4
    int i = 1;
    int j = 4;

    prof(g, i, j, &achou);

    if(achou) {
        puts("EXISTE CAMINHO");
    } else {
        puts("NAO EXISTE CAMINHO");
    }
}

vertice * criaGrafo(int v) {
    vertice * g = (vertice *) malloc(sizeof(vertice) * (v+1));

    for(int i = 1; i <= v; i++) {
        g[i].flag = 0;
        g[i].inicio = NULL;
    }

    return g;
}

bool inserirAresta(vertice * g, int i, int j) {
    // if(arestaExiste(g, i, j)) {
    //     return false;
    // }

    no * novo = (no *) malloc(sizeof(no));

    novo->adj = j;
    novo->prox = g[i].inicio;

    g[i].inicio = novo;

    return true;
}

void prof(vertice * g, int i, int j, bool * achou) {
    if(*achou) {
        return;
    }

    g[i].flag = 1;
    no * p = g[i].inicio;

    while(p) {
        if(g[p->adj].flag == 0) {
            if(p->adj == j) {
                *achou = true;
                return;
            }

            prof(g, p->adj, j, achou);
        }

        p = p->prox;
    }

    g[i].flag = 2;
}