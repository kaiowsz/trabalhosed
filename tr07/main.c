#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

int main() {
    Fila F = InicializarF();
    int opcao;
    TipoDado valor, elemento;

    printf("=================================================\n");
    printf("         LABORATORIO - TAD FILA (LISTAS)         \n");
    printf("=================================================\n");

    do {
        printf("\n--- MENU FILA ---\n");
        printf("1 - Enfileirar (InserirF)\n");
        printf("2 - Desenfileirar (RemoverF)\n");
        printf("3 - Consultar Cabeca (AcessarCabecaF)\n");
        printf("4 - Imprimir Fila\n");
        printf("5 - Verificar se Fila esta Vazia/Cheia\n");
        printf("6 - Esvaziar Fila\n");
        printf("0 - Sair (Condicao de Parada)\n");
        printf("Escolha uma opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
            while (getchar() != '\n');
            printf("Entrada invalida. Tente novamente.\n");
            continue;
        }

        switch (opcao) {
            case 1:
                printf("Digite o numero real para enfileirar: ");
                if (scanf("%f", &valor) == 1) {
                    InserirF(&F, valor);
                    printf("Valor %.2f inserido na fila.\n", valor);
                    ImprimirF(F);
                } else {
                    while (getchar() != '\n');
                    printf("Numero invalido.\n");
                }
                break;

            case 2:
                if (RemoverF(&F, &elemento) == 0) {
                    printf("Valor removido da fila: %.2f\n", elemento);
                    ImprimirF(F);
                } else {
                    printf("Aviso: A fila ja esta vazia!\n");
                }
                break;

            case 3:
                if (AcessarCabecaF(F, &elemento) == 0) {
                    printf("Elemento na cabeca da fila: %.2f\n", elemento);
                } else {
                    printf("A fila esta vazia.\n");
                }
                break;

            case 4:
                ImprimirF(F);
                break;

            case 5:
                printf("Fila Vazia? %s\n", FilaVazia(F) ? "SIM" : "NAO");
                printf("Fila Cheia? %s\n", FilaCheia(F) ? "SIM" : "NAO");
                break;

            case 6:
                EsvaziarF(&F);
                printf("Fila esvaziada com sucesso.\n");
                ImprimirF(F);
                break;

            case 0:
                printf("Encerrando o programa e liberando memoria...\n");
                DestruirF(&F);
                break;

            default:
                printf("Opcao invalida. Escolha entre 0 e 6.\n");
                break;
        }

    } while (opcao != 0);

    printf("Programa finalizado.\n");
    return 0;
}
