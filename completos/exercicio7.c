#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 4

typedef struct s {

    int adj;
    int custo;
    struct s * prox;

} no;

typedef struct {

    no * inicio;

} vertice;

vertice * criaLista(int v);
void inserirAresta(vertice * g, int i, int j, int custo);
void exibir(vertice * g, int v);
vertice * caminhosMaioresQueC(vertice * g, int v, int c);

int main() {

    vertice * g = criaLista(V);

    inserirAresta(g, 1, 2, 100);
    inserirAresta(g, 2, 1, 100);
    
    inserirAresta(g, 1, 3, 10);
    inserirAresta(g, 3, 1, 10);

    inserirAresta(g, 3, 4, 1);
    inserirAresta(g, 4, 3, 1);

    exibir(g, V);

    puts("=================");

    vertice * g2 = caminhosMaioresQueC(g, V, 5);

    exibir(g2, V);

}

vertice * criaLista(int v) {

    vertice * g = (vertice *) malloc(sizeof(vertice) * (v+1));

    for(int i = 1; i <= v; i++) {

        g[i].inicio = NULL;

    }

    return g;

}

void inserirAresta(vertice * g, int i, int j, int custo) {

    no * novo = (no *) malloc(sizeof(no));

    novo->adj = j;
    novo->prox = g[i].inicio;
    novo->custo = custo;

    g[i].inicio = novo;

}

vertice * caminhosMaioresQueC(vertice * g, int v, int c) {

    vertice * gResposta = (vertice *) malloc(sizeof(vertice) * (v+1));

    for(int i = 1; i <= v; i++) {

        no * p = g[i].inicio;

        while(p) {

            if(p->custo > c) {
                inserirAresta(gResposta, i, p->adj, p->custo);
            }

            p = p->prox;

        }

    }

    return gResposta;

}

void exibir(vertice * g, int v) {

    for(int i = 1; i <= v; i++) {

        printf("%d ==>", i);

        no * p = g[i].inicio;

        while(p) {

            printf(" %d", p->adj);
            p = p->prox;

        }

        puts("");
    }

}