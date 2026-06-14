#include <stdio.h>
#include <stdlib.h>
#include "Lista.h" 

TipoDado LeituraDado(void) {
    TipoDado dado;
    scanf("%f", &dado);
    return dado;
}

void ImpDado(TipoDado dado) {
    printf("%.2f ", dado);
}

void ImprimeL(TipoCelula* L) {
    TipoCelula* p = L;
    while (p != NULL) {
        ImpDado(p->dado);
        p = p->seguinte;
    }
    printf("\n");
}

TipoCelula* InsFimL(TipoCelula* L, TipoDado dado) {
    TipoCelula* nova = (TipoCelula*)malloc(sizeof(TipoCelula));
    nova->dado = dado;
    nova->seguinte = NULL;
    
    if (L == NULL) return nova;
    
    TipoCelula* p = L;
    while (p->seguinte != NULL) {
        p = p->seguinte;
    }
    p->seguinte = nova;
    return L;
}

TipoCelula* CriacaolistaInvertida(void) {
    TipoCelula* L = NULL;
    int qtd, i;
    
    printf("Quantos elementos deseja inserir na lista? ");
    scanf("%d", &qtd);
    
    for(i = 0; i < qtd; i++) {
        printf("Digite o dado %d: ", i + 1);
        TipoDado dado = LeituraDado();
        
        TipoCelula* nova = (TipoCelula*)malloc(sizeof(TipoCelula));
        nova->dado = dado;
        nova->seguinte = L;
        L = nova;
    }
    return L;
}

TipoCelula* RemocaoDadoL(TipoCelula* L, TipoDado dado_busca) {
    TipoCelula *atual;
    TipoCelula *anterior;

    if (L == NULL) {
        return L;
    }

    if (L->dado == dado_busca) {
        atual = L;
        L = L->seguinte;
        free(atual);
        return L;
    }

    anterior = L;
    atual = L->seguinte;

    while (atual != NULL) {
        if (atual->dado == dado_busca) {
            anterior->seguinte = atual->seguinte;
            free(atual);
            return L;
        }
        anterior = atual;
        atual = atual->seguinte;
    }

    return L;
}