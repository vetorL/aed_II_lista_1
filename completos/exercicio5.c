// Exercicio 5

// Escreva um algoritmo que dado um grafo m representado em matriz, retorne o
// mesmo grafo em listas de adjacencias.

#define V 5 // numero de vertices do grafo

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s {

    int adj;

    struct s * prox;

} no;

typedef struct {

    no * inicio;

} vertice;

void zeraMatriz(int m[V+1][V+1]);
void inserirArestaMatriz(int m[V+1][V+1], int i, int j);
void zeraLista(vertice * g);
bool inserirArestaLista(vertice * g, int i, int j);
bool arestaExiste(vertice * g, int i, int j);
void exibirLista(vertice * g, int v);

int main() {

    // # Cria o grafo representado em matriz

    int m[V+1][V+1]; // aloca o espaco em memoria para a matriz

    zeraMatriz(m); // zera a matriz

    // Inseri as arestas do grafo na matriz

    inserirArestaMatriz(m, 1, 4);
    inserirArestaMatriz(m, 1, 3);
    inserirArestaMatriz(m, 2, 1);
    inserirArestaMatriz(m, 2, 5);
    inserirArestaMatriz(m, 3, 5);

    // # Transforma o grafo representado em matriz em grafo de lista de adjacencias

    vertice * g = (vertice *) malloc(sizeof(vertice)*(V+1));

    zeraLista(g);

    // loop que passa por todas as casas da matriz
    for(int i = 0; i <= V; i++) {

        for(int j = 0; j <= V; j++) {

            // identifica as arestas presentes na matriz e inseri elas na lista
            if(m[i][j] == 1) {

                inserirArestaLista(g, i, j);

            }

        }

    }

    // # Exibe o grafo em lista de adjacencias
    exibirLista(g, V);

}

void zeraMatriz(int m[V+1][V+1]) {

    // loop que passa por todas as casas da matriz
    for(int i = 0; i <= V; i++) {

        for(int j = 0; j <= V; j++) {

            m[i][j] = 0;

        }

    }

}

void inserirArestaMatriz(int m[V+1][V+1], int i, int j) {

    m[i][j] = 1;

}

void zeraLista(vertice * g) {

    for(int i = 0; i <= V; i++) {

        g[i].inicio =  NULL;

    }

}

bool inserirArestaLista(vertice * g, int i, int j) {

    if(arestaExiste(g, i, j)) {

        return false;

    }

    no * novo = (no *) malloc(sizeof(no));
    novo->adj = j;
    novo->prox = g[i].inicio;

    g[i].inicio = novo;

    return true;

}

bool arestaExiste(vertice * g, int i, int j) {

    no * p = g[i].inicio;

    while(p) {

        if(p->adj == j) {

            return true;

        }

        p = p->prox;

    }

    return false;

}

void exibirLista(vertice * g, int v) {

    for(int i = 1; i<= v; i++) {

        printf("%d ==>", i);

        no * p = g[i].inicio;

        while(p) {

            printf(" %d", p->adj);

            p=p->prox;

        }

        printf("\n");

    }

}