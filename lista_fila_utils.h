#ifndef LISTA_FILA_UTILS_H
#define LISTA_FILA_UTILS_H

struct tlista {
    int valor;
    struct tlista *next;
};
typedef struct tlista Lista;

struct ElementoFila { 
    int valor;
    struct ElementoFila *next;
};
typedef struct ElementoFila efila;

struct fila {
    efila* first;
    efila* last;
};
typedef struct fila Fila;

// Transforma vetor em lista encadeada.
Lista* criarLista(int vetor[], int sizeVetor);

// Transforma lista encadeada em um vetor de elementos Lista;
void criarVetorDeElementos(Lista* first, int sizeVetor, Lista vetor[]);

// Cria fila a partir do vetor ordenado
Fila criarFila(Lista vetor[], int sizeVetor);

// Imprime a Fila no terminal
void printFila(Fila fila);

// Troca dois elementos da lista 
void troca(Lista* vetor1, Lista* vetor2);
#endif
