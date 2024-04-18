#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
void prof(vertice * g, int i, int grupo, int * vertices);
void exibirVerticesGrupo(vertice * g, int v, int grupo);
int maiorGrupoDisjunto(vertice * g, int v);

int main() {

    vertice * g = criaGrafo(V);

    inserirArestaNaoDirigida(g, 1, 2);

    inserirArestaNaoDirigida(g, 3, 5);
    inserirArestaNaoDirigida(g, 4, 5);

    int maiorGrupo = maiorGrupoDisjunto(g, V);
    
    exibir(g, V);

    puts("==========");
    
    printf("Maior grupo: %d\n", maiorGrupo);
    exibirVerticesGrupo(g, V, maiorGrupo);

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

        printf("%d (%d) ==>", i, g[i].flag);

        no * p = g[i].inicio;

        while(p) {

            printf(" %d", p->adj);

            p = p->prox;

        }

        printf("\n");

    }

}

void prof(vertice * g, int i, int grupo, int * vertices) {

    g[i].flag = 1;

    no * p = g[i].inicio;

    while(p) {

        if(g[p->adj].flag == 0) {
            prof(g, p->adj, grupo, vertices);
        }

        p = p->prox;

    }

    *vertices += 1;

    g[i].flag = grupo;

}

int maiorGrupoDisjunto(vertice * g, int v) {

    int maiorGrupo = 0;
    int verticesMaiorGrupo = 0;

    int grupoAtual = 1;

    for(int i = 1; i <= v; i++) {

        if(g[i].flag == 0) {

            int verticesGrupoAtual = 0;

            prof(g, i, grupoAtual, &verticesGrupoAtual);

            if(verticesGrupoAtual > verticesMaiorGrupo) {
               verticesMaiorGrupo = verticesGrupoAtual;
               maiorGrupo = grupoAtual; 
            //    puts("AAAAAAAAAaaaa");
            }

            grupoAtual++;

        }

    }

    return maiorGrupo;

}

void exibirVerticesGrupo(vertice * g, int v, int grupo) {

    printf("Lista de vertices do grupo %d:\n", grupo);

    for(int i = 1; i <= v; i++) {

        if(g[i].flag == grupo) {
            printf("%d ", i);
        }

    }

    puts("");
    puts("+++ END PROGRAM ++");

}