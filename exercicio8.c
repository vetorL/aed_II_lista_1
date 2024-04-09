// Exercicio 8

// Sejam dois grafos g1 e g2 contendo exatamente os mesmos vertices. Verifique 
// se g2 eh um subgrafo de g1, retornando true/false conforme o caso. Para tornar
// o problema mais interessante, considere que um grafo eh representado em listas 
// e outro em matriz.

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s {

    int adj;
    struct s * prox;

} no;

typedef struct {

    no * inicio;

} vertice;

vertice * criaListaAdj(int v);

int main() {

    // Cria g1

    int v1 = 5; // numero de vertices de v1
    vertice * g1 = criaListaAdj(v1);

    // Cria g2
    int v2 = 3; // numero de vertices de v2
    vertice * g2 = criaListaAdj(v2);

}

vertice * criaListaAdj(int v) {

    vertice * g = (vertice *) malloc(sizeof(vertice) * (v+1));

    // zera todos os campos

    for(int i = 0; i <= v; i++) {

        g[i].inicio = NULL;

    }

    return g;

}

bool g1_contem_g2(vertice * g1, vertice *g2) {

    return false;

}