#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct s {

    int adj;
    struct s * prox;

} no;

typedef struct {

    no * inicio;

} vertice;

vertice * criaGrafo(int v);
void inserirAresta(vertice * g, int i, int j);
void exibir(vertice * g, int v);
bool arestaExiste(vertice * g, int i, int j, int v2);
vertice * g1_menos_g2(vertice * g1, vertice * g2, int v1, int v2);

int main() {

    // Cria g1
    int v1 = 3; // numero de vertices de g1
    vertice * g1 = criaGrafo(v1);
    inserirAresta(g1, 1, 2);
    inserirAresta(g1, 1, 3);
    inserirAresta(g1, 3, 2);
    printf("=== g1 ===\n");
    exibir(g1, v1);

    // Cria g2
    int v2 = 2;
    vertice * g2 = criaGrafo(v2);
    inserirAresta(g2, 1, 2);
    printf("=== g2 ===\n");
    exibir(g2, v2);

    // Subtrai os dois e obtem g3
    vertice * g3 = g1_menos_g2(g1, g2, v1, v2);
    printf("=== g3 ===\n");
    exibir(g3, v1);

}

vertice * criaGrafo(int v) {

    vertice * g = (vertice*) malloc(sizeof(vertice) * (v+1));

    for(int i = 0; i <= v; i++) {

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

vertice * g1_menos_g2(vertice * g1, vertice * g2, int v1, int v2) {

    vertice * g3 = criaGrafo(v1);

    // checa se uma aresta que existe em g1 tambem existe em g2
    // se nao existir, adicionar em g3

    for(int i = 1; i <= v1; i++) {

        no * p = g1[i].inicio;

        while(p) {

            int j = p->adj;

            p = p->prox;

            if(arestaExiste(g2, i, j, v2)) {
                continue;
            }

            inserirAresta(g3, i, j);

        }

    }

    return g3;

}

void exibir(vertice * g, int v) {

    for(int i = 1; i <= v; i++) {

        printf("%d ==>", i);

        no * p = g[i].inicio;

        while(p) {
            printf(" %d", p->adj);
            p = p->prox;
        }

        printf("\n");

    }

}

bool arestaExiste(vertice * g, int i, int j, int v2) {

    if(i > v2) {
        return false;
    }

    no * p = g[i].inicio;

    while(p) {

        if(p->adj == j) {
            return true;
        }

        p = p->prox;

    }

    return false;

}