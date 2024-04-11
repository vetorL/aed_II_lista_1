#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SPAM 999
#define EMAIL 666

typedef struct s {

    int adj;
    int id;
    struct s * prox;

} no;

typedef struct {

    no * inicio;

} vertice;

bool inserirAresta(vertice * g, int i, int j, int id);
vertice * criaLista(int v);
void exibirSuspeitosSpam(vertice * g, int v, int id_spam);

int main() {

    int v = 3; // numero de vertices

    vertice * g = criaLista(3);
    inserirAresta(g, 1, 2, SPAM);
    inserirAresta(g, 1, 3, SPAM);
    inserirAresta(g, 3, 2, SPAM);
    inserirAresta(g, 2, 1, EMAIL);

    exibirSuspeitosSpam(g, v, SPAM);

}

vertice * criaLista(int v) {

    vertice * g = (vertice *) malloc(sizeof(vertice)*(v+1));

    for(int i = 0; i <= v; i++) {

        g[i].inicio = NULL;

    }

    return g;

}

bool inserirAresta(vertice * g, int i, int j, int id) {

    // if(arestaExiste(g, i, j, id)) {
    //     return false;
    // }

    no * novo = (no *) malloc(sizeof(no));
    novo->adj = j;
    novo->prox = g[i].inicio;
    novo->id = id;

    g[i].inicio = novo;

}

void exibirSuspeitosSpam(vertice * g, int v, int id_spam) {

    // usuarios que nao receberam o id_spam nenhuma vez sao suspeitos

    printf("Usuários suspeitos de espalharem spam:");

    for(int i = 1; i <= v; i++) {

        bool recebeuSpam = false;

        for(int j = 1; j <= v; j++) {

            no * p = g[j].inicio;

            while(p) {

                if(p->adj == i && p->id == id_spam) {

                    recebeuSpam = true;

                }

                p = p->prox;

            }

        }

        if(!recebeuSpam) {
            printf(" %d", i);
        }

    }

    printf("\n");

}