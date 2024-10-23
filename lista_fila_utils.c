#include "lista_fila_utils.h"
#include <stdlib.h>
#include <stdio.h>

Lista* criarLista(int vetor[], int sizeVetor){
    Lista *first = NULL;
    Lista *aux = NULL;
    Lista *new = NULL;
    int i = 0;

    // Percore o vetor armazenando seus valores nos elementos da lista encadeada.
    while(i<sizeVetor){
        new = (Lista*)malloc(sizeof(Lista*));
        
        new->valor = vetor[i];
        
        new->next = NULL;

        if(first == NULL){
            first = new;
            aux = new;
        }else{
            aux->next = new;
            aux = new;
        }
        i++;
    }
    return first;
}

//void printLista(Lista *first){
//     Lista *aux;
//     aux = first;
//     for(aux; aux != NULL; aux=aux->next){
//         printf("lista encadeada: ");
//         printf("%d\n", aux->valor);
//     }
// }

void criarVetorDeElementos(Lista* first, int sizeVetor, Lista vetor[]){
    // Variavel nulling, armazena o elemento anterior do aux, 'nulificando' o next.
    Lista *aux, *nulling; 
    int i = 0;
    aux = first;
    
    // While para percorer a lista e armazenar os elemetos no vetor.
    while(aux != NULL){
        vetor[i]= *aux;
        i++;
        nulling = aux;
        aux = aux->next;
        nulling->next = NULL;
    }
}

Fila criarFila(Lista vetor[], int sizeVetor){
    Fila fila;
    fila.first = NULL;
    fila.last = NULL;
    efila *aux;
    
    int i = 0;
    // While para criar os elementos da fila e armazenar os valores da lista.
    while(i<sizeVetor){
        fila.last = (efila*)malloc(sizeof(efila*));

        fila.last->valor = vetor[i].valor;

        if(fila.first==NULL){
            fila.first = fila.last;
            fila.first->next = NULL;
            aux = fila.last;
         
        }else{
            fila.last->next = aux;
            aux = fila.last;
        }
        i++;
    }
    return fila;
}

void printFila(Fila fila){
    efila *aux;
    for(aux = fila.last; aux!=NULL; aux=aux->next){
        printf("%d\n", aux->valor);
    }

}

void troca(Lista* vetor1, Lista* vetor2){
    Lista troca;

    troca = *vetor1;
    *vetor1 = *vetor2;
    *vetor2 = troca;
}
