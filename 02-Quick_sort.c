// UFFS - Ciência da Computação
// Pesquisa e Ordenação de Dados
// Raiel Vitor Babinski - 20230003539

#include <stdlib.h>
#include <stdio.h>
#include "lista_fila_utils.h"

void quickSort(Lista vetor[], int inicio, int fim);
int particiona(Lista vetor[], int inicio, int fim);

int main(){
    
    int vetorParaOrdenar[9] = {7, 9, 6, 3, 5, 6, 8, 10, 1};
    
    int sizeVetor = (int)sizeof(vetorParaOrdenar)/sizeof(int);
    Lista vetorLista[sizeVetor];
    
    // Transforma em lista encadeada e depois em vetor de elementos.
    Lista* lista = criarLista(vetorParaOrdenar, sizeVetor);
    criarVetorDeElementos(lista, sizeVetor, vetorLista);

    // Aplica o quick sort.
    quickSort(vetorLista, 0, sizeVetor-1);
    
    // Transforma o vetor ordenado em fila e mostra no terminal.
    Fila filaVetorOrdenado = criarFila(vetorLista, sizeVetor);
    printFila(filaVetorOrdenado);
    return 0;
} 

void quickSort(Lista vetor[], int inicio, int fim){
    // Verifica se o vetor tem mais de um elemento.
    if (inicio < fim){
        // O posPivo recebe o vetor particionado, e aplica o 
        // quick sort nas partes separadas recurcivamente.
        int posPivo = particiona(vetor, inicio, fim);
        quickSort(vetor, inicio, posPivo - 1);
        quickSort(vetor, posPivo+1, fim);
    }
}


int particiona(Lista vetor[], int inicio, int fim){
    int posPivo = fim;
    int k = inicio;
    for (int i = inicio; i<fim; i++){
        // Se i for menor ou igual pivo, troca i com k.
        if (vetor[i].valor <= vetor[posPivo].valor){
            troca(&vetor[i], &vetor[k]);
            k++;
        }
    }
    // Se o valor de k for maior que o valor do posPivo, 
    // troca k com posPivo.
    if(vetor[k].valor > vetor[posPivo].valor){
        troca(&vetor[k], &vetor[posPivo]);
        // Nesse casso o k se torna a posição do posPivo,
        // mas como somente os elementos são trocados, os
        // índices continuam os mesmos.
        return k;
    }
    // Se k for maior que o posPivo ou qualquer 
    // outra situação ocorrer, será retornado o posPivo.
    return posPivo;
}

