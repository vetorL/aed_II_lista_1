#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s {

    int adj;
    struct s * prox;

} no;

typedef struct {

    int flag;
    no * inicio;

} vertice;

void prof(vertice * g, int i);

int main() {

}

bool ehEnraizada(vertice * g) {



}

void prof(vertice * g, int i) {

    g[i].flag = 1;

    no * p = g[i].inicio;

    while(p) {

        if(g[p->adj].flag == 0) {

            prof(g, i);

        }

        p = p->prox;

    }


    g[i].flag = 2;

}