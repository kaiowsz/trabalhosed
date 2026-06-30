#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

Fila InicializarF(void) {
    Fila F;
    F.cabeca = NULL;
    F.queue = NULL;
    return F;
}

int FilaVazia(Fila F) {
    return (F.cabeca == NULL) ? 1 : 0;
}

int FilaCheia(Fila F) {
    (void)F;
    TipoCelula *temp = (TipoCelula*) malloc(sizeof(TipoCelula));
    if (temp == NULL) {
        return 1;
    }
    free(temp);
    return 0;
}

int AcessarCabecaF(Fila F, TipoDado *pelem) {
    if (FilaVazia(F)) {
        return 1; 
    }
    *pelem = F.cabeca->dado;
    return 0;
}

void EsvaziarF(Fila *pF) {
    TipoCelula *atual = pF->cabeca;
    while (atual != NULL) {
        TipoCelula *temp = atual;
        atual = atual->seguinte;
        free(temp);
    }
    pF->cabeca = NULL;
    pF->queue = NULL;
}

void DestruirF(Fila *pF) {
    EsvaziarF(pF);
}
void InserirF(Fila *pF, TipoDado elem) {
    TipoCelula *nova = (TipoCelula*) malloc(sizeof(TipoCelula));
    if (nova == NULL) { 
        printf("Erro: Memoria insuficiente para inserir elemento na fila.\n");
        return;
    }
    nova->dado = elem;
    nova->seguinte = NULL;

    if (FilaVazia(*pF)) {
        pF->cabeca = nova;
        pF->queue = nova;
    } else {
        pF->queue->seguinte = nova;
        pF->queue = nova;
    }
}

char RemoverF(Fila *pF, TipoDado *pelem) {
    if (FilaVazia(*pF)) {
        return 1;
    }

    TipoCelula *removida = pF->cabeca;
    *pelem = removida->dado;

    pF->cabeca = removida->seguinte;
    if (pF->cabeca == NULL) {
        pF->queue = NULL;
    }

    free(removida);
    return 0;
}

void ImprimirF(Fila F) {
    if (FilaVazia(F)) {
        printf("Fila vazia [ ]\n");
        return;
    }

    TipoCelula *atual = F.cabeca;
    printf("Cabeca -> [ ");
    while (atual != NULL) {
        printf("%.2f ", atual->dado);
        atual = atual->seguinte;
    }
    printf("] <- Queue\n");
}
