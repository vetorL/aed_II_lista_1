// Exercicio 8

// Sejam dois grafos g1 e g2 contendo exatamente os mesmos vertices. Verifique 
// se g2 eh um subgrafo de g1, retornando true/false conforme o caso. Para tornar
// o problema mais interessante, considere que um grafo eh representado em listas 
// e outro em matriz.

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define V 5

typedef struct s {

    int adj;
    struct s * prox;

} no;

typedef struct {

    no * inicio;

} vertice;

vertice * criaListaAdj(int v);
void zeraMatriz(int m[V+1][V+1]);
void inserirAresta(vertice * g, int i, int j);
bool g1_contem_g2(vertice * g1, int g2[V+1][V+1]);
bool arestaExiste(int m[V+1][V+1], int i, int j);

int main() {

    // # Cria g1
    vertice * g1 = criaListaAdj(V);
    inserirAresta(g1, 1, 4);
    inserirAresta(g1, 1, 3);
    inserirAresta(g1, 2, 1);
    inserirAresta(g1, 2, 5);
    inserirAresta(g1, 3, 5);

    // # Cria g2
    int g2[V+1][V+1]; // aloca o espaco para a matriz na memoria
    zeraMatriz(g2); // zera a matriz
    g2[1][4] = 1;
    g2[1][3] = 1;
    g2[2][1] = 1;
    g2[2][5] = 1;
    g2[3][5] = 1; // ao inverter essa linha com a de baixo g1_contem_g2 da false
    // g2[5][3] = 1;

    if(g1_contem_g2(g1, g2)) {
        puts("g1 contem g2");
    } else {
        puts("g1 NAO contem g2");
    }

}

vertice * criaListaAdj(int v) {

    vertice * g = (vertice *) malloc(sizeof(vertice) * (v+1));

    // zera todos os campos

    for(int i = 0; i <= v; i++) {

        g[i].inicio = NULL;

    }

    return g;

}

void zeraMatriz(int m[V+1][V+1]) {

    // loop por toda a matriz
    for(int i = 0; i <= V; i++) {
        for(int j = 0; j <= V; j++) {
            m[i][j] = 0;
        }
    }

}

bool g1_contem_g2(vertice * g1, int g2[V+1][V+1]) {

    for(int i = 1; i <= V; i++) {
        no * p1 = g1[i].inicio;

        while(p1) {

            bool existe = arestaExiste(g2, i, p1->adj);

            if(!existe) {
                return false;
            }

            p1 = p1->prox;

        }

    }

    return true;

}

bool arestaExiste(int m[V+1][V+1], int i, int j) {

    if(m[i][j] == 1) {
        return true;
    }

    return false;

}

void inserirAresta(vertice * g, int i, int j) {

    no * novo = (no *) malloc(sizeof(no));
    
    novo->adj = j;
    novo->prox = g[i].inicio;

    g[i].inicio = novo;

}