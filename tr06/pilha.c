#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha Inicializar() 
{ 
    return NULL;
} 

int PilhaVazia(Pilha P) 
{ 
    return (P == NULL) ? 1 : 0;
} 

int PilhaCheia(Pilha P) 
{ 
    return 0; 
} 

int TopoPilha(Pilha P, TipoDado *pelem) 
{ 
    if (PilhaVazia(P)) return 1; 
    *pelem = P->dado;
    return 0; 
} 

void Empilhar(Pilha* pP, TipoDado elem) 
{ 
    Pilha q; 
    q = (TipoCelula *)malloc(sizeof(TipoCelula)); 
    q->dado = elem; 
    q->seguinte = *pP; 
    *pP = q; 
} 

int Desempilhar(Pilha *pP, TipoDado *pelem) 
{ 
    Pilha q; 
    if (PilhaVazia(*pP)) return 1; 
    *pelem = (*pP)->dado; 
    q = *pP; 
    *pP = (*pP)->seguinte; 
    free(q); 
    return 0; 
} 

void Destruir(Pilha *pP) 
{ 
    Pilha q; 
    while (*pP != NULL) 
    { 
        q = *pP; 
        *pP = (*pP)->seguinte; 
        free(q); 
    } 
    *pP = NULL; 
} 

void Esvaziar(Pilha *pP) 
{ 
    Destruir(pP); 
    *pP = NULL; 
} 

void ImprimirPilha(Pilha P) 
{ 
    Pilha q; 
    q = P; 
    printf("Topo -> ");
    while (q != NULL) 
    { 
        printf("%.2f  ", q->dado); 
        q = q->seguinte; 
    } 
    puts("-> Fundo"); 
}
