#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define V 4

typedef struct s {

    int adj;
    struct s * prox;

} no;

typedef struct { 

    int via;
    int flag;
    no * inicio;

} vertice;

vertice * criaGrafo(int v);
bool inserirAresta(vertice * g, int i, int j);
void prof(vertice * g, int i, int j, bool * achou);

int main() {

    vertice * g = criaGrafo(V);

    inserirAresta(g, 1, 2);
    inserirAresta(g, 2, 3);
    inserirAresta(g, 3, 1);
    inserirAresta(g, 3, 4);

    bool achou = false;

    int a = 1;
    int b = 4;

    prof(g, a, b, &achou);

    if(achou) {
        puts("O caminho de a ate b eh:");
        for(int i = a + 1; i <= b; i++) {
            printf("%d ", g[i].via);
        }
        printf("\n");
    } else {
        puts("Nao ha caminho de a ate b");
    }

}

vertice * criaGrafo(int v) {

    vertice * g = (vertice *) malloc(sizeof(vertice) * (v+1));

    for(int i = 1; i <= v; i++) {
        g[i].flag = 0;
        g[i].via = -1;
        g[i].inicio = NULL;
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

void prof(vertice * g, int i, int j, bool * achou) {

    if(*achou == true) {
        return;
    }

    g[i].flag = 1;
    no * p = g[i].inicio;

    while(p) {
        if(g[p->adj].flag == 0) {
            g[p->adj].via = i;
            if(p->adj == j) {
                *achou = true;
                return;
            }
            prof(g, p->adj, j, achou);
        }

        p = p->prox;
    }

    g[i].flag = 2;
}