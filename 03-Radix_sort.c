// UFFS - Ciência da Computação
// Pesquisa e Ordenação de Dados
// Raiel Vitor Babinski - 20230003539

#include <stdlib.h>
#include <stdio.h>
#include "lista_fila_utils.h"

void radixSort(Lista A[], int size);
void countingSort(Lista A[], int size, int pos );
int buscaMax(Lista A[], int size);

int main(){
    
    int vetorParaOrdenar[12] = {15, 52, 21, 554, 234, 67, 63, 89, 124, 890, 765, 344};
    
    int sizeVetor = (int)sizeof(vetorParaOrdenar)/sizeof(int);
    //Vetor de elementos Lista.
    Lista vetorLista[sizeVetor];
    
    // Transforma em lista encadeada e depois em vetor de elementos.
    Lista* lista = criarLista(vetorParaOrdenar, sizeVetor);
    criarVetorDeElementos(lista, sizeVetor, vetorLista);

    // Aplica o Radix Sort.
    radixSort(vetorLista, sizeVetor);
    

    // Transforma o vetor ordenado em fila e mostra no terminal.
    Fila filaVetorOrdenado = criarFila(vetorLista, sizeVetor);
    printFila(filaVetorOrdenado);
    return 0;
} 

void radixSort(Lista A[], int size){
    // Busca o maxímo
    int max = buscaMax(A, size);
    // Loop vai acontecer de acordo com quantas 
    // casas decimais terá o maior número da lista
    for (int pos = 1; max/pos > 0; pos*=10){
        countingSort(A, size, pos);
    }
}

void countingSort(Lista A[], int size, int pos){
    Lista aux[size];
    int count[10];
    int digito = 0;
    
    // Escrever 0 em todas as posições do count.
    for(int i = 0 ; i < 10;i++){
        count[i] = 0;
    }

    for(int i=0 ; i<size; i++){
        // Digito recebe o valor da posição
        // da casa decimal.
        digito = (A[i].valor/pos)%10; 
        count[digito]++;
    }
    for (int i=1; i<10; i++){
        // Soma todas as contagens.
        count[i] += count[i-1];   
    }
    for (int i=size-1; i>=0; i--){
        // Armazena o valor do digito de acordo com a posição 
        digito = (A[i].valor/ pos) % 10;
        // Reduz 1 na posição do digito, com isso
        // temos o indice de onde armazenar o valor
        count[digito]--;
        // Armazena o elemento de arcordo 
        // com o indice encontrado no count
        aux[count[digito]] = A[i];
    }
    // Passa para o A as posições ordenadas.
    for(int i=0; i < size; i++ ){
        A[i] = aux[i];
    }
}

// Encontra o valor maximo da Lista
int buscaMax(Lista A[], int size){
    int max =0;
    for(int i = 0; i < size; i++){
        if (A[i].valor > max){
            max = A[i].valor;
        }
    }
    return max;
}