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
    struct s * prox;

} no;

typedef struct {

    int flag;
    no * inicio;

} vertice;

void inserirArestaND(vertice * g, int i, int j);
void inserirAresta(vertice * g, int i, int j);
vertice * criaLista(int v);
int tamanhoMenorConjunto(vertice * g, int v);
void prof(vertice * g, int i, int * tamanhoGrupo);

int main() {

    vertice * g = criaLista(V);

    inserirArestaND(g, A, C);
    inserirArestaND(g, C, E);
    inserirArestaND(g, E, D);
    inserirArestaND(g, J, K);
    inserirArestaND(g, H, F);
    inserirArestaND(g, F, G);

    printf("O tamanho do menor conjunto eh: %d\n", tamanhoMenorConjunto(g, V));
    
}

vertice * criaLista(int v) {

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

void inserirArestaND(vertice * g, int i, int j) {

    inserirAresta(g, i, j);
    inserirAresta(g, j, i);

}

int tamanhoMenorConjunto(vertice * g, int v) {

    int tamanhoMenorGrupo = v;

    int tamanhoGrupoAtual = 0;

    for(int i = 1; i <= v; i++) {

        if(g[i].flag == 0) {
            prof(g, i, &tamanhoGrupoAtual);
        }

        if(tamanhoGrupoAtual < tamanhoMenorGrupo) {
            tamanhoMenorGrupo = tamanhoGrupoAtual;
        }

        tamanhoGrupoAtual = 0;

    }

    return tamanhoMenorGrupo;
    
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