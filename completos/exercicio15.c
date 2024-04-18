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
    no * inicio;

} vertice;

vertice * criaGrafo(int v);
void inserirAresta(vertice * g, int i, int j);
void inserirArestaNaoDirigida(vertice * g, int i, int j);
void exibir(vertice * g, int v);
void prof(vertice * g, int i);
int contarGruposDisjuntos(vertice * g, int v);

int main() {

    vertice * g = criaGrafo(V);

    inserirArestaNaoDirigida(g, 1, 2);
    
    inserirArestaNaoDirigida(g, 3, 5);
    inserirArestaNaoDirigida(g, 4, 5);

    puts("*Lista de adjacencias*");

    exibir(g, V);

    puts("======================");

    printf("Existem %d grupos disjuntos\n", contarGruposDisjuntos(g, V));

    puts("");

}

vertice * criaGrafo(int v) {

    vertice * g = (vertice *) malloc(sizeof(vertice) * (v+1));

    for(int i = 1; i <= v; i++) {

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

void inserirArestaNaoDirigida(vertice * g, int i, int j) {

    inserirAresta(g, i, j);
    inserirAresta(g, j, i);

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

void prof(vertice * g, int i) {

    g[i].flag = 1;
    no * p = g[i].inicio;

    while(p) {

        if(g[p->adj].flag == 0) {
            prof(g, p->adj);
        }

        p = p->prox;

    }

    g[i].flag = 2;

}

int contarGruposDisjuntos(vertice * g, int v) {

    int grupos = 0;

    for(int i = 1; i <= v; i++) {

        if(g[i].flag == 0) {
            prof(g, i);
            grupos++;
        }

    }

    return grupos;

}