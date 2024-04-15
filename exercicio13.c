#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 4 // numero de vertices do grafo

typedef struct s {

    int adj;
    struct s * prox;

} no;

typedef struct {

    int flag;
    no * inicio;

} vertice;

vertice * criaLista(int v);
void inserirAresta(vertice * g, int i, int j);
void exibir(vertice * g, int v);
void removerCiclo(vertice * g, int i);
no * buscaAresta(vertice * g, int i, int j, no ** ant);
bool removerAresta(vertice * g, int i, int j);

int main() {

    vertice * g = criaLista(V);

    inserirAresta(g, 1, 2);
    inserirAresta(g, 1, 4);
    inserirAresta(g, 2, 3);
    inserirAresta(g, 3, 1);
    inserirAresta(g, 4, 3);

    exibir(g, V);

    puts("========================");

    removerCiclo(g, 1);
    
    puts("========================");

    exibir(g, V);
}

vertice * criaLista(int v) {

    vertice * g = (vertice *) malloc(sizeof(vertice) * (v+1));

    for(int i = 0; i <= v; i++) {
        g[i].flag = 0;
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

void exibir(vertice * g, int v) {

    for(int i = 1; i <= v; i++) {

        no * p = g[i].inicio;

        printf("%d ==>", i);

        while(p) {

            printf(" %d", p->adj);

            p = p->prox;

        }

        printf("\n");

    }

}

void removerCiclo(vertice * g, int i) {

    g[i].flag = 1;
    no * p = g[i].inicio;

    while(p) {

        if(g[p->adj].flag == 0) {
            removerCiclo(g, p->adj);
        }

        if(g[p->adj].flag == 2) {
            printf("OCORRE CICLO\n");
            printf("Removendo ciclo que ocorre na aresta %d -> %d\n", i, p->adj);
            if(removerAresta(g, i, p->adj)) {
                return;
            }
        }

        p = p->prox;

    }

    g[i].flag = 2;

}

bool removerAresta(vertice * g, int i, int j) {

    no * ant;
    no * p = buscaAresta(g, i, j, &ant);

    if(!p) return false;

    if(ant) {
        ant->prox = p->prox;
    } else {
        g[i].inicio = p->prox;
    }

    free(p);
    
    return true;

}

no * buscaAresta(vertice * g, int i, int j, no ** ant) {

    *ant = NULL;

    no * p = g[i].inicio;

    while(p) {

        if(p->adj == j) {
            return p;
        }

        *ant = p;

        p = p->prox;

    }

    return NULL;

}