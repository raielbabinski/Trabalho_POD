// UFFS - Ciência da Computação
// Pesquisa e Ordenação de Dados
// Raiel Vitor Babinski - 20230003539

#include <stdlib.h>
#include <stdio.h>
#include "lista_fila_utils.h"

void boubleSort(Lista vetor[], int size);

int main(){
    
    int vetorParaOrdenar[9] = {7, 9, 6, 3, 5, 6, 8, 10, 1};
    
    int sizeVetor = (int)sizeof(vetorParaOrdenar)/sizeof(int);
    Lista vetorLista[sizeVetor];
    
    // Transforma em lista encadeada e depois em vetor de elementos.
    Lista* lista = criarLista(vetorParaOrdenar, sizeVetor);
    criarVetorDeElementos(lista, sizeVetor, vetorLista);

    // Aplica o bouble sort
    boubleSort(vetorLista, sizeVetor);
    
    // Transforma o vetor ordenado em fila e mostra no terminal.
    Fila filaVetorOrdenado = criarFila(vetorLista, sizeVetor);
    printFila(filaVetorOrdenado);
    return 0;
}

void boubleSort(Lista vetor[],int size){
    // Flag para idicar se alguma troca foi feita.
    int flag;

/*  for que percore a lista ao contrário,
    indicando a fronteira entre ordenados
    e não ordenados.*/
    for (int i = size; i > 1; i--){
        flag = 0;
         // for que carrega o maior elemento até a fronteira.
            for(int j=0;j < i-1; j++){
                // Compara os valores dos elementos
                if (vetor[j].valor > vetor[j+1].valor){
                    troca(&vetor[j], &vetor[j+1]);
                    flag = 1;
                }
            }
        // Se não tiver troca, para o loop.
        if(flag == 0){
            break;
        }
    }
}

