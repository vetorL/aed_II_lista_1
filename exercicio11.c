#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct s {

    int adj;
    struct s * prox;
} no;

typedef struct {

    no * inicio;
    int pais;

} vertice;

#define V 4
#define ALEMANHA 517
#define EUA 911
#define BRASIL 55
#define IRLANDA 113

vertice * criaGrafo(int v);
bool inserirAresta(vertice * g, int i, int j);
void exibir(vertice * g, int v);

int main() {

    vertice * g = criaGrafo(V);
    g[1].pais = ALEMANHA;
    g[2].pais = EUA;
    g[3].pais = BRASIL; 
    g[4].pais = IRLANDA;

    inserirAresta(g, 1, 2);
    inserirAresta(g, 1, 3);
    inserirAresta(g, 2, 3);
    inserirAresta(g, 3, 4);
    inserirAresta(g, 4, 1);
    inserirAresta(g, 4, 2);
    inserirAresta(g, 4, 3);

    exibir(g, V);

}

vertice * criaGrafo(int v) {

    vertice * g = (vertice *) malloc(sizeof(vertice) * (v+1));

    for(int i = 0; i <= v; i++) {

        g[i].inicio = NULL; 
        g[i].pais = NULL;
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