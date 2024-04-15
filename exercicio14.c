#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 4

typedef struct s {

    int adj;
    struct s * prox;

} no;

typedef struct {

    int flag;
    no * inicio;

} vertice;

vertice * criaLista(int v);
bool inserirAresta(vertice * g, int i, int j);
void exibir(vertice * g, int v);
int comprimentoMaiorCiclo(vertice * g, int i);

int main() {

    vertice * g = criaLista(V);

    inserirAresta(g, 1, 2);
    inserirAresta(g, 2, 1);
    inserirAresta(g, 1, 3);
    inserirAresta(g, 3, 4);
    inserirAresta(g, 4, 1);

    puts("Lista de adjacencias com ciclos");
    
    exibir(g, V);

    puts("=============================");

    printf("Comprimento do maior ciclo: %d\n", comprimentoMaiorCiclo(g, 1));

}

vertice * criaLista(int v) {

    vertice * g = (vertice *) malloc(sizeof(vertice) * (v+1));

    for(int i = 0; i <= v; i++) {

        g[i].flag = 0;
        g[i].inicio = NULL;

    }

    return g;

}

bool inserirAresta(vertice * g, int i, int j) {

    // if(arestaExiste(g, i, j)) {
        // return false;
    // }

    no * novo = (no *) malloc(sizeof(no));

    novo->adj = j;
    novo->prox = g[i].inicio;

    g[i].inicio = novo;

    return true;

}

int comprimentoMaiorCiclo(vertice * g, int i) {

    g[i].flag = 1;

    no * p = g[i].inicio;

    int maiorComprimento = 0;

    while(p) {

        if(g[p->adj].flag == 0) {
            comprimentoMaiorCiclo(g, p->adj);
        }

        p = p->prox;

    }

    g[i].flag = 2;

    return maiorComprimento;

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