#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define V 6

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

int main() {

    vertice * g = criaLista(V);

    g[1].ocupacao = 15;
    g[2].ocupacao = 10;
    g[3].ocupacao = 20;
    g[4].ocupacao = 0;
    g[5].ocupacao = 30;
    g[6].ocupacao = 0;

    inserirAresta(g, 1, 2);
    inserirAresta(g, 2, 4);
    inserirAresta(g, 1, 3);
    inserirAresta(g, 3, 5);
    inserirAresta(g, 5, 6);

    printf("A sala vazia mais proxima eh a %d\n", salaVaziaMaisProxima(g, 1));

}

int salaVaziaMaisProxima(vertice * g, int i) {



}