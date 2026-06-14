#include <stdio.h>
#include <stdlib.h>
#include "Lista.h" 

int main(void) {
    TipoCelula *L;
    TipoDado dado_alvo;

    printf("Criando a lista... \n");
    L = CriacaolistaInvertida();
    
    printf("\nLista Original: ");
    ImprimeL(L);
    
    printf("\nDigite o valor que deseja remover da lista: ");
    dado_alvo = LeituraDado();
    
    L = RemocaoDadoL(L, dado_alvo);
    printf("Dado removido com sucesso. \n");
    
    printf("\nLista Atualizada: ");
    ImprimeL(L);
    
    return 0;
}