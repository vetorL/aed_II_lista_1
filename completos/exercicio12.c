#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 9

typedef struct s {

    int adj;
    struct s * prox;

} no;

typedef struct {

    int flag;
    no * inicio;

} vertice;

bool inserirAresta(vertice * g, int i, int j);
vertice * criaLista(int v);
bool ocorreCiclo(vertice * g, int i);
void exibir(vertice * g, int v);

int main() {

    vertice * g = criaLista(V);

    inserirAresta(g, 1, 2);
    inserirAresta(g, 1, 4);
    inserirAresta(g, 1, 7);
    inserirAresta(g, 2, 3);
    inserirAresta(g, 3, 5);
    inserirAresta(g, 4, 5);
    inserirAresta(g, 4, 6);
    inserirAresta(g, 6, 7);
    inserirAresta(g, 7, 1); // comente essa linha para remover o ciclo
    inserirAresta(g, 7, 8);
    inserirAresta(g, 7, 9);

    puts("=== Lista de Adjacencias ===");
    exibir(g, V);
    puts("");

    printf("Resultado: ");

    if(ocorreCiclo) {
        puts("Existe ciclo");
    } else {
        puts("Nao existe ciclo");
    }

    puts("\nFIM DO PROGRAMA\n");

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
    //     return false;
    // }

    no * novo = (no *) malloc(sizeof(no));
    novo->adj = j;
    novo->prox = g[i].inicio;

    g[i].inicio = novo;

    return true;

}

bool ocorreCiclo(vertice * g, int i) {

    g[i].flag = 1;
    no * p = g[i].inicio;

    while(p) {

        if(g[p->adj].flag == 0) {
            ocorreCiclo(g, p->adj);
        }
        
        if(g[p->adj].flag == 1) {
            // puts("OCORRE CICLO");
            return true;
        }

        // printf("%d ", p->adj);

        p = p->prox;

    }

    g[i].flag = 2;

    return false;

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