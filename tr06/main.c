#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {
    Pilha P = Inicializar();
    TipoDado elemento;

    printf("=== Teste do TAD Pilha ===\n\n");

    printf("1. Pilha Inicializada.\n");
    printf("A pilha esta vazia? %s\n\n", PilhaVazia(P) ? "Sim" : "Nao");

    printf("2. Empilhando valores...\n");
    Empilhar(&P, 10.5);
    Empilhar(&P, 20.3);
    Empilhar(&P, 30.8);
    Empilhar(&P, 40.1);

    printf("Estado da pilha:\n");
    ImprimirPilha(P);

    printf("\nA pilha esta cheia? %s\n", PilhaCheia(P) ? "Sim" : "Nao");

    if (TopoPilha(P, &elemento) == 0) {
        printf("Elemento no topo da pilha: %.2f\n", elemento);
    }

    printf("\n3. Desempilhando um valor...\n");
    if (Desempilhar(&P, &elemento) == 0) {
        printf("Valor desempilhado: %.2f\n", elemento);
    }
    printf("Estado da pilha:\n");
    ImprimirPilha(P);

    printf("\n4. Esvaziando a pilha...\n");
    Esvaziar(&P);
    printf("Estado da pilha:\n");
    ImprimirPilha(P);

    printf("A pilha esta vazia? %s\n", PilhaVazia(P) ? "Sim" : "Nao");

    return 0;
}
