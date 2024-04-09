// Exercicio 8

// Sejam dois grafos g1 e g2 contendo exatamente os mesmos vertices. Verifique 
// se g2 eh um subgrafo de g1, retornando true/false conforme o caso. Para tornar
// o problema mais interessante, considere que um grafo eh representado em listas 
// e outro em matriz.

#include <stdbool.h>

typedef struct s {

    int adj;
    struct s * prox;

} no;

typedef struct {

    no * inicio;

} vertice;

int main() {

    

}

bool g1_contem_g2(vertice * g1, vertice *g2) {

    return false;

}