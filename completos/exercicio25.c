#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 7

typedef struct s {

    int adj;
    struct s * prox;

} no;

typedef struct {

    int flag;
    int dist;
    no * inicio;

} vertice;

typedef struct {

    no * inicio;
    no * fim;

} fila;

vertice * criaLista(int v) {

    vertice * g = (vertice *) malloc(sizeof(vertice) * (v+1));

    for(int i = 1; i <= v; i++) {

        g[i].flag = 0;
        g[i].dist = -1;
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
    // inserirAresta(g, j, i);

}

void inicializarFila(fila * f) {

    f->inicio = NULL;
    f->fim = NULL;

}

void entrarFila(fila * f, int n) {

    no * novo = (no *) malloc(sizeof(no));

    novo->adj = n;
    novo->prox = NULL;

    if(f->fim) {
        f->fim->prox = novo;
    } else {
        // lista vazia
        f->inicio = novo;
    }

    f->fim = novo;

}

int sairFila(fila * f) {

    int n = f->inicio->adj;

    no * aux = f->inicio;

    f->inicio = f->inicio->prox;
    
    free(aux);

    if(!f->inicio) {
        f->fim = NULL;
    } 

    return n;

}

void largura(vertice * g, int i, int graus) {

    fila f;
    inicializarFila(&f);
    entrarFila(&f, i);
    g[i].flag = 1;

    while(f.inicio) {

        i = sairFila(&f);
        g[i].flag = 2;
        no * p = g[i].inicio;

        while(p) {

            if(g[p->adj].flag == 0) {
                entrarFila(&f, p->adj);
                g[p->adj].flag = 1;
                g[p->adj].dist = g[i].dist + 1;
            }

            p = p->prox;

        }

    }

}

void exibirUsuariosRelacionados(vertice * g, int i, int graus, int v) {

    largura(g, i, graus);

    for(int i = 1; i <= v; i++) {

        no * p = g[i].inicio;

        while(p) {

            if(g[p->adj].dist <= graus && g[p->adj].flag < 3) {
                printf(" %d", p->adj);
                g[p->adj].flag = 3;
            }

            p = p->prox;

        }

    }

}

void exibir(vertice * g, int v) {

    for(int i = 1; i <= v; i++) {

        printf("%d flag:(%d) dist:(%d) ==>", i, g[i].flag, g[i].dist);

        // bla bla bla

        printf("\n");

    }

}

int main() {

    vertice * g = criaLista(V);

    inserirArestaND(g, 1, 2);    
    inserirArestaND(g, 1, 3);    
    inserirArestaND(g, 2, 4);    
    inserirArestaND(g, 4, 5);    
    inserirArestaND(g, 3, 7);    
    inserirArestaND(g, 3, 6);  

    int i = 1;
    int graus = 1;
    g[i].dist = 0;

    printf("Usuarios relacionados a %d com ate %d graus:", i, graus);

    exibirUsuariosRelacionados(g, i, graus, V);

    puts("");

    exibir(g, V);
}