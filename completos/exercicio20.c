#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define V 3

typedef struct s {

    int adj;
    struct s * prox;

} no;

typedef struct {

    no * inicio;

} vertice;

vertice * criaLista(int v) {

    vertice * g = (vertice *) malloc(sizeof(vertice) * (v+1));

    for(int i = 1; i <= v ; i++) {

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

void inserirArestaND(vertice * g, int i, int j) {

    inserirAresta(g, i, j);
    inserirAresta(g, j, i);

}

bool ehCompleto(vertice * g, int v) {

    for(int i = 1; i <= v; i++) {

        int numeroDeAdjacentes = 1;

        no * p = g[i].inicio;

        while(p) {
            numeroDeAdjacentes += 1;
            p = p->prox;
        }

        if(numeroDeAdjacentes < v) {
            return false;
        }

    }

    return true;

}

int main() {

    vertice * g = criaLista(V);

    inserirArestaND(g, 1, 2);
    inserirArestaND(g, 1, 3);
    inserirArestaND(g, 2, 3);

    if(ehCompleto(g, V)) {
        puts("Grafo eh completo");
    } else {
        puts("NAO EH COMPLETO");
    }

}