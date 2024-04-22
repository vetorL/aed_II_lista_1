#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define ALEMANHA 1
#define BRASIL 2
#define FRANCA 3

#define V 4

typedef struct s {

    int adj;
    struct s * prox;

} no;

typedef struct {

    int flag;
    int pais;
    int numeroDeChamadasParaDiferentesPaises;
    no * inicio;    

} vertice;

vertice * criaLista(vertice * g, int v) {

    vertice * g = (vertice *) malloc(sizeof(vertice) * (v+1));

    for(int i = 1; i <= v ; i++) {

        g[i].flag = 0;
        g[i].numeroDeChamadasParaDiferentesPaises = 0;
        g[i].pais = -1;
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

int unidadeMaisChamadoraDeDiferentesPaises(vertice * g, int v) {

    int unidadeMaisChamadora = 1;

    for(int i = 1; i <= v; i++) {

        

    }

    return unidadeMaisChamadora;

}