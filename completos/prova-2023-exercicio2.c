#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define A 1
#define B 2
#define C 3
#define D 4
#define E 5
#define F 6
#define G 7
#define H 8
#define I 9
#define J 10
#define K 11

#define V 11

typedef struct s {

    int adj;
    int voos;
    struct s * prox;

} no;

typedef struct {

    int flag;
    no * inicio;

} vertice;

vertice * criaLista(int v) {

    vertice * g = (vertice *) malloc(sizeof(vertice) * (v+1));

    for(int i = 1; i <= v; i++) {

        g[i].flag = 0;
        g[i].inicio = NULL;

    }

    return g;
    
}

void inserirAresta(vertice * g, int i, int j, int voos) {

    no * novo = (no *) malloc(sizeof(no));

    novo->adj = j;
    novo->voos = voos;
    novo->prox = g[i].inicio;

    g[i].inicio = novo;

}

void inserirArestaND(vertice * g, int i, int j, int voos) {

    inserirAresta(g, i, j, voos);
    inserirAresta(g, j, i, voos);

}

void prof(vertice * g, int i, int * tamanhoGrupo) {

    g[i].flag = 1;

    no * p = g[i].inicio;
            
    while(p) {

        if(g[i].flag == 0) {
            prof(g, p->adj, tamanhoGrupo);
        }

        p = p->prox;

    }

    *tamanhoGrupo += 1;
    g[i].flag = 2;

}

void exibirMaisMovimentado(vertice * g, int v) {

    int a = -1;
    int b = -1;
    int maiorQtdVoos = -1;

    for(int i = 1; i <= v; i++) {

        no * p = g[i].inicio;

        while(p) {

            if(p->voos > maiorQtdVoos) {
                a = i;
                b = p->adj;
                maiorQtdVoos = p->voos;
            }

            p = p->prox;

        }

    }

    printf("O trajeto mais movimentado eh o %d <-> %d, com %d voos\n", a, b, maiorQtdVoos);

}

int main() {

    vertice * g = criaLista(V);

    inserirArestaND(g, A, C, 4);
    inserirArestaND(g, C, E, 3);
    inserirArestaND(g, E, D, 3);
    inserirArestaND(g, J, K, 4);
    inserirArestaND(g, H, F, 1);
    inserirArestaND(g, F, G, 4);

    exibirMaisMovimentado(g, V);
    
}

